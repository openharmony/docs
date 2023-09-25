# File Subsystem Changelog

## cl.file.1 Change of Error Codes in @ohos.file.storageStatistics and @ohos.file.volumeManager Documents

Changed the error code of "Unknown error" in all APIs in the API reference documents of the [@ohos.file.storageStatistics](../../../application-dev/reference/apis/js-apis-file-storage-statistics.md#) and [@ohos.file.volumeManager](../../../application-dev/reference/apis/js-apis-file-volumemanager.md#) modules. The error code returned is different from the error code in the d.ts file.

Before the change, the error code of "Unknown error" is **13900032**.

After the change, the error code of "Unknown error" is **13900042**.

**Change Impact**

In the code, **13900042** is returned for "Unknown error" from the first version. The error code of ""Unknown error" is incorrect in the d.ts file and API Reference documents.

For applications that have special processing on "13900032 Unknown error", change the error code to **13900042**.

**Key API/Component Changes**

All APIs in the @ohos.file.storageStatistics and @ohos.file.volumemanager modules are involved.

**Adaptation Guide**

For applications that have special processing on "Unknown error", change the error code to **13900042**.
