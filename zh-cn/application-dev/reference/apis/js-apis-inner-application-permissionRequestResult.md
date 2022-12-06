# PermissionRequestResult

PermissionRequestResult模块提供了权限请求结果的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。| 
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果。0表示授权成功，非0表示失败。  | 

## 使用说明

通过AbilityContext实例来获取。

**示例：**
```ts
import Ability from '@ohos.application.Ability'
export default class MainAbility extends Ability {
  onWindowStageCreate(windowStage) {
    var permissions=['com.example.permission']
    var permissionRequestResult;
    this.context.requestPermissionsFromUser(permissions,(err,result) => {
      if(err){
        console.log('requestPermissionsFromUserError: ' + JSON.stringify(err));
      }else{
        permissionRequestResult=result;
        console.log('permissionRequestResult: ' + JSON.stringify(permissionRequestResult));
      }    
    });
  }
}
```