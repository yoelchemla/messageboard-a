#include "Direction.hpp"
#include "Board.hpp"
#include "doctest.h"
using namespace ariel;
#include <string>
using namespace std;



TEST_CASE("check the funcutions post and read:"){
ariel::Board board;
board.post(1, 1,Direction::Horizontal, "hi");
CHECK(board.read(1, 1, Direction::Horizontal, 2) == "hi");
    // overflow from the row and col
CHECK(board.read(100, 200, Direction::Horizontal, 2) == "__");
CHECK(board.read(100, 200, Direction::Vertical, 4) == "____");

        //the same string and the same longest

board.post(100, 200, Direction::Horizontal, "Hey");
CHECK(board.read(100, 200, Direction::Horizontal, 3) == "Hey");

board.post(10, 20, Direction::Vertical, "hola");
CHECK(board.read(10, 20, Direction::Vertical, 4) == "hola");
       ///////

board.post(100, 201, Direction::Vertical, "ey everybody");
CHECK(board.read(99, 200, Direction::Horizontal, 13) == "Hey everybody");

board.post(500, 498, Direction::Vertical, "que_tal");
CHECK(board.read(501, 498, Direction::Vertical, 6) == "ue_tal");

board.post(1032, 1030, Direction::Vertical, "habla_espanol?");
CHECK(board.read(1032, 1030, Direction::Vertical, 15) == "habla_espanol?_");

board.post(3730, 3830, Direction::Horizontal, "yoel");
CHECK(board.read(3729, 3830, Direction::Vertical, 3) == "_yk");
CHECK(board.read(3729, 3831, Direction::Vertical, 3) == "_o_"); 
CHECK(board.read(3729, 3832, Direction::Vertical, 3) == "_e_"); 
CHECK(board.read(3729, 3833, Direction::Vertical, 3) == "_l_");

board.post(1024, 1029, Direction::Horizontal, "messi");
CHECK(board.read(1024, 1029, Direction::Horizontal, 4) == "mess");

board.post(400000, 400005, Direction::Horizontal, "verde");
CHECK(board.read(400000, 400005, Direction::Horizontal, 7) == "verde**");

            //overflow from the two directions
        
board.post(0, 2, Direction::Horizontal, "yo hablo espanol");
CHECK(board.read(0, 0, Direction::Horizontal, 10) == "__yo hablo");
CHECK(board.read(10, 25, Direction::Horizontal, 15) == "espanol________");

board.post(100, 101, Direction::Horizontal, "me llamo yoel");
CHECK(board.read(99, 101, Direction::Horizontal, 9) == "_me llamo");
CHECK(board.read(100, 119, Direction::Horizontal, 15) == "me llamo yoel__");

}
//the bad cases
TEST_CASE("bad cases:"){
ariel::Board board;
board.post(32, 36, Direction::Vertical, " ");
CHECK(board.read(32,36, Direction::Vertical, 9) == "test fail");

board.post(1, 10, Direction::Horizontal, " ");
CHECK(board.read(1,10, Direction::Horizontal, 5) == "error");


board.post(4000, 5000, Direction::Vertical, " ");
CHECK(board.read(4000,5000, Direction::Vertical, 9) == "failed");


}