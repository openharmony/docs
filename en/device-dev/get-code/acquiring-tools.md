# Acquiring Tools<a name="EN-US_TOPIC_0000001055705774"></a>

-   [Using Docker to Prepare the Build Environment](#en-us_topic_0000001055701144_section107932281315)
    -   [HPM-based Docker](#en-us_topic_0000001055701144_section580016182283)
    -   [Standalone Docker Environment](#en-us_topic_0000001055701144_section319412277287)
    -   [Setting Up the Docker Environment](#en-us_topic_0000001055701144_section436042904715)
    -   [Building for  and](#en-us_topic_0000001055701144_section19121250134716)
    -   [Setting Up the Docker Environment for](#en-us_topic_0000001055701144_section776616712419)

-   [Acquiring the Device Development Tool \(HUAWEI DevEco Device Tool\)](#en-us_topic_0000001055701144_section2452141120244)
-   [Acquiring the Application Development Tool \(HUAWEI DevEco Studio\)](#en-us_topic_0000001055701144_section0904101019258)

## Using Docker to Prepare the Build Environment<a name="en-us_topic_0000001055701144_section107932281315"></a>

OpenHarmony provides the following two types of Docker environments for you to quickly get the development environment ready:

-   HPM-based Docker environment: applicable when using the HarmonyOS Package Manager \(HPM\) to build a distribution.
-   Standalone Docker environment: applicable when using Ubuntu or Windows to build a distribution.

    The following table lists container-based options needed for building in the standalone Docker environment.

    **Table  1**  Docker image

    <a name="en-us_topic_0000001055701144_table2790164495315"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001055701144_row3790644155317"><th class="cellrowborder" valign="top" width="35.5064493550645%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000001055701144_p8789114445316"><a name="en-us_topic_0000001055701144_p8789114445316"></a><a name="en-us_topic_0000001055701144_p8789114445316"></a>Docker Image Repository</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.258974102589741%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000001055701144_p17896448533"><a name="en-us_topic_0000001055701144_p17896448533"></a><a name="en-us_topic_0000001055701144_p17896448533"></a>Tag</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.23457654234577%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000001055701144_p1278917444539"><a name="en-us_topic_0000001055701144_p1278917444539"></a><a name="en-us_topic_0000001055701144_p1278917444539"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001055701144_row167901244115315"><td class="cellrowborder" valign="top" width="35.5064493550645%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001055701144_p87901744185316"><a name="en-us_topic_0000001055701144_p87901744185316"></a><a name="en-us_topic_0000001055701144_p87901744185316"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.258974102589741%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001055701144_p15790184410536"><a name="en-us_topic_0000001055701144_p15790184410536"></a><a name="en-us_topic_0000001055701144_p15790184410536"></a>0.0.3</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.23457654234577%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001055701144_p15790124416531"><a name="en-us_topic_0000001055701144_p15790124416531"></a><a name="en-us_topic_0000001055701144_p15790124416531"></a>The build environment for the <span id="en-us_topic_0000001055701144_text1245263410345"><a name="en-us_topic_0000001055701144_text1245263410345"></a><a name="en-us_topic_0000001055701144_text1245263410345"></a>OpenHarmony</span> version has been pre-installed.</p>
    </td>
    </tr>
    </tbody>
    </table>


### HPM-based Docker<a name="en-us_topic_0000001055701144_section580016182283"></a>

**docker\_dist**  is a template component in the  [HPM](https://hpm.harmonyos.com/#/en/home)  system. It helps to quickly initialize an HPM project and use the Docker image to quickly build a distribution of OpenHarmony, greatly simplifying environment configurations needed for building. After configuring the Ubuntu and  [hpm-cli](https://device.harmonyos.com/en/docs/develop/bundles/oem_bundle_guide_prepare-0000001050129846)  development environments, perform the following steps to access the Docker environment:

**Setting Up the Docker Environment**

1.  Initialize the installation template by running the following command in any of the working directories:

    ```
    hpm init -t @ohos/docker_dist
    ```

2.  Modify the  **publishAs**  field.

    Open the  **bundle.json**  file in the current directory and change the value of  **publishAs**  from  **template**  to  **distribution**  as needed.

3.  Select the desired solution, and set the environment variables for the solution distribution.

    -   **Linux**

    ip\_camera\_hi3516dv300:

    ```
    export solution=@ohos/ip_camera_hi3516dv300 
    ```

    ip\_camera\_hi3518ev300:

    ```
    export solution=@ohos/ip_camera_hi3518ev300 
    ```

    wifiiot:

    ```
    export solution=@ohos/wifi_iot 
    ```

    -   **Windows**

    Run the following Windows CMD command:

    ```
    set solution=Distribution name
    ```


**Building**

Start building. The following takes ip\_camera\_hi3518ev300 as an example. Docker can be automatically installed only on Ubuntu. If you are using any other operating system, manually install Docker before pulling the image.

-   **Automatically Installing Docker \(Ubuntu\)**

    Running the following command will automatically install the Docker, pull the image, and start the pulling and building of the corresponding solution in the container.

    ```
    hpm run docker 
    ```

    The following will be displayed if the building is successful:

    ```
    ......
    ohos ipcamera_hi3518 build success!
    @ohos/ip_camera_hi3518ev300: distribution building completed.
    ```


-   **Manually Installing Docker \(Non-Ubuntu\)**

    Perform the following operations to install Docker:

    ```
    # Pull the image.
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.2
    # Build the distribution on Linux.
    hpm run distWithDocker 
    # When using Windows, make sure to configure the Git Bash.
    hpm config set shellPath "Git Bash path"
    hpm run distWithDocker
    ```


### Standalone Docker Environment<a name="en-us_topic_0000001055701144_section319412277287"></a>

The Docker image of OpenHarmony is hosted on  [HUAWEI Cloud SWR](https://auth.huaweicloud.com/authui/login.html?service=https%3A%2F%2Fconsole.huaweicloud.com%2Fswr%2F%3Fregion%3Dcn-south-1%26cloud_route_state%3D%2Fapp%2Fwarehouse%2FwarehouseMangeDetail%2Fgoldensir%2Fopenharmony-docker%2Fopenharmony-docker%3Ftype%3DownImage&locale=en-us#/login). Using the Docker image will help simplify environment configurations needed for the building. After configuring the development environments, perform the steps below to access the Docker environment. The following steps use Ubuntu as an example \(Windows is also supported\).

### Setting Up the Docker Environment<a name="en-us_topic_0000001055701144_section436042904715"></a>

**Method 1: Obtaining the Docker image from HuaweiCloud SWR**

1.  Obtain the Docker image.

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3
    ```

2.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3
    ```


**Method 2: Using the Dockerfile to Build a Local Docker Image**

1.  Obtain the Dockerfile script for a local Docker image.

    ```
    git clone https://gitee.com/openharmony/docs.git
    ```

2.  Go to the directory of the Dockerfile code and run the following command to build the Docker image:

    ```
    cd docs/docker
    ./build.sh
    ```

3.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony openharmony-docker:0.0.3
    ```


### Building for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)<a name="en-us_topic_0000001055701144_section19121250134716"></a>

The following uses the Hi3516 platform as an example to describe the build procedure. Run the following build scripts to start building:

1.  Run the following command in the root directory of the source code to install hb:

    ```
    python3 -m pip install --user build/lite
    ```

2.  Set the build path to the current path.

    ```
    hb set
     .
    ```

    **Figure  1**  Setting page<a name="en-us_topic_0000001055701144_fig18712183616135"></a>  
    

    ![](figures/en-us_image_0000001084080634.png)

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The mapping between the development board and the building GUI:
    >-   Hi3861: wifiiot\_hispark\_pegasus@hisilicon
    >-   Hi3516: ipcamera\_hispark\_taurus@hisilicon
    >-   Hi3518: ipcamera\_hispark\_aries@hisilicon

3.  Select  **ipcamera\_hispark\_taurus@hisilicon**  and press  **Enter**.
4.  Start building.

    ```
    hb build -f
    ```

5.  View the build result.

    The files will be generated in the  **out/hispark\_taurus/ipcamera\_hispark\_taurus**  directory.


### Setting Up the Docker Environment for Large-System Devices \(reference memory ≥ 1 GB\)<a name="en-us_topic_0000001055701144_section776616712419"></a>

**Method 1: Obtaining the Docker image from HuaweiCloud SWR**

1.  Obtain the Docker image.

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3
    ```

2.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3
    ```


**Method 2: Using the Dockerfile to Build a Local Docker Image**

1.  Obtain the Dockerfile script for a local Docker image.

    ```
    git clone https://gitee.com/openharmony/docs.git
    ```

2.  Go to the directory of the Dockerfile code and run the following command to build the Docker image:

    ```
    cd docs/docker
    ./build.sh
    ```

3.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony openharmony-docker:0.0.3
    ```


## Acquiring the Device Development Tool \(HUAWEI DevEco Device Tool\)<a name="en-us_topic_0000001055701144_section2452141120244"></a>

HUAWEI DevEco Device Tool is a one-stop integrated development environment \(IDE\) provided to develop applications for HarmonyOS-based smart devices. It allows on-demand customization of HarmonyOS components, code editing, compilation, burning, and debugging, and supports C and C++ languages. This tool is installed in Visual Studio Code as a plug-in. For details, see  [Tool Acquisition](https://device.harmonyos.com/en/ide)  and  [HUAWEI DevEco Device Tool User Guide](https://device.harmonyos.com/en/docs/ide/user-guides/service_introduction-0000001050166905).

## Acquiring the Application Development Tool \(HUAWEI DevEco Studio\)<a name="en-us_topic_0000001055701144_section0904101019258"></a>

HUAWEI DevEco Studio \(DevEco Studio for short\) is a one-stop IDE oriented to Huawei devices in all scenarios. It provides E2E HarmonyOS application development services, ranging from project template creation to development, compilation, debugging, and release. With DevEco Studio, you will be able to efficiently develop HarmonyOS applications with distributed capabilities while speeding up innovation. For details, see  [Tool Acquisition](https://developer.harmonyos.com/en/develop/deveco-studio)  and  [HUAWEI DevEco Studio User Guide](https://developer.harmonyos.com/en/docs/documentation/doc-guides/tools_overview-0000001053582387).

