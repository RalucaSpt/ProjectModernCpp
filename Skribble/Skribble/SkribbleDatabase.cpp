#include "SkribbleDatabase.h"

bool WordStorage::Initialize()
{
    m_db.sync_schema(); // Sincronizează schema bazei de date
    auto initWordsCount = m_db.count<WordEntity>();
    if (initWordsCount == 0)
        PopulateStorage();

    auto wordsCount = m_db.count<WordEntity>();
    return wordsCount != 0;
}
void WordStorage::PopulateStorage()
{
    std::vector<WordEntity> words{
        { -1, "Word1" },
        { -1, "Word2" },
        { -1, "Word3" },
        // Adăugați mai multe cuvinte aici
    };
    m_db.insert_range(words.begin(), words.end());
}
std::vector<std::string> WordStorage::GetWords()
{
    std::vector<WordEntity> wordEntities = m_db.get_all<WordEntity>();
    std::vector<std::string> words;
    for (const auto& entity : wordEntities) {
        words.push_back(entity.word);
    }
    return words;
}

void WordStorage::AddWord(const std::string& word)
{
    WordEntity newWord{ -1, word };
    m_db.insert(newWord);
}