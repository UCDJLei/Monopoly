//
// Created by LEI on 2/8/2018.
//
#include <iostream>
#include <utility>
#include <memory>
#include "Space.h"
#include <stdio.h>
#include "SpaceType.h"
#include "CSVReader.h"
#include "Go.h"
#include "Property.h"


/*Space::Space(){
  spaceType();
  goptr = &Go();
  proptr = &Property();

}*/

Space::Space(CSVReader& reader){
  std::string type_space = reader.readNextFieldAsString();
  spaceType = string2SpaceType(type_space);
  std::cout<<"after reading the space type"<< std::endl;
  //Space(spaceType,reader);
  switch (spaceType) {
    case SpaceType::goSpace : {
      Go go(reader);
      std::cout<<"after creat a go"<< std::endl;

      goptr = &go;///something wrong here
      std::cout<<"after creat a go"<< std::endl;

      // goptr = std::make_unique<Go>(go); ///??????
      //proptr = nullptr;
    }
      break;
    case SpaceType::PropertySpace: {
      Property property(reader);
      proptr = &property;
      // proptr = std::make_unique<Property>(property); ///??????
      // goptr = nullptr;
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
    std::cout<< "This is a go space, its name is  "<<goptr->name;
  }
  else if (proptr != nullptr){
    std::cout<< "This is a property space, its name is  "<<proptr->name;

  }
}

Go Space ::creat_go(CSVReader reader){
  Go go(reader);
  return go;
}
