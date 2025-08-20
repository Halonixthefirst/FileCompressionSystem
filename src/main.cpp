#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<filesystem>

#include "../HeaderFiles/Reader.h"
#include "../HeaderFiles/Encoder.h"
#include "../HeaderFiles/Decoder.h"

int main() {
  std::cout<<"Enter file path:";
  Reader reader;
  std::string fileName;
  std::getline(std::cin,fileName);
  std::filesystem::path p1=fileName;
  std::cout<<std::endl;
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
    int paddingBits=convertToBinary(bytes,compressedBits);

    std::string outFile="../Compressed/"+p1.stem().string()+".bin";

    std::fstream compressedFile(outFile,std::ios::binary|std::ios::out);
    if (!compressedFile.is_open()) {
      std::cout<<"Error\n";
      return 1;
    }
    size_t mapSize=freqMap.size();
    compressedFile.write(reinterpret_cast<const char *>(&mapSize),sizeof(mapSize));//Store the size of the FreqMap
    for (auto [ch,freq]:freqMap) {
      compressedFile.write(reinterpret_cast<const char *>(&ch),(sizeof(ch)));//Store a char and its size and then its freq and size;
      compressedFile.write(reinterpret_cast<const char *> (&freq),(sizeof(freq)));
    }
    compressedFile.write(reinterpret_cast<const char *>(&paddingBits),sizeof(paddingBits));
    compressedFile.write(reinterpret_cast<const char *>(bytes.data()),bytes.size());//reinterpret unsigned char as const char.
    compressedFile.close();
    std::cout<<"Compression complete\n";
  }
  else if (p1.extension()==".bin") {
    std::fstream compressedFile(p1,std::ios::binary|std::ios::in);
    if (!compressedFile.is_open()) {
      std::cout<<"Error\n";
    }
    size_t mapSize;// size_t is a datatype used for keeping sizes;
    std::unordered_map<char,int> freqMap;
    compressedFile.read(reinterpret_cast<char*>(&mapSize),sizeof(mapSize));// Get the size of map and store it.
    for (size_t i=0;i<mapSize;i++) {
      char ch;
      int freq;
      compressedFile.read(reinterpret_cast<char*> (&ch),(sizeof(ch)));
      compressedFile.read(reinterpret_cast<char*>(&freq),(sizeof(freq)));
      freqMap[ch]=freq;//Put each pair into the freqMap;
    }

    int paddingBits;
    compressedFile.read(reinterpret_cast<char *> (&paddingBits),(sizeof(paddingBits)));
    unsigned char byte;
    std::vector<unsigned char> bytes;
    while (compressedFile.read(reinterpret_cast<char*>(&byte),sizeof(byte))) {
      bytes.push_back(byte);
    }

    std::string bitString;
    for (unsigned char  bit:bytes) {
      for (int i=7;i>=0;i--) {
        bitString+=((bit>>i)&1 )?'1':'0';
      }
    }

    if (paddingBits>0) {
      bitString.erase(bitString.end()-paddingBits,bitString.end());//remove the extra padding bits from the string;
    }
    std::string originalFile=convertToText(freqMap,bitString);
    saveToFile(originalFile, "../Decompressed/"+p1.stem().string()+".txt");
    std::cout<<"File decompressed successfully\n";
  }
}
