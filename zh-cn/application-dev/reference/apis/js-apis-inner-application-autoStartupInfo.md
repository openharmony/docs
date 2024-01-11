 # AutoStartupInfo

定义开机自启动应用组件信息。

> **说明：**
> 
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

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
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.setAutoStartup({
        bundleName: 'com.example.autostartupapp',
        moduleName: 'entry',
        abilityName: 'EntryAbility',
        abilityTypeName: 'ServiceExtension'
      }, (err, data) => {
        console.info('====> err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
      });
    } catch (err) {
      console.info('===> autostartupmanager setAutoStartup throw err: ' + JSON.stringify(err));
    }
  }
}
```
