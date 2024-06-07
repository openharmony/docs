# @ohos.application.formError (formError)(系统接口)

formError模块提供获取卡片错误码的能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API version 9 开始不再维护，建议使用[Form错误码](errorcode-form.md)替代。
> 当前页面仅包含本模块的系统接口，其他公共接口参见[@ohos.application.formError (FormError)](js-apis-application-formError.md)。

## 导入模块

```ts
import { formError } from '@kit.FormKit'
```

## 权限

无

## FormError

枚举，支持的卡片类型

**系统能力：** SystemCapability.Ability.Form

| 名称        | 值   | 说明         |
| ----------- | ---- | ------------ |
| ERR_DISTRIBUTED_SCHEDULE_FAILED<sup>9+</sup> | 37 | 分布式调度失败。<br/>**系统接口**: 此接口为系统接口。  |
