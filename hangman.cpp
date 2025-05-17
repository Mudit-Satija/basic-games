#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Function to display the hangman based on remaining lives
void displayHangman(int lives) {
    switch (lives) {
        case 6:
            cout << R"(
  +---+
  |   |
      |
      |
      |
      |
=========
)";
            break;
        case 5:
            cout << R"(
  +---+
  |   |
  O   |
      |
      |
      |
=========
)";
            break;
        case 4:
            cout << R"(
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
)";
            break;
        case 3:
            cout << R"(
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========
)";
            break;
        case 2:
            cout << R"(
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
)";
            break;
        case 1:
            cout << R"(
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
)";
            break;
        case 0:
            cout << R"(
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
)";
            break;
    }
}

int main() {
    vector<string> words = {"gangotri"};
    srand(time(0)); // Random seed
    string word = words[rand() % words.size()]; // Randomly chosen word

    string guessedWord(word.length(), '_'); // Blanks
    int lives = 6;
    vector<char> guessedLetters;

    cout << "🎮 Welcome to Hangman!\n";
    cout << "Guess the word letter by letter.\nYou have 6 lives. Good luck!\n";

    while (lives > 0 && guessedWord != word) {
        cout << "\nWord: " << guessedWord << "\n";
        cout << "Lives left: " << lives << "\n";
        displayHangman(lives);
        cout << "Guessed letters: ";
        for (char c : guessedLetters) cout << c << " ";
        cout << "\nGuess a letter: ";

        char guess;
        cin >> guess;

        // Convert guess to lowercase for uniformity
        guess = tolower(guess);

        // Check if letter was already guessed
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "⚠️ You already guessed that letter. Try another one.\n";
            continue;
        }

        guessedLetters.push_back(guess);

        // Check if the guessed letter is in the word
        bool found = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (!found) {
            lives--;
            cout << "❌ Wrong guess!\n";
        } else {
            cout << "✅ Good job! Letter found.\n";
        }
    }

    // Final Result
    if (guessedWord == word) {
        cout << "\n🎉 Congratulations! You guessed the word: " << word << "\n";
    } else {
        displayHangman(0);
        cout << "\n💀 Game Over! The correct word was: " << word << "\n";
    }

    return 0;
}
