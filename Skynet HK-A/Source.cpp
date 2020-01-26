#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(0)));
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	int actualTargetLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	int tries = 0;
	int attemptToLocateTarget = rand() % searchGridHighNumber + searchGridLowNumber;

	cout << "\n\n\tWelcome to the AI Drone Hunter 3000! \n" << endl;

	do {
		cout << " -------------------------------------------------" << endl;
		cout << " The real target location is in sector " << actualTargetLocation << endl;
		attemptToLocateTarget = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		cout << " The AI guesses that the target is in sector " << attemptToLocateTarget << endl;
		++tries;

		if (attemptToLocateTarget > actualTargetLocation) {
			cout << " The AI target prediction was too high" << endl;
			searchGridHighNumber = attemptToLocateTarget - 1;
			cout << " -------------------------------------------------\n" << endl;
		} else if (attemptToLocateTarget < actualTargetLocation) {
			cout << " The AI target prediction was too low" << endl;
			searchGridLowNumber = attemptToLocateTarget + 1;
			cout << " -------------------------------------------------\n" << endl;
		} else {
			cout << " That's it! The AI found the target in " << tries << " predictions!" << endl;
			cout << " -------------------------------------------------" << endl;
		}
	} while (attemptToLocateTarget != actualTargetLocation);

	return 0;
}