# ExtensionRunningInfo

- [使用说明](#使用说明)
 - [属性](#属性)
- [bundle.ExtensionAbilityType](#bundleExtensionAbilityType)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 8开始支持。


Extension运行相关信息。


## 使用说明


通过abilityManager中方法获取。


  
```
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getExtensionRunningInfos(upperLimit, (err,data) => { 
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```


### 属性

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| extension | ElementName | 是 | 否 | Extension匹配信息。 | 
| pid | number | 是 | 否 | 进程ID。 | 
| uid | number | 是 | 否 | 用户ID。 | 
| processName | string | 是 | 否 | 进程名称。 | 
| startTime | number | 是 | 否 | Extension启动时间。 | 
| clientPackage | Array&lt;String&gt; | 是 | 否 | 连接客户端包名。 | 
| type | [bundle.ExtensionAbilityType](#bundle-extensionabilitytype) | 是 | 否 | Extension类型。 | 


## bundle.ExtensionAbilityType

Extension类型。

  | 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| FORM | 0 | 表示带有form类型的扩展信息。 | 
| WORK_SCHEDULER | 1 | 表示带有work&nbsp;schedule类型的扩展信息。 | 
| INPUT_METHOD | 2 | 表示用输入法类型的扩展信息。 | 
| SERVICE | 3 | 表示带有service类型的扩展信息。 | 
| ACCESSIBILITY | 4 | 表示具有可访问性类型的扩展信息。 | 
| DATA_SHARE | 5 | 表示带有datashare类型的扩展信息。 | 
| FILE_SHARE | 6 | 表示带有fileshare类型的扩展信息。 | 
| STATIC_SUBSCRIBER | 7 | 表示带有静态订阅者类型的扩展信息。 | 
| WALLPAPER | 8 | 表示带有wallpaper类型的扩展信息。 | 
| UNSPECIFIED | 9 | 表示未指定类型信息。 | 
