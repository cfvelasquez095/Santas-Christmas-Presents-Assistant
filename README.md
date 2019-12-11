# Santa's Christmas Presents Assistant
> An Algorithm Analysis Project


The purpose of this project is to solve a problem presented to us in the Algorithm Analysis class.

The problem itself consists of Santa Claus requiring help from his elves in order to determine which kids will be receiving
a gift this Christmas. Santa will read two lists, a nice list and a naughty list, to his elves. Each list contains the same
amount of kids (each kid will appear in both lists) but different amount of actions made by them. Santa will ask the elves
for a certain amount of kids with their ID's and the elves will help him determine if they will receive a gift or not. 

## Installation

Linux:

```sh
cd Santas-Christmas-Presents-Assistant/
g++ -o presents christmasPresents.cpp
./presents
```

## Usage

Once the program is compiled and you execute it, you will be required to provide the data in the following order:
1. First line will indicate the amount of kids you will be adding into the lists.
2. Second line will indicate the minimum amount of good actions that a kid should have in order to receive a gift.
3. The following lines will correspond to the data going into each list. Each line will have the following format: id #_of_actions
4. After the data is provided for both lists, the following line will indicate how many kids you want to query
5. Then, you will provide the ID's of the kids you want to query based on the previous line. All ID's will be in the same line here.
6. You will be provided with the result for your query in the following way: 0 1 1 0 0, where 0 stands for no gift and 1 stands for gift.