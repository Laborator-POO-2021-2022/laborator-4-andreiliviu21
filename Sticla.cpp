#include "Sticla.hpp"

Sticla::Sticla():pret(0), marca(NULL) {
    // std::cout << "Sticla: Constructor fara parametri" << endl;

} 

Sticla::Sticla(int diametru, const char* tip, int pret, const char* marca):Dop(diametru, tip), pret(pret) {
    // std::cout << "Sticla: Constructor cu parametri" << endl;

    this->marca = new char[strlen(marca) + 1];
    strcpy(this->marca, marca);
}

Sticla::Sticla(const Sticla& obj) {
    // std::cout << "Sticla: Constructor de copiere" << endl;
    marca = NULL;
    *this = obj;
}

Sticla::~Sticla() {
    // std::cout << "Sticla dead x_x" << endl;
    delete[] marca;
}

Sticla& Sticla::operator=(const Sticla& obj) {
    if(marca != NULL ) {
        delete marca;
    }
    this->marca = new char[strlen(obj.marca) + 1];
    strcpy(this->marca, obj.marca);
    this->pret = obj.pret;
	
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Sticla& obj) {
    out << (Dop&)obj;
	out << "Pret: " << obj.pret << endl;
	out << "Marca: " << obj.marca << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Sticla& obj) {
	in >> (Dop&)obj;
    std::cout << "Introdu pretul: \n";
	in >> obj.pret;
    std::cout << "Introdu marca: \n";
    char marca[10];
    in >> (marca);
    delete obj.marca;
    obj.marca = new char[strlen(marca) + 1];
	strcpy(obj.marca,marca);
    return in;
}

int Sticla::getPret() {
    return pret;
}

void Sticla::interschimbare2(Sticla& obj1) {
    Sticla aux (*this);
    *this = obj1;
    obj1 = aux;

}