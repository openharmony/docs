# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 BundleManager.verifyAbc and bundleManager.deleteAbc Are Changed to System APIs

**Access Level**

Public API

**Reason for Change**

To meet security compliance requirements, the **bundleManager.verifyAbc** and **bundleManager.deleteAbc** APIs in [@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts) are changed to system APIs.

**Change Impact**

This change is a non-compatible change.

Before change:

**bundleManager.verifyAbc** and **bundleManager.deleteAbc** are public APIs and can be called by third-party applications.

After change:

**bundleManager.verifyAbc** and **bundleManager.deleteAbc** are changed to system APIs and can be called only by system applications. If a non-system application calls these APIs, error code 202 is returned.


**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.44

**Key API/Component Changes**

The following APIs in [@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts):

1. function verifyAbc(abcPaths: Array\<string\>, deleteOriginalFiles: boolean, callback: AsyncCallback\<void\>): void;

2. function verifyAbc(abcPaths: Array\<string\>, deleteOriginalFiles: boolean): Promise\<void\>;

3. function deleteAbc(abcPath: string): Promise\<void\>;

**Adaptation Guide**

Cancel the call of these APIs in your code. If a non-system application calls these APIs, error code 202 is returned.
