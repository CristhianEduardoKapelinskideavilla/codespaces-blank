#include "Veiculo.h"
#include <iostream>

Veiculo::Veiculo()
{
    this -> capacidade_carga = "";
    this -> ano_fabricacao = "";
    this -> chassi = "";
    this -> modelo = "";
    this -> localizacao = "";
    this -> tracao = "";
    this -> especie = "";
    this -> categoria = "";
    float largura = 0;
    float altura = 0;
    float comprimento = 0;
    float peso = 0;
}

Veiculo::Veiculo(std::string cargcapac, std::string anofab, std::string chas, std::string modl, std::string loc, std::string tra, std::string esp, std::string ca, float larg, float alt, float comp, float pes)
{
    this -> capacidade_carga = cargcapac;
    this -> ano_fabricacao = anofab;
    this -> chassi = chas;
    this -> modelo = modl;
    this -> localizacao = loc;
    this -> tracao = tra;
    this -> especie = esp;
    this -> categoria = ca;
    this -> largura = larg;
    this -> altura = alt;
    this -> comprimento = comp;
    this -> peso = pes;
}

void Veiculo::setCapacidade_carga(std::string cargcapac)
{
    this -> capacidade_carga = cargcapac;
}
void Veiculo::setAno_fabricacao(std::string anofab)
{
    this -> ano_fabricacao = anofab;
}
void Veiculo::setChassi(std::string chas)
{
    this -> chassi = chas;
}
void Veiculo::setModelo(std::string modl)
{
    this -> modelo = modl;
}
void Veiculo::setLocalizacao(std::string loc)
{
    this -> localizacao = loc;
}
void Veiculo::setTracao(std::string tra)
{
    this -> tracao = tra;
}
void Veiculo::setEspecie(std::string esp)
{
    this -> especie = esp;
}
void Veiculo::setCategoria(std::string ca)
{
    this -> categoria = ca;
}
void Veiculo::setLargura(float larg)
{
    if(larg < 0)
    {
        std::cout << "Valor de largura invalido, setado como 0" << std::endl;
        larg = 0;
    }
    this -> largura = larg;
}
void Veiculo::setAltura(float alt)
{
    if(alt < 0)
    {
        std::cout << "Valor de altura invalido, setado como 0" << std::endl;
        alt = 0;
    }
    this -> altura = alt;
}
void Veiculo::setComprimento(float comp)
{
    if(comp < 0)
    {
        std::cout << "Valor de comprimento invalido, setado como 0" << std::endl;
        comp = 0;
    }
    this -> comprimento = comp;
}
void Veiculo::setPeso(float pes)
{
    if(pes < 0)
    {
        std::cout << "Valor de peso invalido" << std::endl;
        pes = 0;
    }
    this -> peso = pes;
}



std::string Veiculo::getCapacidade_carga()
{
    return this -> capacidade_carga;
}
std::string Veiculo::getAno_fabricacao()
{
    return this -> ano_fabricacao;
}
std::string Veiculo::getChassi()
{
    return this -> chassi;
}
std::string Veiculo::getModelo()
{
    return this -> modelo;
}
std::string Veiculo::getLocalizacao()
{
    return this -> localizacao;
}
std::string Veiculo::getTracao()
{
    return this -> tracao;
}
std::string Veiculo::getEspecie()
{
    return this -> especie;
}
std::string Veiculo::getCategoria()
{
    return this -> categoria;
}
float Veiculo::getLargura()
{
    return this -> largura;
}
float Veiculo::getAltura()
{
    return this -> altura;
}
float Veiculo::getComprimento()
{
    return this -> comprimento;
}
float Veiculo::getPeso()
{
    return this -> peso;
}