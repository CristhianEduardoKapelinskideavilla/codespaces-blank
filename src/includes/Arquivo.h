#ifndef ARQUIVO_H_
#define ARQUIVO_H_
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Arquivo
{
private:
    string default_path = "../assets";
public:
    vector<map<string, string>*> *read_csv(string fileName, char delimitador);
    vector<string> *split(string fileName, char delimitador);

};

#endif
