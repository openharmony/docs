# OpenHarmony SELinux新增进程策略配置方法

## 新增Native进程

**适用场景**

由init、chipset_init通过cfg文件孵化的Native进程，例如ueventd、installs。

**配置指导**

1. 在本进程的cfg文件中，新增secon字段，建立进程与标签的映射关系。如果未配置secon字段，进程在SELinux使能状态会被拦截启动。
    ```json
    {
        "services" : [{
                "name" : "demo",
                "path" : ["/system/bin/demo"],
                "uid" : "demo",
                "gid" : ["demo"],
                "secon" : "u:r:demo:s0"
            }
        ]
    }
    ```
2. 在type.te中定义SELinux标签u:r:demo:s0中的SELinux类型demo，使u:r:demo:s0是合法的。

    如果demo是由init孵化，则定义：
    ```text
    type demo, native_system_domain, domain;
    ```
    如果demo是由chipset_init孵化，则定义：
    ```text
    type demo, native_chipset_domain, domain;
    ```

## 新增SA服务进程

**适用场景**

由init通过cfg文件孵化的SA服务进程，例如accountmgr、foundation。

**配置指导**

1. 在本进程的cfg文件中，新增secon字段，建立进程与标签的映射关系。如果未配置secon字段，进程在SELinux使能状态会被拦截启动。
    ```json
    {
        "services" : [{
                "name" : "demo",
                "path" : ["/system/bin/sa_main", "/system/profile/demo.json"],
                "uid" : "demo",
                "gid" : ["demo"],
                "secon" : "u:r:demo:s0"
            }
        ]
    }
    ```
2. 在type.te中定义SELinux标签u:r:demo:s0中的SELinux类型demo，使u:r:demo:s0是合法的。
    ```text
    type demo, sadomain, domain;
    ```

## 新增HDF服务进程

**适用场景**

由init、chipset_init通过cfg文件孵化的HDF服务进程，例如wifi_host、camera_host。

**配置指导**

1. 在本进程的cfg文件中，新增secon字段，建立进程与标签的映射关系。如果未配置secon字段，进程在SELinux使能状态会被拦截启动。
    ```json
    {
        "services" : [{
                "name" : "demo",
                "path" : ["/vendor/bin/hdf_devhost", "0", "demo"],
                "uid" : "demo",
                "gid" : ["demo"],
                "secon" : "u:r:demo:s0"
            }
        ]
    }
    ```

2. 在type.te中定义SELinux标签u:r:demo:s0中的SELinux类型demo，使u:r:demo:s0是合法的。
    ```text
    type demo, hdfdomain, domain;
    ```

## 新增应用进程

**适用场景**

由appspawn孵化的系统应用进程，期望以独立标签运行，例如`com.ohos.permissionmanager`。

**配置指导**

1. 在sehap_contexts文件中，建立应用APL等级、包名与应用进程标签、数据目录标签的映射关系。这里表示，当安装的应用APL为normal且包名为`com.ohos.permissionmanager`时，安装的应用数据目录标签会被配置为`u:object_r:permissionmanager_hap_data_file:s0`，应用运行时的进程标签会被配置为`u:r:permissionmanager_hap:s0`。
    ```text
    apl=normal name=com.ohos.permissionmanager domain=permissionmanager_hap type=permissionmanager_hap_data_file
    ```
    APL说明参考[权限等级说明](../../application-dev/security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)中的`权限APL等级`。
2. 在type.te中定义`permissionmanager_hap`和`permissionmanager_hap_data_file`，使`u:r:permissionmanager_hap:s0`和`u:object_r:permissionmanager_hap_data_file:s0`是合法的。
    ```text
    type permissionmanager_hap, normal_hap_attr, hap_domain, domain;
    type permissionmanager_hap_data_file, normal_hap_data_file_attr, hap_file_attr, data_file_attr, file_attr;
    ```
    这里使用APL等级为normal的应用作为示例，其他APL等级的应用参考下表配置：

    **表1** APL等级与应用attribute归属对应关系
    | APL等级 | 应用进程attribute归属 | 应用数据目录attribute归属 |
    | -------- | -------- | -------- |
    | normal | normal_hap_attr | normal_hap_data_file_attr |
    | system_basic | system_basic_hap_attr | system_basic_hap_data_file_attr |
    | system_core | system_core_hap_attr | system_core_hap_data_file_attr |
