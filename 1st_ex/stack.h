#ifndef STACK_H  // STACK_H
#define STACK_H

#include <cassert>

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
    assert(!isEmpty());

    Node *tmp = topNode;
    topNode = topNode->next;

    delete tmp;
  }

  std::string top() const {
    assert(!isEmpty());
    return topNode->data;
  }

  bool isEmpty() const { return topNode == nullptr; }

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