## Why is C++ used in NACHOS?
There is a java version. But they are not `as stable` and Java does not `allow you to control threads` so the OS thread model is not completely accurate in NACHOS (time only advances when NACHOS functions are called). 

The biggest strengths of C++ is flexibility. It allows you to go down to the level of C and direct memory addressing which is very suitable at system level programming (OS level programming).


## The Nachos Instructional Operating System 
This instructional guide was written by Wayne A. Christopher, Steven J. Procter, and Thomas E. Anderson. 

NACHOS is a system which includes `CPU` and `device simulators` and runs as a regular UNIX process. Nachos allows for  `threads` and `remote procedure calls`, recent hardware advances such as `RISC` (reduced instruction set computer) and the prevalance of `memory hierachies` and modern software design tehcniques, such as `object-oriented programming` and `distributed computing`. 

NACHOS relies on a `hardware simulator`. This means we are executing an operating system **kernel** using a simulation of real hardware. This reduces the compile-execute-debug cycle and allows the use of off-the-shelf symbolic debuggers. 

The Nachos Kernel and hardware simulator run together in the same UNIX process. 

### NACHOS specifications

1. simulates a standard, well-documentation, instruction set: MIPS R2/3000 integer instructions 

<br>can run normal C programs as user programs on OC without requiring user programs to be written in assembly language ; because R2/3000 is a RISC, it can be simulted with only about 10 pages of code.

2. Connection of Nachos "machine" together via sockets

<br>A thread on one "machine" can then send a message to a thread running on a different "machine" But must be simulated on the SAME physical hardware

3. Simulation is deterministic 

<br>Nachos maintains a simulated time that is incremented whenever a user programme executes an instruction and whenever a call is made to certain low-level operating system routines. Interrupt handlers are then invoked when the simulated time reaches the appropriate point. 

4. Simulation is randomizable to add unpredictable but repeatable behavior

<br>the network simulation randomly chooses which packets to drop; provided the intial seed to the random number generator is the same ; however, the behaviour of the system is repeatable 

5. Nachos is implemented in a subset of C++

<br>OOP used for modularity and clean interfaces in building operating systems. 

<br>Omitted: derived classes, operator and function overloading, C++ streams

<br>Kept to minimum: inlines 


## A Road Map through Nachos
Written by Thomas Narten

Nachos provides a skeletal operating system that supports threads, user-level processes, virtual memory and interrupt-driven input output devices. 

Nachos runs a single UNIX process whereas real operating systems run on bare machines. Nachos simulates the general low-level facilities of typical machines including interrupts, virtual memory and interrupt-driven device I/O. 

### Nachos Machine 

1. uses MIPS architecture
2. has registers, memory and a cpu
3. an event-driven simulated clock provides a mechanism to schedule interrupts and execute them at a later time
4. Loads instructions into the machine's memory, initializes registers (including the program counter PCReg) and then tells teh machine to start executing instructions 
5. machine then fetches the instruction PCReg points at, decods it and executes it
6. Process is repeated indefinitely, until an illegal operation is performed or a hardware interrupt is generated 
7. when a trap or interrupt takes place, execution of MIPS instructions is suspended, and a Nachos interrupt service routine is invoked to deal with the condition


### Nachos Mode of operation 

1. User-level

MIPS Simulator. Nachos executes user-level processes by loading them into the simulator's memory, intializing the simulator's registers and then running the simulator. User-programs can only access the memory associated with the simulated machine. 

2. Nachos "kernel"

The kernel executes when Nachos first starts up, or when a user-program executes an instruction that causes a hardware trap (e.g. illegal instruction, page fault, system call, etc.). In "kernel mode", Nachos executes the way normal Unix processes execute. The statements corresponding to the Nachos source code are executed, and the memory accessed corresponds to the memory assigned to Nachos variables. 

---

Nachos does not have to execute user-level programs in order to perform useful things. Nachos supports `kernel threads`, allowing `multiple threads` to execute concurrently. 
User-level processes are executed by having a kernel thread invoke the simulator. Thus, multiprogramming makes use of multiple threads; each user-level process has a Nachos kernel thread associated with it to provide a context for executing the MIPS simulator. 


## The files and functions

> **Machine.h and Machine.cc**

