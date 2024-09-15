#include "Cliente.h"
#include <iostream>

Cliente::Cliente(std::string nom, std::string eml, std::string endrc, std::string fone, std::string cf, int idd)
{
    this -> nome = nom;
    this -> email = eml;
    this -> endereco = endrc;
    this -> telefone = fone;
    this -> cpf = cf;
    this -> idade = idd;
}

Cliente::Cliente()
{
    this -> nome = "";
    this -> email = "";
    this -> endereco = "";
    this -> telefone = "";
    this -> cpf = "";
    this -> idade = 0;
}

void Cliente::setNome(std::string nom)
{
    this -> nome = nom;
}
void Cliente::setEmail(std::string eml)
{
    this -> email = eml;
}
void Cliente::setEndereco(std::string endrc)
{
    this -> endereco = endrc;
}
void Cliente::setTelefone(std::string fone)
{
    this -> telefone = fone;
}
void Cliente::setCpf(std::string cf)
{
    this -> cpf = cf;
}
void Cliente::setIdade(int idd)
{
    if(idd <= 0)
    {
        printf("Idade invalida");
        return;
    }
    this -> idade = idd;
}



std::string Cliente::getNome()
{
    return this -> nome;
}
std::string Cliente::getEmail()
{
    return this -> email;
}
std::string Cliente::getEndereco()
{
    return this -> endereco;
}
std::string Cliente::getTelefone()
{
    return this -> telefone;
}
std::string Cliente::getCpf()
{
    return this -> cpf;
}
int Cliente::getIdade()
{
    return this -> idade;
}