# Bundle Management Subsystem Changelog
## cl.bundlemanager.1 Field metadata in the ApplicationInfo struct Deprecated

The **metadata** field is deprecated since API version 10. You are advised to use **metadataArray** instead.

**Change Impact**

The **metadata** field in the **ApplicationInfo** struct is no longer maintained since API version 10.

**Key API/Component Changes**

The **metadata** field in the **ApplicationInfo** struct is deprecated since API version 10.

**Adaptation Guide**

Use the **metadataArray** field to replace the **metadata** field.

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));
            hilog.info(0x0000, 'testTag', 'metadataArray is: %{public}s', JSON.stringify(data.metadataArray));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);
}
```
