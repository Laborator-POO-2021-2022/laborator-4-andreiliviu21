#include "Dop.hpp"

Dop::Dop():diametru(0), tip(NULL) {
    // std::cout << "Dop: Constructor fara parametrii" << endl;
}

Dop::Dop(int diametru, const char* tip):diametru(diametru) {
    // std::cout << "Dop: Constructor cu parametrii" << endl;
    this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip,tip);

}

Dop::Dop(const Dop& obj) {
	// std::cout << "Dop: Constructor de copiere" << endl;
    tip = NULL;
    *this = obj;
}

Dop::~Dop() {
    // std::cout << "Dop dead x_x" << endl;
    delete []tip;
}

Dop& Dop::operator=(const Dop& obj) {
    if(tip != NULL ) {
        delete tip;
    }
    this->tip = new char[strlen(obj.tip) + 1];
    strcpy(this->tip, obj.tip);
    this->diametru = obj.diametru;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Dop& obj) {
	out << "Diametru: " << obj.diametru << std::endl;
	out << "Tip: " << obj.tip << std::endl;
	
	return out;
}

std::istream& operator>>(std::istream& in, Dop& obj) {
	std::cout << "Introdu tipul dopului:\n";
    char tip[10];
    in >> (tip);
    delete obj.tip;
    obj.tip = new char[strlen(tip) + 1];
	strcpy(obj.tip,tip);
    
    // in >> (obj.tip);
    std::cout << "Introdu diametrul dopului: \n";
    in >> obj.diametru;
	
	return in;
}

int Dop::getDiametru() {
    return diametru;
}

void Dop::interschimbare1(Dop& obj1) {
    Dop aux (*this);
    *this = obj1;
    obj1 = aux;

}