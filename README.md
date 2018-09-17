# Notes Programmation Fillit

## 1. Vérification

* Vérifier qu'un seul argument soit passé à la fonction. (sinon retourne error)
* Vérification de chaque bloc du fichier d'entrée : 
chaque ligne (4) = 4char + 
 avec char = . ou # (sinon retourne erreur)
* Trouver le type de pièce puis l'ajouter à la structure chainée. (si trouve pas retourne erreur)
* Vérifier les lignes vides entre les blocs entrés (mais pas après le dernier bloc)
* Vérifier max 26 pièces

## 2. Stockage

On a une **liste chainée** avec toutes les pièces :

* son numéro en fonction de sa position dans le fichier d'entrée (A, B, C, ...)
* sa position de test en x
* sa position de test en y
* son type (code) de 6 chiffres en chaine de char
* le pointeur vers la pièce suivante.

> Le pointeur vers la première pièce peut contenir la taille de la map (au début Npièces x 4) ainsi que le nombre de pièces.


## 3. Algorithme

* vérifier si la première pièce peut se placer avec *ft_can_fill()*.
* tant que *ft_can_fill()* returne false (ne peut pas se placer) on augmente l'index de la map.t
* à chaque fois qu'une pièce dépasse l'index max, on augmente l'index de la pièce précédente et on remet celui de la pièce en cours à 0.
* Si la première pièce dépasse l'index max ça veut dire qu'uncune configuration n'est possible et on augmente la taile de la map.
* Si la dernière pièce rentre, ça veut dire qu'on a trouvé la meilleur configuration possible et on peut peut lancer la fonction d'affichage

### astuce : 

définir chaque type de pièce avec un code (0x0y,0x0y,0x0y) qui est passé en argument à une fonction qui vérifie si la pièce rentre.
exemple => **ft_can_fill(Structure, 1x0y0x1y-1x1y)**
....
.##.
##..
....
Cette fonction vérifierait si l'emplacement actuel (exemple x = 1 et test y = 1) est libres. s'il l'est, la fonction se décale relativement par rapport à cette position de test pour aller vérifier si les cases sont libres aux positions mentionnées (1x0y = x + 1 et y + 0)
Pour qu'on n'aie pas des nombres négatif qui changent la longueur de la chaine à vérifier en argument, on fixe le 0 à 5. Ce qui donne **ft_can_ill(Structure, 6x5y5x6y4x6y)**.
Ou encore : **ft_can_fill(Structure, 655646)**. (puisqu'un sait que c'est 0x0yxyxyxy)

