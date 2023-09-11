# 包管理子系统ChangeLog
## cl.bundlemanager.1 ApplicationInfo结构体废弃metadata字段

从API version 10开始不再维护，建议使用metadataArray替代。

**变更影响**<br>
ApplicationInfo结构体从API version 10开始不再维护metadata字段。

**关键的接口/组件变更**<br>
ApplicationInfo结构体从API version 10开始，废弃metadata字段。

**适配指导**<br>
使用metadataArray字段替代metadata字段。

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
