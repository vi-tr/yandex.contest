#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
    long long int ans = 0;
    long int uid;
    std::cin >> uid;

    std::ifstream file("data.json");
    json data = json::parse(file);

    for (const auto& projects : data) {
        for (const auto& v : projects["tasks"]) {
            if (v["completed"] && v["user_id"] == uid) ans += 1;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
