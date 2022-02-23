FROM ubuntu:20.04

RUN apt update

COPY . .

# Cache the NDK
RUN wget https://dl.google.com/android/repository/android-ndk-r24-rc1-linux.zip && unzip android-ndk-r24-rc1-linux.zip && rm -r -f android-ndk-r24-rc1-linux.zip

RUN pwd > ndkpath.txt && echo "/android-ndk-r24-rc1-linux" > ndkpath.txt





