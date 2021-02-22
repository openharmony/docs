# Tool Acquisition<a name="EN-US_TOPIC_0000001055701144"></a>

-   [Using Docker to Prepare the Build Environment](#section107932281315)
    -   [HPM-based Docker](#section054931895313)
    -   [Standalone Docker Environment](#section980782720014)

-   [Using a Software Package to Prepare the Build Environment](#section18750162432511)
-   [Acquiring the Device Development Tool \(HUAWEI DevEco Device Tool\)](#section12307171315108)
-   [Tool Introduction](#section68281728193514)
-   [Website](#section13785205443514)
-   [Usage Guidelines](#section14919195917361)
-   [Acquiring the Application Development Tool \(HUAWEI DevEco Studio\)](#section5472125503411)
-   [Tool Introduction](#section17935101224620)
-   [Website](#section1572093543613)
-   [Usage Guidelines](#section1125615298385)

## Using Docker to Prepare the Build Environment<a name="section107932281315"></a>

OpenHarmony provides the following two types of Docker environments for you to quickly get the development environment ready:

-   HPM-based Docker environment: applicable when using the HarmonyOS Package Manager \(HPM\) to build a distribution.
-   Standalone Docker environment: applicable when using Ubuntu or Windows to build a distribution.

    The following table lists container-based options needed for building in the standalone Docker environment.

    **Table  1**  Docker image

    <a name="table2790164495315"></a>
    <table><thead align="left"><tr id="row3790644155317"><th class="cellrowborder" valign="top" width="17.97%" id="mcps1.2.5.1.1"><p id="p127896443535"><a name="p127896443535"></a><a name="p127896443535"></a>Compatible Hardware Platform</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.110000000000003%" id="mcps1.2.5.1.2"><p id="p8789114445316"><a name="p8789114445316"></a><a name="p8789114445316"></a>Docker Image Repository</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.43%" id="mcps1.2.5.1.3"><p id="p17896448533"><a name="p17896448533"></a><a name="p17896448533"></a>Tag</p>
    </th>
    <th class="cellrowborder" valign="top" width="44.49%" id="mcps1.2.5.1.4"><p id="p1278917444539"><a name="p1278917444539"></a><a name="p1278917444539"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167901244115315"><td class="cellrowborder" valign="top" width="17.97%" headers="mcps1.2.5.1.1 "><p id="p6790144155314"><a name="p6790144155314"></a><a name="p6790144155314"></a>Hi3861/Hi3516/Hi3518</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.110000000000003%" headers="mcps1.2.5.1.2 "><p id="p87901744185316"><a name="p87901744185316"></a><a name="p87901744185316"></a>swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.2.5.1.3 "><p id="p15790184410536"><a name="p15790184410536"></a><a name="p15790184410536"></a>0.0.2</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.49%" headers="mcps1.2.5.1.4 "><p id="p15790124416531"><a name="p15790124416531"></a><a name="p15790124416531"></a>The build environment for the <span id="text895113715412"><a name="text895113715412"></a><a name="text895113715412"></a>OpenHarmony</span> version has been pre-installed.</p>
    </td>
    </tr>
    </tbody>
    </table>


### HPM-based Docker<a name="section054931895313"></a>

**docker\_dist**  is a template component in the  [HPM](https://hpm.harmonyos.com/#/en/home)  system. It helps to quickly initialize an HPM project and use the Docker image to quickly build a distribution of OpenHarmony, greatly simplifying environment configurations needed for building. After configuring the Ubuntu and  [hpm-cli](https://device.harmonyos.com/en/docs/develop/bundles/oem_bundle_guide_prepare-0000001050129846)  development environments, perform the following steps to access the Docker environment:

**Setting Up the Docker Environment**

1.  Initialize the installation template by running the following command in any of the working directories:

    ```
    hpm init -t @ohos/docker_dist
    ```

2.  Modify the  **publishAs**  field.

    Open the  **bundle.json**  file in the current directory and change the value of  **publishAs**  from  **template**  to  **distribution**  as needed.

3.  Select the desired solution, and set the environment variables for the solution distribution.

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

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >If you use the Windows command line, run the following command instead:
    >```
    >set solution=Distribution name
    >```


**Building**

Start building. The following takes ip\_camera\_hi3518ev300 as an example.

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

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>Docker can be automatically installed only on Ubuntu. If you are using any other operating system, manually install Docker before pulling the image. The operations are as follows:
>```
># Pull the image.
>docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.2
># Build the distribution on Linux.
>hpm run distWithDocker 
># When using Windows, make sure to configure the Git Bash.
>hpm config set shellPath "Git Bash path"
>hpm run distWithDocker
>```

### Standalone Docker Environment<a name="section980782720014"></a>

The Docker image of OpenHarmony is hosted on  [HUAWEI Cloud SWR](https://auth.huaweicloud.com/authui/login.html?service=https%3A%2F%2Fconsole.huaweicloud.com%2Fswr%2F%3Fregion%3Dcn-south-1%26cloud_route_state%3D%2Fapp%2Fwarehouse%2FwarehouseMangeDetail%2Fgoldensir%2Fopenharmony-docker%2Fopenharmony-docker%3Ftype%3DownImage&locale=en-us#/login). Using the Docker image will help simplify environment configurations needed for the building. After configuring the development environments, perform the steps below to access the Docker environment. The following steps use Ubuntu as an example \(Windows is also supported\).

**Method 1: Obtaining the Docker image from HuaweiCloud SWR**

1.  Obtain the Docker image.

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.2
    ```

2.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker:0.0.2
    ```

3.  Use the following build script to start the building for the wifiiot, ipcamera\_hi3516dv300, and ipcamera\_hi3518ev300 platforms.

    ```
    python build.py wifiiot/ipcamera_hi3516dv300/ipcamera_hi3518ev300
    ```

    ```

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
    docker run -it -v $(pwd):/home/openharmony openharmony-docker:0.0.2
    ```

4.  Use the following build script to start the building for the wifiiot, ipcamera\_hi3516dv300, and ipcamera\_hi3518ev300 platforms.

    ```
    python build.py wifiiot/ipcamera_hi3516dv300/ipcamera_hi3518ev300
    ```


## Using a Software Package to Prepare the Build Environment<a name="section18750162432511"></a>

If you do not use Docker, use a software package instead to install the compilation environment. Specially, download some compilation toolchains from the image sites listed in the following table.

For details about how to download and install all compilation tools, see  [Setting Up the Hi3861 Development Environment](../quick-start/setting-up-the-hi3861-development-environment.md),  [Setting Up the Hi3516 Development Environment](../quick-start/setting-up-the-hi3516-development-environment.md), or  [Setting Up the Hi3518 Development Environment](../quick-start/setting-up-the-hi3518-development-environment.md)  in  _Quick Start_.

**Table  2**  Acquiring compilation toolchain

<a name="table167961324122511"></a>
<table><thead align="left"><tr id="row87941124202517"><th class="cellrowborder" valign="top" width="16.35%" id="mcps1.2.6.1.1"><p id="p12231193484318"><a name="p12231193484318"></a><a name="p12231193484318"></a>Development Board</p>
</th>
<th class="cellrowborder" valign="top" width="10.93%" id="mcps1.2.6.1.2"><p id="p77943248257"><a name="p77943248257"></a><a name="p77943248257"></a>Content</p>
</th>
<th class="cellrowborder" valign="top" width="8.08%" id="mcps1.2.6.1.3"><p id="p879422415251"><a name="p879422415251"></a><a name="p879422415251"></a>Version Information</p>
</th>
<th class="cellrowborder" valign="top" width="7.95%" id="mcps1.2.6.1.4"><p id="p1379420242252"><a name="p1379420242252"></a><a name="p1379420242252"></a>Site</p>
</th>
<th class="cellrowborder" valign="top" width="56.69%" id="mcps1.2.6.1.5"><p id="p479442462518"><a name="p479442462518"></a><a name="p479442462518"></a>SHA-256 Verification Code</p>
</th>
</tr>
</thead>
<tbody><tr id="row2795202472514"><td class="cellrowborder" valign="top" width="16.35%" headers="mcps1.2.6.1.1 "><p id="p16361494412"><a name="p16361494412"></a><a name="p16361494412"></a>Hi3861</p>
</td>
<td class="cellrowborder" valign="top" width="10.93%" headers="mcps1.2.6.1.2 "><p id="p479592415257"><a name="p479592415257"></a><a name="p479592415257"></a>gcc_riscv32</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.2.6.1.3 "><p id="p1679522412514"><a name="p1679522412514"></a><a name="p1679522412514"></a>7.3.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.95%" headers="mcps1.2.6.1.4 "><p id="p13795192412258"><a name="p13795192412258"></a><a name="p13795192412258"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/gcc_riscv32/7.3.0/linux/gcc_riscv32-linux-7.3.0.tar.gz" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.2.6.1.5 "><p id="p7795124152510"><a name="p7795124152510"></a><a name="p7795124152510"></a>966fd4fda68d9886b828e6eef3ac3620806a34d3bccba4020a2ef07d9b8b8826</p>
</td>
</tr>
<tr id="row37951424102514"><td class="cellrowborder" valign="top" width="16.35%" headers="mcps1.2.6.1.1 "><p id="p9871246124413"><a name="p9871246124413"></a><a name="p9871246124413"></a>Hi3861, Hi3516, and Hi3518</p>
</td>
<td class="cellrowborder" valign="top" width="10.93%" headers="mcps1.2.6.1.2 "><p id="p8795524122517"><a name="p8795524122517"></a><a name="p8795524122517"></a>gn</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.2.6.1.3 "><p id="p127951624182514"><a name="p127951624182514"></a><a name="p127951624182514"></a>1523</p>
</td>
<td class="cellrowborder" valign="top" width="7.95%" headers="mcps1.2.6.1.4 "><p id="p47957245252"><a name="p47957245252"></a><a name="p47957245252"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.2.6.1.5 "><p id="p9795192402516"><a name="p9795192402516"></a><a name="p9795192402516"></a>50a5a5ba5877dd0ec8afcb23d3dd4d966a16403c29cd80a4002230241d32ef34</p>
</td>
</tr>
<tr id="row10796824122514"><td class="cellrowborder" valign="top" width="16.35%" headers="mcps1.2.6.1.1 "><p id="p1235855210444"><a name="p1235855210444"></a><a name="p1235855210444"></a>Hi3861, Hi3516, and Hi3518</p>
</td>
<td class="cellrowborder" valign="top" width="10.93%" headers="mcps1.2.6.1.2 "><p id="p379532414251"><a name="p379532414251"></a><a name="p379532414251"></a>ninja</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.2.6.1.3 "><p id="p17952245256"><a name="p17952245256"></a><a name="p17952245256"></a>1.9.0</p>
</td>
<td class="cellrowborder" valign="top" width="7.95%" headers="mcps1.2.6.1.4 "><p id="p12796172442519"><a name="p12796172442519"></a><a name="p12796172442519"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.2.6.1.5 "><p id="p479692492515"><a name="p479692492515"></a><a name="p479692492515"></a>b4a4ba21e94ff77634e1f88697a00b6f498fdbc0b40d7649df1b246b285874f9</p>
</td>
</tr>
<tr id="row2524115316467"><td class="cellrowborder" valign="top" width="16.35%" headers="mcps1.2.6.1.1 "><p id="p162311934144313"><a name="p162311934144313"></a><a name="p162311934144313"></a>Hi3516 and Hi3518</p>
</td>
<td class="cellrowborder" valign="top" width="10.93%" headers="mcps1.2.6.1.2 "><p id="p20794162412258"><a name="p20794162412258"></a><a name="p20794162412258"></a>llvm</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.2.6.1.3 "><p id="p47941224122519"><a name="p47941224122519"></a><a name="p47941224122519"></a>9.0.0-36191</p>
</td>
<td class="cellrowborder" valign="top" width="7.95%" headers="mcps1.2.6.1.4 "><p id="p1379532412256"><a name="p1379532412256"></a><a name="p1379532412256"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.2.6.1.5 "><p id="p15795112414255"><a name="p15795112414255"></a><a name="p15795112414255"></a>a32e467e4bb56b2b48f55b97809d7a246a9482337a948d76f1064b10bc2fb9f3</p>
</td>
</tr>
<tr id="row1179642422512"><td class="cellrowborder" valign="top" width="16.35%" headers="mcps1.2.6.1.1 "><p id="p172311534134318"><a name="p172311534134318"></a><a name="p172311534134318"></a>Hi3516 and Hi3518</p>
</td>
<td class="cellrowborder" valign="top" width="10.93%" headers="mcps1.2.6.1.2 "><p id="p127962247255"><a name="p127962247255"></a><a name="p127962247255"></a>hc-gen</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.2.6.1.3 "><p id="p8796424152514"><a name="p8796424152514"></a><a name="p8796424152514"></a>0.65</p>
</td>
<td class="cellrowborder" valign="top" width="7.95%" headers="mcps1.2.6.1.4 "><p id="p7796624192517"><a name="p7796624192517"></a><a name="p7796624192517"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar" target="_blank" rel="noopener noreferrer">Site</a></p>
</td>
<td class="cellrowborder" valign="top" width="56.69%" headers="mcps1.2.6.1.5 "><p id="p679682402514"><a name="p679682402514"></a><a name="p679682402514"></a>fcfee489371947a464fe41a4b45a897b9a44155891a957f15bad2e157c750162</p>
</td>
</tr>
</tbody>
</table>

You need to check whether these tools are downloaded from the official channel.

1.  Run the following command in the Ubuntu environment to generate an SHA256 digest:

    ```
    #> sha256sum file name
    ```

    If the  **sha256sum**  tool is unavailable, install it as prompted by the Ubuntu command.

2.  Compare the generated digest with the officially provided one.

    If they are consistent, the tool package you downloaded has not been tampered with. Otherwise, your package may be insecure.


## Acquiring the Device Development Tool \(HUAWEI DevEco Device Tool\)<a name="section12307171315108"></a>

## Tool Introduction<a name="section68281728193514"></a>

HUAWEI DevEco Device Tool \(DevEco Device Tool for short\) is a one-stop integrated development environment \(IDE\) provided for developers of OpenHarmony-based smart devices. It allows on-demand customization of OpenHarmony components, code editing, compilation, burning, and debugging, and supports C and C++ languages. DevEco Device Tool is installed in Visual Studio Code as a plug-in.

## Website<a name="section13785205443514"></a>

[https://device.harmonyos.com/en/ide](https://device.harmonyos.com/en/ide)

## Usage Guidelines<a name="section14919195917361"></a>

[https://device.harmonyos.com/en/docs/ide/user-guides/service\_introduction-0000001050166905](https://device.harmonyos.com/en/docs/ide/user-guides/service_introduction-0000001050166905)

## Acquiring the Application Development Tool \(HUAWEI DevEco Studio\)<a name="section5472125503411"></a>

## Tool Introduction<a name="section17935101224620"></a>

HUAWEI DevEco Studio \(DevEco Studio for short\) is a one-stop IDE oriented to Huawei devices in all scenarios. It allows you to create project templates, and develop, build, debug, and release OpenHarmony applications from end to end. DevEco Studio enables you to efficiently develop applications with OpenHarmony distributed capabilities, thereby empowering you to innovate applications.

## Website<a name="section1572093543613"></a>

[https://developer.harmonyos.com/en/develop/deveco-studio](https://developer.harmonyos.com/en/develop/deveco-studio)

## Usage Guidelines<a name="section1125615298385"></a>

[https://developer.harmonyos.com/en/docs/documentation/doc-guides/tools\_overview-0000001053582387](https://developer.harmonyos.com/en/docs/documentation/doc-guides/tools_overview-0000001053582387)

