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