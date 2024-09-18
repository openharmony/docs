# USB Subsystem Changelog

## cl.usbManager.1 @ohos.usbManager controlTransfer Deprecated

**Access Level**

Public API

**Reason for Change**

The original API **ControlTransfer** is deprecated to comply with the USB standard protocol.

**Change Impact**

This change is a non-compatible change.
When the **controlTransfer** API is used, a message is displayed, indicating that the API has been deprecated. You are advised to use the substitute API **usbManager.usbControlTransfer**.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.36

**Deprecated APIs/Components**

|            API           |               Description              |           Substitute API           |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| usbManager.controlTransfer | Replaced by **usbManager.usbControlTransfer**.| usbManager.usbControlTransfer |


**Adaptation Guide**

Change **usbManager.controlTransfer** to **usbManager.usbControlTransfer** during application development.
