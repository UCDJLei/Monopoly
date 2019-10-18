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
  int get_ownerId();

  /*Go*& get_goptr();
  Property* get_proptr();
   */
  std::shared_ptr<Go> get_goptr();
  std::shared_ptr<Property> get_proptr();


  void set_ownerId( int i);
  std::string get_space_name();
  bool owned_whole_Set();


 private:
  SpaceType spaceType;
  std::shared_ptr<Go> goptr;
  std::shared_ptr<Property> proptr;
  //Go* goptr;
  //Property* proptr;
  int ownerId;
  std::string owner_name;

  std::vector<Player*> players_vect_ptr;
};
#endif //MONOPOLYC_V2_SPACE_H
