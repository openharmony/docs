# 拆包工具


拆包工具是OpenHarmony提供的一种调测工具，支持通过命令行方式将HAP、HSP、App等文件解压成文件夹，并且提供Java接口对HAP、HSP、App等文件进行解析。


拆包所用的app_unpacking_tool.jar，可以在本地下载的OpenHarmony的SDK库中找到。


## 约束与限制

拆包工具需要运行在Java8及其以上环境


## 拆包指令说明

### HAP包模式拆包指令

开发者可以使用拆包工具的jar包对应用进行拆包，通过传入拆包选项、文件路径，将HAP包解压出来。

#### 示例

```
java -jar app_unpacking_tool.jar --mode hap --hap-path <path> --out-path <path> [--force true]
```

#### 参数含义及规范

| 指令       | 是否必选项 | 选项          | 描述                                                         |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | 是         | hap           | 拆包类型。                                                   |
| --hap-path | 是         | NA            | HAP包路径。                                                  |
| --rpcid    | 否         | true或者false | 是否单独将rpcid文件从HAP包中提取到指定目录，如果为true，将仅提取rpcid文件，不对HAP包进行拆包。 |
| --out-path | 是         | NA            | 拆包目标文件路径。                                           |
| --force    | 否         | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。  |

### App包模式拆包指令

开发者可以使用拆包工具的jar包对应用进行拆包，通过传入拆包选项、文件路径，将App包解压出来。

#### 示例

```
java -jar app_unpacking_tool.jar --mode app --app-path <path> --out-path <path> [--force true]
```

#### 参数含义及规范

| 指令       | 是否必选项 | 选项          | 描述                                                        |
| ---------- | ---------- |-------------| ----------------------------------------------------------- |
| --mode     | 是         | app         | 拆包类型。                                                  |
| --app-path | 是         | NA          | App包路径。                                                 |
| --out-path | 是         | NA          | 拆包目标文件路径。                                          |
| --force    | 否         | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |

### 从HAP包中获取rpcid文件

开发者可以使用拆包工具的jar包对应用进行拆包，通过传入拆包选项、文件路径，获取应用的rpcid。

#### 示例

```
java -jar app_unpacking_tool.jar --mode hap --rpcid true --hap-path <path> --out-path <path> [--force true]
```

#### 参数含义及规范

| 指令       | 是否必选项 | 选项          | 描述                                                         |
| ---------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode     | 是         | hap           | 拆包类型                                                     |
| --rpcid    | 否         | true或者false | 是否单独将rpcid文件从HAP包中提取到指定目录，如果为true，将仅提取rpcid文件，不对HAP包进行拆包。 |
| --hap-path | 是         | NA            | HAP包路径                                                    |
| --out-path | 是         | NA            | 拆包rpcid目标文件路径                                        |
| --force    | 否         | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。  |

### HSP包模式拆包指令

开发者可以使用拆包工具的jar包对应用进行拆包，通过传入拆包选项、文件路径，将HSP包解压出来。

#### 示例

```
java -jar app_unpacking_tool.jar --mode hsp --hsp-path <path> --out-path <path> [--force true]
```

#### 参数含义及规范

| 指令         | 是否必选项 | 选项          | 描述                                 |
|------------| ---------- | ------------- |------------------------------------|
| --mode     | 是         | hsp           | 拆包类型。                              |
| --hsp-path | 是         | NA            | HSP包路径。                            |
| --out-path | 是         | NA            | 拆包目标文件路径。                          |
| --force    | 否         | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |

### APPQF模式拆包指令

开发者可以使用拆包工具的jar包对应用进行拆包，通过传入拆包选项、文件路径，将APPQF包解压出来。

#### 示例

```
java -jar app_unpacking_tool.jar --mode appqf --appqf-path <path> --out-path <path> [--force true]
```

#### 参数含义及规范

| 指令           | 是否必选项 | 选项          | 描述                                 |
|--------------| ---------- |-------------|------------------------------------|
| --mode       | 是         | appqf       | 拆包类型。                              |
| --appqf-path | 是         | NA          | APPQF包路径。                          |
| --out-path   | 是         | NA          | 拆包目标文件路径。                          |
| --force      | 否         | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |

## 包解析接口

包解析接口仅用于应用市场对打好的HAP、HSP、App等包进行解析，获取其中配置文件等信息。

### 接口目录

