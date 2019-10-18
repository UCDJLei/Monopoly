//
// Created by LEI on 2/8/2018.
//
#include <stdio.h>
#include <fstream>
#include <string.h>
#ifndef MONOPOLYC_V2_CSVREADER_H
#define MONOPOLYC_V2_CSVREADER_H
class CSVReader{
 public:
  CSVReader(const std::string& fileName);
  //CSVReader(std::ifstream file);

  std::string readLine();
  void skipLine();
  std::string readNextFieldAsString();
  int readNextFieldAsInt();
  void skipField();
  std::string readUntilDelim(const std::string& delims);
  std::ifstream file;
  //unsigned int readNextFieldAsLong();
  int readNextLineAsInt() ;

  //
  std::string readNextStuffAsString();
  int readNextStuffAsInt();
  void voidUntilDelim(const std::string& delims);



 private:
  std::string fileName;


};
#endif //MONOPOLYC_V2_CSVREADER_H
