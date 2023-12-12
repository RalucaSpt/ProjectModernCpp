
#include "Routes.h"

void Routes::Run()
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/CreateGame").methods("POST"_method)([](const crow::request& req)
        {
            skribble::Match match; 
            if (req.body=="") {
                return crow::response(400, "Invalid JSON");
            }
            std::string name = req.body;
            
            skribble::Player player;
            player.SetName(name);
            match.AddPlayer(player);
            std::cout<<"nr players:"<<match.getNrPlayers()<<"\n";
            return crow::response(200);
        });
    CROW_ROUTE(app, "/Login").methods("POST"_method)([](const crow::request& req) 
        {
            auto json = req.body;
            std::string name = json["username"];
            std::string password = json["password"];
            if (m_userDb.VerifyUser(name, password));
            {

            }
        });
    app.port(18080).multithreaded().run();
}
