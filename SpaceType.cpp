//
// Created by LEI on 2/8/2018.
//

#include "SpaceType.h"
#include <iostream>
#include <memory>
#include "Space.h"
/*
int handle_type(SpaceType space_type){
  switch (space_type) {
    case SpaceType::goSpace:
    Space::goptr = std::make_unique<Go>(goptr); ///??????
      break;
    case SpaceType ::PropertySpace:
      Space::proptr = std::make_unique<Go>(proptr); ///??????

      break;

  }

}
 dont need this*/

SpaceType string2SpaceType (const std::string& typestring){
  if (typestring == "Go")
    return SpaceType::goSpace;
  else
    return SpaceType::PropertySpace;
}
