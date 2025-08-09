#include "../HeaderFiles/Encoder.h"

HuffmanNode::HuffmanNode(char ch,int freq){
  this->ch=ch;
  this->freq=freq;
  this->left=nullptr;
  this->right=nullptr;
}
HuffmanNode::HuffmanNode(int freq,HuffmanNode* left,HuffmanNode*right){
  this->ch='\0';
  this->freq=freq;
  this->left=left;
  this->right=right;
}

HuffmanNode* buildHuffmanTree(const std::unordered_map<char,int>& freqMap) {
  std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>,comp> Nodes;//To use comp we also write vector<T> because vector is the base of PQ
  for (auto entry:freqMap) {
    Nodes.push(new HuffmanNode(entry.first,entry.second));// Push node with ch=character, freq=freq, left=null, right=null
  }
  while (Nodes.size()>1) {
    HuffmanNode* left=Nodes.top();//Get the lowest freq Node
    Nodes.pop();
    HuffmanNode* right=Nodes.top();//Get next lowest freq Node
    Nodes.pop();
    HuffmanNode* combinedNodes=new HuffmanNode(left->freq+right->freq,left,right);//Add the frequency of the nodes and push them back
    Nodes.push(combinedNodes);
  }
  return Nodes.top();//Root Node
}

void createCode(HuffmanNode* root,std::string code,std::unordered_map<char,std::string>&codes) {
  if (root==nullptr) return;//If current node goes ahead of leaf node
  if (root->left==nullptr && root->right==nullptr) {//if current node is leaf node
    codes[root->ch]=code;// Assign Code at that point with char as key
  }
  createCode(root->left,code+'0',codes);
  createCode(root->right,code+'1',codes);
}
void convertToBinary(std::vector<unsigned char> &bytes,std::string compressedBits) {
  unsigned char currentByte=0;
  int bitCount=0;//count each bit;
  for (char bit: compressedBits) {
    currentByte=currentByte<<1;//Make space for next bit default space is zero;
    if (bit=='1') {
      currentByte=currentByte|1;//If bit is 1 then change the zero to one
    }
    bitCount++;//update count;
    if (bitCount==8) {
      bytes.push_back(currentByte);
      bitCount=0;
      currentByte=0;
    }
  }
    if (bitCount>0) {
      currentByte<<=8-(bitCount);
      bytes.push_back(currentByte);
  }
}

bool comp::operator()(HuffmanNode *a, HuffmanNode *b) {
  return a->freq>b->freq;
}
