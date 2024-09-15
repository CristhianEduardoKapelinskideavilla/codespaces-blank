#ifndef VEICULO_H
#define VEICULO_H
#include <iostream>

class Veiculo
{
protected:
    static int id;
    int id_veiculo;
    std::string capacidade_carga;
    std::string ano_fabricacao;
    std::string chassi;
    std::string modelo;
    std::string localizacao;
    std::string tracao;
    std::string especie;
    std::string categoria;
    std::string placa;
    float largura;
    float altura;
    float comprimento;
    float peso;

public:
    Veiculo();
    Veiculo(std::string capacidade_carga, std::string ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, std::string tracao, std::string especie, std::string categoria, std:: string placa, float largura, float altura, float comprimento, float peso);
    void print();
    int setCapacidade_carga(std::string capacidade_carga);
    int setAno_fabricacao(std::string ano_fabricacao);
    int setChassi(std::string chassi);
    int setModelo(std::string modelo);
    int setLocalizacao(std::string localizacao);
    int setTracao(std::string tracao);
    int setEspecie(std::string especie);
    int setCategoria(std::string categoria);
    int setPlaca(std::string placa);
    int setLargura(float largura);
    int setAltura(float altura);
    int setComprimento(float comprimento);
    int setPeso(float peso);
    
    int getId();
    std::string getCapacidade_carga();
    std::string getAno_fabricacao();
    std::string getChassi();
    std::string getModelo();
    std::string getLocalizacao();
    std::string getTracao();
    std::string getEspecie();
    std::string getCategoria();
    std::string getPlaca();
    float getLargura();
    float getAltura();
    float getComprimento();
    float getPeso();
};
#endif