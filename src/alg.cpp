// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
BST<std::string> bsst;
  std::ifstream file(filename);
  std::string slovvo = "";
  char le = 'a' - 'A';
  if (!file.is_open()) {
  throw std::string("Smth is wrong!");
  }
  while (!file.eof()) {
  char tmprrr = file.get();
  if ((tmprrr >= 'a' && tmprrr <= 'z') || (tmprrr >= 'A' && tmprrr <= 'Z')) {
  if (tmprrr >= 'A' && tmprrr <= 'Z') {
  slovvo += tmprrr;
  tmprrr += le;
  }
  } else if (slovvo != "") {
  bsst.add(slovvo);
  slovvo = "";
  }
  }
  file.close();
  return bsst;
}
