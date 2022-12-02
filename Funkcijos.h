#ifndef STRUC_H_INCLUDED
#define STRUC_H_INCLUDED
#include "mylib.h"

struct duom {
  string vardas;
  string pavarde;
  int paz_sk;
  vector <int> pazymiai;
  int egzaminas;
  double galutinis;
};

double vid_med (char tikrinimas, vector <int> &laik, int paz_sk, int egzaminas);
void Nuskaitymas(vector <duom> &func, int &kiek, string pavadinimas, char tikrinimas);
void Nuskaitymas(list <duom> &func, int &kiek, string pavadinimas, char tikrinimas);
void Isvedimas(vector <duom> stud, int kiek, string pavadinimas_isv ,char tikrinimas);
void Isvedimas(list <duom> stud, int kiek, string pavadinimas_isv ,char tikrinimas);
void Generavimas(int dydis, string pavadinimas);
void Skirstymas(vector <duom> &func, vector <duom> &vargsiukai, vector <duom> &galvociai);
void Skirstymas(list <duom> &func, list <duom> &vargsiukai, list <duom> &galvociai);
bool Palyginimas(duom pirmas, duom antras);
#endif // STRUC_H_INCLUDED
