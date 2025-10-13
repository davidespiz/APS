#include <iostream>

using namespace std;

const int DIM_VET = 6;
const int NUM_RIGHE = 2;
const int NUM_COL = 3;

int NumeroDistintiVettore(int v[], int n);
int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col);
bool contiene(int v[], int n);

int main()
{
  int vett[DIM_VET];
  int mat[NUM_RIGHE][NUM_COL];
  int i, j;

  cout << "Inserisci un vettore di " << DIM_VET << " valori interi : ";
  for (i = 0; i < DIM_VET; i++)
    cin >> vett[i];
  cout << "Il numero di elementi distinti del vettore e' " 
       << NumeroDistintiVettore(vett,DIM_VET) << endl; 

  cout << "Inserisci una matrice di " << NUM_RIGHE 
       << " righe e " << NUM_COL << " colonne" << endl;
  for (i = 0; i < NUM_RIGHE; i++)
    for (j = 0; j < NUM_COL; j++)
      cin >> mat[i][j];

  cout << "Il numero di elementi distinti della matrice e' " 
       << NumeroDistintiMatrice(mat,NUM_RIGHE,NUM_COL) << endl; 
}

int NumeroDistintiVettore(int v[], int n)
{
  int buf[n];
  buf[0] = v[0];
  int tot = 1;

  for(int i = 1; i < n; i++)
    if(contiene(buf, v[i]) == false)
      buf[tot++] = v[i];
  return tot;
}

bool contiene(int v[], int n)
{
  for(int i = 0; i < n; i++)
    if(v[i] == n) 
      return true;
  return false;
}

int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col)
{
  int buf[righe + col];
  buf[0] = m[0][0];
  int tot = 1;

  for(int i = 0; r < righe + col; i++)
    if(contiene(buf, m[r][c]) == false)
        buf[tot++] = m[r][c];
  return tot;
}