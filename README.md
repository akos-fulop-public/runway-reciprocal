# Project Runway Reciprocal

CLI tool to return the reciprocal of a runway identifier

## Usage
The project is set up with a multistage Dockerfile. To compile, use or develop, you need a Linux host with Docker installed.

### Build and run
To build the application, in the project root run:
```docker image build -t runway-reciprocal .```
Then run the app with
```docker container run --rm runway-reciprocal```

### Develop
The recommended way to develop is to build the "builder" stage as an image:
```docker image build --target builder -t runway-reciprocal:builder .```

### Test
The usual method to run the unittests is to manually invoke `ctest` in in the builder image.
However tests can also be executed as a build stage:
```docker image build --target test -t runway-reciprocal:test .```
