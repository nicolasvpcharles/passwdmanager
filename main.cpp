#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;
string encrypt(string charachters, string message)
{
    int i = 0;
    random_device rd;
    mt19937 gen(rd());

    vector<string> charachters_list;
    int char_len = charachters.size();
    string temp_char;

    while (i != char_len)
    {
        if (charachters[i] == ' ')
        {
            charachters_list.push_back(temp_char);
            temp_char = "";
        }
        else
        {
            temp_char = temp_char + charachters[i];
        }

        i = i + 1;
    };

    charachters_list.push_back(temp_char);

    // utilisation
    // on va utiliser un ancien systheme que je fesait avec clf c est comme du morse custom mais le f est utiliser pour marquer la fin de la lettre
    // il faut maintenant pour le programme checker les lettres uniquent
    // on va checker si les lettre a coté de l alphabet n apparaissent aussi pas 2 fois aussi et ainsi de suite l objectif va etre de alouer le plus de lettres possibles sans que elles se touchent
    // pour attribuer quel paire a quel paire on va utiliser les 2 mots qui ont le moins de lettres uniques a f
    // dans le cas ou il y a pas de lettres uniques dans 1 des sets on va utiliser la premiere lettre unique du set a coté
    //
    // Nico

    // ici on va faire une liste avec toutes les lettres qui apparaissent exactement une fois
    vector<char> unique_char;

    i = 0;

    while (i != charachters.size())
    {
        int count = 0;
        int a = 0;

        while (a != charachters.size())
        {
            if (charachters[i] == charachters[a])
            {
                count = count + 1;
            }

            a = a + 1;
        }

        // On ajoute seulement les lettres qui apparaissent une fois
        // et on ignore les espaces
        if (count == 1 && charachters[i] != ' ')
        {
            unique_char.push_back(charachters[i]);
        }

        i = i + 1;
    }

    // ici maintenant que j ai une liste de charachters unique
    // je vais faire apres regarder lesquels appartiennent a quels mots
    // et apres regarder pour elargir la palette des char

    // je vais checker quels lettres uniques appartiennent a quel mot
    i = 0;

    vector<string> unique_char_list = {"", "", "", "", "", ""};

    while (i != charachters_list.size())
    {
        int a = 0;

        while (a != charachters_list[i].size())
        {
            int n = 0;
            bool is_present = false;

            while (n != unique_char.size())
            {
                // ici il va falloir donc checker les charachters
                // il faut checker si la lettre apparait pas dans le bail
                // alors il va falloir l ajouter dans une sous liste
                // avec comme index le numero du mot

                if (charachters_list[i][a] == unique_char[n])
                {
                    is_present = true;
                }

                n = n + 1;
            }

            if (is_present == true)
            {
                // ici vu que l element a bien ete confirmé comme unique
                // on va l ajouter a la liste du mot correspondant
                unique_char_list[i] = unique_char_list[i] + charachters_list[i][a];
            }

            a = a + 1;
        }

        i = i + 1;
    }

    // maintenant que j ai une liste avec les elements et tout
    // il va falloir merge le 0 avec 1 le 2 avk 3 etc

    vector<string> dict_list = {
        unique_char_list[0] + unique_char_list[1],
        unique_char_list[2] + unique_char_list[3],
        unique_char_list[4] + unique_char_list[5]};

    i = 0;

    //
    // maintenant il faut trouver les differentes lettres qui irons en plus dans le dictionnaire
    //
    vector<char> dict = {
        // minuscules
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

        // majuscules
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

        // chiffres
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

        // caractères spéciaux ASCII
        ' ', '!', '"', '#', '$', '%', '&',
        '(', ')', '*', '+', ',', '-', '.', '/',
        ':', ';', '<', '=', '>', '?', '@',
        '[', ']', '^', '_', '`',
        '{', '|', '}', '~'};
    vector<int> dict_list_index;
    // il faut maintenant trouver l indexe de toutes les lettres et les mettres dans une autre liste
    i = 0;
    while (i != dict_list.size())
    {
        // ici la boucle est la pour dictilist

        // il faut refaire une 3eme boucle
        int n = 0;
        while (n != dict_list[i].size())
        {

            int a = 0;
            while (a != dict.size())
            {
                if (dict_list[i][n] == dict[a])
                {
                    dict_list_index.push_back(a);
                };
                a = a + 1;
            };

            n = n + 1;
        };

        i = i + 1;
    };
    // maintenant que j ai les indexs il va falloir que je fasse une liste pour c une autre pour t et une pour f
    // faire au début de f il faut d abord trouver le size du dict list le plus petit
    int n = 0;
    int shortest_dict = 0;
    while (n != dict_list.size())
    {
        if (dict_list[n].size() < dict_list[shortest_dict].size())
        {
            shortest_dict = n;
        };

        n = n + 1;
    };
    // maintenant que je connais le shortest dict je vais faire une fontion qui va m aider a pouvoir trouver le meilleur ordre
    // je vais faire pr que ça prenne le max de charachters vers la droite juque l arrivée de un autre éléemnt qui est dans la liste des char uniques
    // dict = dicti_list
    // dataset=le dataset des elements de la liste
    // char index = l indexe des charachters
    // jsp il y a un beug avec la fonction je vais devoir malheureusement juste imprimer 3 fois la mm fonction nsmr
    //
    i = 0;
    string f = dict_list[shortest_dict];
    // je vais mtn attribuer les autres elements
    int c_index;
    int l_index;
    int f_index;
    if (shortest_dict == 0)
    {
        string c = dict_list[1];
        string t = dict_list[2];
        c_index = 1;
        l_index = 2;
        f_index = 0;
    };
    if (shortest_dict == 1)
    {
        string c = dict_list[0];
        string t = dict_list[2];
        c_index = 0;
        l_index = 2;
        f_index = 1;
    };
    if (shortest_dict == 2)
    {
        string c = dict_list[0];
        string t = dict_list[1];
        c_index = 0;
        l_index = 1;
        f_index = 2;
    };
    //
    // code generer par ia car ça fait 3 jours que je galere a faire une fonction qui marche
    //
    for (int i = 0; i < dict_list.size(); i++)
    {
        int n = 0;

        while (n < dict_list[i].size())
        {
            char current = dict_list[i][n];

            int position = 0;

            while (position < dict.size() && dict[position] != current)
            {
                position++;
            }

            position++;

            while (position < dict.size())
            {
                bool found = false;

                for (int k = 0; k < dict_list.size(); k++)
                {
                    if (k != i && dict_list[k].find(dict[position]) != string::npos)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    break;
                }

                if (dict_list[i].find(dict[position]) == string::npos)
                {
                    dict_list[i] += dict[position];
                }

                position++;
            }

            n++;
        }
    }

    // fin du code generer par ia
    //
    // maintenant que j ai fais ça je peut enfin commencer a faire le language codé pour l encryption des messages
    vector<string> morse = {
        // minuscules
        "lf", "cf", "llf", "lcf", "clf", "ccf", "lllf", "llcf",
        "lclf", "lccf", "cllf", "clcf", "cclf", "cccf", "llllf",
        "lllcf", "llclf", "llccf", "lcllf", "lclcf", "lcclf", "lcccf",
        "clllf", "cllcf", "clclf", "clccf",

        // majuscules
        "ccllf", "cclcf", "ccclf", "cccllf", "cccclf",
        "ccccccf", "lllllf", "llllcf", "lllclf", "lllccf", "llcllf", "llclcf",
        "llcclf", "llcccf", "llccclf", "llcccclf", "lclllf",
        "lcllcf", "lclclf", "lclccf", "lccllf", "lcclcf",
        "lllllllf", "lcccclf", "cllllf", "clllcf",

        // chiffres
        "cllclf", "cllccf", "clcllf", "clclcf", "clcclf", "clcccf",
        "cclllf", "ccllcf", "cclclf", "cclccf",

        // caractères spéciaux ASCII
        "cclcllf", "cclclcf", "cclcclf", "cclcccf",
        "ccclllf", "cccllcf", "ccclclf", "ccclccf",
        "ccccllf", "ccccclf", "cccccf",
        "llllllf", "lllllcf", "llllclf", "llllccf",
        "lllcllf", "lllclcf", "lllcclf", "lllcccf",
        "llclllf", "llcllcf", "llclclf", "llclccf",
        "llccllf", "llcclcf", "llccclf", "llccccf",
        "lcllllf", "lclllcf", "lcllclf", "lcllccf",
        "lclcllf", "lclclcf", "lclcclf", "lclcccf",
        "lcclllf", "lccllcf", "lcclclf", "lcclccf",
        "lcccllf", "lccclcf", "lcccclf", "lcccccf",
        "clllllf", "cllllcf", "clllclf", "clllccf",
        "cllcllf"};

    // maintenant que j ai le dictionnaire pr encrypt
    // il va falloir faire une boucle qui prend les charachters
    // une autre qui va regarder a quel index la lettre est
    // et a la fin il va falloir ajouter a un autre string les lettres clf ajoutées
    //
    i = 0;
    string encrypted_message;
    while (i != message.size())
    {
        // emplacement de la 2eme boucle
        int a = 0;
        int temp_char_index;
        while (a != dict.size())
        {

            if (dict[a] == message[i])
            {
                temp_char_index = a;
                break;
                // je break car j ai trouvé l index a #optimisation
            };

            a = a + 1;
        };
        encrypted_message = encrypted_message + morse[temp_char_index];

        i = i + 1;
    };
    // apres il va falloir faire une autre oucle qui va faire un autre string (oui encore) et y ajouter des elements de la bibliotheque clf
    //  le return je dois retourner le output dedans
    // maintenant que j ai les message en clf je vais maintenant encrypter les messages grace aux 3 bibliotheques
    // il va falloir faire une boucle seulement trouver si c est un c l ou f et apres les remplacer par un char aléatoire dans la bibliotheque
    i = 0;
    string encrypted_clf;
    int num;
    while (i != encrypted_message.size())
    {

        if (encrypted_message[i] == 'c')
        {
            uniform_int_distribution<int> dist_c(0, dict_list[c_index].size() - 1);
            num = dist_c(gen);

            encrypted_clf = encrypted_clf + dict_list[c_index][num];
        };
        if (encrypted_message[i] == 'l')
        {
            uniform_int_distribution<int> dist_l(0, dict_list[l_index].size() - 1);
            num = dist_l(gen);
            encrypted_clf = encrypted_clf + dict_list[l_index][num];
        };
        if (encrypted_message[i] == 'f')
        {
            uniform_int_distribution<int> dist_f(0, dict_list[f_index].size() - 1);
            num = dist_f(gen);
            encrypted_clf = encrypted_clf + dict_list[f_index][num];
        };
        i = i + 1;
    };

    return encrypted_clf;
};
//
// Fonction de décryptage
//
//
//
//
//
//
string decrypt(string charachters, string message)
{
    // pour decrypter il va faloir deja refaire le bail de la phrase et trouver les charachteres semblables
    // je vais juste copier coller le code
    //
    //
    //
    int i = 0;
    random_device rd;
    mt19937 gen(rd());

    vector<string> charachters_list;
    int char_len = charachters.size();
    string temp_char;
    // je vais mettre des cout pr debuger plus simplement
    cout << "-\n-\n-\n-\n-\n-\n";
    while (i != char_len)
    {
        if (charachters[i] == ' ')
        {
            charachters_list.push_back(temp_char);
            temp_char = "";
        }
        else
        {
            temp_char = temp_char + charachters[i];
        }

        i = i + 1;
    };

    charachters_list.push_back(temp_char);

    // utilisation
    // on va utiliser un ancien systheme que je fesait avec clf c est comme du morse custom mais le f est utiliser pour marquer la fin de la lettre
    // il faut maintenant pour le programme checker les lettres uniquent
    // on va checker si les lettre a coté de l alphabet n apparaissent aussi pas 2 fois aussi et ainsi de suite l objectif va etre de alouer le plus de lettres possibles sans que elles se touchent
    // pour attribuer quel paire a quel paire on va utiliser les 2 mots qui ont le moins de lettres uniques a f
    // dans le cas ou il y a pas de lettres uniques dans 1 des sets on va utiliser la premiere lettre unique du set a coté
    //
    // Nico

    // ici on va faire une liste avec toutes les lettres qui apparaissent exactement une fois
    vector<char> unique_char;

    i = 0;

    while (i != charachters.size())
    {
        int count = 0;
        int a = 0;

        while (a != charachters.size())
        {
            if (charachters[i] == charachters[a])
            {
                count = count + 1;
            }

            a = a + 1;
        }

        // On ajoute seulement les lettres qui apparaissent une fois
        // et on ignore les espaces
        if (count == 1 && charachters[i] != ' ')
        {
            unique_char.push_back(charachters[i]);
        }

        i = i + 1;
    }

    // ici maintenant que j ai une liste de charachters unique
    // je vais faire apres regarder lesquels appartiennent a quels mots
    // et apres regarder pour elargir la palette des char

    // je vais checker quels lettres uniques appartiennent a quel mot
    i = 0;

    vector<string> unique_char_list = {"", "", "", "", "", ""};

    while (i != charachters_list.size())
    {
        int a = 0;

        while (a != charachters_list[i].size())
        {
            int n = 0;
            bool is_present = false;

            while (n != unique_char.size())
            {
                // ici il va falloir donc checker les charachters
                // il faut checker si la lettre apparait pas dans le bail
                // alors il va falloir l ajouter dans une sous liste
                // avec comme index le numero du mot

                if (charachters_list[i][a] == unique_char[n])
                {
                    is_present = true;
                }

                n = n + 1;
            }

            if (is_present == true)
            {
                // ici vu que l element a bien ete confirmé comme unique
                // on va l ajouter a la liste du mot correspondant
                unique_char_list[i] = unique_char_list[i] + charachters_list[i][a];
            }

            a = a + 1;
        }

        i = i + 1;
    }

    // maintenant que j ai une liste avec les elements et tout
    // il va falloir merge le 0 avec 1 le 2 avk 3 etc

    vector<string> dict_list = {
        unique_char_list[0] + unique_char_list[1],
        unique_char_list[2] + unique_char_list[3],
        unique_char_list[4] + unique_char_list[5]};

    i = 0;

    //
    // maintenant il faut trouver les differentes lettres qui irons en plus dans le dictionnaire
    //
    vector<char> dict = {
        // minuscules
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

        // majuscules
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

        // chiffres
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

        // caractères spéciaux ASCII
        ' ', '!', '"', '#', '$', '%', '&',
        '(', ')', '*', '+', ',', '-', '.', '/',
        ':', ';', '<', '=', '>', '?', '@',
        '[', ']', '^', '_', '`',
        '{', '|', '}', '~'};
    vector<int> dict_list_index;
    // il faut maintenant trouver l indexe de toutes les lettres et les mettres dans une autre liste
    i = 0;
    while (i != dict_list.size())
    {
        // ici la boucle est la pour dictilist

        // il faut refaire une 3eme boucle
        int n = 0;
        while (n != dict_list[i].size())
        {

            int a = 0;
            while (a != dict.size())
            {
                if (dict_list[i][n] == dict[a])
                {
                    dict_list_index.push_back(a);
                };
                a = a + 1;
            };

            n = n + 1;
        };

        i = i + 1;
    };
    // maintenant que j ai les indexs il va falloir que je fasse une liste pour c une autre pour t et une pour f
    // faire au début de f il faut d abord trouver le size du dict list le plus petit
    int n = 0;
    int shortest_dict = 0;
    while (n != dict_list.size())
    {
        if (dict_list[n].size() < dict_list[shortest_dict].size())
        {
            shortest_dict = n;
        };

        n = n + 1;
    };
    // maintenant que je connais le shortest dict je vais faire une fontion qui va m aider a pouvoir trouver le meilleur ordre
    // je vais faire pr que ça prenne le max de charachters vers la droite juque l arrivée de un autre éléemnt qui est dans la liste des char uniques
    // dict = dicti_list
    // dataset=le dataset des elements de la liste
    // char index = l indexe des charachters
    // jsp il y a un beug avec la fonction je vais devoir malheureusement juste imprimer 3 fois la mm fonction nsmr
    //
    i = 0;
    string f = dict_list[shortest_dict];
    // je vais mtn attribuer les autres elements
    int c_index;
    int l_index;
    int f_index;
    if (shortest_dict == 0)
    {
        string c = dict_list[1];
        string t = dict_list[2];
        c_index = 1;
        l_index = 2;
        f_index = 0;
    };
    if (shortest_dict == 1)
    {
        string c = dict_list[0];
        string t = dict_list[2];
        c_index = 0;
        l_index = 2;
        f_index = 1;
    };
    if (shortest_dict == 2)
    {
        string c = dict_list[0];
        string t = dict_list[1];
        c_index = 0;
        l_index = 1;
        f_index = 2;
    };
    //
    // code generer par ia car ça fait 3 jours que je galere a faire une fonction qui marche
    //
    for (int i = 0; i < dict_list.size(); i++)
    {
        int n = 0;

        while (n < dict_list[i].size())
        {
            char current = dict_list[i][n];

            int position = 0;

            while (position < dict.size() && dict[position] != current)
            {
                position++;
            }

            position++;

            while (position < dict.size())
            {
                bool found = false;

                for (int k = 0; k < dict_list.size(); k++)
                {
                    if (k != i && dict_list[k].find(dict[position]) != string::npos)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    break;
                }

                if (dict_list[i].find(dict[position]) == string::npos)
                {
                    dict_list[i] += dict[position];
                }

                position++;
            }

            n++;
        }
    }
    //
    //
    // fin du code copié collé
    // maintenant il va faloir faire l inverse de ce que on a fait on va prendre les charachteres dict et il va falloir les convertirs en c l f
    i = 0;
    // je fait une premiere boucle pour checker les lettres individuelement
    //
    //
    //
    string c = dict_list[c_index];
    string l = dict_list[l_index];
    f = dict_list[f_index];

    string clf_message;
    while (i != message.size())
    {
        // la je pense juste checker les elements d abord faire une boucle pour c apres pour l apres pour le f je vais mettre un confiremed a la fin pour skipp les autre boucles apres alors
        n = 0;
        bool present = false;
        while (n != dict_list[c_index].size())
        {
            if (message[i] == c[n])
            {
                clf_message = clf_message + "c";
                present = true;
            };

            n = n + 1;
        };

        n = 0;
        while (n != dict_list[l_index].size())
        {

            if (message[i] == l[n])
            {
                clf_message = clf_message + "l";
                present = true;
            };

            n = n + 1;
        };

        n = 0;
        while (n != dict_list[f_index].size())
        {

            if (message[i] == f[n])
            {
                clf_message = clf_message + "f";
                present = true;
            };

            n = n + 1;
        };

        i = i + 1;
    };
    // maintenant que on a le message clf il va falloir que je split le bail avec les f pour que je puisse apres bien faire le bail
    // les prochaines lignes de codes vont split les charachters
    i = 0;
    string temp_char_decrypt;
    vector<string> cl_list;
    while (i != clf_message.size())
    {

        if (clf_message[i] == 'f')
        {
            cl_list.push_back(temp_char_decrypt);
            temp_char_decrypt = "";
        }
        else
        {
            temp_char_decrypt = temp_char_decrypt + clf_message[i];
        };

        i = i + 1;
    };
    // maintenant que j ai tout ça je vais maintenant faire pr changer les clf en lettres
    vector<string> morse = {
        // minuscules
        "l", "c", "ll", "lc", "cl", "cc", "lll", "llc",
        "lcl", "lcc", "cll", "clc", "ccl", "ccc", "llll",
        "lllc", "llcl", "llcc", "lcll", "lclc", "lccl", "lccc",
        "clll", "cllc", "clcl", "clcc",

        // majuscules
        "ccll", "cclc", "cccl", "cccll", "cccll",
        "cccccc", "lllll", "llllc", "lllcl", "lllcc", "llcll", "llclc",
        "llccl", "llccc", "llcccl", "llcccll", "lclll",
        "lcllc", "lclcl", "lclcc", "lccll", "lcclc",
        "lllllll", "lcccc", "cllll", "clllc",

        // chiffres
        "cllcl", "cllcc", "clcll", "clclc", "clccl", "clccc",
        "cclll", "ccllc", "cclcl", "cclcc",

        // caractères spéciaux ASCII
        "cclcll", "cclclc", "cclccl", "cclccc",
        "ccclll", "cccllc", "ccclcl", "ccclcc",
        "ccccll", "cccccl", "ccccc",
        "llllll", "lllllc", "llllcl", "llllcc",
        "lllcll", "lllclc", "lllccl", "lllccc",
        "llclll", "llcllc", "llclcl", "llclcc",
        "llccll", "llcclc", "llcccl", "llcccc",
        "lcllll", "lclllc", "lcllcl", "lcllcc",
        "lclcll", "lclclc", "lclccl", "lclccc",
        "lcclll", "lccllc", "lcclcl", "lcclcc",
        "lcccll", "lccclc", "lccccl", "lccccc",
        "clllll", "cllllc", "clllcl", "clllcc",
        "cllcll"};
    // et mtn les lettres
    dict = {
        // minuscules
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

        // majuscules
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

        // chiffres
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

        // caractères spéciaux ASCII
        ' ', '!', '"', '#', '$', '%', '&',
        '(', ')', '*', '+', ',', '-', '.', '/',
        ':', ';', '<', '=', '>', '?', '@',
        '[', ']', '^', '_', '`',
        '{', '|', '}', '~'};
    i = 0;
    string decrypted_message;
    while (i != cl_list.size())
    {
        n = 0;
        while (n != morse.size())
        {
            if (cl_list[i] == morse[n])
            {
                decrypted_message = decrypted_message + dict[n];
            };
            n = n + 1;
        };
        i = i + 1;
    };

    return decrypted_message;
};

int main()
{
    string phrase;
    string message;
    getline(cin, phrase);
    //il va faloir verifier l eligibilité du message
    cout << "type the message you want to encrypt : ";
    getline(cin, message);
    string phrase_encrypted = encrypt(phrase, message);
    //
    // maintenant il faut decrypt les messages
    //
    string phrase_decrypted = decrypt(phrase, phrase_encrypted);
    cout << "le message decrypté\n";
    cout << phrase_decrypted;
    cout << "\n fin du programme ";
    cout << endl;
}
