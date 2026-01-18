//Driver Algoritmi di Ordinamento (InsertionSort e MergeSort)
#include <cstdlib>
#include <ctime>
#include <iostream>

void InsertionSort(int v[], int n)
{
  int i, j, x;
  
  for(i = 1; i < n; i++)
    {
      x = v[i];
      j = i-1;
      while(j >= 0 && v[j] > x)
        {
          v[j+1] = v[j];
          j--;
        }
      v[j+1] = x;
    }
}

void Merge(int v[], int sx, int md, int dx)
{
   int i = sx, j = md+1, k = 0;
   int* b = new int[dx-sx+1];
   
   while((i <= md) && (j <= dx))
     {
       if(v[i] <= v[j])
         {
           b[k] = v[i];
           i++;
         }
       else
         {
           b[k] = v[j];
           j++;
         }
       k++;
     }   
   while(i <= md)
     {
       b[k] = v[i];
       i++;
       k++;
     }
   while(j <= dx)
     {
       b[k] = v[j];
       j++;
       k++;
     }
   for(k = sx; k <= dx; k++)
     v[k] = b[k-sx];
   delete[] b;
}

void MergeSort(int v[], int sx, int dx)
{
   int md; 

   if (sx == dx)
     return;
   if(sx < dx)
     md = (sx+dx)/2;
   MergeSort(v, sx, md);
   MergeSort(v, md+1, dx);
   Merge(v, sx, md, dx);
}

int main(int argc, char* argv[])
{
  int i; 
  int dim = 1000;
  int* vet1 = new int[dim];
  int* vet2 = new int[dim];

  for(i = 0; i < dim; i++)
    {
      vet1[i] = rand() % 1000;
      vet2[i] = vet1[i];
    }
  cout << std::endl;

  cout << "Vettore prima: " << std::endl;
  for(i = 0; i < dim; i++)
      cout << vet1[i] << " ";
  cout << std::endl;

  cout << "Insertion Sort: " << std::endl;
  InsertionSort(vet1, dim);
 
  for(i = 0; i < dim; i++)
    cout << vet1[i] << " ";
  cout << std::endl;

  cout << "Merge Sort: " << std::endl;
  MergeSort(vet2, 0, dim-1);

  for(i = 0; i < dim; i++)
    cout << vet2[i] << " ";
  cout << std::endl;
  
  return 0;
}
