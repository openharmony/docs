# Device Management Subsystem Changelog

## cl.device_manager.1 API Call Behavior Change Due to SHA256-based Obfuscation and Truncation of udid-hash, appid, and Salt Value, with the First 16 Bits Retained as the Device ID

**Access Level**

Public API

**Reason for Change**

The API for obtaining the deviceid has a security vulnerability. The deviceid obtained by the application remains unchanged after the device is reset or the application is reinstalled. The deviceid can still be used to identify the device on the application.

**Change Impact**

This change is a non-compatible change.

Before change:
After the device is reset or the application is reinstalled, the deviceid obtained remains the same.

After change:
1. The deviceid obtained by the same application after the device is reset is different.
2. The deviceid obtained after the application is reinstalled is different.
3. The deviceid obtained by another application on the same device is different.
4. The deviceid of the same device obtained by the same application on different devices is different.

**Start API Level**

API 10

**Change Since**

OpenHarmony SDK 5.0.0.41

**Key API/Component Changes**

N/A.

**Adaptation Guide**

1. deviceid comparison: The network ID is sent to the peer end for comparison.
2. networkid comparison: The application compares the deviceid with that obtained from the SA.
