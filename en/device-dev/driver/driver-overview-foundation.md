# Driver Overview


## Introduction

OpenHarmony uses the multi-kernel (Linux kernel and LiteOS) design and can be deployed on devices with different resource capacities. How to smoothly adapt device drivers to different kernels on the same hardware and minimize the workloads on driver code porting and maintenance is an important issue to address in the OpenHarmony driver subsystem.

The OpenHarmony driver subsystem provides the following features and capabilities to shorten the driver development period and simplify third-party device driver integration:

- Elastic framework capabilities
  
Based on the traditional driver framework, the OpenHarmony driver subsystem builds elastic framework capabilities to enable deployment on terminal products with memory of hundreds KB to hundreds MB.
  
- Standardized driver interfaces
  
The OpenHarmony driver subsystem provides stable driver APIs compatible with the APIs of future-proof smartphones, tablets, smart TVs.
  
- Component-based driver model
  
The OpenHarmony driver subsystem provides the component-based driver model to implement more refined driver management. You can add or reduce components as required and focus on the interaction between the hardware and driver. The subsystem also presets some template-based driver model components, such as the network device model.
  
- Normalized configuration UI
  
  The OpenHarmony driver subsystem provides a unified configuration tool that supports cross-platform configuration conversion and generation, enabling seamless switchover across platforms.


## HDF

The Hardware Driver Foundation (HDF) provides driver framework capabilities, including driver loading, driver service management, and driver messaging mechanism. It strives to build a unified driver platform to back up a more precise and efficient environment for one-time development for multi-device deployment.

The HDF is built in an object-oriented programming model in C language. It provides a unified platform base to support different kernels through platform decoupling and kernel decoupling. The figure below shows the HDF architecture.

  **Figure 1** HDF architecture 

![](figures/HDF-architecture.png)

The HDF consists of the following:

- Hardware Device Interface (HDI) layer: provides unified and stable APIs for hardware operations.

- HDF: provides unified hardware resource management, driver loading management, device node management, device power management, and driver service model. It consists of the device management, service management, Device Host, and PnPManager modules.

- Unified configuration interface (DevEco): supports abstract description of hardware resources, shields hardware differences, and enables development of universal driver code that is not bound to configuration information. You can use HC-Gen to quickly create configuration files. This unified configuration interface improves development and porting efficiency.

- Operating system abstraction layer (OSAL): provides encapsulated kernel operation APIs, including the APIs for the memory, locks, threads, and semaphores, to shield operation differences between different systems.

- Platform driver: provides unified APIs for peripheral drivers to operate board hardware, such as I2C, SPI, and UART buses, and uniformly abstracts the APIs for board hardware operations.

- Peripheral driver model: provides common driver abstraction models for peripheral drivers to provide standard device drivers and implement driver model abstraction. With standard device driver models, you can deploy drivers through configuration without independent development. The driver model abstraction makes the drivers more general by shielding the interaction between drivers and different system components.


## Driver Development


### Platform Drivers

The OpenHarmony platform drivers provide APIs for accessing the operating system and peripheral drivers. The platform devices refer to buses, such as I2C and UART, and specific hardware resources, such as GPIO and RTC. The platform driver framework is an important part of the OpenHarmony driver framework. Based on the HDF, OSAL, and driver configuration and management mechanism, the platform driver framework provides standard models for implementing a variety of platform device drivers. The platform driver framework provides standard platform device access APIs for peripherals regardless of difference in underlying hardware. It also provides unified adaptation APIs for platform device drivers, focusing only their own hardware control.

The platform driver framework provides the following features:

- Unified platform device access interface: encapsulates platform device operation APIs in a unified manner to shield hardware differences between SoC platforms and differences between OSs.

- Unified platform driver adaptation interface: provides unified adaptation APIs for platform device drivers. You only need to focus on the hardware control the driver, without caring about device management and common service processes.

- Common capabilities irrelevant to SoCs, such as device registration, management, and access control.

Currently, the platform driver framework supports devices, including the ADC, DAC, GPIO, HDMI, I2C, I3C, MIPI CSI, MIPI DSI, MMC, pin, PWM, regulator, RTC, SDIO, SPI, UART, and watchdog.


### Peripheral Drivers

Based on the HDF and platform driver framework, OpenHarmony provides common driver models for peripheral drivers. Standard peripheral device drivers help reduce repeated development. In addition, the unified abstraction of peripheral driver models shields the interaction between drivers and different system devices, making the drivers more general for use.

Currently, OpenHarmony supports peripherals covering audio, cameras, codecs, LCD, lights, motion, sensors, touchscreens, vibrators, USB, WLAN, face authentication, fingerprint authentication, PIN authentication, and user authentication.


### Driver Code Repositories

The table below describes the code repositories of the HDF.

  **Table 1** HDF code repositories

| Repository| Description|
| -------- | -------- |
| drivers/hdf_core/framework | Provides platform-independent frameworks:<br>- **framework/core**:<br>  - Provides capabilities of loading and starting drivers.<br>  - Implements elastic deployment and expansion of the driver framework through the object manager.<br>- **framework/model**:<br>  Provides driver models, such as the network device model.<br>- **framework/ability**<br>  Provides basic driver ability models, such as the I/O communication model.<br>- **framework/tools**:<br>  Provides tools for HDI API conversion, and driver configuration and compilation.<br>- **framework/support**<br>  Provides platform driver APIs and system APIs with normalized abstraction capabilities.|
| drivers/hdf_core/adapter | Provides adaptation code and build scripts related to LiteOS-M and LiteOS-A kernels and user-mode interface libraries.|
| drivers/hdf_core//adapter/khdf/linux | Provides adaptation code and build scripts related to Linux.|
| drivers/peripheral | Provides the hardware abstraction layer for peripheral modules, such as the display, input, sensor, WLAN, audio, and camera.|
| drivers/interface | Defines the HDI APIs of peripheral modules, such as the display, input, sensor, WLAN, audio, and camera.|


### How to Use

- To adapt the OpenHarmony driver to a new platform device, use the standard models and APIs provided by the OpenHarmony platform driver framework. You only need to focus on hardware control, without caring about the device management and common service processes. For details, see **Platform Driver Development**.

- After the platform driver adaptation, you can use the APIs provided by the OpenHarmony platform driver framework for the system and peripheral drivers to further develop services and applications. For details, see **Platform Driver Usage**.

- The OpenHarmony HDF provides a variety of standard peripheral driver models. These models shield hardware differences and provide stable and standard APIs for upper-layer services. You can use these models to develop peripheral drivers. For details, see **Peripheral Driver Usage**.
