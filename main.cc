#include <iostream>
#include <string>
#include <cstdlib>

#include "boost/asio.hpp"

namespace local = boost::asio::local;

int main() {
    try {
        boost::asio::io_context io_context;
        local::stream_protocol::socket sock(io_context);

        sock.connect(local::stream_protocol::endpoint("/tmp/meta_daemon_cicd.sock"));

        std::string message = R"({"pipeline_id": 123, "status": "success"})";

        boost::system::error_code error;
        boost::asio::write(sock, boost::asio::buffer(message), error);

        if (error) {
            throw boost::system::system_error(error);
        }
    }
    catch (std::exception& ec) {
        std::cerr << "Exception: " << ec.what() << std::endl;
    }
}