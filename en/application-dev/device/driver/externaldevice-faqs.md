# FAQs

## Failed to Find the Header File During Compilation or Running

### Symptom

The message "usb/usb_ddk_api.h not found" or "hid/hid_ddk_api.h not found" is displayed during compilation or running.

### Solution

- If an error is reported during compilation, check whether the OpenHarmony version is the latest.

- If an error is reported during running, check whether the device version is <!--RP1-->4.1 Release<!--RP1End--> or later.

## Version Mismatch Displayed During HAP Installation

### Symptom

The message "compileSdkVersion and releaseType of the app do not match the apiVersion and releaseType on the device" is displayed during HAP installation.

### Solution

Check whether the system version of the device is correct according to the mapping provided in [Version Mapping](#version-mapping).

### Version Mapping

| API Type| Minimum API Version| OpenHarmony Version|
| ------------ | ------------ | ------------ |
| Application development APIs (ArkTS APIs)| API10 | <!--RP2-->4.0 Release<!--RP2End--> or later|
| USB DDK APIs| API10 | <!--RP3-->4.0 Release<!--RP3End--> or later|
| HID DDK APIs| API11 | <!--RP4-->4.1 Release<!--RP4End--> or later|


## Failed to Parse the Local .so File During HAP Installation

### Symptom

The message "code:9568347 error: install parse native so failed" is displayed during HAP installation.

### Solution

Configure the value of `abiFilters` in `buildOption/externalNativeOptions` in the `build-profile.json5` file. For details, see [Application Debugging] (https://developer.huawei.com/consumer/en/doc/harmonyos-faqs-V5/faqs-app-debugging-14-V5).
