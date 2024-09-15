#ifndef ONIBUS_H
#define ONIBUS_H
#include <iostream>
#include "Veiculo.h"

class Onibus: public Veiculo
{
protected:
    int passageiros;

public:
    Onibus();
    Onibus(int passageiros, std::string capacidade_carga, std::string ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, std::string tracao, std::string especie, std::string categoria, std::string placa, float largura, float altura, float comprimento, float peso);
    void print();
    int setPassageiros(int passageiros);
};
#endif