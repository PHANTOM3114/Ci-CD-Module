#pragma once

#include "httplib.h"
#include "nlohmann/json.hpp"

class ActionsDataFetcher {
public:
    std::string StartFetching();
private:
    const char* token = std::getenv("GITHUB_TOKEN");
    std::string pipeline_info;
};