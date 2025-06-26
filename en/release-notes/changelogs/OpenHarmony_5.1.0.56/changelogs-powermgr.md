# Power Management Subsystem Changelog

## cl.powermgr Change in ohos.permission.POWER_MANAGER Permission Verification and Error Codes for wakeup, suspend, setScreenOffTime and hibernate APIs

**Access Level**

System API

**Reason for the Change**

Some TS APIs violate the minimum permission principle. Therefore, permission verification need to be added to the corresponding APIs.

**Change Impact**

This change requires application adaptation.

Before change:
System applications can directly access the **wakeup**, **suspend**, **setScreenOffTime**, and **hibernate** APIs without requesting for permissions.

After change:
System applications can call these APIs only after obtaining the **ohos.permission.POWER_MANAGER** permission. If the API permission verification fails, error code 201 is reported.

**Start API Level**

- wakeup available since API version 9
- suspend available since API version 9
- setScreenOffTime available since API version 12
- hibernate available since API version 12

**Change Since**

OpenHarmony SDK 5.1.0.56

**Key API/Component Changes**

The following APIs in [@ohos.account.distributedAccount.d.ts](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md):

- wakeup(detail: string): void
- suspend(isImmediate?: boolean): void
- setScreenOffTime(timeout: number): void
- hibernate(clearMemory: boolean): void

**Adaptation Guide**

An application needs to request for the **ohos.permission.POWER_MANAGER** permission for calling the related APIs.

The error code 201 is added to the **wakeup** API. The following is an example:
```ts
import { power } from '@kit.BasicServicesKit';

try {
    power.wakeup('wakeup_test');
} catch (err) {
    if (err.code === 201) {
      console.error('wakeup failed, permission verification failed');
    } else {
      console.error('wakeup failed, err: ' + err);
    }
}
```

The error code 201 is added to the **suspend** API. The following is an example:
```ts
import { power } from '@kit.BasicServicesKit';

try {
    power.suspend();
} catch (err) {
    if (err.code === 201) {
      console.error('suspend failed, permission verification failed');
    } else {
      console.error('suspend failed, err: ' + err);
    }
}
```

The error code 201 is added to the **setScreenOffTime** API. The following is an example:
```ts
import { power } from '@kit.BasicServicesKit';

try {
    power.setScreenOffTime(30000);
} catch (err) {
    if (err.code === 201) {
      console.error('set screen off time failed, permission verification failed');
    } else {
      console.error('set screen off time failed, err: ' + err);
    }
}
```

The error code 201 is added to the **hibernate** API. The following is an example:
```ts
import { power } from '@kit.BasicServicesKit';

try {
    power.hibernate(true);
} catch (err) {
    if (err.code === 201) {
      console.error('hibernate failed, permission verification failed');
    } else {
      console.error('hibernate failed, err: ' + err);
    }
}
```
