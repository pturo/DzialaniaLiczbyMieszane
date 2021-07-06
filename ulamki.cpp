#include <iostream>

struct mieszane {
    int całkowita;
    int licznik;
    int mianownik;
};

int NWD(int a, int b) {
    int pom;
    while(b!=0)
    {
        pom=b;
        b=a%b;
        a=pom;
    }
    return a;
}

int NWW(int a, int b)
{
    return (a*b)/NWD(a,b);
}

void Dodaj() {
    mieszane m;
    int sc1, sl1, sm1 = 0;
    int sc2, sl2, sm2 = 0;
    int calkowita, licznik, mianownik = 0;
    std::cout << "(Skladnik 1) - Podaj liczbe calkowita, licznik i mianownik (np. 3 1/2 rozdzielone spacjami)" << std::endl;
    std::cin >> m.całkowita;
    sc1 = m.całkowita;
    std::cin >> m.licznik;
    sl1 = m.licznik;
    std::cin >> m.mianownik;
    sm1 = m.mianownik;
    std::cout << "(Skladnik 2) - Podaj liczbe calkowita, licznik i mianownik (np. 3 1/2 rozdzielone spacjami)" << std::endl;
    std::cin >> m.całkowita;
    sc2 = m.całkowita;
    std::cin >> m.licznik;
    sl2 = m.licznik;
    std::cin >> m.mianownik;
    sm2 = m.mianownik;

    // Oblicz sumę uwzględniając później wyciągnięcie całości, jeśli licznik > mianownik.
    // Jeśli licznik = mianownik -> wyciągnij całość i ustaw licznik, mianownik na 0.
    calkowita = sc1 + sc2;
    licznik = sl1 + sl2;
    if(sm1 == sm2){
        mianownik = sm1;
        if(licznik == mianownik) {
            calkowita += 1;
            licznik = 0;
            mianownik = 0;
        }
    } else if (sm1 != sm2) {
        // Oblicz najmiejszą wspólną wielokrotność dla mianownika
        int tempMianownik = NWW(sm1, sm2);
        int tmpLicznik1 = (tempMianownik/sm1) * sl1;
        int tmpLicznik2 = (tempMianownik/sm2) * sl2;
        licznik = tmpLicznik1 + tmpLicznik2;
        mianownik = tempMianownik;
        if(licznik == mianownik) {
            calkowita += 1;
            licznik = 0;
            mianownik = 0;
        } else if (licznik > mianownik) {
            int tmpLicznikNiewl = (calkowita * mianownik) + licznik;
            int tmpNowyLicznik = tmpLicznikNiewl % mianownik;
            calkowita += 1;
            licznik = tmpNowyLicznik;
            mianownik = mianownik;
        }
    }
    std::cout << "Suma: " << calkowita << " i " << licznik << "/" << mianownik << std::endl;
}

void Odejmij() {
    mieszane m;
    int sc1, sl1, sm1 = 0;
    int sc2, sl2, sm2 = 0;
    int calkowita, licznik, mianownik = 0;
    std::cout << "(Odjemna) - Podaj liczbe calkowita, licznik i mianownik (np. 3 1/2 rozdzielone spacjami)" << std::endl;
    std::cin >> m.całkowita;
    sc1 = m.całkowita;
    std::cin >> m.licznik;
    sl1 = m.licznik;
    std::cin >> m.mianownik;
    sm1 = m.mianownik;
    std::cout << "(Odjemnik) - Podaj liczbe calkowita, licznik i mianownik (np. 3 1/2 rozdzielone spacjami)" << std::endl;
    std::cin >> m.całkowita;
    sc2 = m.całkowita;
    std::cin >> m.licznik;
    sl2 = m.licznik;
    std::cin >> m.mianownik;
    sm2 = m.mianownik;

    // Oblicz różnicę, wpierw zamieniając wszystko na ułamki niewłaściwe, następnie
    // rozszerz mianowniki, następnie odejmij i wyciągnij całości.
    int tmpNiewLicznik1 = ((sc1 * sm1) + sl1);
    int tmpNiewLicznik2 = ((sc2 * sm2) + sl2);
    std::cout << "tmpNiewLicznik1: " << tmpNiewLicznik1 << std::endl;
    std::cout << "tmpNiewLicznik2: " << tmpNiewLicznik2 << std::endl;

    if(sm1 == sm2) {
        mianownik = sm1;
    } else if (sm1 != sm2) {
        // Oblicz najmniejszą wspólną wielokrotność dla mianownika
        int tempMianownik = NWW(sm1, sm2);
        int tmpLicznik1 = tmpNiewLicznik1 * sm2;
        int tmpLicznik2 = tmpNiewLicznik2 * sm1;
        std::cout << "tmpLicznik1: " << tmpLicznik1 << std::endl;
        std::cout << "tmpLicznik2: " << tmpLicznik2 << std::endl;
        mianownik = tempMianownik;
        licznik = tmpLicznik1 - tmpLicznik2;
        std::cout << "licznik: " << licznik << std::endl;
    }
    std::cout << "Różnica: " << calkowita << " i " << licznik << "/" << mianownik << std::endl;
}

int main() {
    int test;

    do {
        std::cout << "Jakie dzialanie chcesz wykonac?" << std::endl;
        std::cout << "1. Dodawanie " << std::endl;
        std::cout << "2. Odejmowanie " << std::endl;
        std::cout << "3. Zakończenie programu " << std::endl;

        std::cin >> test;

        switch (test) {
            case 1: Dodaj();
              break;
            case 2: Odejmij();
              break;
        }
    } while (test != 3);
    return 0;
}