#ifndef STACK_H  // STACK_H
#define STACK_H

#include <iostream>

class Stack {
 public:
  Stack() : topNode(nullptr) {}

  ~Stack() {
    while (!isEmpty()) {
      pop();
    };
  }

  void push(const std::string &value) { topNode = new Node(value, topNode); }

  void pop() {
    if (isEmpty()) {
      throw std::underflow_error("Stack is empty");
    }

    Node *tmp = topNode;
    topNode = topNode->next;

    delete tmp;
  }

  std::string top() const {
    if (isEmpty()) {
      throw std::underflow_error("Stack is empty");
    }
    return topNode->data;
  }

  bool isEmpty() const { return topNode == nullptr; }

  void serializeBinary(const std::string &filename) const;
  void deserializeBinary(const std::string &filename);

  void serializeText(const std::string &filename) const;
  void deserializeText(const std::string &filename);

 private:
  struct Node {
    std::string data;
    Node *next;

    Node(const std::string &value, Node *nextNode)
        : data(value), next(nextNode) {}
  };

  Node *topNode;
};

#endif  // STACK_H
