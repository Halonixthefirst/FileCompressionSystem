#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<filesystem>

#include "../HeaderFiles/Reader.h"
#include "../HeaderFiles/Encoder.h"
#include<filesystem>
int main() {
  Reader reader;
  std::string fileName;
  std::getline(std::cin,fileName);
  std::filesystem::path p1=fileName;
  if (p1.extension()==".txt"){
    if (reader.readFile(fileName)=="Error") {
      std::cout<<"Error\n";
      return 1;
    };
    std::string data=reader.readFile(fileName);
    auto freqMap=reader.freqMap(data);

    HuffmanNode* rootNode=buildHuffmanTree(freqMap);

    std::unordered_map<char,std::string>codes;
    createCode(rootNode,"",codes);// codes;

    std::string compressedBits="";

    for (char ch:data) {
      compressedBits+=codes[ch];
    }
    std::vector<unsigned char> bytes;//Encoded structure;
    convertToBinary(bytes,compressedBits);

    std::fstream compressedFile(fileName+".bin",std::ios::binary|std::ios::out);
    size_t mapSize=freqMap.size();
    compressedFile.write(reinterpret_cast<const char *>(&mapSize),sizeof(mapSize));//Store the size of the FreqMap
    for (auto [ch,freq]:freqMap) {
      compressedFile.write(reinterpret_cast<const char *>(&ch),(sizeof(ch)));//Store a char and its size and then its freq and size;
      compressedFile.write(reinterpret_cast<const char *> (&freq),(sizeof(freq)));
    }
    compressedFile.write(reinterpret_cast<const char *>(bytes.data()),bytes.size());//reinterpret unsigned char as const char.
    compressedFile.close();
    std::cout<<"Compression complete\n";
  }
  else if (p1.extension()==".bin") {
    std::cout<<"Its a work in progress honey\n";
    return 0;
  }
}
