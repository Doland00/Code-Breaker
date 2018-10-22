/*
	Don Morton
	10/21/2018
	Code Breaking
*/

// Word Jumble / Code breaker

// basic funtions always included
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = //these are the 10 words to unjumble first "" fills the array of NUM_WORDS secodn fills the array of NUM_FIELDS
	{
		{"wall", "Do you feel like you are banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly is it?"},
		{"persistent", "Keep at it!"},
		{"jumble", "Its what the game is all about."},
		{"oragne", "Perhaps you shoudl get a citrusy drink?"},
		{"clock", "How long have you been working on this?"},
		{"chair", "Maybe you should stop sitting around?"},
		{"wizard", "If you can geuss this one then you will be one."},
		{"apple", "This will help you stay healthy."},
	};

	srand(static_cast<unsigned int>(time(0))); // puts us in a random spot in the random library
	int choice; 
	string theWord; // establishes the word that we will guess
	string theHint;  // gives the player the hint

	string jumble;
	int length; 
	cout << "\t\tWelcome to the CIA Code Breaker training program.\n\n";
	cout << "You will be given a random word and you need to unscramble it.\nBefore the terrorist can complete their objective.\n";
	cout << "If you need a hint just type the word 'hint' into the prompt.\n";
	cout << "There are no capitol letters in these answers";
	cout << "If you are done with your training you can exit the program by entering 'quit'.\n\n";

	string guess;

	bool cont = true;
	char again = 'y';

	while (cont)
	{
		choice = (rand() % NUM_WORDS);
		theWord = WORDS[choice][WORD]; // assigns the word to be figured out
		theHint = WORDS[choice][HINT]; // gives player a hint
		jumble = theWord; // jumbles the word randomly
		length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		cout << "Your first challenge word is: " << jumble << "\n Unscramble this word.";

		cout << "\nYour guess is: ";
		cin >> guess;
		int tries = 1;


		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry that is not the right word. Terrorists just blew up the Eiffel Tower.";
				++tries;
			}

			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			cout << "This is the correct word. You have stopped the bombing of the Statue of Liberty.\n";
			cout << "It took you " << tries << " attempts to stop the terrorists.\n";
		}


		cout << "Would you like to play again?";
		cin >> again;
		if (again == 'n' || again == 'N') {
			cont = false;
		}
	}

	cout << "\nThanks for playing.\n";

	return 0;
}