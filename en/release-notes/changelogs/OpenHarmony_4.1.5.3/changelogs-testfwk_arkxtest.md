# Test Subsystem ChangeLog

## cl.testfwk_arkxtest.1 Change to the WindowFilter Attribute Names

**Access Level**

Public

**Reason for Change**

This change is a compatible change.

**Change Impact**

This change affects the **WindowFilter** API provided by **@ohos.uitest**. If you have used the **WindowFilter** API of **@ohos.uitest-api9** during test case development, adaptation is required so that the compilation can be successful in the SDK environment of the new version.

**Change Since**

OpenHarmony SDK 4.1.5.3

**Key API/Component Changes**

WindowFilter<sup>9+</sup>

Before change

| Name      | Type   | Readable| Writable| Description                      |
| ---------- | ------- | ---- | ---- | -------------------------- |
| bundleName | string  | Yes  | No  | Bundle name of the application to which the window belongs.      |
| title      | string  | Yes  | No  | Title of the window.          |
| focused    | boolean | Yes  | No  | Whether the window is in focused state.    |
| actived    | boolean | Yes  | No  | Whether the window is interacting with the user.|

After change

| Name      | Type   | Readable| Writable| Description                      |
| ---------- | ------- | ---- | ---- | -------------------------- |
| bundleName | string  | Yes  | No  | Bundle name of the application to which the window belongs.      |
| title      | string  | Yes  | No  | Title of the window.          |
| focused    | boolean | Yes  | No  | Whether the window is in focused state.    |
| active     | boolean | Yes  | No  | Whether the window is interacting with the user.|

**Adaptation Guide**

Replace **actived** with **active**.

## cl.testfwk_arkxtest.2 Deprecation of the UiWindow.isActived API

**Access Level**

Public

**Reason for Change**

The API capability is enhanced.

**Change Impact**

This change affects the **UiWindow.isActived** API provided by **@ohos.uitest**. If you have used the **UiWindow.isActived** API of **@ohos.uitest-api9** during test case development, adaptation is required so that the compilation can be successful in the SDK environment of the new version.

**Deprecated Since**

OpenHarmony SDK 4.1.5.3

**Deprecated APIs/Components**

|            API           |               Description              |           Substitute           |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| isActived(): Promise\<boolean>; | Replaced by **isActive()**.| isActive(): Promise\<boolean>; |

**Adaptation Guide**

Replace **isActived()** with **isActive()**.
