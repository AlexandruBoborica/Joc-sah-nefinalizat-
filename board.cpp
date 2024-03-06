#include "board.hpp"
#include "piece.hpp"
#include <iostream>

square::square()
{
    int x = y = 0;
}

square::square(int X, int Y)
{
    this->x = X;
    this->y = Y;
    if ((X + Y) % 2 == 0)
    {
        this->colour = 1;
    }
    else
    {
        this->colour = 0;
    }
    my_piece = nullptr;
    this->occupied = false;
}

square::square(int X, int Y, piece *piece)
{
    this->x = X;
    this->y = Y;
    this->my_piece = piece;
    if ((X + Y) % 2 == 0)
    {
        this->colour = 1;
    }
    else
    {
        this->colour = 0;
    }
    this->occupied = true;
}

piece *square::get_piesa()
{
    return this->my_piece;
}

void square::set_piesa(piece *p)
{
    this->my_piece = p;
}

void square::set_x(int X)
{
    this->x = X;
}

int square::get_x()
{
    return this->x;
}

void square::set_Y(int Y)
{
    this->y = Y;
}

int square::get_y()
{
    return this->y;
}

bool square::is_occupied()
{
    return this->occupied;
}

bool Board :: check_square(int x, int y)
{
    return board[x][y].is_occupied();
}


Board::Board()
{
    set_board();
}

void Board::set_board()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = square(i, j);

    for (int i = 0; i < size; i++)
    {
        board[1][i] = square(1, i, new pawn(0));
        board[6][i] = square(6, i, new pawn(1));
    }
    board[0][1] = square(0 , 1 , new knight(0));
    board[0][6] = square(0 , 6 , new knight(0));
    board[7][1] = square(7 , 1 , new knight(1));
    board[7][6] = square(7 , 6 , new knight(1));
    board[0][2] = square(0 , 2 , new bishop(0));
    board[0][5] = square(0 , 5 , new bishop(0));
    board[7][2] = square(7 , 2 , new bishop(1));
    board[7][5] = square(7 , 5 , new bishop(1));
    board[0][0] = square(0 , 0 , new rook(0));
    board[0][7] = square(0 , 7 , new rook(0));
    board[7][0] = square(7 , 0 , new rook(1));
    board[7][7] = square(7 , 7 , new rook(1));
    board[0][3] = square(0 , 3 , new queen(0));
    board[0][4] = square(0 , 4 , new king(0));
    board[7][3] = square(7 , 3 , new queen(1));
    board[7][4] = square(7 , 4 , new king(1));

}

void Board::print_board()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j].is_occupied())
            {
                if (board[i][j].get_piesa()->get_colour() == 1)
                    std::cout << "W ";
                else
                    std::cout << "B ";
            }
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
}
void Board::print_board_pieces()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j].is_occupied())
            {
                if (dynamic_cast<pawn*>(board[i][j].get_piesa()) != nullptr)
                    std::cout << "P ";
                else if (dynamic_cast<knight*>(board[i][j].get_piesa()) != nullptr)
                    std::cout << "K ";
                    else
                        if(dynamic_cast<bishop*>(board[i][j].get_piesa()) != nullptr)
                        std::cout<<"B ";
                        else
                            if(dynamic_cast<rook*>(board[i][j].get_piesa()) != nullptr)
                            std::cout<<"R ";
                                else if(dynamic_cast<king*>(board[i][j].get_piesa()) != nullptr)
                                std::cout<<"E ";
                                else if(dynamic_cast<queen*>(board[i][j].get_piesa()) != nullptr)
                                std::cout<<"Q ";

                        
            }
            else
            {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
}
