# FAQs

## Failed to Find the Header File During Compilation or Running

### Symptom

The message "usb/usb_ddk_api.h not found" or "hid/hid_ddk_api.h not found" is displayed during compilation or running.

### Solution

- If an error is reported during compilation, check whether the OpenHarmony version is the latest.
<!--RP1-->
- If an error is reported during running, check whether the device version is 4.1 Release or later.<!--RP1End-->

## Version Mismatch Displayed During HAP Installation

### Symptom

The message "compileSdkVersion and releaseType of the app do not match the apiVersion and releaseType on the device" is displayed during HAP installation.

### Solution

<!--RP2-->Check whether the system version of the device is correct<!--RP2--> according to the mapping provided in [Version Mapping](#version-mapping).

### Version Mapping
<!--RP3-->
| API Type| Minimum API Version| OpenHarmony Version|
| --------- | --------- | --------- |
| Application development APIs (ArkTS APIs)| API10 | 4.0 Release or later|
| USB DDK APIs| API10 | 4.0 Release or later|
| HID DDK APIs| API11 | 4.0 Release or later|
| USB Serial DDK API| API18 | 5.1 Release or later|
| SCSI Peripheral DDK API| API18 | 5.1 Release or later|
<!--RP3End-->

## Failed to Parse the Local .so File During HAP Installation

### Symptom

The message "code:9568347 error: install parse native so failed" is displayed during HAP installation.

### Solution

Configure the value of `abiFilters` in `buildOption/externalNativeOptions` in the `build-profile.json5` file. For details, see [Application Debugging] (https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-app-debugging-14-V5).
