# Overview<a name="EN-US_TOPIC_0000001172160289"></a>

Drivers can be classified as platform drivers or device drivers. The platform drivers are generally in the SoC, such as the GPIO, I2C, and SPI drivers. The device drivers are typically outside of the SoC, such as the LCD, TP, and WLAN drivers.

**Figure  1**  OpenHarmony driver classification<a name="fig11697182018375"></a>  


![](figure/分类.png)

The Hardware Driver Foundation \(HDF\) is designed to work across OSs. The HDF driver framework provides strong support for drivers to achieve this goal. During HDF driver development, you are advised to use only the APIs provided by the HDF driver framework. Otherwise, the driver cannot be used across OSs. Before driver development, familiarize yourself with the  [HDF](../driver/driver-hdf-overview.md).

