# LabAssign4

Name: JehadMHamad

assignment number:Lab 4 project 1

what is the assignment doing:                                                                                                             
This project is implementing one of the most popular games of chance is a dice game known as "craps."

how to build your program:                                                                                                                


how to use your program:                                                                                                                  

any limitation, issues:                                                                                                                   
1) i cant find a way to stop the player form playing after they reach 0 credits without changing main you gave. the program still asks if they want to play again in which case if yes the use is stuck in a infitine loop in which they cant wager anything as credits are 0;
2) if you enter any char other than 'n' or 'N" the game still plays. so something like a '1' would allow the program to continue. cant find a way to fix this without fixing the main you gave us.
3) if you enter anything other than a int in the wager you stuck in a infinite  loop inside the invalid wager 
4) when asked if you want to play again and you enter a string like "13" the 1 is used as as way to see if you want to play again while the 3 is put into the wager as a number and plays instantly. if i were to use a string like "aa" same issue except you are stuck in a infinite loop inside the invalid wager like (3)
