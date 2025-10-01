
#include "sender.h"

DataSender::DataSender(sdbus::IConnection& connection, sdbus::ObjectPath objectPath)
    : AdaptorInterfaces(connection, std::move(objectPath))
{
    registerAdaptor();
}

DataSender::~DataSender()
{
    unregisterAdaptor();
}

std::string DataSender::PipelineStatusFetch()
{
    std::string status = fetcher_.StartFetching();
    return status;
}
