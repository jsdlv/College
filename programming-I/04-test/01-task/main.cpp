#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include <random>

// Function to select a random word from the array and remove it to prevent repetition
std::string getRandomWord(std::vector<std::string> &words) {
    if (words.empty()) {
        return "";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, words.size() - 1);
    int randomIndex = dist(gen);
    std::string word = words[randomIndex];
    words.erase(words.begin() + randomIndex);
    return word;
}

// Function to display the word with dots representing unguessed letters
std::string getWordDisplay(const std::string &word, const std::string &guessedLetters) {
    std::string display;
    for (char letter: word) {
        if (guessedLetters.find(letter) != std::string::npos) {
            display += letter;
        } else {
            display += '.';
        }
    }
    return display;
}

int main() {
    // Array with words
    std::vector<std::string> words = {
            "apple", "banana", "orange", "strawberry", "grape", "mango",
            "pineapple", "kiwi", "pear", "apricot", "plum", "cherry",
            "peach", "lemon", "lime", "coconut", "papaya", "fig",
            "persimmon", "grapefruit"
    };

    // Seed random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    int penaltyPoints = 0;
    int guessedWords = 0;

    while (penaltyPoints < 10) {
        std::string secretWord = getRandomWord(words);

        if (secretWord.empty()) {
            break; // No more words to guess
        }

        std::string guessedLetters;
        std::string wordDisplay = getWordDisplay(secretWord, guessedLetters);

        std::cout << "Guess the word: " << wordDisplay << std::endl;

        while (true) {
            char guess;
            std::cout << "Enter a letter (or '0' to quit): ";
            std::cin >> guess;

            if (guess == '0') {
                std::cout << "Game over. You quit!" << std::endl;
                return 0;
            }

            if (secretWord.find(guess) != std::string::npos) {
                guessedLetters += guess;
                wordDisplay = getWordDisplay(secretWord, guessedLetters);
                std::cout << "Correct guess: " << wordDisplay << std::endl;
                if (wordDisplay == secretWord) {
                    guessedWords++;
                    penaltyPoints -= 5;
                    std::cout << "Congratulations! You guessed the word." << std::endl;
                    break;
                }
            } else {
                std::cout << "Wrong guess! Penalty point added." << std::endl;
                penaltyPoints++;
            }

            if (penaltyPoints >= 10) {
                std::cout << "Game over. You reached 10 penalty points!" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "Game over. You successfully guessed " << guessedWords << " words!" << std::endl;
    return 0;
}
