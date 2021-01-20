#include <iostream>

class Person
{
private:
    std::string _name;
    unsigned int _age = 0u;

public:
    void set_name(const std::string& name) { _name = name; }
    void wait(unsigned int age) { _age = age; }
    const std::string& get_name() { return _name; }
    unsigned int get_age() { return _age; }
};

int main()
{
    Person p;

    p.set_name("Batman");
    p.wait(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}
