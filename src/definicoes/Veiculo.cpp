#include "../includes/Veiculo.h"
#include <iostream>

Veiculo::Veiculo()
{
    this -> id_veiculo = Veiculo::id;
    this -> capacidade_carga = 0;
    this -> ano_fabricacao = "";
    this -> chassi = "";
    this -> modelo = "";
    this -> localizacao = "";
    this -> tracao = "";
    this -> especie = "";
    this -> categoria = "";
    this -> placa = "";
    this -> largura = 0;
    this -> altura = 0;
    this -> comprimento = 0;
    this -> peso = 0;
    this -> longitude = 0;
    this -> latitude = 0;
}

Veiculo::Veiculo(float capacidade_carga, std::string ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, std::string tracao, std::string especie, std::string categoria, std::string placa, float largura, float altura, float comprimento, float peso, double latitude, double longitude)
{
    this -> id_veiculo = ++Veiculo::id;
    this -> capacidade_carga = capacidade_carga;
    this -> ano_fabricacao = ano_fabricacao;
    this -> chassi = chassi;
    this -> modelo = modelo;
    this -> localizacao = localizacao;
    this -> tracao = tracao;
    this -> especie = especie;
    this -> categoria = categoria;
    this -> placa = placa;
    this -> largura = largura;
    this -> altura = altura;
    this -> comprimento = comprimento;
    this -> peso = peso;
    this -> latitude = latitude;
    this -> longitude = longitude;
}

int Veiculo::id = 0;

int Veiculo::setCapacidade_carga(float capacidade_carga)
{
    this -> capacidade_carga = capacidade_carga;
    return 1;
}
int Veiculo::setAno_fabricacao(std::string ano_fabricacao)
{
    this -> ano_fabricacao = ano_fabricacao;
    return 1;
}
int Veiculo::setChassi(std::string chassi)
{
    this -> chassi = chassi;
    return 1;
}
int Veiculo::setModelo(std::string modelo)
{
    this -> modelo = modelo;
    return 1;
}
int Veiculo::setLocalizacao(std::string localizacao)
{
    this -> localizacao = localizacao;
    return 1;
}
int Veiculo::setTracao(std::string tracao)
{
    this -> tracao = tracao;
    return 1;
}
int Veiculo::setEspecie(std::string especie)
{
    this -> especie = especie;
    return 1;
}
int Veiculo::setCategoria(std::string categoria)
{
    this -> categoria = categoria;
    return 1;
}
int Veiculo::setPlaca(std::string placa)
{
    this -> placa = placa;
    return 1;
}
int Veiculo::setLargura(float largura)
{
    if(largura < 0)
    {
        std::cout << "Valor de largura invalido, setado como 0" << std::endl;
        return 0;
    }
    this -> largura = largura;
    return 1;
}
int Veiculo::setAltura(float altura)
{
    if(altura < 0)
    {
        std::cout << "Valor de altura invalido, setado como 0" << std::endl;
        return 0;
    }
    this -> altura = altura;
    return 1;
}
int Veiculo::setComprimento(float comprimento)
{
    if(comprimento < 0)
    {
        std::cout << "Valor de comprimento invalido, setado como 0" << std::endl;
        return 0;
    }
    this -> comprimento = comprimento;
    return 1;
}
int Veiculo::setPeso(float peso)
{
    if(peso < 0)
    {
        std::cout << "Valor de peso invalido" << std::endl;
        return 0;
    }
    this -> peso = peso;
    return 1;
}
int Veiculo::setLatitude(double latitude)
{
    this -> latitude = latitude;
    return 1;
}
int Veiculo::setLongitude(double longitude)
{
    this -> longitude = longitude;
    return 1;
}



int Veiculo::getId()
{
    return this -> id_veiculo;
}
float Veiculo::getCapacidade_carga()
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
std::string Veiculo::getPlaca()
{
    return this -> placa;
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
double Veiculo::getLatitude()
{
    return this -> latitude;
}
double Veiculo::getLongitude()
{
    return this -> longitude;
}

bool Veiculo::operator==(const Veiculo& other) const
{
    return this -> id_veiculo == other.id_veiculo;
}
std::ostream& operator<<(std::ostream& os, Veiculo& veiculo)
{
    os << "Modelo: "<< veiculo.getModelo() << "\n"
                << "Capacidade de Carga: " << veiculo.getCapacidade_carga() << "\n"
                << "Id: " << veiculo.getId() << "\n"
                << "Ano de Fabricação: " << veiculo.getAno_fabricacao() << "\n"
                << "Chassi: " << veiculo.getChassi() << "\n"
                << "Localização: " << veiculo.getLocalizacao() << "\n"
                << "Tracao: " << veiculo.getTracao() << "\n"
                << "Especie: " << veiculo.getEspecie() << "\n"
                << "Categoria: " << veiculo.getCategoria() << "\n"
                << "Placa: " << veiculo.getPlaca() << "\n"
                << "Largura: " << veiculo.getLargura() << "cm\n"
                << "Altura: " << veiculo.getAltura() << "cm\n"
                << "Comprimento: " << veiculo.getComprimento() << "cm\n"
                << "Peso: " << veiculo.getPeso() << "kg\n"
                << "Latitude: " << veiculo.getLatitude() << "\n"
                << "Longitude: " << veiculo.getLongitude() << "\n";
    return os;
}