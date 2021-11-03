# Setting Up Ubuntu Development Environment<a name="EN-US_TOPIC_0000001174350605"></a>

-   [Obtaining Source Code and Tools](#section1897711811517)
-   [Obtaining Source Code](#section1545225464016)
-   [Installing Necessary Libraries and Tools](#section108201740181219)
-   [Installing Python3](#section1238412211211)
-   [Installing LLVM \(Required only for OpenHarmony\_v1.x\)](#section12202192215415)
-   [Installing hb](#section15794154618411)
    -   [Prerequisites](#section1083283711515)
    -   [Installation Procedure](#section11518484814)
    -   [Uninstalling hb](#section3512551574)


Operating system: 64-bit version of Ubuntu 16.04 or later.

Perform the following steps to set up the development environment:

1.  Obtain source code.
2.  Install necessary libraries and tools.
3.  Install Python3.
4.  Install LLVM \(required only for OpenHarmony\_v1.x\).
5.  Install hb.

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   Docker is provided for the Ubuntu build environment, which encapsulates related build tools. If you use Docker to prepare the build environment, you do not need to perform the following steps in this section. For details, see  [Using Docker to Prepare the Build Environment](../get-code/gettools-acquire.md#section107932281315).
>-   By default, basic software, such as Samba and Vim, is installed in the system. Adaptation on the software is required to support file sharing between the Linux server and the Windows workstation.
>-   For details about the compilation and building subsystem of OpenHarmony, see  [Compilation and Building Overview](../subsystems/subsys-build-mini-lite.md).

## Obtaining Source Code and Tools<a name="section1897711811517"></a>

The following table describes the tools and source code required for setting up the general environment for a Linux server and how to obtain these tools and the source code.

**Table  1**  Source code and development tools and their obtaining methods

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="25.779999999999998%" id="mcps1.2.4.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="30.819999999999997%" id="mcps1.2.4.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="43.4%" id="mcps1.2.4.1.3"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row45863354112"><td class="cellrowborder" valign="top" width="25.779999999999998%" headers="mcps1.2.4.1.1 "><p id="p3587173513117"><a name="p3587173513117"></a><a name="p3587173513117"></a>Source code</p>
</td>
<td class="cellrowborder" valign="top" width="30.819999999999997%" headers="mcps1.2.4.1.2 "><p id="p258713581118"><a name="p258713581118"></a><a name="p258713581118"></a>Develops functions.</p>
</td>
<td class="cellrowborder" valign="top" width="43.4%" headers="mcps1.2.4.1.3 "><p id="p16587835171114"><a name="p16587835171114"></a><a name="p16587835171114"></a>See <a href="../get-code/sourcecode-acquire.md">Source Code Acquisition</a>.</p>
</td>
</tr>
<tr id="row020505735919"><td class="cellrowborder" valign="top" width="25.779999999999998%" headers="mcps1.2.4.1.1 "><p id="p1220513576596"><a name="p1220513576596"></a><a name="p1220513576596"></a>Necessary libraries and tools</p>
</td>
<td class="cellrowborder" valign="top" width="30.819999999999997%" headers="mcps1.2.4.1.2 "><p id="p2206157145919"><a name="p2206157145919"></a><a name="p2206157145919"></a>Used for compilation (such as packaging and image creation).</p>
</td>
<td class="cellrowborder" valign="top" width="43.4%" headers="mcps1.2.4.1.3 "><p id="p920675719597"><a name="p920675719597"></a><a name="p920675719597"></a>Internet</p>
</td>
</tr>
<tr id="row430016273514"><td class="cellrowborder" valign="top" width="25.779999999999998%" headers="mcps1.2.4.1.1 "><p id="p330015271158"><a name="p330015271158"></a><a name="p330015271158"></a>Python3.7+</p>
</td>
<td class="cellrowborder" valign="top" width="30.819999999999997%" headers="mcps1.2.4.1.2 "><p id="p43003270510"><a name="p43003270510"></a><a name="p43003270510"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="43.4%" headers="mcps1.2.4.1.3 "><p id="p34760459518"><a name="p34760459518"></a><a name="p34760459518"></a>Internet</p>
</td>
</tr>
<tr id="row7531362055"><td class="cellrowborder" valign="top" width="25.779999999999998%" headers="mcps1.2.4.1.1 "><p id="p1467122152710"><a name="p1467122152710"></a><a name="p1467122152710"></a>LLVM (required only for OpenHarmony_v1.x)</p>
</td>
<td class="cellrowborder" valign="top" width="30.819999999999997%" headers="mcps1.2.4.1.2 "><p id="p1739432372718"><a name="p1739432372718"></a><a name="p1739432372718"></a>Functions as the compiler toolchain.</p>
</td>
<td class="cellrowborder" valign="top" width="43.4%" headers="mcps1.2.4.1.3 "><p id="p59711534202610"><a name="p59711534202610"></a><a name="p59711534202610"></a>Internet</p>
</td>
</tr>
<tr id="row1644079184919"><td class="cellrowborder" valign="top" width="25.779999999999998%" headers="mcps1.2.4.1.1 "><p id="p744115914493"><a name="p744115914493"></a><a name="p744115914493"></a>hb</p>
</td>
<td class="cellrowborder" valign="top" width="30.819999999999997%" headers="mcps1.2.4.1.2 "><p id="p1244114913492"><a name="p1244114913492"></a><a name="p1244114913492"></a>Compiles the <span id="text344823833918"><a name="text344823833918"></a><a name="text344823833918"></a>OpenHarmony</span> source code.</p>
</td>
<td class="cellrowborder" valign="top" width="43.4%" headers="mcps1.2.4.1.3 "><p id="p1463918124619"><a name="p1463918124619"></a><a name="p1463918124619"></a>Internet</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, you do not need to install compilation tools like  **gn**  and  **ninja**.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install compilation tools such as  **gn**,  **ninja**, and LLVM. When installing these tools, ensure that their environment variable paths are unique.

## Obtaining Source Code<a name="section1545225464016"></a>

You need to acquire  [source code](../get-code/sourcecode-acquire.md), download it on a Linux server, and decompress it.

## Installing Necessary Libraries and Tools<a name="section108201740181219"></a>

Run the following command to install the libraries and tools required for compilation:

```
sudo apt-get install build-essential gcc g++ make zlib* libffi-dev e2fsprogs pkg-config flex bison perl bc openssl libssl-dev libelf-dev libc6-dev-amd64 binutils binutils-dev libdwarf-dev u-boot-tools mtd-utils gcc-arm-linux-gnueabi cpio device-tree-compiler
```

## Installing Python3<a name="section1238412211211"></a>

1.  Start a Linux server.
2.  Run the following command to check the Python version:

    ```
    python3 --version
    ```

    If Python version is earlier than 3.7, reinstall Python. Do as follows to install Python, for example, Python 3.8.

    1.  Check the Ubuntu version.

        ```
        cat /etc/issue
        ```

    2.  Install Python based on the Ubuntu version.
        -   If the Ubuntu version is 18 or later, run the following command:

            ```
            sudo apt-get install python3.8
            ```

        -   If the Ubuntu version is 16, perform the following steps:

            a. Install dependency packages.

            ```
            sudo apt update && sudo apt install software-properties-common
            ```

            b. Add the source of deadsnakes PPA and press  **Enter**.

            ```
            sudo add-apt-repository ppa:deadsnakes/ppa
            ```

            c. Install Python 3.8.

            ```
            sudo apt upgrade && sudo apt install python3.8
            ```


3.  Set the soft link of  **python**  and  **python3**  to  **python3.8**.

    ```
    sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.8 1
    sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 1
    ```

4.  Install and upgrade the Python package management tool \(pip3\) using either of the following methods:
    -   **Command line:**

        ```
        sudo apt-get install python3-setuptools python3-pip -y
        sudo pip3 install --upgrade pip
        ```

    -   **Installation package:**

        ```
        curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
        python get-pip.py
        ```



## Installing LLVM \(Required only for OpenHarmony\_v1.x\)<a name="section12202192215415"></a>

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>When downloading source code under the OpenHarmony\_v1.x branches or tags, perform the operation procedure described in this section to install LLVM 9.0.0.
>When downloading source code under the Master and OpenHarmony\_v2.x branches or tags, skip this section. The hb automatically downloads the latest version of LLVM.

1.  Start a Linux server.
2.  [Download LLVM](https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar).
3.  Decompress the LLVM installation package to  **\~/llvm**.

    ```
    tar -zxvf llvm.tar -C ~/
    ```

4.  Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=~/llvm/bin:$PATH
    ```

5.  Validate the environment variable.

    ```
    source ~/.bashrc
    ```


## Installing hb<a name="section15794154618411"></a>

### Prerequisites<a name="section1083283711515"></a>

Python 3.7.4 or later has been installed. For details, see  [Installing Python3](#section1238412211211).

### Installation Procedure<a name="section11518484814"></a>

1.  Install  **hb**.

    ```
    python3 -m pip install --user ohos-build
    ```

2.  Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=~/.local/bin:$PATH
    ```

    Update the environment variable.

    ```
    source ~/.bashrc
    ```

3.  Run the  **hb -h**  command. If the following information is displayed, the installation is successful:

    ```
    usage: hb
    
    OHOS build system
    
    positional arguments:
      {build,set,env,clean}
        build               Build source code
        set                 OHOS build settings
        env                 Show OHOS build env
        clean               Clean output
    
    optional arguments:
      -h, --help            Show this help message and exit
    ```


### Uninstalling hb<a name="section3512551574"></a>

```
python3 -m pip uninstall ohos-build
```

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>If you encounter any problem during the installation, resort to the  [FAQs](quickstart-lite-env-setup-faqs.md).

