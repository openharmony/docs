 # AutoStartupInfo (系统接口)

定义开机自启动应用组件信息。

> **说明：**
> 
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。
> 本模块接口为系统接口。

## 属性

**系统接口**: 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 类型   | 必填  | 说明       |
| ------------------------- | ------ | ---- | --------- |
| bundleName   | string | 是  | 应用程序的Bundle名称。 |
| moduleName | string | 否   | 应用程序的Module名称。 |
| abilityName | string | 是  | 应用程序的Ability名称。 |
| abilityTypeName | string | 否 | 应用程序的Ability类型。 |
| appCloneIndex | number   | 否   | 分身应用索引。  |

**示例：**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';

autoStartupManager.setApplicationAutoStartup({
  bundleName: 'com.example.autostartupapp',
  moduleName: 'entry',
  abilityName: 'EntryAbility',
  abilityTypeName: 'ServiceExtension'
} as common.AutoStartupInfo, (err, data) => {
  console.info('====> err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
});
```
