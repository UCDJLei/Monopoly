//
// Created by LEI on 2/8/2018.
//
#include "Go.h"
#include "CSVReader.h"

Go::Go(CSVReader& reader)
{

  salary = reader.readNextFieldAsInt();
  name = reader.readNextFieldAsString();

}

