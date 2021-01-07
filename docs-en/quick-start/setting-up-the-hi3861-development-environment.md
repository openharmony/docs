# Setting Up the Hi3861 Development Environment<a name="EN-US_TOPIC_0000001054781998"></a>

-   [Environment Requirements](#section466851916410)
    -   [Software Requirements](#section1595725202314)
    -   [Build Tools for Linux](#section992619473117)
    -   [Development Tools for Windows](#section2833173411317)

-   [Using Docker to Install the Linux Environment](#section107932281315)
-   [Using an Installation Package to install the Linux Environment](#section497484245614)
    -   [Connecting to a Linux Server](#section1565413132610)
    -   [Changing Linux Shell to Bash](#section1715027152617)
    -   [Installing a Python Environment](#section18835251192618)
    -   [Installing Scons](#section13515123015279)
    -   [Installing gn](#section0646125972716)
    -   [Installing ninja](#section7681117192813)
    -   [Installing gcc\_riscv32 \(Compilation Toolchain for WLAN Module\)](#section1842910288284)

-   [Installing a Windows Development Environment](#section1995840162515)

## Environment Requirements<a name="section466851916410"></a>

### Software Requirements<a name="section1595725202314"></a>

**Table  1**  Requirements on the development platform

<a name="table1822785713303"></a>
<table><thead align="left"><tr id="row72271157163014"><th class="cellrowborder" valign="top" width="12.41%" id="mcps1.2.5.1.1"><p id="p17227205711305"><a name="p17227205711305"></a><a name="p17227205711305"></a>Hardware</p>
</th>
<th class="cellrowborder" valign="top" width="12.389999999999999%" id="mcps1.2.5.1.2"><p id="p112271557113019"><a name="p112271557113019"></a><a name="p112271557113019"></a>Software</p>
</th>
<th class="cellrowborder" valign="top" width="46.21%" id="mcps1.2.5.1.3"><p id="p16227105718309"><a name="p16227105718309"></a><a name="p16227105718309"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="28.99%" id="mcps1.2.5.1.4"><p id="p162271957163018"><a name="p162271957163018"></a><a name="p162271957163018"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row16227157163014"><td class="cellrowborder" valign="top" width="12.41%" headers="mcps1.2.5.1.1 "><p id="p1222775733020"><a name="p1222775733020"></a><a name="p1222775733020"></a>Linux compile server</p>
</td>
<td class="cellrowborder" valign="top" width="12.389999999999999%" headers="mcps1.2.5.1.2 "><p id="p22272577304"><a name="p22272577304"></a><a name="p22272577304"></a>Operating system</p>
</td>
<td class="cellrowborder" valign="top" width="46.21%" headers="mcps1.2.5.1.3 "><p id="p622719576305"><a name="p622719576305"></a><a name="p622719576305"></a>Ubuntu 16.04 64-bit server or later (Use bash as the shell.)</p>
</td>
<td class="cellrowborder" rowspan="2" valign="top" width="28.99%" headers="mcps1.2.5.1.4 "><p id="p162276579305"><a name="p162276579305"></a><a name="p162276579305"></a>You can develop programs on the Windows workstation or Linux server via a remote login.</p>
</td>
</tr>
<tr id="row5227165719305"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p32279578305"><a name="p32279578305"></a><a name="p32279578305"></a>Windows workstation</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p192271757133018"><a name="p192271757133018"></a><a name="p192271757133018"></a>Operating system</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1022855713303"><a name="p1022855713303"></a><a name="p1022855713303"></a>Windows XP/Windows7/Windows10</p>
</td>
</tr>
</tbody>
</table>

### Build Tools for Linux<a name="section992619473117"></a>

The following table describes the tools required for setting up the general environment for a Linux server and how to obtain these tools.

**Table  2**  Development tools and obtaining methods

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="25.562556255625562%" id="mcps1.2.4.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="20.7020702070207%" id="mcps1.2.4.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="53.73537353735374%" id="mcps1.2.4.1.3"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row1829915274517"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p1629902717511"><a name="p1629902717511"></a><a name="p1629902717511"></a>gcc_riscv32</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1219863434519"><a name="p1219863434519"></a><a name="p1219863434519"></a>Executes script cross compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p14145637348"><a name="p14145637348"></a><a name="p14145637348"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/gcc_riscv32/7.3.0/linux/gcc_riscv32-linux-7.3.0.tar.gz" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/gcc_riscv32/7.3.0/linux/gcc_riscv32-linux-7.3.0.tar.gz</a></p>
</td>
</tr>
<tr id="row430016273514"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p330015271158"><a name="p330015271158"></a><a name="p330015271158"></a>Python3.7+</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p43003270510"><a name="p43003270510"></a><a name="p43003270510"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p18254155164617"><a name="p18254155164617"></a><a name="p18254155164617"></a><a href="https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz" target="_blank" rel="noopener noreferrer">https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz</a></p>
</td>
</tr>
<tr id="row1397335913612"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p097355911620"><a name="p097355911620"></a><a name="p097355911620"></a>SCons3.0.4+</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1973195917619"><a name="p1973195917619"></a><a name="p1973195917619"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p1722663441514"><a name="p1722663441514"></a><a name="p1722663441514"></a>Internet</p>
</td>
</tr>
<tr id="row42668197206"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p426711912014"><a name="p426711912014"></a><a name="p426711912014"></a>bash</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p14267131962014"><a name="p14267131962014"></a><a name="p14267131962014"></a>Executes commands.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p14267101962014"><a name="p14267101962014"></a><a name="p14267101962014"></a>Internet</p>
</td>
</tr>
<tr id="row1463517494402"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p258814561424"><a name="p258814561424"></a><a name="p258814561424"></a>build-essential</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p1749611716181"><a name="p1749611716181"></a><a name="p1749611716181"></a>Provides basic software package for compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p8635174916403"><a name="p8635174916403"></a><a name="p8635174916403"></a>Internet</p>
</td>
</tr>
<tr id="row1711946154018"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p15588165684216"><a name="p15588165684216"></a><a name="p15588165684216"></a>gn</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p4588135634213"><a name="p4588135634213"></a><a name="p4588135634213"></a>Generates ninja compilation scripts.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p10572194318318"><a name="p10572194318318"></a><a name="p10572194318318"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar</a></p>
</td>
</tr>
<tr id="row16990164213404"><td class="cellrowborder" valign="top" width="25.562556255625562%" headers="mcps1.2.4.1.1 "><p id="p1858825613428"><a name="p1858825613428"></a><a name="p1858825613428"></a>ninja</p>
</td>
<td class="cellrowborder" valign="top" width="20.7020702070207%" headers="mcps1.2.4.1.2 "><p id="p15844174611816"><a name="p15844174611816"></a><a name="p15844174611816"></a>Executes ninja compilation scripts.</p>
</td>
<td class="cellrowborder" valign="top" width="53.73537353735374%" headers="mcps1.2.4.1.3 "><p id="p1923373393515"><a name="p1923373393515"></a><a name="p1923373393515"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar</a></p>
</td>
</tr>
</tbody>
</table>

### Development Tools for Windows<a name="section2833173411317"></a>

**Table  3**  Development tools and obtaining methods

<a name="table1313323311274"></a>
<table><thead align="left"><tr id="row3133133312711"><th class="cellrowborder" valign="top" width="16.371637163716375%" id="mcps1.2.4.1.1"><p id="p16132203372716"><a name="p16132203372716"></a><a name="p16132203372716"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="50.29502950295029%" id="mcps1.2.4.1.2"><p id="p1413219339278"><a name="p1413219339278"></a><a name="p1413219339278"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p17133183312711"><a name="p17133183312711"></a><a name="p17133183312711"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row138432533451"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p163612016916"><a name="p163612016916"></a><a name="p163612016916"></a>Visual Studio Code</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p1563690791"><a name="p1563690791"></a><a name="p1563690791"></a>Edits code.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p146361701097"><a name="p146361701097"></a><a name="p146361701097"></a><a href="https://code.visualstudio.com/" target="_blank" rel="noopener noreferrer">https://code.visualstudio.com/</a></p>
</td>
</tr>
<tr id="row12133123315277"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p613393317271"><a name="p613393317271"></a><a name="p613393317271"></a>HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p10133193310276"><a name="p10133193310276"></a><a name="p10133193310276"></a>Supports code editing, compilation, burning, and debugging.</p>
<div class="note" id="note7133193392718"><a name="note7133193392718"></a><a name="note7133193392718"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1133183310277"><a name="p1133183310277"></a><a name="p1133183310277"></a>HUAWEI DevEco Device Tool is a one-stop integrated development environment (IDE) provided for developers of <span id="text4133533192719"><a name="text4133533192719"></a><a name="text4133533192719"></a>OpenHarmony</span>-based smart devices. It supports C and C++ languages and is installed in Visual Studio Code as a plug-in.</p>
</div></div>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1240954393114"><a name="p1240954393114"></a><a name="p1240954393114"></a><a href="https://device.harmonyos.com/en/ide" target="_blank" rel="noopener noreferrer">https://device.harmonyos.com/en/ide</a></p>
</td>
</tr>
<tr id="row18342145821513"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p123421958131517"><a name="p123421958131517"></a><a name="p123421958131517"></a>PuTTY, or other HyperTerminal</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p18342658131511"><a name="p18342658131511"></a><a name="p18342658131511"></a>Remotely connects to a Linux compile server or a serial port.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p17342125851518"><a name="p17342125851518"></a><a name="p17342125851518"></a>Internet (for example, <a href="https://www.putty.org/" target="_blank" rel="noopener noreferrer">https://www.putty.org/</a>)</p>
</td>
</tr>
<tr id="row244884215147"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="p1044974291416"><a name="p1044974291416"></a><a name="p1044974291416"></a>CH341SER.EXE</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="p94491342131413"><a name="p94491342131413"></a><a name="p94491342131413"></a>Identifies serial port device to transmit data.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6449184214148"><a name="p6449184214148"></a><a name="p6449184214148"></a><a href="http://www.wch-ic.com/downloads/CH341SER_EXE.html" target="_blank" rel="noopener noreferrer">http://www.wch-ic.com/downloads/CH341SER_EXE.html</a></p>
</td>
</tr>
</tbody>
</table>

## Using Docker to Install the Linux Environment<a name="section107932281315"></a>

You can use Docker to quickly install the Linux environment. For details, see  **Setting Up the Docker Environment**  in  [Using Docker to Prepare the Build Environment](../get-code/tool-acquisition.md).

## Using an Installation Package to install the Linux Environment<a name="section497484245614"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, compilation tools like  **gn**,  **ninja**,  **gcc\_riscv32**  are not required.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install compilation tools such as  **gn**,  **ninja**, and  **gcc\_riscv32**.
>    When installing  **gn**,  **ninja**, and  **gcc\_riscv32**, ensure that the environment variable paths of the compilation tools are unique.

### Connecting to a Linux Server<a name="section1565413132610"></a>

Using PuTTY to log in to a Linux server from a PC running Windows

1.  Open  [PuTTY](https://www.putty.org/), enter the IP address of the Linux server, and click  **Open**.

    **Figure  1**  PuTTY configuration<a name="f825e6d7569cc487db9b744e454c7157a"></a>  
    ![](figures/putty-configuration.png "putty-configuration")

2.  Click  **Yes**  in the PuTTY  **Security Alert**  dialog box.
3.  Enter the account and password.

    **Figure  2**  Login<a name="fe1428afffbdd45f9b4a39497691ff5ff"></a>  
    ![](figures/login.png "login")

4.  The login is successful.

    **Figure  3**  Successful login<a name="f11bea69483e14bd39fef4a10b1ed1a3a"></a>  
    ![](figures/successful-login.png "successful-login")


### Changing Linux Shell to Bash<a name="section1715027152617"></a>

Check whether bash is used as the shell.

```
ls -l /bin/sh
```

If  **/bin/sh -\> bash**  is not displayed, do as follows to change shell to bash.

**Method 1:**  Run the following command on the device and then click  **No**.

```
sudo dpkg-reconfigure dash
```

**Method 2:**  Run the first command to delete sh and then run the second command to create a new soft link.

```
sudo rm -rf /bin/sh
sudo ln -s /bin/bash /bin/sh
```

### Installing a Python Environment<a name="section18835251192618"></a>

1.  Start a Linux server.
2.  Check the Python version \(Python 3.7 or later is required\).

    ```
    python3 --version
    ```

    If the Python version is earlier than 3.7, reinstall a later Python version \(for example, Python 3.8\) as follows:

    1.  Check the Ubuntu version.

    ```
    cat /etc/issue
    ```

    1.  Install Python based on the Ubuntu version.
        -   If the Ubuntu version is 18 or later, run the following command:

            ```
            sudo apt-get install python3.8
            ```

        -   If the Ubuntu version is 16, download the installation package and install Python.

            1.  Install Python environment dependencies \(gcc, g++, make, zlib, libffi\).

            ```
            sudo apt-get install gcc && sudo apt-get install g++ && sudo apt-get install make && sudo apt-get install zlib* && sudo apt-get install libffi-dev
            ```

            1.  Obtain the  [Python3.8.5 installation package](https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz), save it to the Linux server, and run the following command:

            ```
            tar -xvzf Python-3.8.5.tgz && cd Python-3.8.5 && sudo ./configure && sudo make && sudo make install
            ```



3.  After Python is installed, link the Python path to  **/usr/bin/python**.

    Check whether Python is soft linked to Python 3.8.

    ```
    python --version
    ```

    If the command output is not  **python 3.8.5**, run the following command to check the directory where Python 3.8 is stored:

    ```
    which python3.8
    ```

    Replace  **python3.8-path**  in the following command with the output path of the  **which python3.8**  command.

    ```
    cd /usr/bin && sudo rm python && sudo rm python3 && sudo ln -s python3.8-path python && sudo ln -s python3.8-path python3 && python3 --version && python --version
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


5.  Install setuptools.

    ```
    pip3 install setuptools
    ```

6.  Install the GUI menuconfig tool \(Kconfiglib\). You are advised to install Kconfiglib 13.2.0 or later.
    -   **Command line:**

        ```
        sudo pip3 install kconfiglib
        ```


    -   **Installation package:**
        1.  Download the  **.whl**  file \(for example,  **kconfiglib-13.2.0-py2.py3-none-any.whl**\).

            Download path:  [https://pypi.org/project/kconfiglib\#files](https://pypi.org/project/kconfiglib#files)


        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install kconfiglib-13.2.0-py2.py3-none-any.whl
            ```



7.  Install  **pycryptodome**  using either of the following methods:

    Install the Python component packages on which the file signature depends, including pycryptodome, six, and ecdsa. As the installation of  **ecdsa**  depends on that of  **six**, install  **six**  first.

    -   **Command line:**

        ```
        sudo pip3 install pycryptodome
        ```

    -   **Installation package:**
        1.  Download the  **.whl**  file, for example,  **pycryptodome-3.9.9-cp38-cp38-manylinux1\_x86\_64.whl**, from  [https://pypi.org/project/pycryptodome/\#files](https://pypi.org/project/pycryptodome/#files).

        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install pycryptodome-3.9.9-cp38-cp38-manylinux1_x86_64.whl
            ```



8.  Install  **six**  using either of the following methods:
    -   **Command line:**

        ```
        sudo pip3 install six --upgrade --ignore-installed six
        ```


    -   **Installation package:**
        1.  Download the  **.whl**  file, for example,  **six-1.12.0-py2.py3-none-any.whl**  from  [https://pypi.org/project/six/\#files](https://pypi.org/project/six/#files).

        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install six-1.12.0-py2.py3-none-any.whl
            ```



9.  Install  **ecdsa**  using either of the following methods:
    -   **Command line:**

        ```
        sudo pip3 install ecdsa
        ```

    -   **Installation package:**
        1.  Download the  **.whl**  file, for example,  **ecdsa-0.14.1-py2.py3-none-any.whl**  from  [https://pypi.org/project/ecdsa/\#files](https://pypi.org/project/ecdsa/#files).

        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install ecdsa-0.14.1-py2.py3-none-any.whl
            ```




### Installing Scons<a name="section13515123015279"></a>

1.  Start a Linux server.
2.  Install the SCons installation package.

    ```
    sudo apt-get install scons -y
    ```

    If the installation package cannot be found in the software source, do as follows:

    1.  Download the source code package from  [https://scons.org/pages/download.html](https://scons.org/pages/download.html). The recommended SCons version is 3.0.4 or later.
    2.  Decompress the source code package to any directory, for example, scons-3.1.2.

        ```
        tar -xvf scons-3.1.2.tar.gz
        ```

    3.  Go to the source code directory and run the following command to install the source code package:

        ```
        sudo python3 setup.py install
        ```


3.  Check whether the installation is successful.

    ```
    scons -v
    ```

    **Figure  4**  Successful installation<a name="fig235815252492"></a>  
    ![](figures/successful-installation.png "successful-installation")


### Installing gn<a name="section0646125972716"></a>

1.  Start a Linux server.
2.  Download  [gn](https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar).
3.  Decompress the gn installation package to  **\~/gn**.

    ```
    tar -xvf gn.1523.tar -C ~/
    ```

4.  Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=~/gn:$PATH
    ```

5.  Validate the environment variable.

    ```
    source ~/.bashrc
    ```


### Installing ninja<a name="section7681117192813"></a>

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


### Installing gcc\_riscv32 \(Compilation Toolchain for WLAN Module\)<a name="section1842910288284"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>The Hi3861 platform supports only the static link of the libgcc library.  **The dynamic link is not recommended because version 3 of the GNU General Public License \(GPLv3\) will be polluted during commercial distribution.**

1.  Start a Linux server.
2.  Install the  **gcc**,  **g++**,  **bison**,  **flex**,  **makeinfo**  tools to ensure that the toolchain can be correctly compiled.

    ```
    sudo apt-get install gcc && sudo apt-get install g++ && sudo apt-get install flex bison && sudo apt-get install texinfo
    ```

3.  Download the RISC-V GNU toolchain.

    ```
    git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
    ```

4.  Open the  **riscv-gnu-toolchain**  folder and delete empty folders to prevent conflicts during the download of  **newlib**,  **binutils**, and  **gcc**.

    ```
    cd riscv-gnu-toolchain && rm -rf riscv-newlib && rm -rf riscv-binutils && rm -rf riscv-gcc
    ```

5.  Download RISC-V newlib 3.0.0.

    ```
    git clone -b riscv-newlib-3.0.0 https://github.com/riscv/riscv-newlib.git
    ```

6.  Download RISC-V binutils 2.31.1.

    ```
    git clone -b riscv-binutils-2.31.1 https://github.com/riscv/riscv-binutils-gdb.git
    ```

7.  Download RISC-V gcc 7.3.0.

    ```
    git clone -b riscv-gcc-7.3.0 https://github.com/riscv/riscv-gcc
    ```

8.  Download RISC-V gcc 7.3.0 patches.

    Copy the  [89411.patch](https://gcc.gnu.org/git/?p=gcc.git;a=patch;h=026216a753ef0a757a9e368a59fa667ea422cf09;hp=2a23a1c39fb33df0277abd4486a3da64ae5e62c2)  and  [86724.patch](https://gcc.gnu.org/git/?p=gcc.git;a=blobdiff;f=gcc/graphite.h;h=be0a22b38942850d88feb159603bb846a8607539;hp=4e0e58c60ab83f1b8acf576e83330466775fac17;hb=b1761565882ed6a171136c2c89e597bc4dd5b6bf;hpb=fbd5f023a03f9f60c6ae36133703af5a711842a3), modify the line number of the corresponding code, and place the two patches in the  **riscv-gcc**  directory.

    ```
    cd riscv-gcc && patch -p1 < 89411.patch && patch -p1 < 86724.patch
    ```

    If problems such as  **Hunk \#1 FAILED**  occur during patch installation, modify the line number in the code pertaining to the patches  in the  **.c**  file.

9.  Download, decompress, and install  [GMP 6.1.2](https://gmplib.org/download/gmp/gmp-6.1.2.tar.bz2).

    ```
    tar -xvf mpfr-4.0.2.tar.gz && mkdir build_mpfr && cd build_mpfr && ../mpfr-4.0.2/configure --prefix=/usr/local/mpfr-4.0.2 --with-gmp=/usr/local/gmp-6.1.2 --disable-shared && make && make install
    ```

10. Download, decompress, and install  [mpfr-4.0.2 ](https://www.mpfr.org/mpfr-4.0.2/mpfr-4.0.2.tar.gz).

    ```
    tar -xvf mpfr-4.0.2.tar.gz && mkdir build_mpfr && cd build_mpfr && ../mpfr-4.0.2/configure --prefix=/usr/local/mpfr-4.0.2 --with-gmp=/usr/local/gmp-6.1.2 --disable-shared && make && make install
    ```

11. Download, decompress, and install  [mpc-1.1.0](https://ftp.gnu.org/gnu/mpc/mpc-1.1.0.tar.gz).

    ```
    tar -xvf mpc-1.1.0.tar.gz && mkdir build_mpc && cd build_mpc && ../mpc-1.1.0/configure --prefix=/usr/local/mpc-1.1.0 --with-gmp=/usr/local/gmp-6.1.2 --with-mpfr=/usr/local/mpfr-4.0.2 --disable-shared && make && make install
    ```

12. Open the  **riscv-gnu-toolchain**  folder and create a directory for toolchain output.

    ```
    cd /opt && mkdir gcc_riscv32
    ```

13. Build  **bintutils**.

    ```
    mkdir build_binutils && cd build_binutils && ../riscv-binutils-gdb/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --bindir=/opt/gcc_riscv32/bin --libexecdir=/opt/gcc_riscv32/riscv32 --libdir=/opt/gcc_riscv32 --includedir=/opt/gcc_riscv32 && make -j16 && make install
    ```

14. Build  **newlib**.

    ```
    mkdir build_newlib && cd build_newlib && ../riscv-newlib/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" \CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --bindir=/opt/gcc_riscv32/bin --libexecdir=/opt/gcc_riscv32 --libdir=/opt/gcc_riscv32 --includedir=/opt/gcc_riscv32 && make -j16 && make install
    ```

15. Build  **gcc**.

    ```
    mkdir build_gcc && cd build_gcc && ../riscv-gcc/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" LDFLAGS="-Wl,-z,relro,-z,now,-z,noexecstack" CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --with-headers="/opt/gcc-riscv32/riscv32-unknown-elf/include" --with-mpc=/usr/local/mpc-1.1.0 --with-gmp=/usr/local/gmp-6.1.2 --with-mpfr=/usr/local/mpfr-4.0.2 && make -j16 && make install
    ```

16. Set an environment variable.

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=/opt/gcc_riscv32/bin:$PATH
    ```

17. Validate the environment variable.

    ```
    source ~/.bashrc
    ```

18. Enter the following command to check whether the compiler is successfully installed. If the compiler version number is correctly displayed, the installation is successful.

    ```
    riscv32-unknown-elf-gcc -v
    ```


## Installing a Windows Development Environment<a name="section1995840162515"></a>

The OpenHarmony IDE Development Tool \(HUAWEI DevEco Device Tool\) integrates the capabilities of terminal tools. For details about how to install the tool, see  [Preparations ](https://device.harmonyos.com/en/docs/ide/user-guides/tool_install-0000001050164976)and  [Importing and Configuring a Project](https://device.harmonyos.com/en/docs/ide/user-guides/import_project-0000001050164980).

