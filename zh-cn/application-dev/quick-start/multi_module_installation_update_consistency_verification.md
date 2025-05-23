# 多模块应用安装更新一致性校验

## 背景

随着应用发展越来越复杂，应用也被拆成多个模块进行开发维护，不同的团队负责单个或者多个模块，应用在安装更新过程中会针对不同的字段进行一致性校验和验证，保证应用的安全合法性。

## 现状

### 多模块安装或更新时签名证书一致性

|字段名称|说明|安装一致性校验|更新一致性校验|
|--|--|--|--|
|appId|应用的appId,组成方式为bundleName_公钥的base64编码。|是|appId和appIdentifier有一个相同即可。|
|appIdentifier|应用签名证书中的app-identifier，云侧申请应用时生成的唯一编号，应用在申请证书时会写入到证书文件中。|是|appId和appIdentifier有一个相同即可。|
|appDistributionType|应用签名证书中的app-distribution-type，标识应用的分发类型。分为： <li>app_gallery：应用市场分发的应用。 <li> enterprise：企业应用，可以安装到个人设备上。<li> enterprise_mdm：企业MDM应用，只能安装在企业设备上。需要设备管理特权，比如远程锁定，安装普通企业应用等。 <li>enterprise_normal：普通企业应用，只能通过企业MDM应用安装在企业设备上。无需设备管理特权。<li>os_integration：系统预置应用。<li>crowdtesting：众包测试应用。<li>internaltesting：应用市场内测的应用。<li>none：其他。|是|更新时无校验，同版本有校验。|
|appProvisionType|应用签名证书类型，分为debug和release。debug为本地调试使用，release为上架应用市场使用。|是|更新时无校验，同版本有校验。|
|apl|表示应用程序的[APL等级](../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)，系统预定义的apl包括：normal、system_basic和system_core。|是|更新时无校验，同版本有校验。|


### 多模块配置文件字段一致性校验

|字段名称|说明|多模块安装一致性校验|多模块更新一致性校验|备注|
|--|--|--|--|--|
|bundleName|标识应用的Bundle名称，用于标识应用的唯一性。|是|是|NA|
|vendor|标识对应用开发厂商的描述。|否|否|以entry为主|
|versionCode|标识应用的版本号，取值为小于2^31次方的正整数。此数字仅用于确定某个版本是否比另一个版本更新，数值越大表示版本越高。开发者可以将该值设置为任何正整数，但是必须确保应用的新版本都使用比旧版本更大的值。|是|是|应用间HSP不需要校验版本|
|versionName|标识向用户展示的应用版本号。|否|否|以entry为主，不影响应用运行。|
|minCompatibleVersionCode|标识应用能够兼容的最低历史版本号。|否|否|多模块时，保留最大值|
|targetAPIVersion|标识应用运行需要的API目标版本。|否|否|多模块时，保留最大值|
|apiReleaseType|标识编译HAP的SDK发布类型。|否|是|增量安装时，未区分HAP和HSP均未拦截|
|compatibleVersion|标识应用运行建通的最小版本SDK版本|否|否|多模块时，保留最大值|
|singleton|标识应用是否安装在0用户下。|不涉及|是|NA|
|appType|标识应用的类型是否一致，签名证书app-feature.|是||是|集成态的HSP重新签名后和主应用一致。|
|isStage|标识应用是否未Stage模型。|是，FA和stage同版本不允许变更，AGC要拦截|是|NA|
|targetBundleName|overlay指定需要overlay的bundleName|是，AGC需要拦截|是|NA|
|targetPriority|该overlay包的优先级。|是，AGC需要拦截|是|NA|
|bundleType|标识应用的类型|是，AGC需要拦截|是|NA|
|installationFree|标识是否免安装|是，AGC需要拦截|是|NA|
|debug|标识是否未调式应用（IDE断点调测）|是|否|校验规则|
|moduleType|标识HAP的类型，一个应用只允许有一个。|是，同版本entry类型的moduleName不能修改，AGC拦截|是|NA|
|nativeLibraryPath|如果不是所有的module都更新，需要HAP中包含SO的文件夹路径一致（都存在SO时）|否|否|模拟器还是会强校验so类型|
