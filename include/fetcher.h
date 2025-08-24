#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"

class ActionsDataFetcher {
public:
    int StartFetching();
private:
    const char* token = std::getenv("GITHUB_TOKEN");
};