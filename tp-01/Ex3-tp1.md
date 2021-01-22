# Exercice 3

## Question 2

Le passage par valeur permet d'acceder à la valeur d'une variable sans pour autant la modifier.
Un passage par référence permet d'acceder à l'adresse d'une variable, et de pouvoir modifier cette dernière.
Une passage par référence constante permet d'acceder à l'ardesse d'une variable sans pour autant pouvoir la modifier.


## Question 3

```cpp
int count_a_occurrences(const std::string& s);

void update_loop(const float& dt, std::string& errors_out);

bool are_all_positives(const std::vector<int>& values, int& negative_indices_out, size_t& negative_count_out);

std::string concatenate(const char& str1, const char& str2);
```
