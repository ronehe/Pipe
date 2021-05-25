# Pipe: An academic exercise
![img](https://i.imgur.com/91AFoZg.png)
This is the fourh academic exercise of the course OOP2.
* 

Main objective: to create a game based on [pipe](https://www.crazygames.com/game/pipe)

## Setup and guidelines
This game consists of puzzles to the user' choice using custom building blocks that are described below written onto a text file.
There is no limitation to the amount of puzzles that can be inserted.

The provided file must be called "map.txt" and must be of the following form:

```
4 8
YAYSSYAY
YSSYBAAA
KAYAAASY
AYSSYAYB
8 8
BASSSAYY
AYSAYSAS
AAYYSYAS
SASAYAYY
SAASSSYS
SYYYSAAA
AYAASYSA
AKSYAYAA
6 6
BSYYSA
YYAYAS
YYYKYY
YAYYSY
SAYAAS
SSSYYA
```

where:
* The rows and the columns MUST BE AT THE BEGINNING of each level, with no \n in between levels
* Y indicates straight Pipe
* A indicates curved pipe
* S indicates three-way pipe 
* B indicates tap
* K indicates sink

If the map.txt file does not as described, an exception will be thrown, and a message will be written onto a file named "log.txt".

## Main ideas and implementations

The core idea was to distinguish between the inside mechanism that maintains validity of game during execution, 
and between the texture representation of it. So, we created the Board class that will maintain all that has to do
with visibility and texture representation, which holds a private member of class Graph, which handles all algorithmic aspects needed
for maintaining validity.

The board holds a matrix of pointers to Pipe types, and the Graph holds a matrix of Vertex types. Each vertex is mapped onto
a corresponding pipe.

This way we can access the private members via 2 entries, and both will be used depending on the context.
For example, rotation will update the texture, which will update the vertices, and the BFS algorithm will update the vertices, 
which will update the pipes. 

All the pipe types inherit from BasePipe.

### important points
* the neighbors of each pipe are computed in run-time.
* The pipes are inserted at default orientation and shuffled at the beginning of the game
* number of rotations is number of taps
*The BFS was taken from [here](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)

All textures, fonts, and sounds are generated in singleton classes named Textures, Fonts and Sounds.


### Classes

* Board: handle all board related objects, mainly focuses on texture and connection with the graph
	It holds a matrix of pipes that represent what the player sees.

* Graph: handle all "backstage" related objects - mainly the vertices. It handles the entire algorithmic aspect of the game,
and is mainly for maintaining order and for making sure the game remains valid for the entire game.

* Vertex: an object that is an instance of a pipe as a "backstage" object. It is the algorithmic representation of it,
and is the main tool in which the algorithms work on. It holds a pointer to the texture representation of the pipe.

* BasePipe: an object that is an instance of the texture representation of the pipe. It is what the player sees and it is the main
source of interaction. 
 
* ThreeWayPipe, CurvedPipe, StriahtPipe, Sink, Tap: objects that inherit from BasePipe and each has its own texture 
and are the buildinig blocks of the board. They don't do much and have minor responsability.

FileHandler: an object that is responsible for handling input operations, mainly for the text reading before reading the map

* singletons: Fonts, Textures, Sounds are all independent singletons that each responsible for importing the needed information, 
based on name

* Controller: holds everything together. It runs the game and handles main loop of events, and is responsible for connecting all parts
of the program together, such as the FileHandler to the board. It is also responsible for taking 
### Files created
-everything mentioned above

### Noteworthy Algorithms
### Known Bugs

