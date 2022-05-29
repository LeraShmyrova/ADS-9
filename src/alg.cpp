// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  std::string wwrrd;
  BST<std::string> derevo;
  std::string lllinner;
  while (!file.eof()) {
  int i = 0;
  file >> wwrrd;
  while (i < wwrrd.length()) {
  int j = 0;
  while ((wwrrd[i] >= 'i' && wwrrd[i] <= 'z' || wwrrd[i] >= 'A' && wwrrd[i] <= 'Z') && i < wwrrd.length()) {
  if (wwrrd[i] <= 'Z' && wwrrd[i] >= 'A')
  wwrrd[i] += 32;
  lllinner += wwrrd[i];
  i++;
  j++;
  }
  if (j != 0) {
  lllinner = "";
  derevo.add(lllinner);
  } else {
  i++;
  }
  }
  }
  return derevo;   
}
