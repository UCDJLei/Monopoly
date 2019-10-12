//
// Created by LEI on 2/8/2018.
//

#include "GameState.h"

GameState::GameState(const std::string& rules_file_name, const std::string& board_file_name,  const std::string& random_nums_file_name) :board(board_file_name),rule(rules_file_name),diceRoller(random_nums_file_name){

 // board(board_file_name);

  current_turn = 0;
  //player_id = 0;
  //construct the vector of players





  // set up pointers on Go pointting to all players
  //something wrong here!!!



  current_player_id = 0;

  //set_num_space();

  //set_players();
}

void GameState::set_players(){
  std::cout<<"How many players will be playing?"<<std:: endl;
  std::cin >> num_of_players;
  std::string input_name;

  std::cout<<"number of space is  " << get_num_space()<<std::endl;


  for (int i = 0; i < num_of_players; i ++) {
    std::cout << "Player "<< i << " please enter your player name" << std::endl;
    std::cin >> input_name;
    Player player (input_name, i);
    //set all the pointers of space to the 0 space.
    *player.get_space_ptr() = (get_board().get_spacevec()[0]); // something wrong here!!!
    playersvec.push_back(player);
  }
std::cout<<"Finished inputing players names"<<std::endl;
  for (int i = 0; i < num_of_players; i ++){
    get_board().get_spacevec()[0].get_players_vect_ptr().push_back(&playersvec[i]);
  }

  std::cout << "finished pointing to all the players"<<std::endl;

}


Board& GameState:: get_board(){
  return board;
}

int GameState:: get_num_players(){
  return num_of_players;
}

int GameState:: get_num_players_left(){
  return num_of_players_left;
}

DiceRoller& GameState::get_diceRoller(){
  return diceRoller;
}

int GameState :: get_current_turn(){
  return current_turn;
}

/*Player GameState::get_current_player(){
  while(!playersvec[player_id].get_in_game()  ){
    player_id ++;
  }

  return playersvec[player_id];

}
 */
std::vector<Player>& GameState :: get_playersvec(){
  return playersvec;
}

int GameState::get_current_player_id(){
  return current_player_id;
}

std::string& GameState::get_current_player_name(){
    return get_current_player().get_name();
};
Player& GameState::get_current_player(){
 return get_playersvec()[get_current_player_id()];
}

void GameState ::set_num_space(){
  num_space = get_board().get_num_of_spaces();
  std::cout<<"number of space is  " << get_num_space()<<std::endl;

}

int GameState::get_num_space(){
  return num_space;
}
