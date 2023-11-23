#include <cpr/cpr.h>
#include <iostream>
int main() {
    auto response = cpr::Get(cpr::Url{"http://localhost:18080"});
    std::cout << response.text;
    return 0;
}