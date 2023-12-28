#include "SkribbleDatabase.h"


bool Database::Initialize()
{

    m_db.sync_schema();
    auto initWordsCount = m_db.count<Words>();
    if (initWordsCount == 0)
        PopulateStorage();
    auto wordsCount = m_db.count<Words>();
    return wordsCount != 0;
}

void Database::AddUser(const std::string& username, const std::string& password)
{
    Player newUser{ -1, username, password };
    m_db.insert(newUser);
}

void Database::AddPlayerHistory(const int& score,const int& placement, const int& userId)
{
    //PlayerHistory playerHis{ -1, score,placement,userId};
    m_db.insert(skribble::PlayerHistory{ -1, score,placement,userId });
}


std::vector<PlayerHistory> Database::GetHistoryOfPlayer(const int& idPlayer)
{
    return m_db.get_all<PlayerHistory>(sql::where(sql::c(&PlayerHistory::GetId) == 1));
}

std::vector<Player> Database::GetListOfPlayers()
{
    return m_db.get_all<Player>();
}

bool Database::VerifyUser(const std::string& username)
{
    if (auto users = m_db.get_all<Player>(sql::where(sql::c(&Player::GetName) == username)); !users.empty())
    {
        return true;
    }
    return false;
}

bool Database::VerifyPassword(const std::string& username, const std::string& password)
{
    if (auto users = m_db.get_all<Player>(sql::where(sql::c(&Player::GetName) == username)); !users.empty())
    {
        if(users[0].GetPassword()==password)
        {
            return true;
        }
    }
    return false;
}

void Database::PopulateStorage()
{
    std::ifstream file("cuvinte_skribble.txt"); 
    
    std::vector<Words> words;
    
    if (file.is_open()) {
        std::string word;
        while (std::getline(file, word)) {
            if (!word.empty()) {
                words.push_back(Words{ -1, word });
            }
        }
        file.close();
    }
    else {
        std::cerr << "Nu s-a putut deschide fisierul." << std::endl;
        return;
    }
    m_db.insert_range(words.begin(), words.end());
}

std::vector<std::string> Database::GetWords(const int& numWords) 
{
    std::vector<Words> wordsEntity= m_db.get_all<Words>(sql::where(sql::like(&Words::GetWord, "%")), sql::order_by(sql::random()), sql::limit(numWords));
    std::vector<std::string> words;
    for (const auto& it : wordsEntity)
    {
        words.push_back(it.GetWord());
    }
    return words;
}