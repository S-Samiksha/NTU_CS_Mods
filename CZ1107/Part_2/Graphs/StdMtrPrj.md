## Student Project Mentor Explained thoroughly 

# Firstly create the graph...

You need a double layer for the student such that we can take care of extreme cases. 

0:	3 -> 2 -> 1 -> <br>
1:	7 -> 6 -> 4 -> <br>
2:	5 -> <br>
3:	7 -> 6 -> 5 -> 4 -> <br>
4:	8 -> <br>
5:	9 -> <br>
6:	10 -> <br>
7:	11 -> <br>
8:	12 -> 13 -> <br> 
9:	13 -> 12 -> <br>
10:	13 -> 12 -> <br>
11:	14 -> <br>
12:	15 -> <br>
13:	15 -> <br>
14:	15 -> <br>
15: <br>


Firstly, connecting the node 0 which is the source to the projects which are 1, 2, and 3. 

Secondly, connecting the node 15 which is the sink to the mentor. Meaning Mentor point to sink. 

Then for every student, connect the project, connect the student layer, connect student to mentor. 

In other words, nodes 4, 5, 6, 7 interact with nodes 1, 2, 3. AND nodes 8, 9, 10, 11 interact with 12, 13, 14.


# Breadth First Search is used
you firstly find one pathway, in this particular case it is 0->3->7->11->14->15

this pathway is stored in the pred variable 


# Matching
for each -> it has to switch becoming <-  to prevent traversing this route again. 

so from 0->3->7->11->14->15 we get 15->14->11->7->3->0 