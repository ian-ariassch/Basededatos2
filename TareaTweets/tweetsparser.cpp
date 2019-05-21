#include <fstream>
#include <sstream>
#include<iostream>
#include "json.hpp"
#include <set>
#include <vector>
#include <string>
#include <locale>

using json = nlohmann::json;

using namespace std;

set<string> stopwords;
vector<string> filteredwords;
map<long,string> tweets;

void filtrado()
{
  for(map<long,string>::iterator it=tweets.begin(); it!=tweets.end(); ++it)
  {
    istringstream ss((*it).second);
    string palabra;
    do {
        ss >> palabra;
        auto it = stopwords.find(palabra);
        if(it == stopwords.end())
        {
          filteredwords.push_back(palabra);
        }
    } while (ss);
  }

}

string removepunc(string cadena)
{
  for (int i = 0, len = cadena.size(); i < len; i++)
  {
      const auto& xd = use_facet<ctype<wchar_t>>(locale());
      if (ispunct(cadena[i]))
      {

          cadena.erase(i--, 1);
          len = cadena.size();
      }
  }
  return cadena;
};

int main()
{
  setlocale(LC_CTYPE, "");
  ifstream file("tweets.json");
  ifstream stopwordsF("stopwords.txt");
  json j = json::parse(file);
  string texto;
  for(int i=0; i<j.size();i++)
  {
    texto = removepunc(j[i].at("text"));
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    tweets[j[i].at("id")] = texto;
    //cout<<"id: "<<j[i].at("id")<<endl<<"text: "<<removepunc(j[i].at("text"))<<endl;
  }
  string line;
  while(stopwordsF)
  {
    stopwordsF>>line;
    stopwords.insert(line);
  }
  filtrado();

}
