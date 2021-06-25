# Setting Up the Environment<a name="EN-US_TOPIC_0000001152389293"></a>

-   [Environment Requirements](#section1724111409282)
    -   [Hardware](#section487353718276)
    -   [Software Requirements](#section17315193935817)

-   [Installing Linux Build Tools](#section8831868501)
    -   [Changing Linux Shell to Bash](#section434110241084)
    -   [Installing Basic Software Used for Compilation and Building \(Required Only for Ubuntu 20+\)](#section25911132141020)
    -   [Installing File Packing Tools](#section390214473129)


## Environment Requirements<a name="section1724111409282"></a>

### Hardware<a name="section487353718276"></a>

-   Hi3518E V300 IoT camera development board
-   USB-to-serial cable and network cable \(The Windows workstation is connected to the Hi3518E V300 development board through the USB-to-serial cable and network cable.\)

    The following figure shows the hardware connections.


**Figure  1**  Hardware connections<a name="fig8211468392"></a>  
![](figures/hardware-connections-3.png "hardware-connections-3")

### Software Requirements<a name="section17315193935817"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>This section describes how to use an installation package to set up the compilation and development environment. If you are going to use Docker to set up the environment, skip this section and  [Installing Linux Build Tools](#section8831868501).

The following table describes the tools required for setting up the general environment for a Linux server of the Hi3518 development board and how to obtain these tools.

**Table  1**  Development tools and obtaining methods

<a name="table15485545145811"></a>
<table><thead align="left"><tr id="row1748610451588"><th class="cellrowborder" valign="top" width="23.332333233323332%" id="mcps1.2.4.1.1"><p id="p13486154545816"><a name="p13486154545816"></a><a name="p13486154545816"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="14.65146514651465%" id="mcps1.2.4.1.2"><p id="p44867452589"><a name="p44867452589"></a><a name="p44867452589"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="62.016201620162015%" id="mcps1.2.4.1.3"><p id="p1748619458583"><a name="p1748619458583"></a><a name="p1748619458583"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row18630134151917"><td class="cellrowborder" valign="top" width="23.332333233323332%" headers="mcps1.2.4.1.1 "><p id="p1563113417199"><a name="p1563113417199"></a><a name="p1563113417199"></a>bash</p>
</td>
<td class="cellrowborder" valign="top" width="14.65146514651465%" headers="mcps1.2.4.1.2 "><p id="p463193418190"><a name="p463193418190"></a><a name="p463193418190"></a>Processes CLI commands.</p>
</td>
<td class="cellrowborder" valign="top" width="62.016201620162015%" headers="mcps1.2.4.1.3 "><p id="p1063118344191"><a name="p1063118344191"></a><a name="p1063118344191"></a>System configuration</p>
</td>
</tr>
<tr id="row7598468212"><td class="cellrowborder" valign="top" width="23.332333233323332%" headers="mcps1.2.4.1.1 "><p id="p659815642111"><a name="p659815642111"></a><a name="p659815642111"></a>Basic software package for compilation and building (required only for Ubuntu 20+)</p>
</td>
<td class="cellrowborder" valign="top" width="14.65146514651465%" headers="mcps1.2.4.1.2 "><p id="p137174662119"><a name="p137174662119"></a><a name="p137174662119"></a>Provides a basic software package for compilation and building.</p>
</td>
<td class="cellrowborder" valign="top" width="62.016201620162015%" headers="mcps1.2.4.1.3 "><p id="p125983652118"><a name="p125983652118"></a><a name="p125983652118"></a>Internet</p>
</td>
</tr>
<tr id="row08231641105420"><td class="cellrowborder" valign="top" width="23.332333233323332%" headers="mcps1.2.4.1.1 "><p id="p1682494111548"><a name="p1682494111548"></a><a name="p1682494111548"></a>dosfstools, mtools, and mtd-utils</p>
</td>
<td class="cellrowborder" valign="top" width="14.65146514651465%" headers="mcps1.2.4.1.2 "><p id="p1362445934918"><a name="p1362445934918"></a><a name="p1362445934918"></a>Pack files.</p>
</td>
<td class="cellrowborder" valign="top" width="62.016201620162015%" headers="mcps1.2.4.1.3 "><p id="p1262475944916"><a name="p1262475944916"></a><a name="p1262475944916"></a>apt-get install</p>
</td>
</tr>
</tbody>
</table>

## Installing Linux Build Tools<a name="section8831868501"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, you do not need to install  **hc-gen**.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install  **hc-gen**. When installing the compilation tool, ensure that its environment variable path is unique.

### Changing Linux Shell to Bash<a name="section434110241084"></a>

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

### Installing Basic Software Used for Compilation and Building \(Required Only for Ubuntu 20+\)<a name="section25911132141020"></a>

Install the software.

```
sudo apt-get install build-essential gcc g++ make zlib* libffi-dev
```

### Installing File Packing Tools<a name="section390214473129"></a>

1.  Start a Linux server.
2.  Install dosfstools, mtools, and mtd-utils.

    ```
    sudo apt-get install dosfstools mtools mtd-utils
    ```


