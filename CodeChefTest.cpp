// extract to string
#include <iostream>
#include <string>
using namespace std;

main ()
{
    std::string name;
    
    std::cout << "Please, enter your full name: ";
    std::getline (std::cin,name);
    std::cout << "Hello, " << name << "!\n";
    char *a = new char[name.length()+1];
    strcpy(a,name.c_str());
    cout << a[0] << "\n";
    return 0;
}