# Network Subsystem Changelog

## cl.network.1 Error Code 2302998 Added to webSocket.connect

**Access Level**

Public API

**Reason for Change**

The purpose of this change is to standardize the range of domain names for atomic service requests and improve the atomic service release efficiency and platform operation security. When a user initiates an atomic service request, domain name access is subject to the domain name configured for the atomic service. If no domain name is configured, the **connect** API returns the error code 2302998.

**Change Impact**

This change is a non-compatible change.

If no domain name is configured for atomic services of API version 11 or earlier, the **connect** API is not affected.

From API version 12, the **connect** API throws this error code for access to a domain name not configured for an atomic service. For details, see [API Reference](../../../application-dev/reference/apis-network-kit/js-apis-webSocket.md).

**Start API Level**

6

**Change Since**

OpenHarmony SDK 5.0.0.36

**Key API/Component Changes**

| Interface File                                                                                                              |
|--------------------------------------------------------------------------------------------------------------------|
| [ohos.net.webSocket.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.net.webSocket.d.ts) |

**Adaptation Guide**

If you use the **webSocket.connect** API for connection setup when developing an atomic service, you need to go to [AppGallery Connect](https://developer.huawei.com/consumer/en-us/service/josp/agc/index.html)
to configure the server domain name. For details, see [Development Guide](https://developer.huawei.com/consumer/en-us/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5).

If the **webSocket.connect** API fails during atomic service development, use **catch** to capture the error. If the error code is **2302998**, configure the server domain name in [AppGallery Connect](https://developer.huawei.com/consumer/en-us/service/josp/agc/index.html). For details, see [Development Guide](https://developer.huawei.com/consumer/en-us/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5).
