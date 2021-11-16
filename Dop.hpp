#ifndef DOP_HPP
#define DOP_HPP

#include <iostream>
#include <cstring>
using namespace std;

class Dop {
protected:
    int diametru;
    char *tip;
public:
    Dop();  //constructor fara parametrii
    Dop(int, const char*);  //constructor cu parametrii
    Dop(const Dop&);    //constructor de copiere
    ~Dop();

    Dop& operator=(const Dop&);     //operator =
	friend std::ostream& operator<<(std::ostream&, const Dop&);
	friend std::istream& operator>>(std::istream&, Dop&);
    int getDiametru();
    void interschimbare1(Dop&);

};

#endif
