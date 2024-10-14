#ifndef GATTO
#define GATTO

#include<iostream>
#include<cstdlib>
#include<cstring>

class Gatto
{
    private:
        std::string nome;
        __uint8_t età;
        double peso;
    public:
        Gatto(std::string nome="", __uint8_t età=0, double peso=0);
        ~Gatto();
        void setNome(std::string nome);
        std::string getNome() const;
        void setEtà(__uint8_t età);
        __uint8_t getEtà() const;
        void setPeso(double peso);
        double getPeso() const;
        std::string leggiGatto() const;
        void stampa() const;
        friend bool operator >(const Gatto&a, const Gatto&b);
        friend bool operator <(const Gatto&a, const Gatto&b);
        friend bool operator >=(const Gatto&a, const Gatto&b);
        friend bool operator <=(const Gatto&a, const Gatto&b);
        friend bool operator ==(const Gatto&a, const Gatto&b);
        friend bool operator !=(const Gatto&a, const Gatto&b);
        friend std::ostream& operator <<(std::ostream &str, const Gatto&g);
};

#endif