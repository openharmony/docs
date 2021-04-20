# Basic OS Environment Setup<a name="EN-US_TOPIC_0000001121152509"></a>

-   [Environment Requirements](#section466851916410)
    -   [Hardware and Software Requirements](#section1595725202314)
    -   [Development Tools for Windows](#section2833173411317)
    -   [Build Tools for Linux](#section992619473117)

-   [Installing a Windows Development Environment](#section1995840162515)
-   [Using Docker to Install the Linux Environment](#section107932281315)
-   [Using an Installation Package to Install the Linux Environment](#section497484245614)
    -   [Connecting to a Linux Server](#section723115618340)
    -   [Installing and Configuring Python](#section11255767343)
    -   [Installing gn](#section9262166183410)
    -   [Installing ninja](#section02645617348)
    -   [Installing LLVM](#section149564754)
    -   [Installing hb](#section6201103143120)

-   [Obtaining OpenHarmony Source Code](#section1545225464016)
-   [FAQ](#section19253140111619)
    -   [What should I do if garbled characters and segmentation faults occur during hb installation?](#section347685141717)
    -   [What should I do if the message "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation?](#section1996804118553)
    -   [What should I do if the message "module 'platform' has no attribute 'linux\_distribution'" is displayed during hb Installation?](#section6992181918582)
    -   [What should I do if the message "ImportError: No module named apt\_pkg" is displayed during the execution of an unidentifiable command?](#section7854153010120)


Before setting up the environment for a development board, you must set up the basic OS environment for OpenHarmony first. The basic OS environment refers to the building environment and development environment of OpenHarmony. You can choose one of the following methods to set up the basic OS environment based on your preference and the hardware and software used.

-   **Method 1**

    Install a Windows development environment and use docker to install the Linux environment. For details, see the following sections:


1.  [Environment Requirements](#section466851916410)
2.  [Installing a Windows Development Environment](#section1995840162515)
3.  [Using Docker to Install the Linux Environment](#section107932281315)

-   **Method 2**

    Install a Windows development environment and use an installation package to install the Linux environment. For details, see the following sections:


1.  [Environment Requirements](#section466851916410)
2.  [Installing a Windows Development Environment](#section1995840162515)
3.  [Using an Installation Package to Install the Linux Environment](#section497484245614)

-   **Method 3**

    Install the Linux development and building environment. For details, see  [Linux Development Environment](https://device.harmonyos.com/en/docs/ide/user-guides/install_ubuntu-0000001072959308)  in  _HUAWEI DevEco Studio User Guide_.


## Environment Requirements<a name="section466851916410"></a>

### Hardware and Software Requirements<a name="section1595725202314"></a>

**Table  1**  Development platform requirements

<a name="tc50585b2b3fe43f7835154789b0e25af"></a>
<table><thead align="left"><tr id="ra9df6acc53154b819d5f86d885d994de"><th class="cellrowborder" valign="top" width="8.530000000000001%" id="mcps1.2.5.1.1"><p id="a999bb40532eb4f74a7383e1e776bb94a"><a name="a999bb40532eb4f74a7383e1e776bb94a"></a><a name="a999bb40532eb4f74a7383e1e776bb94a"></a>Hardware</p>
</th>
<th class="cellrowborder" valign="top" width="38.43%" id="mcps1.2.5.1.2"><p id="ae63cf791fbe348d3b907d20fc4927df8"><a name="ae63cf791fbe348d3b907d20fc4927df8"></a><a name="ae63cf791fbe348d3b907d20fc4927df8"></a>Software</p>
</th>
<th class="cellrowborder" valign="top" width="39.230000000000004%" id="mcps1.2.5.1.3"><p id="a54c4c80c43c84cb187342865a1d2b51e"><a name="a54c4c80c43c84cb187342865a1d2b51e"></a><a name="a54c4c80c43c84cb187342865a1d2b51e"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="13.810000000000002%" id="mcps1.2.5.1.4"><p id="a11e8d096fb204378a63d8805cd6d1f88"><a name="a11e8d096fb204378a63d8805cd6d1f88"></a><a name="a11e8d096fb204378a63d8805cd6d1f88"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row1136907203"><td class="cellrowborder" valign="top" width="8.530000000000001%" headers="mcps1.2.5.1.1 "><p id="a8e99fd0262cb4489b70cf86c2144c294"><a name="a8e99fd0262cb4489b70cf86c2144c294"></a><a name="a8e99fd0262cb4489b70cf86c2144c294"></a>Windows workstation (host computer)</p>
</td>
<td class="cellrowborder" valign="top" width="38.43%" headers="mcps1.2.5.1.2 "><p id="a44d6164ce2e9421f9ade362f600c2815"><a name="a44d6164ce2e9421f9ade362f600c2815"></a><a name="a44d6164ce2e9421f9ade362f600c2815"></a>Operating system</p>
</td>
<td class="cellrowborder" valign="top" width="39.230000000000004%" headers="mcps1.2.5.1.3 "><p id="a1c17349e334a44ada5c5f150457fe17d"><a name="a1c17349e334a44ada5c5f150457fe17d"></a><a name="a1c17349e334a44ada5c5f150457fe17d"></a>Windows XP/Windows7/Windows10</p>
</td>
<td class="cellrowborder" rowspan="2" valign="top" width="13.810000000000002%" headers="mcps1.2.5.1.4 "><p id="a4d0e2c8444484554ab58949ce322be32"><a name="a4d0e2c8444484554ab58949ce322be32"></a><a name="a4d0e2c8444484554ab58949ce322be32"></a>You can develop programs on the Windows workstation or Linux server via a remote login.</p>
</td>
</tr>
<tr id="row117591159175819"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="a0c1290183f2548898dbfc516a4db2c4b"><a name="a0c1290183f2548898dbfc516a4db2c4b"></a><a name="a0c1290183f2548898dbfc516a4db2c4b"></a>Linux compile server</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="a687efa8001f140488dc1da9a2ee8f6d1"><a name="a687efa8001f140488dc1da9a2ee8f6d1"></a><a name="a687efa8001f140488dc1da9a2ee8f6d1"></a>Operating system</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="ace724e00c9094eccb8c600d6ad426ed8"><a name="ace724e00c9094eccb8c600d6ad426ed8"></a><a name="ace724e00c9094eccb8c600d6ad426ed8"></a>Ubuntu 16.04 64-bit or later is used for the Linux OS, and bash is used as the shell.</p>
<div class="note" id="note124531828194919"><a name="note124531828194919"></a><a name="note124531828194919"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1244243142810"><a name="p1244243142810"></a><a name="p1244243142810"></a>Common software such as samba and vim is installed in the OS by default. Adaptation is required to support Linux file sharing.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

### Development Tools for Windows<a name="section2833173411317"></a>

**Table  2**  Development tools and obtaining methods

<a name="table1313323311274"></a>
<table><thead align="left"><tr id="row3133133312711"><th class="cellrowborder" valign="top" width="27.12%" id="mcps1.2.4.1.1"><p id="p16132203372716"><a name="p16132203372716"></a><a name="p16132203372716"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="36.86%" id="mcps1.2.4.1.2"><p id="p1413219339278"><a name="p1413219339278"></a><a name="p1413219339278"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="36.02%" id="mcps1.2.4.1.3"><p id="p17133183312711"><a name="p17133183312711"></a><a name="p17133183312711"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row138432533451"><td class="cellrowborder" valign="top" width="27.12%" headers="mcps1.2.4.1.1 "><p id="p163612016916"><a name="p163612016916"></a><a name="p163612016916"></a>Visual Studio Code</p>
</td>
<td class="cellrowborder" valign="top" width="36.86%" headers="mcps1.2.4.1.2 "><p id="p1563690791"><a name="p1563690791"></a><a name="p1563690791"></a>Edits code.</p>
</td>
<td class="cellrowborder" valign="top" width="36.02%" headers="mcps1.2.4.1.3 "><p id="p146361701097"><a name="p146361701097"></a><a name="p146361701097"></a><a href="https://code.visualstudio.com/" target="_blank" rel="noopener noreferrer">https://code.visualstudio.com/</a></p>
</td>
</tr>
<tr id="row12133123315277"><td class="cellrowborder" valign="top" width="27.12%" headers="mcps1.2.4.1.1 "><p id="p613393317271"><a name="p613393317271"></a><a name="p613393317271"></a>HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="36.86%" headers="mcps1.2.4.1.2 "><p id="p10133193310276"><a name="p10133193310276"></a><a name="p10133193310276"></a>Supports code editing, compilation, burning, and debugging.</p>
<div class="note" id="note7133193392718"><a name="note7133193392718"></a><a name="note7133193392718"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1133183310277"><a name="p1133183310277"></a><a name="p1133183310277"></a>HUAWEI DevEco Device Tool is a one-stop integrated development environment (IDE) provided for developers of <span id="text145751471194"><a name="text145751471194"></a><a name="text145751471194"></a>OpenHarmony</span>-based smart devices. It supports C and C++ languages and is installed in Visual Studio Code as a plug-in.</p>
</div></div>
</td>
<td class="cellrowborder" valign="top" width="36.02%" headers="mcps1.2.4.1.3 "><p id="p1240954393114"><a name="p1240954393114"></a><a name="p1240954393114"></a><a href="https://device.harmonyos.com/cn/ide" target="_blank" rel="noopener noreferrer">https://device.harmonyos.com/cn/ide</a></p>
</td>
</tr>
<tr id="row18342145821513"><td class="cellrowborder" valign="top" width="27.12%" headers="mcps1.2.4.1.1 "><p id="p123421958131517"><a name="p123421958131517"></a><a name="p123421958131517"></a>IPOP, PuTTY, or other HyperTerminal</p>
</td>
<td class="cellrowborder" valign="top" width="36.86%" headers="mcps1.2.4.1.2 "><p id="p18342658131511"><a name="p18342658131511"></a><a name="p18342658131511"></a>Remotely connects to a Linux compile server or a serial port.</p>
</td>
<td class="cellrowborder" valign="top" width="36.02%" headers="mcps1.2.4.1.3 "><p id="p17342125851518"><a name="p17342125851518"></a><a name="p17342125851518"></a>Internet (for example, <a href="https://www.putty.org/" target="_blank" rel="noopener noreferrer">https://www.putty.org/</a>)</p>
</td>
</tr>
</tbody>
</table>

### Build Tools for Linux<a name="section992619473117"></a>

The following table describes the tools required for setting up the general environment for a Linux server and how to obtain these tools.

**Table  3**  Development tools and obtaining methods

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="25.562556255625562%" id="mcps1.2.4.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="20.7020702070207%" id="mcps1.2.4.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="53.73537353735374%" id="mcps1.2.4.1.3"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row430016273514"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p330015271158"><a name="p330015271158"></a><a name="p330015271158"></a>Python3.7+</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p43003270510"><a name="p43003270510"></a><a name="p43003270510"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p34760459518"><a name="p34760459518"></a><a name="p34760459518"></a>Internet</p>
</td>
</tr>
<tr id="row1711946154018"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p15588165684216"><a name="p15588165684216"></a><a name="p15588165684216"></a>gn</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p4588135634213"><a name="p4588135634213"></a><a name="p4588135634213"></a>Generates ninja compilation scripts.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p14131813191712"><a name="p14131813191712"></a><a name="p14131813191712"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz</a></p>
</td>
</tr>
<tr id="row16990164213404"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p1858825613428"><a name="p1858825613428"></a><a name="p1858825613428"></a>ninja</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p15844174611816"><a name="p15844174611816"></a><a name="p15844174611816"></a>Executes ninja compilation scripts.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p1923373393515"><a name="p1923373393515"></a><a name="p1923373393515"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar</a></p>
</td>
</tr>
<tr id="row7531362055"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p15217227174016"><a name="p15217227174016"></a><a name="p15217227174016"></a>LLVM</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p122171727184019"><a name="p122171727184019"></a><a name="p122171727184019"></a>Functions as the compiler toolchain.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p871055810226"><a name="p871055810226"></a><a name="p871055810226"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar</a></p>
</td>
</tr>
<tr id="row1644079184919"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p744115914493"><a name="p744115914493"></a><a name="p744115914493"></a>hb</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1244114913492"><a name="p1244114913492"></a><a name="p1244114913492"></a>Compiles the source code.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p1463918124619"><a name="p1463918124619"></a><a name="p1463918124619"></a>Internet</p>
</td>
</tr>
</tbody>
</table>

## Installing a Windows Development Environment<a name="section1995840162515"></a>

The OpenHarmony IDE Development Tool \(HUAWEI DevEco Device Tool\) integrates the capabilities of terminal tools. For details about how to install the tool, see  [Preparation](https://device.harmonyos.com/en/docs/ide/user-guides/install_windows-0000001050164976)  and  [Creating a Project](https://device.harmonyos.com/en/docs/ide/user-guides/create_project-0000001072200151).

## Using Docker to Install the Linux Environment<a name="section107932281315"></a>

You can use Docker to quickly install the Linux environment. For details, see  **Setting Up the Docker Environment**  in  [Using Docker to Prepare the Build Environment](../get-code/acquiring-tools.md).

## Using an Installation Package to Install the Linux Environment<a name="section497484245614"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, compilation tools like  **gn**  and  **ninja**  are not required.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install compilation tools such as  **gn**  and  **ninja**. When installing  **gn**  and  **ninja**, ensure that the environment variable paths of the compilation tools are unique.

### Connecting to a Linux Server<a name="section723115618340"></a>

Using PuTTY to log in to a Linux server from a PC running Windows

1.  Open  [PuTTY](https://www.putty.org/), enter the IP address of the Linux server, and click  **Open**.

    **Figure  1**  PuTTY configuration<a name="f825e6d7569cc487db9b744e454c7157a"></a>  
    ![](figures/putty-configuration.png "putty-configuration")

2.  Click  **Yes**  in the  **PuTTY Security Alert**  dialog box.
3.  Enter the account and password.

    **Figure  2**  Login<a name="fe1428afffbdd45f9b4a39497691ff5ff"></a>  
    ![](figures/login.png "login")

4.  Check that the login is successful.

    **Figure  3**  Successful login<a name="f11bea69483e14bd39fef4a10b1ed1a3a"></a>  
    ![](figures/successful-login.png "successful-login")


### Installing and Configuring Python<a name="section11255767343"></a>

1.  Start a Linux server.
2.  Check the Python version \(Python 3.7 or later is required\).

    ```
    python3 --version
    ```

    If Python version is earlier than 3.7, reinstall Python. Do as follows to install Python, for example, Python 3.8.

    1.  Check the Ubuntu version.

    ```
    cat /etc/issue
    ```

    1.  Install Python based on the Ubuntu version.
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



### Installing gn<a name="section9262166183410"></a>

1.  Start a Linux server.
2.  Download  [gn](https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz).
3.  Create the  **gn**  folder in the root directory.

    ```
    mkdir ~/gn
    ```

4.  Decompress the gn installation package to  **\~/gn**.

    ```
    tar -xvf gn-linux-x86-1717.tar.gz -C ~/gn
    ```

5.  Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=~/gn:$PATH
    ```

6.  Validate the environment variable.

    ```
    source ~/.bashrc
    ```


### Installing ninja<a name="section02645617348"></a>

1.  Start a Linux server.
2.  Download  [ninja](https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar).
3.  Decompress the ninja installation package to  **\~/ninja**.

    ```
    tar -xvf ninja.1.9.0.tar -C ~/
    ```

4.  Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=~/ninja:$PATH
    ```

5.  Validate the environment variable.

    ```
    source ~/.bashrc
    ```


### Installing LLVM<a name="section149564754"></a>

1.  Start a Linux server.
2.  Download  [LLVM](https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar).
3.  Decompress the LLVM installation package to  **\~/llvm**.

    ```
    tar -xvf llvm-linux-9.0.0-36191.tar -C ~/
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


### Installing hb<a name="section6201103143120"></a>

**Prerequisites**

-   Python 3.7.4 or later has been installed. For details, see  [Installing and Configuring Python](#section11255767343).
-   The source code has been downloaded. For details, see  [Source Code Acquisition](../get-code/source-code-acquisition.md).

**Installation**

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


**Uninstallation**

```
python3 -m pip uninstall ohos-build
```

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>If you encounter any problem during the installation, resort to the  [FAQ](#section19253140111619).

## Obtaining OpenHarmony Source Code<a name="section1545225464016"></a>

You need to acquire OpenHarmony  [source code](https://repo.huaweicloud.com/harmonyos/os/1.0.1/code-1.0.1.tar.gz), download it on a Linux server, and decompress it. For more obtaining methods, see  [Source Code Acquisition](../get-code/source-code-acquisition.md).

## FAQ<a name="section19253140111619"></a>

### What should I do if garbled characters and segmentation faults occur during hb installation?<a name="section347685141717"></a>

-   **Symptom**

    Garbled characters and segmentation faults occur during the execution of the  **python3 -m pip install --user ohos-build**  command.


-   **Possible Causes**

    pip is of an early version.

-   **Solutions**

    Upgrade pip.

    ```
    python3 -m pip install -U pip
    ```


### What should I do if the message "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation?<a name="section1996804118553"></a>

-   **Symptom**

    The message "cannot import 'sysconfig' from 'distutils'" is displayed during the execution of the  **python3 -m pip install --user ohos-build**  command.


-   **Possible Causes**

    The  **distutils**  module is unavailable.

-   **Solutions**

    Install  **distutils**.

    ```
    sudo apt-get install python3.8-distutils
    ```


### What should I do if the message "module 'platform' has no attribute 'linux\_distribution'" is displayed during hb Installation?<a name="section6992181918582"></a>

-   **Symptom**

The message "module 'platform' has no attribute 'linux\_distribution'" is displayed during the execution of the  **python3 -m pip install --user ohos-build**  command.

-   **Possible Causes**

    There is a compatibility issue of python3-pip.

-   **Solutions**

    Reinstall pip.

    ```
    sudo apt remove python3-pip
    curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
    python get-pip.py
    ```


### What should I do if the message "ImportError: No module named apt\_pkg" is displayed during the execution of an unidentifiable command?<a name="section7854153010120"></a>

-   **Symptom**

    The message "ImportError: No module named apt\_pkg" is displayed when an unidentifiable command is executed on the Linux server.


-   **Possible Causes**

    There is a compatibility issue of python3-apt.

-   **Solutions**

    Reinstall python3-apt.

    ```
    sudo apt-get remove  python3-apt
    sduo apt-get install python3-apt
    ```


