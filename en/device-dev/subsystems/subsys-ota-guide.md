# OTA Update


## Introduction


### Overview

With the rapid development of device systems, it has become a critical challenge for device vendors to help their users to access system updates in a timely manner to experience the new features and improve the system stability and security

Over the Air (OTA) answers this challenge with the support for remote updating of device systems. By providing unified update APIs externally, the update subsystem shields the differences of underlying chips. After secondary development based on the update APIs, device vendors can easily implement remote updating for their devices, such as IP cameras.


### Basic Concepts

- Full package: an update package that packs all images of the target version.

- Differential package: an update package that packs the differential images between the source version and target version.


### Principles

To implement an OTA update, you first need to use the packaging tool to pack the build version into an update package and upload the update package to the OTA server. Devices integrating the OTA update capability can then detect the update package and download it to implement a remote update.

<a href="#ab-update">A/B Update</a>: a typical application of OTA update. In this update mode, a device has a backup system B. When system A is running, system B is updated silently. After the update is successful, the device restarts and switches to the new system.


### Constraints

- Only the open-source suites for devices powered by Hi3861, Hi3516D V300, and RK3568 are supported.

- Devices developed based on Hi3516D V300 and RK3568 must support the SD card in the Virtual Festival of Aerobatic Teams (VFAT) format.

- Generation of update packages can only be performed on the Linux system.

- Currently, the mini and small systems support update using a full package, but not a differential package or an update package with partitions changed.

- To implement an A/B update, ensure that the devices running the standard system support booting from partitions A and B.


## Preparations

- On Windows, download and install the OpenSSL tool and configure environment variables.
- Prepare the packaging tool.
- Build version images using the packaging tool.
- Copy the **diff** file in **out/rk3568/clang_x64/updater/updater/** and the **libext2fs.so**, **e2fsdriod**, **libext2_com_err.so**, and **libext2_misc.so** files in **out/rk3568/clang_x64/thirdparty/e2fsprogs** to the **packaging_tools/lib/** directory of the packaging tool.


## How to Develop

<a href="#generating-a-public/private-key-pair">1. Use the OpenSSL tool to generate a public/private key pair.

<a href="#making-an-update-package">2. Use the packaging tool to generate an update package.</a>

&ensp;&ensp;<a href="#mini-and-small systems">2.1 Mini and small systems</a>

&ensp;&ensp;<a href="#standard system">2.2 Standard system</a>

<a href="#uploading-the-update package">3. Upload the update package to the vendor's OTA server.</a>

<a href="#downloading-the-update-package">4. Download the update package from the vendor's OTA server.</a>

<a href="#integrating-the-OTA-update-capability">5. Integrate the OTA update capability.

&ensp;&ensp;<a href="#api-application-scenario-default">5.1 API application scenario (default)</a>

&ensp;&ensp;<a href="#api-application-scenario-custom">5.2 API application scenario (custom)</a>

&ensp;&ensp;<a href="#ab-update-scenario">5.3 A/B update scenario</a>


## How to Develop


### Generating a Public/Private Key Pair
1. Use the OpenSSL tool to generate a public-private key pair. Place the **signing_cert.crt** file in the **packaging_tools/sign_cert/** directory of the packaging tool.

3. Keep the private key file properly as this file stores the private key used to sign the update package. You need to specify the private key file in the command used for preparing the update package. The public key is used to verify the signature of the update package during the update. For the mini and small systems, the generated public key is preset in the code. The vendor needs to implement the **HotaHalGetPubKey** API to obtain the key. For the standard system, the generated public key is stored in the **/hisilicon/hi3516dv300/build/updater\_config/signing\_cert.crt** file in the **device** or **vendor** directory.

5. For the mini and small systems that use the Hi3516D V300 suite, use the content in **third\_party\u-boot\u-boot-2020.01\product\hiupdate\verify\update\_public\_key.c** file of the U-Boot module.
   Example configuration:

   ```c
   static unsigned char g_pub_key[] = {
       0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01,
       0x00, 0xBF, 0xAA, 0xA5, 0xB3, 0xC2, 0x78, 0x5E,
   }
   ```


### Making an Update Package


#### Mini and Small Systems

1. Create the **target\_package** folder with the following directory structure:

   OTA.tag and config are not required for lightweight systems and small systems upgraded from AB.
     
   ```text
    target_package
    ├── OTA.tag
    ├── config
    ├── {component_1}
    ├── {component_2}
    ├── ......
    ├── {component_N}
    └── updater_config
        └── updater_specified_config.xml
   ```

2. Place the components to be updated, including the image file (for example, **rootfs.img**), as the substitute of **{component\_N}** in the root directory of the **target\_package** folder.

