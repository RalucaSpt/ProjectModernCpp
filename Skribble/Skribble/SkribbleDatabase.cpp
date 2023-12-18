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

std::vector<Player> Database::GetListOfPlayers()
{
    return m_db.get_all<Player>();
}

bool Database::VerifyUser(const std::string& username)
{
    //auto users = m_db.get_all<Player>(sql::where(sql::c(&Player::GetName) == username));
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

    //  
    // std::vector<WordEntity> words{
    //        { -1, "Word1" },
    //        { -1, "Word2" },
    //        { -1, "Word3" },
    //        // Adăugați mai multe cuvinte aici
    //    };
    //    m_db.insert_range(words.begin(), words.end());
    
        std::ifstream file("cuvinte_skribble.txt"); 
        //std::vector<WordEntity> words;
        std::vector<Words> words;
    
        if (file.is_open()) {
            std::string word;
            while (std::getline(file, word)) {
                if (!word.empty()) {
                    //words.push_back(WordEntity{ -1, word });
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