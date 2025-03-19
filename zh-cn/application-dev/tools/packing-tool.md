# 打包工具

打包工具用于在程序编译完成后，对编译出的文件等进行打包，以供安装发布。开发者可以使用DevEco Studio进行打包，也可使用打包工具的JAR包进行打包，JAR包通常存放在SDK路径下的toolchains目录中。

打包工具支持生成：Ability类型的模块包（HAP）、动态共享包（HSP）、应用程序包（App）、快速修复模块包（HQF）、快速修复包（APPQF）。


## 约束与限制

打包工具需要运行在Java8及其以上环境。


## HAP打包指令

开发者可以使用打包工具的JAR包对模块进行打包，通过传入打包选项、文件路径，生成所需的HAP包。

- Stage模型示例：


    ```
    java -jar app_packing_tool.jar --mode hap --json-path <path> [--resources-path <path>] [--ets-path <path>] [--index-path <path>] [--pack-info-path <path>] [--lib-path <path>] --out-path <path> [--force true] [--compress-level 5] [--pkg-context-path <path>] [--hnp-path <path>]
    ```

- FA模型示例：


    ```
    java -jar app_packing_tool.jar --mode hap --json-path <path> [--maple-so-path <path>] [--profile-path <path>] [--maple-so-dir <path>] [--dex-path <path>] [--lib-path <path>] [--resources-path <path>] [--index-path <path>] --out-path <path> [--force true] [--compress-level 5]
    ```

**表1** HAP打包指令参数说明

| 指令             | 是否必选项 | 选项          | 描述                                                         | 备注            |
| ---------------- | ---------- | ------------- | ------------------------------------------------------------ | --------------- |
| --mode           | 是         | hap           | 打包类型。                                                   | NA              |
| --json-path      | 是         | NA            | .json文件路径.FA模型文件名必须为config.json；Stage模型文件名必须为module.json。 | NA              |
| --profile-path   | 否         | NA            | CAPABILITY.profile文件路径。                                 | NA              |
| --maple-so-path  | 否         | NA            | maple so文件输入路径，so文件路径，文件名必须以.so为后缀。如果是多个so需要用“，”分隔。 | NA              |
| --maple-so-dir   | 否         | NA            | maple so目录输入路径。                                       | NA              |
| --dex-path       | 否         | NA            | dex文件路径，文件名必须以.dex为后缀。如果是多个dex需要用“，”分隔。 <br/>dex文件路径也可以为目录。 | NA              |
| --lib-path       | 否         | NA            | lib库文件路径。                                              | NA              |
| --resources-path | 否         | NA            | resources资源包路径。                                        | NA              |
| --index-path     | 否         | NA            | .index文件路径，文件名必须为resources.index。                | NA              |
| --pack-info-path | 否         | NA            | pack.info文件路径，文件名必须为pack.info。                   | NA              |
| --rpcid-path     | 否         | NA            | rpcid.sc文件路径，文件名必须为rpcid.sc。                     | NA              |
| --js-path        | 否         | NA            | 存放js文件目录路径。                                         | 仅stage模型生效 |
| --ets-path       | 否         | NA            | 存放ets文件目录路径。                                        | 仅stage模型生效 |
| --out-path       | 是         | NA            | 目标文件路径，文件名必须以.hap为后缀。                       | NA              |
| --force          | 否         | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。  | NA              |
| --an-path        | 否         | NA            | 存放an文件的路径。                                           | 仅stage模型生效 |
| --ap-path        | 否         | NA            | 存放ap文件的路径。                                           | 仅stage模型生效 |
| --dir-list       | 否         | NA            | 可指定目标文件夹列表，将其打入HAP包内。                      | NA              |
| --compress-level | 否         | number        | 压缩等级，默认值1，可选等级1-9。在应用配置compressNativeLibs参数为true的情况下生效，数值越大压缩率越高、压缩速度越慢。 | NA  |
| --pkg-context-path      | 否         | NA            | 可指定语境信息表文件路径，文件名必须为pkgContextInfo.json。 | 仅stage模型生效              |
| --hnp-path | 否 | NA | 指定native软件包文件路径，将native软件包打入HAP包内。 | NA |

## HSP打包指令

HSP包实现了多个HAP对文件的共享，开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的HSP包。

示例：
```
java -jar app_packing_tool.jar --mode hsp --json-path <path> [--resources-path <path>] [--ets-path <path>] [--index-path <path>] [--pack-info-path <path>] [--lib-path <path>] --out-path <path> [--force true] [--compress-level 5] [--pkg-context-path <path>]
```

**表2** HSP打包指令参数说明