3. Configure the **updater\_specified\_config.xml** file in the **updater_config** folder.
   Example configuration:

     
   ```xml
   <?xml version="1.0"?>
   <package>
       <head name="Component header information">
           <info fileVersion="02" prdID="hisi" softVersion="OpenHarmony x.x" date="202x.xx.xx" time="xx:xx:xx">head info</info>
       </head>
       <group name="Component information">
       <component compAddr="ota_tag" compId="27" resType="5" compType="0" compVer="1.0">./OTA.tag</component>
       <component compAddr="config" compId="23" resType="5" compType="0" compVer="1.0">./config</component>
       <component compAddr="bootloader" compId="24" resType="5" compType="0" compVer="1.0">./u-boot-xxxx.bin</component>
       </group>
   </package>
   ```

     **Table 1** Description of nodes in the component configuration file
   
   | Type| Node Name| Node Label| Mandatory| Description| 
   | -------- | -------- | -------- | -------- | -------- |
   | Header information (head node)| info| / | Yes| Head node information. Set this field to **head info**.| 
   | Header information (head node)| info| fileVersion | Yes| Verification mode of the **update.bin** file. Set this field to **02**.|
   | Header information (head node)| info| prdID | Yes| Reserved. This field does not affect the generation of the update package.| 
   | Header information (head node)| info| softVersion | Yes| Software version number, that is, the version number of the update package. Ensure that the version number is later than the basic version number and OpenHarmony is not followed by any other letter. Otherwise, the update cannot be performed.| 
   | Header information (head node)| info| _date_ | Yes| Date when the update package is generated. This field is reserved and does not affect the generation of the update package.| 
   | Header information (head node)| info| _time_ | Yes| Time when the update package is generated. This field is reserved and does not affect the generation of the update package.|  
   | Component information (group node)| component| / | Yes| Content of this node: path of the component or image file to be packed into the update package. It is the root directory of the version package by default.| 
   | Component information (group node)| component| compAddr | Yes| Name of the partition corresponding to the component, for example, **system** or **vendor**.| 
   | Component information (group node)| component| compId | Yes| Component ID, which must be unique.| 
   | Component information (group node)| component| resType | Yes| Reserved. This field does not affect the generation of the update package.| 
   | Component information (group node)| component| compType | Yes| Image type, which can be a full or differential package. The value **0** indicates a full package, and value **1** indicates a differential package.| 

   > **NOTE**
   > As mini and small systems do not support updating with a differential package, **compType** must be set to **0**, other than **1**.
   > 
   > For mini and small systems, an update package cannot be created by changing partitions.

4. Create the **OTA.tag** file, which contains the magic number of the update package. The magic number is fixed, as shown below:
     
   ```text
   package_type:ota1234567890qwertw
   ```

5. Create the **config** file, and configure the **bootargs** and **bootcmd** information in the file.
   Example configuration:

     
   ```text
   setenv bootargs 'mem=128M console=ttyAMA0,115200 root=/dev/mmcblk0p3 rw rootfstype=ext4 rootwait blkdevparts=mmcblk0:1M
   (u-boot.bin),9M(kernel.bin),50M(rootfs_ext4.img),50M(userfs.img)' setenv bootcmd 'mmc read 0x0 0x82000000 0x800 0x4800;bootm 0x82000000'
   ```

