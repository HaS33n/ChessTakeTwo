#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "ResourceManager.h"
#include "ConnectionManager.h"

class TXTField : public sf::Drawable {

public:
    TXTField();
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setFont(sf::Font& fnt){txt.setFont(fnt);}
    void setTXT(const std::string& text){txt.setString(text);}
    sf::FloatRect getGlobalBounds(){return field.getGlobalBounds();}
    void toggleActive(){if(active){active = false; field.setOutlineThickness(0);}  else {active = true; field.setOutlineThickness(2); txt.setString("");}}
    void pushLetter(char l) {txt.setString(txt.getString()+l);}
    void popLetter();
    const std::string getContent(){return txt.getString();}
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::RectangleShape field;
    sf::Text txt;
    bool active;
};

class MainMenu{

public:
    MainMenu(sf::RenderWindow& w, ResourceManager& rm, ConnectionManager& cm);
    void runMenu();

private:
    void handleMouse(sf::Vector2i mousepos);
    void handleKeyboard(sf::Keyboard::Key key);

    sf::RenderWindow& window;
    ResourceManager& RM;
    ConnectionManager& CM;
    sf::Event event;
    bool isMenuRunning;
    sf::View GMView;
    TXTField f1,f2;
    TXTField* slctd;
    sf::RectangleShape bttn;
    sf::Text bTxt;
};