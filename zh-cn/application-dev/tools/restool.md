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

例如，entry目录结构如下：
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

步骤二：完成资源ID固定。完成固定的方式有两种，通过命令一完成固定或者将自定义的id_defined.json放在resource/base/element/目录下后通过命令二完成固定。

+ 命令一：
```
restool -i entry/src/main -j entry/src/main/module.json -p com.ohos.demo -o out1 -r out1/ResourceTable.txt --defined-ids out/id_defined.json -f
```

+ 命令二：
```
restool -i entry/src/main -j entry/src/main/module.json -p com.ohos.demo -o out1 -r out1/ResourceTable.txt  -f
```
## restool工具错误码

### 11201001 加载依赖库失败

**错误信息**

Failed to load the library 'xxx.dll'.

**错误描述**

加载依赖库失败。

**可能原因**

1. 依赖库路径错误或路径无访问权限。
2. 三方依赖库未安装，或路径错误，或路径无访问权限。
3. 出现Windows系统报错，由于在用户环境变量和系统环境变量中，排在xxx.dll路径之前的路径文件无法被访问，导致加载依赖库时搜索环境变量错误。

**处理步骤**

1. 检查依赖库路径是否准确且有访问权限。
2. 按照错误信息提示安装缺失的三方依赖库，并保证三方依赖库路径准确且有访问权限。
3. 将SDK下的`xxx/openharmony/previewer/common/bin`路径及依赖库所在路径添加至环境变量Path的前两行，两者先后顺序无限制。

### 11203001 JSON文件打开失败

**错误信息**

Failed to open the JSON file 'xxx.json'.

**错误描述**

JSON文件打开失败。

**可能原因**

JSON文件路径错误，或无访问权限。

**处理步骤**

检查JSON文件路径是否准确且有访问权限。

### 11203002 JSON文件解析失败

**错误信息**

Failed to parse the JSON file: incorrect format.

**错误描述**

JSON文件格式错误，解析失败。

**可能原因**

JSON文件格式错误，如包含多余的逗号等。

**处理步骤**

