# CliToolEvent (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

CliToolEvent用于描述CLI工具进程运行期间产生的会话事件信息。

**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## CliToolEvent

CLI工具会话事件信息。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称          | 类型                              | 只读 | 可选 | 说明              |
| ------------- | --------------------------------- | ---- | ---- | ----------------- |
| toolEventType | [ToolEventType](#tooleventtype)   | 否   | 否   | CLI工具事件类型。 |
| data          | string                            | 否   | 否   | CLI工具事件数据。 |

## ToolEventType

CLI工具会话事件类型。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称   | 值       | 说明           |
| ------ | -------- | -------------- |
| STDOUT | 'stdout' | 标准输出事件。 |
| STDERR | 'stderr' | 标准错误事件。 |
| EXIT   | 'exit'   | 进程退出事件。 |
| ERROR  | 'error'  | 进程错误事件。 |
