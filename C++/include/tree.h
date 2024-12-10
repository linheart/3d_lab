#ifndef TREE_H  // TREE_H
#define TREE_H

#include <iostream>

class Tree {
 public:
  Tree() : root(nullptr) {}

  ~Tree() { freeTree(root); }

  void insert(int value) { root = insert(root, value); }

  void remove(int value) { root = removeValue(root, value); }

  bool find(int value) const { return findValue(root, value); }

  void print() const { printTree("", root); }

  void serializeBinary(const std::string &filename) const;
  void deserializeBinary(const std::string &filename);

  void serializeText(const std::string &filename) const;
  void deserializeText(const std::string &filename);

 private:
  struct Node {
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
  };

  Node *root;

  int height(Node *node) const { return node ? node->height : 0; }

  int bFactor(Node *node) const {
    return height(node->right) - height(node->left);
  }

  void fixHeight(Node *node) {
    int hl = height(node->left);
    int hr = height(node->right);
    node->height = std::max(hl, hr) + 1;
  }

  Node *rotateRight(Node *node) {
    Node *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    fixHeight(node);
    fixHeight(tmp);
    return tmp;
  }

  Node *rotateLeft(Node *node) {
    Node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    fixHeight(node);
    fixHeight(tmp);
    return tmp;
  }

  Node *balance(Node *node) {
    fixHeight(node);
    if (bFactor(node) == 2) {
      if (bFactor(node->right) < 0) {
        node->right = rotateRight(node->right);
      }
      return rotateLeft(node);
    }

    if (bFactor(node) == -2) {
      if (bFactor(node->left) > 0) {
        node->left = rotateLeft(node->left);
      }
      return rotateRight(node);
    }

    return node;
  }

  Node *insert(Node *node, int value) {
    if (!node) {
      return new Node(value);
    }

    if (value < node->key) {
      node->left = insert(node->left, value);
    } else if (value > node->key) {
      node->right = insert(node->right, value);
    }

    return balance(node);
  }

  Node *findMin(Node *node) const {
    return node->left ? findMin(node->left) : node;
  }

  Node *removeMin(Node *node) {
    if (!node->left) {
      return node->right;
    }
    node->left = removeMin(node->left);
    return balance(node);
  }

  Node *removeValue(Node *node, int value) {
    if (!node) {
      return nullptr;
    }

    if (value < node->key) {
      node->left = removeValue(node->left, value);
    } else if (value > node->key) {
      node->right = removeValue(node->right, value);
    } else {
      Node *left = node->left;
      Node *right = node->right;

      delete node;

      if (!right) {
        return left;
      }

      Node *min = findMin(right);
      min->right = removeMin(right);
      min->left = left;

      return balance(min);
    }

    return balance(node);
  }

  void freeTree(Node *node) {
    if (!node) {
      return;
    }

    freeTree(node->left);
    freeTree(node->right);
    delete node;
  }

  bool findValue(Node *node, int value) const {
    if (!node) {
      return false;
    }

    if (value == node->key) {
      return true;
    }

    if (value < node->key) {
      return findValue(node->left, value);
    }

    return findValue(node->right, value);
  }

  void printTree(const std::string &prefix = "", Node *node = nullptr,
                 bool isLeft = true) const {
    if (node != nullptr) {
      std::cout << prefix;
      std::cout << (isLeft ? "|--" : "L--");
      std::cout << node->key << std::endl;

      printTree(prefix + (isLeft ? "|   " : "    "), node->right, true);
      printTree(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
  }
};

#endif  // TREE_H
