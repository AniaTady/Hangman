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
bool isMistake(char guessedChar, string correctLatters, string secretWord);
bool isLatinLatter(char guessedChar);
bool wasAlreadyProposed(string correctLatters, char guessedChar);
bool foundInSecretWord(string secretWord, char guessedChar);
bool isItWon(string secretWord, char guessedChar, string correctLatters);
bool isTheLetterGuessed(char singleLetter, string correctLatters);
void printHangman(int mistakesLeft);
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
        bool isLetterWrong = isMistake(guessedChar, correctLetters, secretWord);
        if(isItWon(secretWord, guessedChar, correctLetters))
        {
            cout << endl;
        }
        else
        {
            cout << "Nice!" << endl;
        }
        //KONTYNUACJA 6a?
        if(isLetterWrong == true)
        {
            mistakesLeft -= 1;
            printHangman(mistakesLeft);
        }
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
//DONE
bool isMistake(char guessedChar, string correctLatters, string secretWord)
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
    if(not foundInSecretWord(secretWord, guessedChar))
    {
        cout << "Nope!" << endl;
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
//DONE
bool wasAlreadyProposed(string correctLatters, char guessedChar)
{
    size_t found = correctLatters.find(guessedChar);
    if (found != string::npos)
    {
        return true;
    }
    return false;
}
//DONE
bool foundInSecretWord(string secretWord, char guessedChar)
{
    size_t found = secretWord.find(guessedChar);
    if (found == string::npos)
    {
        return false;
    }
    return true;
}
//DONE
bool isItWon(string secretWord, char guessedChar, string correctLatters)
{
    bool areAllTheLettersGuessed = true;
    for(int i = 0; i < secretWord.size(); i++)
    {
        if(isTheLetterGuessed(secretWord[i], correctLatters))
        {
            areAllTheLettersGuessed = false;
            break;
        }
    }
    return areAllTheLettersGuessed;
}
//DONE
bool isTheLetterGuessed(char singleLetter, string correctLatters)
{
    size_t found = correctLatters.find(singleLetter);
    if (found != string::npos)
    {
        return true;
    }
    return false;
}
//TO DO
void printHangman(int mistakesLeft)
{
    switch(mistakesLeft)
    {
    case 7:
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
        break;
    case 6:
        cout <<
R"(+---------------------+
|    ____________     |
|    |/         |     |
|    |          |     |
|    |          |     |
|    |          &     |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|  __|__              |
+---------------------+
)";
        break;
    case 5:
        cout <<
R"(+---------------------+
|    ____________     |
|    |/         |     |
|    |          |     |
|    |         (_)    |
|    |          &     |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|    |                |
|  __|__              |
+---------------------+
)";
        break;
    case 4:
        cout <<
R"(+---------------------+
|    ____________     |
|    |/         |     |
|    |          |     |
|    |         (_)    |
|    |          &     |
|    |          |     |
|    |          |     |
|    |          |     |
|    |                |
|    |                |
|    |                |
|  __|__              |
+---------------------+
)";
        break;
    case 3:
        cout <<
R"(+---------------------+
|    ____________     |
|    |/         |     |
|    |          |     |
|    |         (_)    |
|    |          &     |
|    |         /|     |
|    |        / |     |
|    |          |     |
|    |                |
|    |                |
|    |                |
|  __|__              |
+---------------------+
)";
        break;
    case 2:
        cout <<
R"(+---------------------+
|    ____________     |
|    |/         |     |
|    |          |     |
|    |         (_)    |
|    |          &     |
|    |         /|\    |
|    |        / | \   |
|    |          |     |
|    |                |
|    |                |
|    |                |
|  __|__              |
+---------------------+
)";
        break;
    case 1:
        cout <<
R"(+---------------------+
|    ____________     |
|    |/         |     |
|    |          |     |
|    |         (_)    |
|    |          &     |
|    |         /|\    |
|    |        / | \   |
|    |          |     |
|    |         /      |
|    |        /       |
|    |                |
|  __|__              |
+---------------------+
)";
        break;
    case 0:
        cout <<
R"(+---------------------+
|    ____________     |
|    |/         |     |
|    |          |     |
|    |         (_)    |
|    |          &     |
|    |         /|\    |
|    |        / | \   |
|    |          |     |
|    |         / \    |
|    |        /   \   |
|    |                |
|  __|__              |
+---------------------+
)";
        break;
    }
}
