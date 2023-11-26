#pragma once
#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

//import <utils>;
//import <product>;
//import <shoppingBasketRow>;

struct WordEntity {
	int id;
	std::string word;
};

struct UserEntity {
	uint16_t id;
	std::string username;
	std::string password_hash;
};

inline auto CreateStorage(const std::string& filename) {
	return sql::make_storage(
		filename,
		sql::make_table(
			"Words",
			sql::make_column("id", &WordEntity::id, sql::primary_key().autoincrement()),
			sql::make_column("word", &WordEntity::word)
		),
		sql::make_table(
			"Users",
			sql::make_column("id", &UserEntity::id),
			sql::make_column("username", &UserEntity::username),
			sql::make_column("password_hash", &UserEntity::password_hash)
		)
	);
}

using Storage = decltype(CreateStorage(""));
const std::string kDbFile{ "words.sqlite" };

class WordStorage {
public:
	bool Initialize();

	std::vector<std::string> GetWords();
	void AddWord(const std::string& word);

private:
	void PopulateStorage();


private:
	Storage m_db = CreateStorage(kDbFile);
};

class UserStorage {
public:
	void AddUser(const std::string& username, const std::string& password);
	bool VerifyUser(const std::string& username, const std::string& password);

private:
	Storage m_db = CreateStorage(kDbFile);
};


