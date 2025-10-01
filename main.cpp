#include <iostream>
#include <string>
#include <cstdlib>
#include <sdbus-c++/IConnection.h>
#include <sdbus-c++/IObject.h>
#include <sdbus-c++/Types.h>

#include "fetcher.h"

int main() {
    sdbus::ServiceName serviceName{"org.metaos.CiCdService"};
    auto connection = sdbus::createBusConnection(serviceName);

    sdbus::ObjectPath objectPath{"/org/metaos/CiCd"};
    auto pipelineData = sdbus::createObject(*connection, std::move(objectPath));

    connection->enterEventLoop();

    return 0;
}