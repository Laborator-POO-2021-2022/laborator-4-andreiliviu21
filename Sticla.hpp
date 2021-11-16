#ifndef STICLA_HPP
#define STICLA_HPP

#include "Dop.hpp"

class Sticla : public Dop {
    int pret;
    char* marca;
public:
    Sticla();   //constructor fara parametrii
    Sticla(int, const char*, int, const char*);     //constructor cu parametrii
    Sticla(const Sticla&);     //constructor de copiere  
    ~Sticla();      //destructor

    Sticla& operator=(const Sticla&);       //operator =
	friend std::ostream& operator<<(std::ostream&, const Sticla&);
	friend std::istream& operator>>(std::istream&, Sticla&);
    int getPret();
    void interschimbare2(Sticla&);


};

#endif