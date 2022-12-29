# 拆包工具


拆包工具是OpenHarmony提供的一种调测工具，支持通过命令行方式将HAP拆分为文件夹或者将App Pack（Application Package）拆分为HAP。


拆包所用的app_unpacking_tool.jar，可以在本地下载的OpenHarmony的SDK库中找到。


- HAP拆包命令
  
  ```bash
  java -jar app_unpacking_tool.jar --mode <option> --hap-path <option>  --out-path <option> --force <option>
  ```

  命令参数含义及规范请见下表。

  | 指令 | 是否必选项 | 描述 |
  | -------- | -------- | -------- |
  | --mode | 是 | 拆包类型，此处为hap。 |
  | --hap-path | 是 | HAP路径。 |
  | --rpcid | 否 | 是否单独将rpcid文件从HAP中提取到指定目录，如果为true，将仅提取rpcid文件，不对HAP进行拆包。 |
  | --out-path | 是 | 拆包目标文件路径。 |
  | --force | 否 | 默认值为false，如果为true,表示当目标文件存在时，强制删除。 |

- App包拆包命令
  
  ```bash
  java -jar app_unpacking_tool.jar --mode <option> --app-path <option>  --out-path <option> --force <option>
  ```

  命令参数含义及规范请见下表。

  | 指令 | 是否必选项 | 描述 |
  | -------- | -------- | -------- |
  | --mode | 是 | 拆包类型，此处为hap。 |
  | --app-path | 是 | app包路径。 |
  | --out-path | 是 | 拆包目标文件路径。 |
  | --force | 否 | 默认值为false，如果为true,表示当目标文件存在时，强制删除。 |

- 从HAP中获取rpcid文件命令
  
  ```bash
  java -jar app_unpacking_tool.jar --mode <option> --rpcid <option>  --hap-path <option> --out-path <option> --force <option>
  ```

  命令参数含义及规范请见下表。

  | 指令 | 是否必选项 | 描述 |
  | -------- | -------- | -------- |
  | --mode | 是 | 拆包类型，此处为hap。 |
  | --rpcid | 否 | 是否单独将rpcid文件从HAP中提取到指定目录，如果为true，将仅提取rpcid文件，不对HAP进行拆包。 |
  | --out-path | 是 | 拆包rpcid目标文件路径。 |
  | --hap-path | 是 | HAP路径。 |
