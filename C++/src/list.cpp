#include "../include/list.h"

#include <fstream>
#include <iostream>

using namespace std;

void SinglyLinkedList::serializeBinary(const string &filename) const {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    throw runtime_error("Unable to open file for binary serialization");
  }

  Node *current = head;
  while (current) {
    size_t length = current->value.size();
    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));
    outFile.write(current->value.data(), length);
    current = current->next;
  }

  outFile.close();
}

void SinglyLinkedList::deserializeBinary(const string &filename) {
  ifstream inFile(filename, ios::binary);
  if (!inFile) {
    throw runtime_error("Unable to open file for binary deserialization");
  }

  while (!inFile.eof()) {
    size_t length;
    if (!inFile.read(reinterpret_cast<char *>(&length), sizeof(length))) break;

    string value(length, '\0');
    inFile.read(&value[0], length);

    addTail(value);
  }

  inFile.close();
}

void SinglyLinkedList::serializeText(const string &filename) const {
  ofstream outFile(filename);
  if (!outFile) {
    throw runtime_error("Unable to open file for text serialization");
  }

  Node *current = head;
  while (current) {
    outFile << current->value << "\n";
    current = current->next;
  }

  outFile.close();
}

void SinglyLinkedList::deserializeText(const string &filename) {
  ifstream inFile(filename);
  if (!inFile) {
    throw runtime_error("Unable to open file for text deserialization");
  }

  string line;
  while (getline(inFile, line)) {
    addTail(line);
  }

  inFile.close();
}

void DoublyLinkedList::serializeBinary(const string &filename) const {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    throw runtime_error("Unable to open file for binary serialization");
  }

  Node *current = head;
  while (current) {
    size_t length = current->value.size();
    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));
    outFile.write(current->value.data(), length);
    current = current->next;
  }

  outFile.close();
}

void DoublyLinkedList::deserializeBinary(const string &filename) {
  ifstream inFile(filename, ios::binary);
  if (!inFile) {
    throw runtime_error("Unable to open file for binary deserialization");
  }

  while (!inFile.eof()) {
    size_t length;
    if (!inFile.read(reinterpret_cast<char *>(&length), sizeof(length))) break;

    string value(length, '\0');
    inFile.read(&value[0], length);

    addTail(value);
  }

  inFile.close();
}

void DoublyLinkedList::serializeText(const string &filename) const {
  ofstream outFile(filename);
  if (!outFile) {
    throw runtime_error("Unable to open file for text serialization");
  }

  Node *current = head;
  while (current) {
    outFile << current->value << "\n";
    current = current->next;
  }

  outFile.close();
}

void DoublyLinkedList::deserializeText(const string &filename) {
  ifstream inFile(filename);
  if (!inFile) {
    throw runtime_error("Unable to open file for text deserialization");
  }

  string line;
  while (getline(inFile, line)) {
    addTail(line);
  }

  inFile.close();
}

int main() {
  SinglyLinkedList singlyList;
  singlyList.addTail("First");
  singlyList.addTail("Second");
  singlyList.addTail("Third");

  cout << "Singly list binary serialization" << endl;
  singlyList.serializeBinary("data.bin");
  SinglyLinkedList singlyListBinaryDser;
  singlyListBinaryDser.deserializeBinary("data.bin");
  singlyListBinaryDser.print();

  cout << "Singly list text serialization" << endl;
  singlyList.serializeText("data.txt");
  SinglyLinkedList singlyListTextDser;
  singlyListTextDser.deserializeText("data.txt");
  singlyListTextDser.print();

  DoublyLinkedList doublyList;
  doublyList.addTail("First");
  doublyList.addTail("Second");
  doublyList.addTail("Third");

  cout << "Doubly list binary serialization" << endl;
  doublyList.serializeBinary("data.bin");
  DoublyLinkedList doublyListBinaryDser;
  doublyListBinaryDser.deserializeBinary("data.bin");
  doublyListBinaryDser.print();

  cout << "Doubly list text serialization" << endl;
  doublyList.serializeText("data.txt");
  DoublyLinkedList doublyListTextDser;
  doublyListTextDser.deserializeText("data.txt");
  doublyListTextDser.print();

  return 0;
}