| 指令             | 是否必选项 | 选项          | 描述                                                         |
| ---------------- | ---------- | ------------- | ------------------------------------------------------------ |
| --mode           | 是         | hsp           | 打包类型。                                                   |
| --json-path      | 是         | NA            | .json文件路径，文件名必须为module.json。                     |
| --profile-path   | 否         | NA            | CAPABILITY.profile文件路径。                                 |
| --dex-path       | 否         | NA            | 1.dex文件路径，文件名必须以.dex为后缀。如果是多个dex需要用“，”分隔。<br/>2.dex文件路径也可以为目录。 |
| --lib-path       | 否         | NA            | lib库文件路径。                                              |
| --resources-path | 否         | NA            | resources资源包路径。                                        |
| --index-path     | 否         | NA            | .index文件路径，文件名必须为resources.index。                |
| --pack-info-path | 否         | NA            | pack.info文件路径，文件名必须为pack.info。                   |
| --js-path        | 否         | NA            | 存放js文件目录路径。                                         |
| --ets-path       | 否         | NA            | 存放ets文件目录路径。                                        |
| --out-path       | 是         | NA            | 目标文件路径，文件名必须以.hsp为后缀。                       |
| --force          | 否         | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。  |
| --compress-level | 否         | number        | 压缩等级，默认值1，可选等级1-9。在应用配置compressNativeLibs参数为true的情况下生效，数值越大压缩率越高、压缩速度越慢。 |
| --pkg-context-path      | 否         | NA            | 可指定语境信息表文件路径，文件名必须为pkgContextInfo.json。 |

## App打包指令

开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的App包。App包用于上架应用市场。

**App打包时HAP合法性校验：** 在对工程内的HAP包打包生成App包时，需要保证被打包的每个HAP在json文件中配置的bundleName、versionCode、minCompatibleVersionCode、debug、minAPIVersion、targetAPIVersion相同，moduleName唯一。对于FA模型，还需要保证json文件中配置的package唯一。HAP模块之间需要保证apiReleaseType相同，HSP模块不校验apiReleaseType。

**打包App时的压缩规则：** 打包App时，对release模式的HAP、HSP包会进行压缩，对debug模式的HAP、HSP包不会压缩。

>**说明：**
>
>从API version 12开始，App打包不再对versionName校验。

示例：

```
java -jar app_packing_tool.jar --mode app [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--force true] [--encrypt-path <path>]
```

**表3** App打包指令参数说明

| 指令                 | 是否必选项 | 选项          | 描述                                                           |
|--------------------|-------|-------------|--------------------------------------------------------------|
| --mode             | 是     | app         | 多个HAP需满足HAP的合法性校验。                                           |
| --hap-path         | 否     | NA          | HAP包文件路径，文件名必须以.hap为后缀。如果是多个HAP包需要用“，”分隔。<br/>HAP包文件路径也可以是目录。 |
| --hsp-path         | 否     | NA          | HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要用“，”分隔。<br/>HSP包文件路径也可以是目录。 |
| --pack-info-path   | 是     | NA          | 文件名必须为pack.info。                                             |
| --out-path         | 是     | NA          | 目标文件路径，文件名必须以.app为后缀。                                        |
| --signature-path   | 否     | NA          | 签名路径。                                                        |
| --certificate-path | 否     | NA          | 证书路径。                                                        |
| --pack-res-path    | 否     | NA          | pack.res快照文件路径。                                 |
| --force            | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                           |
| --encrypt-path     | 否     | NA          | 文件名必须为encrypt.json 。                           |



## 多工程打包指令

多工程打包适用于多个团队开发同一个应用，但不方便共享代码的情况。开发者通过传入已经打好的HAP、HSP和App包，将多个包打成一个最终的App包，并上架应用市场。

**多工程打包HAP合法性校验：** 需要保证被打包的每个HAP在json文件中配置的bundleName、versionCode、minCompatibleVersionCode、debug属性相同，minAPIVersion、targetAPIVersion、compileSdkVersion、compileSdkType相同，moduleName唯一，同一设备entry唯一。对于FA模型，还需要保证json文件中配置的package唯一。HAP模块之间需要保证apiReleaseType相同，HSP模块不校验apiReleaseType。

>**说明：**
>
>从API version 12开始，多工程打包不再对versionName校验。

示例：

```
java -jar app_packing_tool.jar --mode multiApp [--hap-list <path>] [--hsp-list <path>] [--app-list <path>] --out-path <option> [--force true] [--encrypt-path <path>]
```

**表4** 多工程打包指令参数说明

