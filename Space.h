//
// Created by LEI on 2/8/2018.
//

#ifndef MONOPOLYC_V2_SPACE_H
#define MONOPOLYC_V2_SPACE_H
#include <stdio.h>
#include <iostream>
#include <utility>
#include <memory>
#include "SpaceType.h"
#include "Go.h"
#include "Property.h"
#include "CSVReader.h"
#include <vector>
#include "Player.h"

class Space{
 public:
  //Space();
  Space(CSVReader& reader);
  std::vector<Player*>& get_players_vect_ptr();
  void print_space_name();
  Go creat_go(CSVReader reader);


    private:
  SpaceType spaceType;
  Go* goptr;
  Property* proptr;

  std::vector<Player*> players_vect_ptr;
};
#endif //MONOPOLYC_V2_SPACE_H
