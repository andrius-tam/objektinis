#include "mylib.h"
#include "Funkcijos.h"

int main()
{
    srand(time(NULL));
    int kiek=0;
    vector <duom> stud;
    list <duom> stud_list;
    char tikrinimas;
    cout<<"Jei norite studento galutini bala skaiciuoti naudojant mediana iveskite \"m\", o jei norite galutini bala skaiciuoti naudojant vidurki iveskite \"v\"\n";cin>>tikrinimas;
    while (tolower(tikrinimas) != 'v' && tolower(tikrinimas) != 'm') {
    cout<<"Turite ivesti \"v\" arba \"m\"!"<<endl;
    cin>>tikrinimas;
  }
    int dydis = 1000;
    /*while(dydis <= 10000000){
        string pavadinimas = "studentai" + to_string(dydis) + ".txt";
        auto start1 = std::chrono::high_resolution_clock::now();
        Generavimas(dydis,pavadinimas);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        cout<<dydis<<" studentu failo generavimui prireike: "<<diff1.count()<<endl;
        dydis=dydis*10;
    }
    dydis = 1000;*/
    while(dydis <= 10000000){
        string pavadinimas = "studentai" + to_string(dydis) + ".txt";
        string varg_isv = "vargsiukai_vector" + to_string(dydis) + ".txt";
        string galv_isv = "galvociai_vector" + to_string(dydis) + ".txt";
        string varg_isv2 = "vargsiukai_vector_antras" + to_string(dydis) + ".txt";
        string galv_isv2 = "galvociai_vector_antras" + to_string(dydis) + ".txt";
        string varg_isv_list = "vargsiukai_list" + to_string(dydis) + ".txt";
        string galv_isv_list = "galvociai_list" + to_string(dydis) + ".txt";
        string galv_isv_list2 = "galvociai_list_antras" + to_string(dydis) + ".txt";
        string varg_isv_list2 = "vargsiukai_list_antras" + to_string(dydis) + ".txt";
        vector <duom> vargsiukai;
        vector <duom> galvociai;
        vector <duom> vargsiukai2;
        list <duom> vargsiukai_list;
        list <duom> galvociai_list;
        list <duom> vargsiukai_list2;
        // 1 Vektoriu strategija
        Nuskaitymas(stud,kiek,pavadinimas,tikrinimas);
        auto startv1 = std::chrono::high_resolution_clock::now();
        sort(stud.begin(), stud.end(),Palyginimas);
        Skirstymas(stud, vargsiukai, galvociai);
        auto endv1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diffv1 = endv1 - startv1;
        int varg_dyd = vargsiukai.size();
        int galv_dyd = galvociai.size();
        Isvedimas(vargsiukai, varg_dyd, varg_isv ,tikrinimas);
        Isvedimas(galvociai, galv_dyd, galv_isv, tikrinimas);
        // 1 List strategija
        Nuskaitymas(stud_list,kiek,pavadinimas,tikrinimas);
        auto startL1 = std::chrono::high_resolution_clock::now();
        stud_list.sort(Palyginimas);
        Skirstymas(stud_list,vargsiukai_list,galvociai_list);
        auto endL1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diffL1 = endL1 - startL1;
        int varg_list_dyd = vargsiukai_list.size();
        int galv_list_dyd = galvociai_list.size();
        Isvedimas(vargsiukai_list, varg_list_dyd, varg_isv_list, tikrinimas);
        Isvedimas(galvociai_list, galv_list_dyd, galv_isv_list, tikrinimas);
        // 2 Vektoriu strategija
        auto startv2 = std::chrono::high_resolution_clock::now();
        sort(stud.begin(),stud.end(),Palyginimas);
        stud.erase(remove_if(stud.begin(),stud.end(),[&vargsiukai2](duom naujas){
            if(naujas.galutinis < 5.00){
                vargsiukai2.push_back(naujas);
                return true;
                             }
            else {return false;}
                             }),stud.end());
        auto endv2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diffv2 = endv2 - startv2;
        int varg_dyd2 = vargsiukai2.size();
        int pagr_dyd = stud.size();
        Isvedimas(vargsiukai2,varg_dyd2,varg_isv2,tikrinimas);
        Isvedimas(stud,pagr_dyd,galv_isv2,tikrinimas);
        // 2 List strategija
        auto startL2 = std::chrono::high_resolution_clock::now();
        stud_list.sort(Palyginimas);
        stud_list.erase(remove_if(stud_list.begin(),stud_list.end(),[&vargsiukai_list2](duom naujas){
            if(naujas.galutinis < 5.00){
                vargsiukai_list2.push_back(naujas);
                return true;
                             }
            else {return false;}
                             }),stud_list.end());
        auto endL2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diffL2 = endL2 - endL1;
        int varg_list_dyd2 = vargsiukai_list2.size();
        Isvedimas(vargsiukai_list2,varg_list_dyd2,varg_isv_list2,tikrinimas);
        Isvedimas(stud_list,pagr_dyd,galv_isv_list2,tikrinimas);

        cout<<"\n"<<"Veiksmai su "<<dydis<<" failu: "<<endl;
        cout<<"1 Vektoriu strategija: "<<diffv1.count()<<endl;
        cout<<"1 List strategija: "<<diffL1.count()<<endl;
        cout<<"2 Vektoriu strategija: "<<diffv2.count()<<endl;
        cout<<"2 List strategija: "<<diffL2.count()<<endl;

        dydis = dydis*10;
        stud.clear();
        vargsiukai.clear();
        galvociai.clear();
        stud_list.clear();
        vargsiukai_list.clear();
        galvociai_list.clear();
        vargsiukai2.clear();
        vargsiukai_list2.clear();
    }
    return 0;
}
