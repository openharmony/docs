# ElementName

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wang19954-->
<!--SE: @hanfeng6; @lihaitao-->
<!--TSE: @kongjing2-->

应用组件结构体，包含bundleName、moduleName和abilityName等。通常用于组件启动信息[AbilityRunningInfo.ability](../apis-ability-kit/js-apis-inner-application-abilityRunningInfo.md)和组件启动回调函数[connectOptions.onConnect](../apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect)中。

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## ElementName

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称                     | 类型     | 只读 | 可选 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| deviceId                | string   | 否   |  是  | 设备ID。                   |
| bundleName              | string   | 否   |  否  | 应用Bundle名称。          |
| abilityName             | string   | 否   |  否  | Ability名称。               |
| uri                     | string   | 否   |  是  | 资源标识符。                 |
| shortName               | string   | 否   |  是  | Ability短名称，以“.”为开头的字符串。               |
| moduleName              | string   | 否   |  是  | Ability所属的HAP的模块名称。   |