#ifndef READER
#define READER

#include<string>
#include<unordered_map>
class Reader{
  public:
  std::string readFile(const std::string& filename);
  std::unordered_map<char,int> freqMap(const std::string &data);

};
#endif