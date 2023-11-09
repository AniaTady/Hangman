#include <iostream>
#include <sstream>

using namespace std;

string input = "3 HANGMAN 8 A E m n h a , g CAT 6 d o g D O G PYTHON 10 C + + J A V A P H P";
istringstream sin (input);

void doSingleTest();
void beginGame(string secretWord);
void printEmptyGallows();
void printHiddenWord(string secretWord);

int main()
{
    int n;
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
    for(int i = 0; i < charsNumber; i++)
    {
        char guessedChar;
        sin >> guessedChar;
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
//TODO
void printHiddenWord(string secretWord)
{
    for(int i = 0; i < secretWord.size(); i++)
    {
        cout << "_" << " ";
    }
    cout << endl;
}
