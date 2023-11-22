# @ohos.application.Want    
Want是对象间信息传递的载体, 可以用于应用组件间的信息传递。 Want的使用场景之一是作为startAbility的参数, 其包含了指定的启动目标, 以及启动时需携带的相关数据, 如bundleName和abilityName字段分别指明目标Ability所在应用Bundle名称以及对应包内的Ability名称。当Ability A需要启动Ability B并传入一些数据时, 可使用Want作为载体将这些数据传递给Ability B。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Want from '@ohos.application.Want';  
    
```  
    
## Want<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want替代。  
 **系统能力:**  SystemCapability.Ability.AbilityBase    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#deviceId替代。<br>表示运行指定Ability的设备ID。如果未设置该字段，则表明指定本设备。 |  
| bundleName<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#bundleName替代。<br> 表示Bundle名称。 |  
| abilityName<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#abilityName替代。<br>表示待启动的Ability名称。如果在Want中该字段同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。AbilityName需要在一个应用的范围内保证唯一。 |  
| uri<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#uri替代。<br>表示Uri描述。如果在Want中指定了Uri，则Want将匹配指定的Uri信息，包括scheme, schemeSpecificPart, authority和path信息。 |  
| type<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#type替代。<br>表示MIME type类型描述，打开文件的类型，主要用于文管打开文件。比如：'text/xml' 、 'image/*'等，MIME定义参考：https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com。 |  
| flags<sup>(deprecated)</sup> | number | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#flags替代。<br>表示处理Want的方式。默认传数字，具体参考：[flags说明](js-apis-ability-wantConstant.md#wantconstantflags)。 |  
| action<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#action替代。<br>表示要执行的通用操作（如：查看、分享、应用详情）。在隐式Want中，您可以定义该字段，配合uri或parameters来表示对数据要执行的操作。具体参考：[action说明](js-apis-ability-wantConstant.md#wantconstantaction)。隐式Want定义及匹配规则参考：[显式Want与隐式Want匹配规则](../../application-models/explicit-implicit-want-mappings.md)。 |  
| parameters<sup>(deprecated)</sup> | object | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#parameters替代。<br>表示WantParams描述，由开发者自行决定传入的键值对。默认会携带以下key值：<br>ohos.aafwk.callerPid 表示拉起方的pid。<br>ohos.aafwk.param.callerToken 表示拉起方的token。<br>ohos.aafwk.param.callerUid 表示[bundleInfo](js-apis-bundle-BundleInfo.md#bundleinfo)中的uid，应用包里应用程序的uid。<br />- component.startup.newRules：表示是否启用新的管控规则。<br />- moduleName：表示拉起方的模块名，该字段的值即使定义成其他字符串，在传递到另一端时会被修改为正确的值。<br />- ohos.dlp.params.sandbox：表示dlp文件才会有。 |  
| entities<sup>(deprecated)</sup> | Array<string> | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.Want/Want#entities替代。<br>表示目标Ability额外的类别信息（如：浏览器、视频播放器）。在隐式Want中是对action字段的补充。在隐式Want中，您可以定义该字段，来过滤匹配Ability类型。具体参考：[entity说明](js-apis-ability-wantConstant.md#wantconstantentity)。 。 |  