A machine instance is created when Nachos first starts up. <br>
`registers`: An array of 40 registers including stack pointer etc. <br>
`mainMemory`: is byte addressable and organized into 128 byte pages, the same size as disk sectors <br>
`VirtualMemory`: Nachos supports VM through either a single linear page table or a software-managed TLB (though not simultaneously)<br>

`Machine(bool debug)`: Constructor that takes a single argument debug. When debug is TRUE, the MIPS simulator executes instructions in single step mode, invoking the debugger after each instruction is executed. <br>
`ReadRegister(int num)`: fetches the value stored in register num
`WriteRegister(int num, int value)`: places value into register num

---

> **Interrupt.cc and Interrupt.h (machine folder)**
The timer uses several functions from the Interrupt class. 
Pending timer interrupts in the system are maintained in a list called **pending**, comprising objects of the class PendingInterrupt. 
This list is sorted in increasing order of the time tick when the interrupt will be triggered. 

### `void Interrupt::Schedule(VoidFunctionPtr handler, _int arg, int fromNow, IntType type)`

Function schedules/inserts a new interrupt to the pending list. 
Insertion is in sorted order; sorted by the pending time ticks for the interrupt to be triggered. 
Used in Timer to initialize a timer interrupt

Arrange for the CPU to be interrupted when simulated time reaches "now + when". Implementation: just put it on a sorted list.
NOTE: the Nachos kernel should not call this routine directly.
Instead, it is only called by the hardware device simulators.
"handler" is the procedure to call when the interrupt occurs
"arg" is the argument to pass to the procedure
"fromNow" is how far in the future (in simulated time) the interrupt is to occur
"type" is the hardware device that generated the interrupt

### `void Interrupt::OneTick()`
Function to process a single time tick. Updates global variable stats -> totalTicks 
```C++
//totalTicks is global variable 
stats->totalTicks += SystemTick; //OR
stats->totalTicks += UserTick;
```
Calls *Interrupt::CheckIfDue()* to process any pending interrupt that would be triggered now. 
If variable yieldOnReturn is true, then triggers a context switch through a call to *Thread::Yield()*


Advance simulated time and check if there are any pending interrupts to be called. Two things can cause OneTick to be called: interrupts are re-enabled a user instruction is executed.

### `bool Interrupt::CheckIfDue(bool advanceClock)`
Function to process interrupts and invoke handler
Checks if pendingInterrupt at the head of pending list should be triggered at current tick. 
If yes, corresponding handler is invoked. 
Handler for Timer is *Timer::TimerExpired()*

Check if an interrupt is scheduled to occur, and if so, fire it off.
Returns: TRUE, if we fired off any interrupt handlers
Params: "advanceClock" -- if TRUE, there is nothing in the ready queue, so we should simply advance the clock to when the next 		pending interrupt would occur (if any).  If the pending interrupt is just the time-slice daemon, however, then we're done!

### `void Interrupt::YieldOnReturn()`
Function that is called by the Timer Handler *TimerInterruptHandler()*. Sets the variable yieldOnReturn to true. Force *Interrupt::OneTick()* to trigger context switch. 

Called from within an interrupt handler, to cause a context switch 	(for example, on a time slice) in the interrupted thread, when the handler returns. We can't do the context switch here, because that would switch out the interrupt handler, and we want to switch out the interrupted thread.

---

> **Timer.cc and Timer.h (machine folder)**

Timer can be used to trigger an interrupt (i.e., after a fixed number of time ticks).

### `void TimerExpired()`
Function defined in *code/machine/timer.cc*
Executes whenever the timer expires. It in turn invokes the interrupt handler. 

### `TimeOfNextInterrupt()`
Defined in *code/machine/timer.cc*
Returns an integer denoting number of time ticks 
Used to schedule an interrupt using the timer. The interrupt will be triggered after this number of time ticks from current time 
Can be used to make the timer periodic as required for round-robin scheduling

---

> **thread.cc and thread.h (threads folder)**

A thread can be in either of these states
1. READY: eligible to run
2. RUNNING: only one thread can be in this state
3. BLOCKED: waiting for some external event
4. JUST_CREATED: temporary state used during creation 

 ### `Thread::Thread(char* threadName)` 
 
 Initialize a thread control block, so that we can then call Thread::Fork. "threadName" is an arbitrary string, useful for debugging. 

