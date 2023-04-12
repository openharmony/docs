# restool工具


## 简介

restool（资源编译工具）是一种资源构建工具。通过编译资源文件创建资源索引、解析资源。restool保存在sdk安装目录下的toolchains子目录。

## 参数说明

restool当前支持以下命令选项:

| 选项 | 是否可缺省 | 是否存在入参 | 描述 |
| -------- | -------- | -------- | -------- |
| -i | 不可缺省 | 带参数 | 指定需要构建的资源目录或者需要构建的资源中间文件目录。同一个命令可以多次指定。 |
| -j | 不可缺省 | 带参数 | 指定config.json或者module.json文件路径。 |
| -o | 不可缺省 | 带参数 | 指定已编译资源的输出路径。 |
| -p | 不可缺省 | 带参数 | 指定编译资源的bundle名称。 |
| -r | 不可缺省 | 带参数 | 指定资源的头文件路径，有三种格式：“.txt”、“.js”、“.h”。 |
| -e | 可缺省 | 带参数 | 指定生成资源的起始ID值，例如：0x01000000,范围[0x01000000, 0x06FFFFFF),[0x08000000, 0x41FFFFFF) |
| -f | 可缺省 | 不带参数 | 如果输出路径已经存在。强制删除，重新生成。 |
| -h | 可缺省 | 不带参数 | 查看工具帮助信息。 |
| -m | 可缺省 | 带参数 | 多模块联合编译时，指定多个模块名。用“，”连接。 |
| -x | 可缺省 | 带参数 | 指定生成中间文件的资源目录或单个资源路径。同一个命令可以多次指定。 |
| -z | 可缺省 | 不带参数 | 针对资源终将文件目录，生成编译结果。 |
| -v | 可缺省 | 不带参数 | 查看工具版本号。 |
| --ids | 可缺省 | 带参数 | 指定生成id_defined.json的输出目录。 |
| --defined-ids | 可缺省 | 带参数 | 指定id_defined.json文件路径，一般都是通过--ids生成。<br>id_defined.json包含资源类型、名称及其ID的列表。<br>开发者可以自定义id_defined.json中的资源ID。 |

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
|    |----config.json/module.json
```

构建资源全量命令：

```
restool -i entry/src/main  -j entry/src/main/module.json -p com.ohos.demo -o out -r out/ResourceTable.txt -f
```

构建资源增量命令(仅预览模式可用)，具体步骤如下：

1.生成资源中间件:
```
restool -x entry/src/main/resource -o out
```
2.编译中间件:
```
restool -i out1 -i out2 -o out -p com.ohos.demo -r out/ResourceTable.txt -j entry/src/main/module.json -f -z
```

固定资源ID的方式有两种，如下：

方式一：在resource/base/element/目录下存放自定义id_defined.json文件。构建成功后，生成的ID值将会和id_defined.json文件中自定义的ID值保持一致。

方式二：通过--ids 命令生成id_defined.json文件。--defined-ids命令指定id_defined.json文件。构建成功后，生成的ID值将会和id_defined.json文件中自定义的ID值保持一致。

生成id_defined.json文件：
```
restool -i entry/src/main  -j entry/src/main/module.json -p com.ohos.demo -o out -r out/ResourceTable.txt --ids out/id_defined.json -f
```

指定资源ID固定的id_defined.json文件：
```
restool -i entry/src/main  -j entry/src/main/module.json -p com.ohos.demo -o out1 -r out1/ResourceTable.txt --defined-ids out/id_defined.json -f
```