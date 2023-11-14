#include <iostream>
#include <sstream>

using namespace std;

string input = "3 HANGMAN 8 A E m n h a , g CAT 6 d o g D O G PYTHON 10 C + + J A V A P H P";
istringstream sin (input);

void doSingleTest();
void beginGame(string secretWord);
void printEmptyGallows();
void printHiddenWord(string secretWord);
void printGuesses(string correctLetters);
bool isMistake(char guessedChar, string correctLatters);
bool isLatinLatter(char guessedChar);
bool wasAlreadyProposed(string correctLatters, char guessedChar);
int n = 2;
int main()
{
    sin >> n;
    for(int i = 0; i < n; i++)
    {
        doSingleTest();
    }
}
//TO DO
void doSingleTest()
{
    string secretWord;
    sin >> secretWord;
    int charsNumber;
    sin >> charsNumber;
    beginGame(secretWord);
    int mistakesLeft = 7;
    string correctLetters = "";
    for(int i = 0; i < charsNumber; i++)
    {
        cout << "Number of mistakes left: " << mistakesLeft << endl;
        printGuesses(correctLetters);
        cout << "Please guess a letter!" << endl;
        char guessedChar;
        sin >> guessedChar;
        cout << "Your choice: " << guessedChar << endl;
        bool isLetterWrong = isMistake(guessedChar, correctLetters);
    }

}
//DONE
void beginGame(string secretWord)
{
    cout << "Welcome to the Hangman Game!" << endl;
    printEmptyGallows();
    cout << "Secret word:" << endl;
    printHiddenWord(secretWord);
}
//DONE
void printEmptyGallows()
{
    cout <<
R"(+---------------------+
|    ____________     |
|    |/               |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|  __|__              |
+---------------------+
)";
}
//DONE
void printHiddenWord(string secretWord)
{
    for(int i = 0; i < secretWord.size(); i++)
    {
        cout << "_" << " ";
    }
    cout << endl;
}
//DONE
void printGuesses(string correctLetters)
{
    if("" == correctLetters)
    {
        cout << "Guesses: -" << endl;
    }
    else
    {
        cout << "Guesses: " << correctLetters << endl;
    }
}
//TO DO
bool isMistake(char guessedChar, string correctLatters)
{
    if(not isLatinLatter(guessedChar))
    {
        cout << "Only Latin alphabet letters" << endl;
        return true;
    }
    if(wasAlreadyProposed(correctLatters, guessedChar))
    {
        cout << "You've already guessed that letter!" << endl;
        return true;
    }
    return false;
}

//  DONE
bool isLatinLatter(char guessedChar)
{
    if(guessedChar >= 'a' and guessedChar <= 'z')
    {
        return true;
    }
    if(guessedChar >= 'A' and guessedChar <= 'Z')
    {
        return true;
    }
    return false;
}
//TODO
bool wasAlreadyProposed(string correctLatters, char guessedChar)
{
    std::size_t found = correctLatters.find(guessedChar);
    if (found != std::string::npos)
    {
        return true;
    }
    return false;
}