| 类名               | 接口原型                                                     | 类型     | 接口详细描述                                                            |
| ------------------ | ------------------------------------------------------------ | -------- |-------------------------------------------------------------------|
| UncompressEntrance | UncompressResult parseApp(String appPath,String parseMode,String deviceType,String hapName) | Java接口 | 接口功能：根据参数解析app包的pack.info信息 输入参数：app包路径，解析参数 返回值：UncompressResult |
| UncompressEntrance | UncompressResult parseApp(InputStream input,String parseMode,String deviceType,String hapName,String outPath) | Java接口 | 接口功能：根据参数解析app包的pack.info信息 输入参数：app文件流，解析参数 返回值：UncompressResult |
| UncompressEntrance | UncompressResult parseHap(String hapPath)                    | Java接口 | 接口功能：根据参数解析app包的json配置文件 输入参数：HAP包路径，解析参数 返回值：UncompressResult    |
| UncompressEntrance | UncompressResult parseHap(InputStream input)                 | Java接口 | 接口功能：根据参数解析app包的json配置文件 输入参数：HAP包文件流，解析参数 返回值：UncompressResult   |

## 拆包工具信息字段

### UncompressResult（Bundle信息）结构体信息

| 字段            | 类型               | 描述                                     | 备注 |
| ----------------| ------------------ |----------------------------------------| ---- |
| result          | boolean            | 标识此次解析是否成功                             | NA   |
| message         | String             | 解析失败时返回失败原因                            | NA   |
| packInfos       | List\<PackInfo>    | bundle中pack.info文件的packages信息          | NA   |
| profileInfos    | List\<profileInfo> | 应用的配置信息                                | NA   |
| profileInfosStr | List\<String>      | 应用的配置信息 | NA   |
| icon            | String             | 返回入口组件的icon路径，如果没有入口组件，则返回第一个组件的icon信息 | NA   |
| label           | String             | 返回入口组件的label，如果没有入口组件，则返回第一个组件的label信息 | NA   |
| packageSize     | long               | 表示App包的大小，单位字节 | NA   |

### PackInfo结构体信息

| 字段                | 类型          | 描述                                    | 备注 |
| ------------------- | ------------- | --------------------------------------- | ---- |
| name                | String        | 包名                                    | NA   |
| moduleName          | String        | HAP名称                                 | NA   |
| moduleType          | String        | module的类型                            | NA   |
| deviceType          | List\<String> | 表示当前HAP包所支持的设备类型           | NA   |
| deliveryWithInstall | boolean       | 标识当前HAP是否在用户主动安装的时候安装 | NA   |

### ProfileInfo结构体信息

| 字段         | 类型                           | 描述                                       | 备注                                                         |
| ------------ | ------------------------------ | ------------------------------------------ | ------------------------------------------------------------ |
| hapName      | String                         | 标识当前解析的HAP包名称                    | NA                                                           |
| appInfo      | AppInfo结构体（见下述AppInfo） | 标识App信息的结构体（见下述AppInfo信息）   | NA                                                           |
| deviceConfig | Map\<String,DeviceConfig>      | 标识设备信息                               | 存储类型为Map\<String,String>，存储设备类型名称及对应设备类型的信息，在stage模型中，这个字段存储在app结构体中 |
| hapInfo      | HapInfo结构体（见下述HapInfo） | 标识HAP包中module信息（见下述HapInfo信息） | NA                                                           |

### AppInfo结构体信息

