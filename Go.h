//
// Created by LEI on 2/8/2018.
//


#ifndef MONOPOLYC_V2_GO_H
#define MONOPOLYC_V2_GO_H
#include <stdio.h>
#include <string>
#include <iostream>
#include"CSVReader.h"
#include <vector>
#include "Player.h"

class Go{
 public:
    Go(CSVReader& reader);

  std::string name;
  int salary;
  //std::vector<Player*> players_vect_ptr;

};
#endif
//MONOPOLYC_V2_GO_H