This is a constructor which sets the thread as JUST_CREATED status 


### `void Thread::Fork(VoidFunctionPtr func, int arg, int joinP)` 
Invoke (*func)(arg), allowing caller and callee to execute concurrently. <br>	
Turns a thread into one that can be executed
Calls readyToRun()
NOTE: although our definition allows only a single integer argument to be passed to the procedure, it is possible to pass multiple arguments by making them fields of a structure, and passing a pointer to the structure as "arg". <br>
Implemented as the following steps:
1. Allocate a stack
2. Initialize the stack so that a call to SWITCH will cause it to run the procedure
3. Put the thread on the ready queue
<br> "func" is the procedure to run concurrently.
<br> "arg" is a single argument to be passed to the procedure.
<br> "joinP" is 0 if this thread cannot be joined and 1 if this thread will be joined

Allocate stack, initialize registers <br>
Call `Scheduler::ReadyToRun()` to put the thread into readyList, and set its status as READY. 

### `void Thread::Yield ()` 
Finds the next thread to run using findNextToRun()
<br> If another thread has been found 
1. call readyToRun() for the old thread
2. Run the new thread using Run()

Relinquish the CPU if any other thread is ready to run. If so, put the thread on the end of the ready list, so that it will eventually be re-scheduled. NOTE: returns immediately if no other thread on the ready queue. Otherwise returns when the thread eventually works its way to the front of the ready list and gets re-scheduled. NOTE: we **disable interrupts**, so that looking at the thread on the front of the ready list, and switching to it, can be done atomically.  On return, we re-set the interrupt level to its original state, in case we are called with interrupts disabled. Similar to Thread::Sleep(), but a little different.

Suspends the calling thread and put it into readyList.
Call `Scheduler::FindNextToRun()` to select another thread from readyList. Puts current thread into ready list (waiting for rescheduling)

Execute the next ready and selected thread by `Scheduler::Run()` which sets its status as RUNNING and call SWITCH() (in code/threads/switch.s) to exchange the running thread.

If no other threads are ready to execute, continue running the current thread. 

### `void Thread::Sleep ()` 
Set Status to BLOCKED. Find another thread to run using findNextToRun()
<br> If another thread has been found
1. Run the new thread using Run()

Relinquish the CPU, **because the current thread is blocked waiting on a synchronization variable (Semaphore, Lock, or Condition).** Eventually, some thread will wake this thread up, and put it back on the ready queue, so that it can be re-scheduled. NOTE: if there are no threads on the ready queue, that means we have no thread to run.  "Interrupt::Idle" is called to signify that we should idle the CPU until the next I/O interrupt occurs (the only thing that could cause a thread to become ready to run). NOTE: we **assume interrupts are already disabled**, because it is called from the synchronization routines which must disable interrupts for atomicity. We need interrupts off so that there can't be a time slice between pulling the first thread off the ready list, and switching to it.

Suspend the current thread and change its state to BLOCKED ; Run next ready thread ; Invoke `interrupt->Idle()` to wait for he next interrupt when readyList is empty.

Sleep is called when the current thread needs to be blocked until some future event takes place. 
E.g. Waiting for a disk read interrupt
It is called Semaphore::P() in code/threads/synch.cc
Sempaphore::V() will wake up one of the threads in the waiting queue (sleeping threads queue)

### `void Thread::Finish ()` 

Called at the end of execution, Marks a thread for termination 

Called by ThreadRoot when a thread is done executing the forked procedure. NOTE: we don't immediately de-allocate the thread data structure or the execution stack, because we're still running in the thread and we're still on the stack!  Instead, we set  threadToBeDestroyed", so that Scheduler::Run() will call the destructor, once we're running in the context of a different thread.
NOTE: we disable interrupts, so that we don't get a time slice 	between setting threadToBeDestroyed, and going to sleep.

marks current thread for destruction 
call `Sleep()` to find next thread to run and execute it 
call `Sleep()` and never wake up
Deallocate the data structure of a terminated thread
The newly scheduled thread examines the *toBeDestroyed* variable and finished this thread. The same as "terminated" in the lecture 
Terminated the currently running thread. 


---

> **system.cc and system.h (threads folder)**

