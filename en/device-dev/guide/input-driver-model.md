# Input Driver Model<a name="EN-US_TOPIC_0000001111681966"></a>

The input driver model mainly consists of the device manager, common drivers, and chip drivers.

-   Input device manager: provides various input device drivers with the APIs for registering or unregistering input devices and manages the input device list.
-   Input common driver: provides common drivers for initializing the board-level hardware, processing hardware interrupts, and registering input devices with the input device manager.
-   Input chip driver: calls differentiated APIs reserved by the input platform driver to minimize the workload for input chip driver development.

In addition, the input driver model implements functions for reporting input data and parsing input device configurations.

For details about the input driver model, see  [Touchscreen Overview](https://device.harmonyos.com/en/docs/develop/drive/oem_drive_touch_des-0000001052857350)[Touchscreen Overview](../driver/touchscreenoverview.md).

