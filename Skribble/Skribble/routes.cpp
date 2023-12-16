
#include "Routes.h"

void Routes::Run()
{
    //std::queue<std::tuple<std::string, std::string>> m_messages;
    std::vector<crow::json::wvalue> m_messagesJson;
    crow::SimpleApp app;
    Database db;
    db.Initialize();
    CROW_ROUTE(app, "/CreateGame").methods("POST"_method)([](const crow::request& req)
        {
            skribble::Match match;
            if (req.body == "") {
                return crow::response(400, "Invalid JSON");
            }
            std::string name = req.body;

            skribble::Player player;
            player.SetName(name);
            match.AddPlayer(player);
            std::cout << "nr players:" << match.getNrPlayers() << "\n";
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
           /* if (db.VerifyUser(username) == true)
            {   
                if(db.VerifyPassword(password)==true)
                    return crow::response(200);
            }*/
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
            m_messagesJson.clear();
           /* while (!m_messagesJson.empty()) {
                m_messagesJson.pop();
            }*/
            return copyMessage;
        });
    app.port(18080).multithreaded().run();
}
