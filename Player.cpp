//
// Created by LEI on 2/9/2018.
//

#include "Player.h"
Player::Player(std::string& input_name, int playerid){
    cash = 0;
  property_worth= 0;
  asset = 0;
  in_the_game = true;
  name = input_name;
  position= 0;
  space_ptr = nullptr;
  player_id = playerid;

}

int Player:: get_cash(){
    return cash;
}

std::string& Player:: get_name(){
  return name;
}

bool Player::get_in_game(){
  return in_the_game;
}

int Player ::get_position (){
  return position;
}

int Player::get_player_id(){
    return player_id;
}

Space*& Player::get_space_ptr(){
  return space_ptr;
}

void Player::set_out_the_game(){
  in_the_game = false;
}

bool Player::get_in_the_game(){
  return in_the_game;
}




