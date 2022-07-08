# 启动恢复子系统概述


## 启动恢复子系统上下文

下图是启动子系统上下文结构图：

  **图1** 启动子系统上下文结构图

  ![zh-cn_image_0000001217858866](figures/zh-cn_image_0000001217858866.png)

系统上电加载内核后，按照以下流程完成系统各个服务和应用的启动：

1. 内核加载init进程，一般在bootloader启动内核时通过设置内核的cmdline来指定init的位置。
2. init进程启动后，会挂载tmpfs，procfs，创建基本的dev设备节点，提供最基本的根文件系统。
3. init也会启动ueventd监听内核热插拔设备事件，为这些设备创建dev设备节点。包括block设备各个分区设备都是通过此事件创建。
4. init进程挂载block设备各个分区（system，vendor）后，开始扫描各个系统服务的init启动脚本，并拉起各个SA服务。
5. samgr是各个SA的服务注册中心，每个SA启动时，都需要向samgr注册，每个SA会分配一个ID，应用可以通过该ID访问SA。
6. foundation是一个特殊的SA服务进程，提供了用户程序管理框架及基础服务。由该进程负责应用的生命周期管理。
7. 由于应用都需要加载JS的运行环境，涉及大量准备工作，因此appspawn作为应用的孵化器，在接收到foundation里的应用启动请求时，可以直接孵化出应用进程，减少应用启动时间。


启动子系统内部涉及以下组件：

- init启动引导组件：
  init启动引导组件对应的进程为init进程，是内核完成初始化后启动的第一个用户态进程。init进程启动之后，读取init.cfg配置文件，根据解析结果，执行相应命令（见[第2章表2](../subsystems/subsys-boot-init.md)描述）并依次启动各关键系统服务进程，在启动系统服务进程的同时设置其对应权限。

- ueventd启动引导组件：
  ueventd负责监听内核设备驱动插拔的netlink事件，根据事件类型动态管理相应设备的dev节点。

- appspawn应用孵化组件：
  负责接收**用户程序框架**的命令孵化应用进程，设置新进程的权限，并调用应用程序框架的入口函数。

- bootstrap服务启动组件：
  提供了各服务和功能的启动入口标识。在SAMGR启动时，会调用bootstrap标识的入口函数，并启动系统服务。

- syspara系统属性组件：
  系统属性组件，根据OpenHarmony产品兼容性规范提供获取设备信息的接口，如：产品名、品牌名、厂家名等，同时提供设置/读取系统属性的接口。


## 约束与限制

  启动恢复子系统源代码目录和适配平台：

  **表1** 启动恢复子系统源代码目录和适配平台

| 名称 | 适配平台 |
| -------- | -------- |
| base/startup/appspawn_lite | 小型系统设备（参考内存≥1MB），如Hi3516DV300&nbsp;、Hi3518EV300 |
| base/startup/bootstrap_lite | 轻量系统设备（参考内存≥128KB），如Hi3861V100 |
| base/startup/init_lite | 小型系统设备（参考内存≥1MB），如Hi3516DV300、Hi3518EV300 |
| base/startup/syspara_lite | -&nbsp;轻量系统设备（参考内存≥128KB），如Hi3861V100<br/>-&nbsp;小型系统设备（参考内存≥1MB），如Hi3516DV300、Hi3518EV300 |

- init启动引导组件：
  - 每个系统服务启动时都需要编写各自的启动脚本文件init.cfg，定义各自的服务名、可执行文件路径、权限和其他信息。
  - 每个系统服务各自安装其启动脚本到/system/etc/init目录下，init进程统一扫码执行。

- 新芯片平台移植时，平台相关的初始化配置需要增加平台相关的初始化配置文件/vendor/etc/init/init.{hardware}.cfg；该文件完成平台相关的初始化设置，如安装ko驱动，设置平台相关的/proc节点信息。

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**

  > 配置文件init.cfg仅支持json格式。

- bootstrap服务启动组件：需要在链接脚本中配置zInit代码段。

## 启动引导OpenHarmony标准系统的详细流程

当前OpenHarmony标准系统默认支持以下几个镜像：

