//
// Created by LEI on 2/8/2018.
//

#ifndef MONOPOLYC_V2_SPACETYPE_H
#define MONOPOLYC_V2_SPACETYPE_H
#include <ctype.h>
#include <string>
enum class SpaceType{
  goSpace,PropertySpace
};

int handle_type(SpaceType space_type);
SpaceType string2SpaceType (const std::string& typestring);

#endif //MONOPOLYC_V2_SPACETYPE_H
/*
Space sp;
if (sp.spaceType == SpaceType::goSpace)
*/