# Startup


## Context Structure

The following figure shows the context structure of the Startup subsystem.

  **Figure 1** Context structure of the Startup subsystem

  ![context-structure-of-the-startup-subsystem](figure/context-structure-of-the-Startup-subsystem.png)

When the system is powered on, the kernel loads and starts services and applications as follows:

1. The kernel loads the init process, which is specified by **cmdline** of the kernel when the bootloader starts the kernel.
2. After the init process is started, **tmpfs** and **procfs** are mounted and basic **dev** nodes are created to establish a basic root file system.
3. The init process starts the ueventd process to listen for device hot-swap events in the kernel and creates **dev** nodes for related devices  as well as partitions for the block device.
4. After mounting partitions (**system** and **vendor**) of the block device, the init process scans for the init startup script of each system service and starts the respective system ability (SA).
5. Each SA registers with the samgr process, which serves as the service registration center. The samgr process assigns each SA with an ID, which will be used by an application to access the desired SA.
6. The foundation process sends the application startup request to the appspawn process. The foundation implements application lifecycle management. It is a special SA service process that provides the user program management framework and basic services.
7. The appspawn process directly spawns the application process, eliminating the need for the application to load the JS runtime environment. This reduces the application startup time.  


The Startup subsystem consists of the following modules:

- init module
  This module corresponds to the init process, which is the first user-mode process started after the kernel is initialized. After the init process starts, it reads and parses the **init.cfg** file. Based on the parsing result, the init module executes the commands listed in [Table 2](../subsystems/subsys-boot-init.md) and starts the key system service processes in sequence with corresponding permissions granted.

- ueventd module
  This module listens for **netlink** events about hot swap of kernel device drivers and dynamically manages the **dev** node of the corresponding device based on the event type.

- appspawn module
  This module spawns application processes upon receiving commands from the foundation, configures permissions for new processes, and calls the entry function of the application framework.

- bootstrap module
  This module provides entry identifiers for starting services and features. When SAMGR is started, the entry function identified by bootstrap is called and system services are started.

- syspara module
  This module provides APIs for obtaining device information, such as the product name, brand name, and manufacturer name, based on the OpenHarmony Product Compatibility Specifications (PCS). It also provides APIs for setting and obtaining system attributes.


## Constraints

  The source code directory of the Startup subsystem varies according to the platform.

  **Table 1** Directories and applicable platforms of the Startup subsystem

| Source Code Directory| Applicable Platform|
| -------- | -------- |
| base/startup/appspawn_lite | Small-system devices (reference memory ≥ 1 MiB), for example, Hi3516D V300 and Hi3518E V300|
| base/startup/bootstrap_lite | Mini-system devices (reference memory ≥ 128 KiB), for example, Hi3861 V100|
| base/startup/init_lite | Small-system devices (reference memory ≥ 1 MiB), for example, Hi3516D V300 and Hi3518E V300|
| base/startup/syspara_lite | - Mini-system devices (reference memory ≥ 128 KiB), for example, Hi3861 V100<br>- Small-system devices (reference memory ≥ 1 MiB), for example, Hi3516D V300 and Hi3518E V300|

- init module
  - To start a system service, you first need to write a boot script file named **init.cfg**, in which you define the service name, path of executable files, permissions, etc.
  - The boot script of each system service is installed in the **/system/etc/init** directory. The init process scans this directory for the boot script to execute.

- When porting a new chip platform, you need to add the **/vendor/etc/init/init.{hardware}.cfg** file that contains the platform-level initialization configuration. This file is used to implement platform-level initialization, for example, installing the ko driver and configuring information on the related **/proc** nodes.

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>

  > The configuration file **init.cfg** must be in JSON format.

- bootstrap module: The zInit code must be configured in the link script.

## Boot Process for the OpenHarmony Standard System

By default, the OpenHarmony standard system supports the images listed in the following table.