| 镜像名称     | 挂载点  | 说明                                                 |
| ------------ | ------- | ---------------------------------------------------- |
| boot.img     | NA      | 内核和ramdisk镜像，bootloader加载的第一个镜像      |
| system.img   | /system | 系统组件镜像，存放与芯片方案无关的平台业务         |
| vendor.img   | /vendor | 芯片组件镜像，存放芯片相关的硬件抽象服务           |
| updater.img  | /       | 升级组件镜像，用于完成升级；正常启动时不加载次镜像 |
| userdata.img | /data   | 可写的用户数据镜像                                 |

每个开发板都需要在存储器上划分好分区来存放上述镜像，SOC启动时都由bootloader来加载这些镜像，具体过程包括以下几个大的步骤：

- bootloader初始化ROM和RAM等硬件，加载分区表信息。
- bootloader根据分区表加载boot.img，从中解析并加载ramdisk.img到内存中。
- bootloader准备好分区表信息，ramdisk地址等信息，进入内核，内核加载ramdisk并执行init。
- init准备初始文件系统，挂载required.fstab（包括system.img和vendor.img的挂载）。
- 扫描system.img和vendor.img中etc/init目录下的启动配置脚本，执行各个启动命令。

### uboot启动引导过程

本文以常见的[uboot](https://elinux.org/U-Boot)为例介绍bootloader加载OpenHarmony各个系统镜像的关键过程。u-boot启动OpenHarmony系统时，主要通过bootargs向系统传递启动信息。

- u-boot加载解析boot.img

  - boot.img格式

    boot.img镜像的构建和加载是与平台相关的，下面以OpenHarmony目前的一些主流平台为例进行介绍：

    - Hi3516DV300

      在Hi3516DV300平台上的boot.img采用了FIT（flattened image tree）格式，将kernel编译生成的zImage-dtb和cpio格式的ramdisk镜像通过打包工具Mkimage根据its文件中的信息打包生成一个镜像，这个镜像就是boot.img。

      下面对上述boot.img文件生成过程中使用的文件和工具进行简要介绍：

      1. its文件

         image source file，负责描述要生成的image的信息。需要自行构造，例如Hi3516平台中的ohos.its文件。

      2. Mkimage打包工具

         能够解析its文件，将其中按照其中镜像的配置将对应镜像打包生成itb文件，这里也就是boot.img文件。

      3. ramdisk

         使用cpio打包的ramdisk.img镜像文件。

      4. zImage-dtb

         包含压缩的内核镜像和设备描述文件镜像。

    - rk3568

      在rk3568平台上相应的镜像文件为boot_linux.img，其中打包的文件与Hi3516DV300平台不尽相同，下面分别列举：

      1. Image

         kernel编译生成的镜像文件。

      2. toybrick.dtb

         类似于由dts编译而来的设备描述文件镜像。

      3. ramdisk.img

         使用cpio打包的ramdisk.img镜像文件。

  - u-boot加载

    支持了ramdisk的启动过程，此场景需要修改productdefine中的产品配置文件，通过"enable_ramdisk"开关开启ramdisk生成，这一部分与平台相关，不同的平台对于ramdisk 的处理方式不一样。以Hi3516DV300平台为例，需要将u-boot中的原启动参数修改为root=/dev/ram0 initrd=0x84000000,0x292e00。


- u-boot进入

  u-boot启动进入内核时，可以通过bootargs传递关键信息给内核，这一部分内容是与平台相关的，主要信息如下：

  | 名称        | 示例                                                         | 说明                                                         |
  | ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | initrd      | 0x84000000,0x292e00                                          | 参考内核文档。<br/>[ramfs-rootfs-initramfs.rst](https://gitee.com/openharmony/kernel_linux_5.10/blob/master/Documentation/filesystems/ramfs-rootfs-initramfs.rst)<br/>[initrd.rst](https://gitee.com/openharmony/kernel_linux_5.10/blob/master/Documentation/admin-guide/initrd.rst) |
  | init        | /init                                                        |                                                              |
  | blkdevparts | mmcblk0:1M(boot),15M(kernel),200M(system),200M(vendor),<br/>2M(misc),20M(updater),-(userdata) | 分区表信息，kernel会根据此信息创建物理分区。                 |
  | hardware    | Hi3516DV300、rk3568等                                                  | （必要信息）硬件平台。 |
  | root        | /dev/ram0（Hi3516DV00)、root=PARTUUID=614e0000-0000 rw（rk3568）                                                    | kernel加载的启动设备。 |
  | rootfstype  | ext4                                                         | 根文件系统类型。 |
  | default_boot_device | soc/10100000.himci.eMMC | （建议配置信息）默认启动设备，在启动第一阶段会根据这个参数创建required设备的软链接。 |
  | ohos.required_mount.xxx | /dev/block/platform/soc/10100000.himci.eMMC/by-name/xxx@/usr@ext4@ro,barrier=1@wait,required |  现支持从cmdline中读取fstab信息，获取失败的情况下，会继续尝试从fstab.required文件中读取 |

- init挂载required分区

  所谓required分区，就是系统启动引导过程的必要分区，必须在二级启动开始前进行挂载。比如system、vendor等必选镜像，挂载这些镜像前，需要先创建对应的块设备文件。这些块设备文件是通过内核上报UEVENT事件来创建的。init需要知道存储器的主设备目录，需要bootloader通过default_boot_device传递。

  目前init支持两种方式获取required分区信息，一是通过保存在/proc/cmdline中的bootargs，init会首先尝试从cmdline读取required分区信息；二是通过读取ramdisk中的fstab.required文件，只有在前一种方式获取失败的情况下才会尝试通过这种方式获取。

    - 块设备的创建逻辑

      - 准备工作

        1. init从cmdline中读取required fstab，若获取失败，则尝试读fstab.required文件，从中获取必须挂载的块设备的PARTNAME，例如system和vendor.
        2. 创建接收内核上报uevent事件广播消息的socket，从/proc/cmdline里读取default_boot_device。
        3. 带着fstab信息和socket句柄遍历/sys/devices目录，准备开始触发内核上报uevent事件。

      - 触发事件

        1. 通过ueventd触发内核上报uevent事件
        2. 匹配uevent事件中的partitionName与required fstab中的device信息。
        3. 匹配成功后将会进一步处理，格式化设备节点路径，准备开始创建设备节点。

      - 创建节点

        1. 为了便于用户态下对设备节点的访问以及提高设备节点的可读性，会对即将创建的required块设备节点同时创建软链接，这就需要先格式化软链接的路径。
        2. 以上工作都完成后，将执行最后的创建设备节点的步骤，根据传入的uevent中的主次设备号、前置步骤中构建的设备节点路径和软链接路径等创建设备节点，并创建相应软链接。

      至此，块设备节点创建完毕。

    - 与default_boot_device匹配关系

      内核将bootargs信息写入/proc/cmdline，其中就包含了default_boot_device，这个值是内核当中约定好的系统启动必要的主设备目录。以ohos.required_mount.为前缀的内容则是系统启动必要的分区挂载信息，其内容与fstab.required文件内容应当是一致的。另外，分区挂载信息中的块设备节点就是default_boot_device目录中by-name下软链接指向的设备节点。例如，default_boot_device的值为soc/10100000.himci.eMMC，那么ohos.required_mount.system的值就包含了/dev/block/platform/soc/10100000.himci.eMMC/by-name/system这个指向system设备节点的软链接路径。

      在创建块设备节点的过程中，会有一个将设备路径与default_boot_device的值匹配的操作，匹配成功后，会在/dev/block/by-name目录下创建指向真实块设备节点的软链接，以此在访问设备节点的过程中实现芯片平台无关化。

    - 实例

      下面以OpenHarmony系统在Hi3516DV300平台启动过程中必要的system分区为例，详细介绍init进程启动后，从读取required fstab信息到创建required分区块设备节点再到最后完成required分区挂载的全部流程。其中会包含一些关键代码段和关键的log信息供开发者调试参考。

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**

      > 从此处开始出现的代码是按逻辑顺序展示的关键代码行，不代表其在源码当中真正的相邻关系。

      1. 获取required设备信息
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
          以上代码分别展示了获取fstab信息的两种方式，首先调用LoadFstabFromCommandLine()，从cmdline中获取fstab信息，如果获取失败，则输出log，表示继续尝试从fstab.required文件中获取fstab信息。

          对于system分区来说，其读到devices中的关键信息如下所示：
          ```
          /dev/block/platform/fe310000.sdhci/by-name/system
          ```

      2. 创建socket，触发内核上报uevent事件
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

      3. 读取cmdline，获得default_boot_device
         ```
         char *buffer = ReadFileData("/proc/cmdline");
         int ret = GetProcCmdlineValue("default_boot_device", buffer, bootDevice, CMDLINE_VALUE_LEN_MAX);
         INIT_CHECK_ONLY_ELOG(ret == 0, "Failed get default_boot_device value from cmdline");
         ```
         这里取得的default_boot_device的值应该是soc/10100000.himci.eMMC，也就对应了system分区设备所在目录，这一值存放在了bootDevice这个全局变量当中，将在后续创建system分区设备软链接前进行匹配。

      4. 处理required设备uevent事件
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
         存在devices中的设备信息，就是在此处与内核上报的uevent事件进行匹配的。对于system分区设备的uevent消息，其uevent->partitionName值应该为system，与devices中存在的/dev/block/platform/fe310000.sdhci/by-name/system字段匹配成功，则开始处理system分区设备的uevent消息。

      5. 创建required设备节点和对应软链接

         首先应该格式化对应软链接的路径，这一部分就用到了bootargs中default_boot_device的值，与上报的required设备节点路径进行匹配，以创建平台无关的可读性更高的指向该设备节点的软链接，关键部分代码如下：
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
         首先解释一下这段代码中出现的关键变量。

             bus: 这是一个保存了路径信息的字符串，路径是当前处理的设备所连接的总线路径。
             parent: 同样是一个保存了路径信息的字符串，路径是从uevent->syspath取出的当前处理的设备路径。
             links：事先申请好的指向保存软链接路径内存的指针
             bootDevice: 存放bootargs中default_boot_device值的字符串
         根据代码可知，只有处理到所连接总线类型为platform时的设备才会创建对应软链接，这一软链接所在的目录是：
         ```
         /dev/block/platform/soc/10100000.himci.eMMC/by-name
         ```
         而只有匹配到设备目录为bootDevice中路径的设备时，才会创建平台无关目录的软链接。

         对于system分区设备来说，其所在目录如下：
         ```
         /sys/devices/platform/soc/10100000.himci.eMMC/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p5
         ```
         因此在处理内核上报的该设备uevent消息时，会与bootDevice中的路径soc/10100000.himci.eMMC相匹配，因此而创建相应的软链接，这一软连接的路径是：
         ```
         /dev/block/by-name/system
         ```

         软链接路径格式化完成后，将根据uevent中的信息进行最后的创建设备节点和软链接的动作，至此，system分区设备的设备节点创建完毕。

      6. 挂载required分区

         设备节点创建完成后，即可挂载对应分区，主要接口如下：
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
         因此，当我们看到"Mount required partitions"打印的时候，表示required分区设备已经准备完成，即将执行挂载动作。分区挂载过程中，还有一些关键打印如下：
         ```
         BEGET_LOGE("Unsupported file system \" %s \"", item->fsType);
         表示当前文件系统类型不支持

         BEGET_LOGE("Cannot get stat of \" %s \", err = %d", target, errno);
         表示无法获取挂载点目录信息

         BEGET_LOGE("Failed to create dir \" %s \", err = %d", target, errno);
         表示无法创建挂载点目录

         BEGET_LOGI("Mount %s to %s successful", item->deviceName, item->mountPoint);
         表示成功挂载设备，打印中还包含了挂载的设备名和挂载点信息
         ```


- init执行system和vendor中的启动脚本，挂载vendor中更多的分区

​	挂载完必要的分区后，init扫描各个脚本文件。vendor中与芯片或开发板相关的初始化脚本入口如/vendor/etc/init.{ohos.boot.hardware}.cfg。vendor中扩展的挂载分区文件是/vendor/etc/fstab.{ohos.boot.hardware}。hardware的来源是bootloader传递给内核的bootargs。


### 无ramdisk的启动加载流程

有些开发板没有采用ramdisk启动引导，直接通过内核挂载system.img。此场景需要修改productdefine中的产品配置文件，通过"enable_ramdisk"开关关闭ramdisk生成，init也不会从ramdisk里二次启动到system。

此场景的主要启动过程与上述流程类似，只是有ramdisk时，init会把system.img挂载到/usr目录，然后chroot到/usr下，并且执行/etc/init.cfg入口脚本文件；而没有ramdisk时，没有chroot过程，切init执行的入口启动脚本是init.without_two_stages.cfg文件。

对于无ramdisk的启动加载，即system as root. 在bootloader阶段将根文件系统所在的块设备通过bootargs传给内核，如root=/dev/mmcblk0p5，rootfstype=ext4。内核在初始化根文件系统时，解析bootargs中root，完成根文件系统的挂载。
