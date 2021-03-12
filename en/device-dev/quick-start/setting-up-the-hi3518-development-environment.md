# Setting Up the Hi3518 Development Environment<a name="EN-US_TOPIC_0000001054022306"></a>

-   [Prerequisites](#section2074878255)
-   [Requirements Specific to the Hi3518 Development Environment](#section1724111409282)
    -   [Hardware Requirements](#section487353718276)
    -   [Software Requirements](#section17315193935817)

-   [Installing the Linux Compilation Environment](#section8831868501)
    -   [Installing a File Packing Tool](#section480195453419)
    -   [Installing hc-gen](#section351420104218)


## Prerequisites<a name="section2074878255"></a>

You must complete the settings in  [Basic OS Environment Setup](basic-os-environment-setup.md).

## Requirements Specific to the Hi3518 Development Environment<a name="section1724111409282"></a>

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
<tbody><tr id="row08231641105420"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p1682494111548"><a name="p1682494111548"></a><a name="p1682494111548"></a>dosfstools, mtools, and mtd-utils</p>
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


