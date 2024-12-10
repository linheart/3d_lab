#include "../include/hash_table.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void HT::serializeBinary(const string &filename) const {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    throw runtime_error("Unable to open file for binary serialization");
  }

  for (size_t i = 0; i < size; i++) {
    Node *current = node[i];
    while (current) {
      size_t keySize = current->key.size();
      size_t valueSize = current->value.size();

      outFile.write(reinterpret_cast<const char *>(&keySize), sizeof(keySize));
      outFile.write(current->key.c_str(), keySize);
      outFile.write(reinterpret_cast<const char *>(&valueSize),
                    sizeof(valueSize));
      outFile.write(current->value.c_str(), valueSize);
      current = current->next;
    }
  }
  outFile.close();
}

void HT::deserializeBinary(const string &filename) {
  ifstream inFile(filename, ios::binary);
  if (!inFile) {
    throw runtime_error("Unable to open file for binary deserialization");
  }

  while (!inFile.eof()) {
    size_t keySize, valueSize;

    inFile.read(reinterpret_cast<char *>(&keySize), sizeof(keySize));
    string key(keySize, '\0');
    inFile.read(&key[0], keySize);

    inFile.read(reinterpret_cast<char *>(&valueSize), sizeof(valueSize));
    string value(valueSize, '\0');
    inFile.read(&value[0], valueSize);

    (*this)[key] = value;
  }

  inFile.close();
}

void HT::serializeText(const std::string &filename) const {
  ofstream outFile(filename);
  if (!outFile) {
    throw runtime_error("Unable to open file for text serialization");
  }

  for (size_t i = 0; i < size; i++) {
    Node *current = node[i];
    while (current) {
      outFile << current->key << "=" << current->value << "\n";
      current = current->next;
    }
  }

  outFile.close();
}

void HT::deserializeText(const std::string &filename) {
  ifstream inFile(filename);
  if (!inFile) {
    throw runtime_error("Unable to open file for text deserialization");
  }

  string line;
  while (getline(inFile, line)) {
    istringstream stream(line);
    string key;
    string value;

    if (getline(stream, key, '=') && (stream >> value)) {
      (*this)[key] = value;
    }
  }

  inFile.close();
}

int main() {
  HT ht;
  ht["key1"] = "First";
  ht["key2"] = "Second";
  ht["key3"] = "Third";

  cout << "Binary serialization" << endl;
  ht.serializeBinary("data.bin");
  HT binaryDser;
  binaryDser.deserializeBinary("data.bin");

  cout << binaryDser["key1"] << endl;
  cout << binaryDser["key2"] << endl;
  cout << binaryDser["key3"] << endl;

  cout << "Text serialization" << endl;
  ht.serializeText("data.txt");
  HT textDser;
  textDser.deserializeText("data.txt");

  cout << textDser["key1"] << endl;
  cout << textDser["key2"] << endl;
  cout << textDser["key3"] << endl;
  return 0;
}