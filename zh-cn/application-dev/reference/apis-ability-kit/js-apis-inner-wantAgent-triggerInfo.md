# TriggerInfo

作为[trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger)的入参定义触发WantAgent所需要的信息。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import { wantAgent } from '@kit.AbilityKit';
```

## 属性

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称       | 类型                 | 必填 | 说明        |
| ---------- | --- |-------------------- | ----------- |
| code       | number               | 是   | 提供给目标wantAgent的自定义结果码。 |
| want       | Want                 | 否   | 对象间信息传递的载体，可以用于应用组件间的信息传递。    |
| permission | string               | 否   | 权限定义。    |
| extraInfo  | { [key: string]: any } | 否   | 额外数据。    |
| extraInfos<sup>11+<sup>  | Record\<string, Object> | 否   | 额外数据。推荐使用该属性替代extraInfo，设置该属性后，extraInfo不再生效。    |