# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Deleted getAbilityIcon

The **getAbilityIcon** API in [@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts) is deleted. The **getMediaContent** API in [@ohos.resourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.resourceManager.d.ts) can be used instead.

**Change Impact**<br>
The **getAbilityIcon** API does not take effect.

**Key API/Component Changes**<br>
The **getAbilityIcon** API is deleted from **@ohos.bundle.bundleManager.d.ts**.

**Adaptation Guide**<br>
If your application uses **getAbilityIcon** in **@ohos.bundle.bundleManager.d.ts**, replace it with **getMediaContent** in **@ohos.resourceManager.d.ts**. You need to obtain the icon ID in advance. For details, see [Usage Guide](../../../application-dev/reference/apis/js-apis-resource-manager.md#getmediacontent9).

## cl.bundlemanager.2 Added Error Code 202

Error code 202 is added to the bundle manager subsystem. If a non-system application calls a system API of API version 9 or later provided by the bundle manager subsystem, error code 202 is returned.

**Change Impact**<br>
Error code 202 is returned when a non-system application calls a system API of API version 9 or later provided by the bundle manager subsystem.

**Key API/Component Changes**<br>
If a non-system application calls a system API of API version 9 or later provided by the bundle manager subsystem, error code 202 is returned.

**Adaptation Guide**<br>
No adaptation is required.
