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
with visibility and texture representation, which holds a private member of class Graph.

The board holds a matrix of pointers to Pipe types, and the Graph holds a matrix of Vertex types. Each vertex is mapped onto
a corresponding pipe.

This way we can access the private members via 2 entries, and both will be used depending on the context.
For example, rotation will update the texture, which will update the vertices, and the BFS algorithm will update the vertices, 
which will update the pipes. 

All the pipe types inherit from BasePipe.

All textures, fonts, and sounds are generated in singleton classes named Textures, Fonts and Sounds.


