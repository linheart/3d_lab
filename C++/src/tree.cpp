#include "../include/tree.h"

#include <fstream>
#include <functional>
#include <iostream>

using namespace std;

void Tree::serializeBinary(const string &filename) const {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    throw runtime_error("Unable to open file for binary serialization");
  }

  std::function<void(Node *)> serializeNode = [&](Node *node) {
    if (!node) {
      bool hasNode = false;
      outFile.write(reinterpret_cast<const char *>(&hasNode), sizeof(hasNode));
      return;
    }
    bool hasNode = true;
    outFile.write(reinterpret_cast<const char *>(&hasNode), sizeof(hasNode));
    outFile.write(reinterpret_cast<const char *>(&node->key),
                  sizeof(node->key));
    serializeNode(node->left);
    serializeNode(node->right);
  };
  serializeNode(root);
}

void Tree::deserializeBinary(const string &filename) {
  ifstream inFile(filename, ios::binary);
  if (!inFile) {
    throw runtime_error("Unable to open file for binary deserialization");
  }

  std::function<Node *()> deserializeNode = [&]() -> Node * {
    bool hasNode;
    inFile.read(reinterpret_cast<char *>(&hasNode), sizeof(hasNode));
    if (!inFile || !hasNode) {
      return nullptr;
    }

    int value;
    inFile.read(reinterpret_cast<char *>(&value), sizeof(value));
    Node *node = new Node(value);
    node->left = deserializeNode();
    node->right = deserializeNode();
    return node;
  };
  root = deserializeNode();
}

void Tree::serializeText(const string &filename) const {
  ofstream outFile(filename);
  if (!outFile) {
    throw runtime_error("Unable to open file for text serialization");
  }

  function<void(Node *)> serializeNode = [&](Node *node) {
    if (!node) {
      outFile << "# ";
      return;
    }
    outFile << node->key << " ";
    serializeNode(node->left);
    serializeNode(node->right);
  };
  serializeNode(root);
}

void Tree::deserializeText(const string &filename) {
  ifstream inFile(filename);
  if (!inFile) {
    throw runtime_error("Unable to open file for text deserialization");
  }

  function<Node *()> deserializeNode = [&]() -> Node * {
    string token;
    inFile >> token;
    if (!inFile || token == "#") {
      return nullptr;
    }
    int value = stoi(token);
    Node *node = new Node(value);
    node->left = deserializeNode();
    node->right = deserializeNode();
    return node;
  };
  root = deserializeNode();
}

int main() {
  Tree tree;

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);

  cout << "Binary serialization" << endl;
  tree.serializeBinary("data.bin");
  Tree binaryDser;
  binaryDser.deserializeBinary("data.bin");
  binaryDser.print();

  cout << "Text serialization" << endl;
  tree.serializeText("data.txt");
  Tree textDser;
  textDser.deserializeText("data.txt");
  textDser.print();

  return 0;
}