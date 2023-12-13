#pragma once
#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

//import <utils>;
//import <product>;
//import <shoppingBasketRow>;
//
//struct WordEntity {
//	int id;
//	std::string word;
//};

//struct UserEntity {
//	uint16_t m_id;
//	std::string m_username;
//	std::string m_password;
//};
import word;
import player;
using namespace::skribble;

//
//inline auto CreateStorage(const std::string& filename) {
//	return sql::make_storage(
//		filename,
//		sql::make_table(
//			"Words",
//			sql::make_column("id", &WordEntity::id, sql::primary_key().autoincrement()),
//			sql::make_column("word", &WordEntity::word)
//		),
//		sql::make_table(
//			"Users",
//			sql::make_column("id", &UserEntity::m_id),
//			sql::make_column("username", &UserEntity::m_username),
//			sql::make_column("password_hash", &UserEntity::m_password)
//		)
//	);
//}

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
const std::string kUserDbFile{ "words.sqlite" };


class Database
{
public:

	bool Initialize();

	/*std::vector<std::string> GetWords();
	void AddWord(const std::string& word);*/


	void AddUser(const std::string& username, const std::string& password);
	std::vector<Player> GetListOfPlayers();
	bool VerifyUser(const std::string& username);
	bool VerifyPassword(const std::string& password);
	/*bool VeryfyUsernameExistance(const std::string& username);*/
private:
	void PopulateStorage();

private:
	Storage m_db= CreateStorage(kUserDbFile);;
};
//
//class WordStorage {
//public:
//	bool Initialize();
//
//	std::vector<std::string> GetWords();
//	void AddWord(const std::string& word);
//
//private:
//	void PopulateStorage();
//
//
//private:
//	Storage m_wordDB = CreateStorage(kUserDbFile);
//};
//
//class UserStorage {
//public:
//	void AddUser(const std::string& username, const std::string& password);
//	bool VerifyUser(const std::string& username, const std::string& password);
//	bool VeryfyUsernameExistance(const std::string& username);
//private:
//	Storage m_userDB;
//};


