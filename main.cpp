#include <iostream>
#include <cctype>
#include <string.h>

using namespace std;

class Zboruri{
public:
    string locul_plecarii;
    string locul_sosirii;
    string aeroport_plecare;
    string aeroport_sosire;
    int anul;
    int luna;
    int ziua;
    int ora;
    int minutul;
    int durata_zborului;
    int locuri_disponibile;


    void getLoc_plecare()
    {
        cin>>locul_plecarii;
    }
    void getLoc_sosire()
    {
        cin>>locul_sosirii;
    }
    void getAeroport_plecare()
    {
        cin>>aeroport_plecare;
    }
    void getAeroport_sosire()
    {
        cin>>aeroport_sosire;
    }
    void getAn()
    {
        cin>>anul;
    }
    void getLuna()
    {
        cin>>luna;
    }
    void getZiua()
    {
        cin>>ziua;
    }
    void getOra()
    {
        cin>>ora;
    }
    void getMinutul()
    {
        cin>>minutul;
    }
    void getDurata_zborului(){

        cin>>durata_zborului;
    }

    void getLocuri_disponibile()
    {
        cin>>locuri_disponibile;
    }
    void displayInfo()
    {
        cout << "Numele tarii de unde pleaca avionul: " << locul_plecarii << "\n";
        cout << "Numele aeroportului de unde pleaca avionul: " << aeroport_plecare << "\n";
        cout << "Numele tarii unde ajunge avionul: " << locul_sosirii << "\n";
        cout << "Numele aeroportului unde ajunge avionul: " << aeroport_sosire << "\n";
        cout << "Anul plecarii avionului: " << anul  << "\n";
        cout << "Luna plecarii avionului: " << luna << "\n";
        cout << "Ziua plecarii avionului: " << ziua << "\n";
        cout << "Ora plecarii avionului: " << ora << "\n";
        cout << "Minutul plecarii avionului: " << minutul << "\n";
        cout << "Durata zborului este: " << durata_zborului << "\n";
        cout << "Numarul de locuri disponibile este: " << locuri_disponibile << "\n";
    }

};
class Operator : public Zboruri{
public:
    string username;
    string password;

    Operator(string username, string password);


     int Adaugare_zbor(int numar_zboruri, Zboruri zbor[]) {

        for (int i = 0; i < numar_zboruri; i++) {
            cout << "Zborul " << i + 1 << "\n";

            cout << "Introduceti tara de unde pleaca avionul"<< "\n";
            zbor[i].getLoc_plecare();
            if (zbor[i].locul_plecarii <"A" || zbor[i].locul_plecarii >"z" )
                throw "Tara contine litere necunoscute, incercati sa introduceti o tara valida \n";

            cout << "Introduceti aeroportul de unde pleaca avionul"<< "\n";
            zbor[i].getAeroport_plecare();
            if (zbor[i].aeroport_plecare <"A" || zbor[i].aeroport_plecare >"z" )
                throw "Aeroportul contine litere necunoscute, incercati sa introduceti un aeroport valid \n";

            cout << "Introduceti tara unde ajunge avionul"<< "\n";
            zbor[i].getLoc_sosire();
            if (zbor[i].locul_sosirii <"A" || zbor[i].locul_sosirii >"z" )
                throw "Tara contine litere necunoscute, incercati sa introduceti o tara valida \n";

            cout << "Introduceti aeroportul unde ajunge avionul"<< "\n";
            zbor[i].getAeroport_sosire();
            if (zbor[i].aeroport_sosire <"A" || zbor[i].aeroport_sosire >"z" )
                throw "Aeroportul contine litere necunoscute, incercati sa introduceti un aeroport valid\n";

            cout << "Introduceti anul plecarii"<< "\n";
            zbor[i].getAn();
            if (zbor[i].anul <= 2019 || zbor[i].anul > 2022  )
                throw "Anul introdus nu este corect, acesta este din trecut sau nu este disponibil momentan \n";

            cout << "Introduceti luna plecarii"<< "\n";
            zbor[i].getLuna();
            if (zbor[i].anul == 2020 && zbor[i].luna < 12)
                throw "Data zborului este din trecut \n";
            else if (zbor[i].luna < 1 || zbor[i].luna > 12  )
                throw "Luna introdusa este invalida, incercati sa introduceti o luna intre 1 si 12\n";

            cout << "Introduceti ziua plecarii"<< "\n";
            zbor[i].getZiua();
            if (zbor[i].luna == 2 && zbor[i].ziua >28)
                throw "Luna februarie nu are mai mult de 28 de zile in anul selectat \n";
            else if (zbor[i].ziua <1  || zbor[i].ziua > 31 )
                  throw "Ziua introdusa nu este valida \n";

            cout << "Introduceti ora plecarii"<< "\n";
            zbor[i].getOra();
            if (zbor[i].ora < 0 || zbor[i].ora > 24  )
                throw "Ora introdusa este incorecta, aceasta poate fi intre 0 si 24 \n";

            cout << "Introduceti minutul plecarii"<< "\n";
            zbor[i].getMinutul();
            if (zbor[i].minutul < 0 || zbor[i].luna > 59  )
                throw "Minutul introdus nu este valid, accesta poate fi intre 0 si 59\n";

            cout << "Introduceti durata zborului"<< "\n";
            zbor[i].getDurata_zborului();
            if (zbor[i].durata_zborului > 8 )
                throw "Nu exista durata respectiva ca nu mergem cu CFR :) \n";

            cout << "Introduceti numarul de locuri disponibile"<< "\n";
            zbor[i].getLocuri_disponibile();
            if (zbor[i].locuri_disponibile > 400 )
                throw "Numarul de locuri este prea mare, incercati sa introduceti un numar mai mic\n";



        }
         return 1;
    }

