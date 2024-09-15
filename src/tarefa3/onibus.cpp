#include "onibus.h"
Onibus::Onibus():Veiculo()
{
    this -> passageiros = 0;
}

Onibus::Onibus(int passageiros, float capacidade_carga, std::string ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, std::string tracao, std::string especie, std::string categoria, std::string placa, float largura, float altura, float comprimento, float peso, double latitude, double longitude):Veiculo(capacidade_carga, ano_fabricacao, chassi, modelo, localizacao, tracao, especie, categoria, placa, largura, altura, comprimento, peso, latitude, longitude) 
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

int Onibus::getPassageiros()
{
    return this -> passageiros;
}

std::ostream& operator<<(std::ostream& os, Onibus& onibus)
{
    os << static_cast<Veiculo&>(onibus);
    os << "Passageiros: " << onibus.getPassageiros() << "\n";
    return os;
}