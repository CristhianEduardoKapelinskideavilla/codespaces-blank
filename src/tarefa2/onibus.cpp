#include "onibus.h"
Onibus::Onibus():Veiculo()
{
    this -> passageiros = 0;
}

Onibus::Onibus(int passageiros, std::string capacidade_carga, std::string ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, std::string tracao, std::string especie, std::string categoria, std::string placa, float largura, float altura, float comprimento, float peso):Veiculo(capacidade_carga, ano_fabricacao, chassi, modelo, localizacao, tracao, especie, categoria, placa, largura, altura, comprimento, peso) 
{
    this -> passageiros = passageiros;
}

int Onibus::setPassageiros(int passageiros)
{
    if(passageiros < 0)
    {
        std::cout << "Valor de passageiros invalido" << std::endl;
        return 0;
    }
    this -> passageiros = passageiros;
    return 1;
}

void Onibus::print()
{
    std::cout << "Passageiros: " << this -> passageiros << std::endl;
    this -> Veiculo::print();
}