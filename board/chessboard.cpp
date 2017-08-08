//
//  chessboard.cpp
//  Chess
//
//  Created by Yuval Atir
//

#include "chessboard.hpp"

Chessboard::Chessboard()
{

	King* initKingWhitePtr;
	initKingWhitePtr = new King(white, king);
	King* initKingBlackPtr;
	initKingBlackPtr = new King(black, king);

	Queen* initQueenWhitePtr;
	initQueenWhitePtr = new Queen(white, queen);
	Queen* initQueenBlackPtr;
	initQueenBlackPtr = new Queen(black, queen);

	Rook* initRookWhitePtr1;
	initRookWhitePtr1 = new Rook(white, rook);
	Rook* initRookBlackPtr1;
	initRookBlackPtr1 = new Rook(black, rook);
	Rook* initRookWhitePtr2;
	initRookWhitePtr2 = new Rook(white, rook);
	Rook* initRookBlackPtr2;
	initRookBlackPtr2 = new Rook(black, rook);

	Bishop* initBishopWhitePtr1;
	initBishopWhitePtr1 = new Bishop(white, bishop);
	Bishop* initBishopBlackPtr1;
	initBishopBlackPtr1 = new Bishop(black, bishop);
	Bishop* initBishopWhitePtr2;
	initBishopWhitePtr2 = new Bishop(white, bishop);
	Bishop* initBishopBlackPtr2;
	initBishopBlackPtr2 = new Bishop(black, bishop);

	Knight* initKnightWhitePtr1;
	initKnightWhitePtr1 = new Knight(white, knight);
	Knight* initKnightBlackPtr1;
	initKnightBlackPtr1 = new Knight(black, knight);
	Knight* initKnightWhitePtr2;
	initKnightWhitePtr2 = new Knight(white, knight);
	Knight* initKnightBlackPtr2;
	initKnightBlackPtr2 = new Knight(black, knight);

	//piece* tmpPiece;
	for (int x=0 ; x < 8 ; x++){
		for (int y=0 ; y < 8 ; y++){
			EmptyPiece* tmpEmptyPiece;
			tmpEmptyPiece = new EmptyPiece;
			game_board[x][y] = tmpEmptyPiece;
		}
	}
	for (int s = 0 ; s < 8 ; s++ ) {
		Pawn* initPawnWhitePtr;
		initPawnWhitePtr = new Pawn(white, pawn);
		Pawn* initPawnBlackPtr;
		initPawnBlackPtr = new Pawn(black, pawn);
		insert_piece(initPawnWhitePtr,6,s);
		insert_piece(initPawnBlackPtr,1,s);
	}

	insert_piece(initKingWhitePtr,7,4);
	insert_piece(initKingBlackPtr,0,4);

	insert_piece(initQueenWhitePtr,7,3);
	insert_piece(initQueenBlackPtr,0,3);

	insert_piece(initRookWhitePtr1,7,0);
	insert_piece(initRookWhitePtr2,7,7);
	insert_piece(initRookBlackPtr1,0,0);
	insert_piece(initRookBlackPtr2,0,7);

	insert_piece(initBishopWhitePtr1,7,2);
	insert_piece(initBishopWhitePtr2,7,5);
	insert_piece(initBishopBlackPtr1,0,2);
	insert_piece(initBishopBlackPtr2,0,5);

	insert_piece(initKnightWhitePtr1,7,1);
	insert_piece(initKnightWhitePtr2,7,6);
	insert_piece(initKnightBlackPtr1,0,1);
	insert_piece(initKnightBlackPtr2,0,6);


	wking_loc[0] = 7;
	wking_loc[1] = 4;
	bking_loc[0] = 0;
	bking_loc[1] = 4;

	//vector<int>::iterator itbegin = ok.begin();
	//vector<int>::iterator itend = ok.end();
	//for (auto it=itbegin; it<itend; ++it) {
	//	cout << *it << ' ';
	//if ok
	//printf("couldn't initialize board");
	//throw bad_alloc("couldn't initialize board")
	//}
}


Piece* Chessboard::get_piece(int row,int col)
{
	return game_board[row][col];
}


void Chessboard::print_board() const
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	printf("   0        1        2        3        4        5");
	printf("         6        7            \n");
	//its possible to use /r caridge return to cprintf
	for (int row = 0 ; row < 8 ; row++) {
		for (int col = 0 ; col < 8 ; col++) {
			if ( game_board[row][col]->get_color() == black )
				SetConsoleTextAttribute(hConsole, 9);
			else if ( game_board[row][col]->get_color() == white)
				SetConsoleTextAttribute(hConsole, 14);
			else
				SetConsoleTextAttribute(hConsole, 15);

			switch (game_board[row][col]->get_type()) {
			case king:
				if  (game_board[row][col]->get_color() == white)
					printf("(Wking)  ") ;
				else
					printf("(Bking)  ") ;
				break;
			case queen:
				if  (game_board[row][col]->get_color() == white)
					printf("(Wquen)  ") ;
				else
					printf("(Bquen)  ") ;
				break;
			case rook:
				if  (game_board[row][col]->get_color() == white)
					printf("(Wrook)  ") ;
				else
					printf("(Brook)  ") ;
				break;
			case bishop:
				if  (game_board[row][col]->get_color() == white)
					printf("(Wbshp)  ");
				else
					printf("(Bbshp)  ");
				break;
			case knight:
				if  (game_board[row][col]->get_color() == white)
					printf("(Wknit)  ");
				else
					printf("(Bknit)  ");
				break;
			case pawn:
				if  (game_board[row][col]->get_color() == white)
					printf("(Wpawn)  ") ;
				else
					printf("(Bpawn)  ") ;
				break;
			default:
				//SetConsoleTextAttribute(hConsole, 15);
				printf("(     )  ");
				break;
			}
		}
		SetConsoleTextAttribute(hConsole, 15);
		printf("   ");
		printf("%d    \n",row);
	}
	cout << endl;
}