| 指令         | 是否必选项 | 选项        | 描述                                                                                                  |
|------------|-------|-----------|-----------------------------------------------------------------------------------------------------|
| --mode     | 是     | multiApp  | 打包类型，在将多个HAP打入同一个App时，需保证每个HAP满足合法性校验规则。                                                            |
| --hap-list | 否     | HAP的路径    | HAP包文件路径，文件名必须以.hap为后缀。如果是多个HAP包需要”，“分隔。<br/>HAP文件路径也可以是目录。                                          |
| --hsp-list | 否     | HSP的路径    | HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要”，“分隔。<br/>HSP文件路径也可以是目录。                                          |
| --app-list | 否     | App的路径    | App文件路径，文件名必须以.app为后缀。如果是多个App包需要用”，“分隔。<br/>App文件路径也可以是目录。<br/>--hap-list，--hsp-list，--app-list不可以都不传。 |
| --out-path | 是     | NA | 目标文件路径，文件名必须以.app为后缀。 |
| --force    | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                                                                  |
| --encrypt-path | 否     | encrypt.json的路径 | 文件名必须为encrypt.json。                                                                  |



## HQF打包指令

HQF包适用于应用存在一些问题，需要紧急修复的场景。开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的HQF包。

示例:

```
java -jar app_packing_tool.jar --mode hqf --json-path <path> [--lib-path <path>] [--ets-path <path>] [--resources-path <path>] --out-path <path> [--force true]
```

**表5** HQF打包指令参数说明

| 指令          | 是否必选项 | 选项          | 描述                                 |
|-------------|-------|-------------|------------------------------------|
| --mode      | 是     | hqf         | 打包类型。                              |
| --json-path | 是     | NA          | .json文件路径，文件名必须为patch.json。        |
| --lib-path  | 否     | NA          | lib库文件的路径。                         |
| --ets-path  | 否     | NA          | 存放ets文件目录路径。                       |
| --resources-path  | 否     | NA          | resources资源包路径。                       |
| --out-path  | 是     | NA          | 目标文件路径，文件名必须以.hqf为后缀。              |
| --force     | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |

## APPQF打包指令

APPQF包由一个或多个HQF文件组成。这些HQF包在应用市场会从APPQF包中拆分出来，再被分发到具体的设备上。开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的APPQF包。

示例:

```
java -jar app_packing_tool.jar --mode appqf --hqf-list <path> --out-path <path> [--force true]
```

**表6** APPQF打包指令参数说明

| 指令         | 是否必选项 | 选项          | 描述                                 |
|------------|-------|-------------|------------------------------------|
| --mode     | 是     | appqf       | 打包类型。                              |
| --hqf-list | 是     | NA          | HQF文件路径，多个HQF以英文逗号隔开。              |
| --out-path | 是     | NA          | 目标文件路径，文件名必须以.appqf为后缀。            |
| --force    | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |

## 版本归一指令（versionNormalize）

同一个App中，所有HAP、HSP包的versionName和versionCode需要保持一致。当只有一个HAP或HSP需要修改升级时，可以调用此命令，将多个HAP、HSP的版本统一。本命令会修改所传入的HAP、HSP的版本号和版本名称，并在指定目录生成修改后的同名HAP、HSP，以及一个version_record.json文件，用于记录所有HAP、HSP原有的版本号、版本名称。

示例：
```
java -jar path\app_packing_tool.jar --mode versionNormalize --input-list 1.hap,2.hsp --version-code 1000001 --version-name 1.0.1 --out-path path\out\
```

**表7** versionNormalize指令参数说明

| 指令             | 是否必选项 | 选项               | 描述                                                                |
|----------------|-------|------------------|-------------------------------------------------------------------|
| --mode         | 是     | versionNormalize | 命令类型。                                                             |
| --input-list   | 是     | HAP或HSP的路径       | 1.HAP或HSP包文件路径，文件名必须以.HAP或.HSP为后缀。如果是多个HAP或HSP包需要“,”分隔。<br/>2.传入目录时，会读取目录下所有的HAP和HSP文件。 |
| --version-code | 是     | 版本号              | 指定的版本号，HAP、HSP的版本号会被修改为该版本。需要为整数，且不小于所有传入的HAP、HSP的版本号。            |
| --version-name | 是     | 版本名称             | 指定的版本名称，HAP、HSP的版本名称会被修改为该版本名称。                                    |
| --out-path     | 是     | NA               | 目标文件路径，需要为一个目录。                                                   |

## 包名归一指令（packageNormalize）

此命令可以修改传入的HSP的包名和版本号，并在指定目录生成修改后的同名HSP。

示例：
```
java -jar path\app_packing_tool.jar --mode packageNormalize --hsp-list path\1.hsp,path\2.hsp --bundle-name com.example.myapplication --version-code 1000001 --out-path path\out\
```

**表8**  参数含义及规范

