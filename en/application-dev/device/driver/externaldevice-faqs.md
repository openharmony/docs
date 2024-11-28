# FAQs

## Incompatible System Version

### Symptom

The **usb/usb_ddk_api.h not found** or **hid/hid_ddk_api.h not found** error is displayed during SDK building or running.

### Solution

- If an error is reported during SDK building, check whether the system version is the latest.
<!--RP1-->
- If an error is reported during running, check whether the system version is 4.1 Release or later.<!--RP1End-->


### Symptom

The error message **compileSdkVersion and releaseType of the app do not match the apiVersion and releaseType on the device** is displayed during installation.

### Solution
<!--RP2-->
Check whether the system version of the device is correct according to the mapping provided in [Version Mapping](#version-mapping).
<!--RP2End-->
### Version Mapping
<!--RP3-->
| Peripheral SDK Name| Minimum API Version| OpenHarmony/HarmonyOS Version|
| ------------ | ------------ | ------------ |
| Application development APIs (ArkTS APIs)| API10 | 4.0 or later|
| USB DDK APIs| API10 | 4.0 or later|
| HID DDK APIs| API11 | 4.1 or later|
<!--RP3End-->

### Symptom

The error message **code:9568347 error: install parse native so failed** is displayed during HAP installation.

### Solution

Configure the value of **abiFilters** in **buildOption/externalNativeOptions** in the **build-profile.json5** file. For details, see [Application Debugging](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-app-debugging-14-V5).
