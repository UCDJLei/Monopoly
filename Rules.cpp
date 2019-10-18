//
// Created by LEI on 2/8/2018.
//
#include "Rules.h"
#include "CSVReader.h"
#include "Utility.h"
Rules::Rules(){
  starting_cash = 1500;
  turn_limit = 1000;
  number_of_players_left_to_end_game = 1;
  property_set_multiplier = 1;
  number_of_houses_before_hotels = 3;
  must_build_houses_evenly = false;
  put_money_mn_free_parking = false;
  auction_properties = false;
  salary_multiplier_for_landing_on_go = 1;
}

Rules:: Rules(const std::string& file_name){

  CSVReader reader(file_name);

 //reader.readUntilDelim(":");
  //reader.readUntilDelim(" ");
  reader.voidUntilDelim(":");
  reader.voidUntilDelim(" ");

  starting_cash = reader.readNextStuffAsInt();
  //std::cout<< "starting_cash is " << starting_cash << std:: endl;  //this works

  //std::string token = reader.readUntilDelim("\n");
  //std::cout << "in rules file:" << token << std::endl;

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  turn_limit = reader.readNextFieldAsInt();
  if (turn_limit == -1)
    turn_limit = 200000000;
 // std::cout<< "turn_limit is " << turn_limit << std:: endl;  //this works


  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  number_of_players_left_to_end_game= reader.readNextFieldAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  property_set_multiplier =reader.readNextFieldAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  number_of_houses_before_hotels =reader.readNextFieldAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");   //FAIL
  std::string temp = reader.readNextFieldAsString();
  must_build_houses_evenly = is_yes(temp);

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  temp = reader.readNextFieldAsString();
  put_money_mn_free_parking = is_yes(temp);

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  temp = reader.readNextFieldAsString();
  auction_properties = is_yes(temp);

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  //fscanf(reader.file,"%d",&salary_multiplier_for_landing_on_go);
  reader.file >> salary_multiplier_for_landing_on_go;
  //std::cout << "reading multiplier: " << salary_multiplier_for_landing_on_go << std::endl;
  //salary_multiplier_for_landing_on_go =
 //salary_multiplier_for_landing_on_go = reader.readNextStuffAsInt();

}

int Rules::get_salary_multiplier_for_landing_on_go(){
    return salary_multiplier_for_landing_on_go;
}

int Rules::get_starting_cash(){
  return starting_cash;

}

int Rules::get_turn_limit(){
  return turn_limit;
}

int Rules::get_number_of_players_left_to_end_game(){
  return number_of_players_left_to_end_game;
}

int Rules::get_property_set_multiplier(){
  return  property_set_multiplier;
}








