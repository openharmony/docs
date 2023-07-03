# Common Capability Changelog

## cl.common.1 System API Usage Rule Changed

When a system API is called, no verification is performed to check whether the caller is a system application or third-party application. As a result, a third-party application can switch to the full SDK to use system APIs, which brings security risks. To address this issue, application identity verification is added to OpenHarmony 4.0.2.1 and later versions.

**Change Impact**

System APIs are available only to system applications. When a third-party application tries to use a system API, the **202** error will be returned via either an exception or asynchronous callback.

**Adaptation Guide**

To use a system API, a third-party application must either request the system application permission or use a substitute API that is available for non-system applications.
