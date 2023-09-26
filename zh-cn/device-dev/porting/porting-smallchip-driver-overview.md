# 移植概述


驱动主要包含两部分，平台驱动和器件驱动。平台驱动主要包括通常在SOC内的GPIO、I2C、SPI等；器件驱动则主要包含通常在SOC外的器件，如 LCD、TP、WLAN等


  **图1** OpenHarmony 驱动分类

  ![zh-cn_image_0000001207599659](figures/zh-cn_image_0000001207599659.png)


HDF驱动被设计为可以跨OS使用的驱动程序，HDF驱动框架会为驱动达成这个目标提供有力的支撑。开发HDF驱动中，请尽可能只使用HDF驱动框架提供的接口，否则会导致驱动丧失跨OS使用的特性。在开始驱动开发前，建议先了解[HDF驱动框架](../driver/driver-overview-foundation.md)。
