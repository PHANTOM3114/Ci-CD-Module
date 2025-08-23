#include <iostream>
#include <string>
#include <cstdlib>

#include "boost/asio.hpp"
#include "httplib.h"
#include "nlohmann/json.hpp"


int main() {
    const char* token = std::getenv("GITHUB_TOKEN");

    if (token == nullptr) {
        std::cerr << "Error: GITHUB_TOKEN has not been found." << std::endl;
        return 1;
    }

    std::string auth_header = "token " + std::string(token);

    httplib::Client cli("https://api.github.com");

    httplib::Headers headers = {
        { "User-Agent", "MetaOS-CiCD-Module-Test/1.0" },
        { "Accept", "application/vnd.github.v3+json" },
        { "Authorization", auth_header }
    };

    auto res = cli.Get("/repos/PHANTOM3114/MetaOS-Controller/actions/runs", headers);

    if (res) {
        std::cout << "Status Code: " << res->status << std::endl;
        if (!res->body.empty()) {
            nlohmann::json json = nlohmann::json::parse(res->body);
            std::cout << json.dump(4) << std::endl; // Dump(4) is using for normal printing
        }
        return 0;
    }
    else {
        auto err = res.error();
        std::cerr << "HTTP request failed: " << httplib::to_string(err) << std::endl;
        return 1;
    }
}