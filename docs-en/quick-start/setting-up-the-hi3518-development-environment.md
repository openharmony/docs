# Setting Up the Hi3518 Development Environment<a name="EN-US_TOPIC_0000001054022306"></a>

-   [Environment Requirements](#section1724111409282)
    -   [Hardware Requirements](#section487353718276)
    -   [Software Requirements](#section44143554278)
    -   [Build Tools for Linux](#section17315193935817)
    -   [Development Tools for Windows](#section1897593723017)

-   [Using Docker to Install the Linux Environment](#section4848141175215)
-   [Installing the Linux Environment Using an Installation Package](#section8831868501)
    -   [Connecting to a Linux Server](#section12584112413505)
    -   [Changing Linux Shell to Bash](#section21811833145019)
    -   [Installing a Python Environment](#section10807183719500)
    -   [Installing a File Packing Tool](#section480195453419)
    -   [Installing gn](#section16725103716357)
    -   [Installing ninja](#section156834539351)
    -   [Installing LLVM](#section11739111964114)
    -   [Installing hc-gen](#section351420104218)

-   [Installing a Windows Development Environment](#section188621583120)

## Environment Requirements<a name="section1724111409282"></a>

### Hardware Requirements<a name="section487353718276"></a>

-   Linux server
-   Windows workstation \(host computer\)
-   Hi3518EV300 IoT camera development board
-   USB-to-serial cable and network cable \(The Windows workstation is connected to the Hi3518EV300 development board through the USB-to-serial cable and network cable.\)

    The following figure shows the hardware connections.


**Figure  1**  Hardware connections<a name="fig8211468392"></a>  
![](figures/hardware-connections.png "hardware-connections")

### Software Requirements<a name="section44143554278"></a>

**Table  1**  Platforms required for the Hi3518EV300 development board

<a name="table16641975408"></a>
<table><thead align="left"><tr id="row196634713405"><th class="cellrowborder" valign="top" width="8.53%" id="mcps1.2.5.1.1"><p id="p116632718408"><a name="p116632718408"></a><a name="p116632718408"></a>Hardware</p>
</th>
<th class="cellrowborder" valign="top" width="11.66%" id="mcps1.2.5.1.2"><p id="p1766312724017"><a name="p1766312724017"></a><a name="p1766312724017"></a>Software</p>
</th>
<th class="cellrowborder" valign="top" width="66%" id="mcps1.2.5.1.3"><p id="p666327144010"><a name="p666327144010"></a><a name="p666327144010"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="13.81%" id="mcps1.2.5.1.4"><p id="p106631273406"><a name="p106631273406"></a><a name="p106631273406"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row066315717402"><td class="cellrowborder" valign="top" width="8.53%" headers="mcps1.2.5.1.1 "><p id="p666318712403"><a name="p666318712403"></a><a name="p666318712403"></a>Linux compile server</p>
</td>
<td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.2.5.1.2 "><p id="p76632712403"><a name="p76632712403"></a><a name="p76632712403"></a>Operating system</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.5.1.3 "><p id="p15663127204015"><a name="p15663127204015"></a><a name="p15663127204015"></a>Ubuntu 16.04 64-bit or later is used for the Linux OS, and bash is used as the shell.</p>
<div class="note" id="note196631578401"><a name="note196631578401"></a><a name="note196631578401"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1466311720406"><a name="p1466311720406"></a><a name="p1466311720406"></a>Common software such as samba and vim is installed in the OS by default. Adaptation is required to support Linux file sharing.</p>
</div></div>
</td>
<td class="cellrowborder" rowspan="3" valign="top" width="13.81%" headers="mcps1.2.5.1.4 "><p id="p96631975404"><a name="p96631975404"></a><a name="p96631975404"></a>You can develop programs on the Windows workstation or on the Linux server through remote login.</p>
</td>
</tr>
<tr id="row19664272408"><td class="cellrowborder" rowspan="2" valign="top" headers="mcps1.2.5.1.1 "><p id="p1366314764011"><a name="p1366314764011"></a><a name="p1366314764011"></a>Windows workstation</p>
<p id="p145850361498"><a name="p145850361498"></a><a name="p145850361498"></a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p15663177204019"><a name="p15663177204019"></a><a name="p15663177204019"></a>Operating system</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1766411719408"><a name="p1766411719408"></a><a name="p1766411719408"></a>Windows XP/Windows7/Windows10</p>
</td>
</tr>
<tr id="row258543619919"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="a70beb9d769e340018c9c39c7d44cf424"><a name="a70beb9d769e340018c9c39c7d44cf424"></a><a name="a70beb9d769e340018c9c39c7d44cf424"></a>USB-to-Serial adapter driver</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p9790183418466"><a name="p9790183418466"></a><a name="p9790183418466"></a><a href="http://www.hihope.org/download/AllDocuments" target="_blank" rel="noopener noreferrer">http://www.hihope.org/download/AllDocuments</a></p>
<p id="p37901134184614"><a name="p37901134184614"></a><a name="p37901134184614"></a>Driver name: USB-to-Serial Comm Port.exe</p>
</td>
</tr>
</tbody>
</table>

### Build Tools for Linux<a name="section17315193935817"></a>

The following table describes the tools required for setting up the general environment for a Linux server and how to obtain these tools.

**Table  2**  Development tools and obtaining methods

<a name="table15485545145811"></a>
<table><thead align="left"><tr id="row1748610451588"><th class="cellrowborder" valign="top" width="13.081308130813083%" id="mcps1.2.4.1.1"><p id="p13486154545816"><a name="p13486154545816"></a><a name="p13486154545816"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="19.921992199219922%" id="mcps1.2.4.1.2"><p id="p44867452589"><a name="p44867452589"></a><a name="p44867452589"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="66.996699669967%" id="mcps1.2.4.1.3"><p id="p1748619458583"><a name="p1748619458583"></a><a name="p1748619458583"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row1948614518582"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p9486154516582"><a name="p9486154516582"></a><a name="p9486154516582"></a>Python3.7+</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p74861645105812"><a name="p74861645105812"></a><a name="p74861645105812"></a>Runs the compilation scripts.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p11486194575814"><a name="p11486194575814"></a><a name="p11486194575814"></a><a href="https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz" target="_blank" rel="noopener noreferrer">https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz</a></p>
</td>
</tr>
<tr id="row1248714455582"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p1548774535814"><a name="p1548774535814"></a><a name="p1548774535814"></a>bash</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p18487134595817"><a name="p18487134595817"></a><a name="p18487134595817"></a>Executes commands.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p184871645105816"><a name="p184871645105816"></a><a name="p184871645105816"></a>Internet</p>
</td>
</tr>
<tr id="row148784525817"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p10487345115817"><a name="p10487345115817"></a><a name="p10487345115817"></a>gn</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p348724585820"><a name="p348724585820"></a><a name="p348724585820"></a>Generates ninja compilation scripts.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p194878454589"><a name="p194878454589"></a><a name="p194878454589"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar</a></p>
</td>
</tr>
<tr id="row184874451585"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p174871045105814"><a name="p174871045105814"></a><a name="p174871045105814"></a>ninja</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p204871645145811"><a name="p204871645145811"></a><a name="p204871645145811"></a>Executes ninja compilation scripts.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p184871245135810"><a name="p184871245135810"></a><a name="p184871245135810"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar</a></p>
</td>
</tr>
<tr id="row12487154515585"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p1348713452581"><a name="p1348713452581"></a><a name="p1348713452581"></a>LLVM</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p648774510589"><a name="p648774510589"></a><a name="p648774510589"></a>Functions as the compiler toolchain.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p148719454586"><a name="p148719454586"></a><a name="p148719454586"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-34042/linux/llvm-linux-9.0.0-34042.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-34042/linux/llvm-linux-9.0.0-34042.tar</a></p>
</td>
</tr>
<tr id="row1548710453586"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p15487114585814"><a name="p15487114585814"></a><a name="p15487114585814"></a>hc-gen</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p148719452588"><a name="p148719452588"></a><a name="p148719452588"></a>Configures and compiles files.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p1487164565819"><a name="p1487164565819"></a><a name="p1487164565819"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar</a></p>
</td>
</tr>
<tr id="row248764585810"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p1848711459584"><a name="p1848711459584"></a><a name="p1848711459584"></a>IPOP, PuTTY, or HyperTerminal</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p7487745125819"><a name="p7487745125819"></a><a name="p7487745125819"></a>Connects to the Linux server (choose one of the terminals).</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p18487154516584"><a name="p18487154516584"></a><a name="p18487154516584"></a>Public internet (for example, <a href="https://www.putty.org/" target="_blank" rel="noopener noreferrer">https://www.putty.org/</a>)</p>
</td>
</tr>
</tbody>
</table>

### Development Tools for Windows<a name="section1897593723017"></a>

**Table  3**  Development tools for the Windows workstation

<a name="en-us_topic_0000001054501981_table1313323311274"></a>
<table><thead align="left"><tr id="en-us_topic_0000001054501981_row3133133312711"><th class="cellrowborder" valign="top" width="16.371637163716375%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000001054501981_p16132203372716"><a name="en-us_topic_0000001054501981_p16132203372716"></a><a name="en-us_topic_0000001054501981_p16132203372716"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="50.29502950295029%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000001054501981_p1413219339278"><a name="en-us_topic_0000001054501981_p1413219339278"></a><a name="en-us_topic_0000001054501981_p1413219339278"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000001054501981_p17133183312711"><a name="en-us_topic_0000001054501981_p17133183312711"></a><a name="en-us_topic_0000001054501981_p17133183312711"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001054501981_row13697410143219"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001054501981_p163612016916"><a name="en-us_topic_0000001054501981_p163612016916"></a><a name="en-us_topic_0000001054501981_p163612016916"></a>Visual Studio Code</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001054501981_p1563690791"><a name="en-us_topic_0000001054501981_p1563690791"></a><a name="en-us_topic_0000001054501981_p1563690791"></a>Edits codes.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001054501981_p146361701097"><a name="en-us_topic_0000001054501981_p146361701097"></a><a name="en-us_topic_0000001054501981_p146361701097"></a><a href="https://code.visualstudio.com/" target="_blank" rel="noopener noreferrer">https://code.visualstudio.com/</a></p>
</td>
</tr>
<tr id="en-us_topic_0000001054501981_row12133123315277"><td class="cellrowborder" valign="top" width="16.371637163716375%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001054501981_p613393317271"><a name="en-us_topic_0000001054501981_p613393317271"></a><a name="en-us_topic_0000001054501981_p613393317271"></a>HUAWEI DevEco Device Tool</p>
</td>
<td class="cellrowborder" valign="top" width="50.29502950295029%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001054501981_p10133193310276"><a name="en-us_topic_0000001054501981_p10133193310276"></a><a name="en-us_topic_0000001054501981_p10133193310276"></a>Functions as the integrated development environment (IDE) to provide code compilation, burning, and debugging. C and C++ languages are supported.</p>
<div class="note" id="en-us_topic_0000001054501981_note7133193392718"><a name="en-us_topic_0000001054501981_note7133193392718"></a><a name="en-us_topic_0000001054501981_note7133193392718"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001054501981_p1133183310277"><a name="en-us_topic_0000001054501981_p1133183310277"></a><a name="en-us_topic_0000001054501981_p1133183310277"></a>HUAWEI DevEco Device Tool is a one-stop IDE provided by <span id="en-us_topic_0000001054501981_text4133533192719"><a name="en-us_topic_0000001054501981_text4133533192719"></a><a name="en-us_topic_0000001054501981_text4133533192719"></a>OpenHarmony</span> for smart device developers. You can customize <span id="en-us_topic_0000001054501981_text14536110256"><a name="en-us_topic_0000001054501981_text14536110256"></a><a name="en-us_topic_0000001054501981_text14536110256"></a>OpenHarmony</span> components on it as required, HUAWEI DevEco Device Tool is deployed on Visual Studio Code as a plug-in.</p>
</div></div>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001054501981_p16788135433519"><a name="en-us_topic_0000001054501981_p16788135433519"></a><a name="en-us_topic_0000001054501981_p16788135433519"></a><a href="https://device.harmonyos.com/en/ide" target="_blank" rel="noopener noreferrer">https://device.harmonyos.com/en/ide</a></p>
</td>
</tr>
</tbody>
</table>

## Using Docker to Install the Linux Environment<a name="section4848141175215"></a>

You can use Docker to quickly install the Linux environment. For details, see  **Setting Up the Docker Environment**  in  [Using Docker to Prepare the Build Environment](../get-code/tool-acquisition.md).

## Installing the Linux Environment Using an Installation Package<a name="section8831868501"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, compilation tools like  **gn**,  **ninja**,  **LLVM**, and  **hc-gen**  are not required.
>-   \(Recommended\) If you obtain the source code through an image site or a code repository, compilation tools like  **gn**,  **ninja**,  **LLVM**, and  **hc-gen**  need to be installed. When installing  **gn**,  **ninja**,  **LLVM**, and  **hc-gen**, ensure that the environment variable paths of the compilation tools are unique.

### Connecting to a Linux Server<a name="section12584112413505"></a>

Using PuTTY to log in to a Linux server from a PC running Windows

1.  Open  [PuTTY](https://www.putty.org/), enter the IP address of the Linux server, and click  **Open**.

    **Figure  2**  PuTTY configuration<a name="en-us_topic_0000001054781998_f825e6d7569cc487db9b744e454c7157a"></a>  
    ![](figures/putty-configuration.png "putty-configuration")

2.  Click  **Yes**  in the PuTTY  **Security Alert**  dialog box.
3.  Enter the account and password.

    **Figure  3**  Login<a name="en-us_topic_0000001054781998_fe1428afffbdd45f9b4a39497691ff5ff"></a>  
    ![](figures/login.png "login")

4.  The login is successful.

    **Figure  4**  Successful login<a name="en-us_topic_0000001054781998_f11bea69483e14bd39fef4a10b1ed1a3a"></a>  
    ![](figures/successful-login.png "successful-login")


### Changing Linux Shell to Bash<a name="section21811833145019"></a>

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

### Installing a Python Environment<a name="section10807183719500"></a>

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




### Installing a File Packing Tool<a name="section480195453419"></a>

1.  Start a Linux server.
2.  Install  **dosfstools**.

    ```
    sudo apt-get install dosfstools
    ```

3.  Install  **mtools**.

    ```
    sudo apt-get install mtools
    ```

4.  Install  **mtd-utils**.

    ```
    sudo apt-get install mtd-utils
    ```


### Installing gn<a name="section16725103716357"></a>

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


### Installing ninja<a name="section156834539351"></a>

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


### Installing LLVM<a name="section11739111964114"></a>

1.  Start a Linux server.
2.  Download  [LLVM](http://tools.harmonyos.com/mirrors/clang/9.0.0-34042/linux/llvm-linux-9.0.0-34042.tar).
3.  Decompress the LLVM installation package to  **\~/llvm**.

    ```
    tar -xvf llvm-linux-9.0.0-34042.tar -C ~/
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


### Installing hc-gen<a name="section351420104218"></a>

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


## Installing a Windows Development Environment<a name="section188621583120"></a>

The OpenHarmony IDE Development Tool \(HUAWEI DevEco Device Tool\) integrates the capabilities of terminal tools. For details about how to install the tool, see  [Preparations ](https://device.harmonyos.com/en/docs/ide/user-guides/tool_install-0000001050164976)and  [Importing and Configuring a Project](https://device.harmonyos.com/en/docs/ide/user-guides/import_project-0000001050164980).

