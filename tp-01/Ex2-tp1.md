# Exercice 2

## Question 1

Les lignes qui déclenchent une erreur de compilation sont :
* *char c8{"a"};*
* *double\* d11{d10};*
* *double& d12;*
* *int\* i16 = &b2;*
* *int& i18{i14};*
* *const bool b20;*

Voici comment les corriger :
* *char c8{"a"};* -> *char c8{'a'};*
* *double\* d11{d10};* -> *double\* d11{&d10};*
* *double& d12;* -> *double& d12();*
* *int\* i16 = &b2;* -> *int i16 = b2;*
* *int& i18{i14};* -> *const int& i18{i14};*
* *const bool b20;* -> *const bool b20();*

Avec l'option `-Werror`, toutes les variables non utilisées provoquent une erreur.


## Question 2

Les valeurs de *s0* et de *\*i15* valent respectivement 0 et 2.
Mais nous ne pouvons pas donner la valeur de *ul7*.