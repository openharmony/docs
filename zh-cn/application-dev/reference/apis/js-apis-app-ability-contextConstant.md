# @ohos.app.ability.contextConstant (ContextConstant)

ContextConstant提供Context相关的枚举，当前仅包含数据加密等级的枚举。

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
| EL1 | 0 | 设备级加密区，设备开机后可访问的数据区。 |
| EL2 | 1 | 用户级加密区，设备开机，首次输入密码后才能够访问的数据区。 |
