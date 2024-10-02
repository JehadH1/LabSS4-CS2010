
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int credits = 100; 

static int die() {
	int d1 = rand() % 6 + 1;
	int d2 = rand() % 6 + 1;
	int sum = d1 + d2;
	cout << "player rolled " << d1 << " + " << d2 << " = " << sum << endl;
	return sum;
}


static void playGame() {
	
	int wager = 0;
	int playPoint = 0;
	
	bool playing = true;
	cout << "You have " << credits << " credits ";
	cout << "How much do you wager ";


	do {
		cin >> wager;
		if (wager <= 0 || wager > credits) {
			cout << "Invalid wager. Try again please: ";
		}
	} while (wager <= 0 || wager > credits);

	while (playing) {
		cout << endl;
		int roll = die();

		if ((roll == 7) || (roll == 11)) {
			credits += wager;
			
			cout << "\nplayer wins \n\nyou won " << wager << " Your new balance is " << credits << " credits";
			playing = false;
		}
		else if ((roll == 2) || (roll == 3) || (roll == 12)) {
			credits -= wager;
			
			if (credits == 0) {
				cout << "\nyou lost " << wager << " credits You are out of credits - game over";

			}
			else {
				cout << "player loses\n\nyou lost " << wager << " Your new balance is " << credits << " credits";
			}
			playing = false;
		}
		else {
			playPoint = roll;
			cout << "point is " << playPoint << "\n";
			int newRoll = 0;
			while (playing) {
				newRoll = die();

				if (newRoll == 7) {
					credits -= wager;
					
					if (credits == 0) {
						cout << "\nyou lost " << wager << " credits You are out of credits - game over";

					}
					else {
						cout << "player loses\n\nyou lost " << wager << " Your new balance is " << credits << " credits";
					}
					playing = false;
				}
				else if (newRoll == playPoint) {
					credits += wager;
					
					cout << "player wins\n\nyou won " << wager << " Your new balance is " << credits << " credits";
					playing = false;
				}

			}

		}
	}
}



int main() {
	srand(time(NULL));
	char ans;
	bool done = false;
	while (!done) {
		playGame();
		if (credits == 0) {
			break;
		}
		cout << " Play again (y/n) ? ";
		cin >> ans;
		if (ans == 'n' || ans == 'N') done = true;
		else done = false;
		cout << endl;
	}
	return 0;
}