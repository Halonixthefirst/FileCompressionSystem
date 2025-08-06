#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<filesystem>

#include "../HeaderFiles/Reader.h"
#include "../HeaderFiles/Encoder.h"

int main() {
  Reader reader;
  std::string fileName;
  std::getline(std::cin,fileName);
  std::string data=reader.readFile(fileName);
  auto freqMap=reader.freqMap(data);

  // for (auto it:freqMap) {
  //   std::cout<<it.first<<" "<<it.second<<std::endl;
  // }

  HuffmanNode* rootNode=buildHuffmanTree(freqMap);

  std::unordered_map<char,std::string>codes;
  createCode(rootNode,"",codes);
  // for (auto it:codes) {
  //   std::cout<<it.first<<" "<<it.second<<std::endl;
  // }
  // std::string compressedFile;
  // for (char ch :data) {
    // compressedFile+=codes[ch];
  // }
  // std::cout<<compressedFile;

  //save compressed file;
  // std::filesystem::create_directory("../compressed");
}
