#include <iostream>
#include <vector>
using namespace std;

string encrypt(string charachters)
{
    vector<string> charachters_list;
    int i = 0;
    int char_len = charachters.size();
    string temp_char;

    while (i != char_len)
    {

        if (charachters[i] == ' ')
        {
            charachters_list.push_back(temp_char);
            temp_char = "";
            i = i + 1;
        };

        temp_char = temp_char + charachters[i];
        i = i + 1;
    };
    // on va utiliser un ancien systheme que je fesait avec clf c est comme du morse custom mais le f est utiliser pour marquer la fin de la lettre
    // il faut maintenant pour le programme checker les lettres uniquent
    // on va checker si les lettre a coté de l alphabet n apparaissent aussi pas 2 fois aussi et ainsi de suite l objectif va etre de alouer le plus de lettres possibles sans que elles se touchent

    return charachters;
};

string paraphraser(string phrase)
{

    encrypt(phrase);
    return phrase;
};

int main()
{
    string phrase;
    cin >> phrase;
    //

    phrase = paraphraser(phrase);
    cout << phrase;
}
