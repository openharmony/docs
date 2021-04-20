# Setting Up the Hi3518 Development Environment<a name="EN-US_TOPIC_0000001054022306"></a>

-   [Prerequisites](#section2074878255)
-   [Setting Up the Hi3518 Development Environment](#section1724111409282)
    -   [Hardware Requirements](#section487353718276)
    -   [Software Requirements](#section17315193935817)

-   [Installing the Linux Compilation Environment](#section8831868501)
    -   [Changing Linux Shell to Bash](#section1715027152617)
    -   [Installing Basic Software Used for Compilation and Building \(Required Only for Ubuntu 20+\)](#section45512412251)
    -   [Installing a File Packing Tool](#section480195453419)
    -   [Installing hc-gen](#section351420104218)


## Prerequisites<a name="section2074878255"></a>

You must complete the settings in  [Basic OS Environment Setup](basic-os-environment-setup.md).

## Setting Up the Hi3518 Development Environment<a name="section1724111409282"></a>

### Hardware Requirements<a name="section487353718276"></a>

-   Hi3518E V300 IoT camera development board
-   USB-to-serial cable and network cable \(The Windows workstation is connected to the Hi3518E V300 development board through the USB-to-serial cable and network cable.\)

    The following figure shows the hardware connections.


**Figure  1**  Hardware connections<a name="fig8211468392"></a>  
![](figures/hardware-connections.png "hardware-connections")

### Software Requirements<a name="section17315193935817"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>This section describes how to use an installation package to set up the compilation and development environment. If you are going to use Docker to set up the environment, skip this section and  [Installing the Linux Compilation Environment](#section8831868501).

The following table describes the tools required for setting up the general environment for a Linux server of the Hi3518 development board and how to obtain these tools.

**Table  1**  Development tools and obtaining methods

<a name="table15485545145811"></a>
<table><thead align="left"><tr id="row1748610451588"><th class="cellrowborder" valign="top" width="13.081308130813083%" id="mcps1.2.4.1.1"><p id="p13486154545816"><a name="p13486154545816"></a><a name="p13486154545816"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="19.921992199219922%" id="mcps1.2.4.1.2"><p id="p44867452589"><a name="p44867452589"></a><a name="p44867452589"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="66.996699669967%" id="mcps1.2.4.1.3"><p id="p1748619458583"><a name="p1748619458583"></a><a name="p1748619458583"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row18630134151917"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p1563113417199"><a name="p1563113417199"></a><a name="p1563113417199"></a>bash</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p463193418190"><a name="p463193418190"></a><a name="p463193418190"></a>Processes CLI commands.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p1063118344191"><a name="p1063118344191"></a><a name="p1063118344191"></a>System configuration</p>
</td>
</tr>
<tr id="row7598468212"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p659815642111"><a name="p659815642111"></a><a name="p659815642111"></a>Basic software package for compilation and building (required only for Ubuntu 20+)</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p137174662119"><a name="p137174662119"></a><a name="p137174662119"></a>Provides a basic software package for compilation and building.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p125983652118"><a name="p125983652118"></a><a name="p125983652118"></a>Internet</p>
</td>
</tr>
<tr id="row08231641105420"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p1682494111548"><a name="p1682494111548"></a><a name="p1682494111548"></a>dosfstools, mtools, and mtd-utils</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p1362445934918"><a name="p1362445934918"></a><a name="p1362445934918"></a>Pack files.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p1262475944916"><a name="p1262475944916"></a><a name="p1262475944916"></a>apt-get install</p>
</td>
</tr>
<tr id="row1548710453586"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p15487114585814"><a name="p15487114585814"></a><a name="p15487114585814"></a>hc-gen</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p148719452588"><a name="p148719452588"></a><a name="p148719452588"></a>Configures and compiles files.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p1487164565819"><a name="p1487164565819"></a><a name="p1487164565819"></a><a href="https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar" target="_blank" rel="noopener noreferrer">https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar</a></p>
</td>
</tr>
</tbody>
</table>

## Installing the Linux Compilation Environment<a name="section8831868501"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, compilation tools like  **gn**,  **ninja**,  **LLVM**, and  **hc-gen**  are not required.
>-   \(Recommended\) If you obtain the source code through an image site or a code repository, compilation tools like  **LLVM**  and  **hc-gen**  need to be installed. When installing  **LLVM**  and  **hc-gen**, ensure that the environment variable paths of the compilation tools are unique.

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

**Method 2:**  Run the first command to delete  **sh**  and then run the second command to create a new soft link.

```
sudo rm -rf /bin/sh
sudo ln -s /bin/bash /bin/sh
```

### Installing Basic Software Used for Compilation and Building \(Required Only for Ubuntu 20+\)<a name="section45512412251"></a>

Install the software.

```
sudo apt-get install build-essential && sudo apt-get install gcc && sudo apt-get install g++ && sudo apt-get install make && sudo apt-get install zlib* && sudo apt-get install libffi-dev
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


