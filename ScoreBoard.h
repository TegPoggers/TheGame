//
// Created by viviane on 28/11/2021.
//

#ifndef JOGO_SCOREBOARD_H
#define JOGO_SCOREBOARD_H

#include "cstdlib"
#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "cstdio"
using namespace std;

namespace scoreboards {

    typedef struct Leaderboard
    {
        char** names;
        vector<int> scores;
    };

    typedef struct Score{
        string name;
        int score;
    };


    class ScoreBoard {

    private:

        Leaderboard leaderboard;
        Score current;

        FILE *names;
        FILE *scores;

        int line;

    public:

        //Já pega o txt e coloca ele no código
        ScoreBoard();

        ~ScoreBoard();

        void readScores();

        void addScore(Score score);
        void addScore(string player_name, int player_score); // usar esse add txt

        void next();

        void first();

        bool ended();

        Score getCurrent();

        int lenght();

        void sort();

        void stringToChar(char* character, string str);

        void charToString(string str, char* character);

        void saveScore();

    };

}

#endif //JOGO_SCOREBOARD_H
