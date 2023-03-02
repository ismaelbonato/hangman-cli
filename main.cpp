#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string secretWord = "GOIABA";

    bool wrongGuess = true;
    bool notHanging    = true;
    char guess;
    map<char, bool> guessed;

    while (wrongGuess && notHanging) {
        for (char letter: secretWord) {
            if(guessed[letter] ) {
                cout << letter << " ";
            } else {
                cout << "_ ";
            }
        }

        cin >> guess;
        guessed[guess] = true;
    }
    return 0;
}
