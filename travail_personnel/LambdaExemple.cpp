
[capture](paramètres) mutable exception attribute->ret{ body };
// Exemple Déclaration complète

[capture] {paramètres}->ret {body}
// Déclaration d'un lambda const: les objets capturés par copie ne peuvent pas
// être modifiés

[capture] {paramètres} {body}
// Déclaration dans type de retour. le type de retour de la fermeture 
// operator() est déduite d'après le body:
//			- Si le body est composé de la mention return unique, le type
//				de retour est le type de l'expression retournée
//			- Si le body n'est pas composé de la mention return, alors 
//				le type de retour est void.

[capture]{body}
// Déclaration avec la liste des paramètres omis: la fonction ne prend aucun
// argument, comme si la liste des paramètres est {}


#include <iostream>

int main()
{
	bool const estNumeroCanadien{ true };
	int const numbTelephone{ 5146549856 };
	string const nom{ "Jason Bourne" };

	auto lambda = [estNumeroCanadien, nom, numbTelephone]() -> void
	{
		std::cout << "Le numero est canadien: " << std::boolalpha << un_booleen << "." << std::endl;
		std::cout << "Le numero de telephone de  "<< nom << " est " << numbTelephone <<" ."<< std::endl;
	};

	lambda();

	return 0;
}



#include <algorithm>
#include <iostream>


int main()
{
	std::vector<int> const num{ 8, 7, 5, 4, 31, 98, 2, 77, 648 };
	map

	int const diviseur{ 2 };
	int somme{ 0 };

	// Il n'y a aucun problème à mélanger les captures par valeur et par référence.
	std::for_each(std::cbegin(nombres), std::cend(nombres), [diviseur, &somme](int element) -> void
	{
		if (element % diviseur == 0)
		{
			somme += element;
		}
	});

	std::cout << "La somme de tous les éléments divisibles par " << diviseur << " vaut " << somme << "." << std::endl;
	return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	
	map<string, int> bottinTelephone;
	double n, m, value;
	string key, testKey;
	cin >> n;
	
	for_each(values.begin(), values.end(), [&](string& key, string& value) {
		bottinTelephone.insert(pair<string, double>(key, value));
	});


	for_each(cbegin(bottinTelephone), cend(bottinTelephone), [key, &value](string testKey) -> void
	{
		if (testkey == bottinTelephone->first)
		{
			cout << bottinTelephone->first << " " << bottinTelephone->second<< endl;
		}
	});

	return 0;
}


