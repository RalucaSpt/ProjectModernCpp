export module scoreboard;

#include <unordered_map>
#include <string>

export class Scoreboard {
public:
    Scoreboard();
    void addPlayer(const std::string& playerName);
    void updateScore(const std::string& playerName, int points);
    int getScore(const std::string& playerName) const;
    void printScoreboard() const;

private:
    std::unordered_map<std::string, int> scores;
};
