# PermissionRequestResult

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。

权限请求结果。

## 导入模块

```js
import Ability from '@ohos.application.Ability'
```


## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。| 
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果。0表示授权成功，-1表示失败。  | 
