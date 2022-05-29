// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int ssuumma;
    Node *levv;
    Node *rht;
  };  

 private:
  Node * rroooot;
  Node * addNode(Node *rroooot, T value) {
    if (rroooot == nullptr) {
      rroooot = new Node;
      rroooot->value = value;
      rroooot->ssuumma = 1;
      rroooot->levv = rroooot->rht = nullptr;
    } else if (rroooot->value > value) {
      rroooot->levv = addNode(rroooot->levv, value);
    } else if (rroooot->value < value) {
      rroooot->rht = addNode(rroooot->rht, value);
    } else {
      rroooot->ssuumma++;
    }
    return rroooot;
  }
  int depthTree(Node *rroooot) {
    if (rroooot == nullptr)
      return 0;
    if (rroooot->levv == nullptr && rroooot->rht == nullptr)
      return 0;
    int LS = depthTree(rroooot->levv);
    int RS = depthTree(rroooot->rht);
    return LS > RS ? LS + 1 : RS + 1;
  }
  int searchNode(Node *rroooot, T value) {
    Node *t = rroooot;
    if (rroooot == nullptr) {
      return 0;
    } else {
      if (rroooot->value == value) {
        return rroooot->ssuumma;
      } else if (rroooot->value < value) {
        return searchNode(rroooot->rht, value);
      } else {
        return searchNode(rroooot->levv, value);
      }
    }
  }

 public:
  BST() : rroooot(nullptr) {}
  ~BST() {}
  void add(T value) {
    rroooot = addNode(rroooot, value);
  }
  int depth() {
    return depthTree(rroooot);
  }
  int search(T value) {
    return searchNode(rroooot, value);
  }
};
#endif  // INCLUDE_BST_H_
