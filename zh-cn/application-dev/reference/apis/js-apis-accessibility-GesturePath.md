# 手势路径

GesturePath表示手势路径信息。

本模块用于创建辅助功能注入手势所需的手势路径信息。

>![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
>本模块首批接口从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import GesturePath from '@ohos.accessibility.GesturePath';
```

## GesturePath

表示手势路径信息。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称           | 参数类型                                     | 可读   | 可写   | 说明     |
| ------------ | ---------------------------------------- | ---- | ---- | ------ |
| points       | Array&lt;[GesturePoint](js-apis-accessibility-GesturePoint.md#gesturepoint)&gt; | 是    | 是    | 手势触摸点。    |
| durationTime | number                                   | 是    | 是    | 手势总耗时, 单位为毫秒。 |

### constructor

constructor(durationTime: number);

构造函数。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| durationTime | number | 是 | 手势总耗时,单位为毫秒。 |

**示例：**

```ts
let gesturePath = new GesturePath.GesturePath(20);
```
