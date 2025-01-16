# AbilityFirstFrameStateObserver(系统接口)

定义Ability首帧绘制完成事件监听对象，可以作为[on](js-apis-app-ability-appManager-sys.md#appmanageronabilityfirstframestate12)的入参监听Ability首帧绘制完成事件。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## 属性

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                     | 类型                 | 只读 | 必填 | 说明                                                         |
| ------------------------ | -------------------- | ---- | ---- | ------------------------------------------------------------ |
| onAbilityFirstFrameDrawn | AsyncCallback\<void> | 是   | 否   | Ability首帧绘制完成时执行的回调函数。传入参数类型是[AbilityFirstFrameStateData](js-apis-inner-application-abilityFirstFrameStateData-sys)。 |