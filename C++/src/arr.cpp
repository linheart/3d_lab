#include "../include/arr.h"

#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

void Array::serializeBinary(const string &filename) const {
  ofstream outFile(filename, ios::binary);
  if (!outFile) {
    throw runtime_error("Unable to open file for binary serialization");
  }

  outFile.write(reinterpret_cast<const char *>(&length), sizeof(length));

  for (std::size_t i = 0; i < length; ++i) {
    std::size_t strSize = data[i].size();
    outFile.write(reinterpret_cast<const char *>(&strSize), sizeof(strSize));
    outFile.write(data[i].data(), strSize);
  }
  outFile.close();
}

void Array::deserializeBinary(const string &filename) {
  ifstream inFile(filename, ios::binary);
  if (!inFile) {
    throw runtime_error("Unable to open file for binary deserialization");
  }

  size_t newLength = 0;
  inFile.read(reinterpret_cast<char *>(&newLength), sizeof(newLength));

  resize(newLength);
  length = newLength;

  for (size_t i = 0; i < length; ++i) {
    size_t strSize = 0;
    inFile.read(reinterpret_cast<char *>(&strSize), sizeof(strSize));
    string str(strSize, '\0');
    inFile.read(&str[0], strSize);
    data[i] = move(str);
  }

  inFile.close();
}

void Array::serializeText(const string &filename) const {
  ofstream outFile(filename);
  if (!outFile) {
    throw runtime_error("Unable to open file for text serialization");
  }

  outFile << length << "\n";

  for (size_t i = 0; i < length; ++i) {
    outFile << data[i] << "\n";
  }

  outFile.close();
}

void Array::deserializeText(const string &filename) {
  ifstream inFile(filename);
  if (!inFile) {
    throw runtime_error("Unable to open file for text deserialization");
  }

  size_t newLength = 0;
  inFile >> newLength;

  inFile.ignore(numeric_limits<streamsize>::max(), '\n');

  resize(newLength);
  length = newLength;

  for (size_t i = 0; i < length; ++i) {
    getline(inFile, data[i]);
  }

  inFile.close();
}

int main() {
  Array arr;
  arr.append("First");
  arr.append("Second");
  arr.append("Third");

  cout << "Binary serialization" << endl;
  arr.serializeBinary("data.bin");
  Array binaryDser;
  binaryDser.deserializeBinary("data.bin");
  binaryDser.print();

  cout << "Text serialization" << endl;
  arr.serializeText("data.txt");
  Array textDser;
  textDser.deserializeText("data.txt");
  textDser.print();

  return 0;
}