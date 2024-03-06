#pragma once
#include <exception>

class piece;


class Out_of_board : public std::exception
{
public:
    const char* f() const noexcept 
    {
        return "Mutarea este in afara tablei de sah";
    }

}; 

class square
{
private:
    piece *my_piece;
    bool colour;
    bool occupied;
    int x;
    int y;

public:
    square();
    square(int X, int Y);
    square(int X, int Y, piece *piece);
    piece *get_piesa();
    void set_piesa(piece *p);
    void set_x(int X);
    int get_x();
    void set_Y(int Y);
    int get_y();
    bool is_occupied();
};

class Board
{
private:
    int size = 8;
    square board[8][8];

public:
    Board();
    bool check_square(int x, int y);
    square get_square(int x, int y);
    void set_board();
    void print_board();
    void print_board_pieces();
};

