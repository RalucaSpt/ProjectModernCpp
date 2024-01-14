#pragma once



#include <queue>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <crow.h>
#include "SkribbleDatabase.h"

import match;

class Routes
{
public:
	Routes() = default;
	void Run();
	crow::response CreateGame(const crow::request& req);
	crow::response Register(const crow::request& req);
	crow::response Login(const crow::request& req);
	crow::response SendMessage(const crow::request& req);
	crow::response GetMessage(const crow::request& req);
	crow::response ClearChat(const crow::request& req);
	/*
	crow::response CreateGame(const crow::request& req);
	crow::response CreateGame(const crow::request& req);
	crow::response CreateGame(const crow::request& req);*/
private:
	crow::SimpleApp app;
	skribble::Match match;
	std::vector<crow::json::wvalue> m_messagesJson;
	std::vector<std::tuple<int, int, int>> image
	skribble::Database db;
};
