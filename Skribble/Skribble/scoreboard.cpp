module scoreboard;

import <iostream>;
import player;

using skribble::Player;
using skribble::Scoreboard;
Scoreboard::Scoreboard() = default;

void skribble::Scoreboard::addPlayer(const std::string& namePlayer)
{
    if (namePlayer.empty()) {
        std::cerr << "Player name cannot be empty.\n";
        return;
    }
    if (m_scores.find(namePlayer) != m_scores.end()) {
        std::cerr << "Player already exists.\n";
        return;
    }
    m_scores[namePlayer] = 0;
}


void Scoreboard::updateScore(const std::string& playerName, int points) {
    if (m_scores.find(playerName) != m_scores.end()) {
        m_scores[playerName] += points;
    }
    else {
        std::cout << "Player not found.\n";
        return;
    }
}

int Scoreboard::getScore(const std::string& playerName) const {
    auto it = m_scores.find(playerName);
    if (it != m_scores.end()) {
        return it->second;
    }
    else {
        std::cout << "Player not found.\n";
        return 0;
    }
}

void Scoreboard::printTopPlayers(int topN) const
{
    std::vector<std::pair<std::string, int>> sortedScores(m_scores.begin(), m_scores.end());
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
    for (auto& [playerName, score] : m_scores) {
        score = 0;
    }
}

void Scoreboard::removePlayer(const std::string& playerName) {
    auto it = m_scores.find(playerName);
    if (it != m_scores.end()) {
        m_scores.erase(it);
    }
    else {
        std::cout << "Player not found." << std::endl;
    }
}

std::pair<std::string, int> Scoreboard::getMaxScore() const
{
    std::pair<std::string, int> maxScore("", INT_MIN);
    for (const auto& [playerName, score] : m_scores) {
        if (score > maxScore.second) {
            maxScore = { playerName, score };
        }
    }
    return maxScore; 
}

//std::pair<std::string, int> Scoreboard::getMinScore() const
//{
//    return std::pair<std::string, int>();
//}

void Scoreboard::printMaxScores() const
{
    auto maxScore = getMaxScore();
    //auto minScore = getMinScore();

    std::cout << "The player with maximum score is "
        << maxScore.first << " and they have " << maxScore.second << " points." << std::endl;

   /* std::cout << "The player with minimum score is "
        << minScore.first << " and they have " << minScore.second << " points." << std::endl;*/
}

std::vector<std::pair<std::string, int>> Scoreboard::getSortedScores() const
{
    std::vector<std::pair<std::string, int>> sortedScores(m_scores.begin(), m_scores.end());
    std::sort(sortedScores.begin(), sortedScores.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second; 
        }
    );
    return sortedScores;
}

void Scoreboard::printScoreboard() const {
    std::cout << "Scoreboard:" << std::endl;
    for (const auto& [playerName, score] : m_scores) {
        std::cout << playerName << ": " << score << std::endl;
    }
}