| Image    | Mount Point | Description                                                |
| ------------ | ------- | ---------------------------------------------------- |
| boot.img     | NA      | Kernel and ramdisk image, which is the first image loaded by the bootloader.     |
| system.img   | /system | System component image, which stores chip-irrelevant platform services.        |
| vendor.img   | /vendor | Chip component image, which stores chip-related hardware abstraction services.          |
| updater.img  | /       | Updater image, which is used for system updating. This image is not loaded during normal startup.|
| userdata.img | /data   | Writable user data image.                                |

On each development board, you need to partition the memory to store the preceding images. When the SoC starts, the bootloader loads the images as follows:

- Initializes hardware such as the ROM and RAM, and loads the partition table information.
- Loads the **boot.img** file based on the partition table and parses and loads the **ramdisk.img** file to the memory.
- Prepares the partition table information and ramdisk address and enters the kernel, so that the kernel loads the the ramdisk image and starts the init process.
- Waits until the init process prepares the initial file system and mounts **required.fstab** (including **system.img** and **vendor.img**) to the file system.
- Scans the boot scripts in the **etc/init** directory in **system.img** and **vendor.img** and runs each boot command.

### U-Boot Process

[U-Boot](https://elinux.org/U-Boot) is used as an example to describe the key image loading process. When U-Boot starts the system, it passes the boot information to the system by using **bootargs**.

- **boot.img** loading and parsing

  - **boot.img** format

    **boot.img** building and loading varies depending on the platform. The implementation on mainstream OpenHarmony platforms is as follows:

    - Hi3516DV300

      On this platform, the **boot.img** file uses the flattened image tree (FIT) format. It is generated by the Mkimage tool by packing the **zImage-dtb** and **cpio** images, which are generated after kernel compilation, based on the information in the **.its** file.

      The related files and tool are described as follows:

      1. **.its** file

         An image source file that describes the information about the image to be generated. You need to create the file, for example, the **ohos.its** file on the Hi3516 platform.

      2. Mkimage packaging tool

         A tool that parses **its** files and packs the corresponding images based on the image configuration to generate an **itb** file, that is, **boot.img**.

      3. ramdisk

         An image file generated by packing **cpio** images.

      4. zImage-dtb

         An image file that contains the compressed kernel image and device description file image.

    - rk3568

      On this platform, the **boot.img** file is named **boot_linux.img**. The packaged files are different from those on the Hi3516D V300 platform.

      1. Image

         Image file generated after kernel compilation.

      2. toybrick.dtb

         A file that is similar to the device description file image generated after dts compilation.

      3. ramdisk.img

         An image file generated by packing **cpio** images.

  - U-Boot loading

    The ramdisk boot process is supported. In this scenario, you need to modify the product configuration file in **productdefine** and enable ramdisk generation by setting **enable_ramdisk**. The ramdisk processing method varies according to the platform. Take the Hi3516D V300 platform as an example. You need to change the original U-Boot parameter to **root=/dev/ram0 initrd=0x84000000,0x292e00**.


- Kernel start

  When the U-Boot starts the kernel, it can pass key information to the kernel through **bootargs**. The information varies according to the platform. The main fields are described in the table below.

  | Name       | Example                                                        | Description                                                        |
  | ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | initrd      | 0x84000000,0x292e00                                          | For details, see the kernel documentation:<br>[ramfs-rootfs-initramfs.rst](https://gitee.com/openharmony/kernel_linux_5.10/blob/master/Documentation/filesystems/ramfs-rootfs-initramfs.rst)<br>[initrd.rst](https://gitee.com/openharmony/kernel_linux_5.10/blob/master/Documentation/admin-guide/initrd.rst) |
  | init        | /init                                                        |                                                              |
  | blkdevparts | mmcblk0:1M(boot),15M(kernel),200M(system),200M(vendor),<br>2M(misc),20M(updater),-(userdata) | Partition table information. The kernel creates physical partitions based on the information.                |
  | hardware    | Hi3516D V300, rk3568, etc.                                                 | (Mandatory information) Hardware platform.|
  | root        | /dev/ram0 (Hi3516DV00) , root=PARTUUID=614e0000-0000 rw (rk3568)                                                   | Boot device loaded by the kernel.|
  | rootfstype  | ext4                                                         | Type of the root file system.|
  | default_boot_device | soc/10100000.himci.eMMC | (Recommended information) Default boot device. In the first phase of the boot process, a soft link will be created for the required device based on this field.|
  | ohos.required_mount.xxx | /dev/block/platform/soc/10100000.himci.eMMC/by-name/xxx@/usr@ext4@ro,barrier=1@wait,required |  The fstab information is first read from cmdline. If this fails, the system will try to read the information from the **fstab.required** file.|

- Mounting of required partitions

  A required partition is one that is essential for system boot. It must be mounted before level-2 boot. For mandatory images like system and vendor images, the corresponding block device files must be created before mounting. This is usually done based on UEVENT events reported by the kernel. The init process needs to know the main device directory of the storage device. The bootloader passes the primary device directory of the storage device to the init process through **default_boot_device**.

  Currently, the init process obtains required partition information in two ways. The init process first reads the required partition information through the **bootargs** in **/proc/cmdline**. If the attempt fails, the init process reads the **fstab.required** file in the ramdisk image.

    - Logic of block device creation

      - Preparation

      1. The init process reads the required fstab information from **cmdline**. If the attempt fails, the init process reads the **fstab.required** file to obtain **PARTNAME** of the block devices that must be mounted, for example, **system** or **vendor**.
      2. Create a socket for receiving uevent messages reported by the kernel and read **default_boot_device** from **/proc/cmdline**.
      3. Traverse the **/sys/devices** directory with the fstab information and socket handle to get the kernel prepared for reporting uevent messages.

      - Event triggering

      1. Use **ueventd** to trigger the kernel to report a uevent message.
      2. Check whether **partitionName** in the uevent message matches with device information in the required fstab.
      3. If they match, format the device node path and proceed with device node creation.

      - Device node creation

      1. Format the path of the soft link to be created for required block device nodes. A soft link helps facilitate access to device nodes in user mode and improve their readability.
      2. Create device nodes based on the primary and secondary device numbers passed in the uevent message, and the device node path and soft link path obtained in the previous steps. Meanwhile, create a soft link for them.

      Up to now, the creation of block device nodes is complete.

    - Mapping with **default_boot_device**

      The kernel writes **bootargs** information to **/proc/cmdline**. The information includes **default_boot_device**, which specifies the primary device directory required for system boot. The content prefixed with **ohos.required_mount.** is the partition mounting information required for system boot. It should be the same as that in the **fstab.required** file. In addition, the block device node in the partition mounting information should be a device node pointed by the soft link under **by-name** in the **default_boot_device** directory. For example, if the value of **default_boot_device** is **soc/10100000.himci.eMMC**, then the value of **ohos.required_mount.system** contains **/dev/block/platform/soc/10100000.himci.eMMC/by-name/system**, which is the soft link pointing to the system device node.

      During creation of a block device node, the device path will be matched against the value of **default_boot_device**. If the matching is successful, a soft link pointing to the real block device node will be created in **/dev/block/by-name**. In this way, device node access is made irrelevant to the chip platform.

    - Example

      This example assumes the **system** partition as the required partition on the Hi3516D V300 platform to illustrate the boot process. During this process, the init process reads the required fstab information, creates a block device node, and mounts it to the required partition. The following provides the key code snippets and log information as reference for debugging.

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>

      > The code snippets below are exhibited in the logical sequence. They are not neighboring to each other in the source code.

      1. Obtain required device information.
          ```
          Fstab* LoadRequiredFstab(void)
          {
              Fstab *fstab = NULL;
              fstab = LoadFstabFromCommandLine();
              if (fstab == NULL) {
                  INIT_LOGI("Cannot load fstab from command line, try read from fstab.required");
                  const char *fstabFile = "/etc/fstab.required";
                  if (access(fstabFile, F_OK) != 0) {
                      fstabFile = "/system/etc/fstab.required";
                  }
                  INIT_ERROR_CHECK(access(fstabFile, F_OK) == 0, abort(), "Failed get fstab.required");
                  fstab = ReadFstabFromFile(fstabFile, false);
              }
              return fstab;
          }
          ```
          The preceding code provides two methods for the init process to obtain the fstab information. First, the init process calls **LoadFstabFromCommandLine()** to read the fstab information from **cmdline**. If the attempt fails, the init process reads the **fstab.required** file to obtain the fstab information.

          For the **system** partition, the key information read from **devices** is as follows:
          ```
          /dev/block/platform/fe310000.sdhci/by-name/system
          ```

      2. Create a socket and trigger the kernel to report a uevent message.
         ```
         static int StartUeventd(char **requiredDevices, int num)
         {
             INIT_ERROR_CHECK(requiredDevices != NULL && num > 0, return -1, "Failed parameters");
             int ueventSockFd = UeventdSocketInit();
             if (ueventSockFd < 0) {
                 INIT_LOGE("Failed to create uevent socket");
                 return -1;
             }
             RetriggerUevent(ueventSockFd, requiredDevices, num);
             close(ueventSockFd);
             return 0;
         }
         ```

      3. Read information from **cmdline** to obtain **default_boot_device**.
         ```
         char *buffer = ReadFileData("/proc/cmdline");
         int ret = GetProcCmdlineValue("default_boot_device", buffer, bootDevice, CMDLINE_VALUE_LEN_MAX);
         INIT_CHECK_ONLY_ELOG(ret == 0, "Failed to get default_boot_device value from cmdline");
         ```
         In this example, the value of **default_boot_device** is **soc/10100000.himci.eMMC**. The value is stored in the global variable **bootDevice** and will be matched with the path of the **system** partition device when a soft link is created.

      4. Process the uevent message of the required partition device.
         ```
         if (uevent->partitionName == NULL) {
             INIT_LOGI("Match with %s for %s", devices[i], uevent->syspath);
             deviceName = strstr(devices[i], "/dev/block");
             INIT_INFO_CHECK(deviceName != NULL, continue,
                 "device %s not match \"/dev/block\".", devices[i]);
             deviceName += sizeof("/dev/block") - 1;
             INIT_INFO_CHECK(strstr(uevent->syspath, deviceName) != NULL, continue,
                 "uevent->syspath %s not match deviceName %s", uevent->syspath, deviceName);
             HandleBlockDeviceEvent(uevent);
             break;
         } else if (strstr(devices[i], uevent->partitionName) != NULL) {
             INIT_LOGI("Handle block device partitionName %s", uevent->partitionName);
             HandleBlockDeviceEvent(uevent);
             break;
         }
         ```
         In this step, the device information in **devices** is matched with the uevent message reported by the kernel. The value of **uevent->partitionName** should be **system** for the uevent message of the **system** partition device. If the value matches the **/dev/block/platform/fe310000.sdhci/by-name/system** field in **devices**, the uevent message of the **system** partition device will be processed.

      5. Create the required device node and the corresponding soft link.

         The first thing is to format the path of the corresponding soft link. In this step, the value of **default_boot_device** in **bootargs** will be matched with the path of the required device node in the uevent message, so as to create a platform-irrelevant soft link that points to the device node. The key code is as follows:
         ```
         if (STRINGEQUAL(bus, "/sys/bus/platform")) {
             INIT_LOGV("Find a platform device: %s", parent);
             parent = FindPlatformDeviceName(parent);
             if (parent != NULL) {
                 BuildDeviceSymbolLinks(links, linkNum, parent, uevent->partitionName, uevent->deviceName);
             }
             linkNum++;
             if ((parent != NULL) && STRINGEQUAL(parent, bootDevice)) {
                 BuildBootDeviceSymbolLink(links, linkNum, uevent->partitionName);
                 linkNum++;
             }
         }
         ```
         The key variables in the code are as follows:

             **bus**: a string that saves the path of the bus connected to the current device.
             **parent**: a string that stores the device path obtained from **syspath** in the uevent message.
             **links**: a pointer to the memory that stores the soft link path.
             **bootDevice**: a string that stores the value of **default_boot_device** in **bootargs**
         According to the code, the corresponding soft link is created for the device only when the type of the connected bus is **platform**. The path of the soft link is as follows:
         ```
         /dev/block/platform/soc/10100000.himci.eMMC/by-name
         ```
         A platform-irrelevant soft link is created only when the device path matches that in **bootDevice**.

         For the **system** partition device, the path is as follows:
         ```
         /sys/devices/platform/soc/10100000.himci.eMMC/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p5
         ```
         Therefore, when processing the uevent message of the device, the init process compares the device path with that in **bootDevice**, that is, **soc/10100000.himci.eMMC**. If they match, a soft link will be created as follows:
         ```
         /dev/block/by-name/system
         ```

         After the soft link path is formatted, the init process creates the device node and soft link based on the information in the uevent message. Up to now, the creation of a device node for the system partition is complete.

      6. Mount the required partition.

         After a device node is created, mount it to the corresponding partition. The code is as follows:
         ```
          int MountRequriedPartitions(const Fstab *fstab)
          {
              INIT_ERROR_CHECK(fstab != NULL, return -1, "Failed fstab is NULL");
              int rc;
              INIT_LOGI("Mount required partitions");
              rc = MountAllWithFstab(fstab, 1);
              return rc;
          }
         ```
         Therefore, when "Mount required partitions" is displayed, the required partition device is ready for mounting. During the mounting process, the following key information is printed:
         ```
         BEGET_LOGE("Unsupported file system \" %s \"", item->fsType);
         The current file system type is not supported.

         BEGET_LOGE("Cannot get stat of \" %s \", err = %d", target, errno);
         Failed to obtain the mount point directory.

         BEGET_LOGE("Failed to create dir \" %s \", err = %d", target, errno);
         Failed to create the mount point directory.

         BEGET_LOGI("Mount %s to %s successful", item->deviceName, item->mountPoint);
         The device is successfully mounted. The output also contains the name of the mounted device and information about the mount point.
         ```


- Mounting of vendor partitions

​	After mounting required partitions, the init process scans each script file in the **vendor** partition. The initialization scripts related to the chip or development board is named in the format of **/vendor/etc/init.{ohos.boot.hardware}.cfg**. Wherein, **/vendor/etc/fstab.{ohos.boot.hardware}** represents the extended mount partition file; **hardware** is sourced from **bootargs**, which is passed from the bootloader to the kernel.


### Boot Loading Without ramdisk

Certain development boards do not use the ramdisk boot mode. For these boards, the boot process is implemented by directly loading the **system.img** file through the kernel. In such case, you need to modify the product configuration file in **productdefine**. Specifically, you need to turn off the **enable_ramdisk** switch to disable ramdisk generation so that the init process does not boot from ramdisk to system.

The boot loading process in this scenario is similar to that in the preceding section. The only difference is as follows: If ramdisk is used, the init process mounts **system.img** to the **/usr** directory, and then switches to the **/usr** directory using **chroot** and executes the **/etc/init.cfg** script. If ramdisk is not used, there is no chroot process, and the boot script is **init.without_two_stages.cfg**.

For the boot loading process without ramdisk, that is, system as root, the block device where the root file system is located is passed to the kernel through **bootargs**, for example, **root=/dev/mmcblk0p5 and rootfstype=ext4**. During initialization of the root file system, the kernel parses the **root** field in **bootargs** to complete mounting of the root file system.
