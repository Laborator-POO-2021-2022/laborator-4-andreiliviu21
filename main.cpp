#include "Sticla.hpp"

int main() {
    Sticla *s;
    s = new Sticla[3];
    for (int i = 0; i < 3; i++) {
        std::cout<< "\nPentru sticla cu nr " << i << ", introdu te rog datele:\n";
        cin >> s[i];
    }

    
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 4; j++) {
            if( s[i].getPret() >= s[j].getPret() ) {
                s[i].interschimbare2(s[j]);

            } 
        }
    }

    for (int i = 0; i < 3; i++) {
        std::cout<< "\nPentru sticla cu nr " << i << ", datele sunt:\n";
        cout << s[i];
    }

    cout << "\nProduse cu diam > 5\n"; 
    for (int i = 0; i < 3; i++) {
        if (s[i].getDiametru() > 5) {
            
            cout << s[i];
        }
    }
    
    return 0;
}