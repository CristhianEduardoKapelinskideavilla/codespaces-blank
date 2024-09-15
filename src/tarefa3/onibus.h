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
    Onibus(int passageiros, float capacidade_carga, std::string ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, std::string tracao, std::string especie, std::string categoria, std::string placa, float largura, float altura, float comprimento, float peso, double latitude, double longitude);
    int setPassageiros(int passageiros);

    int getPassageiros();
    friend std::ostream& operator<<(std::ostream& os, Onibus& onibus);

};
#endif