//
// Created by LEI on 2/8/2018.
//
#include <iostream>
#include <utility>
#include <memory>
#include "Space.h"



/*Space::Space(){
  spaceType();
  goptr = &Go();
  proptr = &Property();

}*/

Space::Space(CSVReader& reader){
  //std::string type_space = reader.readNextFieldAsString();
  spaceType = string2SpaceType(reader.readNextFieldAsString());
 // std::cout<<"after reading the space type"<< std::endl;
  //Space(spaceType,reader);
  switch (spaceType) {
    case SpaceType::goSpace : {
      Go go(reader);
      goptr = std::make_shared<Go> (go);
      //go = new Go(reader);
    //  std::cout<<"after create a go"<< std::endl;
      //goptr = &go;
      ownerId = -2;


    }
      break;
    case SpaceType::PropertySpace: {
      Property property(reader);
     // std::cout<<"after creat a property"<< std::endl;
      proptr = std::make_shared<Property> (property);
      ownerId = -1;
    }
      break;



  }

}

std::vector<Player*>& Space::get_players_vect_ptr(){
  return players_vect_ptr;
}




/*CSVReader reader(board_file_name);
std::string temp_type_space = reader.readNextFieldAsString();
if (temp_type_space == "Go"){

}*/
/*
Space::Space(SpaceType spaceType,CSVReader reader) {
  switch (spaceType) {
    case SpaceType::goSpace:Space::goptr = std::make_unique<Go>(Go(reader)); ///??????
      break;
    case SpaceType::PropertySpace:Space::proptr = std::make_unique<Property>(Property(reader)); ///??????
      break;

  }
  //
}
 */
 void Space::print_space_name(){
  if(goptr != nullptr){
    std::cout<<goptr->name;
  }
  else if (proptr != nullptr){
    std::cout<<proptr->name;

  }
}

std::string Space::get_space_name() {
  if(goptr != nullptr){
    return goptr->name;
  }
  else if (proptr != nullptr){
    return proptr->name;
  }
  return "";
}

int Space::get_ownerId(){
  return  ownerId;
}

std::shared_ptr<Go> Space::get_goptr(){
  return goptr;
}

void Space::set_ownerId( int i){
  ownerId = i;
}

std::shared_ptr<Property> Space::get_proptr(){
  return proptr;
}


/*bool Space::owned_whole_Set(){
  bool temp_bool = false;
  for (int i = 0 ; i <  )
}*/

