#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <winsock2.h>
#include <string.h>

class Chat
{
public:
	Chat(int port);
private:
	int port_;  
	int server_fd_;
};

