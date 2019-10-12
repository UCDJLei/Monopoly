//
// Created by LEI on 2/8/2018.
//
#include <vector>
#include "Space.h"
//#include "Property.h"
#ifndef MONOPOLYC_V2_BOARD_H
#define MONOPOLYC_V2_BOARD_H

class Board{
 public:
  //Board();
  Board(const std::string& board_file_name);
  std::vector<Space>& get_spacevec();
  int& get_num_of_spaces();

  int num_of_spaces;
 private:

  std::vector<Space> spacevec;
};
#endif //MONOPOLYC_V2_BOARD_H
