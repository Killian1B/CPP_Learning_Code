# Exercice 3
  
## Question 1




## Question 2

La taille en mémoire de la classe A est de 16 bytes, alors que la classe B est de 4 bytes.


## Question 3

Un "upcast" consiste à caster une classe-fille en sa classe-mère, et un "downcast" à caster une classe-mère en sa classe-fille.
Le "downcast" peut poser problème car nous ne pouvons pas savoir en quelle classe-fille caster la classe-mère.
Un `static-cast` est utilisé lorsque nous sommes sûre du cast qui sera effectué. Il peut être utiliser pour préciser le type d'un objet.
Le `dynamic-cast` est utilisé pour les cast de classe. Si un cast n'est pas possible, il renverra un `nullptr`.