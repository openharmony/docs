# PermissionRequestResult

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


权限请求结果。

## 导入模块

```js
import PermissionRequestResult from '@ohos.application.permissionRequestResult'
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。| 
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果。0表示授权成功，-1表示失败。  | 
