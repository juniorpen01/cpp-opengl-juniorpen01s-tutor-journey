FROM ubuntu:24.04

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    libx11-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    libgl1-mesa-dev \
    ca-certificates \
    clang \
    ninja-build \
    cmake \
    git && \
    rm -fr /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN cmake --preset debug && cmake --build --preset debug
CMD ["ctest", "--preset", "debug"]
