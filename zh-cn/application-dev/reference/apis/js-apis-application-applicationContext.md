# ApplicationContext

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


提供开发者应用级别的的上下文，提供注册及取消注册应用内组件生命周期的监听接口。

## 导入模块

```
import Ability from '@ohos.application.Ability';
```

## 使用说明

在使用ApplicationContext的功能前，需要通过context的实例获取。

```js
let applicationContext = this.context.getApplicationContext();
```


## ApplicationContext.registerAbilityLifecycleCallback

registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): **number**;

注册监听应用内生命周期

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| [AbilityLifecycleCallback](js-apis-application-abilityLifecycleCallback.md) | callback | 是   | 回调方法，返回注册监听事件的id |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回的此次注册监听生命周期的id（每次注册该id会自增+1，当超过监听上限数量2^63-1时，返回-1）|

**示例：**

  ```js
  let applicationContext = this.context.getApplicationContext();
  console.log("stage applicationContext: " + JSON.stringify(applicationContext));
  let lifecycleid = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
  console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleid));
  ```

## ApplicationContext.unregisterAbilityLifecycleCallback

unregisterAbilityLifecycleCallback(callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

取消监听应用内生命周期

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | 是   | 注册监听应用内生命周期的id |
| AsyncCallback | callback | 是   | 回调方法                   |

**示例：**

  ```js
  let applicationContext = this.context.getApplicationContext();
  console.log("stage applicationContext: " + JSON.stringify(applicationContext));
  applicationContext.unregisterAbilityLifecycleCallback(lifecycleid, (error, data) => {
      console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
  });
  ```
