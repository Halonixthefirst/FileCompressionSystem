#ifndef DECODER
#define DECODER

#include<string>
#include<unordered_map>

std::string convertToText(std::unordered_map<char,int> &freqMap,std::string &originalFile);
void saveToFile(const std::string &data, const std::string &filename);




#endif