| 字段                             | 类型      | 描述                                                                            | 备注          |
|--------------------------------|---------|-------------------------------------------------------------------------------|-------------|
| bundleName                     | String  | 标识App的包名称                                                                     | NA          |
| vendor                         | String  | 标识App的供应商信息                                                                   | NA          |
| relatedBundleName              | String  | 标识App相关bundle的包名                                                              | NA          |
| versionName                    | String  | 标识App中的versionName信息                                                          | NA          |
| versionCode                    | String  | 标识App中的versionCode信息                                                          | NA          |
| targetApiVersion               | int     | 标识应用运行需要的API目标版本                                                              | NA          |
| compatibleApiVersion           | int     | 标识应用兼容的API版本                                                                  | NA          |
| appName                        | String  | 标识显示在桌面上的ability的label                                                        | NA          |
| appNameEN                      | String  | 标识显示在桌面上的ability的label                                                        | NA          |
| releaseType                    | String  | 标识应用运行需要的API目标版本的类型                                                           | NA          |
| shellVersionCode               | String  | 标识应用的API版本号                                                          | NA          |
| shellVersionName               | String  | 标识应用的API版本名称                                                          | NA          |
| multiFrameworkBundle           | boolean | 标识应用框架                                                         | NA          |
| debug                          | boolean | 标识应用是否可调试                                                                     | NA          |
| icon                           | String  | 标识应用的图标路径                                                                     | NA          |
| label                          | String  | 标识应用的label                                                                    | NA          |
| description                    | String  | 标识应用的描述信息                                                                     | stage模型新增   |
| minCompatibleVersionCode       | int     | 标识应用能够兼容的最低版本号                                                                | NA          |
| distributedNotificationEnabled | boolean | 标记该应用是否开启分布式通知                                                              | stage模型新增   |
| bundleType                     | String  | 标识bundle的类型，取值：<br/>- app：应用<br/>- atomicService：原子化服务 <br/>- shared：应用间共享库 | NA   |
| compileSdkVersion              | String  | 标识编译该应用时使用的sdk版本                                                              | 仅限API10及以后的应用   |
| compileSdkType                 | String  | 标识编译该应用时使用的sdk类别                                                              | 仅限API10及以后的应用   |
| labels                         | HashMap\<String, String> | 标识多语言应用程序AppJson的标签。 | NA          |
| descriptions                   | HashMap\<String, String> | 标识多语言应用程序AppJson的说明。 | NA          |

### HapInfo结构体信息

| 字段                 | 类型                                          | 描述                               | 备注                                   |
| ---------------------|-----------------------------------------------|------------------------------------| ---------------------------------------|
| appModel             | AppModel枚举值                                | 标识应用的框架模型<br/>- FA：FA模型<br/>- STAGE：Stage模型 | NA |
| packageStr           | String                                        | 标识应用的包信息                    | FA模型特有             |
| name                 | String                                        | 标识当前module的名字                | NA                 |
| description          | String                                        | 标识HAP包的描述信息                 | FA模型特有                       |
| supportedModes       | List\<String>                                 | 标识HAP包的支持的模式               | NA                           |
| abilities            | List\<AbilityInfo>                            | 标识HAP包ability信息                | NA                             |
| defPermissions       | List\<DefPermission>                          | 标识HAP包DefPermission信息          | NA                             |
| definePermissions    | List\<DefinePermission>                       | 标识HAP包DefinePermission信息       | NA                             |
| defPermissionsGroups | List\<DefPermissionsGroups>                   | 标识HAP包DefPermissionsGroups 信息  | NA                             |
| distro               | Distro结构体                                  | 标识HAP包的distro信息               | NA                             |
| reqCapabilities      | List\<String>                                 | 标识HAP包reqCapabilities信息        | NA                           |
| deviceType           | List\<String>                                 | 标识HAP可以运行在哪类设备上         | 对应stage模型中的deviceTypes       |
| metaData             | MetaData结构体（见下述metaData）              | 标识HAP的自定义元信息                | NA           |
| dependencies         | List\<DependencyItem>                         | 标识HAP包DependencyItem信息         | NA                             |
| isJs                 | boolean                                       | 标识该应用是否是js应用              | FA模型特有            |
| reqPermissions       | list\<ReqPermission>                          | 标识应用申请的权限的集合             | 对应stage模型的requestPermissions |
| commonEvents         | CommonEvent结构体（见下述CommonEvent）       | 标识静态事件                         | NA     |
| shortcuts            | list\<Shortcut>                               | 标识应用的shortcuts信息              | NA                  |
| distroFilter         | DistroFilter结构体                            | 标识应用市场按设备形态分发的信息     | NA               |
| srcEntrance          | String                                        | 标识应用对应的入口代码路径           | stage模型新增          |
| process              | String                                        | 标识HAP的进程名                      | stage模型新增       |
| mainElement          | String                  | 标识HAP的入口ability名称或者extension名称 | stage模型新增，FA模型将mainAbility的值赋值给mainElement |
| uiSyntax             | String                                        | 定义该JS Component的语法类型         | stage模型新增       |
| pages                | List\<String>                                 | 列举JS Component中每个页面信息       | stage模型新增       |
| extensionAbilityInfos| List\<ExtensionAbilityInfo>                   | 描述extensionAbility的配置信息       | stage模型新增        |
| moduleAtomicService  | ModuleAtomicService结构体（见下述ModuleAtomicService） | 描述HAP的原子化服务信息          | NA              |
| formInfos            | List\<AbilityFormInfo>                        | 描述卡片的信息                       | NA              |
| descriptions         | HashMap\<String, String>                      | 标识HAP的说明信息                    | NA             |
| compressedSize       | long                                          | 标识HAP包压缩后的大小，单位字节         | NA              |
| originalSize         | long                                          | 标识HAP包的原始大小，单位字节         | NA             |

