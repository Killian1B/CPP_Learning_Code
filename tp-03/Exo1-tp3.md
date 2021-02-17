# Exercice 1

## Question 1

| conteneur    | insertion (en tête / en fin) | suppression (en tête / en fin) | accès |
|--------------|-----------|----------|-----------|
| array        | N/A       | N/A      | O(ln(n))  |
| vector       | O(1)      | O(1)     | O(1)      |
| deque        | O(1)      | O(1)     | O(1)      |
| forward_list | O(1)      | O(1)     | O(1)      |
| list         | O(1)      | O(1)     | O(1)      |
| set          | O(ln(n))  | O(ln(n)) | O(ln(n))  |
| unordered_set| O(1)      | O(1)     | O(1)      |


## Question 2

Les opérations succeptibles d'invalider `it` sont celles qui incluent `end()` dans leur utilisation.


## Question 3

`push_back()` va ajouter une copie de l'élément à ajouter, alors que `emplace_back()` va construire un élément correspondant à celui que l'on veut ajouter.


## Question 4

`RelativePoint` a un constructeur, mais n'a pas de constructeur par défault. Il faut lui en ajouter un (Voir Exo1-tp3-Points.cpp).


## Question 5

