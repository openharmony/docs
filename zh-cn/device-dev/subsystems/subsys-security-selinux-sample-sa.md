# OpenHarmony SELinux新增SA或HDF策略配置方法

## 新增SA

**适用场景**

某个进程向samgr注册SA服务，其他进程在与该进程进行IPC通信之前，需要获取该SA服务，SA提供方需要为该SA配置SELinux标签，否则该SA会被SELinux配置为`u:object_r:default_service:s0`标签，配置访问`default_service`的策略会被neverallow禁止。

**配置指导**

1. 在service_contexts文件内，新增SAID与SA标签的映射关系。
    ```text
    10      u:object_r:sa_render_service:s0
    ```

2. 在type.te中定义对应的`sa_render_service`，使对应的标签合法。
    ```text
    type sa_render_service, sa_service_attr
    ```

## 新增HDF

**适用场景**

  某个进程向hdf_devmgr注册HDF服务，其他进程在与该进程进行IPC通信之前，需要获取该HDF服务，HDF提供方需要为该HDF配置SELinux标签，否则该HDF会被SELinux配置为`u:object_r:hdf_default_service:s0`标签，配置访问`hdf_default_service`的策略会被neverallow禁止。


**配置指导**

1. 在service_contexts文件内，新增HDF服务名与HDF标签的映射关系。
    ```text
    thermal_interface_service  u:object_r:hdf_thermal_interface_service:s0
    ```

2. 在type.te中定义对应的`hdf_thermal_interface_service`，使对应的标签合法。
    ```text
    type hdf_thermal_interface_service, hdf_service_attr
    ```
