export module scoreboard;
import <unordered_map>;
import <string>;
import <utility>;
import <algorithm>;
import player;


namespace skribble {
    export class Scoreboard {
    public:
        Scoreboard();
        void addPlayer(const std::string namePlayer);
        void updateScore(const std::string& playerName, int points);
        int getScore(const std::string& playerName) const;
        void printTopPlayers(int topN) const;
        void resetAllScores();
        void removePlayer(const std::string& playerName);
        std::pair<std::string, int> getMaxScore() const;
        // std::pair<std::string, int> getMinScore() const; NU AVEM NEVOIE SI IMPLEMENTAREA ERA INCOMPLETA, semnat anto
        void printMaxScores() const;
        std::vector<std::pair<std::string, int>> getSortedScores() const;
        void printScoreboard() const;

    private:
        std::unordered_map<std::string, int> m_scores;
    };
}