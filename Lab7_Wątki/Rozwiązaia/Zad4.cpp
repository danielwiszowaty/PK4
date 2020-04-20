#include <iostream>
#include <map> 
#include <fstream> 
#include <string> 
#include <algorithm>
#include <cctype>
#include <vector>
#include<thread>
using namespace std;

//Wykorzystaj w¹tki i wybrany bardzo d³ugi tekst angielski wczytany z pliku  do zliczania statystyk s³ów znaków w tym interpunkcji  i ngramow.
//dla  s³ów zaimplementuj z u¿yciem w¹tków  w jednym programie  generacjê  ngramow dla s³ów i o d³ugoœci 2 do 5 wyniki programu statystyki zapisz w osobnych plikach.
//kolejny w¹tek tego samego programu  niech wytwarza  anagramy z s³ów   d³ugiego tekstu i zapisuje do pliku.
//wskazówki
//ngram i anagram to nie to samo
//https://pl.wikipedia.org/wiki/Anagram
//https://stackoverflow.com/questions/3656762/n-gram-generation-from-a-sentence

template <class KTy, class Ty>
void PrintMap(map<KTy, Ty> map,ofstream &wy)
{
    typedef std::map<KTy, Ty>::iterator iterator;
    for (iterator p = map.begin(); p != map.end(); p++)
        wy << p->first << ": " << p->second << endl;
}
template <class KTy>
void PrintVector(vector<KTy>vec,ofstream& wy)
{
    typedef std::vector<KTy>::iterator iterator;
    for (iterator p = vec.begin(); p != vec.end(); p++)
        wy << *p << endl;
}
void liczenie_slow()
{
    static const char* fileName = "RJ.txt";
    map<string, unsigned int> wordsCount;
    ifstream fileStream(fileName);
    if (fileStream.is_open())
        while (fileStream.good())
        {
            string word;
            fileStream >> word;
           
            for (int i = 0, len = word.size(); i < len; i++)
            {
               
                if (ispunct(word[i]))
                {
                    word.erase(i--, 1);
                    len = word.size();
                }
            }

            if (wordsCount.find(word) == wordsCount.end())
                wordsCount[word] = 1;
            else
                wordsCount[word]++;
        }
 
    ofstream wy("slowa.txt");
    PrintMap(wordsCount,wy);
}

void liczenie_znakow()
{
    static const char* fileName = "RJ.txt";
    map<char, unsigned int> wordsCount;
    ifstream fileStream(fileName);
    if (fileStream.is_open())
        while (fileStream.good())
        {
            string word;
            fileStream >> word;

            for (int i = 0; i < word.size(); i++)
            {
                if (wordsCount.find(word[i]) == wordsCount.end())
                    wordsCount[word[i]] = 1;
                else
                    wordsCount[word[i]]++;
            }
        }

    ofstream wy("znaki.txt");
    PrintMap(wordsCount, wy);
}

void ngramy(const int n)
{
    vector<string> vec;
    static const char* fileName = "RJ.txt";
    map<string, unsigned int> wordsCount;
    ifstream fileStream(fileName);
    if (fileStream.is_open())
    {
        string temp;
        for (int i = 0; i < n-1; i++)
        {
            fileStream >> temp;
            vec.push_back(temp);

        }
        while (fileStream.good())
        {
            
            fileStream >> temp;
            vec.push_back(temp);

            string word;

            word = vec[0];
            for (int i = 1; i < n; i++)
            {
                word += (" " + vec[i]);

            }

            for (int i = 0, len = word.size(); i < len; i++)
            {

                if (ispunct(word[i]))
                {
                    word.erase(i--, 1);
                    len = word.size();
                }
            }

            if (wordsCount.find(word) == wordsCount.end())
                wordsCount[word] = 1;
            else
                wordsCount[word]++;
            vec.erase(vec.begin());
        }
    }
    string nazwa;
    nazwa = to_string(n) + "-gramy.txt";
    ofstream wy(nazwa);
    PrintMap(wordsCount, wy);
}

void anagramy()
{
    static const char* fileName = "RJ.txt";
    vector<string> words;
    ifstream fileStream(fileName);
    if (fileStream.is_open())
        while (fileStream.good())
        {
            string word;
            fileStream >> word;

            for (int i = 0, len = word.size(); i < len; i++)
            {

                if (ispunct(word[i]))
                {
                    word.erase(i--, 1);
                    len = word.size();
                }
            }

            sort(word.begin(), word.end());
            do
                words.push_back(word);
            while (next_permutation(word.begin(), word.end()));
            
        }

    ofstream wy("anagramy.txt");
    PrintVector(words, wy);
}

int main()
{
    thread t1(liczenie_slow);
    thread t2(liczenie_znakow);
    thread t3(ngramy, 2);
    thread t4(ngramy, 3);
    thread t5(ngramy, 4);
    thread t6(ngramy, 5);
    //thread t7(anagramy);  //tworzy ka¿d¹ dostêpn¹ warianciê - bardzo wolne
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
   // t7.join();
    return 0;
}