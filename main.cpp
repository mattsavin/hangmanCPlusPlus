#include <iostream>
#include <string>
#include <vector>
#include <random>

std::string chooseWord()
{
    const std::vector<std::string> WORDS {"abruptly", "absurd", "abyss", "affix"};
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, WORDS.size()-1);
    return WORDS[dist6(rng)];
}

std::string hangmanStatus(int guesses)
{
    const std::vector HANGMAN_PICS {
        " +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };

    return HANGMAN_PICS[guesses];
}


int main()
{
    std::string word = chooseWord();
    std::string guess;
    std::string guessedWord {std::string(word.length(), '_')};
    int guesses = 0;
    while(guesses <= 7)
    {
        std::cout << guessedWord << std::endl;
        std::cin >> guess;
        if (guess == word)
        {
            std::cout << "Correct! The word was: " << word << std::endl;
            break;
        }
        for (int i = 0; i < guess.length()-1; ++i)
        {
            if (word.find(guess[i]) != std::string::npos)
            {

            }
        }
        std::cout << guess << std::endl;
        std::cout << hangmanStatus(guesses) << std::endl;
        guesses++;
    }
    return 0;
}
