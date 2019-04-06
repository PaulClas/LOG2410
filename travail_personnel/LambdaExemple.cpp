
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

