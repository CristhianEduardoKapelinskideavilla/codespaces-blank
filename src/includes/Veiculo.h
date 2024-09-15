#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>

class Veiculo
{
protected:
    //id é um atributo estático que será incrementado a cada novo veículo criado, ele é o mesmo para todos os Veiculos, por isso é estático, e é inicializado com 0, não é usavel pelo usuario, é apenas para controle interno, o id_veiculo que é utilizavel pelo usuario.
    static int id;
    int id_veiculo;
    float capacidade_carga;
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
    double latitude;
    double longitude;

public:
    Veiculo();
    Veiculo(float capacidade_carga, std::string ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, std::string tracao, std::string especie, std::string categoria, std:: string placa, float largura, float altura, float comprimento, float peso, double latitude, double longitude);
    int setCapacidade_carga(float capacidade_carga);
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
    int setLatitude(double latitude);
    int setLongitude(double longitude);
    
    int getId();
    float getCapacidade_carga();
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
    double getLatitude();
    double getLongitude();

    bool operator==(const Veiculo& other) const;
    friend std::ostream& operator<<(std::ostream& os, Veiculo& veiculo);
};
#endif