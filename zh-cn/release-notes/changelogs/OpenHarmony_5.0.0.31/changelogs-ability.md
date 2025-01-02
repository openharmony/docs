# ability子系统Changelog

## cl.ability.1 restartApp接口变更

**访问级别**

公开接口

**变更原因**

避免恶意应用在非获焦状态下重启自身，实现霸屏。

**变更影响**

该变更为不兼容性变更。开发者需要在应用处于获焦状态时使用该接口，否则会影响功能。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**适配指导**

开发者需要在应用处于获焦状态时调用restartApp接口。

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onForeground() {
    let applicationContext = this.context.getApplicationContext();
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'EntryAbility'
    };
    try {
      applicationContext.restartApp(want);
    } catch (error) {
      console.error(`restartApp fail, error: ${JSON.stringify(error)}`);
    }
  }
}
```
