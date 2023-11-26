#pragma once
#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

import utils;
import product;
import shoppingBasketRow;

namespace http 
{
    inline auto CreateStorage(const std::string& filename) {
        return sql::make_storage(
            filename,
            sql::make_table(
                "Words",
                sql::make_column("id", &WordEntity::id, sql::primary_key().autoincrement()),
                sql::make_column("word", &WordEntity::word)
            )
        );
    }

    using Storage = decltype(CreateStorage(""));

    class WordStorage {
    public:
        bool Initialize();

        std::vector<std::string> GetWords();
        void AddWord(const std::string& word);

    private:
        void PopulateStorage();

    private:
        const std::string kDbFile{ "words.sqlite" };

    private:
        Storage m_db = CreateStorage(kDbFile);
    };

}
