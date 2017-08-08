//
//  rook.cpp
//  Chess
//
//  Created by Yuval Atir
//

#include "piece.hpp"

bool Rook::is_legal(int from_row,int from_col, int to_row, int to_col) const
{
	if ( ( to_row >= 0 && to_col >= 0 ) && ( to_row <= 7 && to_col <= 7 ) )  {
		if ( ( ( from_row == to_row ) || ( from_col == to_col ) ) &&
				(!( ( from_row == to_row ) && ( from_col == to_col ) ) ) )
			return true;
		else return false;
	}
	return false;
}
