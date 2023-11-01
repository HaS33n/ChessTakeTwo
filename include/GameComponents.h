#pragma once
#include <SFML/Graphics.hpp> 
#include "ResourceManager.h"

enum class chess_color{white,black};
enum class pieceType{king,queen,knight,bishop,rook,pawn};

class Piece {

public:
    Piece(chess_color color, pieceType t, ResourceManager& rm, sf::Vector2f pos, sf::Vector2f size);
    sf::RectangleShape& getFigure(){return figure;}
    void changePos(sf::Vector2f npos){figure.setPosition(npos);}
private:  
    sf::RectangleShape figure;
    chess_color clr;
    pieceType type;
};

class Square : public sf::Drawable {

public:
    Square(chess_color color, sf::Vector2u crds, unsigned short int size);
    void addResident(chess_color color, pieceType t, ResourceManager& rm){resident = new Piece(color,t,rm,object.getPosition(),object.getSize());}
    void flipPieces();
    void toggleSelection(){if(isSelected){isSelected=false;object.setOutlineThickness(0);} else { isSelected=true; object.setOutlineThickness(-2);}}
    const sf::FloatRect getGlobalBounds(){return object.getGlobalBounds();}
    const sf::Vector2f getPosition(){return object.getPosition();}
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    friend void movePiece(Square*, Square*);

    sf::RectangleShape object;
    chess_color clr;
    Piece* resident;
    sf::Vector2u coords;
    bool isSelected;
};

void movePiece(Square* from, Square* to);