    void Afisare_zboruri(int numar_zboruri, Zboruri zbor[]){
        for( int i=0; i<numar_zboruri; i++ )
        {
            cout << "Zborul " << i + 1 << "\n";
            zbor[i].displayInfo();
        }

    }
    int Stergere_zbor(Zboruri zbor[], int numar_zboruri){

        int pozitia_de_la_care_trebuie_sters;

      cout<<"Zborul pe care vrei sa il stergi: \n";
      cin>>pozitia_de_la_care_trebuie_sters;

      for (int i = 0; i < numar_zboruri; i++) {
          if(i == pozitia_de_la_care_trebuie_sters - 1) {

              for (int j = i; j < numar_zboruri - 1; j++)
                  zbor[j] = zbor[j + 1];
              break;
          }


        }
        return numar_zboruri - 1;


    }


};
int Logare(Operator operatorul,string username, string password){

    int contor_logare = 0;
    if (username ==operatorul.username && password == operatorul.password) contor_logare =1;
    if(contor_logare == 1)
        return 1;
     throw "Numele de utilizator sau parola au fost introduse gresit! \n" ;


}

Operator::Operator(string username, string password) {
    this->username = username;
    this->password = password;
}

class Utilizator : public Zboruri{
public:

    string nume_utilizator;
    string parola;


