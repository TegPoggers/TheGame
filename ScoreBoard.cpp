#include "ScoreBoard.h"

namespace scoreboards {

    ScoreBoard::ScoreBoard() : leaderboard(),
                               line(0){

        int rows = 100, cols = 100;
        leaderboard.names = new char*[rows];
        for (int i = 0; i < rows; ++i){
            leaderboard.names[i] = new char[cols];
        }

        readScores();

    }

    ScoreBoard::~ScoreBoard(){}

    void ScoreBoard::readScores(){
        std::ifstream ifs("names.txt");
        std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        //cout << content << endl;

        string::iterator it;

        //Mágica para fazer cada nome uma string (não STL) numa matriz
        int j = 0;
        int k = 0;
        for(int i = 0; i < content.length(); i++){
            if(content[i] == '\n'){
                j++;
                k = 0;
            }
            else{
                leaderboard.names[j][k] = content[i];
                k++;
            }
        }

        std::ifstream scores("scores.txt");
        std::string numbers((std::istreambuf_iterator<char>(scores)), (std::istreambuf_iterator<char>()));

        j = 0;
        k = 0;
        int value = 0;
        for(int i = 0; i < numbers.length(); i++){
            if(numbers[i] == '\n'){
                if(value){
                    leaderboard.scores.push_back(value);
                    value = 0;
                }
            }
            else{
                //Transformar chars em numeros
                value *= 10;
                value += numbers[i] - 48;
            }
        }
        leaderboard.scores.push_back(value);
    }

    int ScoreBoard::lenght(){
        return leaderboard.scores.size();
    }

    void ScoreBoard::first(){
        current.name = leaderboard.names[0];
        current.score = leaderboard.scores[0];
        line = 0;
    }

    Score ScoreBoard::getCurrent(){
        return current;
    }

    void ScoreBoard::next(){
        line++;
        current.name = leaderboard.names[line];
        current.score = leaderboard.scores[line];
    }

    bool ScoreBoard::ended(){
        if(line >= leaderboard.scores.size()){
            return true;
        }
        return false;
    }

    void ScoreBoard::sort(){
        //leaderboard.scores será arrumado e o name será alterado como consequência

        //Insertion sort
        int value, j;
        char* name;
        for(int i = 1; i < leaderboard.scores.size(); i++) {

            value = leaderboard.scores[i];
            name = leaderboard.names[i];
            j = i;
            while(j > 0 && leaderboard.scores[j-1] < value) {

                leaderboard.scores[j] = leaderboard.scores[j - 1];
                leaderboard.names[j] = leaderboard.names[j - 1];
                j--;

            }

            leaderboard.scores[j] = value;
            leaderboard.names[j] = name;

        }

    }

    void ScoreBoard::addScore(Score score){

        int size = leaderboard.scores.size();
        leaderboard.scores.push_back(score.score);
        stringToChar(leaderboard.names[size], score.name);

        sort();

    }

    void ScoreBoard::addScore(string player_name, int player_score){
        current.name = player_name;
        current.score = player_score;
        addScore(current);
    }

    void ScoreBoard::stringToChar(char* character, string str){
        int i;
        for(i = 0; i <= str.size(); i++){
            character[i] = str[i];
        }
        //character[++i] = '\0';
    }

    void ScoreBoard::charToString(string str, char* character){
        int i;
        for(i = 0; character[i] != '\0'; i++){
            str[i] = character[i];
        }
        //str[++i] = '\0';
    }

    void ScoreBoard::saveScore(){
        FILE* name_data = fopen("names.txt", "r+");
        FILE* score_data = fopen("scores.txt", "r+");

        rewind(name_data);

        for(line = 0; line < leaderboard.scores.size(); line++){
            fprintf(name_data, "%s\n", leaderboard.names[line]);
            fprintf(score_data, "%d\n", leaderboard.scores[line]);
        }





        fclose(name_data);
        fclose(score_data);

    }

}