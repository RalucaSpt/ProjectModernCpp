#include "wordDatabase.h"

using namespace http;

bool WordStorage::Initialize()
{
    m_db.sync_schema(); // Sincronizează schema bazei de date
    auto initWordsCount = m_db.count<WordEntity>();
    if (initWordsCount == 0)
        PopulateStorage();

    auto wordsCount = m_db.count<WordEntity>();
    return wordsCount != 0;
}
