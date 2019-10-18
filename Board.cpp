//
// Created by LEI on 2/8/2018.
//
#include "CSVReader.h"
#include "Board.h"



/*Board::Board():{
}*/

Board::Board(const std::string& board_file_name){

  CSVReader reader(board_file_name);
  reader.skipField();
  num_of_spaces = reader.readNextFieldAsInt();
  //std::cout<<"after reading number of space " << std::endl;
  //std::cout << " num_of_spaces is " << num_of_spaces<< std::endl;

  for(int i = 0; i < 4 ; i ++){
    reader.skipLine();
  }

  for(int i = 0; i <num_of_spaces; i++){
    Space space(reader);
    spacevec.push_back (space);
  }

}

std::vector<Space>& Board:: get_spacevec(){
  return spacevec;
}

int& Board ::get_num_of_spaces(){
    return num_of_spaces;
};
