#pragma once

#include "board.hpp"

class piece
{
private:
    bool colour;
    bool out;

public:
    piece();
    piece(bool col);
    bool get_colour();
    bool get_state();
    void set_state(bool in_out);
    virtual bool can_move(Board &board , square start, square end);
};

class pawn : public piece
{
public:
    pawn(bool col) : piece(col) {}
    bool can_move(Board &board , square start, square end) override;
};

class knight : public piece
{
public:
    knight(bool col) : piece(col){}
    bool can_move(Board &board  , square start , square end) override;
};

class bishop : public piece
{
public:
    bishop(bool col) : piece(col){}
    bool can_move(Board &board  , square start , square end) override;

};

class rook : public piece
{
    bool castling_is_done;
public:
    rook(bool col) : piece(col){}
    bool can_move(Board &board  , square start , square end) override;
    bool castle();
};

class king : public piece
{
    bool castling_is_done = false;
public:
    king(bool col) : piece(col){}
    bool can_move(Board &board  , square start , square end) override;
    bool castle();
    void make_castle(bool castling_is_done);
    bool is_castle_valid(Board board , square start , square end);
};

class queen : public piece
{
public:
    queen(bool col) : piece(col){}
    bool can_move(Board &board  , square start , square end) override;
};

