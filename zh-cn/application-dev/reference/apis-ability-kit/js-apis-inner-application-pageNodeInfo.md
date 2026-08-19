# PageNodeInfo

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @HelloCrease-->

用于自动填充的页面节点信息。

**起始版本：** 26.0.0

## 导入模块

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## PageNodeInfo

**起始版本：** 26.0.0

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 名称         | 类型    | 只读 | 可选 | 说明           |
| ------------ | ------- | ---- | ---- | ------------- |
| id           | number  | 否   | 否   | 页面节点的ID。 |
| autoFillType | [AutoFillType](js-apis-inner-application-autoFillType.md) | 否   | 否   | 页面节点的自动填充类型。 |
| value        | string  | 否   | 否   | 页面节点的值。 |
| placeholder  | string  | 否   | 是   | 页面节点的占位符。 |
| rect         | [AutoFillRect](js-apis-inner-application-autoFillRect.md) | 否   | 否   | 当前节点的坐标和宽高信息。 |
| isFocus      | boolean | 否   | 否   | 当前节点是否获焦。 true表示当前节点获焦， false表示当前节点未获焦。 |
