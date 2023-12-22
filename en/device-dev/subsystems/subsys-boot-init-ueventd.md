# ueventd

## Overview

The **ueventd** module listens for **netlink** events about hot plug of kernel device drivers and dynamically manages the dev node of the corresponding device based on the event type.

## Configuration Files of ueventd

### File Type

The configuration files of the **ueventd** module are stored in the **/base/startup/init/ueventd/etc/** directory. They are classified into three types: **device**, **sysfs**, and **firmware**.

Currently, the **ueventd** module uses configuration files of the **device** type. If needed, set DAC permissions for a created node in such files.

File types are distinguished by the field at the beginning of the file. The following uses **device** as an example:
  ```
    [device] # File type.
    # <device name> <mode> <uid> <gid> <parameter>
    /dev/null 0666 0 0
  ```

### Configuration File Description

  - The configuration file of the **ueventd** module is named **ueventd.config**.

  - The file consists of five fields, for example:

  ```
  /dev/null 0666 0 0
  /dev/binder 0666 0 0
  /dev/hwbinder 0666 0 0
  /dev/vndbinder 0666 0 0
  /dev/input/event* 0660 0 input
  ```

  **Fields in the Configuration File**
  | Field       | Description            |
  | ----------- | ---------------- |
  | device name | Device node name.    |
  | mode        | Permission granted to a device node in compliance with the UGO model.|
  | uid         | UID of a device node.|
  | gid         | GID of a device node.|
  | parameter   | Device node parameter information, which is similar to a notification. If a device is created, a corresponding parameter is set so that other processes can perform operations on the node based on the parameter information.<br>/dev/null 0666 0 0  device_null<br>Take the **dev/null** node as as example:<br>When the device node is created, this field is set to **startup.uevent.device_null "added"**; when the device node is removed, this field is set to **startup.uevet.device_null "removed"**.|

  - Remarks

  The nodes of the boot partition may vary according to devices. Therefore, you can configure soft link permissions in the **ueventd.config** file to change the permissions of the corresponding physical device node.
  These nodes are stored in the **/dev/block/by-name** directory.

  ```
  lrwxrwxrwx 1 root    root    20 2017-08-10 16:22 boot_linux -> /dev/block/mmcblk0p5
  lrwxrwxrwx 1 root    root    20 2017-08-10 16:22 bootctrl -> /dev/block/mmcblk0p3
  lrwxrwxrwx 1 ueventd ueventd 21 2017-08-10 16:22 chip-prod -> /dev/block/mmcblk0p10
  lrwxrwxrwx 1 root    root    20 2017-08-10 16:22 misc -> /dev/block/mmcblk0p2
  lrwxrwxrwx 1 root    root    20 2017-08-10 16:22 ramdisk -> /dev/block/mmcblk0p6
  lrwxrwxrwx 1 ueventd ueventd 20 2017-08-10 16:22 resource -> /dev/block/mmcblk0p4
  lrwxrwxrwx 1 ueventd ueventd 20 2017-08-10 16:22 sys-prod -> /dev/block/mmcblk0p9
  lrwxrwxrwx 1 root    root    20 2017-08-10 16:22 system -> /dev/block/mmcblk0p7
  lrwxrwxrwx 1 root    root    20 2017-08-10 16:22 uboot -> /dev/block/mmcblk0p1
  lrwxrwxrwx 1 ueventd ueventd 21 2017-08-10 16:22 updater -> /dev/block/mmcblk0p11
  lrwxrwxrwx 1 ueventd ueventd 21 2017-08-10 16:22 userdata -> /dev/block/mmcblk0p12
  lrwxrwxrwx 1 root    root    20 2017-08-10 16:22 vendor -> /dev/block/mmcblk0p8
  ```

  Configuration example:

  ```
  /dev/block/by-name/misc 0660 update update
  /dev/block/by-name/bootctrl 0660 update update
  ```

### Setting the SELinux Tag of a Device Node

  The SELinux tags of device nodes are set in the **/base/security/selinux_adapter/sepolicy/base/system/file_contexts** file. If the SELinux tag of a device node is not set, the node inherits the SELinux tag of its parent directory.

  - Defining node tags
  ```
  /dev/block(/.*)?                u:object_r:dev_block_file:s0
  /dev/block/zram0                u:object_r:zram_device:s0
  ```

  - Viewing the SELinux tag of the device node by using the **ls -Zl** command

  ```
  # ls -Zl
  total 0
  lrwxrwxrwx 1 root    root    u:object_r:dev_block_file:s0  20 2017-08-10 16:22 boot_linux -> /dev/block/mmcblk0p5
  lrwxrwxrwx 1 root    root    u:object_r:dev_block_file:s0  20 2017-08-10 16:22 bootctrl -> /dev/block/mmcblk0p3
  lrwxrwxrwx 1 ueventd ueventd u:object_r:dev_block_file:s0  21 2017-08-10 16:22 chip-prod -> /dev/block/mmcblk0p10
  lrwxrwxrwx 1 root    root    u:object_r:dev_block_file:s0  20 2017-08-10 16:22 misc -> /dev/block/mmcblk0p2
  lrwxrwxrwx 1 root    root    u:object_r:dev_block_file:s0  20 2017-08-10 16:22 ramdisk -> /dev/block/mmcblk0p6
  lrwxrwxrwx 1 ueventd ueventd u:object_r:dev_block_file:s0  20 2017-08-10 16:22 resource -> /dev/block/mmcblk0p4
  lrwxrwxrwx 1 ueventd ueventd u:object_r:dev_block_file:s0  20 2017-08-10 16:22 sys-prod -> /dev/block/mmcblk0p9
  lrwxrwxrwx 1 root    root    u:object_r:dev_block_file:s0  20 2017-08-10 16:22 system -> /dev/block/mmcblk0p7
  lrwxrwxrwx 1 root    root    u:object_r:dev_block_file:s0  20 2017-08-10 16:22 uboot -> /dev/block/mmcblk0p1
  lrwxrwxrwx 1 ueventd ueventd u:object_r:dev_block_file:s0  21 2017-08-10 16:22 updater -> /dev/block/mmcblk0p11
  lrwxrwxrwx 1 ueventd ueventd u:object_r:dev_block_file:s0  21 2017-08-10 16:22 userdata -> /dev/block/mmcblk0p12
  lrwxrwxrwx 1 root    root    u:object_r:dev_block_file:s0  20 2017-08-10 16:22 vendor -> /dev/block/mmcblk0p8
  ```
