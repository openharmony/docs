# TriggerInfo

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

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

| 名称       | 类型                 | 只读 | 可选 | 说明        |
| ---------- | ------------------- | ---- | ---- | ----------- |
| code       | number               | 否 | 否 | 表示传递的公共事件数据，仅当WantAgent实例的[OperationType](js-apis-app-ability-wantAgent.md#operationtype)类型是'SEND_COMMON_EVENT'时有效。该字段与发布者使用[commonEventManager.publish](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerpublish-1)发布公共事件时，传递[CommonEventPublishData](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventPublishData.md#属性)公共事件数据中的`code`字段含义一致。 |
| want       | [Want](./js-apis-app-ability-want.md)                 | 否 | 是 | 对象间信息传递的载体，可以用于应用组件间的信息传递。    |
| permission | string               | 否 | 是 | 表示公共事件订阅者的权限。仅当WantAgent实例的[OperationType](js-apis-app-ability-wantAgent.md#operationtype)类型是'SEND_COMMON_EVENT'时，该字段生效。    |
| extraInfo  | { [key: string]: any } | 否 | 是 | 额外数据。    |
| extraInfos<sup>11+<sup>  | Record\<string, Object> | 否 | 是 | 额外数据。推荐使用该属性替代extraInfo，设置该属性后，extraInfo不再生效。    |