| 指令             | 是否必选项 | 选项            | 描述                                                  |
|----------------|-------|---------------|-----------------------------------------------------|
| --mode         | 是     | packageNormalize | 命令类型。                                               |
| --hsp-list     | 是     | HSP的路径      | 1.HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要“,”分隔。<br/>2.HSP包目录。 |
| --bundle-name  | 是     | 包名            | 指定的包名，HSP的包名会被修改为指定的包名。                             |
| --version-code | 是     | 版本号           | 指定的版本号，HSP的版本号会被修改为该版本号。需要为整数，且大于0。                 |
| --out-path     | 是     | NA            | 目标文件路径，需要为一个目录。                                     |

## res模式打包指令

此命令用于打包元服务快照资源。

示例：

```
java -jar app_packing_tool.jar --mode res --entrycard-path <path> --pack-info-path <path> --out-path <path> [--force true]
```

**表9** 参数含义及规范

| 指令               | 是否必选项 | 选项            | 描述                                 |
|------------------|-------|---------------|------------------------------------|
| --mode           | 是     | res           | 命令类型。                              |
| --entrycard-path | 是     | NA            | 快照目录的路径。                           |
| --pack-info-path | 是     | NA            | pack.info文件路径。              |
| --out-path       | 是     | NA            | 目标文件路径，文件名必须以.res为后缀。              |
| --force          | 否     | true或者false   | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |

## fastApp模式打包指令

开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、HAP、HSP包文件目录路径，生成所需的App包。App包用于上架应用市场。

**App打包时HAP合法性校验：** 在对工程内的HAP包打包生成App包时，需要保证被打包的每个HAP在json文件中配置的bundleName、versionCode、minCompatibleVersionCode、debug、minAPIVersion、targetAPIVersion相同，moduleName唯一。HAP模块之间需要保证apiReleaseType相同，HSP模块不校验apiReleaseType。

**打包App时的压缩规则：** 打包App时，对release模式的HAP、HSP包会进行压缩，对debug模式的HAP、HSP包不会压缩。

示例：

```
java -jar app_packing_tool.jar --mode fastApp [--hap-path <path>] [--hsp-path <path>] --out-path <path> [--signature-path <path>] [--certificate-path <path>] --pack-info-path <path> [--pack-res-path <path>] [--force true] [--encrypt-path <path>]
```

**表10** 参数含义及规范

| 指令                 | 是否必选项 | 选项         | 描述                                                                                                    |
|--------------------|-------|------------|-------------------------------------------------------------------------------------------------------|
| --mode             | 是     | fastApp    | 多个HAP需满足HAP的合法性校验。                                                                                    |
| --hap-path         | 否     | NA         | HAP包文件目录路径，目录内要包含一个完整的HAP包的所有文件。允许传入多个路径，多个路径需要用英文“,”分隔。                                              |
| --hsp-path         | 否     | NA         | 1.HSP包文件路径，文件名必须以.hsp为后缀。如果是多个HSP包需要用英文“,”分隔。2.HSP包文件目录路径，目录内要包含一个完整的HSP包的所有文件。允许传入多个路径，多个路径需要用英文“,”分隔。 |
| --pack-info-path   | 是     | NA         | 文件名必须为pack.info。                                                                                      |
| --out-path         | 是     | NA         | 目标文件路径，文件名必须以.app为后缀。                                                                                 |
| --signature-path   | 否     | NA         | 签名路径。                                                                                                 |
| --certificate-path | 否     | NA         | 证书路径。                                                                                                 |
| --pack-res-path    | 否     | NA         | pack.res快照文件路径。                                                                          |
| --force            | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                                                                    |
| --encrypt-path     | 否     | NA         | 文件名必须为encrypt.json。                                                                    |

## 打包工具错误码

### 10010001 执行打包工具失败
**错误信息**

Execute packing tool failed.

**错误描述**

执行打包工具失败。

**可能原因**

1. 打包指令参数错误。
2. 打包文件合法性校验失败。

**处理步骤**

