//
// Created by LEI on 2/10/2018.
//
#include "Move.h"



Move::Move(GameState& gamestate){

  roll_dice = false;
  leave_game = false;
  curret_position = 0;
  this->dice1 = 0;
  this->dice2 = 0;
  num_round_pass_go = 0;
  action = 'a';
  this->gameState = &gamestate;
  /*
  dice1 = 0;
  dice2 = 0;
  dice = 0;
  curret_position = 0;
  new_position = 0;
   */

}


void Move ::get_move(GameState& gamestate){
  std :: cout << gamestate.get_current_player().get_name() << " please enter your move" << std::endl << "1 to roll dice"
              << std::endl << "2 to leave the game"<< std::endl;
  std::cout <<"Your move: ";
  int action;
  std::cin >> action;
  if (action == 1){
    roll_dice = true;
  }
  else if (action == 2){
    leave_game = true;
  }

}

void Move:: make_move(GameState& gamestate){
  // Player temp_cur_player = gamestate.get_current_player();

  if (roll_dice){
    // get dices and display to the player
    dice1 = gamestate.get_diceRoller().roll_dice();
   // std::cout << "dice 1 is " << dice1 << std:: endl;
    dice2 = gamestate.get_diceRoller().roll_dice();
    //std::cout << "dice 2 is " << dice2 << std:: endl;

    dice = dice1 + dice2;
    curret_position = gamestate.get_current_player().position;
    new_position = curret_position + dice;

    std::cout << gamestate.get_current_player().get_name()<< ", you rolled a " << dice << std:: endl;

    while(new_position >= gamestate.get_board().get_num_of_spaces()){
      new_position -= gamestate.get_board().get_num_of_spaces();
      num_round_pass_go ++;
    }

    gamestate.get_current_player().cash +=
        (num_round_pass_go * (gamestate.get_board().get_spacevec()[0].get_goptr()->salary));
    //need to take care of how many times the player go though the go space to get salary

    //std::cout<< "Player you are moving to position " << new_position << std::endl;

    gamestate.get_current_player().position = new_position;

    //check the owner of the space and ask the player whether he/ she wants to buy the property
    //get current space owner
    current_owner_id = gamestate.get_board().get_spacevec()[new_position].get_ownerId();
   // std::cout<<"current_owner_id is " << current_owner_id;
    //std::cout<< " new_position is "<< new_position;

    if(new_position == 0) {
      //std::cout << "Player lands on the Go, get salary" << std::endl;
      gamestate.get_current_player().cash +=
          ( ((gamestate.get_rules().get_salary_multiplier_for_landing_on_go())-1)
                * (gamestate.get_board().get_spacevec()[0].get_goptr()->salary));
    }else {
      if(current_owner_id == gamestate.get_current_player_id()){
        std::cout << gamestate.get_current_player().get_name()
                  <<", you landed on "
                  << gamestate.get_board().get_spacevec()[new_position].get_space_name()
                  <<"which you already own"<<std::endl;
        //std::cout<<"You land on your own property, welcome back home!!"<<std::endl;
      }
      else  if(current_owner_id == -1){
        /*std:: cout<<  "gamestate.get_current_player().cash is " << gamestate.get_current_player().cash<<std::endl;
        std::cout<<"rent is " <<gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_rent()<<std::endl;
        std::cout << gamestate.get_rules().get_starting_cash();
         */


        if( gamestate.get_current_player().cash
                >= gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_cost_to_purchase()){
          std::cout << "Would you like to buy " << gamestate.get_board().get_spacevec()[new_position].get_space_name()
                    <<" for $" << gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_cost_to_purchase()
                    <<"?"<<std::endl;
          //std::cout << "This property is unowned, do you want to buy it?" << std::endl;

          std::cout << "Rent on " << gamestate.get_board().get_spacevec()[new_position].get_space_name()
                                  << " is $"
                                  << gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_rent();

          std::cout << "Enter y for yes or n for no: ";
          std::cin >> action;
          if (action == 'y') {
            std::cout << gamestate.get_current_player().get_name() << " bought "
                     << gamestate.get_board().get_spacevec()[new_position].get_space_name()
                     << " for $"
                     << gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_cost_to_purchase()
                     << std::endl;
            //std::cout << "Player wants to buy the property" << std::endl;

            gamestate.get_board().get_spacevec()[new_position].set_ownerId(gamestate.get_current_player().get_player_id());
            // the set_ownerid function does not change the value of the variable owner under the space

            gamestate.get_current_player().cash -=
                gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_cost_to_purchase();
           // std::cout<< "gamestate.get_current_player().cash is " << gamestate.get_current_player().cash<<std::endl;

          }
          else if (action == 'n'){
            //std::cout << "Player doesn't want to buy the property" << std::endl;
          }
        }
        else{
          std::cout << gamestate.get_current_player().get_name()
                    << ", you don't have enough money to afford "
                    << gamestate.get_board().get_spacevec()[new_position].get_space_name()
                    <<". "
                    << gamestate.get_board().get_spacevec()[new_position].get_space_name()
                    << " costs $"
                    <<  gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_cost_to_purchase()
                    << " but you only have $"
                    << gamestate.get_current_player().get_cash()<<std::endl;
          //std::cout<<"Player doesn't have enough money to buy the property"<<std::endl;
        }
      }
      else  if (current_owner_id != -1 && current_owner_id != gamestate.get_current_player_id()) {
        int actual_rent = gamestate.get_board().get_spacevec()[new_position].get_proptr()->get_rent();
        if(property_is_owned_by_same_player(new_position)){
          actual_rent *= gamestate.get_rules().get_property_set_multiplier();
        }
        if (gamestate.get_current_player().cash >= actual_rent){
          //std::cout << "Player lands on the property owned by other player" << std::endl;
          std::cout <<gamestate.get_current_player().get_name();
          std::cout << " paid "
                    << gamestate.get_player_name_by_id(gamestate.get_board().get_spacevec()[new_position].get_ownerId())
                    <<"$"
                    //<< "You need to pay him rent $"
                    << actual_rent
                    <<" for landing on "
                    << gamestate.get_board().get_spacevec()[new_position].get_space_name();

          gamestate.get_current_player().cash -= actual_rent;
          gamestate.set_player_cash_by_id(gamestate.get_board().get_spacevec()[new_position].get_ownerId(),actual_rent);
         // gamestate.get_player_cash_by_id(gamestate.get_board().get_spacevec()[new_position]->get_ownerId())
              //+= gamestate.get_board().get_spacevec()[new_position]->get_proptr()->get_rent();
        } else {
          // player goes to bankrupt and transfer his asset
          std::cout << gamestate.get_current_player().get_name()
                    <<" went bankrupt to "
                    << gamestate.get_player_name_by_id(gamestate.get_board().get_spacevec()[new_position].get_ownerId())
                    <<" for landing on "
                    << gamestate.get_board().get_spacevec()[new_position].get_space_name()
                    <<std::endl;

          gamestate.set_player_cash_by_id(gamestate.get_board().get_spacevec()[new_position].get_ownerId(),gamestate.get_current_player().cash);
             // += gamestate.get_current_player().cash;
          gamestate.get_current_player().cash = 0;
          gamestate.num_of_players_left --;

          for (int i = 0; i <gamestate.get_board().get_num_of_spaces(); i ++){
            if (gamestate.get_board().get_spacevec()[i].get_ownerId() == gamestate.get_current_player().get_player_id()){
              gamestate.get_board().get_spacevec()[i].set_ownerId(gamestate.get_board().get_spacevec()[new_position].get_ownerId());
            }
          }
          gamestate.get_current_player().set_out_the_game();

        }
      }
    }



  }

  else if (leave_game){
    //destructor of the player
    //std::cout<< "Player is leaving the game" << std::endl;
    gamestate.get_current_player().set_out_the_game();
    gamestate.deduct_num_of_players_left();
    gamestate.get_current_player().cash = 0;
    // to transfer all the properties owned by the player
    for (int i = 0 ; i <gamestate.get_board().get_num_of_spaces(); i ++){
      if (gamestate.get_current_player().get_player_id() ==
          gamestate.get_board().get_spacevec()[i].get_ownerId()){
        gamestate.get_board().get_spacevec()[i].set_ownerId(-1);
      }
    }
  }

}

bool Move::property_is_owned_by_same_player(int position_ID) {
  bool temp = true;
  for (int i = 1 ; i < gameState->get_board().get_num_of_spaces(); i ++){
    if (gameState->get_board().get_spacevec()[position_ID].get_proptr()->set_id
        == gameState->get_board().get_spacevec()[i].get_proptr()->set_id){
      if (gameState->get_board().get_spacevec()[position_ID].get_ownerId()
          != gameState->get_board().get_spacevec()[i].get_ownerId()){
        temp = false;
        break;
      }
    }
  }
  return temp;
}