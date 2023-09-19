#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//--- cut here

// REFERENCE: compare returns true if x < y

bool compare(std::string x, std::string y) {
    int xos = 0;
    int yos = 0;
    for (char& c : x) {
        if (c == '1') {
            xos += 1;
        }
    }
    for (char& c : y) {
        if (c == '1') {
            yos += 1;
        }
    }
    
    return (xos != yos) ? (xos > yos) : (std::stoi(x) < std::stoi(y));
}

//---

int main(){
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;
    
    std::sort(nums.begin(), nums.end(), compare);
    
    for(auto& line : nums) std::cout << line << ' ';
}