bool Chessboard::insert_piece(Piece* in_piece, int row, int col)
{
	if (row < 0 || row > 7 || col < 0 || col > 7 ) {
		cout << "Out of bounds" << endl;
		return false;
	}

	if ( game_board[row][col]->get_type() != nada ) {
		cout << "illegal place: allready occupied" << endl;
		//sleep(1500);
		cin.ignore();
		return false;
	}

	game_board[row][col] = in_piece;
	return true;

}

Chessboard::~Chessboard()
{
	for ( int z = 0 ; z < 8 ; z++) {
		for ( int y = 0 ; y < 8 ; y++) {
			delete game_board[z][y];
		}
	}
}


bool Chessboard::move_piece(int from_row,int from_col,int to_row, int to_col)
{
	EmptyPiece* tmpEmptyPiece;
	tmpEmptyPiece = new EmptyPiece;
	if ( get_piece(from_row, from_col)->get_type() != nada) {

		//first check
		if ( get_piece(from_row, from_col)->is_legal(from_row, from_col, to_row, to_col) ) {
			if ( is_legal_board(from_row, from_col, to_row, to_col) ) {

				// all pieces but pawn can kill other pieces if their move to their spot is legal
				if ( ( get_piece(to_row,to_col)->get_type() != pawn ) ||
						( ( get_piece(to_row,to_col)->get_type() == pawn ) &&
								( get_piece(to_row,to_col)->get_type() != nada ) ) )
				{
					game_board[to_row][to_col] = get_piece(from_row,from_col);
					game_board[from_row][from_col] = tmpEmptyPiece;
					return true;   //piece has been moved
				}

			}
		}

		if ( get_piece(from_row, from_col)->get_type() == pawn ) {
			if ( get_piece(from_row, from_col)->is_legal_pawn_kill(this,from_row,from_col,to_row,to_col)==1 ) {
				tmpEmptyPiece = new EmptyPiece;
				game_board[to_row][to_col] = get_piece(from_row,from_col);
				game_board[from_row][from_col] = tmpEmptyPiece;
				return true;   //piece has been moved
			}
		}
	}
	cout << "Illegal Move" << endl;
	cin.ignore();
	return false;
}


bool Chessboard::is_legal_board(int from_row,int from_col,int to_row,int to_col) const

{
	int y=0, z=0;  //y,z == sign

	switch ( game_board[from_row][from_col]->get_type() )  {
	case queen:																				// fall through rook & bishop
	case rook:
		if ( to_row == from_row )
			z = (to_col - from_col ) / abs( to_col - from_col );   							//sign col,can be 0
		else
			y = ( to_row - from_row ) / abs( to_row - from_row );   						//sign row,can be 0

		for (int x=1 ; ( ( to_row == from_row ) && ( x < abs( to_col - from_col ) ) )     	// rook's condition
		|| ( ( to_col == from_col ) && ( x < abs( to_row - from_row ) ) ) ; x++ ) {    		// both axis'

			if ( game_board[from_row+y*x][from_col+z*x]->get_type() != nada ) {
				if ( game_board[from_row][from_col]->get_type() == rook )
					return false;
				else  {  																	//which means its a queen
					if ( y == 0 || z == 0 ) return false;  									//not diagonal
				}
			}
		}
		//  no break because of queen fallthrough
	case bishop:
		for ( int r=1; r < abs( to_row - from_row ) && r < abs( to_col - from_col ) ; r++) {
			y = ( to_row - from_row ) / abs( to_row - from_row );
			z = ( to_col - from_col ) / abs( to_row - from_row );
			if ( game_board[from_row+y*r][from_col+z*r]->get_type() != nada ){
				return false;
			}
		}
		return true;
		break;
	case pawn:
		if ( game_board[from_row][from_col]->get_color() == white ) {
			if ( ( from_row == 6 ) && ( game_board[5][from_col]->get_type() != nada ) )
				return false;
			else
				break;
		}
		else  {   																			//black
			if ( ( from_row == 1 ) && ( game_board[2][from_col]->get_type() != nada ) )
				return false;
			else
				break;
		}
		break;
	default:
		break;
	}
	return true;
}

bool Chessboard::promt_user(int turn,int* location) {

	const char* bw_turn ;
	turn == 1 ? bw_turn = "WHITE" : bw_turn = "BLACK";

	cout << bw_turn << " TURN: Move from Row: " ;
	location[0] = console_input_eclipse_win();
	cout << endl;
	cout << bw_turn << " TURN: Move from Column: " ;
	location[1] = console_input_eclipse_win();
	cout << endl;
	cout << bw_turn << " TURN: Move to Row: " ;
	location[2] = console_input_eclipse_win();
	cout << endl;
	cout << bw_turn << " TURN: Move to Column: " ;
	location[3] = console_input_eclipse_win();
	cout << endl;


	// TODO: q exit by interrupt
	if ( location[0] ==65 || location[1] == 65 ) {
		return false;
	}       //q-48=65

	// runtime error when running next block in windows if not
	// used with #define WIN 1 @chessboard.hpp
	if ( ( location[0] < 0 || location[0] > 7 ) ||
			( location[1] < 0 || location[1] > 7 ) ||
			( location[2] < 0 || location[2] > 7 ) ||
			( location[3] < 0 || location[3] > 7 ) )
	{
		return false;
	}

	return true;
}
