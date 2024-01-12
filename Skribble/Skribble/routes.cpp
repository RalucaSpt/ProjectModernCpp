
#include "Routes.h"

void Routes::Run()
{
    //std::queue<std::tuple<std::string, std::string>> m_messages;
    std::vector<crow::json::wvalue> m_messagesJson;
    std::map<std::string, std::unique_ptr<Match>> listOfMatches;
    crow::SimpleApp app;
    Database db;
    if (db.Initialize() != true)
    {
        std::cerr << "Couldn't initialize database.";
    }


    CROW_ROUTE(app, "/CreateGame").methods("POST"_method)([&listOfMatches](const crow::request& req)
        {
            skribble::Match match;
            if (req.body == "") {
                return crow::response(400, "Invalid JSON");
            }
            std::string name = req.body;
            std::string gameCode{ req.url_params.get("gameCode") };
            skribble::Player player;
            player.SetName(name);
            match.AddPlayer(player);
            listOfMatches.insert({ gameCode,std::make_unique<Match>(match) });
            std::cout << "nr players:" << match.GetNrPlayers() << "\n";
            return crow::response(200);
        });
    CROW_ROUTE(app, "/Register").methods(crow::HTTPMethod::Put)([&db](const crow::request& req)
        {
            std::string username{ req.url_params.get("username") };
            std::string password{ req.url_params.get("password") };
            
             if (db.VerifyUser(username)==true)
             {
                 return crow::response(300);
             }
             else
             {
                 db.AddUser(username, password);
             }
             return crow::response(200);
        });
    CROW_ROUTE(app, "/Login").methods(crow::HTTPMethod::Put)([&db](const crow::request& req)
        {

            std::string username{ req.url_params.get("username") };
            std::string password{ req.url_params.get("password") };
            std::cout << username << "\n";
            if (db.VerifyPassword(username,password) == true)
            {
                return crow::response(200);
            }
            return crow::response(300);
        });
  

    CROW_ROUTE(app, "/SendMessage").methods(crow::HTTPMethod::Put)([&m_messagesJson](const crow::request& req)
        {

            std::string username{ req.url_params.get("username") };
            std::string message{ req.url_params.get("message") };
            if (username.empty() || message.empty())
            {
                return crow::response(300);
            }
            m_messagesJson.push_back(crow::json::wvalue{
               {"username", username},
               {"message", message} });
            return crow::response(200);
        });
    CROW_ROUTE(app, "/GetMessage").methods(crow::HTTPMethod::GET)([&m_messagesJson](/*const crow::request& req*/)
        {
            crow::json::wvalue copyMessage = crow::json::wvalue{ m_messagesJson };
            return copyMessage;
        });
    CROW_ROUTE(app, "/ClearChat").methods(crow::HTTPMethod::GET)([&m_messagesJson](/*const crow::request& req*/)
        {
            m_messagesJson.clear();
            return crow::response(200);
        });
    CROW_ROUTE(app, "/start").methods(crow::HTTPMethod::Put) ([&listOfMatches, &db](const crow::request& req)
        {
            std::string gameCode{ req.url_params.get("gameCode") };
            auto it{ listOfMatches.find(gameCode) };
            if (it != listOfMatches.end())
            {
                it->second->SetMatchWords(db.GetWords(Match::kNrRounds * Match::kNrPlayers));
                it->second->SetIsStarted(true);
                return crow::response(200);
            }
            return crow::response(300);
        });
    CROW_ROUTE(app, "/isStarted").methods(crow::HTTPMethod::GET)([&listOfMatches](const crow::request& req)
        {
            std::string gameCode{ req.url_params.get("gameCode") };
            auto it{ listOfMatches.find(gameCode) };
            return it->second->GetIsStarted();
        });

    app.port(18080).multithreaded().run();
}
