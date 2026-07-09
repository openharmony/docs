# 打包工具
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @jsjzju-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

打包工具用于在程序编译完成后，对编译出的文件等进行打包，以供安装发布。开发者可以使用DevEco Studio进行打包，也可使用打包工具的JAR包进行打包，JAR包通常存放在SDK路径下的toolchains目录中。

打包工具支持生成：Ability类型的模块包（HAP）、动态共享包（HSP）、应用程序包（App）、快速修复模块包（HQF）、快速修复包（APPQF）。

打包指令中的文件来源于[DevEco Studio编译构建产物](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-compile-build)，文件路径查看操作如下。<br/>
1. 在DevEco Studio工程根目录下的/hvigor/hvigor-config.json5文件中，修改"logging"下的"level"字段为"debug"。<br/>
2. 在DevEco Studio菜单栏，依次选择"构建 -> 清理项目"。<br/>
3. 在DevEco Studio菜单栏，依次选择"构建 -> 构建APP(s)"。<br/>
4. 在DevEco Studio底部"构建"窗口，搜索"app_packing_tool.jar"，确认打包参数中文件的路径。<br/>

打包工具会对module.json文件属性进行合法性校验。module.json文件是编译构建产物，其属性值在编译构建时自动生成，与配置文件中配置项对应关系如下。

**表1** module.json与配置文件属性的对照表

