## Standalone Docker Environment

This document provides guidance on building the Docker image for standard-system devices. For details about how to build the Docker image for mini- and small-system devices, see [OpenHarmony Docker Image](https://gitee.com/openharmony/docs/blob/master/docker/README_en.md)

The Docker image of OpenHarmony is hosted on [HUAWEI Cloud SWR](https://auth.huaweicloud.com/authui/login.html?service=https%3A%2F%2Fconsole.huaweicloud.com%2Fswr%2F%3Fregion%3Dcn-south-1%26cloud_route_state%3D%2Fapp%2Fwarehouse%2FwarehouseMangeDetail%2Fgoldensir%2Fopenharmony-docker%2Fopenharmony-docker%3Ftype%3DownImage&locale=en-us#/login). Using the Docker image will help simplify environment configurations needed for the building. After configuring the development environments, perform the steps below to access the Docker environment. The following steps use Ubuntu as an example (Windows is also supported).

### Setting Up the Docker Environment for Standard-System Devices (reference memory ≥ 128 MB) 

##### **Method 1: Obtaining the Docker image from HuaweiCloud SWR**：

1. Obtain the Docker image.
```
docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.5
```
2. Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:
```
docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.5
```

##### **Method 2: Using the Dockerfile to Build a Local Docker Image**

1. Obtain the Dockerfile script for a local Docker image.
```
git clone https://gitee.com/openharmony/docs.git
```
2. Go to the directory of the Dockerfile code and run the following command to build the Docker image:
```
cd docs/docker/standard
./build.sh
```
3. Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:
```
docker run -it -v $(pwd):/home/openharmony openharmony-docker-standard:0.0.5
```

### Building for Standard-System Devices (reference memory ≥ 128 MB)
Run the following script to start building for Standard-System Devices (reference memory ≥ 128 MB)

```
./build.sh --product-name {product_name}
```
**{product_name}** indicates the platform supported by the current distribution, for example, Hi3516DV300.
Files generated during compilation are stored in the **out/{device_name}/** directory, and the generated image is stored in the **out/{device_name}/packages/phone/images/** directory.



**Note**

 You can exit Docker by simply running the **exit** command.