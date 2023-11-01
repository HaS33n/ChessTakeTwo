#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

class ConnectionManager{

public:
    ConnectionManager(){};
    bool tryToConnect(std::string ip, unsigned short int port){if(socket.connect(ip,port)!= sf::Socket::Done) return false; else return true; }
    
private:
    sf::TcpSocket socket;

};