#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class HangManTheGame
{
private:

    string m_secretWord = "GOIABA";
    map<char, bool> m_guessed;
    vector<char> m_wrongGuessedList;
    char m_guess;

    bool winTheGame();
    bool lostedGame();
    vector<string> readFile();
    string getSortedWord();

public:
    HangManTheGame();
    int run();
};

#ifndef HANGMANTHEGAME_H
#define HANGMANTHEGAME_H
#endif // HANGMANTHEGAME_H
