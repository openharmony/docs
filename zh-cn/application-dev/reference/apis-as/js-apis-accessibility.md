# @ohos.accessibility (辅助功能)

本模块提供查询是否启用辅助功能，是否开启触摸浏览模式的能力。

> **说明：**
>
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import accessibility from '@ohos.accessibility';
```

## accessibility.isOpenAccessibilitySync

isOpenAccessibilitySync(): boolean

是否启用了辅助功能。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型        | 说明                                  |
| ----------- | ------------------------------------- |
| boolean&gt; | 启用辅助功能返回true，否则返回false。 |

**示例：**

```ts
import accessibility from '@ohos.accessibility';

let status: boolean = accessibility.isOpenAccessibilitySync();
```

## accessibility.isOpenTouchGuideSync

isOpenTouchGuideSync(): boolean

是否开启了触摸浏览模式。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Vision

**返回值：**

| 类型    | 说明                                  |
| ------- | ------------------------------------- |
| boolean | 启用辅助功能返回true，否则返回false。 |

**示例：**

```ts
import accessibility from '@ohos.accessibility';

let status: boolean = accessibility.isOpenTouchGuideSync();
```
