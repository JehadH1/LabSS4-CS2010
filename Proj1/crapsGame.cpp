#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

static int die();
static void playGame(int &credits);
static void winner(int& credits, int& wager, bool& playing);
static void loser(int& credits, int& wager, bool& playing);

int main() {
	int credits = 100;
	//My main which will call my playGame function
	srand(time(NULL));
	string ans = "n";
	bool done = false;
	//this while loop is used to see of you are done playing or not;
	while (!done) {
		playGame(credits);
		//this part of the loop is used to break out of the game if you have zero credits as you cant play again
		if (credits == 0) {
			break;
		}

		cout << " Play again (y/n) ? ";
		//while loop here will loop till you give it a string thats a y or n.
		//if you dont it will keep you here.
		while (ans != "n" || ans != "N" || ans != "y" || ans != "y") {
			cin >> ans;
			if (ans == "n" || ans == "N") {
				done = true;
				break;
			}
			else if (ans == "y" || ans == "y") {
				done = false;
				break;
			}
			else
				cout << "enter either a y or n : ";
		}

		cout << endl;
	}
	return 0;
}

static int die() {
	//function for dice roll that will roll two dice and return thier some
	int d1 = rand() % 6 + 1;
	int d2 = rand() % 6 + 1;
	int sum = d1 + d2;
	cout << "player rolled " << d1 << " + " << d2 << " = " << sum << endl;
	return sum;
}
static void winner(int& credits, int& wager, bool& playing) {
	credits += wager;

	cout << "player wins\n\nyou won " << wager << " Your new balance is " << credits << " credits";
	playing = false;
}
static void loser(int& credits, int& wager, bool& playing) {
	credits -= wager;
	//checks if you lost all your credits
	if (credits == 0) {
		cout << "\nyou lost " << wager << " credits You are out of credits - game over";
	}
	else {
		cout << "player loses\n\nyou lost " << wager << " Your new balance is " << credits << " credits";
	}
	playing = false;
}

static void playGame(int &credits) {
	//function for playGame, will implement the rules for craps
	int wager = 0;
	int playPoint = 0;
	bool playing = true;

	cout << "You have " << credits << " credits \n";
	cout << "How much do you wager: ";

	//wager part of my game, will chech if you gave it the right values if not will continue to loop till you do.
	//if you give it a double, will cast it as a int and let you play.
	while (wager <= 0 || wager > credits) {
		cin >> wager;
		if (wager <= 0 || wager > credits) {
			//if you eneter a letter will clear and ignore your input
			cin.clear();
			cin.ignore();
			cout << "Invalid wager. Try again please: ";
		}
	}

	//main body for the game, while loop continues as long as you play
	//the if and else if part are used to check for the instant wins
	while (playing) {
		cout << endl;
		int roll = die();

		if ((roll == 7) || (roll == 11)) {
			winner(credits, wager, playing);
		}
		else if ((roll == 2) || (roll == 3) || (roll == 12)) {
			loser(credits, wager, playing);
		}
		//This else if used to make you sum the play point if you didnt instantly win.
		else {
			playPoint = roll;
			cout << "point is " << playPoint << "\n";
			int newRoll = 0;
			//While loop will continue to go till you reroll your setpoint which means you win
			//Or you roll a seven which means you have lost
			while (playing) {
				newRoll = die();

				if (newRoll == 7) {
					loser(credits, wager, playing);
				}
				else if (newRoll == playPoint) {
					winner(credits, wager, playing);
				}
			}
		}
	}
}

