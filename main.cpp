#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string secretWord = "GOIABA";
map<char, bool> guessed;
vector<char> wrongGuessedList;

bool winTheGame() {
    for (char letter: secretWord) {
        if (!guessed[letter]) {
            return false;
        }
    }
    return true;
}

bool lostedGame() {
    return (wrongGuessedList.size() >= 5);
}

vector<string> readFile() {
    ifstream file;
    vector<string> words;
    string word;

    file.open("../words");

    if (!file.is_open()) {
        cout << "error opening words file" << endl;
        exit(EXIT_FAILURE);
    }

    while(true) {
        file >> word;
        if (file.eof()) {
            break;
        }
        words.push_back(word);
    }

    file.close();

    if (words.size() == 0) {
        exit(EXIT_FAILURE);
    }


    return words;
}

string getSortedWord() {
    int magicNumber;
    vector<string> words = readFile();

    srand(time(NULL));

    if(words.size() == 0 ) {
        exit(EXIT_FAILURE);
    }

    magicNumber = rand() % words.size();

    return words.at(magicNumber);
}

int main()
{
    char guess;

    cout << "*****************************" << endl;
    cout << "******* Hang Man Game *******" << endl;
    cout << "*****************************" << endl;
    cout << endl;

    cout << "    ------           " << endl;
    cout << "    |    |           " << endl;
    cout << "    |                " << endl;
    cout << "    |                " << endl;
    cout << "    |                " << endl;
    cout << "    |                " << endl;
    cout << " ___|___             " << endl;
    cout << endl;
    secretWord = getSortedWord();

    while (!winTheGame() && !lostedGame()) {
        for (char letter: secretWord) {
            if(guessed[letter] ) {
                cout << letter << " ";
            } else {
                cout << "_ ";
            }
        }

        cout << endl << "Your guess: ";
        cin >> guess;
        cout << endl;
        guessed[guess] = true;

        system("clear");

        if (wrongGuessedList.size() == 0) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (wrongGuessedList.size() == 1) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (wrongGuessedList.size() == 2) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (wrongGuessedList.size() == 3) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |   /|\\         " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (wrongGuessedList.size() == 4) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |   /|\\         " << endl;
            cout << "    |    |           " << endl;
            cout << "    |   / \\         " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };



        if (secretWord.find(guess) != string::npos) {
            //cout << "correct guess" << endl;
        } else {
            //cout << "wrong guess" << endl;
            wrongGuessedList.push_back(guess);
        }

        cout << " wrong guessed letters: ";
        for (int var = 0; var < wrongGuessedList.size(); ++var) {
            cout << wrongGuessedList.at(var) << " ";
        }
        cout << endl;
    }

    return 0;
}
