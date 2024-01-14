
#include "Routes.h"

void Routes::Run()
{
   

    if (db.Initialize() != true)
    {
        std::cerr << "Couldn't initialize database.";
        return;
    }


    CROW_ROUTE(app, "/CreateGame").methods(crow::HTTPMethod::Put)([this](const crow::request& req)
        {
            return CreateGame(req);
        });
    CROW_ROUTE(app, "/Register").methods(crow::HTTPMethod::Put)([this](const crow::request& req)
        {
            return Register(req);
        });
    CROW_ROUTE(app, "/Login").methods(crow::HTTPMethod::Put)([this](const crow::request& req)
        {
            return Login(req);
        });
  

    CROW_ROUTE(app, "/SendMessage").methods(crow::HTTPMethod::Put)([this](const crow::request& req)
        {
            return SendMessage(req);
        });
    CROW_ROUTE(app, "/GetMessage").methods(crow::HTTPMethod::GET)([this](/*const crow::request& req*/)
        {
            return GetMessage(req);
        });
    CROW_ROUTE(app, "/ClearChat").methods(crow::HTTPMethod::GET)([this](/*const crow::request& req*/)
        {
            return ClearChat(req);
        });
    CROW_ROUTE(app, "/start").methods(crow::HTTPMethod::Put) ([this](const crow::request& req)
        {
            match.SetMatchWords(db.GetWords(Match::kNrRounds*Match::kNrPlayers*3));
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
    CROW_ROUTE(app, "/getPlayerMatchHistory").methods(crow::HTTPMethod::GET)([&match,&db](const crow::request& req)
        {
            std::string username{ req.url_params.get("username") };
            std::vector<crow::json::wvalue> matchHistory;
            int id = db.GetPlayerId(username);
            if(id== std::numeric_limits<int>::max())
                return crow::json::wvalue{ matchHistory };
            else
            {
                std::vector<PlayerHistory> playerhistory{ db.GetHistoryOfPlayer(id) };
                for(const auto& it:playerhistory)
                matchHistory.push_back({
                        {"score",it.GetScore()},
                        {"placement",it.GetPlacement()}
                    });
                return crow::json::wvalue{ matchHistory };
            }
            
        });
    app.port(18080).multithreaded().run();
}

crow::response Routes::CreateGame(const crow::request& req)
{
    skribble::Player player;
    player.SetName(req.url_params.get("username"));
    player.SetScore(0);
    match.AddPlayer(player);
    return crow::response(200);
}

crow::response Routes::Register(const crow::request& req)
{
    if (db.VerifyUser(req.url_params.get("username")) == true)
    {
        return crow::response(300);
    }
    else
    {
        db.AddUser(req.url_params.get("username"), req.url_params.get("password"));
    }
    return crow::response(200);
}

crow::response Routes::Login(const crow::request& req)
{
    std::string username{ req.url_params.get("username") };
    std::string password{ req.url_params.get("password") };
    std::cout << username << "\n";
    if (db.VerifyPassword(username, password) == true)
    {
        if (match.FindPlayer(username) == true)
            match.ErasePlayer(username);
        return crow::response(200);
    }
    return crow::response(300);
}

crow::response Routes::SendMessage(const crow::request& req)
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
}

crow::response Routes::GetMessage(const crow::request& req)
{
    crow::json::wvalue copyMessage = crow::json::wvalue{ m_messagesJson };
    return copyMessage;
}

crow::response Routes::ClearChat(const crow::request& req)
{
    m_messagesJson.clear();
    return crow::response(200);
}
