# 打包拆包工具
## 简介

打包工具和拆包工具，在程序编译完成后，对编译出的文件等进行打包，以供安装发布。打包工具支持应用程序包(hap)，上架应用市场的应用集合（app），快速修复包（hqf），上架应用市场的快速修复包集合（appqf），静态共享库（har），动态共享库（hsp）包的生成，拆包工具用于对hap，app，hqf，appqf，har，hsp包的拆包及对hap，hsp，app，appqf的解析。通常打包过程会在DevEco Studio中自动完成，但开发者也可根据需要通过打包工具的jar包进行打包，jar包通常存放在sdk路径下的toolchains目录中。

## 打包指令说明

### hap包模式打包指令

开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的hap包。

#### 示例

- Stage模型的打包命令示例：


```
java -jar app_packing_tool.jar --mode hap --json-path <option> --resources-path <option> --ets-path <option> --index-path <option> --pack-info-path <option> --out-path <option> --force true
```

- FA模型的打包命令示例：


```
java -jar app_packing_tool.jar --mode hap --json-path <option> --maple-so-path [option] --profile-path [option] --maple-so-dir [option] --dex-path [option] --lib-path [option] --resources-path [option] --index-path [option] --out-path <option> --force [option]
```

#### 参数含义及规范

| 指令               | 是否必选项 | 选项                   | 描述                                                        | 备注         |
|------------------|-------|----------------------|-----------------------------------------------------------|------------|
| --mode           | 是     | hap                  | 打包类型。                                                     | NA         |
| --json-path      | 是     | NA                   | .json文件路径，FA模型文件名必须为config.json；stage模型文件名必须为module.json。 | NA         |
| --profile-path   | 否     | NA                   | CAPABILITY.profile文件路径。                                   | NA         |
| --maple-so-path  | 否     | NA                   | maple so文件输入路径，so文件路径，文件名必须以.so为后缀。如果是多个so需要用“，”分隔。       | NA         |
| --maple-so-dir   | 否     | NA                   | maple so目录输入路径。                                           | NA         |
| --dex-path       | 否     | NA                   | 1.dex文件路径，文件名必须以.dex为后缀。如果是多个dex需要用“，”分隔。 <br/>2.dex文件路径也可以为目录。 | NA         |
| --lib-path       | 否     | NA                   | lib库文件路径。                                                 | NA         |
| --resources-path | 否     | NA                   | resources资源包路径。                                           | NA         |
| --index-path     | 否     | NA                   | .index文件路径，文件名必须为resources.index。                         | NA         |
| --pack-info-path | 否     | NA                   | pack.info文件路径，文件名必须为pack.info。                            | NA         |
| --rpcid-path     | 否     | NA                   | rpcid.sc文件路径，文件名必须为rpcid.sc。                              | NA         |
| --js-path        | 否     | NA                   | 存放js文件目录路径。                                               | 仅stage模型生效 |
| --ets-path       | 否     | NA                   | 存放ets文件目录路径。                                              | 仅stage模型生效 |
| --out-path       | 是     | NA                   | 目标文件路径，文件名必须以.hap为后缀。                                     | NA         |
| --force          | 否     | true或者false          | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                        | NA         |
| --an-path        | 否     | NA                   | 存放an文件的路径。                                                | 仅stage模型生效 |
| --ap-path        | 否     | NA                   | 存放ap文件的路径。                                                | 仅stage模型生效 |
| --dir-list       | 否     | NA                   | 可指定目标文件夹列表，将其打入hap包内。                              | NA         |

### har包模式打包指令

开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的har包。

#### 示例

```
java -jar app_packing_tool.jar --mode har --json-path [option] --jar-path [option]--lib-path [option] --resources-path [option] --out-path [option] --force [option]
```

#### 参数含义及规范

| 指令              | 是否必选项 | 选项          | 描述                                                        |
|-----------------|-------|-------------|-----------------------------------------------------------|
| --mode          | 是     | har         | 打包类型。                                                     |
| --json-path     | 是     | NA          | .json文件路径，FA模型文件名必须为config.json；stage模型文件名必须为module.json。 |
| --jar-path      | 否     | NA          | 1.jar文件路径，文件名必须以.jar为后缀。如果是多个jar需要用“，”分隔。<br/>2.jar文件路径也可以为目录。 |
| --lib-path      | 否     | NA          | lib库文件路径。                                                 |
| --resource-path | 是     | NA          | resources资源包路径。                                           |
| --out-path      | 是     | NA          | 目标文件路径，文件名必须以.har为后缀。                                     |
| --force         | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                        |

### app包模式打包指令

开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的app包。app包用于上架应用市场。


#### 示例

```
java -jar app_packing_tool.jar --mode app --hap-path <option> --hsp-path <option> --out-path <option> --signature-path [option] --certificate-path [option] --pack-info [option]--force [option]
```

#### 参数含义及规范

| 指令                 | 是否必选项 | 选项          | 描述                                                           |
|--------------------|-------|-------------|--------------------------------------------------------------|
| --mode             | 是     | app         | 多个hap需满足hap的合法性校验。                                           |
| --hap-path         | 是     | NA          | 1.hap包文件路径，文件名必须以.hap为后缀。如果是多个hap包需要用“，”分隔。<br/>2.hap包文件路径也可以是目录。 |
| --hsp-path         | 否     | NA          | 1.hsp包文件路径，文件名必须以.hsp为后缀。如果是多个hsp包需要用“，”分隔。<br/>2.hsp包文件路径也可以是目录。 |
| --pack-info-path   | 是     | NA          | 文件名必须为pack.info。                                             |
| --out-path         | 是     | NA          | 目标文件路径，文件名必须以.app为后缀。                                        |
| --signature-path   | 否     | NA          | 签名路径。                                                        |
| --certificate-path | 否     | NA          | 证书路径。                                                        |
| --force            | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                           |

