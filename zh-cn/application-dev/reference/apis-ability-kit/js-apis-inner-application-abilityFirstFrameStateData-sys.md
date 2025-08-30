# AbilityFirstFrameStateData(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

定义了首帧绘制完成事件回调上报的数据结构。通过[on](js-apis-app-ability-appManager-sys.md#appmanageronabilityfirstframestate12)注册监听Ability首帧绘制完成事件后，可使用[AbilityFirstFrameStateObserver](js-apis-inner-application-abilityFirstFrameStateObserver-sys.md)的[onAbilityFirstFrameDrawn](./js-apis-inner-application-abilityFirstFrameStateObserver-sys.md#onabilityfirstframedrawn)回调获取上报的数据结构。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称        | 类型    | 只读 | 可选 | 说明             |
| ----------- | ------- | ---- | ---- | ---------------- |
| bundleName  | string  | 否   | 否   | 应用Bundle名称。 |
| moduleName  | string  | 否   | 否   | 应用Module名称。 |
| abilityName | string  | 否   | 否   | Ability名称。    |
| appIndex    | number  | 否   | 否   | DLP沙盒的索引。  |
| isColdStart | boolean | 否   | 否   | 是否冷启动。true表示冷启动，false表示热启动。     |