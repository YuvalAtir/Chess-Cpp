//
//  piece.hpp
//  Chess
//
//  Created by Yuval Atir
//


#ifndef Piece_hpp
#define Piece_hpp

#include "../board/chessboard.hpp"

enum piece_type {nada, king, queen, rook, bishop, knight, pawn};
enum color {black, white, none};

class Chessboard;

class Piece {
public:
	Piece() : _bw(none), _ptype(nada) {};
	Piece(color bwb, piece_type pt) : _bw(bwb) , _ptype(pt) {} ;
	virtual ~Piece() {};

	virtual bool is_legal(int,int,int,int) const = 0;
	virtual bool is_legal_pawn_kill(Chessboard*,int,int,int,int) const {return true;};

	color get_color() const {return _bw;};
	piece_type get_type() const {return _ptype;};

private:
	color _bw;
	piece_type _ptype;

};


class King : public Piece
{
public:
	King(color _bw, piece_type _ptype=king) : Piece(_bw,_ptype) {};
	bool is_legal(int,int,int,int) const;
};

class Pawn : public Piece
{
public:
	Pawn(color _bw, piece_type _ptype=pawn) : Piece(_bw,_ptype) {};
	bool is_legal(int,int,int,int) const;
	bool is_legal_pawn_kill(Chessboard*,int,int,int,int) const;
};

class Rook : public Piece
{
public:
	Rook(color _bw, piece_type _ptype=rook) : Piece(_bw,_ptype) {};
	bool is_legal(int,int,int,int) const;
};


class Bishop : public Piece
{
public:
	Bishop(color _bw, piece_type _ptype=bishop) : Piece(_bw,_ptype) {};
	bool is_legal(int,int,int,int) const;
};


class Queen : public Piece
{
public:
	Queen(color _bw, piece_type _ptype=queen) : Piece(_bw,_ptype) {};
	bool is_legal(int,int,int,int) const;
};

class Knight : public Piece
{
public:
	Knight(color _bw, piece_type _ptype=knight) : Piece(_bw,_ptype) {};
	bool is_legal(int,int,int,int) const;
};

class EmptyPiece : public Piece
{
public:
	EmptyPiece() : Piece() {};
	bool is_legal(int,int,int,int) const;
};

#endif /* piece_hpp */
