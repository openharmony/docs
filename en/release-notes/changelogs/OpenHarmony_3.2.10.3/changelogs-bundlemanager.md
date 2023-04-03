# Bundle Manager Subsystem ChangeLog

## cl.bundlemanager.1 Name Change of the Bundle Manager Distributed Query Module

The name of the bundle manager distributed query module in API version 9 is changed from **ohos.bundle.distributedBundle** to **[ohos.bundle.distributedBundleManager](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.distributedBundleManager.d.ts)**. The APIs remain unchanged.

**Change Impacts**

There is no impact on applications that use the APIs of versions earlier than 9. The applications that use the APIs of version 9 need to adapt the new module.

**Key API/Component Changes**

The name of the bundle manager distributed query module is changed from **ohos.bundle.distributedBundle** to **ohos.bundle.distributedBundleManager**. The APIs remain unchanged.

**Adaptation Guide**

Change the module to import from **@ohos.bundle.distributedBundle** to **@ohos.bundle.distributedBundleManager**.

```ts
import distributedBundle form '@ohos.bundle.distributedBundleManager';
```
