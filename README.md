# AStarSearch
A* heuristic search

Project 1: A* Heuristic Search

 

For this project, you will continue from lab 3 and implement A* search for the turtle pathfinding problem. You have 3 weeks to work on it. Do not wait until the last day.

Search Space:  The world is represented by an M-by-N 2-dimensional grid.  M and N are not necessarily the same.

Each grid cell can be referred to by its row and column coordinates.

One grid cell is marked as the initial location (in blue), and another cell is marked as the goal location (in red).  All cells marked in gray are obstacles (not passable).

Only four actions are allowed in this problem: move left by 1, move right by 1, move up by 1, and move down by 1.  No diagonal movements are allowed.

You program should find a solution, which is a sequence of grid locations that leads to the goal location.

 

Download the GUI: PathFindingAssignmentInterface.zip

 

Requirements:

In order for your turtle code to work correctly with the GUI, your program should, in order,

Cin two numbers, which are the number of rows and the number of columns of the grid.
Cin two numbers, the row and column numbers of the starting location.
Cin two numbers, the row and column numbers of the goal location.
Cin one number, which is the number of obstacles (gray cells).
For each obstacle:
-- Cin two numbers, the row and column numbers of the obstacle location.

The program should then use A* to find an optimal path to the goal. As A* is running, the program should output (using cout) each node that the A* algorithm is considering as potential nodes to expand (open list), one by one, in this format:

row# column#
row# column#
row# column#
row# column#
row# column#
row# column#
row# column#
-1 -1                             (this is exactly cout << "-1 (space) -1" << endl; )

The -1 (space) -1 signals to the GUI that your A* search has finished, and this is the end of the open list output.

Next you will output (using cout) the solution (a path for the turtle to take), in this format:

row# column#
row# column#
row# column#
row# column#
row# column#
row# column#
-1 -1

Again, here -1 (space) -1 signals to the GUI that this is the end of the outputs.

 

Additional notes:

Each node should be storing the following information:

struct node {
  int x, y;                       // its own row and column
  int parentX, parentY; // row and column of its parent
  int g;                          // its g value
  int h;                          // its h value
};

Any cerr outputs will be saved to the log file. Use it for debug purposes.

If you have trouble with the GUI not stopping properly, make sure to end your main() function with

    cerr << endl;
    cout.flush();
    system("pause");
    return 0;

A* pseudocode is in slides of lecture 7.

 

Documentation:

As part of the project, you will submit a document with:

Part A. Screenshots of five test cases you have designed, running A*.

Part B. Answers to the following questions:

1. What data structure (queue, list, vector, etc) did you use to implement your open list?  Why did you choose it? 

2. What data structure (queue, list, vector, etc) did you use to implement your closed list?  Why did you choose it? 

3. Is your open list sorted? Why or why not?

4. Is your closed list sorted?  Why or why not?

5. Does your A* AI expand the same nodes as the provided TurtleAStar?  What is different?

 

Grading Rubric:

Partial credits could be assigned in all cases when possible.

10 Points for following format specifications: your code does not crash the pathfinding GUI program.
10 Points for readability: code is clean, understandable, and well-organized.
10 Points for correctly implementing an open list.
10 Points for correctly implementing a closed list.
20 Points for correctly implementing the rest of A* and producing an optimal path.
10 Points for submitting five test cases.
10 Points for passing five additional test cases I have prepared. Testing will be done from the GUI, unless your code crashes the GUI.
20 Points for documentation: answering the questions.
Total: 100 points

 


Deliverables:

The assignment counts toward your programming assignment grade.

Submit your source code C++ project (including all project files such as the .sln file) as a zip file.

Submit the documentation as a text, pdf, or Word file.
