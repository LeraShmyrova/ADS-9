// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
  struct Node {
  int ccut;
  Node *prrav;
  Node *leevv;
  T vallu;
  };
  Node *rt;

  Node* addNode(Node* rt, T vallu) {
    if (rt == nullptr) {
      rt = new Node;
      rt->vallu = vallu;
      rt->ccut = 1;
      rt->leevv = rt->prrav = nullptr;
    } else if (rt->vallu > vallu) {
      rt->prrav = addNode(rt->prrav, vallu);
    } else if (rt->vallu < vallu) {
      rt->leevv = addNode(rt->leevv, vallu);
    } else {
      rt->ccut++;
    }
      return rt;
  }

  int searchNode(Node* rt, T vallu) {
    if (rt == nullptr) {
      return 0;
    } else if (rt->vallu < vallu) {
      return searchNode(rt->leevv, vallu);
    } else if (rt->vallu > vallu) {
      return searchNode(rt->prrav, vallu);
    } else {
      return rt->ccut;
    }
  }

  int hTee(Node* rt) {
    if (rt == nullptr)
    return 0;
    if (rt->leevv == nullptr && rt->prrav == nullptr)
    return 0;
    int l = hTee(rt->leevv);
    int r = hTee(rt->prrav);
    return r > l ? r + 1 : l + 1;
  }

 public:
  BST() : rt(nullptr) {}
  void add(T vallu) {
  rt = addNode(rt, vallu);
  }
  int search(T vallu) {
  return searchNode(rt, vallu);
  }
  int depth() {
  return hTee(rt);
  }
};

#endif  // INCLUDE_BST_H_
