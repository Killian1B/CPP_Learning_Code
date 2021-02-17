# Exercice 1

## Question 1

Un attribut de type `const Person&` représente la référence d'un objet, nous ne pourront pas lui attribuer de nouvel objet, mais pourrons le modifier. Alors qu'un attribut de type `const Person` représente juste l'objet et n'est pas modifiable. 
Après l'exécution de ce code, `phone._owner` sera en position 8.


## Question 4

Pour redéfinir le comportement de la classe j'ai changé la visibilité du champ `_owner` de la class `Phone` en `protected` pour pouvoir y accéder depuis `HomePhone`. J'ai aussi changé la méthode `ring` en méthode virtuelle.
J'ai également ajouté une méthode `nos_answer_phone` à la classe `Person` pour afficher le message du répondeur.


## Question 5



## Question 8

Oui, ce code compile. Celà me parrait normal, ici nous ne faisons pas appel au constructeur de Phone mais nous faisons une copie.


## Question 9

Ce type de classes sont des classes abstraites.


## Question 10

