# ExtensionRunningInfo (系统接口)

ExtensionRunningInfo模块封装了Extension运行的相关信息，可以通过[getExtensionRunningInfos接口](js-apis-app-ability-abilityManager-sys.md#getextensionrunninginfos)获取。

> **说明：**
> 
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口为系统接口。

## 导入模块

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## 使用说明

导入abilityManager模块，通过调用abilityManager中的方法获取ExtensionRunningInfo。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：以下各项对应的接口均为系统接口，三方应用不支持调用。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| extension | [ElementName](js-apis-bundleManager-elementName.md) | 是 | 否 | Extension信息。 |
| pid | number | 是 | 否 | 进程ID。 |
| uid | number | 是 | 否 | 应用程序的uid。 |
| processName | string | 是 | 否 | 进程名称。 |
| startTime | number | 是 | 否 | Extension被启动时的时间戳。 |
| clientPackage | Array&lt;String&gt; | 是 | 否 | 表示当期进程下的所有包名。 |
| type | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | 是 | 否 | Extension类型。 |

**示例：**
```ts
import { abilityManager } from '@kit.AbilityKit';

let upperLimit = 1;

function getExtensionInfos() {
  abilityManager.getExtensionRunningInfos(upperLimit, (error, data) => {
    if (error) {
      console.error(`getForegroundApplications failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
      return;
    }

    for (let i = 0; i < data.length; i++) {
      let extensionRunningInfo = data[i];
      console.log(`extensionRunningInfo.extension: ${JSON.stringify(extensionRunningInfo.extension)}`);
      console.log(`extensionRunningInfo.pid: ${JSON.stringify(extensionRunningInfo.pid)}`);
      console.log(`extensionRunningInfo.uid: ${JSON.stringify(extensionRunningInfo.uid)}`);
      console.log(`extensionRunningInfo.processName: ${JSON.stringify(extensionRunningInfo.processName)}`);
      console.log(`extensionRunningInfo.startTime: ${JSON.stringify(extensionRunningInfo.startTime)}`);
      console.log(`extensionRunningInfo.clientPackage: ${JSON.stringify(extensionRunningInfo.clientPackage)}`);
      console.log(`extensionRunningInfo.type: ${JSON.stringify(extensionRunningInfo.type)}`);
    }
  });
}
```
