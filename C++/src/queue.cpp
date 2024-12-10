#include "../include/queue.h"

#include <fstream>
#include <iostream>

using namespace std;

void Queue::serializeBinary(const string &filename) const {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    throw runtime_error("Unable to open file for binary serialization");
  }

  Node *current = frontNode;
  while (current) {
    size_t length = current->data.size();
    outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));
    outFile.write(current->data.data(), length);
    current = current->next;
  }

  outFile.close();
}

void Queue::deserializeBinary(const string &filename) {
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

  inFile.close();
}

void Queue::serializeText(const string &filename) const {
  ofstream outFile(filename);
  if (!outFile) {
    throw runtime_error("Unable to open file for text serialization");
  }

  Node *current = frontNode;
  while (current) {
    outFile << current->data << "\n";
    current = current->next;
  }
}

void Queue::deserializeText(const string &filename) {
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
  Queue queue;

  queue.push("First");
  queue.push("Second");
  queue.push("Third");

  cout << "Binary serialization" << endl;
  queue.serializeBinary("data.bin");
  Queue binaryDser;
  binaryDser.deserializeBinary("data.bin");

  while (!binaryDser.isEmpty()) {
    cout << binaryDser.front() << endl;
    binaryDser.pop();
  }

  cout << "Text serialization" << endl;
  queue.serializeText("data.txt");
  Queue textDser;
  textDser.deserializeText("data.txt");

  while (!textDser.isEmpty()) {
    cout << textDser.front() << endl;
    textDser.pop();
  }

  return 0;
}