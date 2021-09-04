#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    Library A({"Alice_in_Wonderland", "Misery", "Portrait_of_Dorian_Gray", "It", "The_Hunger_Games"},
              {"Lewis_Carroll", "Stephen_King", "Oscar_Wilde","Stephen_King","Susan_Collins"});
    Librarian B;
    Visitor V;

    V.SearchVisitor(B, A);

    return 0;
}
