# OpenHarmony SELinux新增文件策略配置方法

## 只读分区新增文件

**适用场景**

为避免对文件系统恶意破坏，OpenHarmony将部分镜像挂载为只读，如system.img、vendor.img，这些镜像内的文件在编译阶段就会被赋予SELinux标签。

**配置指导**
1. 在file_contexts中，建立文件绝对路径与文件标签的映射关系，可以使用正则表达式。
    ```text
    /system/lib(/.*)?    u:object_r:system_lib_file:s0
    ```
2. 在type.te中定义system_lib_file，使u:object_r:system_lib_file:s0是合法的。
    ```text
    type system_lib_file, system_file_attr, file_attr;
    ```

## 读写分区新增文件

**适用场景**

在OpenHarmony操作系统中，存在一些读写分区，如/data目录为用户数据存储目录，通常用来存储应用程序和用户产生的数据，允许应用程序在其中创建、读取和写入文件，这些文件一般是动态生成的，默认会继承父目录的标签，在业务安全防护需要时，可以在文件创建完成后为其配置独立的文件标签。


**配置指导**
1. 在file_contexts中，建立文件绝对路径与文件标签的映射关系，可以使用正则表达式。
    ```text
    /data/service/el0(/.*)?    u:object_r:data_service_el0_file:s0
    ```
2. 在type.te中定义data_service_el0_file，使u:object_r:data_service_el0_file:s0是合法的。
    ```text
    type data_service_el0_file, file_attr, data_file_attr;
    ```
3. 使标签生效，file_contexts只是映射了文件路径和标签的对应关系，标签不会自动更新到文件上，需要进程主动触发标签更新操作。按文件创建的时机，可以分为以下场景：
      | 适用场景 | 更新标签位置 |
      | -------- | -------- |
      | 通过init从cfg拉起的进程，在cfg内使用mkdir创建目录或文件 | 由于init在解析cfg中的mkdir命令时，已经集成了SELinux更新标签函数Restorecon，所以mkdir会更新标签 |
      | 在开机阶段cfg内使用mkdir创建的目录或文件 | 由于init在解析cfg中的mkdir命令时，已经集成了SELinux更新标签函数Restorecon，所以mkdir会更新标签 |
      | 在进程运行期间，由进程本身创建的目录或文件 | 需要进程在创建目录或文件后，调用SELinux更新标签函数Restorecon更新标签 |

      其中，SELinux更新标签函数参考[OpenHarmony SELinux对外接口](subsys-security-selinux-func.md)。

## 虚拟文件系统新增文件

**适用场景**

对于虚拟文件系统，例如/proc、/sys等目录下的文件标签，可以在 virtfs_contexts文件内对文件或目录进行标签配置。


**配置指导**
1. 虚拟文件系统的标签映射方式和普通文件系统的标签映射方式不一样，在virtfs_contexts中，用genfscon语法来配置。
    ```text
    genfscon  proc /iomem  u:object_r:proc_iomem_file:s0
    ```
2. 在type.te中定义`proc_iomem_file`，使`u:object_r:proc_iomem_file:s0`是合法的。
    ```text
    type proc_iomem_file, fs_attr, proc_attr;
    ```
