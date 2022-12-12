# ErrorCode

ErrorCode是定义启动功能时使用的错误代码。

本模块提供使用的错误代码的能力，包括没有错误，无效的参数等。

> **说明：**
> 
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import errorCode from '@ohos.ability.errorCode'
```

## ErrorCode

定义启动功能时使用的错误代码。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                             | 值    | 说明                                       |
| ------------------------------ | ---- | ---------------------------------------- |
| NO_ERROR         | 0    | 没有错误。   |
| INVALID_PARAMETER | -1   | 无效的参数。 |
| ABILITY_NOT_FOUND | -2   | 找不到ABILITY。 |
| PERMISSION_DENY   | -3   | 拒绝许可。   |