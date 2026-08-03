# Setting Up the Environment

<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=0bd849420b8023922f904909cad7f1ce911d0c8d translatedAt=2026-07-29T01:37:44.650Z pushedAt=2026-07-29T02:08:17.814Z -->

## Development Tool and Configuration

DevEco Studio is a required tool for driver development. You can use it to develop, debug, and package drivers.

Download and install [DevEco Studio](https://developer.huawei.com/consumer/en/download/) using your HUAWEI ID. Then, follow the instructions in [Creating a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-create-new-project) in the [tool overview](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-tools-overview) to perform basic verification and ensure that DevEco Studio runs properly.

## SDK Version Configuration

The ArkTS APIs provided by the extended peripheral management module are applicable only when the SDK is of API version 10 or later<!--Del-->. For details about updating the SDK, see [Update Guide](../../tools/openharmony_sdk_upgrade_assistant.md)<!--DelEnd-->.

The following table lists the SDK versions required to develop dedicated peripheral drivers or enhanced peripheral drivers based on the DDK.

| NDK API          | SDK Version    |
|----------------|----------|
| [UsbDdk](../../reference/apis-driverdevelopment-kit/capi-usbddk.md)  | API 10 or later |
| [HidDdk](../../reference/apis-driverdevelopment-kit/capi-hidddk.md)        | API 11 or later |
| [USBSerialDDK](../../reference/apis-driverdevelopment-kit/capi-serialddk.md) | API 18 or later |
| [ScsiPeripheralDDK](../../reference/apis-driverdevelopment-kit/capi-scsiperipheralddk.md)  | API 18 or later |

## Verifying the Environment

Check whether DevEco Studio is connected to an OpenHarmony device.

![Device connection](figures/device-connected.png)

## HDC Configuration

HarmonyOS Device Connector (hdc) is a command-line debugging tool. It enables interaction with real devices or emulators on Windows, Linux, and Mac systems. For details, see [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc).

> **NOTE**
>   
> Configuring the environment variable **hdc_server_port** and global environment variables is mandatory.

## Development Device

<!--RP1-->

- This section uses RK3568 as the device for development, debugging, and verification. For compiling and burning the RK3568, refer to [Burning an Image](../../../device-dev/quick-start/quickstart-pkg-3568-burn.md).<!--RP1End-->

- When developing an extended peripheral driver client or peripheral driver, you need an external USB device for debugging. Currently, **only external devices connected over the USB bus are supported**.

- The product ID and vendor ID of the USB device are required for defining drivers and implementing IPC.

<!--no_check-->
