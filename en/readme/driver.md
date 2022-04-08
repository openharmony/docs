# Driver<a name="EN-US_TOPIC_0000001052619216"></a>

## Overview<a name="section11660541593"></a>

The OpenHarmony driver subsystem is constructed using the C object-oriented programming \(OOP\). It provides a unified driver platform through platform decoupling, kernel decoupling, and compatible kernels. This unified driver architecture platform is designed to provide a more precise and efficient development environment, where you develop a driver that can be deployed on different systems supporting HDF.

The OpenHarmony driver subsystem provides the following key features and capabilities to shorten the driver development period and make third-party device driver integration much easier:

-   Flexible framework capabilities

    Based on the traditional driver framework, the OpenHarmony driver subsystem builds flexible framework capabilities to deploy terminal products with the capacity ranging from hundreds KB to hundreds MB of memory.


-   Standardized driver APIs

    The OpenHarmony driver subsystem provides you with abundant and stable driver APIs, which are compatible with those of future-proof smartphones, tablets, smart TVs.


-   Component-based driver models

    The OpenHarmony driver subsystem supports component-based driver models. It provides more refined driver management to dismantle components, enabling you to focus on the interaction between the hardware and driver.

    The subsystem also presets some template-based driver model components, such as the network device models.


-   Normalized configuration GUIs

    The OpenHarmony driver subsystem provides a unified configuration GUI and a cross-platform tool for configuration conversion and generation to implement seamless switchover across platforms.


You can use DevEco to manage driver projects, generate driver templates, and manage settings to make the development of OpenHarmony drivers easier.

## Architecture<a name="section101721227145613"></a>

The OpenHarmony driver framework adopts the primary/secondary mode and is developed based on the framework, model, competence library, and tool.

**Figure  1**  Driver subsystem architecture<a name="fig1077923710115"></a>  
![](figures/driver-subsystem-architecture.png "driver-subsystem-architecture")

-   Driver framework stored in the  **framework/core**  directory
    -   Loads and starts drivers.
    -   Deploys and expands the driver framework flexibly through the object manager.

-   Driver model stored in the  **framework/model**  directory
    -   Provides model-based driving capabilities, such as network device models.

-   Driver capability library stored in the  **framework/ability**  directory
    -   Provides basic driver models, such as the I/O communication model.

-   Driver tools stored in the  **framework/tools**  directory
    -   Provides tools for HDI API conversion, and driver configuration and driver compilation.

-   Driver APIs stored in the  **lite/hdi**  directory
    -   Provides standardized driver APIs.

-   Support stored in the  **framework/support**  directory
    -   Provides platform driver APIs and system APIs with normalized abstraction capabilities.


## Directory Structure<a name="section1464106163817"></a>

```
drivers
├── adapter               # Adaptation code for differentiated platforms
├── framework             # Core code of the HDF
└── peripheral            # Peripheral driver code 
```

## Use<a name="section8496817141616"></a>

**Figure  2**  Interaction between the driver and framework<a name="fig1356181413429"></a>  
![](figures/interaction-between-the-driver-and-framework.png "interaction-between-the-driver-and-framework")

Driver loading is mostly done by the driver framework, and you only need to register and configure required APIs. The driver framework will load and initialize the driver based on the parsing content.

Driver development based on the HDF consists of the following three parts:

1. Driver: Develop the functions.

2. Information configuration: Present the loading information of the driver.

3. Resource configuration: Configure the hardware information of the driver.

The driver mainly aims to develop the functions.

The first part that catches your eyes is the driver entry, which is described through  **DriverEntry**.

Three APIs are available, namely  **bind**,  **init**, and  **release**.

```
struct HdfDriverEntry g_deviceSample = {
    .moduleVersion = 1,
    .moduleName = "sample_driver", 
    .Bind = SampleDriverBind,
    .Init = SampleDriverInit,
    .Release = SampleDriverRelease,
};
```

**Bind**: This API is used to bind driver devices and its functions.

```
int32_t SampleDriverBind(struct HdfDeviceObject *deviceObject)
{
    // TODO: Bind device service to device object.
    // And you can also initialize device resources here.
    return HDF_SUCCESS;
}
```

**Init**: When devices are successfully bound, the framework calls  **Init**  to initialize the driver. After initialization is complete, the driver framework will determine whether to create external service interfaces based on the configuration file. If the driver fails to be initialized, the driver framework will automatically release the created device interface.

```
int32_t SampleDriverInit(struct HdfDeviceObject *deviceObject)
{
    // TODO: Init hardware or other resources here.
    return HDF_SUCCESS;
}
```

**Release**: When you need to uninstall a driver, the driver framework calls this function to release the driver resources. Then, other internal resources will be released.

```
void SampleDriverRelease(struct HdfDeviceObject *deviceObject)
{
    // Release all resources.
    return;
}
```

## Installation<a name="section14778154275818"></a>

The OpenHarmony driver is mainly deployed in the kernel space using the static link mode. It is compiled and packed with the kernel subsystem and system image.

**Figure  3**  Driver installation<a name="fig20119729154211"></a>  
![](figures/driver-installation.png "driver-installation")

## Repositories Involved<a name="section134812226297"></a>

**Driver subsystem**

[drivers\_framework](https://gitee.com/openharmony/drivers_framework/blob/master/README.md)

[drivers\_adapter](https://gitee.com/openharmony/drivers_adapter/blob/master/README.md)

[drivers\_adapter\_khdf\_linux](https://gitee.com/openharmony/drivers_adapter_khdf_linux/blob/master/README.md)

[drivers\_peripheral](https://gitee.com/openharmony/drivers_peripheral/blob/master/README.md)

