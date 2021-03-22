#include <iostream>
#include <string>
using namespace std;
#include "Direction.hpp"
#include "Board.hpp"

namespace ariel{
   
     void ariel::Board::post(const unsigned int row,const unsigned int col, Direction d, const string &msg){
        cout<<"hello";
    }
    string ariel::Board::read(const unsigned int row, const unsigned int col, Direction d,unsigned int length){
        return " ";
    }
    void ariel::Board::show (){
         cout<<"hello world";
    }

}