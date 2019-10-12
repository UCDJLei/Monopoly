//
// Created by LEI on 2/8/2018.
//

#include "CSVReader.h"
#include <limits>
#include <ios>
#include <sstream>
#include <iostream>
#include <fstream>

CSVReader::CSVReader(const std::string& fileName) : file(fileName), fileName(fileName){


}

std::string CSVReader::readLine() {
  return readUntilDelim("\n");
  /*std::string temp;
  std::getline(file, temp, '\n');
  return temp;*/
}

std::string CSVReader::readUntilDelim(const std::string& delims) {
  char c;
  std::string stuff;
  //while((file >> c))
  while((file.get(c))){
    //c is not one of the delimiters
    if(delims.find_first_of(c) == std::string::npos ){
      stuff.push_back(c);
    } else{
      return stuff;

    }
  }
}

void CSVReader::skipLine() {
  readLine();
  //file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string CSVReader::readNextFieldAsString() {
  return readUntilDelim(",\n");
}


int CSVReader::readNextFieldAsInt() {
  std::string field = readNextFieldAsString();
  std::stringstream ss(field);
  int num;
  if(!(ss >> num)){
    std::cout << field << " wasn't a number" <<std::endl;
  }
  return num;
}

void CSVReader::skipField() {
  readNextFieldAsString();
}

int CSVReader::readNextLineAsInt() {
  std::string field = readLine();
  std::stringstream ss(field);
  int num;
  if(!(ss >> num)){
    std::cout << field << " wasn't a number" <<std::endl;
  }
  return num;
}

/*unsigned int CSVReader::readNextFieldAsInt() {
  std::string field = readNextFieldAsString();
  std::stringstream ss(field);
  unsigned int num;
  if(!(ss >> num)){
    std::cout << field << " wasn't a number" <<std::endl;
  }
  return num;
}*/


// for reading a rule file

void CSVReader::voidUntilDelim(const std::string& delims) {
  readUntilDelim(delims);
}

int CSVReader::readNextStuffAsInt() {
  std::string field = readNextFieldAsString();
  std::stringstream ss(field);
  int num;
  if(!(ss >> num)){
    std::cout << field << " wasn't a number" <<std::endl;
  }
  return num;
}

std::string CSVReader::readNextStuffAsString() {
  return readUntilDelim("\n");
}