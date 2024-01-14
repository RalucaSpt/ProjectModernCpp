#include<vector>
#include<algorithm>
#include<ranges>
#include <algorithm>
#include <iostream>

//extern "C++" {
    __declspec(dllexport) class sorting
    {
        public:
        void SortPairs(std::vector<std::pair<int, std::string>>& input)
        {
            std::ranges::sort(input);
        }
        void test()
        {
            std::cout << "Hello Word";
        }
    };
     
   
//}