6. Generate the update package.
     
   ```text
   python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key3072.pem -nz -nl2
   ```

   - **./target\_package/**: path of **target\_package**
   - **./output\_package/**: output path of the update package
   - -**pk ./rsa\_private\_key3072.pem**: path of the private key file
   - -**nz**: **not zip** mode
   - -**nl2**: non-standard system mode


#### Standard System
1. Create the **target\_package** folder with the following directory structure:

     
   ```text
   target_package
   ├── {component_1}
   ├── {component_2}
   ├── ......
   ├── {component_N}
   └── updater_config
           ├── BOARD.list
           ├── VERSION.mbn
           └── updater_specified_config.xml
   ```

2. Place the components to be updated, including their image file and **updater_binary** file, as the substitute of **{component\_N}** in the root directory of the **target\_package** folder.

   Take RK3568 as an example. Place the image file in the following build directory: out/rk3568/packages/phone/images/.

   Place the **updater_binary** file in the following build directory: out/rk3568/packages/phone/system/bin/.

3. Configure the component configuration file in the **updater\_config** folder.

4. Configure the list of products supported by the current update package in **BOARD.list** in the **updater\_config** folder.

   Example configuration:

     
   ```text
   HI3516
   RK3568
   ```

   Vendors can configure **Local BoardId** by calling **GetLocalBoardId()** in the **base/updater/updater/utils/utils.cpp** file. Ensure that **Local BoardId** configured in the **utils.cpp** file is present in **BOARD.list**. Otherwise, the update cannot be performed.

5. Configure the versions supported by the current update package in **VERSION.mbn** in the **updater\_config** folder.

   Version number format: Hi3516DV300-eng 10 QP1A.XXXXXX.{Major version number (6 digits)}.XXX{Minor version number (3 digits)}

   For example, **Hi3516DV300-eng 10 QP1A.190711.020**, where **190711** is the major version number, and **020** is the minor version number.

   Example configuration:

     
   ```text
   Hi3516DV300-eng 10 QP1A.190711.001
   Hi3516DV300-eng 10 QP1A.190711.020
   ```

   Ensure that the basic version number is contained in **VERSION.mbn**.

6. For update using an incremental (differential) package, also prepare a source version package (source\_package) in the same format as the target version package (target\_package), and then compress it as a **.zip** file, that is, **source\_package.zip**.

7. If you create an update package with partitions changed, also provide the partition table file named **partition\_file.xml**. You can specify the file using the **-pf** parameter. For details about the configuration nodes, see the description below.

   The partition table is generated with the image. The format is as follows:

     
   ```xml
   <?xml version="1.0" encoding="GB2312" ?>
   <Partition_Info>
   <Part Sel="1" PartitionName="Image 1" FlashType="Flash type" FileSystem="File system type" Start="Start address of the partition" Length="Size of the partition" SelectFile="Actual path of the image"/>
   <Part Sel="1" PartitionName="Image 2" FlashType="Flash type" FileSystem="File system type" Start="Start address of the partition" Length="Size of the partition" SelectFile="Actual path of the image"/>
   </Partition_Info>
   ```

   **Table 2** Description of labels in the partition table

     | Name| Description| 
   | -------- | -------- |
   | Sel | Whether the partition is effective. The value **1** indicates that the partition is effective, and value **0** indicates the opposite.| 
   | PartitionName | Partition name, for example, **fastboot** or **boot**.| 
   | FlashType | Flash type, for example, **emmc** or **ufs**.| 
   | FileSystem | File system type, for example, **ext3/4** or **f2fs**. The value can also be **none**.| 
   | Start | Start address of the partition, in MB. The start address of all partitions is **0**.| 
   | Length | Size of the partition, in MB.| 
   | SelectFile | Actual path of the image or file.| 

8. Generate the update package.

   **Full package**

   Run the following command:

     
   ```text
   python build_update.py ./target_package/ ./output_package/ -pk ./rsa_private_key2048.pem
   ```

   - **./target\_package/**: path of **target\_package**
   - **./output\_package/**: output path of the update package
   - -**pk ./rsa\_private\_key2048.pem**: path of the private key file

   **Incremental (differential) package**

   Run the following command:

     
   ```text
   python build_update.py ./target_package/ ./output_package/  -s ./source_package.zip  -pk ./rsa_private_key2048.pem
   ```

   - **./target\_package/**: path of **target\_package**
   - **./output\_package/**: output path of the update package
   - -**s ./source\_package.zip**: path of the **source\_package.zip** file. For update using a differential package, use the **-s** parameter to specify the source version package.
   - -**pk ./rsa\_private\_key2048.pem**: path of the private key file

   **Update package with partitions changed**

   Run the following command:

     
   ```text
   python build_update.py  ./target_package/ ./output_package/  -pk ./rsa_private_key2048.pem  -pf ./partition_file.xml
   ```

   - **./target\_package/**: path of **target\_package**
   - **./output\_package/**: output path of the update package
   - -**pk ./rsa\_private\_key2048.pem**: path of the private key file
   - -**pf ./partition\_file.xml**: path of the partition table file


### Uploading the Update Package

Upload the update package to the vendor's OTA server.


### **Downloading the Update Package**

1. Download the update package from the OTA server.

2. (Optional) Insert an SD card (with a capacity greater than 100 MB) if the device is developed based on Hi3516D V300.


### Integrating OTA Update Capabilities

1. For mini and small systems

   - Call the dynamic library **libhota.so**. The corresponding header files **hota\_partition.h** and **hota\_updater.h** are located in **base\update\sys\_installer\_lite\interfaces\kits\**.
   - The **libhota.so** source code is located in **base\update\sys\_installer\_lite\frameworks\source**.
   - For details about how to use APIs, see *API Application Scenarios* and update APIs in *API Reference*.
   - If the development board needs to be adapted, see the **base\update\sys\_installer\_lite\hals\hal\_hota\_board.h** file.

2. For the standard system, see the [JS API Reference](../../application-dev/reference/apis/js-apis-update.md) for details.


#### API Application Scenario (Default)

The update package is generated by following the instructions provided in Generating a Public/Private Key Pair and Generating an Update Package.


##### **How to Develop**

1. Download the update package for the current device, and then call the **HotaInit** function to initialize the OTA module.

2. Call the **HotaWrite** function to verify, parse, and write data streams for the update into the device.

3. Call the **HotaRestart** function to restart the system for the update to take effect. Call the **HotaCancel** function if you want to cancel the update.


##### Sample Code

  Perform an OTA update using the update package format and verification method provided by OpenHarmony.
  
```cpp
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


#### API Application Scenario (Custom)

The update package is generated in other ways instead of following the instructions provided in "Generating a Public/Private Key Pair" and "Generating an Update Package."


##### **How to Develop**

1. Download the update package for the current device, and then call the **HotaInit** function to initialize the OTA module.

2. Call the **HotaSetPackageType** function to set the package type to **NOT\_USE\_DEFAULT\_PKG**.

3. Call the **HotaWrite** function to write data streams into the device.

4. Call the **HotaRead** function to read data. Vendors can choose whether to verify the data.

5. (Optional) Call the **HotaSetBootSettings** function to set the startup tag used for entering the U-Boot mode during system restarting.

6. Call the **HotaRestart** function to restart the system for the update to take effect. Call the **HotaCancel** function if you want to cancel the update.


##### Sample Code

  Perform an OTA update using the update package format and verification method not provided by OpenHarmony.
  
```cpp
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
        if (HotaRead(offset, READ_BUF_LEN, (unsigned char *)g_readBuf) != 0) {
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


##### Upgrading the System

An application calls APIs of the OTA module to perform functions such as signature verification of the update package, anti-rollback, as well as burning and flushing to disk. After the update is complete, the system automatically restarts.

For the mini and small systems that use the Hi3516D V300 open source suite, add the value of **LOCAL\_VERSION** to the version that needs to implement the anti-rollback function. For example, for **"ohos default 1.0"-&gt;"ohos default 1.1"**, add the value of **LOCAL\_VERSION** in **device\hisilicon\third\_party\uboot\u-boot-2020.01\product\hiupdate\ota\_update\ota\_local_info.c**.

  Example configuration:
  
```cpp
const char *get_local_version(void)
{
#if defined(CONFIG_TARGET_HI3516EV200) || \
    defined(CONFIG_TARGET_HI3516DV300)
#define LOCAL_VERSION "ohos default 1.0" /* increase: default release version */
```


#### A/B Update Scenario


##### How to Develop

1. Download the update package through the update application.
2. Invoke update_service to start the system installation service through SAMGR.
3. Let the system installation service perform a silent update.
4. Activate the new version upon restarting.


##### How to Develop

- Invoke update_service to call JS APIs to implement the related service logic in an A/B update.

   1. Displaying the update package installation progress:
   ```cpp
   on(eventType: "upgradeProgress", callback: UpdateProgressCallback): void;
   ```
   
   2. Setting the activation policy (immediate restart, restart at night, and activation on next restart):
   ```cpp
   upgrade(apply)
   ```


- Invoke update_service to start the system installation service through SAMGR.
   
   1. Start the system installation service and set up an IPC connection.
   ```cpp
   int SysInstallerInit(void* callback)
   ```
   
   2. Install the A/B update package in the specified path.
   ```cpp
   int StartUpdatePackageZip(string path)
   ```
   
   3. Set the update progress callback.
   ```cpp
   int SetUpdateProgressCallback(void* callback)
   ```
   
   4. Obtain the installation status of the update package (0: not started; 1: installing; 2: installed).
   ```cpp
   int GetUpdateStatus()
   ```


- Use HDI APIs to activate the new version.

   1. Obtain the current boot slot to determine the partition to be updated.
   ```cpp
   int GetCurrentSlot()
   ```
   
   2. Upon completion of the update, switch the updated slot and restart the system for the new version to take effect.
   ```cpp
   int SetActiveBootSlot(int slot)
   ```
   
   3. Upon starting of the update, set the slot of the partition to be updated to the **unbootable** state.
   ```cpp
   int setSlotUnbootable(int slot)
   ```
   
   4. Obtain the number of slots. The value **1** indicates a common update, and the value **2** indicates an A/B update.
   ```cpp
   int32 GetSlotNum(void)
   ```


##### FAQs

1. An exception occurs during installation of the update package.
<br>The system keeps running with the current version. It will attempt a new update in the next package search period.

2. An exception occurs during activation of the new version if the update package is installed in a non-boot partition.
<br>Perform a rollback and set the partition to the **unbootable** state so that the system does not boot from this partition.


##### Verification

In normal cases, the device can download the update package from the OTA server in the background, perform a silent update, and then restart according to the preconfigured activation policy for the new version to take effect.
