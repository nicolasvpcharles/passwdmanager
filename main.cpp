#include <iostream>
#include <vector>
#include <string>
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
    // utilisation
    // on va utiliser un ancien systheme que je fesait avec clf c est comme du morse custom mais le f est utiliser pour marquer la fin de la lettre
    // il faut maintenant pour le programme checker les lettres uniquent
    // on va checker si les lettre a coté de l alphabet n apparaissent aussi pas 2 fois aussi et ainsi de suite l objectif va etre de alouer le plus de lettres possibles sans que elles se touchent
    // pour attribuer quel paire a quel paire on va utiliser les 2 mots qui ont le moins de lettres uniques a f
    // dans le cas ou il y a pas de lettres uniques dans 1 des sets on va utiliser la premiere lettre unique du set a coté
    //
    // Nico

    // checker pour les lettres qui apparaissent 2 fois
    i = 0;
    vector<char> charachter_repetition;
    while (i != charachters.size())
    {
        // faut faire 2 boucles
        int a = 0;
        while (a != charachters.size())
        {
            if (charachters[i] == charachters[a])
            {

                // peut etre refaire une 3eme boucle pour checker si le char est dans la liste
                int n = 0;
                bool is_on_list = false;
                while (n != charachter_repetition.size())
                {
                    if (charachter_repetition[n] == charachters[i])
                    {
                        is_on_list = true;
                    };
                    n = n + 1;
                };
                if (is_on_list == true)
                {
                    charachter_repetition.push_back(charachters[i]);
                }
                // j ai optimiser pour que quand on va faire pour check les lettres pas presente on ai que la copie une fois des charachters en double
                // ici apres je vais devoir faire une autre boucle while pour checker les elements present une fois je vais corriger apres les listes de mots et de lettres
                // il faut aussi que je fasse pour checker le lettres de l alphabet a coté et tt
            };
        };
        // fin du while
        i = i + 1;
    };
    // ici la fonction que je vais mettre va faire une liste avec tout les lettres uniques
    i = 0;
    bool is_unique = true;
    vector<char> unique_char;
    while (i != charachters.size())
    {
        // ici je dois faire une boucle pour checker individuelement les lettres et si elles sont presentes dans la sous liste des lettres doubles
        int a = 0;
        while (a != charachter_repetition.size())
        {
            // je check les elements de la liste
            if (charachters[i] == charachter_repetition[a])
            {
                // si ils y est on le note comme false si ça arrive sur true bah on ajoute le char apres
                is_unique = false;
            };
        };
        // ici je vais devoir recheck si le char est unique ou non pr l ajouter sur la liste
        if (is_unique == true)
        {
            unique_char.push_back(charachters[i]);
        };
        is_unique = true;

        i = i + 1;
    };
    // ici maintenant que j ai une liste de charachters unique je vais faire apres regarder lequels appartiennent a quels mots et apres regarder pour elargir la palette des char

    // mettre les mots dans 3 grp
    vector<string> list1 = {charachters_list[0], charachters_list[2]};
    vector<string> list2 = {charachters_list[2], charachters_list[3]};
    vector<string> list3 = {charachters_list[4], charachters_list[5]};

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
