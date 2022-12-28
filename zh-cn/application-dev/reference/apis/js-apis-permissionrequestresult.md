# PermissionRequestResult

权限请求结果对象，在调用[requestPermissionsFromUser](js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)申请权限时返回此对象表明此次权限申请的结果。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。|
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果：0表示授权成功，非0表示失败。 |

## 使用说明

通过atManager实例来获取。

**示例：**
```ts
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
let atManager = abilityAccessCtrl.createAtManager();
try {
  atManager.requestPermissionsFromUser(this.context, ["ohos.permission.CAMERA"]).then((data) => {
      console.info("data:" + JSON.stringify(data));
      console.info("data permissions:" + data.permissions);
      console.info("data authResults:" + data.authResults);
  }).catch((err) => {
      console.info("data:" + JSON.stringify(err));
  })
} catch(err) {
  console.log(`catch err->${JSON.stringify(err)}`);
}
```