| module.json属性          | 含义          | [module.json5](../quick-start/module-configuration-file.md#配置文件标签)配置项         | [app.json5](../quick-start/app-configuration-file.md#配置文件标签)配置项            | [工程级build-profile.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app)配置项  |
| ------------------------ | ------------------------ | ------------------------ | -------------------------- | --------------------------       |
| bundleName               | 应用的Bundle名称。        | -                        | bundleName                 | -                                |
| bundleType               | 应用的Bundle类型。        | -                        | bundleType                 | -                                |
| versionCode              | 应用的版本号。            | -                        | versionCode                | -                                |
| debug                    | 应用是否可调试。          | -                        | debug                      | -                                |
| module/name              | 当前Module的名称。        | module/name              | -                          | -                                |
| minCompatibleVersionCode | 应用能够兼容的最低历史版本号。| -                        | minCompatibleVersionCode   | -                                |
| minAPIVersion            | 应用运行所需的最小API版本。| -                        | minAPIVersion              | compatibleSdkVersion             |
| targetAPIVersion         | 应用运行需要的API目标版本。 | -                        | targetAPIVersion           | targetSdkVersion/compileSdkVersion  <br/>说明：targetSdkVersion存在时，targetAPIVersion由targetSdkVersion决定；<br/>否则，targetAPIVersion由compileSdkVersion决定。               |
| querySchemes             | 允许应用进行跳转查询的URL schemes。| querySchemes              | -                          | -                                |
| generateBuildHash        | 标识当前HAP或HSP是否由打包工具生成哈希值。| generateBuildHash    | generateBuildHash          | -                                |
| buildVersion               | 应用的构建版本号。        | -                        | buildVersion                 | -                                |

## 约束与限制

- 打包工具需要运行在Java8及其以上环境。
- 打包指令中参数和参数值需成对出现。例如，HAP打包指令中--resources-path \<path>，其中--resources-path为指令参数，path为参数值，两者需要同时出现。
- 不建议使用JDK 20版本运行打包工具。JDK 20对zip64扩展数据字段的校验规则存在已知缺陷，当zip包（如HAP、HSP或任何zip64文件）的目录中zip64扩展字段长度异常时，解析会抛出`Invalid CEN header (invalid zip64 extra data field size)`异常。建议使用JDK 17（LTS）或JDK 21（LTS）等长期支持版本。若必须使用JDK 20，可在JVM启动参数中添加`-Djdk.util.zip.disableZip64ExtraFieldValidation=true`规避此问题。

## HAP打包指令

开发者可以使用打包工具的JAR包对模块进行打包，通过传入打包选项、文件路径，生成所需的HAP包。

**HAP打包时合法性校验**
- 从API version 21开始，在打包entry类型的HAP时，如果module.json文件中querySchemes配置了超过50个URL scheme，则要求minAPIVersion大于等于21。

**打包HAP时的压缩规则：**
- 应用配置compressNativeLibs为true时，会按照--compress-level设置的压缩等级对--lib-path指定目录下的文件进行压缩。
- 出于运行时性能等考量，--lib-path指定目录外的文件不会进行压缩。

示例：
- Stage模型示例：


    ```bash
    java -jar app_packing_tool.jar --mode hap --json-path <path> [--resources-path <path>] [--ets-path <path>] [--index-path <path>] [--pack-info-path <path>] [--lib-path <path>] --out-path <path> [--force true] [--compress-level 5] [--pkg-context-path <path>] [--hnp-path <path>] [--pkg-sdk-info-path <path>] [--skills-path <path>]
    ```

- FA模型示例：


    ```bash
    java -jar app_packing_tool.jar --mode hap --json-path <path> [--maple-so-path <path>] [--profile-path <path>] [--maple-so-dir <path>] [--dex-path <path>] [--lib-path <path>] [--resources-path <path>] [--index-path <path>] --out-path <path> [--force true] [--compress-level 5]
    ```

**表2** HAP打包指令参数说明

| 指令             | 是否必选项 | 选项          | 描述                                                         | 备注            |
| ---------------- | ---------- | ------------- | ------------------------------------------------------------ | --------------- |
| --mode           | 是         | hap           | 打包类型。                                                   | NA              |
| --json-path      | 是         | NA            | .json文件路径。FA模型文件名必须为config.json；Stage模型文件名必须为module.json。 | NA              |
| --profile-path   | 否         | NA            | CAPABILITY.profile文件路径。                                 | NA              |
| --maple-so-path  | 否         | NA            | maple so文件输入路径，so文件路径，文件名必须以.so为后缀。如果是多个so需要用“，”分隔。 | NA              |
| --maple-so-dir   | 否         | NA            | maple so目录输入路径。                                       | NA              |
| --dex-path       | 否         | NA            | dex文件路径，文件名必须以.dex为后缀。如果是多个dex需要用“，”分隔。 <br/>dex文件路径也可以为目录。 | NA              |
| --lib-path       | 否         | NA            | lib库文件路径。从API version 22开始，--exist-src-path配置有效且--lib-path-retain配置为true时，对libs目录做增量打包，直接拷贝--exist-src-path配置的源HAP包中的libs目录，不再打包--lib-path配置的libs目录，--lib-path参数无效。| NA              |
| --resources-path | 否         | NA            | resources资源包路径。                                        | NA              |
| --index-path     | 否         | NA            | .index文件路径，文件名必须为resources.index。                | NA              |
| --pack-info-path | 否         | NA            | pack.info文件路径，文件名必须为pack.info。                   | NA              |
| --rpcid-path     | 否         | NA            | rpcid.sc文件路径，文件名必须为rpcid.sc。                     | NA              |
| --js-path        | 否         | NA            | 存放js文件目录路径。                                         | 仅Stage模型生效。 |
| --ets-path       | 否         | NA            | 存放ets文件目录路径。                                        | 仅Stage模型生效。 |
| --out-path       | 是         | NA            | 目标文件路径，文件名必须以.hap为后缀。                       | NA              |
| --force          | 否         | boolean       | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。 | NA              |
| --an-path        | 否         | NA            | 存放[an文件](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs-V5/faqs-arkts-52-V5)的路径。| 仅stage模型生效。 |
| --ap-path        | 否         | NA            | 存放[ap文件](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs-V5/faqs-arkts-52-V5)的路径。| 仅stage模型生效。 |
| --dir-list       | 否         | NA            | 可指定目标文件夹列表，将其打入HAP包内。                      | NA              |
| --compress-level | 否         | number        | lib库下文件压缩等级，默认值1。可选等级1-9。在应用配置compressNativeLibs参数为true的情况下生效，数值越大压缩率越高、压缩速度越慢。 | NA  |
| --pkg-context-path      | 否         | NA            | 可指定语境信息表文件路径，文件名必须为pkgContextInfo.json。当app.json5配置文件中bundleType取值不是appPlugin，且module.json5配置文件中requestPermissions取值包含"ohos.permission.kernel.SUPPORT_PLUGIN"时，该参数必填。 | 仅Stage模型生效。              |
| --hnp-path | 否 | NA | 指定native软件包文件路径，将native软件包打入HAP包内。 | NA |
| --exist-src-path | 否 | NA | 指定增量打包时的源HAP包路径，该路径必须指向一个已存在的、有效的.hap文件。当--lib-path-retain配置为true时，打包工具会直接拷贝源HAP包中的libs目录，不再打包--lib-path指定的libs目录，该特性称为增量打包。当--lib-path-retain配置为false时，正常打包--lib-path指定的libs目录，该参数无效。当libs目录中so文件压缩耗时比较久时，使用增量打包可以提升打包速度。<br/>从API version 22开始支持该参数。 | 仅Stage模型生效。|
| --lib-path-retain | 否 | boolean | 是否对libs目录做增量打包。为true时表示对libs目录做增量打包，直接拷贝--exist-src-path指向的源HAP中的libs目录，不再打包--lib-path指定的libs目录；为false时表示不做增量打包，打包--lib-path指向的目录。默认值为false。此参数必须与--exist-src-path配套使用，单独设置不生效。<br/>从API version 22开始支持该参数。 | 仅Stage模型生效。|
| --pkg-sdk-info-path | 否         | NA            | pkgSdkInfo.json（构建产物中依赖的HAR的基本信息，包括模块名和版本）文件路径，文件名必须为pkgSdkInfo.json。<br/>从API version 23开始支持该参数。     | 仅Stage模型生效。  |
| --skills-path | 否         | NA            | 存放skill目录的路径。打包时，根据module.json5文件中的skillProfiles配置项，将--skills-path目录下对应的skill内容打入HAP包内。<br/>当bundleType为app或atomicService时，允许传入该参数。当bundleType为shared、appService或appPlugin时，不允许传入该参数，否则打包失败。<br/>从API版本26.0.0开始支持该参数。 | 仅Stage模型生效。  |

## HSP打包指令

HSP包实现了多个HAP对文件的共享，开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的HSP包。

**打包HSP时的压缩规则：**
- 应用配置compressNativeLibs为true时，会按照--compress-level设置的压缩等级对--lib-path指定目录下的文件进行压缩。
- 出于运行时性能等考量，--lib-path指定目录外的文件不会进行压缩。

示例：
```bash
java -jar app_packing_tool.jar --mode hsp --json-path <path> [--resources-path <path>] [--ets-path <path>] [--index-path <path>] [--pack-info-path <path>] [--lib-path <path>] --out-path <path> [--force true] [--compress-level 5] [--pkg-context-path <path>] [--pkg-sdk-info-path <path>] [--skills-path <path>]
```

**表3** HSP打包指令参数说明

| 指令             | 是否必选项 | 选项          | 描述                                                         |
| ---------------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode           | 是         | hsp           | 打包类型。                                                   |
| --json-path      | 是         | NA            | .json文件路径，文件名必须为module.json。                     |
| --profile-path   | 否         | NA            | CAPABILITY.profile文件路径。                                 |
| --dex-path       | 否         | NA            | 1. dex文件路径，文件名必须以.dex为后缀。如果是多个dex需要用“，”分隔。<br/>2. dex文件路径也可以为目录。 |
| --lib-path       | 否         | NA            | lib库文件路径。从API version 22开始，--exist-src-path配置有效且--lib-path-retain配置为true时，对libs目录做增量打包，直接拷贝--exist-src-path配置的源HSP包中的libs目录，不再打包--lib-path配置的libs目录，--lib-path参数无效。|
| --resources-path | 否         | NA            | resources资源包路径。                                        |
| --index-path     | 否         | NA            | .index文件路径，文件名必须为resources.index。                |
| --pack-info-path | 否         | NA            | pack.info文件路径，文件名必须为pack.info。                   |
| --js-path        | 否         | NA            | 存放js文件目录路径。                                         |
| --ets-path       | 否         | NA            | 存放ets文件目录路径。                                        |
| --out-path       | 是         | NA            | 目标文件路径，文件名必须以.hsp为后缀。                       |
| --force          | 否         | boolean       | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。 |
| --compress-level | 否         | number        | lib库下文件压缩等级，默认值1，可选等级1-9。在应用配置compressNativeLibs参数为true的情况下生效，数值越大压缩率越高、压缩速度越慢。 |
| --pkg-context-path      | 否         | NA            | 可指定语境信息表文件路径，文件名必须为pkgContextInfo.json。当app.json5配置文件中bundleType取值不是appPlugin，且module.json5配置文件中requestPermissions取值包含"ohos.permission.kernel.SUPPORT_PLUGIN"时，该参数必填。 |
| --exist-src-path | 否 | NA | 指定增量打包时的源HSP包路径，该路径必须指向一个已存在的、有效的.hsp文件。当--lib-path-retain配置为true时，打包工具会直接拷贝源HSP包中的libs目录，不再打包--lib-path指定的libs目录，该特性称为增量打包。当--lib-path-retain配置为false时，正常打包--lib-path指定的libs目录，该参数无效。当libs目录中so文件压缩耗时比较久时，使用增量打包可以提升打包速度。<br/>从API version 22开始支持该参数。 |
| --lib-path-retain | 否 | boolean | 是否对libs目录做增量打包。为true时表示对libs目录做增量打包，直接拷贝--exist-src-path指向的源HSP中的libs目录，不再打包--lib-path指定的libs目录；为false时表示不做增量打包，打包--lib-path指向的目录。默认值为false。此参数必须与--exist-src-path配套使用，单独设置不生效。<br/>从API version 22开始支持该参数。|
| --pkg-sdk-info-path | 否         | NA            | pkgSdkInfo.json（构建产物中依赖的HAR的基本信息，包括模块名和版本）文件路径，文件名必须为pkgSdkInfo.json。<br/>从API version 23开始支持该参数。     |
| --skills-path | 否         | NA            | 存放skill目录的路径。打包时，根据module.json5文件中的skillProfiles配置项，将--skills-path目录下对应的skill内容打入HSP包内。<br/>当bundleType为app、atomicService或skill时，允许传入该参数。当bundleType为shared、appService或appPlugin时，不允许传入该参数，否则打包失败。<br/>从API版本26.0.0开始支持该参数。 |

## App打包指令

开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的App包。App包用于上架应用市场。

**表4** App打包合法性校验规则

| HAP或HSP的module.json中的被校验字段  | 校验规则                           |
| --------------------------------- | --------------------------------- |
| module下的name字段                | 要求所有HAP或HSP的name字段值均不相同。      |
| bundleName                       | 要求所有HAP或HSP的bundleName字段值均保持一致。  |
| bundleType                       | 要求所有HAP或HSP的bundleType字段值均保持一致。  |
| versionCode                      | 要求所有HAP或HSP的versionCode字段值均保持一致。 |
| debug                            | 从API version 20开始，要求所有HAP的debug字段值均保持一致，如果HAP的debug字段值为false，HSP的debug字段值也必须为false。如果HAP的debug字段值为true，对HSP的debug字段值无要求。<br/>对于API version 19及之前版本，要求所有HAP或HSP的debug字段值均保持一致。    |
| minAPIVersion                    | 从API version 20开始，要求所有HAP的minAPIVersion字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 19及之前版本，要求所有HAP或HSP的minAPIVersion字段值均保持一致。    |
| minCompatibleVersionCode         | 从API version 16开始，要求所有HAP的minCompatibleVersionCode字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 15及之前版本，要求所有HAP或HSP的minCompatibleVersionCode字段值均保持一致。    |
| targetAPIVersion                 | 从API version 16开始，要求所有HAP的targetAPIVersion字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 15及之前版本，要求所有HAP或HSP的targetAPIVersion字段值均保持一致。    |
| versionName                | 从API version 12开始，不再对versionName校验。      |
| buildVersion                | 从API version 23，要求所有HAP或HSP的buildVersion字段值均保持一致。      |

> **说明：** 
>
> - module.json文件为DevEco Studio编译构建产物，其中的字段与配置文件的对应关系，请参考[表1 module.json与配置文件属性的对照表](packing-tool.md)。

**打包APP时的压缩规则：** 打包APP时，对release模式的HAP、HSP包会进行压缩，对debug模式的HAP、HSP包不会压缩。

> **说明：** 
> 
> 若HAP或HSP中已压缩的so文件，在打包APP时再次压缩，将不会有明显体积缩减。

示例：

```bash
java -jar app_packing_tool.jar --mode app [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--pack-res-path <path>] [--force true] [--encrypt-path <path>] [--pac-json-path <path>] [--atomic-service-entry-size-limit <size>] [--atomic-service-non-entry-size-limit <size>] [--replace-pack-info false]
```

**表5** App打包指令参数说明
<!--Table: 25%; 10%; 10%; 55%-->
| 指令                 | 是否必选项 | 选项          | 描述                                                           |
|--------------------|-------|-------------|--------------------------------------------------------------|
| --mode             | 是     | app         | 多个HAP需满足HAP的合法性校验。                                           |
| --hap-path         | 否     | NA          | HAP包文件路径，文件名必须以.hap为后缀。如果是多个HAP包需要用“,”分隔。<br/>HAP包文件路径也可以是目录。 |
| --hsp-path         | 否     | NA          | HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要用“,”分隔。<br/>HSP包文件路径也可以是目录。 |
| --pack-info-path   | 是     | NA          | 文件名必须为pack.info。                                             |
| --out-path         | 是     | NA          | 目标文件路径，文件名必须以.app为后缀。                                        |
| --signature-path   | 否     | NA          | 签名路径。                                                        |
| --certificate-path | 否     | NA          | 证书路径。                                                        |
| --pack-res-path    | 否     | NA          | pack.res快照文件路径。                                 |
| --force            | 否     | boolean     | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。|
| --encrypt-path     | 否     | NA          | 文件名必须为encrypt.json 。                           |
| --pac-json-path     | 否     | NA          | <!--RP1-->pac.json<!--RP1End-->文件路径，文件名必须为pac.json。<br/>从API version 20开始支持该参数。|
| --atomic-service-entry-size-limit      | 否         | NA            | 设置元服务entry包大小（包含其依赖包的大小）限制，仅Stage模型应用且bundleType为atomicService时生效。取值范围为[0,4194304]的整数，取值为0表示不限制大小，单位KB。不设置该参数时默认值为2048KB。如果entry包是release模式（module.json5文件中type字段值为entry，且app.json5中debug字段的值为false），该限制作用于打包app时压缩后的entry包大小（包含其依赖包的大小）。                       |
| --atomic-service-non-entry-size-limit  | 否         | NA            | 设置元服务非entry包大小（包含其依赖包的大小）限制，仅Stage模型应用且bundleType为atomicService时生效。取值范围为[0,4194304]的整数，取值为0表示不限制大小，单位KB。不设置该参数时默认值为2048KB。如果非entry包是release模式（module.json5文件中type字段值不是entry，且app.json5中debug字段的值为false），该限制作用于打包app时压缩后的非entry包大小（包含其依赖包的大小）。                     |
| --replace-pack-info    | 否     | boolean          | 打包APP时，是否使用由--pack-info-path参数指定的pack.info文件替换HAP、HSP包中的pack.info文件。如果为true表示替换，false表示不替换，默认值为true。<br/>从API version 22开始支持该参数。 |
| --stat-duplicate       | 否     | boolean       | 打包完成后，是否扫描重复so文件，该参数可用于识别重复so，以减小包大小。取值为true时，执行扫描，扫描完成会在--out-path参数指定的输出文件所在目录下生成`scan_report`目录，其中包含文件名为`scan_result`的[重复so文件扫描报告](#扫描重复so文件)，并在告警中打印`scan_report`目录路径。取值为false时，不执行扫描。默认值为false。<br/>从API version 23开始支持该参数。 |
| --deduplicate-so       | 否     | boolean       | 用于在打包时对so文件进行去重，从而有效减小App的包体积。<br/>默认值：`false`<br/>取值说明：<br/>`true`：执行so文件去重。去重完成后，将在`--out-path`指定的目录下生成去重报告[so_dedup_report.json](#so去重报告)，并在日志中打印去重结果。<br/>`false`：不执行so文件去重。<br/>去重策略：<br/>- 当App包中不同模块间存在相同的so文件，且这些so会解压到应用根目录时（即`module.json5`中`compressNativeLibs`和`extractNativeLibs`不同时为`false`，且`libIsolation`为`false`）。<br/>- 打包工具会根据`deviceTypes`、`deliveryWithInstall`、`distributionFilter`、`requiredDeviceFeatures`等配置进行去重，确保去重后应用在各个可安装设备上的功能保持不变。<br/>**说明**：<br/>- 若应用代码中有直接从原始安装包中读取so文件的操作，开启去重后应用行为将发生变化。此时请勿开启该功能，或修改代码逻辑改为读取解压后的so文件后再开启。<br/>- 开发者若在打包时开启了so去重功能，建议仔细检查去重结果，并在上架前充分验证去重后App包的功能完整性。<br/>从API版本26.0.0开始支持该参数。|

## 多工程打包指令

多工程打包适用于多个团队开发同一个应用，但不方便共享代码的情况。开发者通过传入已经打好的HAP、HSP和App包，将多个包打成一个最终的App包，并上架应用市场。

**表6** 多工程打包合法性校验规则

| HAP或HSP的module.json中的被校验字段  | 校验规则                           |
| --------------------------------- | --------------------------------- |
| module下的name字段                | 要求所有HAP或HSP的name字段值均不相同。      |
| bundleName                       | 要求所有HAP或HSP的bundleName字段值均保持一致。  |
| bundleType                       | 要求所有HAP或HSP的bundleType字段值均保持一致。  |
| versionCode                      | 要求所有HAP或HSP的versionCode字段值均保持一致。 |
| debug                            | 从API version 20开始，要求所有HAP的debug字段值均保持一致，如果HAP的debug字段值为false，HSP的debug字段值也必须为false。如果HAP的debug字段值为true，对HSP的debug字段值无要求。<br/>对于API version 19及之前版本，要求所有HAP或HSP的debug字段值均保持一致。    |
| minAPIVersion                    | 从API version 20开始，要求所有HAP的minAPIVersion字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 19及之前版本，要求所有HAP或HSP的minAPIVersion字段值均保持一致。    |
| minCompatibleVersionCode         | 从API version 16开始，要求所有HAP的minCompatibleVersionCode字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 15及之前版本，要求所有HAP或HSP的minCompatibleVersionCode字段值均保持一致。    |
| targetAPIVersion                 | 从API version 16开始，要求所有HAP的targetAPIVersion字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 15及之前版本，要求所有HAP或HSP的targetAPIVersion字段值均保持一致。    |
| versionName                | 从API version 12开始，不再对versionName校验。      |
| buildVersion                | 从API version 23开始，要求所有HAP或HSP的buildVersion字段值均保持一致。      |

> **说明：** 
>
> - module.json文件为DevEco Studio编译构建产物，其中的字段与配置文件的对应关系，请参考[表1 module.json与配置文件属性的对照表](packing-tool.md)。

示例：

```bash
java -jar app_packing_tool.jar --mode multiApp [--hap-list <path>] [--hsp-list <path>] [--app-list <path>] --out-path <option> [--force true] [--encrypt-path <path>] [--pac-json-path <path>] [--atomic-service-entry-size-limit <size>] [--atomic-service-non-entry-size-limit <size>]
```

**表7** 多工程打包指令参数说明

| 指令         | 是否必选项 | 选项        | 描述                                                        |
|------------|-------|-----------|----------------------------------------------------------------|
| --mode     | 是     | multiApp  | 打包类型，在将多个HAP打入同一个App时，需保证每个HAP满足合法性校验规则。                                                            |
| --hap-list | 否     | HAP的路径    | HAP包文件路径，文件名必须以.hap为后缀。如果是多个HAP包需要“,”分隔。<br/>HAP文件路径也可以是目录。                                          |
| --hsp-list | 否     | HSP的路径    | HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要“,”分隔。<br/>HSP文件路径也可以是目录。                                          |
| --app-list | 否     | App的路径    | App文件路径，文件名必须以.app为后缀。如果是多个App包需要用“,”分隔。<br/>App文件路径也可以是目录。<br/>--hap-list，--hsp-list，--app-list不可以都不传。 |
| --out-path | 是     | NA | 目标文件路径，文件名必须以.app为后缀。 |
| --force    | 否     | boolean | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。  |
| --encrypt-path | 否     | encrypt.json的路径 | 文件名必须为encrypt.json。                                                                  |
| --pac-json-path | 否     | NA          | <!--RP1-->pac.json<!--RP1End-->文件路径，文件名必须为pac.json。<br/>最终app产物中pac.json文件只来源于该参数，不配置的话，最终app产物不包含该文件。<br/>--app-list参数指定的app包中的pac.json不会打包进最终app。<br/>从API version 20开始支持该参数。|
| --atomic-service-entry-size-limit      | 否         | NA            | 设置元服务entry包大小（包含其依赖包的大小）限制，仅Stage模型应用且bundleType为atomicService时生效。取值范围为[0,4194304]的整数，取值为0表示不限制大小，单位KB。不设置该参数时默认值为2048KB。如果entry包是release模式（module.json5文件中type字段值为entry，且app.json5中debug字段的值为false），该限制作用于打包app时压缩后的entry包大小（包含其依赖包的大小）。                       |
| --atomic-service-non-entry-size-limit  | 否         | NA            | 设置元服务非entry包大小（包含其依赖包的大小）限制，仅Stage模型应用且bundleType为atomicService时生效。取值范围为[0,4194304]的整数，取值为0表示不限制大小，单位KB。不设置该参数时默认值为2048KB。如果非entry包是release模式（module.json5文件中type字段值不是entry，且app.json5中debug字段的值为false），该限制作用于打包app时压缩后的非entry包大小（包含其依赖包的大小）。                     |
| --stat-duplicate       | 否     | boolean       | 打包完成后，是否扫描重复so文件，该参数可用于识别重复so，以减小包大小。取值为true时，执行扫描，扫描完成会在--out-path参数指定的输出文件所在目录下生成`scan_report`目录，其中包含文件名为`scan_result`的[重复so文件扫描报告](#扫描重复so文件)，并在告警中打印`scan_report`目录路径。取值为false时，不执行扫描。默认值为false。<br/>从API version 23开始支持该参数。 |
| --deduplicate-so       | 否     | boolean       | 用于在打包时对so文件进行去重，从而有效减小App的包体积。<br/>默认值：`false`<br/>取值说明：<br/>`true`：执行so文件去重。去重完成后，将在`--out-path`指定的目录下生成去重报告[so_dedup_report.json](#so去重报告)，并在日志中打印去重结果。<br/>`false`：不执行so文件去重。<br/>去重策略：<br/>- 当App包中不同模块间存在相同的so文件，且这些so会解压到应用根目录时（即`module.json5`中`compressNativeLibs`和`extractNativeLibs`不同时为`false`，且`libIsolation`为`false`）。<br/>- 打包工具会根据`deviceTypes`、`deliveryWithInstall`、`distributionFilter`、`requiredDeviceFeatures`等配置进行去重，确保去重后应用在各个可安装设备上的功能保持不变。<br/>**说明**：<br/>- 若应用代码中有直接从原始安装包中读取so文件的操作，开启去重后应用行为将发生变化。此时请勿开启该功能，或修改代码逻辑改为读取解压后的so文件后再开启。<br/>- 开发者若在打包时开启了so去重功能，建议仔细检查去重结果，并在上架前充分验证去重后App包的功能完整性。<br/>从API版本26.0.0开始支持该参数。|

## HQF打包指令

HQF包适用于[增量调试](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-incremental-debugging)场景。开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的HQF包。

> **说明：** 
>
> - HQF包不支持上架应用市场，仅用于增量调试。

示例:

```bash
java -jar app_packing_tool.jar --mode hqf --json-path <path> [--lib-path <path>] [--ets-path <path>] [--resources-path <path>] --out-path <path> [--force true]
```

**表8** HQF打包指令参数说明

| 指令          | 是否必选项 | 选项          | 描述                                 |
|-------------|-------|-------------|------------------------------------|
| --mode      | 是     | hqf         | 打包类型。                              |
| --json-path | 是     | NA          | .json文件路径，文件名必须为[patch.json](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-incremental-debugging#section28031446182019)。        |
| --lib-path  | 否     | NA          | lib库文件的路径。                         |
| --ets-path  | 否     | NA          | 存放ets文件目录路径。                       |
| --resources-path  | 否     | NA          | resources资源包路径。                       |
| --out-path  | 是     | NA          | 目标文件路径，文件名必须以.hqf为后缀。              |
| --force     | 否     | boolean | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。 |

## APPQF打包指令

APPQF包由一个或多个HQF文件组成。这些HQF包在应用市场会从APPQF包中拆分出来，再被分发到具体的设备上。开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的APPQF包。

**APPQF打包合法性校验**
- 在打包生成APPQF包时，确保每个HQF的[patch.json文件](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-incremental-debugging#section28031446182019)中的versionName、versionCode、patchVersionName、patchVersionCode保持一致。
- 所有HQF不得重复。HQF重复是指同时满足以下两个条件：
    1. 两个HQF的patch.json文件中module下的name字段相同。
    2. 两个HQF的patch.json文件中module下的deviceTypes属性相交（至少存在一个相同的设备类型）。

示例:

```bash
java -jar app_packing_tool.jar --mode appqf --hqf-list <path> --out-path <path> [--force true]
```

**表9** APPQF打包指令参数说明

| 指令         | 是否必选项 | 选项          | 描述                                 |
|------------|-------|-------------|------------------------------------|
| --mode     | 是     | appqf       | 打包类型。                              |
| --hqf-list | 是     | NA          | [HQF文件](packing-tool.md#hqf打包指令)路径，多个HQF以英文逗号隔开。              |
| --out-path | 是     | NA          | 目标文件路径，文件名必须以.appqf为后缀。            |
| --force    | 否     | boolean | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。 |

## 版本归一指令（versionNormalize）

同一个App中，所有HAP、HSP包的versionName和versionCode需要保持一致。当只有一个HAP或HSP需要修改升级时，可以调用此命令，将多个HAP、HSP的版本统一。本命令会修改所传入的HAP、HSP的版本号和版本名称，并在指定目录生成修改后的同名HAP、HSP，以及一个version_record.json文件，用于记录所有HAP、HSP原有的版本号、版本名称。

示例：
```bash
java -jar app_packing_tool.jar --mode versionNormalize --input-list 1.hap,2.hsp --version-code 1000001 --version-name 1.0.1 --out-path out
```

**表10** versionNormalize指令参数说明

| 指令             | 是否必选项 | 选项               | 描述                                                                |
|----------------|-------|------------------|-------------------------------------------------------------------|
| --mode         | 是     | versionNormalize | 命令类型。                                                             |
| --input-list   | 是     | HAP或HSP的路径       | 1. HAP或HSP包文件路径，文件名必须以.hap或.hsp为后缀。如果是多个HAP或HSP包需要“,”分隔。<br/>2. 传入目录时，会读取目录下所有的HAP和HSP文件。 |
| --version-code | 是     | 版本号              | 指定的版本号，HAP、HSP的版本号会被修改为该版本。需要为整数，且不小于所有传入的HAP、HSP的版本号。            |
| --version-name | 是     | 版本名称             | 指定的版本名称，HAP、HSP的版本名称会被修改为该版本名称。                                    |
| --out-path     | 是     | NA               | 目标文件路径，需要为一个目录。                                                   |

## 包名归一指令（packageNormalize）

此命令可以修改传入的HSP的包名和版本号，并在指定目录生成修改后的同名HSP。

示例：
```bash
java -jar app_packing_tool.jar --mode packageNormalize --hsp-list 1.hsp,2.hsp --bundle-name com.example.myapplication --version-code 1000001 --out-path out
```

**表11**  参数含义及规范

| 指令             | 是否必选项 | 选项            | 描述                                                  |
|----------------|-------|---------------|-----------------------------------------------------|
| --mode         | 是     | packageNormalize | 命令类型。                                               |
| --hsp-list     | 是     | HSP的路径      | 1. HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要“,”分隔。<br/>2. HSP包目录。仅处理目录内以.hsp为后缀的文件。|
| --bundle-name  | 是     | 包名            | 指定的包名，HSP的包名会被修改为指定的包名。                             |
| --version-code | 是     | 版本号           | 指定的版本号，HSP的版本号会被修改为该版本号。需要为整数，且大于0。                 |
| --out-path     | 是     | NA            | 目标文件路径，需要为一个目录。                                     |

## 通用归一指令（generalNormalize）

此命令可以修改传入的HAP或HSP的deviceType/bundleName/versionName/versionCode/minCompatibleVersionCode/minAPIVersion/targetAPIVersion/<br/>
apiReleaseType/bundleTypes/installationFree/deliveryWithInstall参数，并在指定目录生成修改后的同名HAP或HSP，以及一个general_record.json文件，用于记录所有HAP、HSP原有的参数名称和moduleName。上述设置的参数应符合正确打包规范，否则会在指定目录生成HAP或HSP失败，指定目录不会有文件生成。

> **说明：** 
>
> - 从API version 20开始支持通用归一化指令。

示例：

```bash
java -jar app_packing_tool.jar --mode generalNormalize --input-list 1.hsp,2.hsp --bundle-name com.example.myapplication --version-code 1000001 --version-name 1.0.1 --min-compatible-version-code 14 --min-api-version 14 --target-api-version 14 --api-release-type Release1 --bundle-type app --installation-free false --delivery-with-install true --device-types default,tablet --out-path out
```

**表12**  参数含义及规范

| 指令                          | 是否必选项 | 选项                                               | 描述                                                         |
| ----------------------------- | ---------- | -------------------------------------------------- | ------------------------------------------------------------ |
| --mode                        | 是         | generalNormalize                                   | 指令类型，表示通用归一化指令。                               |
| --input-list                  | 是         | HAP或HSP的路径                                     | 1. HAP或HSP包文件路径，文件名必须以.hap或.hsp为后缀。多个HAP或HSP包文件路径之间使用“,”分隔。<br/>2. 传入目录时，会读取目录下所有的HAP和HSP文件。 |
| --bundle-name                 | 否         | 包名                                               | 指定的Bundle名称，传入的包的Bundle名称会被修改为该Bundle名称。指定的值不能为空，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的bundleName字段。 |
| --version-code                | 否         | 版本号                                             | 指定的版本号，传入的包的版本号会被修改为该版本号。取值范围为0~2147483647的整数，指定的值不能为空值，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的versionCode字段。 |
| --version-name                | 否         | 版本名称                                           | 指定的版本名称，传入的包的版本名称会被修改为该版本名称。指定的值不能为空，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的versionName字段。 |
| --min-compatible-version-code | 否         | 能够兼容的最低历史版本号                           | 指定的最低历史版本号，传入的包的最低历史版本号会被修改为该版本号。取值范围为0~2147483647的整数，指定的值不能为空值，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的minCompatibleVersionCode字段。 |
| --min-api-version             | 否         | SDK的API最小版本                                   | 指定的SDK的API最小版本，传入的包的SDK的API最小版本会被修改为该版本。取值范围为0~2147483647的整数，指定的值不能为空值，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的minAPIVersion字段。 |
| --target-api-version          | 否         | API目标版本                                        | 指定的API目标版本，传入的包的API目标版本会被修改为该版本。取值范围为0~2147483647的整数，指定的值不能为空值，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的targetAPIVersion字段。 |
| --api-release-type            | 否         | API目标版本的类型                                  | 指定的API目标版本的类型，传入的包的API目标版本的类型会被修改为该类型。指定的值不能为空，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的apiReleaseType字段。 |
| --bundle-type                 | 否         | Bundle类型                                         | 指定的Bundle类型，传入的包的Bundle类型会被修改为该类型。指定的值不能为空，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的bundleType字段。 |
| --installation-free           | 否         | 是否支持免安装特性                                 | 指定的免安装特性，传入的包的免安装特性会被修改为该类型。指定的值不能为空，该字段的详细定义和规格请参考Stage模型[module.json5](../quick-start/module-configuration-file.md#配置文件标签)/FA模型[config.json](../quick-start/application-configuration-file-overview-fa.md)中的installationFree字段。 |
| --delivery-with-install       | 否         | 当前HAP是否在用户主动安装HAP所在应用的时候一起安装 | 指定的HAP是否需要一起安装，传入的包的deliveryWithInstall会被修改为该类型。指定的值不能为空，该字段的详细定义和规格参考Stage模型[module.json5](../quick-start/module-configuration-file.md#配置文件标签)/FA模型[config.json](../quick-start/application-configuration-file-overview-fa.md)中的deliveryWithInstall字段。 |
| --device-types                | 否         | 允许Ability运行的设备类型                          | 指定的设备类型，传入的包的设备类型会被修改为该类型。指定的值不能为空，该字段的详细定义和规格请参考Stage模型[module.json5](../quick-start/module-configuration-file.md#配置文件标签)/FA模型[config.json](../quick-start/application-configuration-file-overview-fa.md)中的deviceTypes字段，传入值的形式为字符串格式，多个设备类型之间使用“,”分隔。 |
| --out-path                    | 是         | NA                                                 | 目标文件路径，需要为一个有读写权限的目录。                   |
| --build-version                | 否         | 构建版本号                                             | 指定的构建版本号，传入的包的构建版本号会被修改为该版本号。指定的值不能为空值，该字段的详细定义和规格请参考[app.json5](../quick-start/app-configuration-file.md#配置文件标签)中的buildVersion字段。 |

## res模式打包指令

此命令用于打包元服务快照资源。

示例：

```bash
java -jar app_packing_tool.jar --mode res --entrycard-path <path> --pack-info-path <path> --out-path <path> [--force true]
```

**表13** 参数含义及规范

| 指令               | 是否必选项 | 选项            | 描述                                 |
|------------------|-------|---------------|------------------------------------|
| --mode           | 是     | res           | 命令类型。                              |
| --entrycard-path | 是     | NA            | 快照目录的路径。                           |
| --pack-info-path | 是     | NA            | pack.info文件路径。              |
| --out-path       | 是     | NA            | 目标文件路径，文件名必须以.res为后缀。              |
| --force          | 否     | boolean   | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。 |

## fastApp模式打包指令

开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、HAP、HSP包文件目录路径，生成所需的App包。App包用于上架应用市场。

**表14** fastApp打包合法性校验规则

| HAP或HSP的module.json中的被校验字段  | 校验规则                           |
| --------------------------------- | --------------------------------- |
| module下的name字段                | 要求所有HAP或HSP的name字段值均不相同。      |
| bundleName                       | 要求所有HAP或HSP的bundleName字段值均保持一致。  |
| bundleType                       | 要求所有HAP或HSP的bundleType字段值均保持一致。  |
| versionCode                      | 要求所有HAP或HSP的versionCode字段值均保持一致。 |
| debug                            | 从API version 20开始，要求所有HAP的debug字段值均保持一致，如果HAP的debug字段值为false，HSP的debug字段值也必须为false。如果HAP的debug字段值为true，对HSP的debug字段值无要求。<br/>对于API version 19及之前版本，要求所有HAP或HSP的debug字段值均保持一致。    |
| minAPIVersion                    | 从API version 20开始，要求所有HAP的minAPIVersion字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 19及之前版本，要求所有HAP或HSP的minAPIVersion字段值均保持一致。    |
| minCompatibleVersionCode         | 从API version 16开始，要求所有HAP的minCompatibleVersionCode字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 15及之前版本，要求所有HAP或HSP的minCompatibleVersionCode字段值均保持一致。    |
| targetAPIVersion                 | 从API version 16开始，要求所有HAP的targetAPIVersion字段值均保持一致，且均不低于所有HSP对应字段的最大值。<br/>对于API version 15及之前版本，要求所有HAP或HSP的targetAPIVersion字段值均保持一致。    |
| buildVersion                      | 从API version 23开始，要求所有HAP或HSP的buildVersion字段值均保持一致。 |

> **说明：** 
>
> - module.json文件为DevEco Studio编译构建产物，其中的字段与配置文件的对应关系，请参考[表1 module.json与配置文件属性的对照表](packing-tool.md)。

**打包App时的压缩规则：** 打包App时，对release模式的HAP、HSP包会进行压缩，对debug模式的HAP、HSP包不会压缩。

> **说明：** 
> 
> 若HAP或HSP中已压缩的so文件，在打包APP时再次压缩，将不会有明显体积缩减。

示例：

```bash
java -jar app_packing_tool.jar --mode fastApp [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--pack-res-path <path>] [--force true] [--encrypt-path <path>] [--pac-json-path <path>] [--atomic-service-entry-size-limit <size>] [--atomic-service-non-entry-size-limit <size>]
```

**表15** 参数含义及规范

| 指令                 | 是否必选项 | 选项         | 描述                                                     |
|--------------------|-------|------------|----------------------------------------------------|
| --mode             | 是     | fastApp    | 多个HAP需满足HAP的合法性校验。                                      |
| --hap-path         | 否     | NA         | HAP包文件目录路径，目录内要包含一个完整的HAP包的所有文件。允许传入多个路径，多个路径需要用英文“,”分隔。                                              |
| --hsp-path         | 否     | NA         | 1. HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要用英文“,”分隔。<br/>2. HSP包文件目录路径，目录内要包含一个完整的HSP包的所有文件。允许传入多个路径，多个路径需要用英文“,”分隔。 |
| --pack-info-path   | 是     | NA         | 文件名必须为pack.info。                                               |
| --out-path         | 是     | NA         | 目标文件路径，文件名必须以.app为后缀。                                             |
| --signature-path   | 否     | NA         | 签名路径。                                                            |
| --certificate-path | 否     | NA         | 证书路径。                                                |
| --pack-res-path    | 否     | NA         | pack.res快照文件路径。                   |
| --force            | 否     | boolean | 当目标文件路径已存在时，控制是否强制执行覆盖。当--out-path目标文件打包前已存在，该参数为true时，覆盖写入；为false时，终止打包过程并报错。当--out-path目标文件打包前不存在，正常打包，该参数无效。默认值为false。 |
| --encrypt-path     | 否     | NA         | 文件名必须为encrypt.json。           |
| --pac-json-path     | 否     | NA          | <!--RP1-->pac.json<!--RP1End-->文件路径，文件名必须为pac.json。<br/>从API version 20开始支持该参数。|
| --atomic-service-entry-size-limit      | 否         | NA            | 设置元服务entry包大小（包含其依赖包的大小）限制，仅Stage模型应用且bundleType为atomicService时生效。取值范围为[0,4194304]的整数，取值为0表示不限制大小，单位KB。不设置该参数时默认值为2048KB。如果entry包是release模式（module.json5文件中type字段值为entry，且app.json5中debug字段的值为false），该限制作用于打包app时压缩后的entry包大小（包含其依赖包的大小）。                      |
| --atomic-service-non-entry-size-limit  | 否         | NA            | 设置元服务非entry包大小（包含其依赖包的大小）限制，仅Stage模型应用且bundleType为atomicService时生效。取值范围为[0,4194304]的整数，取值为0表示不限制大小，单位KB。不设置该参数时默认值为2048KB。如果非entry包是release模式（module.json5文件中type字段值不是entry，且app.json5中debug字段的值为false），该限制作用于打包app时压缩后的非entry包大小（包含其依赖包的大小）。                     |
| --stat-duplicate       | 否     | boolean       | 打包完成后，是否扫描重复so文件，该参数可用于识别重复so，以减小包大小。取值为true时，执行扫描，扫描完成会在--out-path参数指定的输出文件所在目录下生成`scan_report`目录，其中包含文件名为`scan_result`的[重复so文件扫描报告](#扫描重复so文件)，并在告警中打印`scan_report`目录路径。取值为false时，不执行扫描。默认值为false。<br/>从API version 23开始支持该参数。 |
| --deduplicate-so       | 否     | boolean       | 用于在打包时对so文件进行去重，从而有效减小App的包体积。<br/>默认值：`false`<br/>取值说明：<br/>`true`：执行so文件去重。去重完成后，将在`--out-path`指定的目录下生成去重报告[so_dedup_report.json](#so去重报告)，并在日志中打印去重结果。<br/>`false`：不执行so文件去重。<br/>去重策略：<br/>- 当App包中不同模块间存在相同的so文件，且这些so会解压到应用根目录时（即`module.json5`中`compressNativeLibs`和`extractNativeLibs`不同时为`false`，且`libIsolation`为`false`）。<br/>- 打包工具会根据`deviceTypes`、`deliveryWithInstall`、`distributionFilter`、`requiredDeviceFeatures`等配置进行去重，确保去重后应用在各个可安装设备上的功能保持不变。<br/>**说明**：<br/>- 若应用代码中有直接从原始安装包中读取so文件的操作，开启去重后应用行为将发生变化。此时请勿开启该功能，或修改代码逻辑改为读取解压后的so文件后再开启。<br/>- 开发者若在打包时开启了so去重功能，建议仔细检查去重结果，并在上架前充分验证去重后App包的功能完整性。<br/>从API版本26.0.0开始支持该参数。|

## 扫描重复so文件

通过[app打包指令](#app打包指令)、[fastApp打包指令](#fastapp模式打包指令)或[多工程打包指令](#多工程打包指令)打包生成App包时，设置--stat-duplicate为true开启扫描重复so文件，系统将在打包成功后生成扫描报告。识别重复so后，开发者可根据实际需求减小包大小。扫描报告将存放在打包生成的App包所在目录下的`scan_report`目录中。扫描报告的内容结构如表16所示，重复so文件的特征信息结构如表17所示。扫描报告的示例如下：

json统计结果：
```json
[{
    "result":[{
        "md5":"975c41f5727b416b1ffefa5bb0f073b2",
        "size":1108880,
        "files":[
            "/application-entry-default.hap/libs/armeabi-v7a/example.so",
            "/entry-default.hap/libs/armeabi-v7a/example.so"
        ]
    }],
    "startTime": "2025-11-13 16:02:48.381",
    "stopTime": "2025-11-13 16:02:48.381",
    "taskDesc": "find the duplicated so"
}]
```
**表16 重复so文件扫描报告字段信息**

| 字段      | 类型   | 描述                        |
| --------- | ------ | --------------------------- |
| result    | Struct | 重复so文件的特征信息，包含MD5值、文件大小和文件路径，具体内容参考表17。       |
| startTime | String | 任务开始时间。              |
| stopTime  | String | 任务结束时间。              |
| taskDesc  | String | 任务描述，输出"find the duplicated so"。            |

**表17 重复so文件的特征字段信息**

| 字段  | 类型            | 描述                       |
| ----- | --------------- | -------------------------- |
| md5   | String          | 重复so文件的MD5值。          |
| size  | int             | 重复so文件的大小。单位为Byte。 |
| files | Vector\<String> | 重复so文件的路径。     |

## so去重报告

通过[App打包指令](#app打包指令)、[fastApp打包指令](#fastapp模式打包指令)或[多工程打包指令](#多工程打包指令)打包生成App包时，设置--deduplicate-so为true开启so去重功能，系统将在打包过程中对重复的so文件进行去重处理，并在打包成功后生成去重报告。去重报告将存放在打包生成的App包所在目录下的`so_dedup_report.json`文件中。去重报告记录了去重操作的时间戳、节省的总文件大小，以及每个模块中保留和移除的so文件列表。

去重报告的示例如下：
```json
{
    "timestamp":"2026-07-04T09:24:50Z",
    "totalSavedSize":4120,
    "modules":{
        "feature":{
            "kept":[],
            "removed":[
                "libs/arm64-v8a/libshared.so"
            ]
        },
        "entry":{
            "kept":[
                "libs/arm64-v8a/libshared.so"
            ],
            "removed":[]
        }
    }
}
```

**表18 so去重报告字段信息**

| 字段           | 类型   | 描述                                                         |
| -------------- | ------ | ------------------------------------------------------------ |
| timestamp      | String | so去重操作的时间戳，格式为ISO 8601（例如：2026-07-04T09:24:50Z）。 |
| totalSavedSize | int    | 通过去重操作节省的总文件大小，即去重前后所有HAP/HSP包大小差值之和（app压缩前），单位为Byte。                  |
| modules        | Object | 各个模块的去重详情，key为模块名称，value为该模块的去重信息对象。   |

**表19 模块去重信息字段信息**

| 字段    | 类型            | 描述                                                         |
| ------- | --------------- | ------------------------------------------------------------ |
| kept    | Vector\<String> | 该模块中保留的so文件路径列表（只针对存在重复的so）。                              |
| removed | Vector\<String> | 该模块中被移除的so文件路径列表。 |

## 打包工具错误码

### 10010001 执行打包工具失败
**错误信息**

Execute packing tool failed.

**错误描述**

执行打包工具失败。

**可能原因**

1. 打包文件合法性校验失败。
2. 需要打包的文件正在被其他程序使用，例如压缩软件或文件管理器。

**处理步骤**

1. 根据报错信息检查[app.json5](../quick-start/app-configuration-file.md)和[module.json5](../quick-start/module-configuration-file.md)中的配置项是否准确。当有多条报错信息时，优先根据第一条报错信息进行排查。
2. 检查是否有程序（如压缩软件、文件管理器）占用打包文件，关闭相关进程后重试。

### 10010002 打包参数解析失败
**错误信息**

Command parser failed.

**错误描述**

打包参数解析失败。

**可能原因**

1. 参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。
2. 必填参数缺失或传入空值。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10010003 --force参数值校验失败
**错误信息**

Command verify failed.

**错误描述**

--force参数值校验失败。

**可能原因**

1. --force参数值不是布尔类型。
2. 参数值不在取值范围内，仅支持取值为true或false。
3. 参数值大小写或格式错误，如True、FALSE、1、yes等。

**处理步骤**

检查参数值，确保明确指定为true或false。

### 10011001 打包HAP时参数校验失败
**错误信息**

Parse and check args invalid in hap mode.

**错误描述**

打包HAP时参数校验失败。

**可能原因**

参数值格式不正确，如路径为空、文件类型不匹配、非法字符。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011002 打包HSP时参数校验失败
**错误信息**

Parse and check args invalid in hsp mode.

**错误描述**

打包HSP时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011003 打包App时参数校验失败
**错误信息**

Parse and check args invalid in app mode.

**错误描述**

打包App时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011004 多工程打包时参数校验失败
**错误信息**

Parse and check args invalid in multiApp mode.

**错误描述**

多工程打包时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011005 res模式打包时参数校验失败
**错误信息**

Parse and check args invalid in res mode.

**错误描述**

res模式打包时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011006 打包HQF时参数校验失败
**错误信息**

Parse and check args invalid in hqf mode.

**错误描述**

打包HQF时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011007 打包APPQF时参数校验失败
**错误信息**

Parse and check args invalid in appqf mode.

**错误描述**

打包APPQF时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011008 包名归一化时参数校验失败
**错误信息**

Parse and check args invalid in packageNormalize mode.

**错误描述**

包名归一化时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011009 版本归一化时参数校验失败
**错误信息**

Parse and check args invalid in versionNormalize mode.

**错误描述**

版本归一化时参数校验失败。

**可能原因**

参数值格式不正确（如路径为空、文件类型不匹配、非法字符）。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011011 --mode参数值校验失败
**错误信息**

Command verify mode is invalid.

**错误描述**

--mode参数值校验失败。

**可能原因**

1. --mode参数值不是有效的打包模式。
2. 参数值拼写错误或大小写不符合规范。
3. 使用了当前工具版本尚未支持的打包模式。

**处理步骤**

1. 检查--mode参数取值，确保使用打包资料中列举的合法打包模式。
2. 核对参数拼写及大小写是否与文档保持一致。
3. 确认所使用的打包工具版本是否支持该打包模式。

### 10011012 校验bundleType是否为shared时失败
**错误信息**

Check bundleType is shared failed.

**错误描述**

校验bundleType是否为shared时失败。

**可能原因**

解析--json-path指定的module.json文件失败。

**处理步骤**

1. 检查--json-path指定的module.json文件，确保文件格式符合JSON格式规则。
2. 查看报错日志中第一条错误码，确认具体错误信息。

### 10011016 检查HSP是否包含入口UIAbility失败
**错误信息**

Check hsp has entry ability failed.

**错误描述**

检查HSP是否包含入口UIAbility失败。

**可能原因**

解析--json-path指定的module.json文件失败。

**处理步骤**

1. 检查--json-path指定的module.json文件，确保文件格式符合JSON格式规则。
2. 查看报错日志中第一条错误码，确认具体错误信息。

### 10011017 检查HSP是否包含入口ExtensionAbility失败
**错误信息**

Check hsp has entry extensionAbility failed.

**错误描述**

检查HSP是否包含入口ExtensionAbility失败。

**可能原因**

解析--json-path指定的module.json文件失败。

**处理步骤**

1. 检查--json-path指定的module.json文件，确保文件格式符合JSON格式规则。
2. 查看报错日志中第一条错误码，确认具体错误信息。

### 10011018 检查--out-path参数失败
**错误信息**

Invalid output path.

**错误描述**

检查--out-path参数失败。

**可能原因**

1. --force参数值为false，且--out-path指定的文件已存在。
2. 当前为HAP打包模式，但--out-path指定的文件后缀不是.hap。
3. 当前为HSP打包模式，但--out-path指定的文件后缀不是.hsp。
4. 当前为app打包模式，但--out-path指定的文件后缀不是.app。
5. 当前为res打包模式，但--out-path指定的文件后缀不是.res。

**处理步骤**

1. 当--out-path指定的目标文件已存在时，请将--force参数设置为true以允许覆盖。
2. 根据当前打包模式，确认--out-path指定的输出文件后缀正确。

### 10011020 版本归一化打包模式参数校验失败
**错误信息**

Handle hap and hsp input failed.

**错误描述**

版本归一化打包模式校验--input-list参数失败。

**可能原因**

--input-list参数指向的文件既不是HAP也不是HSP。

**处理步骤**

确认--input-list参数中列出的文件均为有效的.hap或.hsp包。

### 10011021 通用归一化打包模式参数校验失败
**错误信息**

Parse and check args invalid in generalNormalize mode.

**错误描述**

通用归一化打包模式参数校验失败。

**可能原因**

1. 打包归一化后的pack.info文件失败。
2. 通用归一化打包模式下的参数配置不正确。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10011022 检查元服务大小限制参数失败
**错误信息**

Parse atomicService size limit failed.

**错误描述**

检查元服务大小限制参数失败。

**可能原因**

1. --atomic-service-entry-size-limit参数值不在[0, 4194304]范围内（单位KB）。
2. --atomic-service-non-entry-size-limit参数值不在[0, 4194304]范围内（单位KB）。

**处理步骤**

1. 确认--atomic-service-entry-size-limit参数值为[0, 4194304]范围内的整数（单位KB）。
2. 确认--atomic-service-non-entry-size-limit参数值为[0, 4194304]范围内的整数（单位KB）。

### 10012001 执行压缩操作失败
**错误信息**

Execute compress process failed.

**错误描述**

执行打包操作时，例如打包HAP或App，执行压缩操作失败，导致打包中断。

**可能原因**

1. 打包文件合法性校验失败。
2. 需要打包的文件正在被其他程序使用，例如压缩软件或文件管理器。

**处理步骤**

1. 根据报错信息检查[app.json5](../quick-start/app-configuration-file.md)和[module.json5](../quick-start/module-configuration-file.md)中的配置项是否准确。当有多条报错信息时，优先根据第一条报错信息进行排查。
2. 检查是否有程序（如压缩软件、文件管理器）占用打包文件，关闭相关进程后重试。

### 10012002 HAP包压缩失败
**错误信息**

Compress Stage Hap failed.

**错误描述**

打包HAP时，执行压缩Stage模型的HAP包操作失败。

**可能原因**

1. Stage模型HAP包打包文件合法性校验失败。
2. 需要打包的文件正在被其他程序使用，例如压缩软件或文件管理器。

**处理步骤**

1. 根据报错信息检查[app.json5](../quick-start/app-configuration-file.md)和[module.json5](../quick-start/module-configuration-file.md)中的配置项是否准确。当有多条报错信息时，优先根据第一条报错信息进行排查。
2. 检查是否有程序（如压缩软件、文件管理器）占用打包文件，关闭相关进程后重试。

### 10012003 校验HAP信息失败
**错误信息**

Verify stage hap info failed.

**错误描述**

打包Stage模型HAP包时，配置信息校验失败。

**可能原因**

1. `module.json5`中`atomicService`或`continueBundleName`存在配置错误；或`app.json5`中`asanEnabled`或`hwasanEnabled`存在配置错误。
2. `module.json5`中`moduleType`为`skill`并且`bundleType`不为`skill`；或`bundleType`为`skill`并且`moduleType`不为`skill`。独立skill模块的bundleType和moduleType必须同为skill。

**处理步骤**

1. 参考[asanEnabled配置错误码](#10012004-检查参数asanenabled失败)、[hwasanEnabled配置错误码](#10012005-检查参数hwasanenabled失败)、[atomicService配置错误码](#10012006-检查atomicservice失败)、[continueBundleName配置错误码](#10012007-检查continuebundlename无效)，更改配置项。
2. 如果是独立skill模块，确保[app.json5](../quick-start/app-configuration-file.md)中`bundleType`和[module.json5](../quick-start/module-configuration-file.md)中`type`均配置为`skill`。

### 10012004 检查参数asanEnabled失败
**错误信息**

Check asanEnabled failed.

**错误描述**

打包HAP或HSP时，`app.json5`中`asanEnabled`配置错误。

**可能原因**

`asanEnabled`和`tsanEnabled`被同时设置为true。

**处理步骤**

检查[app.json5](../quick-start/app-configuration-file.md)，修改`asanEnabled`和`tsanEnabled`，确保二者不会同时为true。

### 10012005 检查参数hwasanEnabled失败
**错误信息**

Check hwasanEnabled failed.

**错误描述**

打包HAP或HSP时，`app.json5`中`hwasanEnabled`配置错误。

**可能原因**

1. `hwasanEnabled`和`asanEnabled`被同时配置为true。
2. `hwasanEnabled`和`tsanEnabled`被同时配置为true。
3. `hwasanEnabled`和`GWPAsanEnabled`被同时配置为true。

**处理步骤**

检查[app.json5](../quick-start/app-configuration-file.md)，确保`asanEnabled`、`tsanEnabled`、`GWPAsanEnabled`三项的中任一项与`hwasanEnabled`，不会同时配置为true。

### 10012006 检查atomicService失败
**错误信息**

Check atomicService failed.

**错误描述**

打包HAP或HSP时，`atomicService`配置检查失败。

**可能原因**

1. `module.json5`中`entry`模块未配置ability，导致`atomicService`配置检查失败。
2. 当`app.json5`中`bundleType`配置为`atomicService`时，但`module.json5`中`installationFree`为false。

**处理步骤**

1. 检查[module.json5](../quick-start/module-configuration-file.md)，确保`module.json5`文件中正确配置了`abilities`标签，并且至少包含一个ability，详细请参见[abilities标签](../quick-start/module-configuration-file.md#abilities标签)。
2. 检查`module.json5`和[app.json5](../quick-start/app-configuration-file.md)，当`bundleType`为`atomicService`时，确保`installationFree`配置为true，反之，需要配置为false。

### 10012007 检查continueBundleName无效
**错误信息**

Check continueBundleName invalid.

**错误描述**

打包HAP或HSP时，`continueBundleName`配置检查失败。

**可能原因**

`module.json5`中的`continueBundleName`与`app.json5`中`bundleName`相同。

**处理步骤**

修改`continueBundleName`，确保其与[app.json5](../quick-start/app-configuration-file.md)中的`bundleName`不同。

### 10012008 检查overlay失败
**错误信息**

Check whether is an overlay hsp failed.

**错误描述**

检查是否是overlay特性HSP包失败。

**可能原因**

1. 在`module.json5`中同时配置了`targetModuleName`与`requestPermissions`。

2. `module.json5`中的`targetModuleName`和`module.json5`中的`name`相同。

3. 在`module.json5`中配置了`targetPriority`时，未配置`targetModuleName`。

4. 在`app.json5`中配置了`targetBundleName`时，`module.json5`中未配置`targetModuleName`。

5. 在`app.json5`中的`targetBundleName`与`bundleName`配置相同。

**处理步骤**

1. 检查[module.json5](../quick-start/module-configuration-file.md)，确保`targetModuleName`和`requestPermissions`不会同时出现。
2. 检查`module.json5`，确保`targetModuleName`和`name`不同。
3. 检查`module.json5`，确保配置`targetPriority`时，同时配置了`targetModuleName`。
4. 检查[app.json5](../quick-start/app-configuration-file.md)和`module.json5`，确保配置`targetBundleName`时，同时配置了`targetModuleName`。
5. 检查`app.json5`，确保`targetBundleName`与`bundleName`不同。

### 10012009 执行压缩操作时异常
**错误信息**

Process compress exception.

**错误描述**

执行压缩HAP或HSP/App操作时存在异常。

**可能原因**

1. 打包文件合法性校验失败。
2. 需要打包的文件正在被其他程序使用，例如压缩软件或文件管理器。

**处理步骤**

1. 根据报错信息检查[app.json5](../quick-start/app-configuration-file.md)和[module.json5](../quick-start/module-configuration-file.md)中的配置项是否准确。当有多条报错信息时，优先根据第一条报错信息进行排查。
2. 检查是否有程序（如压缩软件、文件管理器）占用打包文件，关闭相关进程后重试。

### 10012010 校验模块generateBuildHash属性失败
**错误信息**

Verify has generate build hash failed.

**错误描述**

校验模块generateBuildHash属性失败。

**可能原因**

解析--json-path指定的module.json文件失败。

**处理步骤**

检查--json-path指定的module.json文件，确保文件格式符合JSON格式规则。

### 10012011 设置generateBuildHash属性失败
**错误信息**

Set generate build hash failed.

**错误描述**

设置generateBuildHash属性失败。

**可能原因**

1. 解析--json-path指定的module.json文件失败。
2. 在对module.json进行格式化或写入时发生I/O异常。

**处理步骤**

1. 检查--json-path指定的module.json文件，确保文件格式符合JSON格式规则。
2. 根据日志中“Error Message:”信息，定位具体的I/O或格式化异常原因。

### 10012012 检查应用的ubsanEnabled属性失败
**错误信息**

Check ubsanEnabled failed.

**错误描述**

检查应用的ubsanEnabled属性失败。

**可能原因**

1. 在app.json5中同时将ubsanEnabled和asanEnabled设置为true。
2. 在app.json5中同时将ubsanEnabled和tsanEnabled设置为true。
3. 在app.json5中同时将ubsanEnabled和hwasanEnabled设置为true。

**处理步骤**

修改app.json5配置，确保ubsanEnabled不与asanEnabled、tsanEnabled或hwasanEnabled中的任一属性同时为true。

### 10012013 解析module.json文件失败
**错误信息**

Read Stage hap verify info exist exception.

**错误描述**

解析module.json文件失败。

**可能原因**

1. 解析module.json时发生I/O异常。
2. JDK 20对zip64扩展数据字段校验存在已知缺陷，当zip包（如HAP、HSP或任何zip64文件）的目录中zip64扩展字段长度异常时，解析会抛出`Invalid CEN header (invalid zip64 extra data field size)`异常。

**处理步骤**

1. 根据日志中“Error Message:”信息，定位具体的I/O或格式化异常原因。
2. 若“Error Message:”中包含`Invalid CEN header (invalid zip64 extra data field size)`，请检查当前JDK版本是否为JDK 20。建议更换为JDK 17（LTS）或JDK 21（LTS）等长期支持版本。若无法更换JDK版本，可在JVM启动参数中添加`-Djdk.util.zip.disableZip64ExtraFieldValidation=true`规避此问题。在打包指令中添加JVM启动参数的示例如下：
   ```bash
   java -Djdk.util.zip.disableZip64ExtraFieldValidation=true -jar app_packing_tool.jar --mode app --hap-path <path> --out-path <path> --pack-info-path <path>
   ```

### 10012014 打包--lib-path指定目录失败
**错误信息**

Parallel compress exception.

**错误描述**

打包--lib-path指定目录失败。

**可能原因**

1. 待压缩文件在压缩过程中被删除。
2. 读取文件时发生I/O错误（坏盘、网络文件系统异常）。
3. 文件路径过长、包含不支持的字符。
4. 磁盘空间不足。

**处理步骤**

1. 确认待压缩文件存在。
2. 更换待压缩文件存储位置，重试打包。
3. 检查并修改文件路径和文件名，重试打包。
4. 清理磁盘，确认充足磁盘空间。

### 10012015 构建App包失败
**错误信息**

Compress app file failed.

**错误描述**

构建App包失败。

**可能原因**

1. App打包文件合法性校验失败。
2. 需要打包的文件正在被其他程序使用，例如压缩软件或文件管理器。

**处理步骤**

1. 根据报错信息检查[app.json5](../quick-start/app-configuration-file.md)和[module.json5](../quick-start/module-configuration-file.md)中的配置项是否准确。当有多条报错信息时，优先根据第一条报错信息进行排查。
2. 检查是否有程序（如压缩软件、文件管理器）占用打包文件，关闭相关进程后重试。

### 10012016 打包指定的HAP或HSP文件无效
**错误信息**

Check input hap or hsp file is invalid.

**错误描述**

打包指定的HAP或HSP文件无效。

**可能原因**

1. 打包参数中指定的HAP或HSP文件名为空。
2. 打包参数中HAP文件名后缀不是.hap或者HSP文件名后缀不是.hsp。

**处理步骤**

1. 确认打包参数中HAP或HSP文件名不为空。
2. 确认打包参数中HAP文件名后缀是.hap或者HSP文件名后缀是.hsp。

### 10012017 检查SharedAPP无效
**错误信息**

Check shared App mode invalid.

**错误描述**

构建[bundleType](../quick-start/app-configuration-file.md#配置文件标签)为shared的App包时，检查HSP包无效。

**可能原因**

1. 存在两个以上的[HSP包](../quick-start/in-app-hsp.md)。例如下图使用DevEco Studio构建App时，工程中包含了两个HSP包library和library1，此时打包APP包失败。

    ![alt text](figures/error-causes.png)

2. HSP包在`module.json5`中配置了`dependencies`。

**处理步骤**

1. 检查打包文件，确保`bundleType`为shared的App包中，HSP包不超过一个。
2. 检查打包文件，删除HSP包中[module.json5](../quick-start/module-configuration-file.md)配置的`dependencies`。

### 10012018 检查应用的Bundle类型无效
**错误信息**

Check bundleType is invalid.

**错误描述**

检查应用的Bundle类型无效。

**可能原因**

参与打包的HAP和HSP的bundleType不相同。

**处理步骤**

检查所有参与打包的HAP和HSP的app.json5配置文件，确认bundleType配置完全一致。

### 10012019 检查元服务包大小失败
**错误信息**

Check app atomicservice compress size failed.

**错误描述**

检查元服务包大小失败。

**可能原因**

1. 解析元服务包时抛I/O异常。
2. 元服务应用内没有HAP（module.json5文件中type字段值为entry或feature）和HSP（module.json5文件中type字段值为shared）包。

**处理步骤**

1. 根据日志中“Error Message:”信息，定位具体的I/O或格式化异常原因。
2. 检查元服务应用，确认包含HAP（module.json5文件中type字段值为entry或feature）和HSP（module.json5文件中type字段值为shared）包。

### 10012020 解析FA应用config.json文件失败
**错误信息**

Read FA hap verify info exist exception.

**错误描述**

解析FA应用config.json文件失败。

**可能原因**

解析FA应用的HAP或HSP包的config.json文件抛I/O异常。

**处理步骤**

根据日志中“Error Message:”信息，定位具体的I/O或格式化异常原因。

### 10012021 打包App时抛I/O异常
**错误信息**

IO exception when compress app.

**错误描述**

打包App时抛I/O异常。

**可能原因**

打包App时，应用的[pack.info](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app#section03812484215)文件覆盖HAP或HSP包内pack.info文件时抛I/O异常。

**处理步骤**

根据日志中“Error Message:”信息，定位具体的I/O或格式化异常原因。

### 10012022 校验Stage HSP失败
**错误信息**

Verify stage hsp info failed.

**错误描述**

打包HSP时，校验Stage模型HSP包失败。

**可能原因**

1. `module.json5`中的`atomicService`、`continueBundleName`存在配置错误，或`app.json5`中的`asanEnabled`、`hwasanEnabled`存在配置错误。
2. overlay配置出错。
3. `module.json5`中的`type`既不是`shared`也不是`skill`。独立skill模块的`type`必须为`skill`。

**处理步骤**

1. 参考[asanEnabled配置错误码](#10012004-检查参数asanenabled失败)、[hwasanEnabled配置错误码](#10012005-检查参数hwasanenabled失败)、[atomicService配置错误码](#10012006-检查atomicservice失败)、[continueBundleName配置错误码](#10012007-检查continuebundlename无效)，更改配置项。
2. 参考[检查overlay失败](#10012008-检查overlay失败)，更改配置项。
3. 检查[module.json5](../quick-start/module-configuration-file.md)，确保`type`配置为`shared`或`skill`。

### 10012023 json文件格式化失败
**错误信息**

Json special process exist exception.

**错误描述**

json文件格式化失败。

**可能原因**

json文件格式化时抛异常。

**处理步骤**

根据日志中“Error Message:”信息，定位具体的I/O或格式化异常原因。

### 10012024 校验元服务大小失败
**错误信息**

Check atomicService size failed.

**错误描述**

打包App时，元服务包的大小超出了限制。

**可能原因**

元服务包及依赖的共享库或资源文件大小超出了限制。具体限制请参考[表5 App打包指令参数说明](#app打包指令)中--atomic-service-entry-size-limit和--atomic-service-non-entry-size-limit参数描述。

**处理步骤**

优化并减少包的大小，例如删除不必要的资源、精简代码或减少依赖。

### 10012025 多工程打包失败
**错误信息**

Compress in app mode for multi project failed.

**错误描述**

多工程打包失败。

**可能原因**

1. multiApp打包文件合法性校验失败。
2. 需要打包的文件正在被其他程序使用，例如压缩软件或文件管理器。

**处理步骤**

1. 根据报错信息检查[app.json5](../quick-start/app-configuration-file.md)和[module.json5](../quick-start/module-configuration-file.md)中的配置项是否准确。当有多条报错信息时，优先根据第一条报错信息进行排查。
2. 检查是否有程序（如压缩软件、文件管理器）占用打包文件，关闭相关进程后重试。

### 10012028 打包--app-list参数失败
**错误信息**

Dispose app failed.

**错误描述**

处理app失败。

**可能原因**

多工程打包时，--app-list指定的app不包含pack.info文件。

**处理步骤**

确认--app-list指定的app包含pack.info文件。

### 10012029 APP/HAP/HSP不包含pack.info文件
**错误信息**

pack.info does not find in hap or app.

**错误描述**

多工程打包模式下，参与打包的APP/HAP/HSP不包含pack.info文件。

**可能原因**

多工程打包模式下，参与打包的APP/HAP/HSP包中缺失pack.info文件。

**处理步骤**

确认多工程打包模式下，所有参与打包的APP/HAP/HSP包均包含有效的pack.info文件。

### 10012034 解析moduleName失败
**错误信息**

Get module name from line string failed.

**错误描述**

res打包模式下，解析moduleName失败。

**可能原因**

res打包模式下，--pack-info-path指定的[pack.info](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app#section03812484215)文件缺失moduleName标签或moduleName标签值为空。

**处理步骤**

确认--pack-info-path指定的pack.info文件包含moduleName标签且moduleName标签值不为空。

### 10012035 APPQF模式打包失败
**错误信息**

Compress in appqf mode failed.

**错误描述**

APPQF模式打包失败。

**可能原因**

APPQF打包模式下，校验--hqf-list参数失败。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10012037 HQF一致性校验失败
**错误信息**

Check hqf has same app fields failed.

**错误描述**

在APPQF打包模式下，打包工具对--hqf-list参数指定的多个HQF包进行一致性校验时失败。

**可能原因**

1. APPQF打包模式下，--hqf-list指定的HQF集合中，存在两个及以上HQF的bundleName不相同。
2. APPQF打包模式下，--hqf-list指定的HQF集合中，存在两个及以上HQF的versionCode不相同。
3. APPQF打包模式下，--hqf-list指定的HQF集合中，存在两个及以上HQF的versionName不相同。
4. APPQF打包模式下，--hqf-list指定的HQF集合中，存在两个及以上HQF的patchVersionCode不相同。
5. APPQF打包模式下，--hqf-list指定的HQF集合中，存在两个及以上HQF的patchVersionName不相同。

**处理步骤**

1. 确认--hqf-list指定的所有HQF的bundleName相同。
2. 确认--hqf-list指定的所有HQF的versionCode相同。
3. 确认--hqf-list指定的所有HQF的versionName相同。
4. 确认--hqf-list指定的所有HQF的patchVersionCode相同。
5. 确认--hqf-list指定的所有HQF的patchVersionName相同。

### 10012038 检查HQF的moduleName失败
**错误信息**

Check hqf module is invalid.

**错误描述**

在APPQF打包模式下，--hqf-list参数指定的多个HQF包的moduleName校验失败。

**可能原因**

APPQF打包模式下，--hqf-list指定的HQF集合中，存在两个HQF的moduleName相同且deviceTypes属性集合相交。

**处理步骤**

确认--hqf-list指定的所有HQF的moduleName不相同或deviceTypes属性集合不相交。

### 10012039 版本归一化模式打包失败
**错误信息**

Version normalize failed.

**错误描述**

版本归一化模式打包失败。

**可能原因**

1. 版本归一化打包模式下，参与打包的HAP或HSP包同时存在module.json和config.json文件，导致冲突。
2. 版本归一化打包模式下，参与打包的HAP或HSP包既不包含module.json也不包含config.json文件，缺失必要配置文件。
3. 对pack.info、module.json或config.json文件解析失败，文件格式不合法或内容缺失。

**处理步骤**

1. 确认参与打包的HAP或HSP包中仅包含module.json或者config.json中的一个。
2. 查看报错日志中第一条错误码，确认具体错误信息。

### 10012040 校验模块的版本信息失败
**错误信息**

Verify module version failed.

**错误描述**

版本归一化打包模式下，校验模块的版本信息失败。

**可能原因**

版本归一化打包模式下，--version-code参数值小于--input-list参数中某个HAP或HSP包的versionCode值。

**处理步骤**

确认--version-code参数值大于等于--input-list参数中HAP或HSP包的versionCode值。

### 10012041 计算SHA-256值失败
**错误信息**

SHA-256 hash calculation failed.

**错误描述**

打包HAP或HSP时，计算SHA-256值失败。

**可能原因**

计算HAP或HSP包的SHA-256时抛I/O异常。

**处理步骤**

根据日志中“Error Message:”信息，定位具体的异常原因。

### 10012042 HAP或HSP包重复
**错误信息**

Select haps find duplicated hap.

**错误描述**

参与打包的HAP或HSP包中存在两个HAP包或两个HSP包文件名相同。

**可能原因**

多工程打包模式下，--app-list、--hap-list和--hsp-list参数值中存在两个HAP包或HSP包文件名相同。

**处理步骤**

确认--app-list、--hap-list和--hsp-list参数值中的HAP或HSP包文件名不相同。

### 10012046 解析config.json文件失败
**错误信息**

Parse and modify config.json failed.

**错误描述**

版本归一化模式或通用归一化模式下，解析config.json文件失败。

**可能原因**

1. config.json文件不包含app标签。
2. config.json文件中app标签下不包含version标签。
3. config.json文件中app/version标签下不包含code标签。
4. config.json文件中app/version标签下不包含name标签。
5. config.json文件中module标签下不包含name标签。

**处理步骤**

1. 检查config.json文件，确保包含app标签。
2. 检查config.json文件，确保app标签下包含version标签。
3. 检查config.json文件，确保app/version标签下包含code标签。
4. 检查config.json文件，确保app/version标签下包含name标签。
5. 检查config.json文件，确保module标签下包含name标签。

### 10012047 解析module.json文件失败
**错误信息**

Parse and modify module.json failed.

**错误描述**

版本归一化模式或通用归一化模式下，解析module.json文件失败。

**可能原因**

1. module.json文件不包含app标签。
2. module.json文件中app标签下不包含versionCode标签。
3. module.json文件中app标签下不包含versionName标签。
4. module.json文件中app标签下不包含bundleName标签。
5. module.json文件中module标签下不包含name标签。

**处理步骤**

1. 检查module.json文件，确保包含app标签。
2. 检查module.json文件，确保app标签下包含versionCode标签。
3. 检查module.json文件，确保app标签下包含versionName标签。
4. 检查module.json文件，确保app标签下包含bundleName标签。
5. 检查module.json文件，确保module标签下包含name标签。

### 10012050 检查插件宿主失败
**错误信息**

Check is plugin host failed.

**错误描述**

打包HSP时，检查插件宿主失败。

**可能原因**

--json-path指定的module.json文件中不包含module标签。

**处理步骤**

检查--json-path指定的module.json文件，确保包含module标签。

### 10012052 检查--pkg-context-path参数失败
**错误信息**

Check pkg context failed.

**错误描述**

打包HAP或HSP时，检查--pkg-context-path参数失败。

**可能原因**

1. --pkg-context-path参数值为空。
2. --pkg-context-path指定的不是pkgContextInfo.json文件。

**处理步骤**

1. 确认--pkg-context-path参数值不为空。
2. 确认--pkg-context-path指定的是pkgContextInfo.json文件。

### 10012053 检查插件属性失败
**错误信息**

Check app plugin failed.

**错误描述**

打包HSP时，检查插件属性失败。

**可能原因**

1. --json-path指定的module.json文件不存在。
2. --json-path指定的module.json文件不包含module标签。
3. 检查--pkg-context-path参数失败。
4. --json-path指定的module.json文件包含非embeddedUI类型的extensionAbilities。
5. --json-path指定的module.json文件中bundleType是appPlugin时，module.json文件不包含[ohos.permission.kernel.SUPPORT_PLUGIN](../security/AccessToken/restricted-permissions.md#ohospermissionkernelsupport_plugin)权限。

**处理步骤**

1. 确认--json-path指定的module.json文件存在。
2. 确认--json-path指定的module.json文件包含module标签。
3. 查看报错日志中第一条错误码，确认具体错误信息。
4. 确认--json-path指定的module.json文件不包含非embeddedUI类型的extensionAbilities。
5. 确认--json-path指定的module.json文件中bundleType是appPlugin时，module.json文件包含ohos.permission.kernel.SUPPORT_PLUGIN权限。

### 10012054 校验HAR去重属性失败
**错误信息**

Check deduplicateHar field failed.

**错误描述**

打包HSP/HAP时，校验[deduplicateHar](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app#section03812484215)属性失败。

**可能原因**

HSP/HAP模块module.json文件中minAPIVersion小于21，且deduplicateHar的值为true。

**处理步骤**

打包HSP/HAP时，如果deduplicateHar的属性值为true时，则要求minAPIVersion大于等于21。

### 10012055 二进制文件解压缩配置校验失败
**错误信息**

Binary file decompression configuration verification failed.

**错误描述**

打包HSP/HAP时，二进制文件的解压缩配置校验失败。

**可能原因**

HSP/HAP在[module.json5](../quick-start/module-configuration-file.md)配置了应用内可执行二进制文件的路径信息[executableBinaryPaths](../quick-start/module-configuration-file.md#executablebinarypaths标签)且存在二进制文件，但配置为以不解压libs库的方式进行安装。

**处理步骤**

如果module.json5中配置了executableBinaryPaths且存在二进制文件，请确保配置为应用以解压libs库的方式进行安装，即module.json5配置文件中的extractNativeLibs或compressNativeLibs中至少有一项为true。

### 10013001 解析module.json或config.json文件异常
**错误信息**

Parse json object exception.

**错误描述**

解析module.json或config.json文件异常。

**可能原因**

json文本语法错误，例如括号未闭合、引号使用不当、非法转义字符等。

**处理步骤**

确认json文本语法正确。

### 10013002 解析module.json或config.json文件失败
**错误信息**

Parse json profile failed.

**错误描述**

解析json配置失败。

**可能原因**

1. module.json或config.json文件不包含app标签。
2. module.json或config.json文件不包含module标签。
3. 解析module.json或config.json文件时抛异常。

**处理步骤**

1. 检查module.json或config.json文件，确保包含app标签。
2. 检查module.json或config.json文件，确保包含module标签。
3. 检查module.json或config.json文件，确保文件格式符合json格式规则。

### 10013003 检查atomicService属性无效
**错误信息**

Check module atomicService invalid.

**错误描述**

检查atomicService属性无效。

**可能原因**

HAP或HSP的bundleType不是atomicService，但module.json中配置了atomicService标签。

**处理步骤**

HAP或HSP的bundleType不是atomicService，更改module.json中配置的atomicService标签。

### 10013004 解析module.json文件失败
**错误信息**

Failed to parse module.json for the Stage module.

**错误描述**

解析module.json文件失败。

**可能原因**

1. module.json文件内不包含versionCode标签。
2. module.json文件内不包含versionName标签。
3. module.json文件内module标签内不包含name标签。

**处理步骤**

1. 检查module.json文件，确保包含versionCode标签。
2. 检查module.json文件，确保包含versionName标签。
3. 检查module.json文件，确保module标签内包含name标签。

### 10013005 检查模块bundleType失败
**错误信息**

Failed to parse module.json and bundleType.

**错误描述**

检查模块bundleType失败。

**可能原因**

不符合配置要求，例如：
1. 模块的[app.json5](../quick-start/app-configuration-file.md)配置文件中`bundleType`为app，但[module.json5](../quick-start/module-configuration-file.md)中的`installationFree`属性值为true。
2. 模块的app.json5配置文件中`bundleType`为atomicService，但module.json5中的`installationFree`属性值为false。
3. 模块的app.json5配置文件中`bundleType`为shared，但module.json5中的`type`属性值不是shared。
4. `bundleType`为skill，但module.json5中的`type`属性值不为skill；或`type`为skill但`bundleType`不为skill。独立skill模块的bundleType和moduleType必须同为skill。

**处理步骤**

1. 确保app.json5配置文件中`bundleType`为app时，module.json5中的`installationFree`属性值为false。
2. 确保app.json5配置文件中`bundleType`为atomicService时，module.json5中的`installationFree`属性值为true。
3. 确保app.json5配置文件中`bundleType`为shared时，module.json5中的`type`属性值也是shared。
4. 确保独立skill模块时，app.json5配置文件中`bundleType`和module.json5中的`type`均配置为skill。
5. 当有多条报错信息时，优先根据第一条报错信息进行排查。

### 10013006 检查entry模块中的ability失败
**错误信息**

check entry module at least one ability failed.

**错误描述**

Entry类型包中没有ability。

**可能原因**

Entry类型包中不存在ability，该错误可能是由于`module.json5`未配置`abilities`或者`abilities`配置为空引起。

**处理步骤**

检查[module.json5](../quick-start/module-configuration-file.md)，确保Entry类型包`abilities`正确配置了ability。

### 10013007 检查installationFree错误
**错误信息**

Check module atomicService installationFree invalid.

**错误描述**

打包HAP或HSP时，检查`atomicService`和`installationFree`配置出错。

**可能原因**

1. `app.json5`中的`bundleType`配置了无效值。
2. 当`bundleType`为shared时，`module.json5`中`installationFree`未设置为false。
3. 当`installationFree`为true时，`bundleType`未设置为atomicService。

**处理步骤**

1. 检查[app.json5](../quick-start/app-configuration-file.md)，确保`bundleType`设置为app，atomicService，shared<!--Del-->，appService<!--DelEnd-->之一。
2. 如果`bundleType`为shared，确保[module.json5](../quick-start/module-configuration-file.md)中的`installationFree`设置为false。
3. 如果`installationFree`为true，确保`bundleType`设置为atomicService。

### 10013008 获取bundleName属性失败
**错误信息**

Get the bundleName from json file failed.

**错误描述**

获取bundleName属性失败。

**可能原因**

module.json文件内app标签内不包含bundleName属性。

**处理步骤**

检查module.json文件，确保app标签内包含bundleName属性。

### 10013009 解析proxyData属性失败
**错误信息**

Failed to parse module.json and proxyData object.

**错误描述**

解析proxyData属性失败。

**可能原因**

module.json文件中module标签下的proxyData标签中某个元素不包含uri标签。

**处理步骤**

检查module.json文件，确保module标签下的proxyData标签各元素包含uri标签。

### 10013010 检查bundleType一致性失败
**错误信息**

Failed to check the consistency of bundleType.

**错误描述**

检查bundleType一致性失败。

**可能原因**

1. 各HAP模块的module.json文件中bundleType配置不一致。
2. 各HSP模块的module.json文件中bundleType配置不一致。

**处理步骤**
1. 检查各HAP模块的module.json文件，确保bundleType配置一致。
2. 检查各HSP模块的module.json文件，确保bundleType配置一致。

### 10013011 解析patch.json中模块名失败
**错误信息**

Failed to parse patch module name from patch.json.

**错误描述**

解析patch.json中模块名失败。

**可能原因**

patch.json文件内module标签内不包含name属性。

**处理步骤**

检查patch.json文件，确保module标签内包含name属性。

### 10013012 获取FA模型模块的config.json文件失败
**错误信息**

Failed to parse FA hap verify info from config.json.

**错误描述**

获取FA模型模块的config.json文件失败。

**可能原因**

打包FA模型app时，有HAP/HSP不包含config.json文件。

**处理步骤**

打包FA模型app时，确保所有HAP/HSP包含config.json文件。

### 10013013 解析FA模型模块的config.json文件失败
**错误信息**

Failed to parse config.json for the FA module.

**错误描述**

解析FA模型模块的config.json文件失败。

**可能原因**
1. config.json文件的app标签内不包含version标签。
2. config.json文件的app标签内version标签不包含code标签。
3. config.json文件的app标签内version标签不包含name标签。
4. config.json文件的app标签内不包含apiVersion标签。
5. config.json文件的module标签内不包含distro标签。
6. config.json文件的module标签内distro标签不包含moduleName标签。
7. config.json文件的module标签内不包含package标签。

**处理步骤**
1. 检查config.json文件，确保app标签内包含version标签。
2. 检查config.json文件，确保app标签内version标签包含code标签。
3. 检查config.json文件，确保app标签内version标签包含name标签。
4. 检查config.json文件，确保app标签内包含apiVersion标签。
5. 检查config.json文件，确保module标签内包含distro标签。
6. 检查config.json文件，确保module标签内distro标签包含moduleName标签。
7. 检查config.json文件，确保module标签内包含package标签。

### 10013014 合并pack.info文件失败
**错误信息**

Merge two pack.info into one pack.info file failed.

**错误描述**

合并pack.info文件失败。

**可能原因**

1. 校验pack.info文件失败。
2. 合并pack.info文件抛异常。

**处理步骤**

1. 查看报错日志中第一条错误码，确认具体错误信息。
2. 根据日志中“Error Message:”确认异常信息。

### 10013015 校验pack.info文件失败
**错误信息**

Verify pack.info file failed.

**错误描述**

校验pack.info文件失败。

**可能原因**

1. 参与合并的两个pack.info文件其中一个不包含summary标签。
2. 参与合并的两个pack.info文件其中一个不包含app标签。
3. 校验pack.info文件中app标签失败。

**处理步骤**

1. 检查参与合并的两个pack.info文件，确认均包含summary标签。
2. 检查参与合并的两个pack.info文件，确认均包含app标签。
3. 查看报错日志中第一条错误码，确认具体错误信息。

### 10013016 合并pack.info文件时校验失败
**错误信息**

Verify app in pack.info failed.

**错误描述**

合并pack.info文件时校验失败。

**可能原因**

1. 参与合并的两个pack.info文件的bundleName不一致。
2. 参与合并的两个pack.info文件的bundleType不一致。
3. 参与合并的两个pack.info文件其中一个app标签内不包含version标签。
4. 参与合并的两个pack.info文件app标签内code标签值不一致。

**处理步骤**

1. 检查参与合并的两个pack.info文件，确保bundleName一致。
2. 检查参与合并的两个pack.info文件，确保bundleType一致。
3. 检查参与合并的两个pack.info文件，确保app标签内包含version标签。
4. 检查参与合并的两个pack.info文件，确保app标签内code标签值一致。

### 10013017 校验pack.info文件的bundleType失败
**错误信息**

Verify bundleType in pack.info file failed.

**错误描述**

校验pack.info文件的bundleType失败。

**可能原因**

参与合并的两个pack.info文件的bundleType不一致。

**处理步骤**

检查参与合并的两个pack.info文件，确保bundleType一致。

### 10013018 解析pack.info文件forms标签失败

**错误信息**

Parse forms name in pack.info file failed.

**错误描述**

解析pack.info文件forms标签对应的模块名失败。

**可能原因**

1. pack.info文件不包含summary标签。
2. pack.info文件中summary标签内不包含modules标签。
3. pack.info文件中summary标签内modules标签中某个元素不包含distro标签。
4. pack.info文件中summary/modules/distro标签不包含moduleName标签。

**处理步骤**

1. 检查pack.info文件，确保包含summary标签。
2. 检查pack.info文件，确保summary标签内包含modules标签。
3. 检查pack.info文件，确保summary标签内modules标签中各元素均包含distro标签。
4. 检查pack.info文件，确保summary/modules/distro标签包含moduleName标签。

### 10013019 合并pack.info文件失败
**错误信息**

Failed to merge pack.info objects.

**错误描述**

multiApp打包模式下，合并HAP或HSP包的pack.info文件失败。

**可能原因**

1. 参与合并的两个pack.info文件其中一个不包含summary标签。
2. 参与合并的两个pack.info文件其中一个summary标签内不包含modules标签。
3. 参与合并的两个pack.info文件其中一个不包含packages标签。

**处理步骤**

1. 检查参与合并的两个pack.info文件，确保均包含summary标签。
2. 检查参与合并的两个pack.info文件，确保summary标签内包含modules标签。
3. 检查参与合并的两个pack.info文件，确保均包含packages标签。

### 10013020 合并pack.info文件失败
**错误信息**

Failed to merge two pack.info files into one pack.info file by packagePair.

**错误描述**

multiApp打包模式下，合并app包的pack.info文件失败。

**可能原因**

1. 校验pack.info文件失败。
2. 合并pack.info文件抛异常。

**处理步骤**

1. 查看报错日志中第一条错误码，确认具体错误信息。
2. 根据日志中“Error Message:”确认异常信息。

### 10013022 解析pack.info文件的forms属性失败
**错误信息**

Failed to parse pack.info forms.

**错误描述**

解析pack.info文件的forms属性失败。

**可能原因**

1. pack.info文件中forms标签内某元素不包含defaultDimension标签。
2. pack.info文件中forms标签内某元素defaultDimension标签值包含多个*。
3. pack.info文件中forms标签内存在一个或多个元素不包含supportDimensions标签。

**处理步骤**

1. 检查pack.info文件，确保forms标签内各元素均包含defaultDimension标签。
2. 检查pack.info文件，确保forms标签内各元素defaultDimension标签值均只包含1个*。
3. 检查pack.info文件，确保forms标签各元素均包含supportDimensions标签。

### 10014001 未找到可用文件
**错误信息**

File available not found exception.

**错误描述**

使用打包工具打包时，需要打包的文件不可使用。

**可能原因**

1. 指定的文件路径错误或文件不存在。
2. 文件正在被其他程序使用，例如压缩软件或文件管理器。
3. 当前用户没有访问该文件的权限。

**处理步骤**

1. 确认提供的文件路径正确，并检查该文件是否存在。
2. 检查是否有程序（如压缩软件、文件管理器）占用文件，关闭相关进程后重试。
3. 检查并调整文件的访问权限，例如当前用户可以读取、修改、删除文件。

### 10014002 关闭.zip归档输出流异常
**错误信息**

Close zip output stream exception.

**错误描述**

关闭.zip归档输出流异常。

**可能原因**

1. 磁盘I/O失败。
2. 磁盘空间不足。

**处理步骤**

根据日志中“Error Message:”信息确认具体错误信息，下面列举可能原因对应的处理措施。
1. 确保磁盘正常。
2. 确保磁盘空间剩余配额充足。

### 10014003 关闭I/O输入流异常
**错误信息**

IO exception when closing stream.

**错误描述**

关闭I/O输入流异常。

**可能原因**

底层文件描述符异常失效。

**处理步骤**

1. 根据日志中“Error Message:”确认异常信息。
2. 检查系统日志，确保文件系统和磁盘正常。

### 10014004 获取文件内容失败
**错误信息**

Get file content failed.

**错误描述**

获取文件内容失败。

**可能原因**

文件I/O操作抛异常。

**处理步骤**

根据日志中“Error Message:”，确认异常信息。

### 10014005 文件不存在
**错误信息**

Parse file not exist.

**错误描述**

文件不存在。

**可能原因**

文件不存在。

**处理步骤**

根据日志中“Error Message:”信息，确保文件路径正确且文件存在。

### 10014006 获取文件大小失败
**错误信息**

Get file size failed.

**错误描述**

获取文件大小失败。

**可能原因**

1. 文件不存在。
2. 路径指向的不是文件。

**处理步骤**

根据日志中“Error Message:”信息确认文件路径，确保文件存在且是文件类型。

### 10014007 文件I/O异常
**错误信息**

File IO exception.

**错误描述**

文件I/O异常。

**可能原因**

1. 文件不存在。
2. 操作文件权限不足。
3. 磁盘空间不足。

**处理步骤**

根据日志中“Error Message:”信息确认文件路径。
1. 确保文件存在。
2. 确保当前用户拥有操作文件权限。
3. 确保磁盘空间剩余配额充足。

### 10014008 压缩文件异常
**错误信息**

Compress file exception.

**错误描述**

压缩文件异常。

**可能原因**

打包压缩文件时抛异常。

**处理步骤**

根据日志中“Error Message:”，确认异常信息。

检查系统日志，确保文件系统和磁盘正常。

### 10014009 删除文件失败
**错误信息**

File delete failed.

**错误描述**

删除文件失败。

**可能原因**

文件被其它进程占用。

**处理步骤**

根据日志中“Error Message:”信息确认文件路径。

确保文件当前不被其它进程占用，手动删除文件。

### 10015001 文件I/O异常
**错误信息**

IO exception.

**错误描述**

文件I/O异常。

**可能原因**

1. 文件不存在。
2. 操作文件权限不足。
3. 磁盘空间不足。
4. 系统内部错误。

**处理步骤**

根据日志中“Error Message:”信息确认文件路径。
1. 确保文件存在。
2. 确保当前用户拥有操作文件权限。
3. 确保磁盘空间剩余配额充足。
4. 查看相关错误信息确认具体异常原因。

### 10015002 空指针异常
**错误信息**

Null pointer exception.

**错误描述**

空指针异常。

**可能原因**

程序类对象未初始化。

**处理步骤**

根据日志中“Error Message:”，确认异常信息。

### 10016001 校验应用属性失败
**错误信息**

App fields is invalid.

**错误描述**

打包App时，校验应用属性失败。

**可能原因**

1. 有两个HAP的minCompatibleVersionCode属性值不相同。
2. 有两个HAP的targetAPIVersion属性值不相同。
3. 有两个HAP的minAPIVersion属性值不相同。
4. 有两个HAP的debug属性值不相同。
5. HAP的minCompatibleVersionCode/targetAPIVersion/minAPIVersion属性值小于某HSP。
6. HAP的debug属性值为false时，存在HSP的debug属性值为true。

**处理步骤**

根据日志中“Error Message:”信息，确认错误信息及存在问题的HAP或HSP名。
1. 确保参与打包的HAP的minCompatibleVersionCode属性值相同。
2. 确保参与打包的HAP的targetAPIVersion属性值相同。
3. 确保参与打包的HAP的minAPIVersion属性值相同。
4. 确保参与打包的HAP的debug属性值相同。
5. 确保HAP的minCompatibleVersionCode/targetAPIVersion/minAPIVersion属性值大于等于所有HSP的对应属性值。
6. 确保HAP的debug属性值为false时，所有HSP的debug属性值为false。

### 10016002 HAP或HSP属性不同
**错误信息**

Some app variable is different.

**错误描述**

打包App时，HAP或HSP属性不同。

**可能原因**

1. 当前参与打包的HAP或HSP中，存在模块的bundleName与其他模块不一致。
2. 当前参与打包的HAP或HSP中，存在模块的bundleType与其他模块不一致。
3. 当前参与打包的HAP或HSP中，存在模块的versionCode与其他模块不一致。
4. 当前参与打包的HAP或HSP中，存在模块的apiReleaseType（[app.json5](../quick-start/app-configuration-file.md)配置文件中的属性）与其他模块不一致。
5. 当前参与打包的HAP或HSP中，存在模块的targetBundleName（app.json5配置文件中的属性）与其他模块不一致。
6. 当前参与打包的HAP或HSP中，存在模块的targetPriority（app.json5配置文件中的属性）与其他模块不一致。
7. 当前参与打包的HAP中，存在模块的multiAppMode（app.json5配置文件中的属性）与其他模块不一致。

**处理步骤**

1. 确保当前参与打包的HAP或HSP的bundleName一致。
2. 确保当前参与打包的HAP或HSP的bundleType一致。
3. 确保当前参与打包的HAP或HSP的versionCode一致。
4. 确保当前参与打包的HAP或HSP的apiReleaseType一致。
5. 确保当前参与打包的HAP或HSP的targetBundleName一致。
6. 确保当前参与打包的HAP或HSP的targetPriority一致。
7. 确保当前参与打包的HAP的multiAppMode一致。

### 10016003 分发策略相交校验失败
**错误信息**

Check two distroFilter policy disjoint invalid.

**错误描述**

[HAP唯一性校验](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-verification-rule)需要判断分发策略是否相交，由于分发策略配置错误，导致无法判断分发策略是否相交。

**可能原因**

分发策略`policy`、`value`标签为空或为无效值。

**处理步骤**

检查分发策略相关配置，确保`policy`的值为`include`或`exclude`，`value`取值参见[distributionFilter标签](../quick-start/module-configuration-file.md#distributionfilter标签)。

### 10016004 校验模块名失败
**错误信息**

Check module name is invalid.

**错误描述**

打包app时校验模块名失败。

**可能原因**

1. HAP或HSP的module.json文件module标签不包含name标签。
2. 在参与打包的HAP或HSP中，存在两个或以上module.json文件，其中module/name标签值相同，并且module/deviceType属性值有交集，同时module/metadata/resource/distributionFilter属性值也有交集。

**处理步骤**

1. 检查HAP或HSP的module.json文件，确保module标签包含name标签。
2. 检查参与打包的HAP或HSP的module.json文件，确保module/name标签值不相同或者module/deviceType属性值集合不相交或者module/metadata/resource/distributionFilter属性值集合不相交。

### 10016005 校验应用包名失败
**错误信息**

Check packageName invalid.

**错误描述**

校验应用包名失败。

**可能原因**

在参与打包的HAP或HSP中，存在两个或以上module.json文件，其中module/package标签值相同，并且module/deviceType属性值有交集，同时module/metadata/resource/distributionFilter属性值也有交集。

**处理步骤**

根据日志中“Error Message:”信息，确认存在问题的HAP或HSP。

检查参与打包的HAP或HSP的module.json文件，确保module/package标签值不相同或者module/deviceType属性值集合不相交或者module/metadata/resource/distributionFilter属性值集合不相交。

### 10016006 检查HAP包无效
**错误信息**

Verify hap info is invalid.

**错误描述**

构建App包时，校验用于打包的HAP或HSP失败。

**可能原因**

多个HAP或HSP包配置之间存在冲突。

**处理步骤**

根据报错信息检查[app.json5](../quick-start/app-configuration-file.md)和[module.json5](../quick-start/module-configuration-file.md)中的配置项是否准确。当有多条报错信息时，优先根据第一条报错信息进行排查。

### 10016007 检查entry模块无效
**错误信息**

Check entry module invalid.

**错误描述**

构建App包时，当工程中存在多个Entry类型HAP包时，检查配置信息失败。

**可能原因**

不符合HAP唯一性校验规则。

**处理步骤**

参考[HAP唯一性校验](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-verification-rule)，调整工程中的Entry类型HAP配置。

### 10016008 检查dependency属性无效
**错误信息**

Check dependency is invalid.

**错误描述**

检查dependency属性无效。

**可能原因**

参与打包的HAP或HSP的module.json文件中module/installationFree属性值不一致。

**处理步骤**

检查参与打包的HAP或HSP的module.json文件，确保module/installationFree属性值一致。

### 10016009 检查依赖错误
**错误信息**

Check dependency list is invalid.

**错误描述**

构建App包时，模块依赖关系检查失败。

**可能原因**

1. 模块间存在循环依赖，例如：模块library1的`module.json5`中`dependencies`配置了library2，同时模块library2中的`dependencies`配置了library1，则这两个模块之间构成循环依赖。
2. `module.json5`配置中依赖的模块对应的`module.json5`中的`type`为entry或feature。

**处理步骤**

1. 检查[module.json5](../quick-start/module-configuration-file.md)中的`dependencies`，删除循环依赖，确保App中不存在循环依赖。
2. 检查`module.json5`中的`dependencies`的配置，删除对entry或feature类型模块的依赖。

### 10016010 检查元服务无效
**错误信息**

Check atomicservice is invalid.

**错误描述**

构建App包时，检查元服务无效。

**可能原因**

`module.json5`中`preloads`配置的`moduleName`错误。

**处理步骤**

检查[module.json5](../quick-start/module-configuration-file.md)中的[preloads属性](../quick-start/module-configuration-file.md#atomicservice标签)下的`moduleName`，不能配置为自身模块`module.json5`中的`name`，且`moduleName`对应的模块必须存在。

### 10016011 检查元服务预加载无效
**错误信息**

Atomicservice preloads is invalid.

**错误描述**

构建bundleType为atomicService类型的App包时，检查元服务包预加载的模块无效。

**可能原因**

1. 元服务包`module.json5`中的`preloads`配置了重复的`moduleName`。
2. 元服务包`preloads`配置的`moduleName`，和其他元服务包中`module.json5`中的`name`不匹配。
3. 元服务包`preloads`配置的`moduleName`，和自身`module.json5`中的`name`相同。

**处理步骤**

检查[module.json5](../quick-start/module-configuration-file.md)中元服务[preloads属性](../quick-start/module-configuration-file.md#atomicservice标签)，确保没有配置重复的模块，配置所有的模块都存在且不能配置自身的模块名。

### 10016012 目标模块不存在
**错误信息**

TargetModuleName is not exist.

**错误描述**

构建App时，模块中配置了目标模块，但未找到该模块。

**可能原因**

`module.json5`中配置了`targetModuleName`，但和其他模块对应`module.json5`中的`name`均不同。

**处理步骤**

检查`targetModuleName`配置项，确保其正确配置（详细请参见[module.json5配置文件标签](../quick-start/module-configuration-file.md#配置文件标签)及targetModuleName属性），必要时创建目标模块。

### 10016013 校验compileSdkType属性不一致
**错误信息**

CompileSdkType is different.

**错误描述**

校验compileSdkType属性不一致。

**可能原因**

参与打包的HAP或HSP的module.json文件中app/compileSdkType标签值不一致。

**处理步骤**

检查参与打包的HAP或HSP的module.json文件，确保app/compileSdkType标签值一致。

### 10016014 代理数据不唯一
**错误信息**

Proxy data uri is not unique.

**错误描述**

数据代理uri不唯一，存在重复项。

**可能原因**

`module.json5`中的`proxyData`配置的uri存在重复。

**处理步骤**

检查[module.json5](../quick-start/module-configuration-file.md)，删除`proxyData`中重复的uri，确保每个uri都是唯一的（详细请参见[proxyData标签](../quick-start/module-configuration-file.md#proxydata标签)）。

### 10016015 ContinueType配置无效
**错误信息**

Check continueType is invalid.

**错误描述**

构建App时，检查continueType配置错误。

**可能原因**

1. `module.json5`不同的ability存在重复的`continueType`配置项。
2. 不同的`module.json5`中同时存在重复的`deviceType`配置项和`continueType`配置项。

**处理步骤**

检查[module.json5](../quick-start/module-configuration-file.md)，删除`continueType`或`deviceType`重复的配置项。

### 10016016 文件大小检查错误
**错误信息**

Check file size failed.

**错误描述**

构建元服务类型App时，单个包大小超过限制。

**可能原因**

单个包大小超过限制。具体限制请参考[表5 App打包指令参数说明](#app打包指令)中--atomic-service-entry-size-limit和--atomic-service-non-entry-size-limit参数描述。

**处理步骤**

优化并减少对应单个包文件的大小，例如删除不必要的资源、精简代码或压缩文件。

### 10016017 HapVerifyInfos集合为空
**错误信息**

The provided list of HapVerifyInfos is empty.

**错误描述**

HapVerifyInfos集合为空。

**可能原因**

打包APP时，--hap-path和--hsp-path参数值均为空。

**处理步骤**

打包APP时，确保--hap-path和--hsp-path参数值不能均为空。

### 10016018 元服务模块大小检查错误
**错误信息**

Check the atomicService module size failed.

**错误描述**

构建元服务类型App时，单个包和其依赖的共享库大小超过限制。

**可能原因**

单个包和其依赖的共享库总大小超过限制。具体限制请参考[表5 App打包指令参数说明](#app打包指令)中--atomic-service-entry-size-limit和--atomic-service-non-entry-size-limit参数描述。

**处理步骤**

优化并减少相应包的大小，例如删除不必要的资源、精简代码或减少依赖项。

### 10016019 检查分发策略无效
**错误信息**

Check the entry module distributionFilter is invalid.

**错误描述**

检查Entry类型模块分发策略错误。

**可能原因**

Entry类型模块分发策略配置存在错误。

**处理步骤**

检查Entry模块分发策略是否正确配置，例如`policy`的值应为`exclude`或`include`，详细请参考[distributionFilter标签](../quick-start/module-configuration-file.md#distributionfilter标签)。

### 10017001 包名归一化模式校验HSP包的bundleName和versionCode属性失败
**错误信息**

Normalize HSP bundleName and versionCode failed.

**错误描述**

包名归一化模式校验HSP包的bundleName和versionCode属性失败。

**可能原因**

1. HSP包的module.json文件不包含app标签。
2. HSP包的pack.info文件不包含summary标签。
3. HSP包的pack.info文件不包含summary/app标签。
4. HSP包的pack.info文件不包含summary/version标签。

**处理步骤**

1. 检查HSP包的module.json文件，确保包含app标签。
2. 检查HSP包的pack.info文件，确保包含summary标签。
3. 检查HSP包的pack.info文件，确保包含summary/app标签。
4. 检查HSP包的pack.info文件，确保包含summary/version标签。

### 10017002 更新module.json文件失败
**错误信息**

Update module.json failed.

**错误描述**

更新module.json文件失败。

**可能原因**

module.json文件不包含app标签。

**处理步骤**

确保module.json文件包含app标签。

### 10017003 更新pack.info文件失败
**错误信息**

Update pack.info failed.

**错误描述**

更新pack.info文件失败。

**可能原因**

1. pack.info文件不包含summary标签。
2. pack.info文件不包含summary/app标签。
3. pack.info文件不包含summary/version标签。

**处理步骤**

1. 检查pack.info文件，确保包含summary标签。
2. 检查pack.info文件，确保包含summary/app标签。
3. 检查pack.info文件，确保包含summary/version标签。

### 10018001 fastApp模式打包校验失败
**错误信息**

Parse and check args invalid in fast app mode.

**错误描述**

fastApp模式打包校验失败。

**可能原因**

打包参数校验失败。

**处理步骤**

查看报错日志中第一条错误码，确认具体错误信息。

### 10018002 检查bundleType一致性失败
**错误信息**

Check bundleType consistency failed.

**错误描述**

fastApp模式打包检查bundleType一致性失败。

**可能原因**

1. 参与打包的HAP包的bundleType属性值不一致。
2. 参与打包的HSP包的bundleType属性值不一致。

**处理步骤**

1. 检查参与打包的HAP包，确保bundleType属性值一致。
2. 检查参与打包的HSP包，确保bundleType属性值一致。

### 10018003 检查pack.info文件无效
**错误信息**

Pack.info is invalid.

**错误描述**

fastApp模式打包检查pack.info文件无效。

**可能原因**

1. --pack-info-path参数指向的pack.info文件的packages标签中有两个元素的name标签值相同。
2. --pack-info-path参数指向的pack.info文件不包含packages标签或packages标签内容为空。
3. --hap-path参数指向的HAP包的pack.info文件的packages标签中元素个数大于1。
4. --pack-info-path参数指向的pack.info文件的packages标签不包含--hap-path参数指向的HAP包。
5. --hap-path参数指向的HAP包中存在两个或以上HAP包的pack.info文件的packages/name标签值相同。
6. --hsp-path参数指向的HSP包的pack.info文件的packages标签中元素个数大于1。
7. --pack-info-path参数指向的pack.info文件的packages标签不包含--hsp-path参数指向的HSP包。
8. --hsp-path参数指向的HSP包中存在两个或以上HSP包的pack.info文件的packages/name标签值相同。

**处理步骤**

根据日志中“Error Message:”信息，确认存在问题文件的路径。
1. 检查--pack-info-path参数指向的pack.info文件。确保packages标签中各元素的name标签值均不相同。
2. 检查--pack-info-path参数指向的pack.info文件，确保包含packages标签并且packages标签内容不为空。
3. 检查--hap-path参数指向的HAP包的pack.info文件，确保packages标签中仅存在1个元素内容。
4. 检查--pack-info-path参数指向的pack.info文件，确保packages标签包含--hap-path参数指向的HAP包。
5. 检查--hap-path参数指向的HAP包中每个pack.info文件，确保packages/name的标签值唯一。
6. 检查--hsp-path参数指向的HSP包的pack.info文件，确保packages标签中仅存在1个元素内容。
7. 检查--pack-info-path参数指向的pack.info文件，确保packages标签包含--hsp-path参数指向的HSP包。
8. 检查--hsp-path参数指向的HSP包中每个pack.info文件，确保packages/name的标签值唯一。

### 10018004 向压缩包中添加文件或目录条目失败
**错误信息**

Add archive entry failed.

**错误描述**

向压缩包中添加文件或目录条目失败。

**可能原因**

待打包文件夹为空。

**处理步骤**

仅作告警提示，无需处理。

根据“Error Message:”信息获取待打包空文件目录，确认该空文件符合打包预期。

### 10018005 打包libs目录异常
**错误信息**

Packing with multiple threads exception.

**错误描述**

打包libs目录异常。

**可能原因**

打包libs目录异常。

**处理步骤**

根据日志中“Error Message:”，确认异常信息。

### 10018006 fastApp模式重打包HSP异常
**错误信息**

Repack hsp exception.

**错误描述**

fastApp模式重打包HSP异常。

**可能原因**

重打包HSP异常。

**处理步骤**

根据日志中“Error Message:”，确认异常信息。

### 10019001 增量打包HAP异常
**错误信息**

Incremental pack hap exception.

**错误描述**

增量打包HAP异常。

**可能原因**

增量打包HAP时抛I/O异常。

**处理步骤**

根据日志中“Error Message:”，确认异常信息。

### 10019002 增量打包HSP异常
**错误信息**

Incremental pack hsp exception.

**错误描述**

增量打包HSP异常。

**可能原因**

增量打包HSP时抛I/O异常。

**处理步骤**

根据日志中“Error Message:”，确认异常信息。

### 10021001 so去重失败
**错误信息**

so deduplication failed.

**错误描述**

so去重失败。

**可能原因**

1. so去重过程中发生I/O异常。
2. so文件MD5计算失败。
3. 文件系统操作失败。

**处理步骤**

1. 根据日志中“Error Message:”信息，确认具体的异常原因。
2. 检查模块中libs目录和so文件是否完整。
3. 确保有足够的磁盘空间进行so去重操作。