### AbilityInfo结构体信息

| 字段                | 类型                       | 描述                                              | 备注                        |
|-------------------|--------------------------| ------------------------------------------------- | ------------------------------- |
| name              | String                   | 标识当前ability的逻辑名                           | NA                              |
| description       | String                   | 标识ability的描述                                 | NA                              |
| descriptionRes    | String                   | 标识ability资源的描述                             | NA                              |
| icon              | String                   | 标识ability图标                                   | NA                              |
| iconPath          | String                   | 标识ability图标路径                               | NA                              |
| label             | String                   | 标识ability对用户显示的名称                       | NA                              |
| labelRes          | String                   | 标识ability对用户显示的名称资源                   | NA                              |
| type              | String                   | 标识ability类型                                   | Stage模型下该值直接赋予page类型 |
| formsEnabled      | boolean                  | 标识ability卡片是否使能                           | NA                              |
| formInfo          | FormInfo结构体           | 描述卡片的信息                                    | NA                              |
| uri               | String                   | 标识ability的uri信息                              | FA模型支持                      |
| launchType        | String                   | 标识ability中的launcherType信息                   | NA                              |
| orientation       | String                   | 标识ability中的orientation信息                    | NA                              |
| visible           | boolean                  | 标识ability中的visible信息                        | NA                              |
| grantPermission   | boolean                  | 标识ability中的grantPermission信息                | NA                              |
| readPermission    | String                   | 标识ability中的readPermission信息                 | NA                              |
| writePermission   | String                   | 标识ability中的writePermission信息                | NA                              |
| uriPermissionMode | String                   | 标识ability中的uriPermissionMode信息              | NA                              |
| uriPermissionPath | String                   | 标识ability中的uriPermissionPath信息              | NA                              |
| directLaunch      | boolean                  | 标识ability中的directLaunch信息                   | NA                              |
| mission           | String                   | 标识ability中的mission信息                        | NA                              |
| targetAbility     | String                   | 标识ability中的targetAbility信息                  | NA                              |
| multiUserShared   | boolean                  | 标识ability中的multiUserShared信息                | NA                              |
| supportPipMode    | boolean                  | 标识ability中的supportPipMode信息                 | NA                              |
| srcLanguage       | String                   | 标识ability中的srcLanguage信息                    | NA                              |
| srcPath           | String                   | 标识ability中的srcPath信息                        | NA                              |
| srcEntrance       | String                   | 标识ability中的srcEntrance信息                    | NA                              |
| continuable       | boolean                  | 标识ability中的continuable信息                    | NA                              |
| metaData          | MetaData结构体（见下述MetaData） | 标识ability的自定义元信息                  | NA                             |
| configChanges     | List\<String>            | 标识ability中的configChanges信息                  | NA                              |
| formInfos         | List\<AbilityFormInfo>   | 标识ability中的forms信息                          | NA                              |
| permissions       | List\<String>            | 标识ability中的permissions信息                    | NA                              |
| skills            | List\<SkillInfo>         | 标识ability中的skills信息                         | NA                              |
| backgroundModes   | List\<String>            | 标识ability中的backgroundModes信息                | NA                              |
| labels            | HashMap\<String, String> | 标识多语言下ability对用户显示的名称                | NA                             |
| descriptions      | HashMap\<String, String> | 标识多语言下ability的描述                         | NA                              |

### Distro结构体信息

| 字段                | 类型    | 描述                                    | 备注                                                         |
| ------------------- |---------| --------------------------------------- | ------------------------------------------------------------ |
| moduleName          | String  | 标识当前module的名字                    | 对应Stage模型中module结构体中的moduleName字段                 |
| moduleType          | String  | 标识当前HAP的类型                       | 对应Stage模型中module结构体中的moduleType字段                 |
| deliveryWithInstall | boolean | 标识当前HAP是否在用户主动安装的时候安装 | 对应Stage模型中module结构体中的deliveryWithInstall字段         |
| installationFree    | int     | 标识当前HAP是否支持免安装特性           | 对应Stage模型中module结构体中的installationFree字段，json文件中如果配置了该字段为true，返回1，配置为false，返回0，未配置返回2 |
| virtualMachine      | String  | 标识当前HAP运行的目标虚拟机类型，供云端分发使用，如应用市场和分发中心 | 对应Stage模型中module结构体中的virtualMachine字段 |

