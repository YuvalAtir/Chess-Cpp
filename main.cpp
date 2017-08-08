//
//  main.cpp
//  Chess
//
//  Created by Yuval Atir
//

//int main(int argc, char* const argv[]) {


#include "./board/chessboard.hpp"

void console_clear_screen() {
#ifdef WINDOWS
#ifndef ECLIPSE
	system("cls");
#endif
#endif
#ifdef LINUX
	system("clear");
#endif
}

int console_input_eclipse_win() {
	int in;
#ifdef ECLIPSE
	in = getchar()-48;
#endif
#ifdef WIN
	cin >> in ;
#endif
	return in;
}

int main()
{

	Chessboard boardgame;
	int from_row, from_col, to_row, to_col;
	int turn=1;    										// 1 = WHITE
	int location[4];
	bool ok;
	color bw_str;

	while (1) {
		console_clear_screen();
		boardgame.print_board();
		cout << "to exit type q" << endl;
		ok = boardgame.promt_user(turn, location);
		if (ok == false) {
			exit(0);
		}
		from_row = location[0];
		from_col = location[1];
		to_row = location[2];
		to_col = location[3];
		bw_str = (turn == 1 ? white : black );
		if (boardgame.get_piece(from_row,from_col)->get_color() != bw_str)  {
			cout << "pick a " << bw_str <<" piece, hit any key\n" << endl;
			cin.ignore();
			continue;
		}
		if  ( boardgame.get_piece(from_row,from_col)->get_type() == nada ) {
			cout << "pick a piece, hit any key\n" << endl;
			cin.ignore();
			continue;
		}
		if ( boardgame.move_piece(from_row, from_col, to_row, to_col) ) {
			turn=(turn==1 ? 0 : 1 );    // change turn
			continue;
		}
		else {
			cout << "pick another piece, hit any key\n" << endl;
			cin.ignore();
			continue;
		}
	} // while
} // main
