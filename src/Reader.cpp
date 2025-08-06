#include<unordered_map>
#include<string>
#include<iterator>
#include<fstream>

#include "../HeaderFiles/Reader.h"

std::string Reader ::readFile(const std::string& filename){
  std::ifstream file(filename,std::ios::binary);
  if(!file) return "Error";
  return std::string(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());
}
std::unordered_map<char,int> Reader::freqMap(const std::string& data){
  std::unordered_map<char,int> freqMap;
  for(auto ch:data){
    freqMap[ch]++;
  }
  return freqMap;
}