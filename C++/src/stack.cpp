#include "../include/stack.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void Stack::serializeBinary(const string &filename) const {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    throw runtime_error("Unable to open file for binary serialization");
  }

  Node *current = topNode;
  while (current) {
    size_t length = current->data.size();
    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));
    outFile.write(current->data.c_str(), length);
    current = current->next;
  }

  outFile.close();
}

void Stack::deserializeBinary(const string &filename) {
  ifstream inFile(filename, ios::binary);
  if (!inFile) {
    throw runtime_error("Unable to open file for binary deserialization");
  }

  while (true) {
    size_t length;
    if (!inFile.read(reinterpret_cast<char *>(&length), sizeof(length))) {
      break;
    }
    string value(length, '\0');
    inFile.read(&value[0], length);
    push(value);
  }
}

void Stack::serializeText(const string &filename) const {
  ofstream outFile(filename);
  if (!outFile) {
    throw runtime_error("Unable to open file for text serialization");
  }

  Node *current = topNode;
  while (current) {
    outFile << current->data << "\n";
    current = current->next;
  }
}

void Stack::deserializeText(const string &filename) {
  ifstream inFile(filename);
  if (!inFile) {
    throw runtime_error("Unable to open file for text deserialization");
  }

  string line;
  while (getline(inFile, line)) {
    push(line);
  }
}

int main() {
  Stack stack;

  stack.push("First");
  stack.push("Second");
  stack.push("Third");

  cout << "Binary serialization" << endl;
  stack.serializeBinary("data.bin");
  Stack binaryDser;
  binaryDser.deserializeBinary("data.bin");

  while (!binaryDser.isEmpty()) {
    cout << binaryDser.top() << endl;
    binaryDser.pop();
  }

  cout << "Text serialization" << endl;
  stack.serializeText("data.txt");
  Stack textDser;
  textDser.deserializeText("data.txt");

  while (!textDser.isEmpty()) {
    cout << textDser.top() << endl;
    textDser.pop();
  }

  return 0;
}