### `void TimerInterruptHandler()`
Function defined in *code/threads/system.cc*
Executes whenever the associated timer expires and the interrupt is triggered 
Timer is initialized in *code/threads/system.cc* using the constructor for class Timer which is defined in *code/machine/timer.cc*

---

> **scheduler.cc and scheduler.h (threads folder)**

Maintains a list of threads that are ready to run: ready list (ready queue) <br>
The scheduler is invoked whenever the current thread gives up the CPU(non-preemptive) <br>
Simple scheduling policy is used:<br>
1. Assume equal priority for all threads
2. Select threads in **FCFS** fashion
3. Append at the end and remove from the front
<br>

`void Scheduler::ReadyToRun (Thread *thread)` Mark a thread as ready, but not running. Put it on the ready list, for later scheduling onto the CPU. "thread" is the thread to be put on the ready list. Does not start the thread yet!

`Thread *Scheduler::FindNextToRun ()` Return the next thread to be scheduled onto the CPU. If there are no ready threads, return NULL. Side effect: Thread is removed from the ready list.

`void Scheduler::Run (Thread *nextThread)` Dispatch the CPU to nextThread.  Save the state of the old thread, and load the state of the new thread, by calling the machine dependent context switch routine, SWITCH. Note: we assume the state of the previously running thread has already been changed from running to blocked or ready (depending). Side effect: The global variable currentThread becomes nextThread. "nextThread" is the thread to be put into the CPU.

1. Check whether the current thread overflowed its stack
2. Change the state of the new thread to RUNNING
3. Perform the actual context switch (by calling Switch())
4. Terminate previous thread (if applicable)


> **synch.cc**

### `void Semaphore::P()`
Wait until semaphore value > 0, then decrement.  Checking the value and decrementing must be done atomically, so we need to disable interrupts before checking the value. Note that Thread::Sleep assumes that interrupts are disabled when it is called.

### `void Semaphore::V()`
Increment semaphore value, waking up a waiter if necessary. As with P(), this operation must be atomic, so we need to disable interrupts.  Scheduler::ReadyToRun() assumes that threads are disabled when it is called.

---



## Experiment 1

> **threadtest.cc**

`void SimpleThread(_int which)` : Loop 5 times, yielding the CPU to another ready thread each iteration. "which" is simply a number identifying the thread, for debugging purposes.

`void ThreadTest()`: Set up a ping-pong between two threads, by forking a thread to call SimpleThread, and then calling SimpleThread ourselves.

This is the test procedure called from within main()

`Fork(function, arg, join)` 
1. "function": the procedure to be executed concurrently (here: SimpleThread)
2. "arg": a single parameter which is passed to the procedure (here: id of the thread(0,1,2))
3. "join": a flag which indicates whether the thread can be joined (not important for the lab)

```C++
DEBUG('t', "Entering SimpleTest");
Thread *t1 = new Thread("forked thread"); //thread constructor does only minimal initialization
t1->Fork(SimpleThread, 1, 0); //Turns a thread into one that can be scheduled and executed by the CPU
Thread *t2 = new Thread("forked thread"); 
t2->Fork(SimpleThread, 2, 0); 
SimpleThread(0); //After starting the two new threads, execute the SimpleThread function
```

`SimpleThread(_int which)`
Each thread is executing this function 
The function does nothing but prints a status line three times
the _int which is the only argument passed by fork. Here: 'which' tells you which thread


```C++
int num;
for (num=0; num<3;num++){
    printf("*** thread %d looped %d times\n", (int) which, num);
    currentThread->Yield(); //causes the current thread to give up the CPU
}

```
**Objective**: Unnderstand how thread management and scheduling works 

## Experiment 2

We need to understand non-preemptive FIFO scheduling. Understand how to schedule process/threads using round-robin strategy with a fixed time quantum. Understand how to create and reset timer interrupts to implement the fixed time quantum 

`Thread::Fork()` invoked `Scheduler::ReadyToRun()`. Appends new thread at the end of readyList

`Thread::Yield()` invokes `Scheduler::ReadyToRun()`. Adds thread back at the end readyList. 

`Thread::Yield(), Sleep(), Finish()` invoke `Scheduler::FindNextToRun()`. Selects next thread to run (head of readyList), and executes it using `Schedule::Run()`. 







##### References
All notes above are taken from NTU's CZ2005 Operating System Module and the learning materials provided. 
