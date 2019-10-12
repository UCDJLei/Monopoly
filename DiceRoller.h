//
// Created by LEI on 2/8/2018.
//
#include <iostream>
#include <vector>

#ifndef MONOPOLYC_V2_DICEROLLER_H
#define MONOPOLYC_V2_DICEROLLER_H
class DiceRoller{
 public:
  DiceRoller();
  DiceRoller(const std::string& rule_file_name);
  std::vector<int>& get_random_num_vec();
  unsigned int get_num_from_vec();
  void add_num_to_vec(int num);

 private:
  std::vector<int> random_num_vec;
  int num_of_random_num;
  int read_position;
};
#endif //MONOPOLYC_V2_DICEROLLER_H
