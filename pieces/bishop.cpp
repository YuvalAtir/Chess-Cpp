//
//  bishop.cpp
//  Chess
//
//  Created by Yuval Atir
//

#include "piece.hpp"

bool Bishop :: is_legal(int from_row, int from_col, int to_row, int to_col) const
{
	if ( ( to_row >= 0 && to_col >= 0) && ( to_row <= 7 && to_col <= 7) )  {
		if ( ( abs( to_row - from_row ) == abs( to_col - from_col ) ) && ( to_row - from_row != 0 ) )
			return true;
		else return false;
	}
	return false;
}
