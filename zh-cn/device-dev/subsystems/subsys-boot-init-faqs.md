# init常见问题指导

## 服务进程相关问题

### 系统服务进程退出后不自动重启

    查看服务进程的cfg文件，是否将"once"项配置为1；该项若为1，则表示为一次性进程，进程退出后不会再被init拉起

### 如何默认disable系统服务进程

    当前服务的cfg文件中配置"disable" 项未启用，可以通过配置"start-mode" 项来控制启动方式

### 如何关闭系统服务进程沙盒

    在服务的cfg文件中配置 "sandbox" : 0 即服务不进入沙盒、1为进入沙盒，默认服务是进入沙盒

### 服务不存在

  **现象描述：**

  kernel日志打印 "Failed get servName"。

  **原因分析：**

  在init中查找对应的代码位置，发现是服务不存在。

  **解决方法：**

  1. 确认服务是否在cfg中正确配置。
  2. 服务的cfg文件是否正常加载。
  3. cfg文件格式是否正确。
## init开机启动相关问题

### 卡在开机Logo界面

 1. 原因分析：init 二级启动没有完成。

    解决方法：执行begetctl setloglevel 0并重启设备，通过串口查看内核日志。确认init的二级启动是否正常完成，关键log如下：
    
  ```
  [32.173144][pid=1] [Init] [INFO] [init.c:206]Start init second stage.
  [33.173144][pid=1] [Init] [DEBUG] [init.c:206]Parse init configs from /etc/init.cfg.
  ```

​   如果此时hdcd服务没有启动，或者分区没有挂载好，无法执行begetctl 命令。需要修改init 代码，设置log等级。确保init 的debug        log能正常输出。

 2. 原因分析：init.cfg 解析失败。

    1. cfg json格式错误。
    2. 无法正确解析：无权限或权限受限。

    解决方法：

      1. 排查cfg文件json格式， init cfg文件遵循json格式，按要求修改cfg文件。
      2. 日志中有 permission denied，init 进程报权限问题。判断是否是selinux 导致的，关闭selinux 重新验证，如果正常，无权限报错。则是selinux 策略配置不正确导致的。 请配置正确的selinux 策略。selinux 策略配置，请参考base/security/selinux_adapter 仓中的说明。

  3. 原因分析：required mount 分区没有正常挂载。

     1. cmdline中没有配置或格式错误。
     2. ramdisk中没有fstag.requried 文件。

     解决方法：

       1. 查看日志， 查看Kernel command line 中是否required mount 分区配置；如果配置，查看cmdline格式是否出错，按照格式修改或添加命令。
          
          ```
          [0.000000] Kernel command line: currentslot=0 bootslots=0 rw rootwait earlycon=uart8250,mmio32,0xfe660000 console=ttyFIQ0 ohos.boot.eng_mode=on root=PARTUUID=614e0000-0000 hardware=rk3568 default_boot_device=fe310000.sdhci ohos.required_mount.system=/dev/block/platform/fe310000.sdhci/by-name/system@/usr@ext4@ro,barrier=1@wait,required ohos.required_mount.vendor=/dev/block/platform/fe310000.sdhci/by-name/vendor@/vendor@ext4@ro,barrier=1@wait,required ohos.required_mount.misc=/dev/block/platform/fe310000.sdhci/by-name/misc@none@none@none@wait,required ohos.required_mount.bootctrl=/dev/block/platform/fe310000.sdhci/by-name/bootctrl@none@none@none@wait,required
          ```

           或 在设备中通过cat /proc/cmdline 查看。

       2. 查看 ramdisk.img 中是否存在fstab.required文件。

  4. 原因分析：com.ohos.launcher 没有启动， 导致无开机动画。

     1. ps -ef 查看com.ohos.launcher是否存在。

     解决方案：根据日志具体分析。

  5. 原因分析： bootanimation 启动失败。

     1. 查看bootanimation服务是否被拉起。
     2. 判断bootanimation是否被重复拉起。

     解决方法：

     1. 在日志中查看log： 

        ```
        [10.175192] [pid=1] [Init] [INFO] [init_service_manager.c:1088]Start service bootanimation
        ```

         表示服务启动。

  6. 原因分析：data分区没有正常挂载

     1. 设备分区表没有配置userdata分区。
     2. device的fstab 中没有给出data分区的挂载配置。
     3. device 给的fstab中配置的文件系统与userdata 镜像实际的文件系统不匹配。如fstab 中配置的是ext4, 而userdata 镜像实际的文件系统是f2fs。

     解决方法：

     对应的关键内核日志:

     1. "wait for file:/dev/block/platform/soc/10100000.himci.eMMC/by-name/userdata failed after"。
     2. 日志中看不到userdata 任何挂载相关的输出。
     3. "Mount /dev/block/platform/soc/10100000.himci.eMMC/by-name/userdata to /data failed",  如果fstab 配置了nofail, log 有"Mount no fail     device /dev/block/platform/soc/10100000.himci.eMMC/by-name/userdata to /data failed"
      nofail，表示该设备的挂载，不可以失败。

