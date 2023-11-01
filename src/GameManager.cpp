#include "../include/GameManager.h"
GameManager::GameManager(sf::RenderWindow& window) : window(window), MM(window,RM,CM) {
	window.setVerticalSyncEnabled(true);
	isWhite = true;
	slctd = nullptr;

	//init the board
	chess_color previous; 

	for(int i=0;i<8;i++){
		if(i%2 == 0)
			previous = chess_color::white;

		else
			previous = chess_color::black;

		
		for(int j=0;j<8;j++){
			if(previous == chess_color::white){
				board[i][j] = new Square(chess_color::black,sf::Vector2u(i+1,j+1), 50);
				previous = chess_color::black;
			}

			else{
				board[i][j] = new Square(chess_color::white,sf::Vector2u(i+1,j+1), 50);
				previous = chess_color::white;
			}
		}
	}
	//populate the board with pieces
	//pawns
	for(int i=0;i<8;i++)
		board[i][1]->addResident(chess_color::white,pieceType::pawn,RM);

	for(int i=0;i<8;i++)
		board[i][6]->addResident(chess_color::black,pieceType::pawn,RM);	

	//knights
	board[1][0]->addResident(chess_color::white,pieceType::knight,RM);
	board[6][0]->addResident(chess_color::white,pieceType::knight,RM);
	board[1][7]->addResident(chess_color::black,pieceType::knight,RM);
	board[6][7]->addResident(chess_color::black,pieceType::knight,RM);

	//rooks
	board[0][0]->addResident(chess_color::white,pieceType::rook,RM);
	board[7][0]->addResident(chess_color::white,pieceType::rook,RM);
	board[0][7]->addResident(chess_color::black,pieceType::rook,RM);
	board[7][7]->addResident(chess_color::black,pieceType::rook,RM);

	//bishops
	board[2][0]->addResident(chess_color::white,pieceType::bishop,RM);
	board[5][0]->addResident(chess_color::white,pieceType::bishop,RM);
	board[2][7]->addResident(chess_color::black,pieceType::bishop,RM);
	board[5][7]->addResident(chess_color::black,pieceType::bishop,RM);

	//queens
	board[3][0]->addResident(chess_color::white,pieceType::queen,RM);
	board[3][7]->addResident(chess_color::black,pieceType::queen,RM);

	//kings
	board[4][0]->addResident(chess_color::white,pieceType::king,RM);
	board[4][7]->addResident(chess_color::black,pieceType::king,RM);

}

void GameManager::runGame() {
	MM.runMenu();

	//rotate the board if needed
	if(!isWhite){
		sf::View rotation = window.getDefaultView();
		rotation.setRotation(180);
		window.setView(rotation);
// /*
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
				board[i][j]->flipPieces();
		}
// */
	}

	//fire up the main loop
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
		


		updateWindow();
	}
}

void GameManager::handleMouse(sf::Vector2i mousepos) {
	//std::cout << mousepos.x << " " << mousepos.y << std::endl;
	Square* clickedSquare;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			if(board[i][j]->getGlobalBounds().contains(window.mapPixelToCoords(mousepos)))
				clickedSquare = board[i][j];

	if(slctd == nullptr){
		slctd = clickedSquare;
		slctd->toggleSelection();
	}

	else{
		if(clickedSquare == slctd){
			slctd->toggleSelection();
			slctd = nullptr;	
		}


		else{
			movePiece(slctd,clickedSquare);
			slctd->toggleSelection();
			slctd = nullptr;
		}
	}
}

void GameManager::handleKeyboard(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Escape) 
		window.close();
		
}

void GameManager::updateWindow() {
	window.clear(sf::Color::Red);

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			window.draw(*board[i][j]);
		}
	}

	window.display();
}

