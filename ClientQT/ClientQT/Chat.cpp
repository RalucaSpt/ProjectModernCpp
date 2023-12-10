#include "Chat.h"

Chat::Chat(int port)
	: port_(port)
{
    server_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd_ == 0) {
        std::cerr << "Socket creation failed.\n";
        exit(EXIT_FAILURE);
    }
    // Define?te adresa serverului
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_);

    // Leag? socket-ul de adresa specificat?
    if (bind(server_fd_, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed.\n";
        exit(EXIT_FAILURE);
    }
}
