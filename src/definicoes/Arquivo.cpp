#include "../includes/Arquivo.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


/**
 * Converte o conteudo do csv para um array, por meio do delimitador.
*/
vector<string> *Arquivo::split(string fileName, char delimitador) {
    string *lines, dado, pathFile = this->default_path + fileName;
    vector<string> *dados = new vector<string>();

    stringstream ss(pathFile);

    while (getline(ss, dado, delimitador)) {
        dados->push_back(dado);
    }

    return dados;
}

/**
 * le o conteudo do csv em forma de array, verifica cada coluna de uma linha, e retorna um vetor contendo um map onde cada indice corresponde a um cabeçalho.
*/
vector<map<string, string>*> *Arquivo::read_csv(string fileName, char delimitador) {
        vector<map<string, string>*> *vector_csv = new vector<map<string, string>*>();
        map<string, string> *linha_csv = new map<string, string>();
        vector<string> *conteudo_csv = this->split(fileName, ';');
        vector<string> *cabecalhos = new vector<string>();
        int indice = -1, coluna = 0;
        
        for(string dado : *conteudo_csv) {
            if(dado[dado.length()-1] == '\n' || (cabecalhos->size() != 0 && cabecalhos->size()+1 == coluna+1))
                ++indice; 
                
            if(dado[dado.length()-1] == '\n')
                dado = dado.replace(dado.end()-1, dado.end(), "");
            
            if(cabecalhos->size() != 0 && cabecalhos->size()+1 == coluna+1) {
                vector_csv->push_back(linha_csv);
                coluna = 0;
                continue;
            }

            if(indice == -1) {
                cabecalhos->push_back(dado);
                continue;     
            }

            string nome_coluna = cabecalhos->at(coluna);
            linha_csv->insert(pair<string, string>(nome_coluna, dado));
            ++coluna;
        }
        return vector_csv;
}
