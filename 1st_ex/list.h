#ifndef LIST_H  // LIST_H
#define LIST_H

class SinglyLinkedList {
  SinglyLinkedList() : head(nullptr) {}

  ~SinglyLinkedList() {
    while (head) {
      Node *tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void addHead(std::string value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  void addTail(std::string value) {
    Node *newNode = new Node(value);
    if (!head) {
      head = newNode;
      return;
    }

    Node *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  void removeHead() {
    if (!head) return;

    Node *tmp = head;
    head = head->next;
    delete tmp;
  }

  void removeTail() {
    if (!head) return;

    if (!head->next) {
      delete head;
      head = nullptr;
      return;
    }

    Node *current = head;
    while (current->next && current->next->next) {
      current = current->next;
    }

    delete current->next;
    current->next = nullptr;
  }

  void removeByValue(std::string value) {
    if (!head) return;

    if (head->value == value) {
      removeHead();
      return;
    }

    Node *current = head;
    while (current->next && current->next->value != value) {
      current = current->next;
    }

    if (current->next) {
      Node *tmp = current->next;
      current->next = current->next->next;
      delete tmp;
    }
  }

  bool search(std::string value) const {
    Node *current = head;
    while (current) {
      if (current->value == value) {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  void print() const {
    Node *current = head;
    while (current) {
      std::cout << current->value << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

 private:
  struct Node {
    std::string value;
    Node *next;

    Node(std::string val) : value(val), next(nullptr) {}
  };

  Node *head;

 public:
};

class DoublyLinkedList {
 public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  ~DoublyLinkedList() {
    while (head) {
      Node *tmp = head;
      head = head->next;
      delete tmp;
    }
    tail = nullptr;
  }

  void addHead(std::string value) {
    Node *newNode = new Node(value);
    newNode->next = head;

    if (head) {
      head->prev = newNode;
    } else {
      tail = newNode;
    }

    head = newNode;
  }

  void addTail(std::string value) {
    Node *newNode = new Node(value);
    newNode->prev = tail;

    if (tail) {
      tail->next = newNode;
    } else {
      head = newNode;
    }

    tail = newNode;
  }

  void removeHead() {
    if (!head) return;

    Node *tmp = head;
    head = head->next;

    if (head) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }

    delete tmp;
  }

  void removeTail() {
    if (!tail) return;

    Node *tmp = tail;
    tail = tail->prev;

    if (tail) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }

    delete tmp;
  }

  void removeByValue(std::string value) {
    if (!head) return;

    if (head->value == value) {
      removeHead();
      return;
    }

    Node *current = head;
    while (current && current->value != value) {
      current = current->next;
    }

    if (current) {
      if (current->prev) {
        current->prev->next = current->next;
      }
      if (current->next) {
        current->next->prev = current->prev;
      }

      if (current == tail) {
        tail = current->prev;
      }

      delete current;
    }
  }

  bool search(std::string value) const {
    Node *current = head;
    while (current) {
      if (current->value == value) {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  void print() const {
    Node *current = head;
    while (current) {
      std::cout << current->value << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

 private:
  struct Node {
    std::string value;
    Node *next;
    Node *prev;

    Node(std::string val) : value(val), next(nullptr), prev(nullptr) {}
  };

  Node *head;
  Node *tail;
};

#endif  // LIST_H