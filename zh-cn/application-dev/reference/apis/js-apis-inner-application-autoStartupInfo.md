 # AutoStartupInfo

定义开机自启动应用组件信息。

> **说明：**
> 
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 类型   | 必填  | 说明       |
| ------------------------- | ------ | ---- | --------- |
| bundleName   | string | 是  | 应用程序的Bundle名称。 |
| moduleName | string | 否   | 应用程序的Module名称。 |
| abilityName | string | 是  | 应用程序的Ability名称。 |
| abilityTypeName | string | 否 | 应用程序的Ability类型。 |

**示例：**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

let autoStartupCallback = {
  onAutoStartupOn(data) {
    console.info('==> autostartupmanager onAutoStartupOn data.bundleName: ' + data.bundleName);
    console.info('==> autostartupmanager onAutoStartupOn data.moduleName: ' + data.moduleName);
    console.info('==> autostartupmanager onAutoStartupOn data.abilityName: ' + data.abilityName);
    console.info('==> autostartupmanager onAutoStartupOn data.abilityTypeName: ' + data.abilityTypeName);
  },
  onAutoStartupOff(data) {
    console.info('==> autostartupmanager onAutoStartupOff data.bundleName: ' + data.bundleName);
    console.info('==> autostartupmanager onAutoStartupOff data.moduleName: ' + data.moduleName);
    console.info('==> autostartupmanager onAutoStartupOff data.abilityName: ' + data.abilityName);
    console.info('==> autostartupmanager onAutoStartupOff data.abilityTypeName: ' + data.abilityTypeName);
  }
}
try {
  AutoStartupManager.on('systemAutoStartup', autoStartupCallback)
} catch (err) {
  console.info('==> autostartupmanager on callback err: ' + JSON.stringify(err));
}
```
