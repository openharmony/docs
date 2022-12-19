# PermissionRequestResult

权限请求结果对象，在调用[requestPermissionsFromUser](js-apis-inner-application-uiAbilityContext.md#abilitycontextrequestpermissionsfromuser)申请权限时返回此对象表明此次权限申请的结果。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。|
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果：0表示授权成功，非0表示失败。 |

## 使用说明

通过AbilityContext实例来获取。

**示例：**
```ts
import UIAbility from '@ohos.app.ability.UIAbility'
export default class MainAbility extends UIAbility {
  onWindowStageCreate(windowStage) {
    var permissions = ['com.example.permission']
    var permissionRequestResult;
    this.context.requestPermissionsFromUser(permissions, (err, result) => {
      if (err) {
        console.log('requestPermissionsFromUserError: ' + JSON.stringify(err));
      } else {
        permissionRequestResult = result;
        console.log('permissionRequestResult: ' + JSON.stringify(permissionRequestResult));
      }    
    });
  }
}
```