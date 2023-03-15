# 驱动加载

## 驱动加载概述

HDF驱动框架提供把和配置的设备列表匹配成功的驱动程序加载起来的功能。

## 驱动加载策略

支持按需加载和按序加载两种策略，具体设备的加载策略由配置文件（参考[驱动开发](../driver/driver-hdf-development.md)）中的preload字段来控制，配置值参考如下：

```c
typedef enum {
    DEVICE_PRELOAD_ENABLE = 0,
    DEVICE_PRELOAD_ENABLE_STEP2 = 1,
    DEVICE_PRELOAD_DISABLE = 2,
    DEVICE_PRELOAD_INVALID
} DevicePreload;
```

### 按需加载

- preload字段配置为0（DEVICE_PRELOAD_ENABLE），则系统启动过程中默认加载。

- preload字段配置为1（DEVICE_PRELOAD_ENABLE_STEP2），当系统支持快速启动的时候，则在系统完成之后再加载这一类驱动，否则和DEVICE_PRELOAD_ENABLE含义相同。

- preload字段配置为2（DEVICE_PRELOAD_DISABLE），则系统启动过程中默认不加载，支持后续动态加载，当用户态获取驱动服务（参考[消息机制](../driver/driver-hdf-message-management.md)）时，如果驱动服务不存在，HDF框架会尝试动态加载该驱动。

### 按序加载（默认加载策略）

配置文件中的priority（取值范围为整数0到200）是用来表示host（驱动容器）和驱动的优先级。不同的host内的驱动，host的priority值越小，驱动加载优先级越高；同一个host内驱动的priority值越小，加载优先级越高。