1. 检查打包指令参数是否正确，例如传入参数为文件路径时，需确保该路径下存在该文件。详细请参见[HAP打包指令](#hap打包指令)、[HSP打包指令](#hsp打包指令)、[App打包指令](#app打包指令)。
2. 根据相关报错信息检查打包文件是否正确，例如下图使用DevEco Studio进行打包HAP包时，配置`app.json5`中`asanEnabled`和`tsanEnable`同时为true，会同时给出错误码10010001和[10012004](#10012004-检查参数asanenabled失败)的错误信息以及相关解决方案。当有多条报错信息时，通常根据第一条报错信息进行排查解决。

![alt text](figures/zh_cn_packing_tool_image_10010001_01.png)

HAP包文件合法性，详细可参见:
- [应用配置文件概述（Stage模型）](../../application-dev/quick-start/application-configuration-file-overview-stage.md)
- [应用配置文件概述（FA模型）](../../application-dev/quick-start/application-configuration-file-overview-fa.md)

### 10012001 执行压缩操作失败
**错误信息**

Execute compress process failed.

**错误描述**

执行打包操作时，例如打包HAP或App，发生压缩失败，导致打包中断。

**可能原因**

1. 打包文件校验不通过，例如`app.json5`配置错误。
2. 需要打包的文件正在被其他程序使用，例如IDE、压缩软件或文件管理器。

**处理步骤**

1. 查看错误日志，检查具体报错的文件路径，确认打包文件是否完整、配置是否正确。例如下图使用DevEco Studio进行打包HAP包时，错误配置了`app.json5`中`asanEnabled`和`tsanEnable`同时为true，会同时给出错误码10012001和[10012004](#10012004-检查参数asanenabled失败)的错误信息以及相关解决方案。当有多条报错信息时，通常根据第一条报错信息进行排查解决。
   
![alt text](figures/zh_cn_packing_tool_image_10012001_01.png)

2. 关闭可能占用打包文件的相关程序或进程，例如IDE、压缩软件或文件管理器。

### 10012002 压缩HAP失败
**错误信息**

Compress Stage Hap failed.

**错误描述**

打包HAP时，压缩Stage类型的HAP包失败。

**可能原因**

1. HAP文件合法性校验失败，例如 `config.json`、`module.json5`、`app.json5`配置错误。
2. 其他进程正在占用打包HAP所需文件。

**处理步骤**

1. 查看错误日志，检查具体的错误信息（参考[执行压缩操作失败](#10012001-执行压缩操作失败)），确认失败的文件或目录。检查HAP相关配置文件（如`config.json`、`module.json5`、`app.json5`），确保格式正确、内容完整。
2. 关闭可能占用打包文件的相关程序或进程，例如压缩软件或文件管理器。

### 10012003 校验HAP信息失败
**错误信息**

Verify stage hap info failed.

**错误描述**

打包HAP时，校验Stage类型HAP包配置信息失败。

**可能原因**

以下配置项可能存在错误，检查`module.json5`和`app.json5`是否配置正确：
1. `asanEnabled`配置错误。
2. `hwasanEnabled`配置错误。
3. `atomicService`配置错误。
4. `continueBundleName`配置错误。

**处理步骤**

1. 参考[asanEnabled配置错误](#10012004-检查参数asanenabled失败)。
2. 参考[hwasanEnabled配置错误](#10012005-检查参数hwasanenabled失败)。
3. 参考[atomicService配置错误](#10012006-检查atomicservice失败)。
4. 参考[continueBundleName配置错误](#10012007-检查continuebundlename无效)。

### 10012004 检查参数asanEnabled失败
**错误信息**

Check asanEnabled failed.

**错误描述**

打包HAP/HSP时，`app.json5`中`asanEnabled`配置错误。

**可能原因**

`asanEnabled`和`tsanEnabled`被同时设置为true（如下图所示）。

![alt text](figures/zh_cn_packing_tool_image_10012004_01.png)

**处理步骤**

检查`app.json5`文件，修改`asanEnabled`和`tsanEnabled`，确保二者不会同时为true。

### 10012005 检查参数hwasanEnabled失败
**错误信息**

Check hwasanEnabled failed.

**错误描述**

打包HAP/HSP时，`app.json5`中`hwasanEnabled`配置错误。

**可能原因**

1. `hwasanEnabled`和`asanEnabled`被同时配置为true（如下图所示）。

![alt text](figures/zh_cn_packing_tool_image_10012005_01.png)

2. `hwasanEnabled`和`tsanEnabled`被同时配置为true。
3. `hwasanEnabled`和`GWPAsanEnabled`被同时配置为true。

**处理步骤**

检查`app.json5`，确保`hwasanEnabled`和`asanEnabled`、`tsanEnabled`和`GWPAsanEnabled`不会同时配置为true。

### 10012006 检查atomicService失败
**错误信息**

Check atomicService failed.

**错误描述**

打包HAP/HSP时，`atomicService`配置检查失败。

**可能原因**

1. `module.json5`中`entry`模块未配置ability，导致`atomicService`配置检查失败，详细请参见错误码[10013006 检查 entry 模块中的 ability 失败](#10013006-检查entry模块中的ability失败)。
2. 当`app.json5`中`bundleType`配置为`atomicService`时，`module.json5`中`installationFree`为false。

**处理步骤**

1. 检查`module.json5`，确保`module.json5`文件中正确配置了`abilities`标签，并且至少包含一个ability，详细请参见[abilities标签](../../application-dev/quick-start/module-configuration-file.md#abilities标签)。
2. 检查`module.json5`和`app.json5`，当`bundleType`为`atomicService`时，确保`installationFree`配置为true，反之，需要配置为false。

### 10012007 检查continueBundleName无效
**错误信息**

Check continueBundleName invalid.

**错误描述**

打包HAP/HSP时，检查`module.json5`中的`continueBundleName`配置错误。

**可能原因**

`continueBundleName`与当前包名称相同。例如下图中`module.json5`配置的`continueBundleName`为`app.json5`中配置的`bundleName`。

![alt text](figures/zh_cn_packing_tool_image_10012007_01.png)

**处理步骤**

修改`continueBundleName`，确保其未配置自身包名。

### 10012008 检查overlay失败
**错误信息**

Check whether is an overlay hsp failed.

**错误描述**

HSP包配置的`targetModuleName`指定的目标module存在错误。

**可能原因**

1. 在`module.json5`中同时配置了`targetModuleName`与`requestPermissions`。

![alt text](figures/zh_cn_packing_tool_image_10012008_01.png)

2. 在`module.json5`中`targetModuleName`配置为自身的模块名。

![alt text](figures/zh_cn_packing_tool_image_10012008_02.png)

3.  在`module.json5`中配置了`targetPriority`，但未配置`targetModuleName`。

![alt text](figures/zh_cn_packing_tool_image_10012008_03.png)

4. 仅在`app.json5`中配置了targetBundleName，`module.json5`中未配置targetModuleName。

![alt text](figures/zh_cn_packing_tool_image_10012008_04.png)

5. 在`app.json5`中`targetBundleName`与`bundleName`配置相同。

![alt text](figures/zh_cn_packing_tool_image_10012008_05.png)

**处理步骤**

1. 检查`module.json5`，确保`targetModuleName`和`requestPermissions`不会同时出现。
2. 检查`module.json5`，确保`targetModuleName`和自身模块名不同。
3. 检查`module.json5`，确保配置`targetPriority`前配置了`targetModuleName`。
4. 检查`app.json5`和`module.json5`，根据需要增加`targetModuleName`。`targetModuleName`详细请参见[module.json5配置文件标签](../../application-dev/quick-start/module-configuration-file.md#配置文件标签)中targetModuleName标签。
5. 检查`app.json5`，确保`targetBundleName`与`bundleName`不同。

### 10012009 执行压缩操作时异常
**错误信息**

Process compress exception.

**错误描述**

压缩HAP/HSP/App时存在异常。

**可能原因**

校验HAP/HSP/App的包内容错误，例如`module.json5`文件配置错误。

**处理步骤**

根据相关报错信息检查打包文件是否正确，例如下图使用DevEco Studio进行打包HAP包时，配置了`app.json5`中`asanEnabled`和`tsanEnabled`同时为true，DevEco Studio日志会同时给出错误码10012009和[10012004](#10012004-检查参数asanenabled失败)的错误信息以及相关解决方案。当有多条报错信息时，通常根据第一条报错信息进行排查解决。

![alt text](figures/zh_cn_packing_tool_image_10012009_01.png)

### 10012015 构建App包失败
**错误信息**

Compress app file failed.

**错误描述**

构建App类型的包时失败。

**可能原因**

校验HAP/HSP/App合法性失败。
**处理步骤**

根据相关报错信息进行修改。例如下图使用DevEco Studio构建shared类型App包，检查SharedApp无效，DevEco Studio日志会同时给出错误码10012015和[10012017](#10012017-检查sharedapp无效)的错误信息以及相关解决方案。当有多条报错信息时，通常根据第一条报错信息进行排查解决。

![alt text](figures/zh_cn_packing_tool_image_10012015_01.png)

### 10012017 检查SharedAPP无效
**错误信息**

Check shared App mode invalid.

**错误描述**

构建shared类型的App包（共享库应用，详细请参见[app.json5文件及bundleType标签](../../application-dev/quick-start/app-configuration-file.md#配置文件标签)）时，检查HSP包不通过。

**可能原因**

1. 存在两个以上的HSP包（动态共享包，详细请参见[module.json5文件及type标签](../../application-dev/quick-start/module-configuration-file.md#配置文件标签)）。例如下图使用DevEco Studio构建App时，工程中包含了两个HSP包library和library1，此时打包APP包失败。

![alt text](figures/zh_cn_packing_tool_image_10012017_01.png)

2. HSP包在`module.json5`中配置了`dependencies`。

![alt text](figures/zh_cn_packing_tool_image_10012017_02.png)

**处理步骤**

1. 检查打包文件，确保打包shared类型的App包，HSP包不超过一个。
2. 检查打包文件，删除HSP包`module.json5`配置的`dependencies`。

### 10012022 校验Stage HSP失败
**错误信息**

Verify stage hsp info failed.

**错误描述**

打包HSP时，校验Stage类型HSP包失败。

**可能原因**

以下配置项可能存在错误，请检查`module.json`、`config.json`、`app.json5`是否配置正确:
1. `asanEnabled`配置出错。
2. `hwasanEnabled`配置出错。
3. `atomicService`配置出错。
4. `continueBundleName`配置出错。
5. overlay配置出错。

**处理步骤**

1. 参考[asanEnabled配置错误](#10012004-检查参数asanenabled失败)。
2. 参考[hwasanEnabled配置出错](#10012005-检查参数hwasanenabled失败)。
3. 参考[atomicService配置出错](#10012006-检查atomicservice失败)。
4. 参考[continueBundleName配置出错](#10012007-检查continuebundlename无效)。
5. 参考[检查overlay失败](#10012008-检查overlay失败)。

### 10012024 校验元服务大小失败
**错误信息**

Check atomicService size failed.

**错误描述**

打包App时，检查元服务包的大小超出了2MB。

**可能原因**

元服务包及依赖的共享库或资源文件大小超出了2MB的限制。

**处理步骤**

优化并减少包的大小，例如删除不必要的资源、精简代码或减少依赖。

### 10013006 检查entry模块中的ability失败
**错误信息**

check entry module at least one ability failed.

**错误描述**

Entry类型包中没有ability。

**可能原因**

Entry类型包中不存在ability，该错误可能是由于`module.json5`未配置`abilities`或者`abilities`配置为空引起。

![alt text](figures/zh_cn_packing_tool_image_10013006_01.png)

![alt text](figures/zh_cn_packing_tool_image_10013006_02.png)

**处理步骤**

检查`module.json5`，确保Entry类型包`abilities`正确配置了ability。

### 10013007 检查installationFree错误
**错误信息**

Check module atomicService installationFree invalid.

**错误描述**

打包HAP/HSP时，检查`atomicService`和`installationFree`配置出错。

**可能原因**

1. `bundleType`配置了无效值。
2. 当`bundleType`为shared时，`installationFree`未设置为false。
3. 当`installationFree`为true时，`bundleType`未设置为atomicService。

**处理步骤**

1. 检查`app.json5`，确保`bundleType`设置为app，atomicService，shared，appService之一。
2. 如果`bundleType`为shared，确保`module.json5`中`installationFree`设置为false。
3. 如果`installationFree`为true，确保`app.json5`中`bundleType`设置为atomicService。

### 10014001 未找到可用文件
**错误信息**

File available not found exception.

**错误描述**

使用打包工具打包时，需要打包的文件不可使用。

**可能原因**

1. 指定的文件路径错误或文件不存在。
2. 文件正在被其他程序占用。
3. 当前用户没有访问该文件的权限。

**处理步骤**

1. 确认提供的文件路径正确，并检查该文件是否存在。
2. 如果文件被占用，关闭可能正在使用该文件的程序或进程。
3. 检查并调整文件的访问权限，例如当前用户可以读取、修改、删除文件。

### 10016003 检查分发策略交集错误
**错误信息**

Check two distroFilter policy disjoint invalid.

**错误描述**

构建App包时，如果工程中存在多个Entry类型模块，并且这些 Entry 配置的`deviceTypes`存在交集时，检查其分发策略错误。

**可能原因**

1. 分发策略`policy`和`value`标签为空，或无效值。

**处理步骤**

1. 检查分发策略相关配置，确保`policy`的值为`include`或`exclude`，`value`为支持的取值，详细请参见[distributionFilter标签](../../application-dev/quick-start/module-configuration-file.md#distributionfilter标签)。

### 10016006 检查HAP包无效
**错误信息**

Verify hap info is invalid.

**错误描述**

构建App包时，校验用于打包的HAP/HSP失败。

**可能原因**

1. HAP文件路径有错。
2. 不同HAP包的App配置不一致。
3. FA模型`packageName`重复。
4. 存在无效的模块依赖。
5. 元服务应用预加载失败。
6. 目标模块缺失。
7. 不同HAP使用的编译sdk版本不一致。

**处理步骤**

1. 检查打包参数传入HAP的路径是否正确。
2. 检查各HAP中App的配置是否一致。
3. 检查`config.json`，避免`packageName`重复。
4. 检查打包模块中是否存在循坏依赖或无效的依赖项。
5. 检查元服务预加载模块是否存在，且非当前模块自身。
6. 检查所有目标模块是否均存在。
7. 统一各个HAP包编译sdk版本。

### 10016007 检查entry模块无效
**错误信息**

Check entry module invalid.

**错误描述**

构建App包时，当工程中存在多个Entry类型HAP时，配置检查失败。

**可能原因**

多个Entry类型HAP配置的deviceType以及distroFilter存在交集，不符合HAP唯一性校验规则。

**处理步骤**

参考[HAP唯一性校验](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-hvigor-verification-rule-V5)，调整工程中的Entry类型HAP配置。

### 10016009 检查依赖错误
**错误信息**

Check dependency list is invalid.

**错误描述**

构建App包时，模块依赖关系检查失败。

**可能原因**

1. 存在循环依赖
    例如：模块library依赖了library1，library1依赖了library，则这两个模块之间构成循环依赖。

   ![alt text](figures/zh_cn_packing_tool_image_10016009_01.png)

   ![alt text](figures/zh_cn_packing_tool_image_10016009_02.png)

2. 依赖的模块类型为entry或feature。

**处理步骤**

1. 检查不同模块`module.json5`中`dependencies`的配置，删除循环依赖，确保App中不存在循环依赖。
2. 检查不同模块`module.json5`中`dependencies`的配置，删除对entry或feature类型上配置的依赖。

### 10016010 检查元服务无效
**错误信息**

Check atomicservice is invalid.

**错误描述**

构建App包时，检查元服务无效。

**可能原因**

元服务预加载模块无效。

**处理步骤**

检查`module.json5`中元服务预加载模块是否有效（参考[atomicservice标签](../../application-dev/quick-start/module-configuration-file.md#atomicservice标签)），不能配置自身moduleName，且必须有对应的模块，取值为长度不超过31字节的字符串。

### 10016011 检查元服务预加载无效
**错误信息**

Atomicservice preloads is invalid.

**错误描述**

构建App包时，检查元服务预加载的模块无效。

**可能原因**

1. 元服务预加载配置了重复模块。
2. 元服务预加载配置了不存在的模块。
3. 元服务预加载了配置了自身。

**处理步骤**

检查`module.json5`中元服务预加载模块是否有效（参考[atomicservice标签](../../application-dev/quick-start/module-configuration-file.md#atomicservice标签)），确保没有配置重复的模块，所有配置的模块都存在，并且不能配置自身的moduleName。

### 10016012 目标模块不存在
**错误信息**

TargetModuleName is not exist.

**错误描述**

构建App时，模块中配置了目标模块，但检查时未在打包文件或工程中找到该模块。

**可能原因**

打包文件或工程中缺少匹配的目标模块。

**处理步骤**

检查目标模块是否存在于打包文件或工程中，确保其正确配置（详细请参见[abilities标签](../../application-dev/quick-start/module-configuration-file.md#abilities标签)及targetModuleName属性），必要时创建目标模块。

### 10016014 代理数据不唯一
**错误信息**

Proxy data uri is not unique.

**错误描述**

数据代理uri不唯一，存在重复项。

**可能原因**

数据代理配置的uri存在重复。

**处理步骤**

检查`module.json5`文件，删除`proxyData`中重复的uri，确保每个uri都是唯一的（详细请参见[proxyData](../../application-dev/quick-start/module-configuration-file.md#proxydata标签)标签）。

### 10016015 ContinueType配置无效
**错误信息**

Check continueType is invalid.

**错误描述**

构建App时，检查continueType配置错误。

**可能原因**

1. `module.json5`不同的ability存在重复的`continueType`配置项。
2. 不同的module中同时存在重复的`deviceType`配置项和`continueType`配置项。

**处理步骤**

检查`module.json5`，删除`continueType`或`deviceType`重复的配置项。

### 10016016 文件大小检查错误
**错误信息**

Check file size failed.

**错误描述**

构建元服务类型App时，检查单个包大小超过2MB。

**可能原因**

单个包大小超过2MB，超出限制。

**处理步骤**

优化并减少对应单个包文件的大小，例如删除不必要的资源、精简代码或压缩文件。

### 10016018 元服务模块大小检查错误
**错误信息**

Check the atomicService module size failed.

**错误描述**

构建元服务类型App时，检查单个包和其依赖的共享库大小超过2MB。

**可能原因**

单个包和其依赖的共享库总大小超过2MB，超出限制。

**处理步骤**

优化并减少相应包的大小，例如删除不必要的资源、精简代码或减少依赖项。

### 10016019 检查分发策略无效
**错误信息**

Check the entry module distributionFilter is invalid.

**错误描述**

检查Entry类型模块分发策略错误。

**可能原因**

工程中Entry类型模块分发策略配置存在错误。

**处理步骤**

检查Entry模块分发策略是否正确配置，例如`policy`的值应为`exclude`或`include`，参考[distributionFilter标签](../../application-dev/quick-start/module-configuration-file.md#distributionfilter标签)。
