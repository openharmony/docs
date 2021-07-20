# Docker Environment<a name="EN-US_TOPIC_0000001055701144"></a>

-   [Introduction](#section107932281315)
-   [Preparations](#section7337134183512)
-   [Standalone Docker Environment](#section2858536103611)
    -   [Setting Up the Docker Environment for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)](#section319412277287)
    -   [Building for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)](#section631485163615)
    -   [Setting Up the Docker Environment for Standard-System Devices \(reference memory ≥ 128 MB\)](#section13585262391)
    -   [Building for Standard-System Devices \(reference memory ≥ 128 MB\)](#section193711513406)

-   [HPM-based Docker Environment](#section485713518337)
    -   [Setting Up the Docker Environment](#section3295842510)
    -   [Obtaining and Building Source Code](#section69141039143518)


## Introduction<a name="section107932281315"></a>

OpenHarmony provides the following two types of Docker environments for you to quickly get the development environment ready:

-   Standalone Docker environment: applicable when using Ubuntu or Windows to build a distribution
-   HPM-based Docker environment: applicable when using the HarmonyOS Package Manager \(HPM\) to build a distribution

**Table  1**  Docker image

<a name="table11986917191214"></a>
<table><thead align="left"><tr id="row149861417121215"><th class="cellrowborder" valign="top" width="15.831583158315832%" id="mcps1.2.6.1.1"><p id="p798611714124"><a name="p798611714124"></a><a name="p798611714124"></a>Docker Environment</p>
</th>
<th class="cellrowborder" valign="top" width="13.97139713971397%" id="mcps1.2.6.1.2"><p id="p1698661751219"><a name="p1698661751219"></a><a name="p1698661751219"></a>System Type</p>
</th>
<th class="cellrowborder" valign="top" width="18.61186118611861%" id="mcps1.2.6.1.3"><p id="p1798671761217"><a name="p1798671761217"></a><a name="p1798671761217"></a>Operating Platform</p>
</th>
<th class="cellrowborder" valign="top" width="35.8935893589359%" id="mcps1.2.6.1.4"><p id="p20526205414295"><a name="p20526205414295"></a><a name="p20526205414295"></a>Docker Image Repository</p>
</th>
<th class="cellrowborder" valign="top" width="15.69156915691569%" id="mcps1.2.6.1.5"><p id="p1833001309"><a name="p1833001309"></a><a name="p1833001309"></a>Tag</p>
</th>
</tr>
</thead>
<tbody><tr id="row1798661751216"><td class="cellrowborder" rowspan="2" align="center" valign="top" width="15.831583158315832%" headers="mcps1.2.6.1.1 "><p id="p1898631791213"><a name="p1898631791213"></a><a name="p1898631791213"></a>Standalone Docker environment</p>
</td>
<td class="cellrowborder" valign="top" width="13.97139713971397%" headers="mcps1.2.6.1.2 "><p id="p1598617177128"><a name="p1598617177128"></a><a name="p1598617177128"></a>Mini and small systems</p>
</td>
<td class="cellrowborder" valign="top" width="18.61186118611861%" headers="mcps1.2.6.1.3 "><p id="p898614178122"><a name="p898614178122"></a><a name="p898614178122"></a>Ubuntu or Windows</p>
</td>
<td class="cellrowborder" valign="top" width="35.8935893589359%" headers="mcps1.2.6.1.4 "><p id="p12667431305"><a name="p12667431305"></a><a name="p12667431305"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker</p>
</td>
<td class="cellrowborder" valign="top" width="15.69156915691569%" headers="mcps1.2.6.1.5 "><p id="p143320173017"><a name="p143320173017"></a><a name="p143320173017"></a>0.0.5</p>
</td>
</tr>
<tr id="row998612174129"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1998617172126"><a name="p1998617172126"></a><a name="p1998617172126"></a>Standard system</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1598641741215"><a name="p1598641741215"></a><a name="p1598641741215"></a>Ubuntu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p552616549297"><a name="p552616549297"></a><a name="p552616549297"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p1633303300"><a name="p1633303300"></a><a name="p1633303300"></a>0.0.1</p>
</td>
</tr>
<tr id="row5986201731214"><td class="cellrowborder" align="center" valign="top" width="15.831583158315832%" headers="mcps1.2.6.1.1 "><p id="p136981216143"><a name="p136981216143"></a><a name="p136981216143"></a>HPM-based Docker environment</p>
</td>
<td class="cellrowborder" valign="top" width="13.97139713971397%" headers="mcps1.2.6.1.2 "><p id="p969831161416"><a name="p969831161416"></a><a name="p969831161416"></a>Mini and small systems</p>
</td>
<td class="cellrowborder" valign="top" width="18.61186118611861%" headers="mcps1.2.6.1.3 "><p id="p18821161052214"><a name="p18821161052214"></a><a name="p18821161052214"></a>Ubuntu or Windows</p>
</td>
<td class="cellrowborder" valign="top" width="35.8935893589359%" headers="mcps1.2.6.1.4 "><p id="p1652616548294"><a name="p1652616548294"></a><a name="p1652616548294"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker</p>
</td>
<td class="cellrowborder" valign="top" width="15.69156915691569%" headers="mcps1.2.6.1.5 "><p id="p1433130173010"><a name="p1433130173010"></a><a name="p1433130173010"></a>0.0.3</p>
</td>
</tr>
</tbody>
</table>

## Preparations<a name="section7337134183512"></a>

Before using the Docker environment, perform the following operations:

1.  Install Docker. For details, see  [Install Docker Engine](https://docs.docker.com/engine/install/).
2.  Obtain the OpenHarmony source code. For details, see  [Source Code Acquisition](sourcecode-acquire.md).

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >You do not need to obtain the source code for the HPM-based Docker environment.


## Standalone Docker Environment<a name="section2858536103611"></a>

The Docker image of OpenHarmony is hosted on  [HUAWEI CLOUD SWR](https://console.huaweicloud.com/swr/?region=cn-south-1&locale=en-us#/app/warehouse/warehouseMangeDetail/goldensir/openharmony-docker/openharmony-docker?type=ownImage). Using the Docker image will help simplify environment configurations needed for the building. The following describes the detailed procedure.

### Setting Up the Docker Environment for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)<a name="section319412277287"></a>

**Method 1: Obtaining the Docker image from HUAWEI CLOUD SWR**

1.  Obtain the Docker image.

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.5
    ```

2.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    Run the following command in Ubuntu:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.5
    ```

    Run the following command in Windows \(assuming that the source code directory is  **D:\\OpenHarmony**\):

    ```
    docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.5
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

    Run the following command in Ubuntu:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.5
    ```

    Run the following command in Windows \(assuming that the source code directory is  **D:\\OpenHarmony**\):

    ```
    docker run -it -v D:\OpenHarmony:/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.5
    ```


### Building for Mini-System Devices \(reference memory ≥ 128 KB\) and Small-System Devices \(reference memory ≥ 1 MB\)<a name="section631485163615"></a>

The following uses the Hi3516 platform as an example to describe the build procedure.

Set the build path to the current path.

```
hb set
 .
```

**Figure  1**  Setting page<a name="fig18712183616135"></a>  


![](figure/en-us_image_0000001101413884.png)

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
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

2.  Run the following script to start building for standard-system devices \(reference memory ≥ 128 MB\).

    ```
    ./build.sh --product-name {product_name}
    ```

    **product\_name**  indicates the platform supported by the current distribution, for example, Hi3516D V300.

    Files generated during building are stored in the  **out/ohos-arm-release/**  directory, and the generated image is stored in the  **out/ohos-arm-release/packages/phone/images/**  directory.


>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>You can exit Docker by simply running the  **exit**  command.

## HPM-based Docker Environment<a name="section485713518337"></a>

**docker\_dist**  is a template component in the  [HPM](https://hpm.harmonyos.com/#/en/home)  system. It helps to quickly initialize an HPM project and use the Docker image to quickly build a distribution of OpenHarmony, greatly simplifying environment configurations needed for building. After configuring the Ubuntu and  [hpm-cli](../bundles/bundles-guide-prepare.md)  development environments, perform the following steps to access the Docker environment:

### Setting Up the Docker Environment<a name="section3295842510"></a>

1.  Initialize the installation template by running the following command in any of the working directories:

    ```
    hpm init -t @ohos/docker_dist
    ```

2.  Modify the  **publishAs**  field.

    The obtained bundle is of the template type. Open the  **bundle.json**  file in the current directory and change the value of  **publishAs**  from  **template**  to  **distribution**  as needed.


### Obtaining and Building Source Code<a name="section69141039143518"></a>

Start building. Docker can be automatically installed only in Ubuntu. If you are using any other operating system, manually install Docker before pulling the image.

-   **Automatically Installing Docker \(Ubuntu\)**

    Running the following command will automatically install Docker, pull the Docker image, and start the pulling and building of the corresponding solution in the container.

    **Method 1:**

    Add a parameter to specify the solution. For example:

    ```
    hpm run docker solution={product}
    ```

    **\{product\}**  indicates the solution, for example,  **@ohos/hispark\_taurus**,  **@ohos/hispark\_aries**, and  **@ohos/hispark\_pegasus**.

    **Method 2:**

    Set an environment variable to specify the solution, and then run the build command.

    1.  Select the desired solution.

        ```
        export solution={product}
        ```

        **\{product\}**  indicates the solution, for example,  **@ohos/hispark\_taurus**,  **@ohos/hispark\_aries**, and  **@ohos/hispark\_pegasus**.

    2.  Obtain and build the source code.

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


