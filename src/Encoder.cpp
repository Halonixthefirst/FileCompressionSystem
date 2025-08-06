#include "../HeaderFiles/Encoder.h"

HuffmanNode::HuffmanNode(char ch,int freq){//Single Node Constructor
  this->ch=ch;
  this->freq=freq;
  this->left=nullptr;
  this->right=nullptr;
}
HuffmanNode::HuffmanNode(int freq,HuffmanNode* left,HuffmanNode*right){//Merged n=Node constructor from 2 lowest frequency nodes;
  this->ch='\0';
  this->freq=freq;
  this->left=left;
  this->right=right;
}
HuffmanNode* buildHuffmanTree(const std::unordered_map<char,int>& freqMap) {
  std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>,comp> Nodes;
  for (auto entry:freqMap) {
    Nodes.push(new HuffmanNode(entry.first,entry.second));
  }
  while (Nodes.size()>1) {
    HuffmanNode* left=Nodes.top();
    Nodes.pop();
    HuffmanNode* right=Nodes.top();
    Nodes.pop();
    HuffmanNode* combinedNodes=new HuffmanNode(left->freq+right->freq,left,right);
    Nodes.push(combinedNodes);
  }
  return Nodes.top();
}
void createCode(HuffmanNode* root,std::string code,std::unordered_map<char,std::string>&codes) {
  if (root==nullptr) return;
  if (root->left==nullptr && root->right==nullptr) {
    codes[root->ch]=code;
  }
  createCode(root->left,code+'0',codes);
  createCode(root->right,code+'1',codes);
}




bool comp::operator()(HuffmanNode *a, HuffmanNode *b) {
  return a->freq>b->freq;
}