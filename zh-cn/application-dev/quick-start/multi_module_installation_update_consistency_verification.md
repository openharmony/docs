# 应用安装与更新一致性校验

随着应用发展越来越复杂，应用也被拆成多个模块进行开发维护，不同的团队负责单个或者多个模块，应用在安装更新过程中会针对不同的字段进行一致性校验和验证，保证应用的安全合法性。本文介绍多模块安装或更新时，签名证书、配置文件的一致性校验规则。


### 签名证书一致性校验

|字段名称|说明|安装一致性校验规则|更新一致性校验规则|
|--|--|--|--|
|appId|应用的appId，组成方式为bundleName_公钥的base64编码。|是|appId和appIdentifier任一相同即可。|
|appIdentifier|应用的唯一标识，是AppGallery Connect创建应用时分配的[APP ID](https://developer.huawei.com/consumer/cn/doc/app/agc-help-createharmonyapp-0000001945392297)，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。|是|appId和appIdentifier任一相同即可。|
|appDistributionType|应用<!--RP1-->[签名证书](../security/app-provision-structure.md)<!--RP1End-->中的app-distribution-type，标识应用的分发类型。|是|更新不同版本时无校验，同版本有校验。|
|appProvisionType|应用签名[证书类型](https://developer.huawei.com/consumer/cn/doc/app/agc-help-add-debugprofile-0000001914423102)，分为debug和release。debug为本地调试使用，release为上架应用市场使用。|是|更新不同版本时无校验，同版本有校验。|
|apl|表示应用程序的[APL等级](../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)，系统定义的apl包括：normal、system_basic和system_core。|是|更新不同版本时无校验，同版本有校验。|


### 配置文件一致性校验

|字段名称|说明|安装一致性校验规则|更新一致性校验规则|
|--|--|--|--|
|bundleName|标识应用的Bundle名称，用于标识应用的唯一性。该字段来源[app.json5配置文件](./app-configuration-file.md)中bundleName字段。|是|是|
|vendor|标识对应用开发厂商的描述。多个模块安装更新时，校验entry模块的一致性。该字段来源[app.json5配置文件](./app-configuration-file.md)中vendor字段。|否|否|
|versionCode|标识应用的版本号，取值为小于2^31次方的正整数。此数字仅用于确定某个版本是否比另一个版本更新，数值越大表示版本越高。开发者可以将该值设置为任何正整数，但是必须确保应用的新版本都使用比旧版本更大的值。该字段来源[app.json5配置文件](./app-configuration-file.md)中versionCode字段。|是|是|
|versionName|标识向用户展示的应用版本号，以entry为主，不影响应用运行。该字段来源[app.json5配置文件](./app-configuration-file.md)。|否|否|
|minCompatibleVersionCode|标识应用能够兼容的最低历史版本号，多模块安装更新时，保留最大值。该字段来源[app.json5配置文件](./app-configuration-file.md)中versionName字段。|否|否|
|targetAPIVersion|标识应用运行需要的API目标版本，多模块安装更新时，保留最大值。该字段来源[app.json5配置文件](./app-configuration-file.md)中targetAPIVersion字段。|否|否|
|apiReleaseType|标识编译HAP的SDK发布类型。增量安装时，未区分HAP和HSP，均未拦截。该字段来源[app.json5配置文件](./app-configuration-file.md)中apiReleaseType字段。|否|是|
|compatibleVersion|标识应用运行需要最小的SDK版本，多模块安装更新时，保留最大值。|否|否|
|<!--DelRow--> singleton|标识应用是否安装在共有用户下。|不涉及|是|
|<!--DelRow--> appType|标识应用的类型，分为SYSTEM_APP、THIRD_SYSTEM_APP、THIRD_PARTY_APP。|是|是|
|<!--DelRow--> isStage|标识应用是否为Stage模型。|是，FA和stage同版本不允许变更|是|
|targetBundleName|标识当前包所指定的目标应用，配置该字段的应用为具有overlay特征的应用。该字段来源[app.json5配置文件](./app-configuration-file.md)中targetBundleName字段。|是|是|
|targetPriority|标识当前应用的优先级。该字段来源[app.json5配置文件](./app-configuration-file.md)中targetPriority字段。|是|是|
|bundleType|标识应用的类型。该字段来源[app.json5配置文件](./app-configuration-file.md)中bundleType字段。|是|是|
|installationFree|标识是否支持免安装。该字段来源[module.json5配置文件](./module-configuration-file.md)中installationFree字段。|是|是|
|debug|标识是否可调式（IDE断点调测）。该字段来源[app.json5配置文件](./app-configuration-file.md)中debug字段。|是|否|
|moduleType|标识应用包的类型，应用中单个模块只允许配置一个。该字段来源[module.json5配置文件](./module-configuration-file.md)中type字段。|是，同版本entry类型的moduleName不能修改，AGC拦截|是|
|nativeLibraryPath|如果不是所有的module都更新，需要HAP中包含SO的文件夹路径一致（都存在SO时），模拟器还是会强校验SO类型。|否|否|
