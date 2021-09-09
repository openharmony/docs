# Setting Up the Environment<a name="EN-US_TOPIC_0000001174270689"></a>

-   [Environment Requirements](#section179175261196)
    -   [Hardware](#section5840424125014)
    -   [Software](#section965634210501)

-   [Installing Linux Build Tools](#section182916865219)
    -   [Changing Linux Shell to Bash](#section1715027152617)
    -   [Installing Basic Software Used for Compilation and Building \(Required Only for Ubuntu 20+\)](#section45512412251)
    -   [Installing File Packing Tools and JVM](#section16199102083717)


## Environment Requirements<a name="section179175261196"></a>

### Hardware<a name="section5840424125014"></a>

-   Hi3516D V300 IoT camera development board
-   USB-to-serial cable and network cable \(The Windows workstation is connected to the Hi3516D V300 development board through the USB-to-serial cable and network cable.\)

The following figure shows the hardware connections.

**Figure  1**  Hardware connections<a name="fig38451744110"></a>  
![](figure/hardware-connections-0.png "hardware-connections-0")

### Software<a name="section965634210501"></a>

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>This section describes how to use an installation package to set up the compilation and development environment. If you are going to use Docker to set up the environment, skip this section and  [Installing Linux Build Tools](#section182916865219).

The following table describes the tools required for setting up the general environment for a Linux server of the Hi3516 development board and how to obtain these tools.

**Table  1**  Development tools and obtaining methods

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="13.081308130813083%" id="mcps1.2.4.1.1"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="19.921992199219922%" id="mcps1.2.4.1.2"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="66.996699669967%" id="mcps1.2.4.1.3"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row167343191518"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p467443191517"><a name="p467443191517"></a><a name="p467443191517"></a>bash</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p0674153114151"><a name="p0674153114151"></a><a name="p0674153114151"></a>Processes CLI commands.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p116746312151"><a name="p116746312151"></a><a name="p116746312151"></a>System configuration</p>
</td>
</tr>
<tr id="row14885193315201"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p137174662119"><a name="p137174662119"></a><a name="p137174662119"></a>Basic software package for compilation and building (required only for Ubuntu 20+)</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p258814561424"><a name="p258814561424"></a><a name="p258814561424"></a>Provides a basic software package for compilation and building.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p1749611716181"><a name="p1749611716181"></a><a name="p1749611716181"></a>Internet</p>
</td>
</tr>
<tr id="row52253812238"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p28007392236"><a name="p28007392236"></a><a name="p28007392236"></a>dosfstools, mtools, and mtd-utils</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p98008390232"><a name="p98008390232"></a><a name="p98008390232"></a>Pack files.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p280018394233"><a name="p280018394233"></a><a name="p280018394233"></a>apt-get install</p>
</td>
</tr>
<tr id="row29204072315"><td class="cellrowborder" valign="top" width="13.081308130813083%" headers="mcps1.2.4.1.1 "><p id="p5921190162318"><a name="p5921190162318"></a><a name="p5921190162318"></a>Java virtual machine (JVM)</p>
</td>
<td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.2.4.1.2 "><p id="p17921110152311"><a name="p17921110152311"></a><a name="p17921110152311"></a>Compiles, debugs, and runs Java programs.</p>
</td>
<td class="cellrowborder" valign="top" width="66.996699669967%" headers="mcps1.2.4.1.3 "><p id="p16921805237"><a name="p16921805237"></a><a name="p16921805237"></a>apt-get install</p>
</td>
</tr>
</tbody>
</table>

## Installing Linux Build Tools<a name="section182916865219"></a>

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, you do not need to install  **hc-gen**.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install  **hc-gen**. When installing the compilation tool, ensure that its environment variable path is unique.

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
sudo apt-get install build-essential gcc g++ make zlib* libffi-dev
```

### Installing File Packing Tools and JVM<a name="section16199102083717"></a>

1.  Start a Linux server.
2.  Install the dosfstools, mtools, mtd-utils, Java Runtime Environment \(JRE\), and Java SDK.

    ```
    sudo apt-get install dosfstools mtools mtd-utils default-jre default-jdk
    ```


