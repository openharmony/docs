# 打包工具


打包工具是OpenHarmony提供的一种调测工具，支持通过命令行的方式生成HAP、将多个HAP打包为App Pack（Application Package），或将多个HAP和App Pack打包为App Pack。App Pack为应用市场上架时所需的包格式。


打包所用的app_packing_tool.jar，可以在本地下载的OpenHarmony的SDK库中找到。


- 打包为HAP
  Stage模型打包命令如下：

  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --json-path <option> --resources-path <option> --ets-path <option> --index-path <option> --pack-info-path <option> --out-path <option> --force <option>
  ```

  FA模型打包命令如下：

  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --json-path <option> --maple-so-path <option>  --profile-path <option> --maple-so-dir <option> --dex-path <option> --lib-path <option> --resources-path <option> --index-path <option> --out-path <option> --force <option>
  ```

  命令参数含义及规范请见下表。

  | 指令 | 是否必选项 | 描述 |
  | -------- | -------- | -------- |
  | --mode | 是 | 打包类型，此处为hap。 |
  | --json-path | 是 | .json文件路径，FA模型文件名必须为config.json；stage模型文件名必须为module.json5。 |
  | --profile-path | 否 | CAPABILITY.profile文件路径 |
  | --maple-so-path | 否 | maple&nbsp;so文件输入路径，so文件路径，文件名必须以.so为后缀。如果是多个so需要用"，"分隔。 |
  | --maple-so-dir | 否 | maple&nbsp;so目录输入路径。 |
  | --dex-path | 否 | 1.dex文件路径，文件名必须以.dex为后缀。如果是多个dex需要用"，"分隔。<br/>2.dex文件路径也可以为目录。 |
  | --lib-path | 否 | lib库文件路径。 |
  | --resources-path | 否 | resources资源包路径。 |
  | --index-path | 否 | .index文件路径，文件名必须为resources.index。 |
  | --pack-info-path | 否 | pack.info文件路径，文件名必须为pack.info。 |
  | --rpcid-path | 否 | rpcid.sc文件路径，文件名必须为rpcid.sc。 |
  | --js-path | 否 | 存放js文件目录路径，仅stage模型生效。 |
  | --ets-path | 否 | 存放ets文件的目录路径，仅stage模型生效。 |
  | --out-path | 是 | 目标文件路径，文件名必须以.hap为后缀。 |
  | --force | 否 | 默认值为false，如果为true,表示当目标文件存在时，强制删除。 |

- 将多个HAP打包为APP包
  命令如下：

  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --hap-path <option>  --out-path <option> --signature-path <option> --certificate-path <option>  --pack-info-path <option> --force <option>
  ```

  命令参数含义及规范请见下表。

  | 指令 | 是否必选项 | 描述 |
  | -------- | -------- | -------- |
  | --mode | 是 | 打包类型，此处为app。在将多个HAP打入同一个app时，需保证每个HAP的versionCode、versionName字段相同。 |
  | --hap-path | 是 | 1.HAP文件路径，文件名必须以.hap为后缀。如果是多个HAP需要用"，"分隔。<br/>2.HAP文件路径也可以是目录。 |
  | --pack-info-path | 是 | 文件名必须为pack.info。 |
  | --out-path | 是 | 目标文件路径，文件名必须以.app为后缀。 |
  | --signature-path | 否 | 签名路径。 |
  | --certificate-path | 否 | 证书路径，请参见[签名指导](../security/hapsigntool-guidelines.md)。 |
  | --force | 否 | 默认值为false，如果为true,表示当目标文件存在时，强制删除。 |

- 多个HAP或者多个APP打包为APP包
  命令如下：

  
  ```bash
  java -jar app_packing_tool.jar --mode <option> --hap-list <option> --app-list <option> --out-path <option>
  ```

  命令参数含义及规范请见下表。

  | 指令 | 是否必选项 | 描述 |
  | -------- | -------- | -------- |
  | --mode | 是 | 打包类型，此处为multiApp。在将多个HAP打入同一个APP时，需保证每个HAP满足合法性校验规则。 |
  | --hap-list | 否 | 1.HAP文件路径，文件名必须以.hap为后缀。如果是多个HAP需要用"，"分隔。<br/>2.HAP文件路径也可以是目录。 |
  | --app-list | 否 | 1.APP文件路径，文件名必须以.app为后缀。如果是多个APP包需要用"，"分隔。<br/>2.APP文件路径也可以是目录。<br/>3.--hap-list命令与--app-list不可以都不传。 |
  | --out-path | 是 | 目标文件路径，文件名必须以.app为后缀。 |
  | --force | 否 | 默认值为false，如果为true,表示当目标文件存在时，强制删除。 |

  多工程打包HAP合法性校验规则：

  - 需保证被打包的每个HAP在配置文件（请参见"[FA模型配置文件](../application-models/application-component-configuration-fa.md)"或 "[Stage模型配置文件](../application-models/application-component-configuration-stage.md)"）中配置的bundleName、versionCode、versionName、minCompatibleVersionCode、minAPIVersion,   targetAPIVersion , apiReleaseType等字段相同。
  - 每个HAP的moduleName唯一，同一设备Entry类型的HAP唯一。
  - 对于FA模型，还需要保证json文件中配置的package唯一。
