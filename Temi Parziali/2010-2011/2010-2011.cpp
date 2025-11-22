bool StessoImpegno(Impegno v[], int n, string nome_file);

bool StessoImpegno(Impegno v[], int n, string nome_file)
{
   ifstream is(nome_file);
   Data d1, d2;
   char ch;

   is >> d1 >> ch >> d2;
   is.close();

   for(int i = 0; i < n; i++)
   {
      if(v.Inizio() <= d1 && d1 <= v.Fine() && v.Inizio() <= d1 && v.Fine() <= d2)
         return true;
   }
   return false;
}