### MetaData结构体信息

| 字段           | 类型                 | 描述                             | 备注                      |
| -------------- |----------------------| -------------------------------- | ------------------------- |
| parameters     | List\<MetaDataInfo>  | 标识Metadata的参数信息           | FA模型特有，stage模型废弃  |
| results        | List\<MetaDataInfo>  | 标识Metadata的results信息        | FA模型特有，stage模型废弃  |
| customizeDatas | List\<CustomizeData> | 标识Metadata的customizeDatas信息 | NA                         |

### MetaDataInfo结构体信息

| 字段        | 类型   | 描述                              | 备注                      |
| ----------- | ------ | --------------------------------- | ------------------------- |
| name        | String | 标识MetaDataInfo的name信息        | FA模型特有，stage模型废弃  |
| description | String | 标识MetaDataInfo的description信息 | FA模型特有，stage模型废弃  |
| type        | String | 标识MetaDataInfo的type信息        | FA模型特有，stage模型废弃  |

### CustomizeData结构体信息

| 字段  | 类型   | 描述                         | 备注                    |
| ----- | ------ | ---------------------------- | ----------------------- |
| name  | String | 标识CustomizeData的name信息  | 对应stage模型的metadata |
| value | String | 标识CustomizeData的value信息 | 对应stage模型的metadata |
| extra | String | 标识CustomizeData的extra信息 | 对应stage模型的metadata |

### ReqPermission结构体信息

| 字段      | 类型                               | 描述                                                       | 备注 |
| --------- | ---------------------------------- |------------------------------------------------------------| ---- |
| name      | String                             | 标识ReqPermission的名称信息                                 | NA   |
| reason    | String                             | 当申请的权限为user_grant权限时此字段必填，描述申请权限的原因 | NA   |
| usedScene | UsedScene结构体（见下述UsedScene） | 描述权限使用的场景和时机。场景类型有：ability、调用时机（when），可配置多个ability | NA   |
| reasons   | HashMap\<String, String>           | 当申请的权限为user_grant权限时此字段必填，描述申请权限的原因 | NA    |

### UsedScene结构体信息

| 字段    | 类型          | 描述                                                         | 备注 |
| ------- | ------------- | ------------------------------------------------------------ | ---- |
| ability | List\<String> | 标识需要使用到该权限的元能力（ability），该标签值为数组形式   | NA   |
| when    | String        | 标识使用该权限的时机，值为inuse/always，表示为仅允许前台使用和前后台都可使用 | NA   |

### Shortcut结构体信息

| 字段       | 类型                   | 描述                                                         | 备注 |
| ---------- | ---------------------- | :----------------------------------------------------------- | ---- |
| shortcutId | String                 | 标识ShortCut的Id                                             | NA   |
| label      | String                 | 标识ShortCut的标签信息                                       | NA   |
| icon       | String                 | 标识ShortCut的图标信息                                       | NA   |
| intents    | List\<IntentInfo>      | 标识快捷方式内定义的目标intent信息集合，每个intent可配置两个子标签，targetClass,targetBundle | NA   |
| labels     | HashMap\<String, String> | 标识多语言下ShortCut对用户显示的名称                        | NA   |

### IntentInfo结构体信息

| 字段         | 类型   | 描述             | 备注 |
| ------------ | ------ | ---------------- | ---- |
| targetClass  | String | 快捷方式目标类型 | NA   |
| targetBundle | String | 快捷方式目标包名 | NA   |

### DistroFilter结构体信息

| 字段          | 类型                | 描述                                  | 备注 |
| ------------- | ------------------- | ------------------------------------- | ---- |
| apiVersion    | ApiVersion结构体    | 标识DistroFilter中的apiVersion信息    | NA   |
| screenShape   | ScreenShape结构体   | 标识DistroFilter中的screenShape信息   | NA   |
| screenDensity | ScreenDensity结构体 | 标识DistroFilter中的screenDensity信息 | NA   |
| screenWindow  | ScreenWindow结构体  | 标识DistroFilter中的screenWindow信息  | NA   |
| countryCode   | CountryCode结构体   | 标识DistroFilter中的countryCode信息   | NA   |

