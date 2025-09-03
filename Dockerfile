FROM opensuse/leap:latest
MAINTAINER Tux

# Update and install packages
RUN zypper refresh && \
    zypper install -y \
        gcc-c++ \
        make \
        cmake \
        git \
        boost-devel \
        libboost_system-devel \
        libopenssl-devel \
        nlohmann_json-devel \
        nano \
        sudo

# Install cpp-httplib
RUN git clone https://github.com/yhirose/cpp-httplib.git /opt/cpp-httplib && \
    cp /opt/cpp-httplib/httplib.h /usr/local/include/

# Set working directory
WORKDIR /workspace

ENTRYPOINT ["/bin/bash"]