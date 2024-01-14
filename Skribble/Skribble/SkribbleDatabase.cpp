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

void Database::AddPlayerHistory(const int16_t& score,const uint8_t& placement, const uint32_t& userId)
{
    //PlayerHistory playerHis{ -1, score,placement,userId};
    m_db.insert(skribble::PlayerHistory{ static_cast<uint32_t>(-1), score,placement,userId });
}


std::vector<PlayerHistory> Database::GetHistoryOfPlayer(const int& idPlayer)
{
  
    return m_db.get_all<PlayerHistory>(sql::where(sql::c(&PlayerHistory::GetId) == idPlayer));
   
}

std::vector<Player> Database::GetListOfPlayers()
{
    return m_db.get_all<Player>();
}

int Database::GetPlayerId(const std::string& name)
{
    auto id= m_db.select(&Player::GetIdPlayer, sql::where(sql::c(&Player::GetName) == name));
    if (id.size() != 0)
        return id[0];
    else return std::numeric_limits<int>::max();
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

std::deque<Words> Database::GetWords(const int& numWords) 
{
    std::vector<Words> wordsEntity=m_db.get_all<Words>(sql::where(sql::like(&Words::GetWord, "%")), sql::order_by(sql::random()), sql::limit(numWords));
    std::deque<Words> wordsDeque;
    wordsDeque.insert(wordsDeque.end(),
        std::make_move_iterator(wordsEntity.begin()),
        std::make_move_iterator(wordsEntity.end()));
    return wordsDeque;
}