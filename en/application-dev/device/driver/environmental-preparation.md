# Setting Up the Environment

## Development Tool and Configuration

DevEco Studio, as the driver development tool, allows you to develop, debug, and package drivers. [Download and install](https://developer.huawei.com/consumer/en/download/) DevEco Studio and verify basic operations to ensure that it can function properly.

[Download and install](https://developer.huawei.com/consumer/en/download/) DevEco Studio and verify basic operations to ensure that it can function properly. For details, see [Creating and Running a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-create-new-project) in [DevEco Studio User Guide](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-tools-overview).

## SDK Version Configuration

The ArkTs APIs for peripheral management are applicable only when the SDK is of API version 10 or later.

The following table lists the SDK versions required to develop dedicated peripheral drivers or enhanced peripheral drivers based on the DDK.

| NDK API         | SDK Version   |
|----------------|----------|
| USB DDK        | API version 10 or later|
| HID DDK        | API version 11 or later|
| USB Serial DDK | API version 18 or later|
| SCSI Peripheral DDK  | API version 18 or later|

## Verifying the Environment

Check whether DevEco Studio is connected to the OpenHarmony device.

![Device connection](figures/device-connected.png)

## HDC Configuration

HarmonyOS Device Connector (hdc) is a command-line tool for debugging. It can be used to interact with real devices or the Emulators on Windows, Linux, and macOS. For details about the configuration, see [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc).

**NOTE**<br>Configuration of the environment variable **hdc_server_port** and global environment variables is mandatory.

## Development Device
<!--RP1-->
- Currently, RK3568 is used as the device for development, debugging, and verification. For details about how to compile and burn the RK3568, see [Quick Start](../../../device-dev/quick-start/quickstart-pkg-3568-burn.md).<!--RP1End-->
- During peripheral client and driver development, you need to connect an external USB device for debugging. Currently, **only an external USB device is supported**.
- The product ID and vendor ID of the USB device are required for defining drivers and implementing IPC.
