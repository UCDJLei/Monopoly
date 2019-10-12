//
// Created by LEI on 2/10/2018.
//
#include "Move.h"
#include <vector>
#include "DiceRoller.h"
#include "GameState.h"
Move::Move(){

  roll_dice = false;
  leave_game = false;
  dice1 = 0;
  dice2 = 0;
  dice = 0;
  curret_position = 0;
  new_position = 0;

}


void Move ::get_move(GameState gamestate){
  std :: cout << gamestate.get_current_player().get_name() << " please enther your move" << std::endl << "1 to roll dice"
              << std::endl << "2 to leave the game"<< std::endl;
  int action;
  std::cin >> action;
  if (action == 1){
    roll_dice = true;
  }
  else if (action == 2){
    leave_game = true;
  }

}

void Move:: make_move(GameState gamestate){
  // Player temp_cur_player = gamestate.get_current_player();

  if (roll_dice){
    // get dices and display to the player
    dice1 = (gamestate.get_diceRoller().get_num_from_vec())%6 +1;
    std::cout << "dice 1 is " << dice1 << std:: endl;
    dice2 = (gamestate.get_diceRoller().get_num_from_vec())%6 +1;
    std::cout << "dice 2 is " << dice2 << std:: endl;

    dice = dice1 + dice2;

    std::cout << gamestate.get_current_player().get_name()<< " you rolled a  " << dice << std:: endl;

    //move the player on the board
    // figure out the current and new space current player land on
    curret_position = gamestate.get_current_player().get_position();
    std::cout<< "Player you are at position " << curret_position << std::endl;
    new_position = (curret_position + dice) % (gamestate.get_num_space());
    std::cout<< "Player you are moving to position " << new_position << std::endl;


    current_space = &*(gamestate.get_board().get_spacevec()[curret_position]);
    new_space = &*(gamestate.get_board().get_spacevec()[new_position]);

    std::cout<< "after assigning current and new space pointers" << std:: endl;

    //break out old pointers and build up new pointers between players and the space
    for (int i = 0; i < current_space->get_players_vect_ptr().size(); i++){
      std::cout<<"hey I am insie the for loop"<<std::endl;
      //something wrong here!!!!
      if (current_space->get_players_vect_ptr()[i]->get_player_id() == gamestate.get_current_player().get_player_id())
       //current_space->get_players_vect_ptr().erase( current_space->get_players_vect_ptr().begin()+ i);
      std::cout <<"Found the matching player id " << i <<std::endl;
    }

    //build up pointers from new position to player

    gamestate.get_board().get_spacevec()[new_position]->get_players_vect_ptr().push_back(&(gamestate.get_current_player()));

    // creat pointers from player to the newposition
    gamestate.get_current_player().get_space_ptr() = *&new_space;

    std::cout << "now player is at space " << std::endl;

   // gamestate.get_current_player().get_space_ptr()->print_space_name();

    /*Space* temp_space_ptr = temp_cur_player.get_space_ptr();
    Space* temp_space_ptr1 =  move.new_space;
    temp_space_ptr =  temp_space_ptr1;*/


    //temp_cur_player.get_space_ptr() =  move.new_space;


  }

  else if (leave_game){
    //destructor of the player

  }

}


