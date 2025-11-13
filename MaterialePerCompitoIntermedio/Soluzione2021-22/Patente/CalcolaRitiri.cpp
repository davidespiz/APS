#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> CalcolaRitiri(string nome_file, int punti_iniziali);
bool Membro(string s, vector<string>& v);

int main(int argc, char* argv[])
{
  vector<string> v = CalcolaRitiri(argv[1], atoi(argv[2]));
  for (unsigned i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  return 0;
}

// si suppone che non si possano togliere più punti di quelli iniziali

vector<string> CalcolaRitiri(string nome_file, int punti_iniziali)
{
  vector<string> ritiri;
  vector<pair<string,int>> vettore_punti;
  ifstream is(nome_file);
  string nome;
  int punti;
  bool trovato;

  while (is >> nome >> punti)
  {
	 if (Membro(nome,ritiri))
		 continue;
	 trovato = false;
     for (unsigned i = 0; i < vettore_punti.size(); i++)
        if (vettore_punti[i].first == nome)
          {
			trovato = true;
            vettore_punti[i].second += punti;
			if (vettore_punti[i].second < 0)
				ritiri.push_back(nome);           
            break;
          }
      if (!trovato)
        vettore_punti.push_back(make_pair(nome,punti_iniziali + punti));
  }
  return ritiri;
}

bool Membro(string s, vector<string>& v)
{
	for (unsigned i = 0; i < v.size(); i++)
		if (s == v[i])
			return true;
	return false;
}
