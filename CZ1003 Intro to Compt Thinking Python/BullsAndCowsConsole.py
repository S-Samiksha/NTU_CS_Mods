import random

#creating the random four digit
fourDigitRandom = [random.randint(0,9), random.randint(0,9), random.randint(0,9), random.randint(0,9)]
A_Bull = 0
B_Cow_raw = 0
B_Cow_net = 0

#Checking user input
def getinput():
    count = 0
    while count < 5:
        guess = input("Please input a four digit value separated by a space: ")
        guess_list = guess.split()
        if len(guess) != 7 and len(guess_list) !=4:
            count += 1
            print("Please input FOUR digit value SEPARATED by a space: ")
        else:
          print("This is you guess value:", guess)
          break
    else:
        print("You have reached maximum trial limit")
    return guess_list

# Check Answer
while A_Bull < 4:
    # Change the input value into list
    A_Bull = 0
    B_Cow_raw = 0
    B_Cow_net = 0
    guess_list = getinput()
    for i in range(len(fourDigitRandom)):
        if fourDigitRandom[i] == int(guess_list[i]):
            A_Bull += 1
        else:
           A_Bull += 0
    for i in range(len(fourDigitRandom)):
        if fourDigitRandom in guess_list:
            B_Cow_raw +=1
        else:
          B_Cow_raw += 0
    B_Cow_net = B_Cow_raw
    print(A_Bull,"Bull", B_Cow_net, "Cow")
else:
    print("You have attained 4 Bulls. You have won the game!")
