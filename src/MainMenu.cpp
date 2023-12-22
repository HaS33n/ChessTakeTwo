#include "../include/MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& w, ResourceManager& rm, ConnectionManager& cm) : window(w), RM(rm), CM(cm) {
    window.setVerticalSyncEnabled(true);
    //GMView = window.getView();
    //window.setView(window.getDefaultView());
    slctd = nullptr;
    isMenuRunning = true;

    f1.setFont(RM.loadFont("arial"));
    f1.setSize(sf::Vector2f(w.getSize().x*2/3, w.getSize().y/8));
    f1.setPosition(sf::Vector2f(w.getSize().x/6, w.getSize().y/8));
    f1.setTXT("IP");

    f2.setTXT("PORT");
    f2.setFont(RM.loadFont("arial"));
    f2.setSize(sf::Vector2f(w.getSize().x*2/3, w.getSize().y/8));
    f2.setPosition(sf::Vector2f(w.getSize().x/6, w.getSize().y * 3 / 8));    

    bttn.setFillColor(sf::Color::Red);
    bttn.setSize(sf::Vector2f(w.getSize().x/2, w.getSize().y/8));
    bttn.setPosition(sf::Vector2f(w.getSize().x/4, w.getSize().y*0.75f));

    bTxt.setFont(RM.loadFont("arial"));
    bTxt.setFillColor(sf::Color::White);
    bTxt.setCharacterSize(bttn.getSize().y * 0.6f / 0.75f);
    bTxt.setPosition(bttn.getPosition());
    bTxt.setString("CONNECT");
}

void MainMenu::runMenu()
{
    while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
					handleMouse(sf::Mouse::getPosition(window));
				break;
			case sf::Event::KeyPressed:
				handleKeyboard(event.key.code);
				break;
			default:
				break;
			}

		}
		//---------------------------------------------------------------------------------------------
		if(!isMenuRunning)
            return;

		window.clear(sf::Color::White);
        window.draw(f1);
        window.draw(f2);
        window.draw(bttn);
        window.draw(bTxt);
        window.display();
	}
}

void MainMenu::handleMouse(sf::Vector2i mousepos)
{
    sf::Vector2f mpos = window.mapPixelToCoords(mousepos);
    
    if(f1.getGlobalBounds().contains(mpos)){
        if(slctd!=&f1){
            if(slctd != nullptr)
                slctd->toggleActive();
            
            slctd = &f1;
            slctd->toggleActive();
        }
    }

    else if(f2.getGlobalBounds().contains(mpos)){
        if(slctd!=&f2){
            if(slctd != nullptr)
                slctd->toggleActive();
            
            slctd = &f2;
            slctd->toggleActive();
        }
    }

    else if(bttn.getGlobalBounds().contains(mpos)){
        //if(CM.tryToConnect(f1.getContent(),stoi(f2.getContent())));
            isMenuRunning = false;
    }

}

void MainMenu::handleKeyboard(sf::Keyboard::Key key)
{   
    switch (key)
    {
    case sf::Keyboard::Escape:
        window.close();
        break;
    
    case sf::Keyboard::Backspace:
        if(slctd != nullptr)
            slctd->popLetter();
        break;

    case sf::Keyboard::Tab:
        if(slctd != nullptr){
            if(slctd == &f1){
                f1.toggleActive();
                slctd = &f2;
                f2.toggleActive();
            }

            else{
                f2.toggleActive();
                slctd = &f1;
                f1.toggleActive();
            }
                
        }
        else{
            slctd = &f1;
            f1.toggleActive();
        }
            
        break;
    
    case sf::Keyboard::Num0:
         if(slctd != nullptr)
            slctd->pushLetter('0');
        break;

    case sf::Keyboard::Num1:
         if(slctd != nullptr)
            slctd->pushLetter('1');
        break;

    case sf::Keyboard::Num2:
         if(slctd != nullptr)
            slctd->pushLetter('2');
        break;

    case sf::Keyboard::Num3:
         if(slctd != nullptr)
            slctd->pushLetter('3');
        break;

    case sf::Keyboard::Num4:
         if(slctd != nullptr)
            slctd->pushLetter('4');
        break;

    case sf::Keyboard::Num5:
         if(slctd != nullptr)
            slctd->pushLetter('5');
        break;

    case sf::Keyboard::Num6:
         if(slctd != nullptr)
            slctd->pushLetter('6');
        break;

    case sf::Keyboard::Num7:
         if(slctd != nullptr)
            slctd->pushLetter('7');
        break;

    case sf::Keyboard::Num8:
         if(slctd != nullptr)
            slctd->pushLetter('8');
        break;

    case sf::Keyboard::Num9:
         if(slctd != nullptr)
            slctd->pushLetter('9');
        break;

    case sf::Keyboard::Period:
         if(slctd == &f1)
            slctd->pushLetter('.');
        break;

    default:
        break;
    }
}

TXTField::TXTField()
{
    active = false;
    field.setFillColor(sf::Color::Black);
    field.setOutlineColor(sf::Color::Red);

    txt.setFillColor(sf::Color::White);
}

void TXTField::setSize(sf::Vector2f size)
{
    field.setSize(size);
    txt.setCharacterSize(size.y * 0.6f / 0.75f);
}

void TXTField::setPosition(sf::Vector2f position)
{
    field.setPosition(position);
    txt.setPosition(sf::Vector2f(position.x+3,position.y));
}

void TXTField::popLetter()
{   
    if(txt.getString().getSize()>= 1){
        std::string nstr = txt.getString();
        nstr.erase(nstr.end()-1);
        txt.setString(nstr);
    }

}

void TXTField::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(field,states);
    target.draw(txt,states);
}

