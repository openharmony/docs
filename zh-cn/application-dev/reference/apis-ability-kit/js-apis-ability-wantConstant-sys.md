# @ohos.ability.wantConstant (wantConstant)(系统接口)

wantConstant模块提供want中操作want常数和解释Flags说明的能力。

> **说明：**
> 
> 本模块首批接口从API version 6开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.wantConstant](js-apis-app-ability-wantConstant.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.ability.wantConstant (wantConstant)](js-apis-ability-wantConstant.md)。

## 导入模块

```ts
import wantConstant from '@ohos.ability.wantConstant';
```

## wantConstant.Flags

Flags说明。用于表示处理Want的方式。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称                                 | 值       | 说明                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。  |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 按照前缀匹配的方式验证URI权限。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。 |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示迁移是可拉回的。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。      |
