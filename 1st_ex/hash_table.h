#ifndef HASH_TABLE_H  // HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>

class HT {
 public:
  HT() {
    node = new Node *[size];
    for (size_t i = 0; i < size; i++) {
      node[i] = nullptr;
    }
  }

  ~HT() {
    for (size_t i = 0; i < size; i++) {
      Node *current = node[i];
      while (current != nullptr) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
      }
      node[i] = nullptr;
    }
    delete[] node;
  }

  std::string &operator[](const std::string &key) {
    unsigned index = hashFunction(key);
    Node *current = node[index];

    while (current) {
      if (current->key == key) {
        return current->value;
      }
      current = current->next;
    }

    Node *newNode = new Node(key, "");
    newNode->next = node[index];
    node[index] = newNode;
    return newNode->value;
  }

 private:
  struct Node {
    std::string key;
    std::string value;
    Node *next;

    Node(const std::string &k, const std::string &v)
        : key(k), value(v), next(nullptr) {}
    ~Node() { delete next; }
  };

  Node **node;

  unsigned hashFunction(const std::string &key) const {
    std::hash<std::string> hasher;
    return hasher(key) % size;
  }

  size_t size = 100;
};

#endif  // HASH_TABLE_H