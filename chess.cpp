#include <SDL2/SDL.h>
#include <iostream>
#include "piece.hpp"
#include "board.hpp"


int main(int argc, char *args[])
{
    Board board;
    board.print_board();
    std::cout<<std::endl;
    std::cout<<"-------------------"<<std::endl;
    board.print_board_pieces();
    return 0;
}
