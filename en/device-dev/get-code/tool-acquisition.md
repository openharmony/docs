# Tool Acquisition<a name="EN-US_TOPIC_0000001055701144"></a>

-   [How to Obtain the Docker Environment](#section107932281315)
-   [HPM-based Docker](#section485713518337)
    -   [Setting Up the Docker Environment](#section18957202218355)
    -   [Building](#section69141039143518)

-   [Standalone Docker Environment](#section2858536103611)
    -   [Setting Up the Docker Environment for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)](#section319412277287)
    -   [Building for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)](#section631485163615)
    -   [Setting Up the Docker Environment for Standard-System Devices \(reference memory ≥ 128 MB\)](#section13585262391)
    -   [Building for Standard-System Devices \(reference memory ≥ 128 MB\)](#section193711513406)

-   [Acquiring the Device Development Tool \(HUAWEI DevEco Device Tool\)](#section2452141120244)
-   [Acquiring the Application Development Tool \(HUAWEI DevEco Studio\)](#section0904101019258)

## How to Obtain the Docker Environment<a name="section107932281315"></a>

OpenHarmony provides the following two types of Docker environments for you to quickly get the development environment ready:

-   HPM-based Docker environment: applicable when using the HarmonyOS Package Manager \(HPM\) to build a distribution.
-   Standalone Docker environment: applicable when using Ubuntu or Windows to build a distribution.

    The following table lists container-based options needed for building in the standalone Docker environment.

    **Table  1**  Docker image

    <a name="table2790164495315"></a>
    <table><thead align="left"><tr id="row3790644155317"><th class="cellrowborder" valign="top" width="35.5064493550645%" id="mcps1.2.4.1.1"><p id="p8789114445316"><a name="p8789114445316"></a><a name="p8789114445316"></a>Docker Image Repository</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.258974102589741%" id="mcps1.2.4.1.2"><p id="p17896448533"><a name="p17896448533"></a><a name="p17896448533"></a>Tag</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.23457654234577%" id="mcps1.2.4.1.3"><p id="p1278917444539"><a name="p1278917444539"></a><a name="p1278917444539"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167901244115315"><td class="cellrowborder" valign="top" width="35.5064493550645%" headers="mcps1.2.4.1.1 "><p id="p87901744185316"><a name="p87901744185316"></a><a name="p87901744185316"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.258974102589741%" headers="mcps1.2.4.1.2 "><p id="p15790184410536"><a name="p15790184410536"></a><a name="p15790184410536"></a>0.0.5</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.23457654234577%" headers="mcps1.2.4.1.3 "><p id="p15790124416531"><a name="p15790124416531"></a><a name="p15790124416531"></a>The <span id="text929334781813"><a name="text929334781813"></a><a name="text929334781813"></a>OpenHarmony</span> build environment has been pre-installed. This repository applies to <span id="text167042559153"><a name="text167042559153"></a><a name="text167042559153"></a>Mini-System Devices (reference memory ≥ 128 KB)</span> and <span id="text358943111611"><a name="text358943111611"></a><a name="text358943111611"></a>Small-System Devices (reference memory ≥ 1 MB)</span>.</p>
    </td>
    </tr>
    <tr id="row757355774214"><td class="cellrowborder" valign="top" width="35.5064493550645%" headers="mcps1.2.4.1.1 "><p id="p156285811425"><a name="p156285811425"></a><a name="p156285811425"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.258974102589741%" headers="mcps1.2.4.1.2 "><p id="p15562155818429"><a name="p15562155818429"></a><a name="p15562155818429"></a>0.0.1</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.23457654234577%" headers="mcps1.2.4.1.3 "><p id="p17562758184213"><a name="p17562758184213"></a><a name="p17562758184213"></a>The <span id="text956295819420"><a name="text956295819420"></a><a name="text956295819420"></a>OpenHarmony</span> build environment has been pre-installed. This repository applies to <span id="text17573710444"><a name="text17573710444"></a><a name="text17573710444"></a>Standard-System Devices (reference memory ≥ 128 MB)</span>.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >For details about how to install Docker, see  [Install Docker Engine on Ubuntu](https://docs.docker.com/engine/install/ubuntu/).


## HPM-based Docker<a name="section485713518337"></a>

**docker\_dist**  is a template component in the  [HPM](https://hpm.harmonyos.com/#/en/home)  system. It helps to quickly initialize an HPM project and use the Docker image to quickly build a distribution of OpenHarmony, greatly simplifying environment configurations needed for building. After configuring the Ubuntu and  [hpm-cli](https://device.harmonyos.com/en/docs/develop/bundles/oem_bundle_guide_prepare-0000001050129846)  development environments, perform the following steps to access the Docker environment:

### Setting Up the Docker Environment<a name="section18957202218355"></a>

1.  Initialize the installation template by running the following command in any of the working directories:

    ```
    hpm init -t @ohos/docker_dist
    ```

2.  Modify the  **publishAs**  field.

    The obtained bundle is of the template type. Open the  **bundle.json**  file in the current directory and change the value of  **publishAs**  from  **template**  to  **distribution**  as needed.


### Building<a name="section69141039143518"></a>

Start building. Docker can be automatically installed only on Ubuntu. If you are using any other operating system, manually install Docker before pulling the image.

-   **Automatically Installing Docker \(Ubuntu\)**

    Running the following command will automatically install Docker, pull the Docker image, and start the pulling and building of the corresponding solution in the container.

    Method 1:

    Add a parameter to specify the solution. For example:

    ```
    hpm run docker solution={product}
    ```

    **\{product\}**  indicates the solution, for example,  **@ohos/hispark\_taurus**,  **@ohos/hispark\_aries**, and  **@ohos/hispark\_pegasus**.

    Method 2:

    Set an environment variable to specify the solution, and then run the build command.

    1. Select the desired solution.

    ```
    export solution={product}
    ```

    **\{product\}**  indicates the solution, for example,  **@ohos/hispark\_taurus**,  **@ohos/hispark\_aries**, and  **@ohos/hispark\_pegasus**.

    2. Start building.

    ```
    hpm run docker
    ```

    This example uses the  **@ohos/hispark\_taurus**  solution for illustration. If the execution is successful, the output is as follows:

    ```
    ...
    ohos ipcamera_hispark_taurus build success!
    @ohos/hispark_taurus: distribution building completed.
    ```


-   **Manually Installing Docker \(Non-Ubuntu\)**

    Perform the following operations to install Docker:

    ```
    # Pull the image.
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.3# Compile the Docker image in the Linux environment.
    hpm run distWithDocker solution={product}
    # When using Windows, make sure to configure the Git Bash.
    hpm config set shellPath "Git Bash path"
    hpm run distWithDocker solution={product}
    ```


## Standalone Docker Environment<a name="section2858536103611"></a>

The Docker image of OpenHarmony is hosted on  [HUAWEI CLOUD SWR](https://console.huaweicloud.com/swr/?region=cn-south-1&locale=en-us#/app/warehouse/warehouseMangeDetail/goldensir/openharmony-docker/openharmony-docker?type=ownImage). Using the Docker image will help simplify environment configurations needed for the building. After configuring the development environments, perform the procedures below to access the Docker environment. Both Ubuntu and Windows are supported. The following procedures use Ubuntu as an example.

### Setting Up the Docker Environment for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)<a name="section319412277287"></a>

**Method 1: Obtaining the Docker image from HUAWEI CLOUD SWR**

1.  Obtain the Docker image.

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.5
    ```

2.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.5
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
    docker run -it -v $(pwd):/home/openharmony openharmony-docker:0.0.5
    ```


### Building for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)<a name="section631485163615"></a>

The following uses the Hi3516 platform as an example to describe the build procedure. Run the following build scripts to start building:

Set the build path to the current path.

```
hb set
 .
```

**Figure  1**  Setting page<a name="fig18712183616135"></a>  


![](figures/en-us_image_0000001101413884.png)

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>The mapping between the development board and the building GUI:
>-   Hi3861: wifiiot\_hispark\_pegasus@hisilicon
>-   Hi3516: ipcamera\_hispark\_taurus@hisilicon
>-   Hi3518: ipcamera\_hispark\_aries@hisilicon

1.  Select  **ipcamera\_hispark\_taurus@hisilicon**  and press  **Enter**.
2.  Start building.

    ```
    hb build -f
    ```

3.  View the build result.

    The files will be generated in the  **out/hispark\_taurus/ipcamera\_hispark\_taurus**  directory.


### Setting Up the Docker Environment for Standard-System Devices \(reference memory ≥ 128 MB\)<a name="section13585262391"></a>

**Method 1: Obtaining the Docker image from HUAWEI CLOUD SWR**

1.  Obtain the Docker image.

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.1
    ```

2.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.1
    ```


**Method 2: Using the Dockerfile to Build a Local Docker Image**

1.  Obtain the Dockerfile script for a local Docker image.

    ```
    git clone https://gitee.com/openharmony/docs.git
    ```

2.  Go to the directory of the Dockerfile code and run the following command to build the Docker image:

    ```
    cd docs/docker/standard
    ./build.sh
    ```

3.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony openharmony-docker-standard:0.0.1
    ```


### Building for Standard-System Devices \(reference memory ≥ 128 MB\)<a name="section193711513406"></a>

1.  Run the preprocessing script in the root directory of the source code.

    ```
    ../scripts/prepare.sh
    ```

2.  Run the following script to start building for Standard-System Devices \(reference memory ≥ 128 MB\).

    ```
    ./build.sh --product-name {product_name}
    ```

    **product\_name**  indicates the platform supported by the current distribution, for example, Hi3516D V300.

    Files generated during compilation are stored in the  **out/ohos-arm-release/**  directory, and the generated image is stored in the  **out/ohos-arm-release/packages/phone/images/**  directory.


>![](public_sys-resources/icon-note.gif) **NOTE:** 
>You can exit Docker by simply running the  **exit**  command.

## Acquiring the Device Development Tool \(HUAWEI DevEco Device Tool\)<a name="section2452141120244"></a>

HUAWEI DevEco Device Tool is a one-stop integrated development environment \(IDE\) provided to develop applications for OpenHarmony-based smart devices. It allows on-demand customization of OpenHarmony components, code editing, compilation, burning, and debugging, and supports C and C++ languages. This tool is installed in Visual Studio Code as a plug-in. For details, see  [Tool Acquisition](https://device.harmonyos.com/en/ide)  and  [HUAWEI DevEco Device Tool User Guide](https://device.harmonyos.com/en/docs/ide/user-guides/service_introduction-0000001050166905).

The roadmap of Huawei DevEco Device Tool for supporting OpenHarmony device development is shown in the figure below.

![](figures/3.png)

## Acquiring the Application Development Tool \(HUAWEI DevEco Studio\)<a name="section0904101019258"></a>

HUAWEI DevEco Studio \(DevEco Studio for short\) is a one-stop IDE oriented to Huawei devices in all scenarios. It provides E2E OpenHarmony application development services, ranging from project template creation to development, compilation, debugging, and release. With DevEco Studio, you will be able to efficiently develop OpenHarmony applications with distributed capabilities while speeding up innovation. For details, see  [Tool Acquisition](https://developer.harmonyos.com/en/develop/deveco-studio)  and  [HUAWEI DevEco Studio User Guide](https://developer.harmonyos.com/en/docs/documentation/doc-guides/tools_overview-0000001053582387).

