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
  reader.voidUntilDelim(": ");
  int starting_cash = reader.readNextStuffAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  int turn_limit = reader.readNextFieldAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  int number_of_players_left_to_end_game= reader.readNextFieldAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  int property_set_multiplier =reader.readNextFieldAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  int number_of_houses_before_hotels =reader.readNextFieldAsInt();

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  std::string temp = reader.readNextFieldAsString();
  bool must_build_houses_evenly = is_yes(temp);

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  temp = reader.readNextFieldAsString();
  bool put_money_mn_free_parking = is_yes(temp);

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  temp = reader.readNextFieldAsString();
  bool auction_properties = is_yes(temp);

  reader.readUntilDelim(":");
  reader.readUntilDelim(" ");
  int salary_multiplier_for_landing_on_go = reader.readNextFieldAsInt();



  /*// open file and transfer content from file_name to rule_file
  std::ifstream rules_file;
  rules_file.open(file_name);

  if(rules_file.fail()){
    printf("Failed to open rules file %s\n. Using default rules\n", file_name);
   // return Rules();//need a function to do this maybe

  }

  //rules.num_dice_rolled  = 2;
  //rules.max_dice_value = 6;

  fscanf(rules_file, " Starting Cash: %d", &starting_cash);
  fscanf(rules_file, " Turn Limit ( -1 for no turn limit ) : %d", &turn_limit);

  if (turn_limit == -1)
    turn_limit = 2000000000;

  fscanf(rules_file, " Number of Players Left To End Game: %d", &number_of_players_left_to_end_game);
  fscanf(rules_file, " Property Set Multiplier: %d", &property_set_multiplier);
  fscanf(rules_file, " Number of Houses Before Hotels: %d", &number_of_houses_before_hotels);
  std::string temp;
  fscanf(file_name, "Must Build Houses Evenly: %s\n", temp);
  must_build_houses_evenly = is_yes(temp);
  fscanf(file_name, "Put Money In Free Parking: %s\n", temp);
  put_money_mn_free_parking = is_yes(temp);
  fscanf(file_name, "Auction Properties: %s\n", temp);
  auction_properties = is_yes(temp);


  fscanf(file_name, "Salary Multiplier For Landing On Go: %d", &salary_multiplier_for_landing_on_go);

  rules_file.clear();
   */
}




