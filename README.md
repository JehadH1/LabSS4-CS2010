# LabAssign4

Name: JehadMHamad

assignment number:Lab 4 project 1

what is the assignment doing: 
This project is implementing one of the most popular games of chance is a dice game known as "craps."

how to build your program:                                                                                                                
You only need two core functions to build this program
die(): This function will use the random number generator to simulate rolling two dice, returning their combined sum.
playGame(): This function will implement the rules of craps using loops and conditional statements. It will repeatedly call die() to get the result of dice rolls and determine whether the player has won or lost based on the rules.
In addition to these functions, you’ll need to manage variables like credits, wager, and roll. Make sure to define credits as a global variable so that its value persists across multiple rounds of the game.
Use a do-while loop to ensure the player makes a valid wager. If the wager is greater than their available credits or a negative amount, prompt them to try again.
The game mechanics work as follows: on the first roll, store the result in a variable. If the result is 7 or 11, the player wins and their wager amount is doubled and have a new credit amount and can choose to play again. If the result is 2, 3, or 12, the player loses and their wager amount is subtarcted and they have a new credit amount and can decide to play again. If the result is any other number, it becomes the "point" number. The player will continue rolling in a loop until they either roll the point number again (which means they win (wager doubled)) or roll a 7 (which means they lose(wager subtarcted)). In both cases, they’ll have the option to play another round.

how to use your program:                                                                                                                  
enter a number for your wager between 0 and credit amount, if you dont program will ask you again till you do.
Then the program will show you the results of the die throw, which would be an instant win or loss or  the chance  to have your drice throw be a set point. in that case you will keep rolling till you roll the set point number which means win, if its a 7 you lose.
In both cases, they’ll have the option to play another round, if you want to play again enter 'y' which will let you play again but this time your credits are from 0 till your new amount depending on if you won or lost. if not program ends.

any limitation, issues:                                                                                                                   
1) i cant find a way to stop the player form playing after they reach 0 credits without changing main you gave. the program still asks if they want to play again in which case if yes the use is stuck in a infitine loop in which they cant wager anything as credits are 0;
2) if you enter any char other than 'n' or 'N" the game still plays. so something like a '1' would allow the program to continue. cant find a way to fix this without fixing the main you gave us.
3) if you enter anything other than a int in the wager you stuck in a infinite  loop inside the invalid wager 
4) when asked if you want to play again and you enter a string like "13" the 1 is used as as way to see if you want to play again while the 3 is put into the wager as a number and plays instantly. if i were to use a string like "aa" same issue except you are stuck in a infinite loop inside the invalid wager like (3)
