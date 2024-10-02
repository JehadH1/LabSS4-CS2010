
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
static int die() {
	int d1 = rand() % 6 + 1;
	int d2 = rand() % 6 + 1;
	int sum = d1 + d2;
	cout << "player rolled " << d1 << " + " << d2 << " = " << sum << endl;
	return sum;
}


static void playGame(int* credit) {
	int cred = *credit;
	int wager = 0;
	int plyPoint = 0;
	int turns = 1;
	bool state = true;
	cout << "You have " << cred << " credits ";
	cout << "How much do you wager ";


	do {
		cin >> wager;
		if (wager <= 0 || wager > cred) {
			cout << "Invalid wager. Try again please: ";
		}
	} while (wager <= 0 || wager > cred);

	while (state) {
		cout << endl;
		int num = die();
		if (((num == 7) || (num == 11)) && (turns == 1)) {
			*credit += wager;
			cred = *credit;
			cout << "\nplayer wins \n\nyou won " << wager << " Your new balance is " << cred << " credits";
			state = false;
		}
		else if (((num == 2) || (num == 3) || (num == 12)) && (turns == 1)) {
			*credit -= wager;
			cred = *credit;
			if (*credit == 0) {
				cout << "\nyou lost " << wager << " credits You are out of credits - game over";

			}
			else {
				cout << "player loses\n\nyou lost " << wager << " Your new balance is " << cred << " credits";
			}
			state = false;
		}
		else {
			plyPoint = num;
			cout << "point is " << plyPoint << "\n";
			int newnum = 0;
			while (state) {
				newnum = die();

				if (newnum == 7) {
					*credit -= wager;
					cred = *credit;
					if (*credit == 0) {
						cout << "\nyou lost " << wager << " credits You are out of credits - game over";

					}
					else {
						cout << "player loses\n\nyou lost " << wager << " Your new balance is " << cred << " credits";
					}
					state = false;
				}
				else if (newnum == plyPoint) {
					*credit += wager;
					cred = *credit;
					cout << "player wins\n\nyou won " << wager << " Your new balance is " << cred << " credits";
					state = false;
				}

			}

		}
	}
}



int main() {
	srand(time(NULL));
	char ans;
	bool done = false;
	int credit = 100;
	while (!done) {
		playGame(&credit);
		if (credit == 0) {
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