# Ubuntu Build Environment<a name="EN-US_TOPIC_0000001105407498"></a>

-   [Obtaining Source Code and Tools](#section1897711811517)
-   [Obtaining OpenHarmony Source Code](#section1545225464016)
-   [Installing and Configuring Python](#section1238412211211)
-   [Installing gn](#section29216201423)
-   [Installing ninja](#section8762358731)
-   [Installing hc-gen](#section4924165316437)
-   [Installing LLVM](#section12202192215415)
-   [Installing hb](#section15794154618411)
    -   [Prerequisites](#section1083283711515)
    -   [Installation Procedure](#section11518484814)
    -   [Uninstalling hb](#section3512551574)


Operating system: 64-bit version of Ubuntu 16.04 or later.

Perform the following steps to set up the build environment:

1.  Obtain source code.
2.  Install and configure Python.
3.  Install GN.
4.  Install Ninja.
5.  Installing hc-gen
6.  Install LLVM.
7.  Install hb.

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   Docker is provided for the Ubuntu build environment, which encapsulates related build tools. If you use Docker to prepare the build environment, you do not need to perform the following steps in this section. Instead, refer to  [Using Docker to Prepare the Build Environment](../get-code/tool-acquisition.md).
>-   By default, basic software, such as Samba and Vim, is installed in the system. Adaptation on the software is required to support file sharing between the Linux server and the Windows workstation.
>-   For details about the compilation and building subsystem of OpenHarmony, see the  [Compilation and Building Overview](../subsystems/compilation-and-building-overview.md).

## Obtaining Source Code and Tools<a name="section1897711811517"></a>

The following table describes the tools and source code required for setting up the general environment for a Linux server and how to obtain these tools and the source code.

**Table  1**  Source code and development tools and their obtaining methods

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="25.562556255625562%" id="mcps1.2.4.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="20.7020702070207%" id="mcps1.2.4.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="53.73537353735374%" id="mcps1.2.4.1.3"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row45863354112"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p3587173513117"><a name="p3587173513117"></a><a name="p3587173513117"></a>Source code</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p258713581118"><a name="p258713581118"></a><a name="p258713581118"></a>Develops functions.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p16587835171114"><a name="p16587835171114"></a><a name="p16587835171114"></a>For details, see <a href="../get-code/source-code-acquisition.md">Source Code Acquisition</a>.</p>
</td>
</tr>
<tr id="row430016273514"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p330015271158"><a name="p330015271158"></a><a name="p330015271158"></a>Python3.7+</p>
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
<tr id="row18800428194715"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p280042884712"><a name="p280042884712"></a><a name="p280042884712"></a>hc-gen</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p15800428174711"><a name="p15800428174711"></a><a name="p15800428174711"></a>Configures and compiles files.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p10800828174712"><a name="p10800828174712"></a><a name="p10800828174712"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar</a></p>
</td>
</tr>
<tr id="row7531362055"><td class="cellrowborder" rowspan="2" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p1467122152710"><a name="p1467122152710"></a><a name="p1467122152710"></a></p>
<p id="p15217227174016"><a name="p15217227174016"></a><a name="p15217227174016"></a>LLVM</p>
<p id="p689515112108"><a name="p689515112108"></a><a name="p689515112108"></a></p>
</td>
<td class="cellrowborder" rowspan="2" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1739432372718"><a name="p1739432372718"></a><a name="p1739432372718"></a></p>
<p id="p122171727184019"><a name="p122171727184019"></a><a name="p122171727184019"></a>Functions as the compiler toolchain.</p>
<p id="p108951116109"><a name="p108951116109"></a><a name="p108951116109"></a></p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p1974322421510"><a name="p1974322421510"></a><a name="p1974322421510"></a>For master and OpenHarmony_2.x branch/tag, please use v10.0.1 from the following link:</p><p id="p5445144091417"><a name="p5445144091417"></a><a name="p5445144091417"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/clang/10.0.1-62608/linux/llvm.tar.gz" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/clang/10.0.1-62608/linux/llvm.tar.gz</a></p>
</td>
</tr>
<tr id="row78941113109"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1974322421510"><a name="p1974322421510"></a><a name="p1974322421510"></a>For OpenHarmony_1.x branch/tag, please use v9.0.0 from the following link:</p>
<p id="p198321032101412"><a name="p198321032101412"></a><a name="p198321032101412"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar</a></p>
</td>
</tr>
<tr id="row1644079184919"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p744115914493"><a name="p744115914493"></a><a name="p744115914493"></a>hb</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1244114913492"><a name="p1244114913492"></a><a name="p1244114913492"></a>Compiles the <span id="text344823833918"><a name="text344823833918"></a><a name="text344823833918"></a>OpenHarmony</span> source code.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p1463918124619"><a name="p1463918124619"></a><a name="p1463918124619"></a>Internet</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, you do not need to install compilation tools like  **gn**  and  **ninja**.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install compilation tools such as  **gn**,  **ninja**, and LLVM. When installing these tools, ensure that their environment variable paths are unique.

## Obtaining OpenHarmony Source Code<a name="section1545225464016"></a>

You need to acquire  [source code](../get-code/source-code-acquisition.md), download it on a Linux server, and decompress it.

## Installing and Configuring Python<a name="section1238412211211"></a>

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



## Installing gn<a name="section29216201423"></a>

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


## Installing ninja<a name="section8762358731"></a>

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


## Installing hc-gen<a name="section4924165316437"></a>

1.  Start a Linux server.
2.  Download  [hc-gen](https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar).
3.  Decompress the hc-gen installation package to  **\~/hc-gen**  on the Linux server.

    ```
    tar -xvf hc-gen-0.65-linux.tar -C ~/
    ```

4.  Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=~/hc-gen:$PATH
    ```

5.  Validate the environment variable.

    ```
    source ~/.bashrc
    ```


## Installing LLVM<a name="section12202192215415"></a>

1.  Start a Linux server.
2.  [Download LLVM](https://repo.huaweicloud.com/harmonyos/compiler/clang/10.0.1-62608/linux/llvm.tar.gz).

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >For OpenHarmony\_1.x branch/tag, click  [here](https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-36191/linux/llvm-linux-9.0.0-36191.tar)  to download LLVM.

3.  Decompress the LLVM installation package to  **\~/llvm**.

    ```
    tar -zxvf llvm.tar.gz -C ~/
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >For OpenHarmony\_1.x branch/tag, run the following command to decompress the LLVM installation package:
    >```
    >tar -xvf llvm-linux-9.0.0-36191.tar -C ~/
    >```

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

Python 3.7.4 or later has been installed. For details, see  [Installing and Configuring Python](#section1238412211211).

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

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>If you encounter any problem during the installation, resort to the  [FAQ](faq.md).

