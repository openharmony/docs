# OpenHarmony Docker Image

### Docker Image

This document provides guidance on building the Docker image for mini- and small-system devices. For details about how to build the Docker image for standard-system devices, see [OpenHarmony Docker Image](https://gitee.com/openharmony/docs/blob/master/docker/standard/Readme-en.md)

The Docker image of OpenHarmony is hosted on [HUAWEI Cloud SWR](https://auth.huaweicloud.com/authui/login.html?service=https%3A%2F%2Fconsole.huaweicloud.com%2Fswr%2F%3Fregion%3Dcn-south-1%26cloud_route_state%3D%2Fapp%2Fwarehouse%2FwarehouseMangeDetail%2Fgoldensir%2Fopenharmony-docker%2Fopenharmony-docker%3Ftype%3DownImage&locale=en-us#/login). Using the Docker image will help simplify environment configurations needed for the building. The following table lists container-based options needed for building in the standalone Docker environment.

| Docker Image Repository                                      | Tag     | Description                                                  |
| :----------------------------------------------------------- | :------ | :----------------------------------------------------------- |
| `swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker` | `0.0.7` | The OpenHarmony build environment has been pre-installed. This repository applies to Mini-System Devices (reference memory ≥ 128 KB) and Small-System Devices (reference memory ≥ 1 MB). |

### Usage

 After configuring the development environments, perform the steps below to access the Docker environment. 

1. Obtain the Docker image.
     ```
     docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.7
     ```
2. Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:
     ```
     docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.7
     ```
3. Run the following script to start building for different platforms.
     ```
     hb set # Set the working directory.
     . # Enter the directory where the source code is stored. If the code is stored in the current directory, enter a period (.).
     Press the Up or Down key to select the platform to build on, then press Enter.
     hb build -f # Start building.
     ```
