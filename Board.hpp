#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Direction.hpp"

namespace ariel {

class Board {

 public:
   static void post(const unsigned int row, const unsigned int col, Direction d, const string &msg);
   static string read(const unsigned int row,const unsigned int col, Direction d,unsigned int length);
   static void show();  
    };
}

