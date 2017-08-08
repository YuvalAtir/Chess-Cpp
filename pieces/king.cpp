//
//  king.cpp
//  Chess
//
//  Created by Yuval Atir
//

#include "piece.hpp"

bool King :: is_legal(int from_row, int from_col, int to_row, int to_col) const
{
	if ( ( to_row >= 0 && to_col >= 0 ) && ( to_row <= 7 && to_col <= 7 ) )  {  		// within bounds
		if ( ( ( abs( from_row-to_row ) == 1 && abs( to_col - from_col ) == 1) ||		// one step diagonal
				( abs( from_row - to_row ) == 1 && ( to_col == from_col ) ) ||				// one step vertical
				( ( from_row == to_row ) && abs( to_col - from_col ) == 1 ) ) &&			// one step horizontal
				!( ( from_col == to_col ) && ( to_row == from_row ) ) )						// not the same location
			return true;
		else return false;
	}
	return false;
}
