# restool工具


## 简介

restool是一种应用工程资源编译工具，通过编译资源文件创建资源索引、解析资源，开发者可以调用[资源管理接口](../reference/apis-localization-kit/js-apis-resource-manager.md)获取到对应资源。restool工具保存在sdk安装目录下的toolchains子目录。

## 参数说明

### restool支持的命令选项

| 选项 | 是否可缺省 | 是否存在入参 | 描述 |
| -------- | -------- | -------- | -------- |
| -i | 不可缺省 | 带参数 | 指定需要构建的资源目录或者资源中间件。<br>在资源目录中支持指定一个编译好的Hap资源目录（解压态），在此Hap的基础上完成叠加编译。<br>具体可参考如下[编译资源命令](#编译资源)。 |
| -j | 不可缺省 | 带参数 | 指定config.json或者module.json文件路径。 |
| -o | 不可缺省 | 带参数 | 指定已编译资源的输出路径。 |
| -p | 不可缺省 | 带参数 | 指定编译资源的bundle名称。 |
| -r | 不可缺省 | 带参数 | 指定资源的头文件路径，有三种格式：“.txt”、“.js”、“.h”。 |
| -e | 可缺省 | 带参数 | 指定生成资源的起始ID值，例如：0x01000000,范围[0x01000000, 0x06FFFFFF),[0x08000000, 0x41FFFFFF)。 |
| -f | 可缺省 | 不带参数 | 如果输出路径已经存在。强制删除，重新生成。 |
| -h | 可缺省 | 不带参数 | 查看工具帮助信息。 |
| -m | 可缺省 | 带参数 | 多模块联合编译时，指定多个模块名。用“，”连接。 |
| -x | 可缺省 | 带参数 | 指定生成中间文件的资源目录或单个资源路径。同一个命令可以多次指定。 |
| -z | 可缺省 | 不带参数 | 针对资源中间文件目录，生成编译结果。 |
| -v | 可缺省 | 不带参数 | 查看工具版本号。 |
| --ids | 可缺省 | 带参数 | 指定生成id_defined.json的输出目录。 |
| --defined-ids | 可缺省 | 带参数 | 指定id_defined.json文件路径，一般都是通过--ids生成。<br>id_defined.json包含资源类型、名称及其ID的列表。<br>开发者可以自定义id_defined.json中的资源ID。 |
| --icon-check | 可缺省 | 不带参数 | 开启icon和startWindowIcon的PNG图片校验功能。 |
| --thread | 可缺省 | 带参数 | 指定资源编译时开启的子线程数量。 |
| --target-config | 可缺省 | 带参数 | 与“-i”命令同时使用，支持选择编译。<br>具体可参考如下**target-config参数说明**。|
| --ignored-file | 可缺省 | 带参数 | 指定资源编译时文件和文件夹的忽略规则，格式为正则表达式，多个规则之间以“:”分隔。例如：“\\.git:\\.svn”表示忽略名称为“.git”、“.svn”的文件和文件夹。|

**target-config参数说明**

支持参数配置类型：MccMnc、Locale、Orientation、Device、ColorMode、Density。

参数格式说明：配置之间用“;”分割，配置中的值用“[]”封装，并使用“,”分割。

MccMnc匹配规则：Mcc（国家码）必须相同；Mnc（网络码）不存在时默认匹配，否则Mnc须相同才匹配。

Locale匹配规则：Locale匹配需满足以下三条规则。

1、语言须相同。

2、脚本（文字）不存在时默认匹配，否则必须相同。

3、国家或地区不存在时默认匹配，否则必须相同。

参数举例说明：Locale[zh_CN,en_US];Device[phone]，该参数过滤其他语言，保留能匹配上zh_CN和en_US的语言；过滤其他设备，保留phone；其他参数（如MccMnc、Orientation等）配置不过滤均保留。

### restool支持的子命令

| 命令  | 描述 |
| ---  | ---- |
| dump | 以json的格式输出hap包中resource的内容。 |

**dump命令**

```
restool dump [-h] [config] filePath
```

dump命令参数列表：

| 参数 | 是否可缺省 | 是否存在入参 | 描述 |
| --- | --------- | ---------- |------- |
| -h  | 可缺省 | 不带参数 | 帮助信息。 |
| config | 可缺省 | 不带参数 | 只打印hap包中资源的限定词信息。 |

示例：

```sh
# 打印hap包中所有的资源信息
restool dump entry.hap
# 打印hap包中资源的限定词信息
restool dump config entry.hap
```

## 使用实例

例如：entry目录结构如下
```
entry/src/main
|    |----resource
|    |    |----base
|    |    |    |----element
|    |    |    |----media
|    |    |    |----profile
|    |    |----rawfile
|    |    |----resfile
|    |----config.json/module.json
```

### 编译资源

编译资源的方式有三种，分别是全量资源编译、增量资源编译和叠加资源编译。其中增量编译仅预览模式可用，用于预览开发阶段的组件效果；全量编译用于构建工程的资源文件；叠加编译支持将工程中的资源叠加进已有的Hap模板资源中，复用已编译的资源项。

1、全量资源编译，命令如下：

```
restool -i entry/src/main -j entry/src/main/module.json -p com.ohos.demo -o out -r out/ResourceTable.txt -f
```

2、增量资源编译，具体步骤如下：

步骤一：生成资源中间件，命令如下:

```
restool -x entry/src/main/resource -o out
```
步骤二：编译资源中间件，命令如下:

```
restool -i out1 -i out2 -o out -p com.ohos.demo -r out/ResourceTable.txt -j entry/src/main/module.json -f -z
```

3、叠加资源编译，命令如下：

```
# hapResource为解压后的Hap包路径
restool -i entry/src/main -i hapResource -j entry/src/main/module.json -p com.ohos.demo -o out -r out/ResourceTable.txt -f
```

### 固定资源ID

固定资源ID，具体步骤如下：

步骤一：创建id_defined.json文件。创建方式有两种，分别是通过命令行和自定义。

+ 方式一：通过命令行生成此文件，命令如下：

```
restool -i entry/src/main -j entry/src/main/module.json -p com.ohos.demo -o out -r out/ResourceTable.txt --ids out -f
```

+ 方式二：自定义文件，文件名必须是id_defined.json，文件内容如下：

```
{
    "record" :
    [
        {
            "id" : "0x01000000", // 资源需要固定的ID值
            "name" : "app_name", // 资源名称
            "type" : "string" // 资源类型
        }
    ]
}
```

步骤二：完成资源ID固定。完成固定的方式有两种，通过命令一完成固定或者将自定义的id_definded.json放在resource/base/element/目录下后通过命令二完成固定。

+ 命令一：
```
restool -i entry/src/main -j entry/src/main/module.json -p com.ohos.demo -o out1 -r out1/ResourceTable.txt --defined-ids out/id_defined.json -f
```

+ 命令二：
```
restool -i entry/src/main -j entry/src/main/module.json -p com.ohos.demo -o out1 -r out1/ResourceTable.txt  -f
```