#include "mylib.h"
#include "Funkcijos.h"

double vid_med (char tikrinimas, vector <int> &laik, int paz_sk, int egzaminas)
{
  double vid;
  if (tolower(tikrinimas) == 'v') {
    if (paz_sk == 0) vid = 0;
    else vid = accumulate(laik.begin(),laik.end(),0.0)/double(paz_sk);
  }
  else
  {
    if (paz_sk == 0)
    {
      vid = 0;
    }
    else{
      sort(laik.begin(), laik.end());
      if (paz_sk % 2 == 0)
      {
          vid = double(laik[(paz_sk-1)/2]+laik[paz_sk/2])/2.0;
      }
      else
      {
          vid = double(laik[paz_sk/2]);
      }
    }

  }
  return vid * 0.4 + double(egzaminas) * 0.6;
}

void Nuskaitymas(vector <duom> &func, int &kiek, string pavadinimas, char tikrinimas)
{
    try
    {
      ifstream df;
      df.open(pavadinimas);
      string eil;
      string header;
      if (df.is_open())
      {
        int sk, nd;
        getline(df >> ws, header);
        stringstream stream(header);
        sk = (distance(istream_iterator<string>(stream), istream_iterator<string>())) - 3;
        while (getline(df >> ws, eil))
        {
            duom naujas;
            stringstream stream(eil);
            naujas.paz_sk = sk;
            stream >> naujas.vardas>>naujas.pavarde;
            for(int i=0;i<sk;i++){
                stream >> nd;
                naujas.pazymiai.push_back(nd);
            }
            stream >> naujas.egzaminas;
            naujas.galutinis = vid_med(tikrinimas,naujas.pazymiai,naujas.paz_sk,naujas.egzaminas);
            func.push_back(naujas);
        }
      }
      else throw std::runtime_error(pavadinimas);
      kiek = func.size();
      df.close();
    }
    catch(const exception& e){
     cout << "Failo nuskaityti nepavyko: " <<e.what()<< endl;
  }
}

void Nuskaitymas(list <duom> &func, int &kiek, string pavadinimas, char tikrinimas)
{
    try
    {
      ifstream df;
      df.open(pavadinimas);
      string eil;
      string header;
      if (df.is_open())
      {
        int sk, nd;
        getline(df >> ws, header);
        stringstream stream(header);
        sk = (distance(istream_iterator<string>(stream), istream_iterator<string>())) - 3;
        while (getline(df >> ws, eil))
        {
            duom naujas;
            stringstream stream(eil);
            naujas.paz_sk = sk;
            stream >> naujas.vardas>>naujas.pavarde;
            for(int i=0;i<sk;i++){
                stream >> nd;
                naujas.pazymiai.push_back(nd);
            }
            stream >> naujas.egzaminas;
            naujas.galutinis = vid_med(tikrinimas,naujas.pazymiai,naujas.paz_sk,naujas.egzaminas);
            func.push_back(naujas);
        }
      }
      else throw std::runtime_error(pavadinimas);
      kiek = func.size();
      df.close();
    }
    catch(const exception& e){
     cout << "Failo nuskaityti nepavyko: " <<e.what()<< endl;
  }
}

void Isvedimas(vector <duom> stud, int kiek, string pavadinimas_isv ,char tikrinimas) {
  ofstream rf;
  rf.open(pavadinimas_isv);
  rf<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(18)<<left<<"Galutinis balas"<<endl;
  for (int i=0; i<kiek;i++)
  {
      rf<<setw(20)<<left<<stud.at(i).vardas<<setw(20)<<left<<stud.at(i).pavarde<<fixed<<setprecision(2)<<setw(18)<<left<<stud.at(i).galutinis<<endl;
  }
  rf.close();
}

void Isvedimas(list <duom> func, int kiek, string pavadinimas_isv ,char tikrinimas) {
  ofstream rf;
  rf.open(pavadinimas_isv);
  rf<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(18)<<left<<"Galutinis balas"<<endl;
  for(const auto& naujas:func)
  {
      rf<<setw(20)<<left<<naujas.vardas<<setw(20)<<left<<naujas.pavarde<<fixed<<setprecision(2)<<setw(18)<<left<<naujas.galutinis<<endl;
  }
  rf.close();
}

void Generavimas(int dydis, string pavadinimas){
    stringstream buff;
    ofstream gf;
    gf.open(pavadinimas);
    int ndsk = rand() % 10 + 1;
    buff<<setw(20)<<left<<"Vardas"<<setw(20)<<"Pavarde";
    for(int i=0;i<ndsk;i++)buff<<setw(20)<<"ND" + to_string(i+1);
    buff<<setw(20)<<"Egz."<<"\n";
    for(int i=0;i<dydis;i++){
        buff<<setw(20)<<left<<"Vardas" + to_string(i+1)<<setw(20)<<"Pavarde" + to_string(i+1);
        for(int j=0;j<ndsk;j++){
            buff<<setw(20)<<(rand() % 10 + 1);
        }
        buff<<setw(20)<<(rand() % 10 + 1)<<"\n";
    }
    gf << buff.str();
    buff.clear();
    gf.close();
}

void Skirstymas(vector <duom> &func, vector <duom> &vargsiukai, vector <duom> &galvociai){
    for(auto &naujas:func){
        if(naujas.galutinis < 5.00) vargsiukai.push_back(naujas);
        else galvociai.push_back(naujas);
    }
}

void Skirstymas(list <duom> &func, list <duom> &vargsiukai, list <duom> &galvociai){
    for(auto &naujas:func){
        if(naujas.galutinis < 5.00) vargsiukai.push_back(naujas);
        else galvociai.push_back(naujas);
    }
}

bool Palyginimas(duom pirmas, duom antras)
{
    if (pirmas.galutinis != antras.galutinis)
        return pirmas.galutinis < antras.galutinis;
    return pirmas.vardas < antras.vardas;
}
