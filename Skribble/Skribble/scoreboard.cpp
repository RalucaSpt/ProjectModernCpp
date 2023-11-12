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

void Scoreboard::printTopPlayers(int topN) const
{
    std::vector<std::pair<std::string, int>> sortedScores(scores.begin(), scores.end());
    std::sort(sortedScores.begin(), sortedScores.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        }
    );
    std::cout << "Top " << topN << " Players:" << std::endl;
    for (int i = 0; i < topN && i < sortedScores.size(); ++i) {
        std::cout << sortedScores[i].first << ": " << sortedScores[i].second << std::endl;
    }
}

void Scoreboard::resetAllScores() {
    for (auto& [playerName, score] : scores) {
        score = 0;
    }
}

std::pair<std::string, int> Scoreboard::getMaxScore() const
{
    std::pair<std::string, int> maxScore("", INT_MIN);
    for (const auto& [playerName, score] : scores) {
        if (score > maxScore.second) {
            maxScore = { playerName, score };
        }
    }
    return maxScore; 
}

std::pair<std::string, int> Scoreboard::getMinScore() const
{
    return std::pair<std::string, int>();
}

void Scoreboard::printExtremeScores() const
{
    auto maxScore = getMaxScore();
    auto minScore = getMinScore();

    std::cout << "The player with maximum score is "
        << maxScore.first << " and they have " << maxScore.second << " points." << std::endl;

    std::cout << "The player with minimum score is "
        << minScore.first << " and they have " << minScore.second << " points." << std::endl;
}

std::vector<std::pair<std::string, int>> Scoreboard::getSortedScores() const
{
    std::vector<std::pair<std::string, int>> sortedScores(scores.begin(), scores.end());
    std::sort(sortedScores.begin(), sortedScores.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second; 
        }
    );
    return sortedScores;
}

void Scoreboard::printScoreboard() const {
    std::cout << "Scoreboard:" << std::endl;
    for (const auto& [playerName, score] : scores) {
        std::cout << playerName << ": " << score << std::endl;
    }
}

