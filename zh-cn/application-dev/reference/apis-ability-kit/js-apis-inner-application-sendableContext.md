# SendableContext

SendableContext符合[Sendable协议](../../arkts-utils/arkts-sendable.md#sendable协议)，继承自[lang.ISendable](../apis-arkts/js-apis-arkts-lang.md#langisendable)。

> **说明：**
>
> - 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { sendableContextManager } from '@kit.AbilityKit';
```

## SendableContext

SendableContext符合[Sendable协议](../../arkts-utils/arkts-sendable.md#sendable协议)，可以与Context对象相互转换，用于ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）的数据传递。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。
