#ifndef QUEUE_H  // QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
 public:
  Queue() : frontNode(nullptr), rearNode(nullptr) {}

  ~Queue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const std::string &value) {
    Node *newNode = new Node(value);

    if (!frontNode) {
      frontNode = rearNode = newNode;
    } else {
      rearNode->next = newNode;
      rearNode = newNode;
    }
  }

  void pop() {
    if (isEmpty()) {
      throw std::overflow_error("Queue is empty");
    }

    Node *tmp = frontNode;
    frontNode = frontNode->next;

    if (!frontNode) {
      rearNode = nullptr;
    }

    delete tmp;
  }

  std::string front() const {
    if (isEmpty()) {
      throw std::overflow_error("Queue is empty");
    }
    return frontNode->data;
  }

  bool isEmpty() const { return frontNode == nullptr; }

  void serializeBinary(const std::string &filename) const;
  void deserializeBinary(const std::string &filename);

  void serializeText(const std::string &filename) const;
  void deserializeText(const std::string &filename);

 private:
  struct Node {
    std::string data;
    Node *next;

    Node(const std::string &value) : data(value), next(nullptr) {}
  };

  Node *frontNode;
  Node *rearNode;
};

#endif  // QUEUE_H
