#ifndef ENCODER
#define ENCODER

#include<string>
#include<queue>
#include<unordered_map>
#include<vector>
#include<fstream>

class HuffmanNode{
  public:
    char ch;
    int freq;
    char minChar;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char ch,int freq);//Single Node Constructor
    HuffmanNode(int freq,HuffmanNode* left,HuffmanNode* right);//Merged Node constructor from 2 lowest frequency nodes;
};
HuffmanNode* buildHuffmanTree(const std::unordered_map<char,int>& freqMap);
void createCode(HuffmanNode* root,std::string,std::unordered_map<char,std::string>&codes);
struct comp{
  bool operator()(HuffmanNode*a , HuffmanNode* b);
};
int convertToBinary(std::vector<unsigned char> &bytes,std::string compressedBits);

#endif