# ANS Subsystem Changelog

## cl.notificationManager.1 API Renaming

Renamed certain APIs to meet the naming conventions.

**Change Impact**

The underlying layer still supports the functions of the original APIs, and therefore these APIs can be called in OpenHarmony 4.0.2.3.

**Key API/Component Changes**

| Bundle Name           | Original API                                                      | New API                                                      |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.notificationManager.d.ts | **function** supportDoNotDisturbMode(callback: AsyncCallback\<boolean>): **void**; | **function** isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean>): **void**; |
| ohos.notificationManager.d.ts | **function** supportDoNotDisturbMode(): Promise\<boolean>; | **function** isSupportDoNotDisturbMode(): Promise\<boolean>; |

**Adaptation Guide**

Call the new API **isSupportDoNotDisturbMode**.
