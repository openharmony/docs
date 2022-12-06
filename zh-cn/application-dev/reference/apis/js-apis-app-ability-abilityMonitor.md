# AbilityMonitor

AbilityMonitor模块提供匹配满足指定条件的受监视能力对象的方法的能力，最近匹配的ability对象将保存在AbilityMonitor对象中。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```ts
import AbilityMonitor from '@ohos.app.ability.abilityDelegatorRegistry'
```

## 使用说明

通过abilityDelegator中的addAbilityMonitor来设置。

```js
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry'
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
try {
    abilityDelegator.addAbilityMonitor(monitor, (err : any) => {
        console.info("addAbilityMonitor callback");
    });
} catch (paramError) {
  console.log('error.code: ' + JSON.stringify(paramError.code) +
    ' error.message: ' + JSON.stringify(paramError.message));
}
```

## AbilityMonitor

Ability监听器

系统能力：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                                                         | 类型     | 可读 | 可写 | 说明                                                         |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | 是   | 是   | 当前AbilityMonitor绑定的ability名称 |
| moduleName?                                                  | string   | 是   | 是   | 当前AbilityMonitor绑定的module名称 |
| onAbilityCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability被启动初始化时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onAbilityForeground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability状态变成前台时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onAbilityBackground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability状态变成后台时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onAbilityDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/> |
| onWindowStageCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被创建时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/> |
| onWindowStageRestore?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被重载时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/> |
| onWindowStageDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/> |


