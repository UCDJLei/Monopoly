//
// Created by LEI on 2/8/2018.
//

#ifndef MONOPOLYC_V2_RULES_H
#define MONOPOLYC_V2_RULES_H
#include <iostream>

class Rules{
 public:
    Rules();
    Rules(const std::string& file_name);
 private:

  int starting_cash;
  int turn_limit;
  int number_of_players_left_to_end_game;
  int property_set_multiplier;
  int number_of_houses_before_hotels;
  bool must_build_houses_evenly;
  bool put_money_mn_free_parking;
  bool auction_properties;
  int salary_multiplier_for_landing_on_go;
};
#endif //MONOPOLYC_V2_RULES_H
