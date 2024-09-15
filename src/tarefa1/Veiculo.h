// Descrever a frota de veículos (carro, camionete, caminhão). Cada veículo tem suas particularidades específicas (capacidade de carga, ano de fabricação, chassi, modelo, localização, etc...)
#ifndef VEICULO_H
 #define VEICULO_H
#include <iostream>

class Veiculo
{

private:
    std::string capacidade_carga;
    std::string ano_fabricacao;
    std::string chassi;
    std::string modelo;
    std::string localizacao;
    std::string tracao;
    std::string especie;
    std::string categoria;
    float largura;
    float altura;
    float comprimento;
    float peso;

public:
    Veiculo();
    Veiculo(std::string cargcapac, std::string anofab, std::string chas, std::string modl, std::string loc, std::string tra, std::string esp, std::string ca, float larg, float alt, float comp, float pes);
    void setCapacidade_carga(std::string cargcapac);
    void setAno_fabricacao(std::string anofab);
    void setChassi(std::string chas);
    void setModelo(std::string modl);
    void setLocalizacao(std::string loc);
    void setTracao(std::string tra);
    void setEspecie(std::string esp);
    void setCategoria(std::string ca);
    void setLargura(float larg);
    void setAltura(float alt);
    void setComprimento(float comp);
    void setPeso(float);

    std::string getCapacidade_carga();
    std::string getAno_fabricacao();
    std::string getChassi();
    std::string getModelo();
    std::string getLocalizacao();
    std::string getTracao();
    std::string getEspecie();
    std::string getCategoria();
    float getLargura();
    float getAltura();
    float getComprimento();
    float getPeso();
};
#endif