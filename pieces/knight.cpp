//
//  knight.cpp
//  Chess
//
//  Created by Yuval Atir
//

#include "piece.hpp"

bool Knight :: is_legal(int from_row, int from_col, int to_row, int to_col) const
{
	if ( ( to_row >= 0 && to_col >= 0 ) && ( to_row <= 7 && to_col <= 7 ) )  {
		if ( ( ( abs( from_row - to_row ) == 1 && abs( to_col - from_col ) == 2 ) ||
				( abs( from_row - to_row ) == 2 && abs( to_col - from_col ) == 1 ) ) &&
				!((from_col==to_col)&&(to_row==from_row)) )
			return true;
		else return false;
	}
	return false;
}