### ApiVersion结构体信息

| 字段   | 类型          | 描述                     | 备注 |
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | 标识结构体中的policy信息 | NA   |
| value  | List\<String> | 标识结构体中的value信息  | NA   |

### ScreenShape结构体信息

| 字段   | 类型          | 描述                     | 备注 |
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | 标识结构体中的policy信息 | NA   |
| value  | List\<String> | 标识结构体中的value信息  | NA   |

### ScreenDensity结构体信息

| 字段   | 类型          | 描述                     | 备注 |
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | 标识结构体中的policy信息 | NA   |
| value  | List\<String> | 标识结构体中的value信息  | NA   |

### ScreenWindow结构体信息

| 字段   | 类型          | 描述                     | 备注 |
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | 标识结构体中的policy信息 | NA   |
| value  | List\<String> | 标识结构体中的value信息  | NA   |

### CountryCode结构体信息

| 字段   | 类型          | 描述                     | 备注 |
| ------ | ------------- | ------------------------ | ---- |
| policy | String        | 标识结构体中的policy信息 | NA   |
| value  | List\<String> | 标识结构体中的value信息  | NA   |

### ExtensionAbilityInfo结构体信息

| 字段            | 类型                     | 描述                                                  | 备注                                |
| --------------- | ------------------------ | ----------------------------------------------------- | ----------------------------------- |
| name            | String                   | 标识当前extensionAbility的逻辑名                      | stage模型支持                      |
| srcEntrance     | String                   | 标识extensionAbility所对应的js代码路径                | stage模型支持                      |
| icon            | String                   | 标签标识extensionAbility图标                          | stage模型支持                      |
| label           | String                   | 标识extensionAbility对用户显示的名称                  | stage模型支持                      |
| description     | String                   | 标识extensionAbility的描述                            | stage模型支持                      |
| type            | String                   | 标识extensionAbility的类型：form、workScheduler、inputMethod、service、accessibility、dataShare、fileShare、wallpaper、backup | stage模型支持，目前仅解析了form、staticSubscriber的信息、其他类型（如：workScheduler、inputMethod、service、accessibility、dataShare、fileShare、wallpaper、backup）暂未解析        |
| permissions     | List\<String>            | 标识被其它应用的ability调用时需要申请的权限的集合       | stage模型支持                      |
| readPermission  | String                   | 标识读取ability的数据所需的权限                         | stage模型支持                    |
| writePermission | String                   | 标识向ability写数据所需的权限                           | stage模型支持                   |
| visible         | boolean                  | 标识extensionAbility是否可以被其它应用调用              | stage模型支持                   |
| skills          | List\<SkillInfo>         | 标识extensionAbility能够接收的意图的特征集              | stage模型支持                    |
| metadataInfos   | List\<ModuleMetadataInfo>| 标识extensionAbility能够接收的元数据信息                | stage模型支持                    |
| metadata        | MetaData结构体           | 标识extensionAbility的元信息                            | 将metadata中的信息赋值到CustomizeData中 |
| uri             | String                   | 标识extensionAbility提供的数据uri                       | stage模型支持                           |
| descriptions    | HashMap\<String, String> | 标识多语言下extensionAbility的描述                      | NA                              |
| labels          | HashMap\<String, String> | 标识多语言下extensionAbility对用户显示的名称            | NA                             |

### SkillInfo结构体信息

| 字段     | 类型                | 描述                   | 备注 |
| -------- | ------------------- |----------------------| ---- |
| actions  | List\<String>       | 标识能够接收的意图的action值的集合 | NA   |
| entities | List\<String>       | 标识能够接收的意图的元能力的类别集合   | NA   |

### UriInfo结构体信息

| 字段          | 类型   | 描述                     | 备注 |
| ------------- | ------ |------------------------| ---- |
| schema        | String | 标识ModuleUriInfo的范式信息   | NA   |
| host          | String | 标识ModuleUriInfo的宿主信息   | NA   |
| port          | String | 标识ModuleUriInfo的端口信息   | NA   |
| pathStartWith | String | 标识ModuleUriInfo的路径前缀   | NA   |
| pathRegex     | String | 标识ModuleUriInfo的路径正则信息 | NA   |
| path          | String | 标识ModuleUriInfo的路径信息   | NA   |
| type          | String | 标识ModuleUriInfo的种类     | NA   |

