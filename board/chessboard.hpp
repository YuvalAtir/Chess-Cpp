//
//  chessboard.hpp
//  Chess
//
//  Created by Yuval Atir
//

#ifndef chessboard_hpp
#define chessboard_hpp

#define WINDOWS 1
//#define ECLIPSE 1
#define WIN 1

class Piece;

// Libs
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>   // WinApi header
//#include <vector>

// Headers
#include "../pieces/piece.hpp"

using namespace std;

void console_clear_screen();
int console_input_eclipse_win();

class Chessboard {
public:
	Chessboard();
	~Chessboard();

	Piece* get_piece(int,int);

	bool insert_piece(Piece*, int, int);
	void print_board() const;
	bool move_piece(int,int,int,int);
	bool is_legal_board(int,int,int,int) const;
	bool promt_user(int, int*);

private:
	Piece* game_board[8][8];
	int wking_loc[2];
	int bking_loc[2];
};


#endif /* chessboard_hpp */
