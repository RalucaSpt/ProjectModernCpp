module scoreboard;

import <iostream>;

Scoreboard::Scoreboard() = default;

void Scoreboard::addPlayer(const std::string& playerName) {
    scores[playerName] = 0;
}

void Scoreboard::updateScore(const std::string& playerName, int points) {
    if (scores.find(playerName) != scores.end()) {
        scores[playerName] += points;
    }
    else {
        std::cout << "Player not found." << std::endl;
    }
}


