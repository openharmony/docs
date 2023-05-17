# Driver Loading

## Overview

The HDF loads the drivers that match the configured device list.

## Driver Loading Policies

The HDF supports on-demand loading and sequential loading of drivers. The **preload** field in the configuration file (see [Driver Development](../driver/driver-hdf-development.md)) specifies the loading policy of a driver. The values are as follows:

```c
typedef enum {
    DEVICE_PRELOAD_ENABLE = 0,
    DEVICE_PRELOAD_ENABLE_STEP2 = 1,
    DEVICE_PRELOAD_DISABLE = 2,
    DEVICE_PRELOAD_INVALID
} DevicePreload;
```

### On-Demand Loading

- The value **0** (**DEVICE_PRELOAD_ENABLE**) means to load the driver by default during the system boot process.

- The value **1** (**DEVICE_PRELOAD_ENABLE_STEP2**) means to load the driver after a quick start is complete. If the system does not support quick start, the value **1** has the same meaning as **DEVICE_PRELOAD_ENABLE**.

- The value **2** (**DEVICE_PRELOAD_DISABLE**) means to load the driver dynamically. When a user-mode process requests the driver service, the HDF attempts to dynamically load the driver if the driver service is not available. For more details, see [Driver Messaging Mechanism](../driver/driver-hdf-message-management.md).

### Sequential Loading (Default)

The **priority** field (ranging from 0 to 200) in the configuration file determines the loading sequence of a host and a driver. For the drivers in different hosts, the driver with a smaller priority value is loaded first. For the drivers in the same host, the driver with a smaller priority value is loaded first.

### Exception Recovery (User-Mode Driver)
The policies for restoring from a driver service exception are as follows:
- If **preload** is set to **0** (**DEVICE_PRELOAD_ENABLE**) or **1** (**DEVICE_PRELOAD_ENABLE_STEP2**) for the driver service, the startup module starts the host and reloads the service.
- If **preload** is set to **2** (**DEVICE_PRELOAD_DISABLE**), the service module needs to register an HDF service status listener. When receiving a notification on service exit, the service module calls **LoadDevice()** to reload the service.
