//
// Created by LEI on 2/8/2018.
//
#include <iostream>
#include <vector>
#include <fstream>

#ifndef MONOPOLYC_V2_DICEROLLER_H
#define MONOPOLYC_V2_DICEROLLER_H
class DiceRoller{
 public:
  DiceRoller();
  DiceRoller(const std::string& rule_file_name);
  std::vector<int> get_random_num_vec();
  int roll_dice();
  void add_num_to_vec(int num);

 private:
  int num_of_random_num;

  std::vector<int> random_num_vec;
  int read_position;
  int dice;

};
#endif //MONOPOLYC_V2_DICEROLLER_H
