#include "stanza.hpp"

void Stanza::AmmettiPaziente(Paziente* p, const Data& d)
{
   ricoverati.push_back(Ricovero(p, d));
}

void Stanza::DimettiPaziente(int index)
{
   ricoverati.erase(ricoverati.begin() + index);
}

void Stanza::IncrementaDimissione(int index, int k)
{
   ricoverati[index].dimissione += k;
}