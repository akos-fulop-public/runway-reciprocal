FROM rockylinux:9.3 AS builder

RUN dnf install -y clang cmake git
RUN echo "export CXX=/usr/bin/clang++" >> ~/.bashrc

WORKDIR /tmp
RUN git clone https://github.com/google/googletest.git -b v1.14.0 && \
	cd googletest && \
	mkdir build && \
	cd build && \
	cmake .. && \
	cmake --build . --target install
RUN echo "export GTEST_COLOR=1" >> ~/.bashrc
WORKDIR /src
RUN rm -r /tmp/googletest

ENTRYPOINT [ "/bin/bash" ]

FROM builder AS build

WORKDIR /build
COPY . /src
RUN cmake /src && cmake --build .
WORKDIR /src

FROM build AS test
WORKDIR /build
RUN ctest --output-on-failure

FROM rockylinux:9.3

WORKDIR /app
COPY --from=build /build/src/app /app/app
ENTRYPOINT [ "/app/app" ]
