#include "SkribbleDatabase.h"
//
//bool WordStorage::Initialize()
//{
//    m_wordDB.sync_schema(); // Sincronizează schema bazei de date
//    //auto initWordsCount = m_wordDB.count<WordEntity>();
//    auto initWordsCount = m_wordDB.count<Words>();
//    if (initWordsCount == 0)
//        PopulateStorage();
//
//    //auto wordsCount = m_wordDB.count<WordEntity>();
//    auto wordsCount = m_wordDB.count<Words>();
//    return wordsCount != 0;
//}
//void WordStorage::PopulateStorage()
//{
////  
//// std::vector<WordEntity> words{
////        { -1, "Word1" },
////        { -1, "Word2" },
////        { -1, "Word3" },
////        // Adăugați mai multe cuvinte aici
////    };
////    m_db.insert_range(words.begin(), words.end());
//
//    std::ifstream file("cuvinte_skribble.txt"); 
//    //std::vector<WordEntity> words;
//    std::vector<Words> words;
//
//    if (file.is_open()) {
//        std::string word;
//        while (std::getline(file, word)) {
//            if (!word.empty()) {
//                //words.push_back(WordEntity{ -1, word });
//                words.push_back(Words{ -1, word });
//            }
//        }
//        file.close();
//    }
//    else {
//        std::cerr << "Nu s-a putut deschide fisierul." << std::endl;
//        return;
//    }
//
//    m_wordDB.insert_range(words.begin(), words.end());
//}
//std::vector<std::string> WordStorage::GetWords()
//{
//    //std::vector<WordEntity> wordEntities = m_wordDB.get_all<WordEntity>();
//    std::vector<Words> wordEntities = m_wordDB.get_all<Words>();
//    std::vector<std::string> words;
//    for (const auto& entity : wordEntities) {
//        //words.push_back(entity.word);
//        words.push_back(entity.GetWord());
//    }
//    return words;
//}
//
//void WordStorage::AddWord(const std::string& word)
//{
//    //WordEntity newWord{ -1, word };
//    Words newWord{ -1, word };
//    m_wordDB.insert(newWord);
//}
//
//
//
//void UserStorage::AddUser(const std::string& username, const std::string& password)
//{
//    UserEntity newUser{ -1, username, password };
//    m_userDB.insert(newUser);
//}
//
//bool UserStorage::VerifyUser(const std::string& username, const std::string& password)
//{
//    auto users = m_userDB.get_all<UserEntity>(sql::where(sql::c(&UserEntity::m_username) == username));
//    if (!users.empty())
//    {
//        const auto& user = users.front();
//        return password == user.m_password;
//    }
//    return false;
//}
//
//bool UserStorage::VeryfyUsernameExistance(const std::string& username)
//{
//    auto users = m_userDB.get_all<UserEntity>(sql::where(sql::c(&UserEntity::m_username) == username));
//    if (!users.empty())
//    {
//        return true;
//    }
//    return false;
//}

bool Database::Initialize()
{

    m_db.sync_schema(); // Sincronizează schema bazei de date
    //auto initWordsCount = m_wordDB.count<WordEntity>();
    auto initWordsCount = m_db.count<Words>();
    if (initWordsCount == 0)
        PopulateStorage();

    //auto wordsCount = m_wordDB.count<WordEntity>();
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
bool Database::VerifyPassword(const std::string& password)
{
    if (auto pass = m_db.get_all<Player>(sql::where(sql::c(&Player::GetPassword) == password)); !pass.empty())
    {
        return true;
    }
    return false;
}
//bool Database::VerifyPassword(const std::string& username, const std::string& password)
//{
//    auto users = m_db.get_all<Player>(sql::where(sql::c(&Player::GetName) == username));
//    if (!users.empty())
//    {
//        return true;
//    }
//    return false;
//}

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