### 卡在开机动画界面

  **原因分析：**

  1. 开机动画没有正常退出。
  2. 系统应用孵化失败。
  3. 服务上报bootevent不完整，所有注册了bootevent 的服务，没有全部上报。

  **解决方法：**

  1. 查看服务是否在反复重启， 重启服务是否配置critical。
  2. ps -ef | grep ohos, 确定系统应用是否存在；日志中有 permission denied，init进程报权限问题。 确认系统应用权限，关闭selinux， 重新验证，如果正常， 则是selinux 策略配置不正确导致，重新配置或添加对应的selinux权限。 [selinux 策略配置](https://gitee.com/openharmony/security_selinux_adapter#%E6%97%A5%E5%BF%97%E4%BF%A1%E6%81%AF) 请参考base/security/selinux_adapter 仓中的说明。
  3. 通过bootevent事件分析， 通过排查没有上报的bootevent的服务， 可能会导致开机动画卡死，比如systemUI。

### 自动重启

  **原因分析：**

  1. init服务中定义“importance”的属性。
  2. critcial 使能， 关键进程符合critical 会重启。
  3. init进程挂掉会导致panic。

  **解决方法：**

  1. 小型系统中服务配置importance属性为0，importance: 0重启， 1 不重启。
  2. 关键进程服务配置critcial 会导致进程重启。
  3. CloseStdio();之前执行execv("/bin/sh", NULL)。

### reboot命令无法重启

  **原因分析：**

 1. reboot 插件安装失败。
 2. reboot 命令错误。
 3. ohos.startup.powerctrl reboot 系统参数设置失败。
 4. reboot selinux 权限受限。

  **解决方法：**

 1. 插件安装成功，在板子中查看/system/lib/init/reboot/librebootmodule.z.so是否安装成功。
 2. 执行begetctl setloglevel 0设置日志级别，日志打印：

  ```
  08-10 18:48:07.653  1421  1421 D C02c0b/BEGET: [init_reboot_innerkits.c:51]Reboot cmd reboot
  ```

​    查看 reboot 命令， reboot命令不超过96。

 3. hdc shell 执行param set ohos.startup.powerctrl reboot， 观察是否重启， 重启表示系统参数设置成功。
 4. 日志中有 permission denied，init 进程报权限问题。关闭selinux, 重新验证， 如果验证成功，则是selnux策略配置不正确导致， 重新配置或添加对应的selinux权限。 [selinux 策略配置](https://gitee.com/openharmony/security_selinux_adapter#%E6%97%A5%E5%BF%97%E4%BF%A1%E6%81%AF) 请参考base/security/selinux_adapter 仓中的说明。

### 系统启动过程中打印“Cfg error!”错误后停止启动

  **现象描述：**

  系统启动过程中，解析init.cfg文件错误，启动过程停止，打印日志如下：

  ```
  Cfg error, failed to parse json etc/init.cfg
  ```

  **可能原因：**

  修改init.cfg文件时，漏掉或多加了逗号或括号等，导致init.cfg文件的json格式被破坏。

  **解决办法**

  仔细检查init.cfg文件，确保其格式符合json格式要求。

### 请求其他服务代持fd，init有报错

  **现象描述：**

  kernel日志打印 "Service ' xxx '(pid = xxx) is not valid or request with unexpected process(pid = xxx)"。

  **原因分析：**

  kernel日志打印，都是由init 打印。在init中查找对应的代码位置。发现是其他服务代持fd。

  **解决方法：**

  只支持代持本服务的fd，不允许让其他服务代持fd。