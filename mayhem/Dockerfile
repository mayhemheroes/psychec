FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake clang

COPY . /repo
WORKDIR /repo/build
RUN cmake ..
RUN make -j8
WORKDIR /repo
RUN clang++ /repo/mayhem/fuzz_fullDir.cpp utility/*.cpp tools/*.cpp -fsanitize=fuzzer -o /fuzz -Iutility/ -I.

FROM ubuntu:22.04 as package
COPY --from=builder /repo/build/cnip /
COPY --from=builder /repo/build/C/* /deps/
COPY --from=builder /repo/build/common/* /deps/
COPY --from=builder /fuzz /fuzz_fullDir
ENV LD_LIBRARY_PATH=/deps