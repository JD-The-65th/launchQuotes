FROM ubuntu:20.04

RUN apt update

COPY . .

RUN         apt-get update \
                && apt-get install -y \
                    software-properties-common \
                    wget \
                && add-apt-repository -y ppa:ubuntu-toolchain-r/test \
                && apt-get update \
                && apt-get install -y \
                    make \
                    git \
                    curl \
                    ninja-build \
                    unzip \
                    lsb-release \
                    && apt clean all

# Get CMAKE, workaround for apt being out of date

RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null

RUN apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"

RUN apt update && apt install -y cmake

# Cache the NDK
RUN wget https://dl.google.com/android/repository/android-ndk-r24-rc1-linux.zip && unzip android-ndk-r24-rc1-linux.zip && rm -r -f android-ndk-r24-rc1-linux.zip

RUN pwd > ndkpath.txt && echo "/android-ndk-r24-rc1-linux" > ndkpath.txt

# Get Powershell

RUN wget https://github.com/PowerShell/PowerShell/releases/download/v7.2.1/powershell-lts_7.2.1-1.deb_amd64.deb && dpkg -i powershell-lts_7.2.1-1.deb_amd64.deb && apt-get install -f && rm -r -f powershell-lts_7.2.1-1.deb_amd64.deb

# Get QPM-Rust

RUN wget https://nightly.link/RedBrumbler/QuestPackageManager-Rust/workflows/cargo-build/main/linux-qpm-rust.zip && unzip linux-qpm-rust.zip && chmod +x qpm-rust && rm -r -f linux-qpm-rust.zip

# Build

RUN  ./qpm-rust restore && pwsh ./build.ps1 






