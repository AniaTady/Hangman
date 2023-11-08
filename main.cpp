#include <iostream>
#include <sstream>

using namespace std;

string input = "3 HANGMAN 8 A E m n h a , g CAT 6 d o g D O G PYTHON 10 C + + J A V A P H P";
istringstream sin (input);

void doSingleTest();

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
    cout << secretWord;
    int charsNumber;
    sin >> charsNumber;
    for(int i = 0; i < charsNumber; i++)
    {
        char guessedChar;
        sin >> guessedChar;
    }

}
