//
// Created by LEI on 2/8/2018.
//
#include "Property.h"
#include "CSVReader.h"

#include <string>
#include <iostream>

Property::Property():
      set_id(-1),intra_set_id(-1),name(NULL),cost_to_purchase(-1),cost_to_buy_house(-1),cost_to_buy_hotel(-1),
      rent(-1),one_house_rent(-1),hotel_rent(-1) {}

Property::Property(CSVReader& reader){
  set_id = reader.readNextFieldAsInt();
  intra_set_id = reader.readNextFieldAsInt();
  name = reader.readNextFieldAsString();
  cost_to_purchase = reader.readNextFieldAsInt();
  cost_to_buy_house = reader.readNextFieldAsInt();
  cost_to_buy_hotel = reader.readNextFieldAsInt();
  rent = reader.readNextFieldAsInt();
  one_house_rent = reader.readNextFieldAsInt();
  hotel_rent = reader.readNextFieldAsInt();
}


int Property::get_rent(){
  return rent;
}

int Property::get_cost_to_purchase(){
  return   cost_to_purchase;

}

void Property::set_update_Rent(int multiplier){
  rent = rent*multiplier;
}