    void getNume_utilizator()
    {
        cin>>nume_utilizator;
    }
    void getParola()
    {
        cin>>parola;
    }
    int Cautare_zbor(int numar_zboruri, Zboruri zbor[]){

        string modalitate, oras_plecare, oras_sosire, aeroport_plecare_avion, aeroport_sosire_avion;
        int contor = 0;
        cout<<"Introduceti cifra ce reprezinta criteriul dupa care se realizeaza cautarea \n";
        cout<<"1.Dupa locatia de unde pleaca si destinatia avionului\n";
        cout<<"2.Dupa aeroportul de unde pleaca avionul si aeroportul unde soseste \n";
        cin>>modalitate;
        if (modalitate == "1"){
            cout<<"Tara de unde pleaca avionul:";
            cin>>oras_plecare;
            cout<<"Tara unde soseste avionul:";
            cin>>oras_sosire;
        for( int i=0; i<numar_zboruri; i++ )
        {
           if(zbor[i].locul_plecarii == oras_plecare && zbor[i].locul_sosirii == oras_sosire ) {
               cout << "Zborul cautat este zborul " << i + 1 << "\n";
               zbor[i].displayInfo();
               contor = 1;
           }
        }
        }
        if(modalitate == "2"){

            cout<<"Aeroportul de unde pleaca avionul:";
            cin>>aeroport_plecare_avion;
            cout<<"Aeroportul unde soseste avionul:";
            cin>>aeroport_sosire_avion;
            for( int i=0; i<numar_zboruri; i++ )
            {
                if(zbor[i].aeroport_plecare == aeroport_plecare_avion && zbor[i].aeroport_sosire == aeroport_sosire_avion ) {
                    cout << "Zborul cautat este zborul " << i + 1 << "\n";
                    zbor[i].displayInfo();
                    contor = 1;
                }
            }


        }
        if(contor == 1)
            return 1;
        throw "Zbor inexistent\n";

    }
    int Rezervare_zbor(int numar_zboruri, Zboruri zbor[]){

        int numarul_zborului, numar_locuri, contor = 0;
        cout<<"Introduceti numarul zborului pe care vreti sa il rezervati \n";
        cin>>numarul_zborului;
        cout<<"Introduceti numarul de locuri pe care vreti sa le rezervati \n";
        cin>>numar_locuri;
        for( int i=0; i<numar_zboruri; i++ )
        {
            if((i+1) == numarul_zborului) {
                zbor[i].locuri_disponibile = zbor[i].locuri_disponibile - numar_locuri;
                zbor[i].displayInfo();
                contor = 1;
            }
        }
        if(contor == 1)
            return 1;
        throw "Detaliile rezervarii au fost introduse gresit\n";

    }


};

   int Creare_cont(Utilizator &utilizator){


           cout<<"Introduceti numele de utilizator pe care doriti sa il aveti:\n";
           utilizator.getNume_utilizator();
           if (utilizator.nume_utilizator.length() < 5)
               throw "Numele de utilizator este unul prea comun \n";

           cout<<"Introduceti parola pe care doriti sa o aveti:\n";
           utilizator.getParola();
           int n = utilizator.parola.length();
           int contor = 0;
          bool hasLower = false, hasUpper = false;
          bool hasDigit = false, specialChar = false;


       for (int i = 0; i < n ; i++) {

           if (islower(utilizator.parola[i]))
               hasLower = true;
           if (isupper(utilizator.parola[i]))
               hasUpper = true;
           if (isdigit(utilizator.parola[i]))
               hasDigit = true;
           if (!isalpha(utilizator.parola[i]) && !isdigit(utilizator.parola[i]))
               specialChar = true;

       }
       if (hasLower == true && hasUpper == true && hasDigit == true && specialChar == true && n >= 8) {
           cout << "Introducere reusita \n";
           contor = 1;



       }
       if(contor == 1)
          return 1;
       throw "Parola este prea slaba, incercati o parola mai solida\n";

   }

int Autentificare(Utilizator utilizator,string username, string password){

       int contor_autentificare = 0;
    if (username == utilizator.nume_utilizator && password.compare(utilizator.parola) == 0) contor_autentificare = 1;
        if(contor_autentificare == 1)
            return 1;
    throw "Numele de utilizator sau parola nu corespund\n";


}



