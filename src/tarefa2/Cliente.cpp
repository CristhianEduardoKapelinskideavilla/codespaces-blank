#include "Cliente.h"
#include <iostream>

Cliente::Cliente(std::string nome, std::string email, std::string endereco, std::string telefone, std::string cpf, int idade)
{
    this -> nome = nome;
    this -> email = email;
    this -> endereco = endereco;
    this -> telefone = telefone;
    this -> cpf = cpf;
    this -> idade = idade;
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

void Cliente::print()
{
    std::cout << "\nNome: " << this -> getNome() << "\n"
                << "CPF: " << this -> getCpf() << "\n"
                << "Endereço: " << this -> getEndereco() << "\n"
                << "Telefone: " << this -> getTelefone() << "\n"
                << "Email: " << this -> getEmail() << "\n"
                << "Idade: " << this -> getIdade() << " anos\n";
}

int Cliente::setNome(std::string nome)
{
    this -> nome = nome;
    return 1;
}
int Cliente::setEmail(std::string email)
{
    this -> email = email;
    return 1;
}
int Cliente::setEndereco(std::string endereco)
{
    this -> endereco = endereco;
    return 1;
}
int Cliente::setTelefone(std::string telefone)
{
    this -> telefone = telefone;
    return 1;
}
int Cliente::setCpf(std::string cpf)
{
    this -> cpf = cpf;
    return 1;
}
int Cliente::setIdade(int idade)
{
    if(idade <= 0)
    {
        printf("Idade invalida");
        return 0;
    }
    this -> idade = idade;
    return 1;
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