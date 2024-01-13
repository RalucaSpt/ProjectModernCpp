
#include "Routes.h"

void Routes::Run()
{
    skribble::Match match;
    std::vector<crow::json::wvalue> m_messagesJson;
   
    std::vector<std::tuple<int, int, int>> image;

    crow::SimpleApp app;

    Database db;

    if (db.Initialize() != true)
    {
        std::cerr << "Couldn't initialize database.";
    }


    CROW_ROUTE(app, "/CreateGame").methods(crow::HTTPMethod::Put)([&match](const crow::request& req)
        {
            //skribble::Match match;
            
            std::string name = req.url_params.get("username");
            std::string gameCode{ req.url_params.get("gameCode") };
            skribble::Player player;
            player.SetName(name);
            player.SetScore(0);
            match.AddPlayer(player);
            //listOfMatches.insert({ gameCode,std::make_unique<Match>(std::move(match)) });
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
    CROW_ROUTE(app, "/Login").methods(crow::HTTPMethod::Put)([&match,&db](const crow::request& req)
        {

            std::string username{ req.url_params.get("username") };
            std::string password{ req.url_params.get("password") };
            std::cout << username << "\n";
            if (db.VerifyPassword(username,password) == true)
            {
                if (match.FindPlayer(username) == true)
                    match.ErasePlayer(username);
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
    CROW_ROUTE(app, "/start").methods(crow::HTTPMethod::Put) ([&match, &db](const crow::request& req)
        {
            match.SetMatchWords(db.GetWords(Match::kNrRounds*Match::kNrPlayers));
            match.SetIsStarted(true);
            return crow::response(200);
        });
    CROW_ROUTE(app, "/isStarted").methods(crow::HTTPMethod::GET)([&match](const crow::request& req)
        {
         
            return match.GetIsStarted();
        });
    CROW_ROUTE(app, "/playerIsDrawing" ).methods(crow::HTTPMethod::GET)([&match](const crow::request& req)
        {
         
            std::string username{ req.url_params.get("username") };
            if (match.GetPlayerStatus(username) == false)
                return "guessing";
            else
                return "drawing";
            //it->second->GetPlayer(username);
            //return crow::response(200);
        });
    CROW_ROUTE(app, "/getPlayersList").methods(crow::HTTPMethod::GET)([&match](/*const crow::request& req*/)
        {
            
            std::vector<crow::json::wvalue> listPlayers;
            for (const auto& [player,score]: match.GetPlayerScore())
            {
                listPlayers.push_back(crow::json::wvalue{ {"player", player},{"score",score} });
            }
            crow::json::wvalue list = crow::json::wvalue{listPlayers };
            return list;
        });
    app.port(18080).multithreaded().run();
}