int main(){

    int numar_zboruri;
    string utilizator, operator_name, parola_operator, username, user_password, optiune1, optiune2;

    cout<<"Introduceti numarul de zboruri cu care vreti sa lucrati: "<<"\n";
    cin>>numar_zboruri;

    Zboruri zbor[numar_zboruri];

    //Operatorii
    Operator operator1("Maluma","Natalia");

    Utilizator utilizator1;

   int semafor_mare = 0;
   while (semafor_mare == 0) {
       cout << "------->Meniu alegere utilizator<------- \n";
       cout << "Introduceti ce fel de utilizator sunteti(Operator/Utilizator) sau Iesire : \n";
       cout << "1.Operator \n";
       cout << "2.Utilizator \n";
       cout << "3.Iesire \n";
       cin >> utilizator;

       if (utilizator == "Operator") {

           int semafor_mic = 0;
           while (semafor_mic == 0) {
               cout << "Introduceti datele de logare \n";
               cout << "Numele operatorului este: ";
               cin >> operator_name;
               cout << "Parola operatorului este: ";
               cin >> parola_operator;


               try {
                   if (Logare(operator1, operator_name, parola_operator) == 1 ) {

                       cout << "Logare reusita!\n";
                       semafor_mic = 1;
                   }

               }

               catch (const char *msg) {
                   cout << msg;
                   cout << "Introduceti datele de logare \n";
                   cout << "Numele operatorului este: ";
                   cin >> operator_name;
                   cout << "Parola operatorului este: ";
                   cin >> parola_operator;

               }
           }

           int variabila_semafor = 0;
           int operator_stocare = 0;
           while (variabila_semafor == 0) {

               cout << "------->Meniu alegere operatiune<------- \n";
               cout << "Selelectati cifra corespunzatoare optiunii pe care vreti sa o executati : \n";
               cout << "1.Adaugare zbor \n";
               cout << "2.Stergere zbor \n";
               cout << "3.Inapoi \n";
               cin >> optiune1;
               if (optiune1 == "1") {
                   try {
                       operator_stocare = operator1.Adaugare_zbor(numar_zboruri, zbor);
                       if (operator_stocare == 1) {
                           cout << "Zbor adaugat cu succes \n";
                           operator1.Afisare_zboruri(numar_zboruri, zbor);
                       }
                   }

                   catch (const char *msg) {
                       cout << msg;
                   }


               }
               if (optiune1 == "2") {
                   operator1.Stergere_zbor(zbor, numar_zboruri);
                   operator1.Afisare_zboruri(numar_zboruri, zbor);

               }
               if (optiune1 == "3") variabila_semafor = 1;
           }
       }

       int variabila_semafor1 = 0;
       int utilizator_stocare = 0;
       int utilizator_stocare_1 = 0;
       int utilizator_stocare_2 = 0;

       string utilizator_name, parola_utilizator;
       if (utilizator == "Utilizator") {
           while (variabila_semafor1 == 0) {

               cout << "------->Meniu utilizator nou<------- \n";
               cout << "Selelectati cifra corespunzatoare optiunii pe care vreti sa o executati : \n";
               cout << "1.Creare cont \n";
               cout << "2.Autentificare \n";
               cout << "3.Inapoi \n";
               cin >> optiune2;
               if (optiune2 == "1") {
                   try {
                       utilizator_stocare = Creare_cont(utilizator1);
                       if (utilizator_stocare == 1)
                           cout << "Utilizator adaugat cu succes \n";

                   }
                   catch (const char *msg) {
                       cout << msg;
                   }

               }
               if (optiune2 == "2") {

                   int semafor_mic_autentificare = 0;

                   while (semafor_mic_autentificare == 0) {

                   cout << "Introduceti datele de logare \n";
                   cout << "Numele utilizatorului este: ";
                   cin >> utilizator_name;
                   cout << "Parola utilizatorului este: ";
                   cin >> parola_utilizator;
                   try {

                       if (Autentificare(utilizator1, utilizator_name, parola_utilizator) == 1) {

                           string optiune3;
                           cout << "Autentificare reusita \n";
                           cout << "--->Meniu utilizator<--- \n";
                           cout <<"Introduceti cifra corespunzatoare actiunii pe care doriti sa o executati! \n";
                           cout << "1.Cautare zbor \n";
                           cout << "2.Rezervare zbor \n";
                           cout << "3.Inapoi \n";
                           cin >>optiune3;
                           if (optiune3 == "1"){
                               try {
                                   utilizator_stocare_1 = utilizator1.Cautare_zbor(numar_zboruri, zbor);
                                   if (utilizator_stocare_1 == 1)
                                       cout << "Zborul a fost afisat \n";

                               }
                               catch (const char *msg) {
                                   cout << msg;
                               }
                           }
                           if (optiune3 == "2"){
                               try {
                                   utilizator_stocare_2 = utilizator1.Rezervare_zbor(numar_zboruri, zbor);
                                   if (utilizator_stocare_2 == 1)
                                       cout << "Locurile dumneavoastra au fost rezervate \n";

                               }
                               catch (const char *msg) {
                                   cout << msg;
                               }

                           }
                           if (optiune3 == "3") semafor_mic_autentificare = 1;
                       }
                   }
                   catch (const char *msg) {
                       cout << msg;
                       cout << "Introduceti datele de logare \n";
                       cout << "Numele utilizatorului este: ";
                       cin >> utilizator_name;
                       cout << "Parola utilizatorului este: ";
                       cin >> parola_utilizator;
                   }

               }
           }

               if (optiune2 == "3") variabila_semafor1 = 1;
           }

       }

       if (utilizator == "Iesire") semafor_mare = 1;

   }




}