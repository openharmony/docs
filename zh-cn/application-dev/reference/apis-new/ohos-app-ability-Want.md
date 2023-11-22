# @ohos.app.ability.Want    
Want是对象间信息传递的载体，可以用于应用组件间的信息传递。Want的使用场景之一是作为startAbility的参数，其包含了指定的启动目标，以及启动时需携带的相关数据，例如bundleName和abilityName字段分别指明目标Ability所在应用的包名以及对应包内的Ability名称。当UIAbilityA需要启动UIAbilityB并传入一些数据时，可使用Want作为载体将这些数据传递给UIAbilityB。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Want  
 **系统能力:**  SystemCapability.Ability.AbilityBase    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | false | 表示待启动Ability所在的应用Bundle名称。 |  
| abilityName | string | false | false | 表示待启动Ability名称。如果在Want中该字段同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。AbilityName需要在一个应用的范围内保证唯一。 |  
| deviceId | string | false | false | 表示运行指定Ability的设备ID。如果未设置该字段，则表明指定本设备。 |  
| uri | string | false | false | 表示携带的数据，一般配合type使用，指明待处理的数据类型。如果在Want中指定了uri，则Want将匹配指定的Uri信息，包括`scheme`、`schemeSpecificPart`、`authority`和`path`信息。 |  
| type | string | false | false | 表示MIME type类型描述，打开文件的类型，主要用于文管打开文件。比如：'text/xml' 、 'image/*'等，MIME定义请参见https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com。 |  
| flags | number | false | false | 表示处理Want的方式。默认传数字。<br />例如通过wantConstant.Flags.FLAG_ABILITY_CONTINUATION表示是否以设备间迁移方式启动Ability。 |  
| action | string | false | false | 表示要执行的通用操作（如：查看、分享、应用详情）。在隐式Want中，您可以定义该字段，配合uri或parameters来表示对数据要执行的操作。隐式Want定义及匹配规则请参见[显式Want与隐式Want匹配规则](../../application-models/explicit-implicit-want-mappings.md)。 |  
| parameters | object | false | false | 表示WantParams描述，由开发者自行决定传入的键值对。默认会携带以下key值：<br />- ohos.aafwk.callerPid：表示拉起方的pid。<br />- ohos.aafwk.param.callerBundleName：表示拉起方的Bundle Name。<br />- ohos.aafwk.param.callerToken：表示拉起方的token。<br />- ohos.aafwk.param.callerUid：表示[BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1)中的uid，应用包里应用程序的uid。<br />- component.startup.newRules：表示是否启用新的管控规则。<br />- moduleName：表示拉起方的模块名，该字段的值即使定义成其他字符串，在传递到另一端时会被修改为正确的值。<br />- ohos.dlp.params.sandbox：表示dlp文件才会有。<br />- ability.params.backToOtherMissionStack：表示是否支持跨任务链返回。 |  
| entities | Array<string> | false | false | 表示目标Ability额外的类别信息（如：浏览器、视频播放器）。在隐式Want中是对action字段的补充。在隐式Want中，您可以定义该字段，来过滤匹配Ability类型。 |  
| moduleName | string | false | false | 表示待启动的Ability所属的模块名称。 |  
