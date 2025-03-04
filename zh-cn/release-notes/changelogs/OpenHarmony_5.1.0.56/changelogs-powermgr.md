# 电源管理子系统Changelog

## cl.powermgr @ohos.power.d.ts中wakeup、suspend、setScreenOffTime、hibernate接口新增ohos.permission.POWER_MANAGER权限校验、错误码变更

**访问级别**

系统接口

**变更原因**

电源服务中部分ts接口对应native层的权限校验存在问题，违反权限最小化原则，因此需要给相应接口新增权限。

**变更影响**

此变更涉及应用适配。

变更前：
系统应用可直接访问wakeup、suspend、setScreenOffTime、hibernate接口，无需申请权限。

变更后：
系统应用需申请ohos.permission.POWER_MANAGER权限后，方可调用wakeup、suspend、setScreenOffTime、hibernate接口，接口权限校验失败会抛出201错误码。

**起始API Level**

- wakeup接口起始API 9
- suspend接口起始API 9
- setScreenOffTime接口起始API 12
- hibernate接口起始API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

[@ohos.power.d.ts](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-power-sys.md)中如下接口:

- wakeup(detail: string): void
- suspend(isImmediate?: boolean): void
- setScreenOffTime(timeout: number): void
- hibernate(clearMemory: boolean): void

**适配指导**

接口调用方需要申请ohos.permission.POWER_MANAGER权限。

调用wakeup接口新增201错误码,示例如下:
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

调用suspend接口新增201错误码,示例如下:
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

调用setScreenOffTime接口新增201错误码,示例如下:
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

调用hibernate接口新增201错误码,示例如下:
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