//
//  pawn.cpp
//  Chess
//
//  Created by Yuval Atir
//

#include "piece.hpp"

bool Pawn :: is_legal(int from_row,int from_col, int to_row, int to_col ) const
{
	if ( ( to_row >= 0 && to_col >= 0) && ( to_row <= 7 && to_col <= 7) )  {
		switch(from_row) {
		case 1:
		case 6:
			if ( ( (abs( from_row - to_row ) == 2 ) || ( abs( from_row - to_row ) == 1 ) )
					&& ( to_col == from_col ) ) {
				if ( ( ( get_color() == black) && (to_row-from_row > 0) ) ||
						( ( get_color() == white ) && ( to_row-from_row < 0) ) ) {
					return true;
				}
			}
			return false;
		default:
			if ( ( abs( from_row - to_row ) == 1 ) && ( to_col == from_col ) ) {
				if ( ( ( get_color() == black ) && ( to_row - from_row > 0 ) ) ||
						( ( get_color() == white ) && ( to_row - from_row < 0) ) ) {
					return true;
				}
			}
			return false;
		}
	}
	return false;
}

bool Pawn::is_legal_pawn_kill(Chessboard* pboard, int from_row, int from_col, int to_row, int to_col) const
{
	if ( pboard->get_piece(from_row,from_col)->get_color() == black ) {
		if ( pboard->get_piece(from_row,from_col)->get_type() == pawn ) {
			if ( ( to_row-from_row == 1 ) && ( abs( to_col - from_col ) == 1 ) )
				return true;
		}
	}
	if ( pboard->get_piece(from_row,from_col)->get_color() == white ) {
		if ( pboard->get_piece(from_row,from_col)->get_type() == pawn ) {
			if ( ( from_row-to_row == 1 ) && ( abs( to_col-from_col ) == 1 ) )
				return true;
		}
	}
	return false;
}
