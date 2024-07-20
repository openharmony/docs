# AutoStartupCallback (系统接口)

应用设置为开机自启动时的回调函数。

> **说明：**	
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。
> 本模块接口为系统接口。

## AutoStartupCallback.onAutoStartupOn

onAutoStartupOn(info: AutoStartupInfo): void;

应用设置为开机自启动时调用。

**系统接口**: 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | 是 | 设置为开机自启动的应用组件信息。 |

**示例：**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let autoStartupCallback: common.AutoStartupCallback = {
  onAutoStartupOn(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
  },
  onAutoStartupOff(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
  }
}

try {
  autoStartupManager.on('systemAutoStartup', autoStartupCallback)
} catch (err) {
  console.info('===> autostartupmanager on callback err: ' + JSON.stringify(err as BusinessError));
}
```

## AutoStartupCallback.onAutoStartupOff

onAutoStartupOff(info: AutoStartupInfo): void;

取消应用开机自启动时调用。

**系统接口**: 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                 |
| ------ | --------------- | ---- | -------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | 是   | 取消开机自启动的应用组件信息。 |

**示例：**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let autoStartupCallback: common.AutoStartupCallback = {
  onAutoStartupOn(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
  },
  onAutoStartupOff(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
  }
}

try {
  autoStartupManager.on('systemAutoStartup', autoStartupCallback)
} catch (err) {
  console.info('===> autostartupmanager on callback err: ' + JSON.stringify(err as BusinessError));
}
```
