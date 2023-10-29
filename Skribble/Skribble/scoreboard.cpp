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

int Scoreboard::getScore(const std::string& playerName) const {
    auto it = scores.find(playerName);
    if (it != scores.end()) {
        return it->second;
    }
    else {
        std::cout << "Player not found." << std::endl;
        return 0;
    }
}

void Scoreboard::printScoreboard() const {
    std::cout << "Scoreboard:" << std::endl;
    for (const auto& [playerName, score] : scores) {
        std::cout << playerName << ": " << score << std::endl;
    }
}

