#include "../include/GameComponents.h"

void movePiece(Square* from, Square* to){
    if(from->resident == nullptr){
        std::cout<<"nullptr \n";
        return;
    }
        

    if(to->resident != nullptr)
        delete to->resident;

    to->resident = from->resident;
    to->resident->changePos(to->getPosition());
    from->resident = nullptr;

}

Square::Square(chess_color color, sf::Vector2u crds, unsigned short int size){
    resident = nullptr;
    clr = color;
    coords = crds;
    isSelected = false;
    object.setSize(sf::Vector2f(size,size));
    object.setPosition(sf::Vector2f((crds.x-1)*size,(8-crds.y)*size));
    object.setOutlineColor(sf::Color::Red);

    if(color == chess_color::white)
        object.setFillColor(sf::Color::White);

    else
        object.setFillColor(sf::Color::Black);
}

Piece::Piece(chess_color color, pieceType t, ResourceManager& rm, sf::Vector2f pos, sf::Vector2f size){
    clr = color;
    type = t;
    std::string fullname; //idk how to call this variable lol
    if(color==chess_color::white)
        fullname = "w_";
    else
        fullname = "b_";

    switch (t)
    {
    case pieceType::pawn:
        fullname.append("pawn");
        break;

    case pieceType::bishop:
        fullname.append("bishop");
        break;

    case pieceType::knight:
        fullname.append("knight");
        break;

    case pieceType::rook:
        fullname.append("rook");
        break;

    case pieceType::queen:
        fullname.append("queen");
        break;

    case pieceType::king:
        fullname.append("king");
        break;
    
    default:
        break;
    }

    figure.setTexture(&rm.loadTexture(fullname));
    figure.setSize(size);
    figure.setPosition(pos);
}



void Square::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(object,states);
    if(resident!=nullptr)
        target.draw(resident->getFigure());
}

void Square::flipPieces(){
    if(resident == nullptr)
        return;
    
    int w = resident->getFigure().getTextureRect().width;
    int h = resident->getFigure().getTextureRect().height;

    resident->getFigure().setTextureRect(sf::IntRect(0,h,w,-h));
}