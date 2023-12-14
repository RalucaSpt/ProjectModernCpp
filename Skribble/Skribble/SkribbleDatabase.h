#pragma once
#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

import word;
import player;
using namespace skribble;

inline auto CreateStorage(const std::string& filename) {
	return sql::make_storage(
		filename,
		sql::make_table(
			"Words",
			sql::make_column("id", &Words::SetId, &Words::GetId, sql::primary_key().autoincrement()),
			sql::make_column("word", &Words::SetWord, &Words::GetWord)
		),
		sql::make_table(
			"Users",
			sql::make_column("id", &Player::SetId,&Player::GetIdPlayer, sql::primary_key().autoincrement()),
			sql::make_column("username", &Player::SetName, &Player::GetName),
			sql::make_column("password_hash", &Player::SetPassword, &Player::GetPassword)
		)
	);
}

using Storage = decltype(CreateStorage(""));
const std::string kUserDbFile{ "database.sqlite" };


class Database
{
public:

	bool Initialize();

	std::vector<std::string> GetWords(const int& numWords);

	void AddUser(const std::string& username, const std::string& password);
	std::vector<Player> GetListOfPlayers();
	bool VerifyUser(const std::string& username);
	bool VerifyPassword(const std::string& username,const std::string& password);

private:
	void PopulateStorage();

private:
	Storage m_db= CreateStorage(kUserDbFile);;
};