#### 打包app时hap的合法性校验

在对工程内的hap包打包生成app包时，需要保证被打包的每个hap在json文件中配置的bundleName，versionCode，versionName，minCompatibleVersionCode，debug，minAPIVersion，targetAPIVersion，apiReleaseType相同，moduleName唯一，对于fa模型，还需要保证json文件中配置的package唯一。

### 多工程打包

多工程打包适用于多个团队开发同一个应用，但不方便共享代码的情况。开发者通过传入已经打好的hap、hsp和app包，将多个包打成一个最终的app包，并上架应用市场。

#### 示例

```
java -jar app_packing_tool.jar --mode multiApp --hap-list [option] --hsp-list [option] --app-list [option] --out-path <option>
```

#### 参数含义及规范

| 指令         | 是否必选项 | 选项        | 描述                                                                                                  |
|------------|-------|-----------|-----------------------------------------------------------------------------------------------------|
| --mode     | 是     | multiApp  | 打包类型，在将多个hap打入同一个app时，需保证每个hap满足合法性校验规则。                                                            |
| --hap-list | 否     | hap的路径    | 1.hap包文件路径，文件名必须以.hap为后缀。如果是多个hap包需要”，“分隔。<br/>2.hap文件路径也可以是目录。                                          |
| --hsp-list | 否     | hsp的路径    | 1.hsp包文件路径，文件名必须以.hsp为后缀。如果是多个hsp包需要”，“分隔。<br/>2.hsp文件路径也可以是目录。                                          |
| --app-list | 否     | app的路径    | 1.app文件路径，文件名必须以.app为后缀。如果是多个app包需要用”，“分隔。<br/>2.app文件路径也可以是目录。<br/>3.--hap-list，--hsp-list，--app-list不可以都不传。 |
| --out-path | 是     | NA | 目标文件路径，文件名必须以.hqf为后缀。 |
| --force    | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                                                                  |

#### 多工程打包hap合法性校验

需要保证被打包的每个hap在json文件中配置的bundleName，versionCode，versionName，minCompatibleVersionCode，debug属性相同，minAPIVersion，targetAPIVersion，apiReleaseType，compileSdkVersion，compileSdkType相同，moduleName唯一，同一设备entry唯一，对于fa模型，还需要保证json文件中配置的package唯一。

### hqf模式打包指令

hqf包适用于应用存在一些问题，需要紧急修复的场景。开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的hqf包。

#### 示例

```
java -jar app_packing_tool.jar --mode hqf --json-path <option> --lib-path <option> --ets-path <option> --out-path <option>
```

#### 参数含义及规范

| 指令          | 是否必选项 | 选项          | 描述                                 |
|-------------|-------|-------------|------------------------------------|
| --mode      | 是     | hqf         | 打包类型。                              |
| --json-path | 是     | NA          | .json文件路径，文件名必须为patch.json。        |
| --lib-path  | 否     | NA          | lib库文件的路径。                         |
| --ets-path  | 是     | NA          | 存放ets文件目录路径。                       |
| --out-path  | 是     | NA          | 目标文件路径，文件名必须以.hqf为后缀。              |
| --force     | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |

### appqf模式打包指令

appqf包由一个或多个hqf文件组成。这些hqf包在应用市场会从appqf包中拆分出来，再被分发到具体的设备上。开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的appqf包。

#### 示例

```
java -jar app_packing_tool.jar --mode appqf --hqf-list <option> --out-path <option>
```

#### 参数含义及规范

| 指令         | 是否必选项 | 选项          | 描述                                 |
|------------|-------|-------------|------------------------------------|
| --mode     | 是     | appqf       | 打包类型。                              |
| --hqf-list | 是     | NA          | hqf文件路径，多个hqf以英文逗号隔开。              |
| --out-path | 是     | NA          | 目标文件路径，文件名必须以.appqf为后缀。            |
| --force    | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。 |


### hsp模式打包指令

hsp包实现了多个hap对文件的共享，开发者可以使用打包工具的jar包对应用进行打包，通过传入打包选项、文件路径，生成所需的hsp包。

#### 示例
```
java -jar path\app_packing_tool.jar --mode hsp --json-path <option> --resources-path <option> --ets-path <option> --index-path <option> --pack-info-path <option> --out-path path\out\library.hsp --force true
```

#### 参数含义及规范

| 指令               | 是否必选项 | 选项          | 描述                                                        |
|------------------|-------|-------------|-----------------------------------------------------------|
| --mode           | 是     | hsp         | 打包类型。                                                     |
| --json-path      | 是     | NA          | .json文件路径，文件名必须为module.json。                              |
| --profile-path   | 否     | NA          | CAPABILITY.profile文件路径。                                   |
| --dex-path       | 否     | NA          | 1.dex文件路径，文件名必须以.dex为后缀。如果是多个dex需要用“，”分隔。<br/>2.dex文件路径也可以为目录。 |
| --lib-path       | 否     | NA          | lib库文件路径。                                                 |
| --resources-path | 否     | NA          | resources资源包路径。                                           |
| --index-path     | 否     | NA          | .index文件路径，文件名必须为resources.index。                         |
| --pack-info-path | 否     | NA          | pack.info文件路径，文件名必须为pack.info。                            |
| --js-path        | 否     | NA          | 存放js文件目录路径。                                               |
| --ets-path       | 否     | NA          | 存放ets文件目录路径。                                              |
| --out-path       | 是     | NA          | 目标文件路径，文件名必须以.hsp为后缀。                                     |
| --force          | 否     | true或者false | 默认值为false，如果为true，表示当目标文件存在时，强制删除。                        |