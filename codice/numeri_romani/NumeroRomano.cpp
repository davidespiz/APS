//TraduciNumeroRomano.cpp
#include <iostream>
#define MAX_BUFFER 250

unsigned TraduciNumeroRomano(char s[]);
unsigned TraduciCifra1(char ch);
unsigned TraduciCifra2(char s[], unsigned i);

int main()
{
  char s[MAX_BUFFER];
  printf("Inserisci un numero: ");
  scanf("%s",s);
  
  printf("Il numero e' : %d\n", TraduciNumeroRomano(s));
}

unsigned TraduciNumeroRomano(char s[])
{
  int k, num = 0, max_val = 0; 
  
  for(int i=strlen(s); i>=0; i--)
    {
      k = TraduciCifra1(s[i]);
      // oppure k = TraduciCifra2(s, i);
      if(k >= max_val)
        {
          max_val = k;
          num += k;
        }
      else
        num -= k; 
    }
  return num;
}

unsigned TraduciCifra1(char ch)
{
  if(ch == 'M')
    return 1000;
  else if(ch == 'D')
    return 500;
  else if(ch == 'C')
    return 100;
  else if(ch == 'L')
    return 50;
  else if(ch == 'X')
    return 10;
  else if(ch == 'V')
    return 5;
  else if(ch == 'I')
    return 1;
  else
    return 0;    
}

unsigned TraduciCifra2(char s[], unsigned i)
{
  if(s[i] == 'M')
    return 1000;
  else if(s[i] == 'D')
    return 500;
  else if(s[i] == 'C')
    return 100;
  else if(s[i] == 'L')
    return 50;
  else if(s[i] == 'X')
    return 10;
  else if(s[i] == 'V')
    return 5;
  else if(s[i] == 'I')
    return 1;
  else
    return 0;    
}
