# ContextConstant

ContextConstant模块提供数据加密等级定义的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import contextConstant from '@ohos.app.ability.contextConstant';
```

## ContextConstant.AreaMode

使用时通过ContextConstant.AreaMode获取。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| EL1 | 0 | 设备级加密区。 | 
| EL2 | 1 | 用户凭据加密区。 | 
