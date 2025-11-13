#include <iostream>
#include <vector>
#include "Pila.hpp"

bool BenFormata(string s);
bool Aperta(char ch);
bool ParentesiOmologhe(char ch1, char ch2);

int main()
{
  string s;
  vector<string> v(5);
  unsigned i;

  v[0] = "{[[]()]}([])[]";
  v[1] = "{[}]";
  v[2] = "([])()[)";
  v[3] = "([";
  v[4] = "())";
    
  for (i = 0; i < v.size(); i++)
    if (BenFormata(v[i]))
      cout << v[i] << " e' ben formata" << endl;
    else
      cout << v[i] << " non e' ben formata" << endl;

  cout << "Inserisci una stringa: ";
  cin >> s;
  if (BenFormata(s))
    cout << s << " e' ben formata" << endl;
  else
    cout << s << " non e' ben formata" << endl;
  return 0;
}

bool BenFormata(string s)
{
  Pila p;
  unsigned i = 0;
  char ch;

  while(i < s.length())
    {
      if (Aperta(s[i]))
        p.Push(s[i]);
      else
        {
          if (p.EstVuota()) 
            return false; // chiusa senza aperta
          ch = p.Top();
          p.Pop();
          if (!ParentesiOmologhe(ch,s[i]))
            return false;
        }
      i++;
    }
  return p.EstVuota();
}

bool Aperta(char ch)
{
  return ch == '(' || ch == '[' || ch == '{';
}

bool ParentesiOmologhe(char ch1, char ch2)
{
  return (ch1 == '(' && ch2 == ')')
    || (ch1 == '[' && ch2 == ']')
    || (ch1 == '{' && ch2 == '}');
}

