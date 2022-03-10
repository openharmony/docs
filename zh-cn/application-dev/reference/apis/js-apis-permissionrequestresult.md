# PermissionRequestResult

- [属性](#属性)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 9开始支持。


权限请求结果。


## 属性

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core| 
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果。0表示授权成功，-1表示失败。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
