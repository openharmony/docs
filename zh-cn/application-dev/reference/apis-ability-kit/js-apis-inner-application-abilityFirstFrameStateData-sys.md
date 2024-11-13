# AbilityFirstFrameStateData(系统接口)

定义首帧绘制完成回调上报数据结构，可以通过[on](js-apis-app-ability-appManager-sys.md#appmanageronabilityfirstframestate12)注册监听Ability首帧绘制完成事件后，通过[AbilityFirstFrameStateObserver](js-apis-inner-application-abilityFirstFrameStateObserver-sys.md)的onAbilityFirstFrameDrawn首帧绘制完成回调获取。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称        | 类型    | 只读 | 必填 | 说明             |
| ----------- | ------- | ---- | ---- | ---------------- |
| bundleName  | string  | 是   | 否   | 应用Bundle名称。 |
| moduleName  | string  | 是   | 否   | 应用Module名称。 |
| abilityName | string  | 是   | 否   | Ability名称。    |
| appIndex    | number  | 是   | 否   | DLP沙盒的索引。  |
| isColdStart | boolean | 是   | 否   | 是否冷启动。     |