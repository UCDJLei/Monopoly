//
// Created by LEI on 2/8/2018.
//

#include "DiceRoller.h"
#include "CSVReader.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>


DiceRoller::DiceRoller():num_of_random_num(0),random_num_vec(0,0),read_position(0){}

DiceRoller::DiceRoller(const std::string& rule_file_name){
  std::cout<<"just open the random number file"<<std::endl;

  CSVReader reader(rule_file_name);
  num_of_random_num = 0;
  while(!reader.file.eof()) {
    num_of_random_num ++;
    random_num_vec.push_back(reader.readNextLineAsInt());

  }
  /*FILE* file;
  file = fopen(rule_file_name, "r");
  if (file == nullptr) {
    std::cout << "NOTHING IN THE FILE" << std::endl;
  }*/
 /* CSVReader reader(rule_file_name);
  num_of_random_num = -1;
  while (!(reader.file).eof()){
   int temp;
    temp = reader.readNextFieldAsInt();
    random_num_vec.push_back(temp);
    int temp;
    num_of_random_num++;
    random_num_vec.push_back(reader.readNextFieldAsInt());
  }*/
 // num_of_random_num = 0;
 /* while(!feof(file)){
    int temp;
    fscanf(file, "%d\n",&temp);
    add_num_to_vec(temp);
    num_of_random_num ++;
  }
  */

  std::cout<<"read all the random numbers"<<std::endl;
  std::cout<<"num_of_random_num"<<num_of_random_num - 1<<std::endl;
  std::cout<< "last number" << random_num_vec[3]<<std::endl;



  read_position = 0;
}

std::vector<int>& DiceRoller::get_random_num_vec(){
    return random_num_vec;
};

/*unsigned int DiceRoller::get_num_of_random_num(){
  return num_of_random_num;
}*/

 unsigned int DiceRoller :: get_num_from_vec(){
  unsigned int dice = get_random_num_vec()[read_position] %6 +1;
  read_position = (read_position + 1) % num_of_random_num;
}


void DiceRoller::add_num_to_vec(int num){
  random_num_vec.push_back(num);
}
