# Simple Online Chess

Welcome to the Simple Online Chess project! This project is a basic implementation of an online chess game that allows players to play against each other over the internet.

Integral part of this project is [this repository](https://github.com/HaS33n/ChessTakeTwo---Server) that provides server.

project written in C++ using [SFML](https://www.sfml-dev.org/).
## Features

- Play chess online with friends.
- Real-time updates of the game board.
- Simple and intuitive user interface.

## Getting Started (debian)

1. Clone the repository to your local machine:

```bash
git clone https://github.com/HaS33n/ChessTakeTwo
```

2. Navigate to the project directory:

```bash
cd ChessTakeTwo
```

3. Install SFML

```bash
sudo apt-get install libsfml-dev
```

4. Compile program using provided makefile:

```bash
make
```

5. Launch the game:

```bash
./bin/main
```

- Each player can make their moves by selecting the piece and the destination square.
- The game will automatically update in real-time for both players.

## License

This project is licensed under the MIT License.
