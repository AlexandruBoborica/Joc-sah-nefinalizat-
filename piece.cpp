#include "piece.hpp"
#include "board.hpp"
#include <iostream>


piece::piece()
{
    colour = 1;
    out = 0;
}

piece::piece(bool col)
{
    this->colour = col;
}

bool piece::get_colour()
{
    return this->colour;
}

bool piece::get_state()
{
    return this->out;
}

void piece::set_state(bool in_out)
{
    this->out = in_out;
}

bool piece::can_move(Board &board , square start, square end)
{
    return false;
}

bool pawn::can_move(Board &board , square start, square end)
{
    if(end.get_x()>7 || end.get_x()<0 || end.get_y()>7 || end.get_x()<0)
        throw Out_of_board();
    pawn *p = dynamic_cast<pawn *>(end.get_piesa());
    int direction;
    if (this->get_colour() == 1)
        direction = -1;
    else
        direction = 1;

    bool pawn_colour = this->get_colour();
    if (pawn_colour == 1) ///daca pionul e alb
    {
        if (start.get_x() == end.get_x())
        {
            if (start.get_x() + 1 * direction == end.get_x() && end.is_occupied() == false)
                return true;
            if (start.get_x() + 2 * direction == end.get_x() && end.is_occupied() == false && start.get_x() == 6)
                return true;
        }
        else
            if (start.get_x() + 1 * direction == end.get_x() && (start.get_y() + 1 == end.get_y() || start.get_y() - 1 == end.get_y()) && end.is_occupied() == true && p->get_colour() == 0)
                return true;
        return false;
    }
    else ///pionul e negru
    {
        if (start.get_x() == end.get_x())
        {
            if (start.get_x() + 1 * direction == end.get_x() && end.is_occupied() == false)
                return true;
            if (start.get_x() + 2 * direction == end.get_x() && end.is_occupied() == false && start.get_x() == 1)
                return true;
        }
        else
            if (start.get_x() + 1 * direction == end.get_x() && (start.get_y() + 1 == end.get_y() || start.get_y() - 1 == end.get_y()) && end.is_occupied() == true && p->get_colour() == 1)
                return true;
        return false;
    }
    return false;
}




bool knight :: can_move( Board &board , square start , square end)
{
    if(end.get_x()>7 || end.get_x()<0 || end.get_y()>7 || end.get_x()<0)
        throw Out_of_board();
   
    bool knight_colour = this->get_colour();

    int dx = abs(end.get_x() - start.get_x());
    int dy = abs(end.get_y() - start.get_y());
    if(dx * dy == 2)
    {
        if(end.is_occupied() == false || (end.is_occupied() == true && end.get_piesa()->get_colour() != knight_colour))
            return true;
    }
    return false;



}


bool bishop::can_move( Board &board, square start, square end)
{
    if (end.get_x() > 7 || end.get_x() < 0 || end.get_y() > 7 || end.get_x() < 0)
        throw Out_of_board();
    bool bishop_colour = this->get_colour();
    int dx = abs(end.get_x() - start.get_x());
    int dy = abs(end.get_y() - start.get_y());

    if (dx == dy)
    {
        int xStep = (end.get_x() > start.get_x()) ? 1 : -1;
        int yStep = (end.get_y() > start.get_y()) ? 1 : -1;

        int x = start.get_x() + xStep;
        int y = start.get_y() + yStep;
        while (x != end.get_x() && y != end.get_y())
        {
            if(board.check_square(x,y) == true)
            {
                break;
            }
            x += xStep;
            y += yStep;
        }
        if ((x == end.get_x() && y == end.get_y()) || (end.is_occupied() && end.get_piesa()->get_colour() != bishop_colour))
        {
            return true;
        }
    }

    return false;
}

bool rook :: castle()
{
    return castling_is_done;
}



bool rook::can_move(Board &board, square start, square end)
{
    if (end.get_x() > 7 || end.get_x() < 0 || end.get_y() > 7 || end.get_x() < 0)
        throw Out_of_board();

    if (start.get_x() != end.get_x() && start.get_y() != end.get_y())
    {
        
        return false;
    }

    int xStep = (end.get_x() > start.get_x()) ? 1 : ((end.get_x() < start.get_x()) ? -1 : 0);
    int yStep = (end.get_y() > start.get_y()) ? 1 : ((end.get_y() < start.get_y()) ? -1 : 0);

    int x = start.get_x() + xStep;
    int y = start.get_y() + yStep;

    while (x != end.get_x() || y != end.get_y())
    {
        if (board.check_square(x, y))
        {
           
            return false;
        }

        x += xStep;
        y += yStep;
    }

   
    if (end.is_occupied() && end.get_piesa()->get_colour() == this->get_colour())
    {
        return false;
    }

    return true;
}



bool king :: castle()
{
    return castling_is_done;
}

void king :: make_castle(bool c)
{
    this->castling_is_done = c;
}

bool king :: is_castle_valid(Board board, square start, square end)
{
    if(this->castle())
        return false;
    
}

bool king :: can_move(Board &board , square start , square end)
{
    if(end.get_x()>7 || end.get_x()<0 || end.get_y()>7 || end.get_x()<0)
        throw Out_of_board();
    bool king_colour = this->get_colour();
    if(end.get_piesa()->get_colour() == king_colour)
    {
        return false;
    }

    int x = abs(start.get_x() - end.get_x());
    int y = abs(start.get_y() - end.get_y());
    if(x+y == 1)
    {
        return true;
    }
    return false;
}

bool queen::can_move(Board &board, square start, square end)
{
    if (end.get_x() > 7 || end.get_x() < 0 || end.get_y() > 7 || end.get_x() < 0)
        throw Out_of_board();

    bool queen_colour = this->get_colour();

    int dx = abs(end.get_x() - start.get_x());
    int dy = abs(end.get_y() - start.get_y());
    if ((dx == 0 || dy == 0 || dx == dy))
    {
        int xStep = (end.get_x() > start.get_x()) ? 1 : ((end.get_x() < start.get_x()) ? -1 : 0);
        int yStep = (end.get_y() > start.get_y()) ? 1 : ((end.get_y() < start.get_y()) ? -1 : 0);

        int x = start.get_x() + xStep;
        int y = start.get_y() + yStep;

        while (x != end.get_x() || y != end.get_y())
        {
            if (board.check_square(x, y))
            {
                return false;
            }

            x += xStep;
            y += yStep;
        }
        if (end.is_occupied() && end.get_piesa()->get_colour() == queen_colour)
        {
            return false;
        }

        return true;
    }

    return false;
}