检查JSON文件格式，可参考[JSON](https://www.json.org/json-zh.html)。

### 11203003 JSON节点的类型与预期不匹配

**错误信息**

The value type of node 'xxx' does not match. Expected type: xxx.

**错误描述**

JSON中`xxx`节点的类型错误。

**可能原因**

JSON中对应节点的类型错误，如预期类型是string，实际类型为number。

**处理步骤**

检查JSON中`xxx`节点的类型。

### 11203004 JSON中缺少必需节点

**错误信息**

The required node 'xxx' is missing.

**错误描述**

JSON中缺少必需的`xxx`节点。

**可能原因**

JSON中没有配置对应的必需节点，如`name`、`value`等。

**处理步骤**

检查JSON中是否缺少`xxx`节点。

### 11203005 JSON中存在空object或空数组

**错误信息**

The array or object node 'xxx' cannot be empty.

**错误描述**

JSON中`xxx`节点为空object或空数组。

**可能原因**

JSON中对应节点为空，如object配置为{}，或数组配置为[]。

**处理步骤**

检查JSON中`xxx`节点是否为空。

### 11203006 JSON中包含多个子节点

**错误信息**

The node 'xxx' in the JSON file can have only one member.

**错误描述**

JSON中`xxx`节点仅能包含一个子节点。

**可能原因**

JSON中对应节点包含了多个子节点。

**处理步骤**

检查`xxx`节点是否仅包含一个子节点。

### 11203007 无效的JSON节点名称

**错误信息**

Invalid node name 'xxx'. Valid values: ["boolean","color","float","id","intarray","integer","pattern","plural","strarray","string","symbol","theme"].

**错误描述**

无效的JSON节点名称`xxx`。

**可能原因**

JSON中对应节点的名称错误，不在指定的名称["boolean","color","float","id","intarray","integer","pattern","plural","strarray","string","symbol","theme"]范围内。

**处理步骤**

检查JSON中`xxx`节点的名称是否在指定的范围内。

### 11204001 创建文件失败

**错误信息**

Failed to create the directory or file 'xxx'.

**错误描述**

创建文件失败。

**可能原因**

文件路径错误，或无访问权限。

**处理步骤**

检查文件路径是否准确且有访问权限。

### 11204003 删除文件失败

**错误信息**

Failed to delete the directory or file 'xxx'.

**错误描述**

删除文件失败。

**可能原因**

文件路径错误，或无访问权限。

**处理步骤**

检查文件路径是否准确且有访问权限。

### 11204004 拷贝文件失败

**错误信息**

Failed to copy the file from 'xxx' to 'xxx'.

**错误描述**

拷贝文件失败。

**可能原因**

文件路径错误，或无访问权限。

**处理步骤**

检查文件路径是否准确且有访问权限。

### 11204005 打开文件失败

**错误信息**

Failed to open the file 'xxx'.

**错误描述**

打开文件失败。

**可能原因**

文件路径错误，或无访问权限。

**处理步骤**

检查文件路径是否准确且有访问权限。

### 11204006 读取文件失败

**错误信息**

Failed to read the file 'xxx'.

**错误描述**

读取文件失败。

**可能原因**

1. 文件路径错误，或无访问权限。
2. 文件内容为空。

**处理步骤**

1. 检查文件路径是否准确且有访问权限。
2. 检查文件内容是否为空。

### 11210001 未知命令选项

**错误信息**

Unknown option 'xxx'.

**错误描述**

未知命令选项。

**可能原因**

不支持对应命令选项。

**处理步骤**

检查命令是否准确，可使用-h查看命令帮助信息，输入正确的命令选项和参数。

### 11210002 选项缺少必需参数

**错误信息**

Option 'xxx' requires an argument.

**错误描述**

选项缺少必需的参数。

**可能原因**

选项缺少必需的参数，如-i/--inputPath没有指定输入路径。

**处理步骤**

检查命令是否准确，可使用-h查看命令帮助信息，输入正确的命令选项和参数。

### 11210003 无效参数

**错误信息**

Invalid argument value 'xxx'.

**错误描述**

无效的参数。

**可能原因**

命令选项均需带有前缀短划线`-`，选项对应的参数无短划线，若输入选项时遗漏了短划线，该选项将被当作参数处理，无法生效，如输入`restool inputPath`。

**处理步骤**

检查命令是否准确，可使用-h查看命令帮助信息，输入正确的命令选项和参数。

### 11210004 无效的输入路径

**错误信息**

Invalid input path 'xxx'.

**错误描述**

无效的输入路径。

**可能原因**

-i/--inputPath选项指定的路径参数错误，或无访问权限。

**处理步骤**

检查路径参数是否准确且有访问权限。

### 11210005 重复的输入路径

**错误信息**

Duplicated input path 'xxx'.

**错误描述**

重复的输入路径。

**可能原因**

多个-i/--inputPath选项指定了相同的输入路径。

**处理步骤**

检查-i/--inputPath选项指定的路径是否重复。

### 11210006 包名存在冲突

**错误信息**

The package names 'xxx' and 'xxx' conflict.

**错误描述**

包名存在冲突。

**可能原因**

多次指定了-p/--packageName选项。

**处理步骤**

检查是否多次指定-p/--packageName选项。

### 11210007 无效的输出路径

**错误信息**

Invalid output path 'xxx'.

**错误描述**

无效的输出路径。

**可能原因**

-o/--outputPath指定的输出路径不存在，或无访问权限。

**处理步骤**

检查路径参数是否准确且有访问权限。

### 11210008 输出路径存在冲突

**错误信息**

The output paths 'xxx' and 'xxx' conflict.

**错误描述**

输出路径存在冲突。

**可能原因**

多次指定了-o/--outputPath选项。

**处理步骤**

检查是否多次指定-o/--outputPath选项。

### 11210009 重复的资源头文件路径

**错误信息**

Duplicated resource header path 'xxx'.

**错误描述**

重复的资源头文件路径。

**可能原因**

多个-r/--resHeader选项指定了相同的资源头文件路径。

**处理步骤**

检查-r/--resHeader选项指定的资源头文件路径是否重复。

### 11210010 模块名称存在冲突

**错误信息**

The module names 'xxx' and 'xxx' conflict.

**错误描述**

模块名称存在冲突。

**可能原因**

多次指定了-m/--modules选项。

**处理步骤**

检查是否多次指定-m/--modules选项。

### 11210011 重复的模块名称

**错误信息**

Duplicated module name 'xxx'.

**错误描述**

重复的模块名称。

**可能原因**

-m/--modules选项指定了重复的模块名称，如`-m entry,entry`。

**处理步骤**

检查-m/--modules选项指定的模块名称是否重复。

### 11210012 应用配置文件存在冲突

**错误信息**

The paths 'xxx' and 'xxx' of the module.json (in the stage model) or config.json (in the FA model) file conflict.

**错误描述**

应用配置文件[module.json（Stage模型）](../quick-start/module-configuration-file.md)或[config.json（FA模型）](../quick-start/application-configuration-file-overview-fa.md)的路径存在冲突。

**可能原因**

多次指定了-j/--json选项。

**处理步骤**

检查是否多次指定-j/--json选项。

### 11210013 无效的资源起始id

**错误信息**

Invalid start ID 'xxx'. It is out of range.

**错误描述**

无效的资源起始id。

**可能原因**

通过-e/--startId指定的资源起始id不在指定范围内。

**处理步骤**

检查资源起始id是否在[0x01000000, 0x06FFFFFF) 或 [0x08000000, 0xFFFFFFFF)的范围内。

### 11210014 重复的增量资源文件路径

**错误信息**

Duplicated append path 'xxx'.

**错误描述**

重复的增量资源文件路径。

**可能原因**

多个-x/--append选项指定了相同的增量资源文件路径。

**处理步骤**

检查-x/--append指定的增量资源文件路径是否重复。

### 11210015 target-config存在冲突

**错误信息**

The target configurations 'xxx' and 'xxx' conflict.

**错误描述**

多个target-config选项指定的参数存在冲突。

**可能原因**

多次指定了--target-config选项。

**处理步骤**

检查是否多次指定--target-config选项。

### 11210016 无效的target-config

**错误信息**

Invalid target configuration argument 'xxx'. The argument format for option --target-config should be like 'Locale[zh_CN,en_US];Device[phone]'.

**错误描述**

无效的target-config参数。

**可能原因**

--target-config选项指定的参数格式错误。

**处理步骤**

检查--target-config选项对应参数格式是否准确，如：`Locale[zh_CN,en_US];Device[phone]`，具体格式信息可以参考[restool支持的命令选项](#restool支持的命令选项)中关于target-config的说明。

### 11210017 无效的系统资源id_defined.json路径

**错误信息**

Invalid system id_defined.json path 'xxx'.

**错误描述**

无效的系统资源id_defined.json路径。

**可能原因**

通过--defined-sysids指定的系统资源的id_defined.json路径错误或无访问权限。

**处理步骤**

检查系统资源的id_defined.json路径是否准确且有访问权限。

### 11210018 重复的系统资源id_defined.json路径

**错误信息**

Duplicated system id_defined.json path 'xxx'.

**错误描述**

--defined-sysids选项指定的文件路径重复。

**可能原因**

多个--defined-sysids选项指定了相同的系统资源id_defined.json路径。

**处理步骤**

检查--defined-sysids选项指定的系统资源id_defined.json文件路径是否重复。

### 11210019 compressed-config存在冲突

**错误信息**

The compression JSON paths 'xxx' and 'xxx' conflict.

**错误描述**

多个--compressed-config选项指定的参数存在冲突。

**可能原因**

多次指定了--compressed-config选项。

**处理步骤**

检查是否多次指定--compressed-config选项。

### 11210020 参数非ASCII值

**错误信息**

The argument value 'xxx' is not an ASCII value.

**错误描述**

参数非ASCII值。

**可能原因**

输入、输出路径等参数中存在中文或其他非ASCII字符。

**处理步骤**

检查参数中是否存在中文或者其他非ASCII字符。

### 11210021 选项之间存在互斥

**错误信息**

Options 'xxx' and 'xxx' cannot be used together.

**错误描述**

不能同时指定两个互斥的选项。

**可能原因**

同时指定了两个互斥的选项，如`-x`和`--target-config`。

**处理步骤**

检查命令是否准确，避免指定互斥的选项，可以使用-h查看命令帮助信息，输入正确的命令选项和参数。

### 11210022 包名为空

**错误信息**

The package name is empty. It should be specified with option -p/--packageName.

**错误描述**

包名为空。

**可能原因**

未指定-p/--packageName选项。

**处理步骤**

检查是否通过-p/--packageName选项指定包名。

### 11210023 资源头文件路径为空

**错误信息**

The resource header path (for example, ./ResourceTable.js, ./ResourceTable.h) is empty. It should be specified with option -r/--resHeader.

**错误描述**

资源头文件的路径为空。

**可能原因**

未通过-r/--resHeader选项指定资源头文件路径。

**处理步骤**

检查是否通过-r/--resHeader选项指定资源头文件路径。

### 11210024 dump命令缺少HAP包路径

**错误信息**

The HAP path of the resource dump command is missing.

**错误描述**

dump命令缺少HAP包路径。

**可能原因**

dump命令未指定HAP包路径。

**处理步骤**

检查dump命令是否指定HAP包路径，如：`restool dump xxx/entry.hap`。

### 11210025 dump命令指定的HAP包路径无效

**错误信息**

Invalid HAP path 'xxx' in the resource dump command.

**错误描述**

dump命令指定HAP包路径无效。

**可能原因**

dump命令指定的HAP包路径错误或无访问权限。

**处理步骤**

检查dump命令指定的HAP包路径是否准确且有访问权限。

### 11210026 无效的子线程数量

**错误信息**

Invalid thread count 'xxx'. It should be an integer greater than 0.

**错误描述**

无效的子线程数量。

**可能原因**

--thread选项指定的子线程数量为负数或小数。

**处理步骤**

检查--thread选项的参数是否为大于0的整数。

### 11211001 输出路径已存在

**错误信息**

The output path exists. Specify option -f/--forceWrite to overwrite.

**错误描述**

输出路径已存在。

**可能原因**

通过-o/--output指定的输出路径下已存在文件，无法直接覆盖。

**处理步骤**

检查输出路径下是否已有文件，可手动删除或指定-f/--forceWrite选项强制覆盖。

### 11211002 缺少模块配置文件路径

**错误信息**

There are multiple input paths, but the path of the module.json (in the stage model) or config.json (in the FA model) file is not specified with option -j/--json.

**错误描述**

缺少应用配置文件[module.json（Stage模型）](../quick-start/module-configuration-file.md)或[config.json（FA模型）](../quick-start/application-configuration-file-overview-fa.md)的路径。

**可能原因**

当通过-i/--inputPath仅指定了单个输入路径时，restool默认从输入路径的父目录读取应用配置文件；当指定了多个输入路径时，如`restool -i xxx\AppScope -i xxx\entry\main`，需要通过-j/--json明确指定应用配置文件的路径。

**处理步骤**

检查是否通过-j/--json明确指定应用配置文件路径。

### 11211003 无效的模块类型

**错误信息**

Invalid module type 'xxx'. Valid values: ["entry", "har", "shared", "feature"].

**错误描述**

无效的模块类型。

**可能原因**

应用配置文件[module.json（Stage模型）](../quick-start/module-configuration-file.md)或[config.json（FA模型）](../quick-start/application-configuration-file-overview-fa.md)中指定的模块类型错误，取值不在["entry", "har", "shared", "feature"]范围内。

**处理步骤**

检查模块类型是否在指定的范围内。

### 11211004 资源起始id与id_defined.json存在冲突

**错误信息**

The start ID 'xxx' specified by option -e/--startId conflict with the IDs in the id_defined.json file.

**错误描述**

通过-e/--startId指定的资源起始id与id_defined.json文件存在冲突。

**可能原因**

默认情况下，资源起始id为`0x01000000`，编译时资源id依次递增，同时restool提供了两种方式自定义资源id：
1. 选项-e/--startId：可以在[0x01000000, 0x06FFFFFF) 或 [0x08000000, 0xFFFFFFFF)的范围内指定资源起始id。
2. [固定资源ID](#固定资源id)：通过id_defined.json文件指定资源id。

若同时使用两种方式，可能导致同一个资源在两种方式下计算得到的资源id值不一致，存在冲突。

**处理步骤**

检查是否同时使用上述两种方式自定义资源id。

### 11211007 id_defined.json中的资源类型无效

**错误信息**

Invalid resource type 'xxx' in the id_defined.json file. Valid values: ["boolean","color","float","id","intarray","integer","pattern","plural","strarray","string","symbol","theme"].

**错误描述**

id_defined.json中的资源类型无效。

**可能原因**

id_defined.json中资源类型type的取值不在["boolean","color","float","id","intarray","integer","pattern","plural","strarray","string","symbol","theme"]范围内。

**处理步骤**

检查资源类型是否在指定范围内。

### 11211008 id_defined.json中的资源id无效

**错误信息**

Invalid ID value 'xxx' in the id_defined.json file. It should be a hexadecimal string, match the pattern ^0[xX][0-9a-fA-F]{8}, and be in the scope [0x01000000,0x06FFFFFF] or [0x08000000,0xFFFFFFFF].

**错误描述**

id_defined.json中资源id无效。

**可能原因**

1. id_defined.json中资源id非十六进制数。
2. id取值不在[0x01000000,0x06FFFFFF] 或 [0x08000000,0xFFFFFFFF]的范围内。

**处理步骤**

检查资源id是否为十六进制格式且取值在[0x01000000,0x06FFFFFF] 或 [0x08000000,0xFFFFFFFF]范围内。

<!--Del-->
### 11211010 id_defined.json中的资源顺序无效

**错误信息**

The order value 'xxx' in the id_defined.json file does not match the record element sequence 'xxx'. Expected value: xxx.

**错误描述**

id_defined.json中资源的order属性值与资源在`record`数组中的声明顺序不一致。

**可能原因**

id_defined.json中资源的order属性值错误，如下错误示例：

```
{
    "startId": "0x07800000",
    "record": [
        {
            "type": "color",
            "name": "ohos_id_color_foreground",
            "order": 0
        },
        {
            "type": "color",
            "name": "ohos_id_color_foreground_dark",
            "order": 2
        }
    ]
}
```

其中声明了两个资源，数组`record`的下标从0开始，第二个资源`ohos_id_color_foreground_dark`在数组中的下标为1，对应order的值也应该为1。

**处理步骤**

检查资源order属性值与资源在数组中的声明顺序是否一致。
<!--DelEnd-->

### 11211012 id_defined.json定义了重复的id

**错误信息**

The names 'xxx' and 'xxx' in the id_defined.json file define the same ID.

**错误描述**

id_defined.json中两个资源定义了同一个资源id值。

**可能原因**

id_defined.json中两个资源定义了同一个资源id值。

**处理步骤**

检查id_defined.json中的资源id是否唯一且取值在[0x01000000,0x06FFFFFF] 或 [0x08000000,0xFFFFFFFF]范围内。

### 11211014 错误的模块名称

**错误信息**

The module name 'xxx' is not found in ["yyy","zzz"], which is specified by -m/--modules.

**错误描述**

应用配置文件中的模块名称不在-m/--modules指定的模块名称列表内。

**可能原因**

1. -m/--modules指定的模块名称列表错误。
2. 应用配置文件[module.json（Stage模型）](../quick-start/module-configuration-file.md)或[config.json（FA模型）](../quick-start/application-configuration-file-overview-fa.md)中name指定的模块名称错误。

**处理步骤**

检查-m/--modules指定的模块名称列表中是否包含应用配置文件中name指定的模块名称。

### 11211101 无效的资源文件

**错误信息**

Failed to scan resources: invalid path 'xxx'.

**错误描述**

扫描资源失败，无效的资源文件。

**可能原因**

资源文件不符合要求，比如：
1. rawfile应该是一个文件夹，实际是文件。
2. base/element下应该都是JSON文件，实际存在文件夹。

**处理步骤**

检查资源文件的类型是否正确，可参考[资源分类与访问-资源分类](../quick-start/resource-categories-and-access.md#资源分类)中关于各类资源文件的说明。

### 11211103 无效的限定词目录

**错误信息**

Invalid qualifier key 'xxx'. It should match the pattern of the qualifiers directory, for example zh_CN or en_US.

**错误描述**

无效的限定词目录。

**可能原因**

限定词目录名称错误。

**处理步骤**

检查限定词目录名称是否准确，限定词目录命名规则可参考[资源分类与访问-限定词目录](../quick-start/resource-categories-and-access.md#资源目录)。

### 11211104 无效的资源组目录

**错误信息**

Invalid resource directory name 'xxx'. Valid values: ["element","media","profile"].

**错误描述**

无效的资源组目录名称。

**可能原因**

限定词目录下的资源组目录名称错误，不在["element","media","profile"]范围内。

**处理步骤**

检查限定词目录下是否仅包含[资源组目录](../quick-start/resource-categories-and-access.md#资源组目录)：`element`，`media`和`profile`。

### 11211106 无效的翻译状态

**错误信息**

Invalid translation priority value 'xxx'. Valid values: ["code","translate","LT","customer"].

**错误描述**

无效的翻译状态。

**可能原因**

字符串或[单复数](../../application-dev/internationalization/l10n-singular-plural.md)资源的可翻译属性attr下的翻译状态属性priority配置错误，不在["code","translate","LT","customer"]范围内。

**处理步骤**

检查翻译状态priority的值是否准确，可参考[资源可翻译特性](../quick-start/resource-categories-and-access.md#资源可翻译特性)中关于priority的说明。

### 11211107 不支持的element资源类型

**错误信息**

Unsupported element resource type 'xxx'. Valid values: ["integer","string","strarray","intarray","boolean","color","theme","plural","float","pattern","symbol"].

**错误描述**

不支持的element资源类型。

**可能原因**

element目录下json资源文件支持的资源类型为["integer","string","strarray","intarray","boolean","color","theme","plural","float","pattern","symbol"]，不支持"id"。

**处理步骤**

检查element资源的类型是否准确，可参考[资源组目录](../quick-start/resource-categories-and-access.md#资源组目录)中关于element资源的说明。

### 11211108 无效的颜色值

**错误信息**

Invalid color value 'xxx' of the resource 'xxx'. It can only reference '$color:xxx' or be '#rgb', '#argb', '#rrggbb', or '#aarrggbb'.

**错误描述**

无效的颜色值。

**可能原因**

color资源只支持以下两种格式：
1. 引用其他color资源，如`$color:xxx`引用应用自身color资源，或`$ohos:color:xxx`引用系统color资源。
2. 以`#`开头的rgb颜色值格式，如`#rgb`,`#argb`,`#rrggbb`,`#aarrggbb`。

**处理步骤**

检查color资源是否为正确的引用格式或rgb格式。

### 11211109 无效的资源引用

**错误信息**

Invalid resource reference `$xxx:xxx`. Supported reference: `$(ohos:)?xxx:xxx`.

**错误描述**

无效的资源引用。

**可能原因**

资源引用只适用于同类型资源之间，如string.json中的字符串资源可以用`$string:xxx`引用应用自身的字符串资源，或使用`$ohos:string:xxx`引用系统字符串资源，但不能通过`$integer:xxx`引用整数资源。

**处理步骤**

检查资源引用方式是否正确。

### 11211110 theme资源的parent为空

**错误信息**

The parent value of resource 'xxx' is empty. It should be a valid resource name.

**错误描述**

theme资源的parent值为空。

**可能原因**

theme资源的parent属性是可选的，其值需配置为其他theme资源的名称，不能是空字符串。如下正确示例：
```
{
  "theme": [
    {
      "name": "base",
      "value": [
        {
          "name": "width",
          "value": "wrap_content"
        },
        {
          "name": "height",
          "value": "wrap_content"
        },
        {
          "name": "size",
          "value": "25dp"
        }
      ]
    },
    {
      "name": "child",
      "parent": "base",
      "value": [
        {
          "name": "noTitle",
          "value": "yes"
        }
      ]
    }
  ]
}
```
其中声明了两个theme资源`base`和`child`，`base`不包含parent属性，`child`的parent配置为"base"。

**处理步骤**

检查theme资源的parent是否为空，如无需parent属性，可以将其移除。

### 11211111 数组类型的资源超长

**错误信息**

The array resource 'xxx' is too large. The total length of the value of the array elements cannot exceed 65535.

**错误描述**

数组类型的资源超长。

**可能原因**

单个数组类型资源总长度超过了65535个字节。

**处理步骤**

检查数组类型资源是否超长，可以将其拆分为多个数组资源。

### 11211112 无效的单复数资源类别

**错误信息**

Invalid quantity 'xxx' of the plural resource 'xxx'. Valid values: ["zero","one","two","few","many","other"].

**错误描述**

无效的单复数资源类别。

**可能原因**

单复数资源的类别属性quantity配置错误，不在["zero","one","two","few","many","other"]范围内。

**处理步骤**

检查单复数的类别是否准确，可参考[支持单复数](../../application-dev/internationalization/l10n-singular-plural.md)中关于单复数类别的说明。

### 11211113 单复数资源的类别重复

**错误信息**

Duplicated quantity 'xxx' of the plural resource 'xxx'.

**错误描述**

单复数资源的类别重复。

**可能原因**

单复数资源中重复声明了相同的类别，如下错误示例中`eat_apple`重复声明了类别`one`：
```
{
  "plural": [
    {
      "name": "eat_apple",
      "value": [
        {
          "quantity": "one",
          "value": "%d apple"
        },
        {
          "quantity": "one",
          "value": "%d apple"
        },
        {
          "quantity": "other",
          "value": "%d apples"
        }
      ]
    }
  ]
}
```

**处理步骤**

检查单复数资源声明的类别是否重复，可参考[支持单复数](../../application-dev/internationalization/l10n-singular-plural.md)中关于单复数类别的说明。

### 11211114 单复数资源缺少other类别

**错误信息**

The plural resource 'xxx' should contain the 'other' quantity.

**错误描述**

单复数资源应该包含other类别。

**可能原因**

单复数资源缺少other类别的声明。

**处理步骤**

检查单复数资源是否包含other类别的声明，可参考[支持单复数](../../application-dev/internationalization/l10n-singular-plural.md)中关于单复数类别的说明。

### 11211115 无效的symbol资源

**错误信息**

Invalid value 'xxx' of the symbol resource 'xxx'. It should be in the scope [0xF0000,0xFFFFF] or [0x100000,0x10FFFF].

**错误描述**

无效的symbol资源值。

**可能原因**

symbol资源的值不在[0xF0000,0xFFFFF] 或 [0x100000,0x10FFFF]范围内。

**处理步骤**

检查symbol资源的值是否在指定范围内。

### 11211116 无效的资源名称

**错误信息**

Invalid resource name 'xxx'. It should match the pattern [a-zA-Z0-9_].

**错误描述**

无效的资源名称。

**可能原因**

资源名称需要与规则[a-zA-Z0-9_]匹配，只能包含大小写字母、数字和下划线。

**处理步骤**

检查资源名称与规则[a-zA-Z0-9_]是否匹配。

### 11211117 资源重复定义

**错误信息**

Resource 'xxx' conflict. It is first declared at 'xxx' and declared again at 'xxx'.

**错误描述**

资源重复定义。

**可能原因**

在多处定义了同类型同名的资源，存在冲突。

**处理步骤**

检查资源是否重复定义，可以修改资源名称或删除重复资源。

### 11211118 资源id超过最大值

**错误信息**

The resource ID 'xxx' exceeds the maximum ID 'xxx'.

**错误描述**

资源id超过最大值。

**可能原因**

应用资源id的范围为[0x01000000,0x06FFFFFF] 或 [0x08000000,0xFFFFFFFF]，资源过多，或指定了较大的资源起始id，可能导致id溢出超过最大值0x06FFFFFF 或 0xFFFFFFFF。

**处理步骤**

1. 删除无用资源。
2. 指定较小的资源起始id。

### 11211120 引用的资源未定义

**错误信息**

The resource reference '$xxx:xxx' is not defined.

**错误描述**

引用的资源未定义。

**可能原因**

1. 引用的资源不存在，如资源已被删除或重命名。
2. 引用的资源所在的目录未通过-i/--inputPath指定为输入路径。

**处理步骤**

1. 检查报错的资源是否存在。
2. 检查资源所在的`resources`的父目录是否通过-i/--inputPath指定为输入路径，如报错信息中的资源定义在`xxx/entry/src/main/resources/base/element/string.json`中，则需指定`xxx/entry/src/main`为输入路径。

### 11211124 解析resources.index文件失败

**错误信息**

Failed to parse the resources.index file.

**错误描述**

解析resources.index失败。

**可能原因**

resources.index格式不正确，如内容为空或文件开头不存在128字节的版本信息。

**处理步骤**

检查resources.index文件的来源，确保该文件是由restool工具编译生成。

### 11212001 解析HAP包错误

**错误信息**

Failed to parse the HAP.

**错误描述**

解析HAP包失败。

**可能原因**

HAP包格式不正确，如经过多次压缩导致解压失败。

**处理步骤**

检查HAP包格式，确保HAP包由SDK工具直接生成，无压缩解压等修改操作。