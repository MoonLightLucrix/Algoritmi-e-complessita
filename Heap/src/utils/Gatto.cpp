#include "Gatto.hpp"

Gatto::Gatto(std::string nome, __uint8_t età, double peso): nome(nome), età(età), peso(peso) {}

Gatto::~Gatto(){}

void Gatto::setNome(std::string nome)
{
    this->nome=nome;
}

std::string Gatto::getNome() const
{
    return nome;
}

void Gatto::setEtà(__uint8_t età)
{
    this->età=età;
}

__uint8_t Gatto::getEtà() const
{
    return età;
}

void Gatto::setPeso(double peso)
{
    this->peso=peso;
}

double Gatto::getPeso() const
{
    return peso;
}

std::string Gatto::leggiGatto() const
{
    return "Nome: " + nome + ", età: " + std::to_string(età) + ", peso: " + std::to_string(peso);
}

void Gatto::stampa() const
{
    std::cout<<leggiGatto()<<std::endl;
}

bool operator >(const Gatto&a, const Gatto&b)
{
    return (a.età>b.età);
}

bool operator <(const Gatto&a, const Gatto&b)
{
    return (a.età<b.età);
}

bool operator >=(const Gatto&a, const Gatto&b)
{
    return (a.età>=b.età);
}

bool operator <=(const Gatto&a, const Gatto&b)
{
    return (a.età<=b.età);
}

bool operator ==(const Gatto&a, const Gatto&b)
{
    return (a.età==b.età);
}

bool operator !=(const Gatto&a, const Gatto&b)
{
    return (a.età>b.età);
}

std::ostream &operator<<(std::ostream &str, const Gatto&g)
{
    str<<g.leggiGatto();
    return str;
}