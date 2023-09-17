#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

// Function to select a random word from an array
std::string getRandomWord(const std::string words[], int wordCount) {
    int randomIndex = rand() % wordCount;
    return words[randomIndex];
}

// Function to check if a letter is in the word
bool isLetterInWord(char letter, const std::string &word) {
    return word.find(letter) != std::string::npos;
}

// Function to update the display of guessed letters
std::string updateGuessedWord(char letter, const std::string &word, const std::string &guessedWord) {
    std::string updatedWord = guessedWord;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == letter) {
            updatedWord[i] = letter;
        }
    }
    return updatedWord;
}

int main() {
    // Array with words
    const std::string WORDS[] = {
            "apple", "banana", "orange", "strawberry", "grape", "mango",
            "pineapple", "kiwi", "pear", "apricot", "plum", "cherry",
            "peach", "lemon", "lime", "coconut", "papaya", "fig",
            "persimmon", "grapefruit"
    };
    const int WORD_COUNT = sizeof(WORDS) / sizeof(WORDS[0]);

    // Seed random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Select a random word for the game
    std::string secretWord = getRandomWord(WORDS, WORD_COUNT);

    // Set variables for the game
    const int MAX_WRONG_ATTEMPTS = 10;
    std::string guessedWordDisplay(secretWord.size(), '.');
    std::string usedLetters;
    int wrongAttempts = 0;

    // Game loop
    while (wrongAttempts < MAX_WRONG_ATTEMPTS && guessedWordDisplay != secretWord) {
        std::cout << "Wrong attempts: " << wrongAttempts << std::endl;
        std::cout << "Guessed word so far: " << guessedWordDisplay << std::endl;
        std::cout << "Used letters: " << usedLetters << std::endl;

        char guessedLetter;
        std::cout << "Enter a letter: ";
        std::cin >> guessedLetter;

        if (isLetterInWord(guessedLetter, secretWord)) {
            guessedWordDisplay = updateGuessedWord(guessedLetter, secretWord, guessedWordDisplay);
        } else {
            std::cout << "Wrong guess! Penalty point added." << std::endl;
            ++wrongAttempts;
            usedLetters += guessedLetter;
        }
    }

    // Game result
    if (wrongAttempts == MAX_WRONG_ATTEMPTS) {
        std::cout << "You lost! The word was: " << secretWord << std::endl;
    } else {
        std::cout << "Congratulations! You guessed correctly: " << secretWord << std::endl;
    }

    return 0;
}