![img](https://i.imgur.com/91AFoZg.png)
# Pipe: An academic exercise
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
3 5
ASAKA
BSASA
ASASA
```

where:
* The rows and the columns MUST BE AT THE BEGINNING of each level, with no \n in between levels
* Y indicates straight Pipe
* A indicates curved pipe
* S indicates three-way pipe 
* B indicates tap
* K indicates sink

If the map.txt file does not as described, an exception will be thrown, and a message will be written onto a file named "log.txt".
