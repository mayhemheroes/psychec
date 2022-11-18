FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y clang

COPY . /repo
# WORKDIR /repo/build
WORKDIR /repo
# RUN cmake ..
RUN clang++ harness.cpp utility/Process.cpp tools/*.cpp -fsanitize=fuzzer -o out -Iutility/

# FROM ubuntu:22.04 as package
# COPY --from=builder /repo/build/cnip /
# COPY --from=builder /repo/build/C/* /deps/
# COPY --from=builder /repo/build/common/* /deps/
# ENV LD_LIBRARY_PATH=/deps
