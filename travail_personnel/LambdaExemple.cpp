
[capture](param�tres) mutable exception attribute->ret{ body };
// Exemple D�claration compl�te

[capture] {param�tres}->ret {body}
// D�claration d'un lambda const: les objets captur�s par copie ne peuvent pas
// �tre modifi�s

[capture] {param�tres} {body}
// D�claration dans type de retour. le type de retour de la fermeture 
// operator() est d�duite d'apr�s le body:
//			- Si le body est compos� de la mention return unique, le type
//				de retour est le type de l'expression retourn�e
//			- Si le body n'est pas compos� de la mention return, alors 
//				le type de retour est void.

[capture]{body}
// D�claration avec la liste des param�tres omis: la fonction ne prend aucun
// argument, comme si la liste des param�tres est {}

