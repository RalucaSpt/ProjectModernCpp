#pragma once
//#include <string>
//#include <vector>
#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;
import <vector>;
import <string>;
import <deque>;
import word;
import player;
import playerhistory;
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
		),
		sql::make_table(
			"PlayerHistory",
			sql::make_column("id", &PlayerHistory::SetId, &PlayerHistory::GetId, sql::primary_key().autoincrement()),
			sql::make_column("score", &PlayerHistory::SetScore, &PlayerHistory::GetScore),
			sql::make_column("placement", &PlayerHistory::SetPlacement, &PlayerHistory::GetPlacement),
			sql::make_column("playerid", &PlayerHistory::SetUserId, &PlayerHistory::GetUserId),
			sql::foreign_key(&PlayerHistory::GetUserId).references(&Player::GetIdPlayer)
		)
	);
}

using Storage = decltype(CreateStorage(""));
const std::string kUserDbFile{ "database.sqlite" };


class Database
{
public:

	bool Initialize();

	std::deque<Words> GetWords(const int& numWords);

	bool VerifyUser(const std::string& username);
	bool VerifyPassword(const std::string& username,const std::string& password);
	
	void AddUser(const std::string& username, const std::string& password);
	void AddPlayerHistory(const int16_t& m_score, const uint8_t& m_placement, const uint32_t& m_userId);

	std::vector<PlayerHistory> GetHistoryOfPlayer(const int& idPlayer);
	std::vector<Player> GetListOfPlayers();
	int GetPlayerId(const std::string& name);

private:
	void PopulateStorage();

private:
	Storage m_db= CreateStorage(kUserDbFile);;
};
