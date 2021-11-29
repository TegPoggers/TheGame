#include "ScoreBoard.h"

namespace scoreboards {

    ScoreBoard::ScoreBoard() : leaderboard(),
                               line(0){

        int rows = 100, cols = 100;
        leaderboard.names = new char*[rows];
        for (int i = 0; i < rows; ++i){
            leaderboard.names[i] = new char[cols];
        }

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                leaderboard.names[i][j] = 0;

        readScores();

    }

    ScoreBoard::~ScoreBoard(){}

    void ScoreBoard::readScores(){
        std::ifstream names("../SaveData/names.txt");
        std::string content((std::istreambuf_iterator<char>(names)), (std::istreambuf_iterator<char>()));

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

        std::ifstream scores("../SaveData/scores.txt");
        std::string numbers((std::istreambuf_iterator<char>(scores)), (std::istreambuf_iterator<char>()));

        leaderboard.scores.clear();

        j = 0;
        int value = 0;
        for(int i = 0; i < numbers.length(); i++){
            if(numbers[i] == '\n'){
                if(value){
                    leaderboard.scores.push_back(value);
                    value = 0;
                    j++;
                }
            }
            else{
                value *= 10;
                value += numbers[i] - 48;
            }
        }
        leaderboard.scores.push_back(value);
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
        if(line < leaderboard.scores.size()) {
            current.name = leaderboard.names[line];
            current.score = leaderboard.scores[line];

        }
    }

    bool ScoreBoard::ended(){
        if(line >= leaderboard.scores.size()){
            line = 0;
            return true;
        }
        return false;
    }

    void ScoreBoard::sort(){

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
        character[i] = '\0';
        /*while(i < 100){
            character[i] = 0;
            i++;
        }*/
    }

    void ScoreBoard::saveScore(){
        FILE* name_data = fopen("../SaveData/names.txt", "r+");
        FILE* score_data = fopen("../SaveData/scores.txt", "r+");

        rewind(name_data);
        rewind(score_data);

        for(line = 0; line < leaderboard.scores.size() - 1; line++){
            fprintf(name_data, "%s\n", leaderboard.names[line]);
            fprintf(score_data, "%d\n", leaderboard.scores[line]);
        }

        fprintf(name_data, "%s", leaderboard.names[line]);
        fprintf(score_data, "%d", leaderboard.scores[line]);

        fclose(name_data);
        fclose(score_data);

    }

}