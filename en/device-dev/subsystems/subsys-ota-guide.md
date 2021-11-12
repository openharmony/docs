# OTA Update<a name="EN-US_TOPIC_0000001163932574"></a>

-   [Introduction](#section753413913562)
-   [Constraints](#section61232796162135)
-   [Generating a Public/Private Key Pair](#section1392711588162135)
-   [Generating an Update Package](#section704519924162135)
    -   [Mini and Small Systems](#section527064658162135)
    -   [Standard System](#section1291354584162135)

-   [Uploading the Update Package](#section1040019352162135)
-   [Downloading the Update Package](#section1870792413162135)
-   [Integrating OTA Update Capabilities](#section2107348555162135)
-   [API Application Scenario \(Default\)](#section1308521557162135)
    -   [How to Develop](#section2103641927162135)
    -   [Sample Code](#section1918621904162135)

-   [API Application Scenario \(Custom\)](#section1332839930162135)
    -   [How to Develop](#section2120976727162135)
    -   [Sample Code](#section1743369672162135)

-   [Upgrading the System](#section1704276175162135)

## Introduction<a name="section753413913562"></a>

Over the Air \(OTA\) is a technology that makes it easier for you to remotely update devices, such as IP cameras. Currently, the mini and small systems support update using a full package, but not a differential package. A full package contains all content of a new system, and a differential package contains the differences between the old and new systems.

## Constraints<a name="section61232796162135"></a>

-   Only the open-source suites for devices powered by Hi3861, Hi3518E V300, and Hi3516D V300 are supported.
-   Devices developed based on Hi3518E V300 and Hi3516D V300 must support the SD card in the Virtual Festival of Aerobatic Teams \(VFAT\) format.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Generation of update packages can only be performed on the Linux system.


## Generating a Public/Private Key Pair<a name="section1392711588162135"></a>

1.  Download the  [OpenSSL](http://slproweb.com/products/Win32OpenSSL.html)  tool, install it on a Windows PC, and configure environment variables.
2.  Use the OpenSSL tool to generate a public/private key pair.
3.  Keep the private key file properly as this file stores the private key used to sign the update package. You need to specify the private key file in the command used for preparing the update package. The public key is used to verify the signature of the update package during the upgrade, and it is stored as follows:

    For the mini and small systems, the generated public key is preset in the code. The vendor needs to implement the  **HotaHalGetPubKey**  API to obtain the key. For the standard system, the generated public key is stored in the  **./device/hisilicon/hi3516dv300/build/updater\_config/signing\_cert.crt**  file.

4.  For the mini and small systems that use the Hi3518E V300 or Hi3516D V300 suite, also use the content in  **public\_arr.txt**  to replace the content in  **g\_pub\_key**  in the  **device\\hisilicon\\third\_party\\uboot\\u-boot-2020.01\\product\\hiupdate\\verify\\update\_public\_key.c**  file of the U-Boot module.

    Example configuration for the public key of the U-Boot module:

    ```
    static unsigned char g_pub_key[PUBKEY_LEN] = {
        0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01,
        0x00, 0xBF, 0xAA, 0xA5, 0xB3, 0xC2, 0x78, 0x5E,
    }
    ```


## Generating an Update Package<a name="section704519924162135"></a>

### Mini and Small Systems<a name="section527064658162135"></a>

1.  Create the  **target\_package**  folder with the following directory structure:

    ```
     target_package
     ├── OTA.tag
     ├── config
     ├── {component_1}
     ├── {component_2}
     ├── ...
     ├── {component_N}
     └── updater_config
         └── updater_specified_config.xml
    ```

2.  Place the components to be updated, including the image file \(for example,  **rootfs.img**\), as \{component\_N\} in the root directory of the  **target\_package**  folder.
3.  Configure the  **updater\_specified\_config.xml**  file in the  **update\_config**  folder.

    Example configuration of the  **updater\_specified\_config.xml**  file:

    ```
    <?xml version="1.0"?>
    <package>
        <head name="Component header information">
            <info fileVersion="01" prdID="hisi" softVersion="OpenHarmony x.x" date="202x.xx.xx" time="xx:xx:xx">head info</info>
        </head>
        <group name="Component information">
        <component compAddr="ota_tag" compId="27" resType="5" compType="0" compVer="1.0">./OTA.tag</component>
        <component compAddr="config" compId="23" resType="5" compType="0" compVer="1.0">./config</component>
        <component compAddr="bootloader" compId="24" resType="5" compType="0" compVer="1.0">./u-boot-xxxx.bin</component>
        </group>
    </package>
    ```

    **Table 1**  Description of nodes in the component configuration file

    <a name="table252476175162135"></a>
    <table><thead align="left"><tr id="row479509028162135"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="entry1406757300162135p0"><a name="entry1406757300162135p0"></a><a name="entry1406757300162135p0"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.2"><p id="entry442152588162135p0"><a name="entry442152588162135p0"></a><a name="entry442152588162135p0"></a>Node Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.3"><p id="entry1001010016162135p0"><a name="entry1001010016162135p0"></a><a name="entry1001010016162135p0"></a>Node Label</p>
    </th>
    <th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="entry523786033162135p0"><a name="entry523786033162135p0"></a><a name="entry523786033162135p0"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="entry1703280805162135p0"><a name="entry1703280805162135p0"></a><a name="entry1703280805162135p0"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1146183787162135"><td class="cellrowborder" rowspan="6" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p1965185185211"><a name="p1965185185211"></a><a name="p1965185185211"></a>Header information (head node)</p>
    </td>
    <td class="cellrowborder" rowspan="6" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="entry787291920162135p0"><a name="entry787291920162135p0"></a><a name="entry787291920162135p0"></a>info</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="entry1321423743162135p0"><a name="entry1321423743162135p0"></a><a name="entry1321423743162135p0"></a>/</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="entry414082731162135p0"><a name="entry414082731162135p0"></a><a name="entry414082731162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="entry783609139162135p0"><a name="entry783609139162135p0"></a><a name="entry783609139162135p0"></a>Content of this node: head info</p>
    </td>
    </tr>
    <tr id="row1958159196162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry1679905595162135p0"><a name="entry1679905595162135p0"></a><a name="entry1679905595162135p0"></a>fileVersion</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry658282018162135p0"><a name="entry658282018162135p0"></a><a name="entry658282018162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry1810096705162135p0"><a name="entry1810096705162135p0"></a><a name="entry1810096705162135p0"></a>This field is reserved and does not affect the generation of the update package.</p>
    </td>
    </tr>
    <tr id="row147166457162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry1081707070162135p0"><a name="entry1081707070162135p0"></a><a name="entry1081707070162135p0"></a>prdID</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry1297695863162135p0"><a name="entry1297695863162135p0"></a><a name="entry1297695863162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry876347577162135p0"><a name="entry876347577162135p0"></a><a name="entry876347577162135p0"></a>This field is reserved and does not affect the generation of the update package.</p>
    </td>
    </tr>
    <tr id="row713278098162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry1527725234162135p0"><a name="entry1527725234162135p0"></a><a name="entry1527725234162135p0"></a>softVersion</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry1298699378162135p0"><a name="entry1298699378162135p0"></a><a name="entry1298699378162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry1986606994162135p0"><a name="entry1986606994162135p0"></a><a name="entry1986606994162135p0"></a>Software version number, that is, the version number of the update package. The version number must be within the range specified by <strong id="b1587416137107"><a name="b1587416137107"></a><a name="b1587416137107"></a>VERSION.mbn</strong>. Otherwise, an update package will not be generated.</p>
    </td>
    </tr>
    <tr id="row1998569355162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry40037754162135p0"><a name="entry40037754162135p0"></a><a name="entry40037754162135p0"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry1867473067162135p0"><a name="entry1867473067162135p0"></a><a name="entry1867473067162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry1898510646162135p0"><a name="entry1898510646162135p0"></a><a name="entry1898510646162135p0"></a>Date when the update package is generated. This field is reserved and does not affect the generation of the update package.</p>
    </td>
    </tr>
    <tr id="row853604644162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry341395756162135p0"><a name="entry341395756162135p0"></a><a name="entry341395756162135p0"></a>time</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry411979929162135p0"><a name="entry411979929162135p0"></a><a name="entry411979929162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry1952723593162135p0"><a name="entry1952723593162135p0"></a><a name="entry1952723593162135p0"></a>Time when the update package is generated. This field is reserved and does not affect the generation of the update package.</p>
    </td>
    </tr>
    <tr id="row311903547162135"><td class="cellrowborder" rowspan="5" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="entry1756487158162135p0"><a name="entry1756487158162135p0"></a><a name="entry1756487158162135p0"></a>Component information (group node)</p>
    </td>
    <td class="cellrowborder" rowspan="5" valign="top" width="20%" headers="mcps1.1.6.1.2 "><p id="entry2070156141162135p0"><a name="entry2070156141162135p0"></a><a name="entry2070156141162135p0"></a>component</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.3 "><p id="entry894043714162135p0"><a name="entry894043714162135p0"></a><a name="entry894043714162135p0"></a>/</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="entry1899300718162135p0"><a name="entry1899300718162135p0"></a><a name="entry1899300718162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="entry1457912275162135p0"><a name="entry1457912275162135p0"></a><a name="entry1457912275162135p0"></a>Content of this node: path of the component or image file to be packed into the update package. It is the root directory of the version package by default.</p>
    </td>
    </tr>
    <tr id="row691331702162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry1271021967162135p0"><a name="entry1271021967162135p0"></a><a name="entry1271021967162135p0"></a>compAddr</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry967575438162135p0"><a name="entry967575438162135p0"></a><a name="entry967575438162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry2010019875162135p0"><a name="entry2010019875162135p0"></a><a name="entry2010019875162135p0"></a>Name of the partition corresponding to the component, for example, <strong id="b19437823131512"><a name="b19437823131512"></a><a name="b19437823131512"></a>system</strong> or <strong id="b375692501514"><a name="b375692501514"></a><a name="b375692501514"></a>vendor</strong>.</p>
    </td>
    </tr>
    <tr id="row849226815162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry21721216162135p0"><a name="entry21721216162135p0"></a><a name="entry21721216162135p0"></a>compId</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry674558287162135p0"><a name="entry674558287162135p0"></a><a name="entry674558287162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry1193039499162135p0"><a name="entry1193039499162135p0"></a><a name="entry1193039499162135p0"></a>Component ID, which must be unique.</p>
    </td>
    </tr>
    <tr id="row813205598162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry897639380162135p0"><a name="entry897639380162135p0"></a><a name="entry897639380162135p0"></a>resType</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry204468393162135p0"><a name="entry204468393162135p0"></a><a name="entry204468393162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry1005669355162135p0"><a name="entry1005669355162135p0"></a><a name="entry1005669355162135p0"></a>This field is reserved and does not affect the generation of the update package.</p>
    </td>
    </tr>
    <tr id="row2087193735162135"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="entry800634310162135p0"><a name="entry800634310162135p0"></a><a name="entry800634310162135p0"></a>compType</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="entry1484190922162135p0"><a name="entry1484190922162135p0"></a><a name="entry1484190922162135p0"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="entry894563848162135p0"><a name="entry894563848162135p0"></a><a name="entry894563848162135p0"></a>Image type, which can be a full or differential package. The value <strong id="b16850185911295"><a name="b16850185911295"></a><a name="b16850185911295"></a>0</strong> indicates a full package, and value <strong id="b2095321320305"><a name="b2095321320305"></a><a name="b2095321320305"></a>1</strong> indicates a differential package.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >As mini and small systems do not support update using a differential package,  **compType**  must be set to  **0**, other than  **1**.
    >For mini and small systems, an update package cannot be created by changing partitions.

4.  Create the  **OTA.tag**  file, which contains the magic number of the update package. The magic number is as follows:

    ```
    package_type:ota1234567890qwertw
    ```

5.  Create the  **config**  file, and configure the  **bootargs**  and  **bootcmd**  information in the file.

    Example configuration:

    ```
    setenv bootargs 'mem=128M console=ttyAMA0,115200 root=/dev/mmcblk0p3 rw rootfstype=ext4 rootwait blkdevparts=mmcblk0:1M
    (u-boot.bin),9M(kernel.bin),50M(rootfs_ext4.img),50M(userfs.img)' setenv bootcmd 'mmc read 0x0 0x82000000 0x800 0x4800;bootm 0x82000000'
    ```

6.  Generate the update package.

    ```
    python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key3072.pem -nz -nl2x
    ```

    -   **./target\_package/**: path of  **target\_package**
    -   **./output\_package/**: output path of the update package
    -   **-pk ./rsa\_private\_key3072.pem**: path of the private key file
    -   **-nz**:  **not zip**  mode
    -   **-nl2**: non-standard system mode


### Standard System<a name="section1291354584162135"></a>

1.  Create the  **target\_package**  folder with the following directory structure:

    ```
    target_package
    ├── {component_1}
    ├── {component_2}
    ├── ...
    ├── {component_N}
    └── updater_config
            ├── BOARD.list
            ├── VERSION.mbn
            └── updater_specified_config.xml
    ```

2.  Place the components to be updated, including the image file \(for example,  **system.img**\), as \{component\_N\} in the root directory of the  **target\_package**  folder.

3.  Configure the component configuration file in the  **update\_config**  folder.

4.  Configure the list of products supported by the current update package in  **BOARD.list**  in the  **update\_config**  folder.

    Example configuration:

    ```
    HI3516
    HI3518
    ```

5.  Configure the versions supported by the current update package in  **VERSION.mbn**  in the  **update\_config**  folder.

    Version number format: Hi3516DV300-eng 10 QP1A.XXXXXX.\{Major version number \(6 digits\)\}.XXX\{Minor version number \(3 digits\)\}

    For example, Hi3516DV300-eng 10 QP1A.190711.020, where  **190711**  is the major version number, and  **020**  is the minor version number.

    Example configuration:

    ```
    Hi3516DV300-eng 10 QP1A.190711.001
    Hi3516DV300-eng 10 QP1A.190711.020
    Hi3518DV300-eng 10 QP1A.190711.021
    ```

6.  For update using an incremental \(differential\) package, also prepare a source version package \(source\_package\) in the same format as the target version package \(target\_package\), and then compress it as a  **.zip**  file, that is,  **source\_package.zip**.

7.  If you create an update package with partitions changed, also provide the partition table file named  **partition\_file.xml**. You can specify the file using the  **-pf**  parameter. For details about the configuration nodes, see the description below.

    The partition table is generated with the image. The format is as follows:

    ```
    <?xml version="1.0" encoding="GB2312" ?>
    <Partition_Info>
    <Part Sel="1" PartitionName="Image 1" FlashType="Flash type" FileSystem="File system type" Start="Start address of the partition" Length="Size of the partition" SelectFile="Actual path of the image"/>
    <Part Sel="1" PartitionName="Image 2" FlashType="Flash type" FileSystem="File system type" Start="Start address of the partition" Length="Size of the partition" SelectFile="Actual path of the image"/>
    </Partition_Info>
    ```

    **Table 2**  Description of labels in the partition table

    <a name="table806330288162135"></a>
    <table><thead align="left"><tr id="row682144517162135"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry387204270162135p0"><a name="entry387204270162135p0"></a><a name="entry387204270162135p0"></a>Label</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry750055172162135p0"><a name="entry750055172162135p0"></a><a name="entry750055172162135p0"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1074495132162135"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1271686486162135p0"><a name="entry1271686486162135p0"></a><a name="entry1271686486162135p0"></a>Sel</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1588639785162135p0"><a name="entry1588639785162135p0"></a><a name="entry1588639785162135p0"></a>Whether the partition is effective. The value <strong id="b156151453173416"><a name="b156151453173416"></a><a name="b156151453173416"></a>1</strong> indicates that the partition is effective, and value <strong id="b166297633517"><a name="b166297633517"></a><a name="b166297633517"></a>0</strong> indicates the opposite.</p>
    </td>
    </tr>
    <tr id="row1838873028162135"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry405380697162135p0"><a name="entry405380697162135p0"></a><a name="entry405380697162135p0"></a>PartitionName</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry539229490162135p0"><a name="entry539229490162135p0"></a><a name="entry539229490162135p0"></a>Partition name, for example, <strong id="b1173483114376"><a name="b1173483114376"></a><a name="b1173483114376"></a>fastboot</strong> or <strong id="b163708336376"><a name="b163708336376"></a><a name="b163708336376"></a>boot</strong>.</p>
    </td>
    </tr>
    <tr id="row1321400941162135"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry360591364162135p0"><a name="entry360591364162135p0"></a><a name="entry360591364162135p0"></a>FlashType</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1536610466162135p0"><a name="entry1536610466162135p0"></a><a name="entry1536610466162135p0"></a>Flash type, for example, <strong id="b1711717453820"><a name="b1711717453820"></a><a name="b1711717453820"></a>emmc</strong> or <strong id="b86479117387"><a name="b86479117387"></a><a name="b86479117387"></a>ufs</strong>.</p>
    </td>
    </tr>
    <tr id="row1724163696162135"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry278309753162135p0"><a name="entry278309753162135p0"></a><a name="entry278309753162135p0"></a>FileSystem</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry218585771162135p0"><a name="entry218585771162135p0"></a><a name="entry218585771162135p0"></a>File system type, for example, <strong id="b63519206383"><a name="b63519206383"></a><a name="b63519206383"></a>ext3/4</strong> or <strong id="b172821252383"><a name="b172821252383"></a><a name="b172821252383"></a>f2fs</strong>. The value can also be <strong id="b63162773815"><a name="b63162773815"></a><a name="b63162773815"></a>none</strong>.</p>
    </td>
    </tr>
    <tr id="row1809526161162135"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1440557777162135p0"><a name="entry1440557777162135p0"></a><a name="entry1440557777162135p0"></a>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry814481339162135p0"><a name="entry814481339162135p0"></a><a name="entry814481339162135p0"></a>Start address of the partition, in MB. The start address of all partitions is <strong id="b1171284398"><a name="b1171284398"></a><a name="b1171284398"></a>0</strong>.</p>
    </td>
    </tr>
    <tr id="row1052365500162135"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry463606592162135p0"><a name="entry463606592162135p0"></a><a name="entry463606592162135p0"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry18613946162135p0"><a name="entry18613946162135p0"></a><a name="entry18613946162135p0"></a>Size of the partition, in MB.</p>
    </td>
    </tr>
    <tr id="row2062761324162135"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1424721291162135p0"><a name="entry1424721291162135p0"></a><a name="entry1424721291162135p0"></a>SelectFile</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1154631273162135p0"><a name="entry1154631273162135p0"></a><a name="entry1154631273162135p0"></a>Actual path of the image or file.</p>
    </td>
    </tr>
    </tbody>
    </table>

8.  Generate the update package.

    **Full package**

    Run the following command:

    ```
    python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key3072.pem
    ```

    -   **./target\_package/**: path of  **target\_package**
    -   **./output\_package/**: output path of the update package
    -   **-pk ./rsa\_private\_key3072.pem**: path of the private key file

    **Incremental \(differential\) package**

    Run the following command:

    ```
    python build_update.py ./target_package/ ./output_package/  -s ./source_package.zip  -pk ./rsa_private_key3072.pem
    ```

    -   **./target\_package/**: path of  **target\_package**
    -   **./output\_package/**: output path of the update package
    -   **-s ./source\_package.zip**: path of the  **source\_package.zip**  file. For update using a differential package, use the  **-s**  parameter to specify the source version package.
    -   **-pk ./rsa\_private\_key3072.pem**: path of the private key file

    **Update package with partitions changed**

    Run the following command:

    ```
    python build_update.py  ./target_package/ ./output_package/  -pk ./rsa_private_key3072.pem  -pf ./partition_file.xml
    ```

    -   **./target\_package/**: path of  **target\_package**
    -   **./output\_package/**: output path of the update package
    -   **-pk ./rsa\_private\_key3072.pem**: path of the private key file
    -   **-pf ./partition\_file.xml**: path of the partition table file


## Uploading the Update Package<a name="section1040019352162135"></a>

Upload the update package to the vendor's OTA server.

## Downloading the Update Package<a name="section1870792413162135"></a>

1.  Download the update package from the OTA server.
2.  \(Optional\) Insert an SD card \(with a capacity greater than 100 MB\) if the device is developed based on Hi3518E V300 or Hi3516D V300.

## Integrating OTA Update Capabilities<a name="section2107348555162135"></a>

1.  For mini and small systems

    -   If a vendor requests OTA capabilities, use the dynamic library  **libhota.so**  and include the header files  **hota\_partition.h**  and  **hota\_updater.h**  in  **base\\update\\ota\_lite\\interfaces\\kits**.

    -   The  **libhota.so**  source code is stored in  **base\\update\\ota\_lite\\frameworks\\source**.

    -   For details about how to use APIs, see  _API Application Scenario_  and OTA APIs in  _API Reference_.

    -   If the development board needs to be adapted, see the  **base\\update\\ota\_lite\\hals\\hal\_hota\_board.h**  file.

2.  For the standard system, see the  _JS Reference Specifications_  for details.


## API Application Scenario \(Default\)<a name="section1308521557162135"></a>

The update package is generated by following the instructions provided in Generating a Public/Private Key Pair and Generating an Update Package.

### **How to Develop**<a name="section2103641927162135"></a>

1.  Download the update package for the current device, and then call the  **HotaInit**  function to initialize the OTA module.

2.  Call the  **HotaWrite**  function to verify, parse, and write data streams into the device.

3.  Call the  **HotaRestart**  function to restart the system for the update to take effect. Call the  **HotaCancel**  function if you want to cancel the update.


### **Sample Code**<a name="section1918621904162135"></a>

Perform an OTA update using the update package format and verification method provided by OpenHarmony.

```
int main(int argc, char **argv)
{
    printf("this is update print!\r\n");
    if (HotaInit(NULL, NULL) < 0) {
        printf("ota update init fail!\r\n");
        return -1;
    }
    int fd = open(OTA_PKG_FILE, O_RDWR, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("file open failed, fd = %d\r\n", fd);
        (void)HotaCancel();
        return -1;
    }
    int offset = 0;
    int fileLen = lseek(fd, 0, SEEK_END);
    int leftLen = fileLen;
    while (leftLen > 0) {
        if (lseek(fd, offset, SEEK_SET) < 0) {
            close(fd);
            printf("lseek fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        int tmpLen = leftLen >= READ_BUF_LEN ? READ_BUF_LEN : leftLen;
        (void)memset_s(g_readBuf, READ_BUF_LEN, 0, READ_BUF_LEN);
        if (read(fd, g_readBuf, tmpLen) < 0) {
            close(fd);
            printf("read fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        if (HotaWrite((unsigned char *)g_readBuf, offset, tmpLen) != 0) {
            printf("ota write fail!\r\n");
            close(fd);
            (void)HotaCancel();
            return -1;
        }
        offset += READ_BUF_LEN;
        leftLen -= tmpLen;
    }
    close(fd);
    printf("ota write finish!\r\n");
    printf("device will reboot in 10s...\r\n");
    sleep(10);
    (void)HotaRestart();
    return 0;
}
```

## API Application Scenario \(Custom\)<a name="section1332839930162135"></a>

The update package is generated in other ways instead of following the instructions provided in Generating a Public/Private Key Pair and Generating an Update Package.

### **How to Develop**<a name="section2120976727162135"></a>

1.  Download the update package for the current device, and then call the  **HotaInit**  function to initialize the OTA module.

2.  Call the  **HotaSetPackageType**  function to set the package type to  **NOT\_USE\_DEFAULT\_PKG**.

3.  Call the  **HotaWrite**  function to write data streams into the device.

4.  Call the  **HotaRead**  function to read data. Vendors can choose whether to verify the data.

5.  \(Optional\) Call the  **HotaSetBootSettings**  function to set the startup tag used for entering the U-Boot mode during system restarting.

6.  Call the  **HotaRestart**  function to restart the system for the update to take effect. Call the  **HotaCancel**  function if you want to cancel the update.


### **Sample Code**<a name="section1743369672162135"></a>

Perform an OTA update using the update package format and verification method not provided by OpenHarmony.

```
int main(int argc, char **argv)
{
    printf("this is update print!\r\n");
    if (HotaInit(NULL, NULL) < 0) {
        printf("ota update init fail!\r\n");
        (void)HotaCancel();
        return -1;
    }
    (void)HotaSetPackageType(NOT_USE_DEFAULT_PKG);
    int fd = open(OTA_PKG_FILE, O_RDWR, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("file open failed, fd = %d\r\n", fd);
        (void)HotaCancel();
        return -1;
    }
    int offset = 0;
    int fileLen = lseek(fd, 0, SEEK_END);
    int leftLen = fileLen;
    while (leftLen > 0) {
        if (lseek(fd, offset, SEEK_SET) < 0) {
            close(fd);
            printf("lseek fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        int tmpLen = leftLen >= READ_BUF_LEN ? READ_BUF_LEN : leftLen;
        (void)memset_s(g_readBuf, READ_BUF_LEN, 0, READ_BUF_LEN);
        if (read(fd, g_readBuf, tmpLen) < 0) {
            close(fd);
            printf("read fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        if (HotaWrite((unsigned char *)g_readBuf, offset, tmpLen) != 0) {
            printf("ota write fail!\r\n");
            close(fd);
            (void)HotaCancel();
            return -1;
        }
        offset += READ_BUF_LEN;
        leftLen -= tmpLen;
    }
    close(fd);
    printf("ota write finish!\r\n");
    leftLen = fileLen;
    while (leftLen > 0) {
        int tmpLen = leftLen >= READ_BUF_LEN ? READ_BUF_LEN : leftLen;
        (void)memset_s(g_readBuf, READ_BUF_LEN, 0, READ_BUF_LEN);
        if (HotaRead(offset, READ_BUF_LEN, (unsigned char *)g_readBuf) != 0) {}
            printf("ota write fail!\r\n");
            (void)HotaCancel();
            return -1;
        }
        /* do your verify and parse */
        offset += READ_BUF_LEN;
        leftLen -= tmpLen;
    }
    /* set your boot settings */
    (void)HotaSetBootSettings();
    printf("device will reboot in 10s...\r\n");
    sleep(10);
    (void)HotaRestart();
    return 0;
}
```

## Upgrading the System<a name="section1704276175162135"></a>

Vendor applications call APIs of the OTA module to perform functions such as signature verification of the update package, anti-rollback, burning and data flushing-to-disk. After the update is complete, the system automatically restarts.

For the mini and small systems that use the Hi3518E V300 or Hi3516D V300 open source suite, add the value of  **LOCAL\_VERSION**  to the version that needs to implement the anti-rollback function. For example, for  **"ohos default 1.0"-\>"ohos default 1.1"**, add the value of  **LOCAL\_VERSION**  in  **device\\hisilicon\\third\_party\\uboot\\u-boot-2020.01\\product\\hiupdate\\ota\_update\\ota\_local\_info.c**.

Example for modification of the local version:

```
const char *get_local_version(void)
{
#if defined(CONFIG_TARGET_HI3516EV200) || \
    defined(CONFIG_TARGET_HI3516DV300) || \
    defined(CONFIG_TARGET_HI3518EV300)
#define LOCAL_VERSION "ohos default 1.0" /* increase: default release version */
```

