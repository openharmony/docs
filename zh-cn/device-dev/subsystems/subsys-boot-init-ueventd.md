# ueventd介绍说明

## 概述

 ueventd负责监听内核设备驱动插拔的netlink事件，根据事件类型动态管理相应设备的dev节点。

## 配置文件说明

### ueventd配置文件类型

  ueventd 的配置文件在/base/startup/init/ueventd/etc/目录下，配置文件主要分三个类型，分别是：device、 sysfs、 firmware。

  目前配置的为device类型，当需要对创建的节点权限有DAC的设置要求时在该文件中配置。

  不同的文件类型根据文件开头的字段来区分，以device 为例：
  ```
    [device] # 表示文件类型
    # <device name> <mode> <uid> <gid> <parameter>
    /dev/null 0666 0 0
  ```

### ueventd配置文件的说明

  - ueventd的配置文件名为ueventd.config.

  - ueventd配置文件的内容主要有5个字段组成，例如：

  ```
  /dev/null 0666 0 0
  /dev/binder 0666 0 0
  /dev/hwbinder 0666 0 0
  /dev/vndbinder 0666 0 0
  /dev/input/event* 0660 0 input
  ```

  **ueventd配置文件的字段说明**
  | 字段        | 说明             |
  | ----------- | ---------------- |
  | device name | 设备节点名称     |
  | mode        | 设备节点所给予的权限，遵循UGO模型|
  | uid         | 设备节点的uid |
  | gid         | 设备节点的gid |
  | parameter   | 设备节点参数信息，作用类似于通知，如果设备创建了，会设置一个对应parameter，根据参数信息便于其他进程对该节点进行对应的操作 <br>/dev/null 0666 0 0  device_null<br />如在dev/null节点下操作：<br />当设备被创建，设置startup.uevent.device_null "added"；当设备被卸载，我们会设置startup.uevet.device_null "removed"|

  - 特别说明

  由于启动分区的个节点可能会随设备的不同发生变化，因此支持通过在ueventd.config配置软连接的权限来修改其对应的物理设备节点的权限。
  这部分节点主要在/dev/block/by-name目录下：

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

  配置实例如下：

  ```
  /dev/block/by-name/misc 0660 update update
  /dev/block/by-name/bootctrl 0660 update update
  ```

### 设备节点的selinux 标签设置

  设备节点的selinux 标签在/base/security/selinux_adapter/sepolicy/base/system/file_contexts文件中设置，当某个节点的selinux标签未设置时，其会继承父目录的标签selinux。

  - 节点标签定义：
  ```
  /dev/block(/.*)?                u:object_r:dev_block_file:s0
  /dev/block/zram0                u:object_r:zram_device:s0
  ```

  - 使用ls -Zl 可以查看节点的selinux标签

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