### AbilityFormInfo结构体信息

| 字段                | 类型                     | 描述                                                         | 备注        |
| ------------------- | -------------------------| ------------------------------------------------------------ |-----------|
| name                | String                   | 标识forms的名称                                              | NA        |
| type                | String                   | 标签标识卡片的类型                                           | NA        |
| updateEnabled       | boolean                  | 标识该卡片是否支持定时刷新                                   | NA        |
| scheduledUpdateTime | String                   | 标签标识卡片顶点刷新的时间，采用24小时计数，精确到分钟       | NA        |
| updateDuration      | int                      | 标识卡片定时刷新的更新频率，单位为30分钟，取值为30的倍数值   | NA        |
| supportDimensions   | List\<String>            | 标识卡片外观规格，取值为”1 * 2“，”2 * 2“，”2 * 4“，”4 * 4“   | NA        |
| defaultDimension    | String                   | 标识卡片默认外观规格，取值必须在supportDimensions配置的列表中 | NA        |
| MetaData            | MetaData                 | 标识卡片的自定义信息                                         | NA        |
| description         | String                   | 标识forms的描述                                              | stage模型新增 |
| src                 | String                   | 标签JS卡片对应的UI代码                                       | NA        |
| windowInfo          | ModuleWindowInfo结构体   | 标签能力窗体的窗口。                                       | NA        |
| isDefault           | boolean                  | 标识该卡片是否为默认卡片，每个HAP有且只能有一个默认卡片      | NA        |
| colorMode           | String                   | 标识卡片的色调，取值为auto、dark、light其中之一              | NA        |
| formConfigAbility   | String                   | 标识卡片调整的Ability名称                                    | NA        |
| formVisibleNotify   | String                   | 标识卡片是否被允许使用卡片可见性通知                         | NA        |
| providerAbility     | String                   | 卡片的提供方所在的Ability或者extension名称，1.FA模型：如果卡片配置在service类型的ability中，providerAbility配置为mainAbility 2.FA模型：如果卡片配置在Page类型的Ability中，providerAbility配置为当前Ability 3.FA模型：如果没有配置mainAbility，providerAbility配置为当前HAP包中的优先使用system.home，否则第一个page的Ability 4.stage模型中（follow上述规则），providerAbility配置为mainElement | NA |
| descriptions        | HashMap\<String, String> | 标识多语言下ability的描述                                     | NA     |


### CommonEvent结构体信息

| 字段       | 类型          | 描述                                   | 备注                                             |
| ---------- | ------------- | -------------------------------------- | ------------------------------------------------ |
| name       | String        | 当前静态公共事件对应的类名             | Stage模型从staticSubscriber类型的Extension中获取 |
| permission | String        | 标识实现该静态公共事件需要申请的权限   | Stage模型从staticSubscriber类型的Extension中获取 |
| data       | List\<String> | 当前静态公共时间需要携带的额外数据数组 | Stage模型从staticSubscriber类型的Extension中获取 |
| type       | List\<String> | 配置当前静态公共时间的类别数组         | Stage模型从staticSubscriber类型的Extension中获取 |
| events     | List\<String> | 标识能够接收的意图的event值的集合      | Stage模型从staticSubscriber类型的Extension中获取 |

### DependencyItem结构体信息

| 字段           | 类型   | 描述           | 备注 |
|--------------| ------ |--------------| ---- |
| bundleName   | String | 共享包的bundleName | NA   |
| moduleName   | String | 共享包的moduleName | NA   |
| versionCode  | String | 共享包的版本号      | NA   |

### ModuleAtomicService结构体信息

| 字段         | 类型                   | 描述           | 备注 |
|--------------|------------------------|----------------| ---- |
| preloadItems | list\<PreloadItem>     | 预加载对象     | NA   |

### PreloadItem结构体信息

| 字段         | 类型   | 描述           | 备注 |
|--------------|--------|----------------| ---- |
| moduleName   | String | 预加载的模块名 | NA   |

### DeviceConfig结构体信息

