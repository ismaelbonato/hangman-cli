#include "hangmanthegame.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

HangManTheGame::HangManTheGame() {
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

    m_secretWord = getSortedWord();
}

int HangManTheGame::run() {

    while (!winTheGame() && !lostedGame()) {
        for (char letter: m_secretWord) {
            if(m_guessed[letter] ) {
                cout << letter << " ";
            } else {
                cout << "_ ";
            }
        }

        cout << endl << "Your guess: ";
        cin >> m_guess;
        cout << endl;
        m_guessed[m_guess] = true;

        system("clear");

        if (m_wrongGuessedList.size() == 0) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (m_wrongGuessedList.size() == 1) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (m_wrongGuessedList.size() == 2) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (m_wrongGuessedList.size() == 3) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |   /|\\         " << endl;
            cout << "    |                " << endl;
            cout << "    |                " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (m_wrongGuessedList.size() == 4) {
            cout << "    ------           " << endl;
            cout << "    |    |           " << endl;
            cout << "    |    O           " << endl;
            cout << "    |   /|\\         " << endl;
            cout << "    |    |           " << endl;
            cout << "    |   / \\         " << endl;
            cout << " ___|___             " << endl;
            cout << endl;
        };

        if (m_secretWord.find(m_guess) != string::npos) {
            //cout << "correct guess" << endl;
        } else {
            //cout << "wrong guess" << endl;
            m_wrongGuessedList.push_back(m_guess);
        }

        cout << " wrong guessed letters: ";
        for (int var = 0; var < m_wrongGuessedList.size(); ++var) {
            cout << m_wrongGuessedList.at(var) << " ";
        }
        cout << endl;
    }
    return 0;
}

bool HangManTheGame::winTheGame() {
    for (char letter: m_secretWord) {
        if (!m_guessed[letter]) {
            return false;
        }
    }
    return true;
}

bool HangManTheGame::lostedGame() {
    return (m_wrongGuessedList.size() >= 5);
}

vector<string> HangManTheGame::readFile() {
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

string HangManTheGame::getSortedWord() {
    int magicNumber;
    vector<string> words = readFile();

    srand(time(NULL));

    if(words.size() == 0 ) {
        exit(EXIT_FAILURE);
    }

    magicNumber = rand() % words.size();

    return words.at(magicNumber);
}
