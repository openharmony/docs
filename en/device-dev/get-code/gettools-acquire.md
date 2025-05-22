# Docker Environment


## Introduction

OpenHarmony provides the following two types of docker environments for you to quickly get the development environment ready:  

- Standalone Docker environment: applicable when using Ubuntu or Windows to build a distribution

- HPM-based Docker environment: applicable when using the HarmonyOS Package Manager (HPM) to build a distribution

**Table 1** Docker environments

| System Type| Operating Platform| Docker Image Repository| Tag| 
| -------- | -------- | -------- | -------- |
| Standard system (standalone Docker environment)| Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard | 3.2 | 
| Small system (standalone Docker environment)| Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small | 3.2 | 
| Mini system (standalone Docker environment)| Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini | 3.2 | 
| Mini and small systems (HPM Docker environment)| Ubuntu/Windows | swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker | 0.0.3 | 


## Setting Up Environment

Before using the Docker environment, you need to make necessary preparations. The following uses Ubuntu as an example to describe the specific preparations.

1. Installing Docker
   - Install Docker.
      ```
      sudo apt install docker.io
      ```
   - For details about how to install Docker on other types of OS, see [Docker Guide] (https://docs.docker.com/engine/install/).

2. Obtain the OpenHarmony source code.

   For details, see [Source Code Acquisition](sourcecode-acquire.md).

   > **NOTE**<br>
   > You do not need to obtain the source code for the HPM-based Docker environment.

3. Obtaining the required permissions.

   Perform subsequent operations as a user who has the root permission or has been granted the permission to use Docker. On Ubuntu, you can add **sudo** before a command to obtain the **root** permission. On Windows, you may need to run **cmd** or **PowerShell** in administrator mode.

## Standalone Docker Environment

A Docker image is a lightweight executable software package that contains applications and runtimes. Docker images of OpenHarmony are hosted on HuaweiCloud SWR. Using the Docker image will help simplify environment configurations needed for the building. The following describes the detailed procedure.

### Setting Up the Docker Environment for Mini- and Small-System Devices

1. Obtain the Docker image.

   For mini-system devices:

   ```
   docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2
   ```
   For small-system devices:
   ```
   docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini:3.2
   ```

2. Access the Docker build environment.

   After obtaining the Docker image, you need to create a Docker container and access the container. Go to the root directory of OpenHarmony source code and run the respective command to access the Docker build environment.

   - Ubuntu
     
      ```
      # For mini-system devices
      docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2

      # For small-system devices:
      docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini:3.2
      ```

   - Windows (example source code directory: `D:\OpenHarmony`)

      ```
      # For mini-system devices
      docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2

      # For small-system devices:
      docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_mini:3.2
      ```

   > **NOTE**<br>
   > `docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_small:3.2`: used to create an OpenHarmony Docker container that runs in interactive mode and maps the current directory to the `/home/openharmony` directory of the container.

### Building for Mini- and Small-System Devices

1. Run the build script.

   Run `docker run` to access the Docker container in `/home/openharmony`. Then, run the build script to start building for mini-system devices (reference memory ≥ 128 KiB) and small-system devices (reference memory ≥ 1 MiB).

   ```
   python3 build.py -p {product_name}@{company}
   ```

   where, `{product_name}` indicates the platform supported by the current version, and `{company}` indicates the company name.
   
   For example, to start building for `ipcamera_hispark_taurus` of `hisilicon`, use the following command:

   ```
   python3 build.py -p ipcamera_hispark_taurus@hisilicon
   ```

   Similarly, to start building for `qemu_small_system_demo` of `ohemu`, use the following command:

   ```
   python3 build.py -p qemu_small_system_demo@ohemu
   ```

2. View the build result.

   The files generated during the build are stored in `out/{device_name}/`, and the resulting images are stored in `out/{device_name}/packages/phone/images/`.

> **NOTE**<br>
> To exit Docker, run `exit`. This command stops the current Docker container and goes back to your OS.

### Setting Up the Docker Environment for Standard-System Devices

1. Obtain the Docker image.

   Before setting up a Docker environment for standard-system devices, you need to obtain the corresponding Docker image by running the following command:
     
   ```
   docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard:3.2
   ```

2. Access the Docker build environment.

   Same as the previous procedure, you need to create a new Docker container and access the container. Go to the root directory of OpenHarmony source code and run the respective command to access the Docker build environment.
     
   - Ubuntu

      ```
      docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard:3.2
      ```

   - Windows (example source code directory: D:\OpenHarmony)

      ```
      docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/docker_oh_standard:3.2
      ```

### Building for Standard-System Devices

1. Run the build script.

   Run `docker run` to access the Docker container in `/home/openharmony`. Then, run the build script to start building for standard-system devices (reference memory ≥ 128 MiB).
  
   ```
   ./build.sh --product-name {product_name} --ccache
   ```

   `{product_name}` indicates the platform supported by the current distribution. For example, if `{product_name}` is `rk3568`, run the following command to start building:

   ```
   ./build.sh --product-name rk3568 --ccache
   ```

2. View the build result.
   Files generated during the build are stored in `out/{device_name}/`, and the generated image is stored in `out/{device_name}/packages/phone/images/`.

> **NOTE**<br>
> To exit Docker, run `exit`. This command stops the current Docker container and goes back to your OS.


## HPM-based Docker Environment

**docker_dist** is a template component in the [HPM](https://hpm.harmonyos.com/) system. It helps to quickly initialize an HPM project and use the Docker image to quickly build a distribution of , greatly simplifying environment configurations needed for building. After configuring the Ubuntu and [hpm-cli](https://device.harmonyos.com/cn/docs/documentation/guide/hpm-part-development-install-0000001178291102) development environments, perform the following steps to access the Docker environment:


### Setting Up the Docker Environment

1. Initialize the installation template.

   Run the following command in any of the working directories:
     
   ```
   hpm init -t @ohos/docker_dist
   ```

2. Modify the **publishAs** field.

   The obtained bundle is of the template type. Open the **bundle.json** file in the current directory and change the value of **publishAs** from **template** to **distribution** as needed.


### Obtaining and Building Source Code

Start building. Docker can be automatically installed only in Ubuntu. If you are using any other operating system, manually install Docker before pulling the image.

- Automatical installation (Ubuntu)<br>
  Running the following command will automatically install Docker, pull the Docker image, and start the pulling and building of the corresponding solution in the container.

  Method 1:

  Add a parameter to specify the solution. For example:

    
  ```
  hpm run docker solution={product}
  ```

  **{product}** indicates the solution, for example, **\@ohos/hispark_taurus**, **\@ohos/hispark_aries**, or **\@ohos/hispark_pegasus**.

  Method 2:

  Set an environment variable to specify the solution, and then run the build command.

  1. Select the desired solution.
        
      ```
      export solution={product}
      ```

      **{product}** indicates the solution, for example, **\@ohos/hispark_taurus**, **\@ohos/hispark_aries**, or **\@ohos/hispark_pegasus**.
  2. Obtain and build the source code.
        
      ```
      hpm run docker
      ```

    This example uses the **\@ohos/hispark_taurus** solution for illustration. If the execution is successful, the output is as follows:
    
  ```
  ......
  ohos ipcamera_hispark_taurus build success!
  @ohos/hispark_taurus: distribution building completed.
  ```

- Manual installation (Non-Ubuntu)<br>
  Perform the following operations to install Docker:

    
  ```
  # Pull an image.
  docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3# Build the Docker image in the Linux environment.
  hpm run distWithDocker solution={product}
  # On Windows, make sure to configure the Git Bash.
  hpm config set shellPath "Git Bash path"
  hpm run distWithDocker solution={product}
  ```