| 字段                           | 类型    | 描述                                     | 备注 |
|--------------------------------|-------- |------------------------------------------| ---- |
| targetReqSdk                   | String  | 标识应用程序DeviceConfig的目标请求Sdk版本  | NA   |
| compatibleReqSdk               | String  | 标识应用程序DeviceConfig的兼容请求Sdk版本  | NA   |
| jointUserid                    | String  | 标识应用程序DeviceConfig的jointUserid      | NA   |
| process                        | String  | 标识应用程序DeviceConfig的进程             | NA   |
| arkFlag                        | String  | 标识应用程序DeviceConfig的arkFlag          | NA   |
| targetArkVersion               | String  | 标识应用程序DeviceConfig的targetArkVersion | NA   |
| compatibleArkVersion           | String  | 标识应用程序DeviceConfig的兼容ArkVersion   | NA   |
| directLaunch                   | boolean | 标识应用程序DeviceConfig的直接启动         | NA   |
| distributedNotificationEnabled | boolean | 标识应用程序AppJson的distributedNotificationEnabled | NA   |

### DefPermission结构体信息

| 字段           | 类型                     | 描述                                      | 备注 |
|----------------|--------------------------|-------------------------------------------| ---- |
| name           | String                   | 标识指示DefPermission的名称               | NA   |
| grantMode      | String                   | 标识DefPermission的grantMode              | NA   |
| group          | String                   | 标识DefPermission的组                     | NA   |
| label          | String                   | 标识DefPermission的标签                   | NA   |
| description    | String                   | 标识DefPermission的描述                   | NA   |
| availableScope | List\<String>            | 标识DefPermission的可用范围               | NA   |
| labels         | HashMap\<String, String> | 标识多语言应用程序DefPermission的标签     | NA   |
| descriptions   | HashMap\<String, String> | 标识多语言应用程序DefPermission的说明     | NA   |

### DefinePermission结构体信息

| 字段                   | 类型                     | 描述                                               | 备注 |
|------------------------|--------------------------|----------------------------------------------------| ---- |
| name                   | String                   | 标识DefinePermission的名称                         | NA   |
| grantMode              | String                   | 标识DefinePermission的grantMode                        | NA   |
| availableLevel         | String                   | 标识DefinePermission的组                               | NA   |
| provisionEnable        | boolean                  | 标识模块定义权限的提供启用                           | NA   |
| distributedSceneEnable | boolean                  | 标识ModuleDefinePermissions的distributedSceneEnable | NA   |
| label                  | String                   | 标识DefinePermission的标签                              | NA   |
| description            | String                   | 标识DefinePermission的描述                              | NA   |
| descriptions           | HashMap\<String, String> | 标识多语言应用程序DefinePermission的说明                | NA   |
| labels                 | HashMap\<String, String> | 标识多语言应用程序DefinePermission的标签                | NA   |

### DefPermissionsGroups结构体信息

| 字段        | 类型    | 描述                         | 备注 |
|-------------|---------|------------------------------| ---- |
| name        | String  | 标识DefPermissionGroup的名称 | NA   |
| order       | String  | 标识DefPermissionGrou的顺序  | NA   |
| icon        | String  | 标识DefPermissionGroup的图标 | NA   |
| label       | String  | 标识DefPermissionGroup的标签 | NA   |
| description | String  | 标识DefPermissionGroup的描述 | NA   |
| request     | boolean | 标识DefPermissionGroup的请求 | NA   |

### FormInfo结构体信息

| 字段          | 类型          | 描述                     | 备注 |
|---------------|---------------|--------------------------| ---- |
| formEntity    | List\<String> | 标识formInfo的formEntity | NA   |
| minHeight     | String        | 标识formInfo的最小高度   | NA   |
| defaultHeight | String        | 标识formInfo的默认高度   | NA   |
| minWidth      | String        | 标识formInfo的最小宽度   | NA   |
| defaultWidth  | String        | 标识formInfo的默认宽度   | NA   |

### ModuleMetadataInfo结构体信息

| 字段     | 类型    | 描述                         | 备注 |
|----------|---------|------------------------------| ---- |
| name     | String  | 标识ModuleMetadataInfo的名称 | NA   |
| value    | String  | 标识ModuleMetadataInfo的值   | NA   |
| resource | String  | 标识ModuleMetadataInfo的资源 | NA   |

### ModuleWindowInfo结构体信息

| 字段            | 类型    | 描述                                | 备注 |
|-----------------|---------|-------------------------------------| ---- |
| designWidth     | int     | 标识模块已用场景的设计宽度           | NA   |
| autoDesignWidth | boolean | 标识ModuleUsedScene的autoDesignWidth | NA   |