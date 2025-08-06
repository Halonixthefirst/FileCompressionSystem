#ifndef ENCODER
#define ENCODER

#include<string>
#include<queue>
#include<unordered_map>
#include<vector>

class HuffmanNode{
  public:
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char ch,int freq);
    HuffmanNode(int freq,HuffmanNode* left,HuffmanNode* right);
};
HuffmanNode* buildHuffmanTree(const std::unordered_map<char,int>& freqMap);
void createCode(HuffmanNode* root,std::string,std::unordered_map<char,std::string>&codes);
struct comp{
  bool operator()(HuffmanNode*a , HuffmanNode* b);
};
#endif