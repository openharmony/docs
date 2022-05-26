# ExtensionRunningInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明**
>
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。


Extension运行相关信息。


## 导入模块

```js
import abilitymanager from '@ohos.application.abilityManager';
```

## 使用说明


通过abilityManager中方法获取。

```js
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getExtensionRunningInfos(upperLimit, (err,data) => { 
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```


### 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| extension | ElementName | 是 | 否 | Extension匹配信息。 |
| pid | number | 是 | 否 | 进程ID。 |
| uid | number | 是 | 否 | 用户ID。 |
| processName | string | 是 | 否 | 进程名称。 |
| startTime | number | 是 | 否 | Extension启动时间。 |
| clientPackage | Array&lt;String&gt; | 是 | 否 | 表示当期进程下的所有包名。 |
| type | [bundle.ExtensionAbilityType](#bundleextensionabilitytype) | 是 | 否 | Extension类型。 |


## bundle.ExtensionAbilityType

Extension类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

  | 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| FORM | 0 | 表示带有form类型的扩展信息。 | 
| WORK_SCHEDULER | 1 | 表示带有work&nbsp;scheduler类型的扩展信息。 | 
| INPUT_METHOD | 2 | 表示用输入法类型的扩展信息。 | 
| SERVICE | 3 | 表示带有service类型的扩展信息。 | 
| ACCESSIBILITY | 4 | 表示具有可访问性类型的扩展信息。 | 
| DATA_SHARE | 5 | 表示带有datashare类型的扩展信息。 | 
| FILE_SHARE | 6 | 表示带有fileshare类型的扩展信息。 | 
| STATIC_SUBSCRIBER | 7 | 表示带有静态订阅者类型的扩展信息。 | 
| WALLPAPER | 8 | 表示带有wallpaper类型的扩展信息。 | 
| UNSPECIFIED | 9 | 表示未指定类型信息。 | 
