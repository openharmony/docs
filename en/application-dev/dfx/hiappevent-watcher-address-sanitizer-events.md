# Address Sanitizer Event Overview
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mlkgeek-->
<!--Designer: @StevenLai1994-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## Overview

An address sanitizer event indicates that an invalid address has been accessed, causing the application to behave abnormally. In most cases, the application crashes.

You can subscribe to address sanitizer events through the HiAppEvent APIs. Both ArkTS and C/C++ APIs are available. Choose the one that fits your scenario.

- [Subscribing to Address Sanitizer Events (ArkTS)](hiappevent-watcher-address-sanitizer-events-arkts.md)

- [Subscribing to Address Sanitizer Events (C/C++)](hiappevent-watcher-address-sanitizer-events-ndk.md)

> **NOTE**
>
> Address sanitizer events can be subscribed to through HiAppEvent in [application clones](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone). Since API version 22, this capability is also supported in [input method applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide). It is not supported in atomic services.

## Detection Principles

For details, see [Address Sanitizer Detection](address-sanitizer-guidelines.md).

## Page Switch Log Custom Parameters

Since **API version 24**, page switch log configuration is supported. When an address sanitizer fault occurs in an application, the system can collect and report page switch logs to help you locate the issue.

### configEventPolicy

| API| Description|
| -------- | -------- |
| [configEventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventconfigeventpolicy22) (policy: EventPolicy): Promise&lt;void>| Sets the policy parameters for address sanitizer events and enables page switch log collection for address sanitizer events. |

### Parameters of configEventPolicy

You can enable page switch log collection for address sanitizer events by setting parameters in [EventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#eventpolicy22).

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| addressSanitizerPolicy | [AddressSanitizerPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#addresssanitizerpolicy24) | No| Yes| Configuration policy for address sanitizer events. |

Example:

```ts
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';
import { deviceInfo, BusinessError } from '@kit.BasicServicesKit';

let policy: hiAppEvent.EventPolicy = {
    "addressSanitizerPolicy": {
        "pageSwitchLogEnable": true // Enable page switch logs.
    }
};
hiAppEvent.configEventPolicy(policy).then(() => {
    hilog.info(0x0000, 'hiAppEvent', `Set addressSanitizer config policy successfully.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'hiAppEvent', `Failed to set addressSanitizer config policy. code: ${err.code}, message: ${err.message}`);
});
```

## Event Fields

### params

The **params** field in address sanitizer event information is described as follows:

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Time when the event is triggered, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| type | string | Address sanitizer error type. For details, see **type**.|
| external_log | string[] | Path of the fault log file. **To prevent new log files from failing to be written because the directory storage exceeds the limit (see `log_over_limit`), delete the log files promptly after they are processed.**|
| log_over_limit | boolean | Whether the total size of generated fault log files and existing log files exceeds the upper limit of 5 MB. The value **true** indicates that the limit is exceeded and log writing fails. The value **false** indicates that the limit is not exceeded.<br>When minidump is enabled, the upper limit is adjusted to 35 MB. When minidump is disabled, the upper limit is restored to 5 MB.|
| page_switch_log | string | Path of the page switch log.<br>**NOTE**: Supported since API version 24.|

### type

The **type** field in address sanitizer event information is described as follows:

| Value| Description|
| -------- | -------- |
| GWP-ASAN | Error type triggered by [GWP-ASan](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-gwpasan-detection).|
| UBSAN | Error type triggered by [UBSan](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ubsan-detection).|
| TSAN | Error type triggered by [TSan](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-tsan-detection).|
| FDSAN | Since API version 20, you can subscribe to error types triggered by [fdsan](../napi/fdsan.md).|
| ARKTS_ENVSAN | Since API version 26.0.0, you can subscribe to events reported by [Ark multi-thread detection](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ark-runtime-detection#section75786272088).|
| stack tag-mismatch | [HWASan](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-hwasan-detection) detects a stack tag mismatch, which may be caused by use after return, out-of-scope stack access, or out-of-bounds access.|
| alloc-dealloc-mismatch | The memory allocation and deallocation methods do not match.|
| allocation-size-too-big | Heap memory that is too large is allocated.|
| calloc-overflow | A memory allocation error occurs in **calloc**.|
| container-overflow | Container overflow occurs.|
| double-free | Memory is freed repeatedly.|
| dynamic-stack-buffer-overflow | Buffer access exceeds the boundary of a stack-allocated object.|
| global-buffer-overflow | Global buffer overflow occurs.|
| heap-buffer-overflow | Heap buffer overflow occurs.|
| heap-use-after-free | Released heap memory is accessed.|
| invalid-allocation-alignment | An invalid memory allocation alignment is used.|
| memcpy-param-overlap | **memcpy** does not support overlapping memory regions.|
| new-delete-type-mismatch | The deallocated memory size does not match the allocated size.|
| stack-buffer-overflow | Stack buffer overflow occurs.|
| stack-buffer-underflow | Stack buffer underflow occurs.|
| stack-use-after-return | Stack memory is used after the function returns.|
| stack-use-after-scope | Stack memory outside the valid scope is used.|
| strcat-param-overlap | An error occurs because memory is moved in overlapping buffers.|
| use-after-poison | A poisoned memory address is accessed.|
