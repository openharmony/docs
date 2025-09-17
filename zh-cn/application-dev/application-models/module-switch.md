# module的切换

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

从[FA模型](ability-terminology.md#fa模型)切换到[Stage模型](ability-terminology.md#stage模型)时，开发者需要将config.json文件module标签下的配置迁移到module.json5配置文件module标签下，具体差异见下列表格。

**表1** FA模型module标签与Stage模型module标签差异对比

| FA标签 | 标签说明 | 对应的Stage标签 | 差异说明 |
| -------- | -------- | -------- | -------- |
| mainAbility | 服务中心图标露出的ability，常驻进程拉起时会启动mainAbility。 | mainElement | 标签名称变更，Stage模型不在使用“.”符号。 |
| package | 标识HAP的包结构名称，在应用内保证唯一性。 | / | Stage模型使用name来保证应用唯一性。**FA模型升级到Stage模型时，Stage模型的name需要和FA模型的package保持一致，否则会导致升级失败。** |
| name | 标识HAP的类名。 | / | FA模型中实际未使能，Stage模型没有与之对应的标签。 |
| supportedModes | 标识应用支持的运行模式，当前只定义了驾驶模式（drive）。 | / | Stage模型已废弃。 |
| distro对象中的moduleName | 标识当前HAP的名称。<br/>**distro对象**中的moduleName。 | name | 标签变更。 |
| distro对象中的moduleType | 标识当前HAP的类型，包括两种类型：entry和feature。另外，如果表示HAR包类型，请设置为har。 | type | 标签变更。 |
| distro对象中的installationFree | 标识当前HAP是否支持免安装特性。 | installationFree | 标签变更。 |
| distro对象中的deliveryWithInstall | 标识当前HAP是否支持随应用安装。 | deliveryWithInstall | 标签变更。 |
| metaData | 标识HAP的元信息。 | metadata | 具体差异见表2。 |
| abilities | 标识当前模块内的所有Ability。 | abilities | 具体差异见表5。 |
| js | 标识基于ArkUI框架开发的JS模块集合，其中的每个元素代表一个JS模块的信息。 | pages | Stage模型在module标签下保留该对象中的pages，window配置与pages的下一级。 |
| shortcuts | 标识应用的快捷方式信息。 | shortcut_config.json文件 | 在开发视图的resources/base/profile下面定义配置文件shortcut_config.json。 |
| reqPermissions | 标识应用运行时向系统申请的权限。 | requestPermissions | 标签名称变更。 |
| colorMode | 标识应用自身的颜色模式。 | / | Stage模型不支持。 |
| distroFilter | 标识应用的分发规则。 | distributionFilter_config.json文件 | Stage模型在开发视图的resources/base/profile下面定义配置文件distributionFilter_config.json。 |
| reqCapabilities | 标识运行应用程序所需的设备能力。 | / | Stage模型不支持。 |
| commonEvents | 公共事件。 | common_event_config.json文件 | Stage模型在开发视图的resources/base/profile下面定义配置文件common_event_config.json。 |
| entryTheme | 此标签标识系统内部主题的关键字。 | / | Stage模型不支持。 |


**表2** FA模型metaData和Stage中metadata对比

| FA标签 | 标签说明 | 对应的Stage模型标签 | 差异对比 |
| -------- | -------- | -------- | -------- |
| parameters | 标识调用Ability时所有调用参数的元信息。 | / | Stage模型不支持。 |
| results | 标识Ability返回值的元信息。 | / | Stage模型不支持。 |
| customizeData | 该标签标识父级组件的自定义元信息，Parameters和results在application不可配。 | metadata | 具体差异见表3。 |

**表3** FA模型metaData的customizeData和Stage中metadata对比

| FA标签 | 标签说明 | 对应的Stage模型标签 | 差异对比 |
| -------- | -------- | -------- | -------- |
| name | 标识数据项的键名称。字符串最大长度为255字节。 | name | 无。 |
| value | 标识数据项的值。字符串最大长度为255字节。 | value | 无。 |
| extra | 标识当前custom数据的格式，取值为表示extra的资源值。 | resource | 标签变更。具体实例见表4。 |


**表4** FA模型metaData和Stage中metadata示例

| FA模型示例 | Stage模型示例 |
| -------- | -------- |
| “meteData”: {<br/>    "customizeDate": [{<br/>        "name": "label",<br/>        "value": "string",<br/>        "extra": "$string:label",<br/>    }]<br/>} | “meteData”: [{<br/>    "name": "label",<br/>    "value": "string",<br/>    "resource": "$string:label",<br/>}] |


**表5** FA模型和Stage中abilities差异对比

| FA模型的abilities对象标签 | 描述 | Stage模型中abilities对象标签 | 差异对比 |
| -------- | -------- | -------- | -------- |
| process | 运行应用程序或Ability的进程名称。 | / | Stage模型不支持abilities中配置，在module标签下配置process。 |
| uri | 标识Ability的统一资源标识符。 | / | Stage模型不支持。 |
| deviceCapability | 标识Ability运行时要求设备具有的能力，采用字符串数组的格式表示。 | / | Stage模型不支持。 |
| metaData | 该标签标识ability的元信息。 | metadata | 具体差异见表2。 |
| type | 标识Ability的类型。 | / | Stage模型不支持。 |
| grantPermission | 指定是否可以向Ability内任何数据授予权限。 | / | abilities内不支持。 |
| readPermission | 标识读取Ability的数据所需的权限。该标签仅适用于data类型的Ability。 | / | abilities内不支持，在extensionAbilities标签中支持。 |
| writePermission | 标识向Ability写数据所需的权限。 | / | abilities内不支持，在extensionAbilities标签中支持。 |
| configChanges | 标识Ability关注的系统配置集合。 | / | Stage模型不支持。 |
| mission | 标识Ability指定的任务栈。 | / | Stage模型不支持。 |
| targetAbility | 标识当前Ability重用的目标Ability。 | / | Stage模型不支持。 |
| multiUserShared | 标识Ability是否支持多用户状态进行共享，该标签仅适用于data类型的Ability。 | / | Stage模型不支持。 |
| supportPipMode | 标识Ability是否支持用户进入PIP模式（用于在页面最上层悬浮小窗口，俗称"画中画"，常见于视频播放等场景）。 | / | Stage模型不支持。 |
| formsEnabled | 标识Ability是否支持卡片（forms）功能。 | / | Stage模型不支持。 |
| forms | 标识服务卡片的属性。该标签仅当formsEnabled为"true"时，才能生效。 | form_config.json文件 | Stage模型在开发视图的resources/base/profile下面定义配置文件form_config.json。 |
| srcLanguage | Ability开发语言的类型。 | / | Stage模型不支持。 |
| srcPath | 该标签标识Ability对应的JS组件代码路径。 | srcEntry | 该标签标识ability所对应的js代码路径。 |
| uriPermission | 标识该Ability有权访问的应用程序数据。 | / | Stage模型不支持。 |
