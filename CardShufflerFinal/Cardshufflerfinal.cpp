#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

// Function to generate a full deck of cards
vector<string> generateDeck() {
    vector<string> deck;
    string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    for (const string& suit : suits) {
        for (const string& rank : ranks) {
            deck.push_back(rank + " of " + suit);
        }
    }
    return deck;
}

// Function to shuffle the deck of cards
void shuffleDeck(vector<string>& deck) {
    // Seed the random number generator with the current time
    srand(time(0));

    // Use a simple shuffling algorithm with rand()
    for (int i = deck.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1); // Generate a random index between 0 and i
        swap(deck[i], deck[j]);      // Swap the elements at i and j
    }
}

// Function to print the deck of cards
void printDeck(const vector<string>& deck) {
    for (const string& card : deck) {
        cout << card << endl;
    }
}

int main() {
    char continueShuffle = 'y'; // Initialize to 'y' to enter the loop
    bool firstShuffle = true;    // Flag to track the first shuffle

    while (continueShuffle == 'y' || continueShuffle == 'Y') {
        // Generate a full deck of cards
        vector<string> deck = generateDeck();

        // Print the original deck only for the first shuffle
        if (firstShuffle) {
            cout << "Original Deck:" << endl;
            printDeck(deck);
            cout << endl;
            firstShuffle = false; // Set the flag to false after the first shuffle
        }

        // Shuffle the deck
        shuffleDeck(deck);

        // Print the shuffled deck
        cout << "Shuffled Deck:" << endl;
        printDeck(deck);
        cout << endl;

        // Ask the user if they want to shuffle again
        cout << "Shuffle another deck? (y/n): ";
        cin >> continueShuffle;

        // Input validation:  Check for valid input.
        while (cin.fail() || (continueShuffle != 'y' && continueShuffle != 'Y' && continueShuffle != 'n' && continueShuffle != 'N')) {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            cin >> continueShuffle; //try again
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume the newline character after reading the character
    }

    cout << "Program terminated." << endl; //prints termination message
    return 0;
}
