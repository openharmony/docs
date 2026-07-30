# FunctionInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @dsz2025-->
<!--Adviser: @HelloCrease-->

FunctionInfo用于描述[Function](./js-apis-app-function-functionManager-sys.md)的基本信息，包括Function命名空间、名称、版本、描述、输入输出模式等。

**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。

## 导入模块

```ts
import { FunctionInfo } from '@kit.AbilityKit';
```

## FunctionInfo

描述[Function](./js-apis-app-function-functionManager-sys.md)的基本信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称               | 类型                                                   | 只读 | 可选 | 说明                                                         |
| ------------------ | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| functionNamespace  | string                                                 | 是   | 否   | Function的命名空间，用于在系统中对Function进行分类和管理。命名空间可以帮助组织和识别不同功能领域的Function。 |
| functionName       | string                                                 | 是   | 否   | Function的名称，用于在functionNamespace内唯一标识一个Function。             |
| version            | string                                                 | 是   | 否   | Function的版本号。遵循语义化版本规范（如"1.0.0"），格式由提供商定义。版本号用于标识Function的功能迭代和兼容性变化。 |
| description        | string                                                 | 是   | 否   | Function的功能描述。该描述应清晰说明Function的核心功能和用途，帮助用户和AI Agent理解Function能做什么，用于辅助决策。 |
| inputSchema        | string                                                 | 是   | 是   | Function的输入参数JSON Schema定义，描述Function接受的输入参数结构和类型。需要符合JSON Schema格式定义。 |
| outputSchema       | string                                                 | 是   | 是   | Function的输出结果JSON Schema定义，描述Function返回值的结构和类型。需要符合JSON Schema格式定义。 |
