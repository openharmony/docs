# ContinuationExtraParams

本模块提供流转管理入口中互联面板所需的过滤参数。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import continuationManager from "@ohos.continuation.continuationManager"
```

## ContinuationExtraParams

表示流转管理入口中互联面板所需的过滤参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.DistributedAbilityManager

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceType | Array\<string> | 是 | 是 | 表示设备类型。|
| targetBundle | string | 是 | 是 | 表示目标包名。 |
| description | string | 是 | 是 | 表示设备过滤的描述。 |
| filter | any | 是 | 是 | 表示设备过滤的参数。 |
| continuationMode | [ContinuationMode](js-apis-continuation-continuationManager.md#continuationmode) | 是 | 是 | 表示协同的模式。 |
| authInfo | { [key: string]: any } | 是 | 是 | 表示认证的信息。 |