//std::string decode(std::string result,HuffmanNode* Node,std::vector<char> input) {
//  HuffmanNode* current=Node;
//  for (char it: input) {
//    if (it=='1') {
//      current=current->right;
//    }
//    else{
//      current=current->left;
//    }
//    if (current->left==nullptr && current->right==nullptr) {
//      result+=current->ch;
//      current=Node;
//    }
//  }
//  return result;