#ifndef READER
#define READER

#include<string>
#include<unordered_map>
class Reader{
  public:
  std::string readFile(const std::string& filename);//Input a file using binary stream;
  std::unordered_map<char,int> freqMap(const std::string &data);// go through the file using istreambuf iterator and hash each character.

};
#endif