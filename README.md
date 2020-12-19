# Gaze_Maze_Solver
Simple brute force tool created to solve mazes for Stage 7 of the game "I wanna Gaze at the Horizon"

"I wanna Gaze at the Horizon" is a (very)highly difficult puzzle platformer consisting of 9 stages. This tool was created in order to automatically solve instances of the lowest point of that game - a kind of puzzle that requires too much brute forcing and too little actual thinking.

The puzzle works as follows: The player is given a large maze, consisting of several doors (Labeled by lower case letters) and several keys (Labeled by upper case letters). Each key has a COLOR, and it can only open doors with the same color. The colors are as follows:
------- Key | Door |
Blue:    B  |  b   |
Cyan:    C  |  c   |
Green:   G  |  g   |
Magenta: M  |  m   |
Purple:  P  |  p   |
Yellow:  Y  |  y   |
--------------------
The goal of the puzzle is to reach a portal, labeled as '@', by collecting keys and opening as many doors as necessary. For each instance of a maze, it must be guaranteed that a solution exists, i.e. there is an order in which the player can open the doors that leads to the exit portal. In addition, walls are labeled as '-', while free spaces are labeled as '.'


Here's a sample maze that can easily be solved by a human:
---------
-@Bb.Yy.*
---------

Where * denotes the player's starting position. However, note that the player's starting position must be input manually in the tool.
Upon receiving an input in the adequate format, the tool will return a set of coordinates, representing the order in which the doors must be opened. In the above example, the tool would return the following set of coordinates:
1 5
1 2
i.e., the player must (obviously) open the yellow door first, then the blue door.

Note that, despite the algorithm's immense asymptotic complexity, it generally succeeds in quickly generating a solution, provided that a solution exists.
