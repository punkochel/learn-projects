#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP

#include <iostream>
#include <csignal>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <vector>

using namespace std;

class TCPClient {
	int sock;
	std::string address;
	int port;
	struct sockaddr_in server;
public:
	TCPClient();
	bool setup(string address, int port);
	bool Send(string data);
	string receive(int size = 4096);
	string read();
	void exit();
};

#endif // TCP_CLIENT_HPP