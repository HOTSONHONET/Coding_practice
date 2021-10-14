# Problem Statement
Mustafa wants to cross a dungeon. The dungeon has N cells, and in every cell, there are M monsters. To cross each cell he has to kill one monster, on killing the monster, he loses the strength equal to that of the monster and gains some confidence which adds up in his strength and he proceeds to the next cell. Mustafa can only kill a monster if his strength is greater than or equal to the strength of the monster. Help him find the minimum strength he must have in the beginning so that he can cross N cells.


## Example:

N=3
M=3

P = 
[[3 2 5], 
[8 9 1], 
[4 7 6]]

C = 
[[1 1 1], 
[1 1 1], 
[1 1 1]]


Output:
5


## Explanation:

Let strength of mustafa be s=5
Mustafa kills 2nd monster in first cell gains the confidence equal to 1.(s=4)
Mustafa then kills 3rd Monster in second cell and gains confidence equal to 1.(s=4)
Mustafa then kills 1st monster in third cell and gains confidence equal to 1.(s=1)
So s=5 is the minimum strength required to cross the dungeon. 