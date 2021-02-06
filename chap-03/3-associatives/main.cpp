#include <set>
#include <unordered_set>
#include <iostream>
#include <map>

#include "keys.h"

int main()
{
    std::set<ComparableDog> dogs_set;
    ComparableDog medor { "medor", "labrador" };
    dogs_set.emplace(medor);
    ComparableDog gus { "gus", "bordercollie" };
    dogs_set.emplace(gus);
    ComparableDog medor_clone(medor);
    dogs_set.emplace(medor_clone);
    std::cout << dogs_set.size() << std::endl;

    std::unordered_set<HashableDog> dogs_unordered_set;
    HashableDog medor_hash { "medor", "labrador" };
    dogs_unordered_set.emplace(medor_hash);
    HashableDog gus_hash {"gus", "bordercollie"};
    dogs_unordered_set.emplace(gus_hash);
    std::cout << dogs_unordered_set.size() << std::endl;

    using Owner = std::pair<std::string, std::string>;
    std::map<ComparableDog, Owner> owners_by_dog;

    ComparableDog zim { "zim", "poodle" };
    ComparableDog flippy { "flippy", "spaniel" };

    owners_by_dog.insert(std::make_pair(medor, Owner { "Claire", "David" }));
    owners_by_dog.insert_or_assign(gus, Owner { "Marc", "Zipstein" });
    owners_by_dog.emplace(zim, Owner { "Céline", "Noël" });
    owners_by_dog.try_emplace(flippy, "Vincent", "Nozick");

    owners_by_dog.emplace(gus, Owner { "Claire", "David" });
    // -> gus is still owned by Marc (emplace does not modify values with existing keys, neither does insert or try_emplace)

    owners_by_dog.insert_or_assign(gus, Owner { "Vincent", "Nozick" });
    // -> gus is now owned by Vincent (insert_or_assign reassign values with existing keys)


    return 0;
}