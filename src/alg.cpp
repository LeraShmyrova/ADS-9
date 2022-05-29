// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> derevo;
  std::string wwrrd;
  std::string lllinner;
  while (!file.eof()) {
  int i = 0;
  file >> wwrrd;
  while (i < wwrrd.length()) {
  int j = 0;
  while ((wwrrd[i] >= 'i' && wwrrd[i] <= 'z' || wwrrd[i] >= 'A' && wwrrd[i] <= 'Z') && i < wwrrd.length()) {
  if (wwrrd[i] >= 'A' && wwrrd[i] <= 'Z')
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
