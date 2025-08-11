#include"../HeaderFiles/Decoder.h"
#include "../HeaderFiles/Encoder.h"


std::string convertToText(std::unordered_map<char,int> &freqMap,std::string &bytes)
{
  std::string originalFile;
  HuffmanNode* rootNode=buildHuffmanTree(freqMap);
  HuffmanNode* current=rootNode;
  for (char it:bytes) {
    if (it=='1') {
      current=current->right;
    }
    else {
      current=current->left;
    }
    if (current->left==nullptr && current->right==nullptr) {
      originalFile+=current->ch;
      current=rootNode;
    }
  }
  return originalFile;
}
void saveToFile(const std::string &data, const std::string &filename) {
  std::ofstream outFile(filename,std::ios::binary);
  if (!outFile.is_open()) {
    return;
  }
  outFile.write(data.data(),data.size());
  outFile.close();
}