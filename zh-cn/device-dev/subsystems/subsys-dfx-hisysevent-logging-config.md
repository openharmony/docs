# HiSysEvent打点配置


## 概述


### 功能简介

组件若有HiSysEvent事件的打点需求，则需要先定义yaml文件并在bundle.json文件中[配置yaml文件的路径](subsys-dfx-hisysevent-logging-config.md#验证yaml文件)。OpenHarmony编译框架在编译过程中则会通过python编译脚本解析校验bundle.json文件指定的所有yaml文件。在解析校验之后，编译框架会将这些yaml文件中配置的信息汇总转换成名为hisysevent.zip文件。最后，将此zip文件打包到系统指定路径下，用作HiSysEvent事件落盘的判断依据。


### 基本概念

在配置HiSysEvent打点之前，开发者应了解以下基本概念：

- 事件领域 用于标识事件所属的领域，在yaml文件中以domain为键值指定，可参考yaml文件样例中的[domain](subsys-dfx-hisysevent-logging-config.md#编写yaml文件)。

- 事件名称 用于指定事件领域包含的所有事件，可参考yaml文件样例中的[EVENT_NAMEA/EVENT_NAMEB](subsys-dfx-hisysevent-logging-config.md#编写yaml文件)。

- 参数 用于定义某个事件名称包含的所有键值，可参考yaml文件样例中的[__BASE/NAME1/NAME2](subsys-dfx-hisysevent-logging-config.md#编写yaml文件)。


### 约束与限制

定义事件领域、事件名称及参数的约束与限制：

- 每个yaml文件只能有一个事件领域，且不能与其他yaml文件中定义的事件领域重名。

- 每个事件领域可定义零个或多个事件名称，同一个事件领域内部的事件名称不能重名。

- 每个事件名称可定义多个参数，同一个事件名称内部的参数不能重名，每个事件名称有且只有一个名称为__BASE的参数，此参数字段组成如表1，其它自定义参数，具体字段组成如表2。
    **表1** __BASE参数字段说明
  
  | 字段名称 | 描述 |
  | -------- | -------- |
  | type | 字段说明：必选字段，用来标识该事件名称的类型。<br/>取值范围：<br/>-&nbsp;FAULT：故障类型。<br/>-&nbsp;STATISTIC：统计类型。<br/>-&nbsp;SECURITY：安全类型。<br/>-&nbsp;BEHAVIOR：行为类型。 |
  | level | 字段说明：必选字段，用来标识该事件名称的级别。<br/>取值范围：<br/>-&nbsp;CRITICAL：严重。<br/>-&nbsp;MINOR：一般。 |
  | tag | 字段说明：可选字段，用来标识该事件名称的标签。<br/>定义规则：<br/>-&nbsp;最多可同时定义5个标签，标签之间使用空格来分隔。<br/>-&nbsp;单个标签最多包含16个字符，字符范围[a-zA-Z0-9]。 |
  | desc | 字段说明：必选字段，用来对该事件名称进行描述。<br/>定义规则：<br/>-&nbsp;至少包含3个字符，最多包含128个字符。 |
  | preserve | 字段说明：可选字段，用来标识事件是否需要落盘，默认值为true。<br/>取值范围：<br/>- true：事件需要落盘。<br/>- false：事件不需要落盘。 |

    **表2** 自定义参数字段说明
  
  | 字段名称 | 描述 |
  | -------- | -------- |
  | type | 字段说明：必选字段，用来标识该参数的类型。<br/>取值范围：<br/>-&nbsp;BOOL<br/>-&nbsp;INT8<br/>-&nbsp;UINT8<br/>-&nbsp;INT16<br/>-&nbsp;UINT16<br/>-&nbsp;INT32<br/>-&nbsp;UINT32<br/>-&nbsp;INT64<br/>-&nbsp;UINT64<br/>-&nbsp;FLOAT<br/>-&nbsp;DOUBLE<br/>-&nbsp;STRING |
  | arrsize | 字段作用：可选字段，用来标识数组类型参数的长度。<br/>取值范围：<br/>-&nbsp;1~100 |
  | desc | 字段作用：必选字段，用来对该参数进行描述。<br/>定义规则：<br/>-&nbsp;至少包含3个字符，最多包含128个字符。 |


## 开发步骤


### 编写yaml文件


**编写规则**

- 事件领域命名规则：
  - 字母开头，且只能由大写字母/数字/下划线组成；
  - 字符串长度取值范围为1~16。

- 事件名称命名规则：
  - 字母开头，且只能由大写字母/数字/下划线组成；
  - 字符串长度取值范围1~32；
  - 单个事件领域内部事件名称的不能超过4096个。

- 参数命名规则：
  - 字母开头，且只能由大写字母/数字/下划线组成；
  - 字符串长度取值范围1~48；
  - 单个事件名称内包含的参数的个数不能超过128个。


**编写样例**

- yaml文件样例指定的事件领域名称为MODULEA，该事件领域包含两个事件，名称分别是EVENT_NAMEA和EVENT_NAMEB。

- EVENT_NAMEA被定义成错误类型的严重事件，该事件包含类型为字符串类型的NAME1参数、字符串类型的NAME2参数及无符号短整型类型的NAME3参数，可以通过事件领域MODULEA和事件名称EVENT_NAMEA对其进行[实时订阅](../subsystems/subsys-dfx-hisysevent-listening.md)。

- EVENT_NAMEB被定义成统计类型的一般事件，EVENT_NAMEB包含类型为无符号短整型类型的NAME1参数及整型类型的NAME2参数。因为EVENT_NAMEB在__BASE参数中定义了名称为tag1和tag2的两个事件标签，所以不仅可以通过事件领域MODULEA和事件名称EVENT_NAMEB对其进行[实时订阅](../subsystems/subsys-dfx-hisysevent-listening.md)，所以还可以通过事件标签对该事件进行实时订阅。
  
  ```
  ##########################################
  # the hisysevent definition for module a #
  ##########################################
  
  domain: MODULEA
  
  EVENT_NAMEA:
      __BASE: {type: FAULT, level: CRITICAL, desc: event name a}
      NAME1: {type: STRING, desc: name1}
      NAME2: {type: STRING, desc: name2}
      NAME3: {type: UINT16, desc: name3}
  
  EVENT_NAMEB:
      __BASE: {type: STATISTIC, level: MINOR, tag: tag1 tag2, desc: event name b}
      NAME1: {type: UINT16, desc: name1}
      NAME2: {type: INT32, desc: name2}
  ```


### 验证yaml文件


**配置yaml文件路径**

在bundle.json文件中通过hisysevent_config属性完成yaml文件的路径指定：


```
{
    "name": "@ohos/moduel_a",
    "description": "module a",
    "version": "3.1",
    "license": "Apache License 2.0",
    "publishAs": "code-segment",
    "segment": {
        "destPath": "moduel_a_path"
    },
    "dirs": {},
    "scripts": {},
    "component": {
        "name": "hisysevent_native",
        "subsystem": "hiviewdfx",
        "adapted_system_type": [
            "standard"
        ],
        "rom": "",
        "ram": "",
        "hisysevent_config": [
            "//moduel_a_path/yaml_file1.yaml",
            "//moduel_a_path/yaml_file2.yaml"
        ],
        "deps": {
            "components": [
                "hilog_native",
                "hitrace_native",
                "ipc",
                "safwk",
                "samgr",
                "utils_base"
            ],
            "third_party": []
        },
        "build": {
        }
    }
}
```


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> yaml文件可根据实际需求置于组件工程的任意目录下，只要在bundle.json文件指定即可。


**编译yaml文件**

- 全量编译：
  - 全量编译整个系统，会将所有组件配置的yaml文件中的配置进行汇总，正常完成系统编译后，指定目录下就会生成hisysevent.zip文件。
    
     ```
     cd 工程根目录的绝对路径
     ./build --product-name <product name>
     ```

  - 全量编译生成的hisysevent.zip文件可以通过以下命令获取：
    
     ```
     cd 工程根目录的绝对路径
     find out -name hisysevent.zip -type f
     ```

- 单文件编译：
  也可以只编译单个组件的yaml文件，命令如下：

  
  ```
  cd 工程根目录的绝对路径
  ./build/ohos/hisysevent/gen_def_from_all_yaml.py --yaml-list <yaml file list> --def-path <file store directory>
  ```

    **表3** 单文件编译参数说明
  
  | 选项名称 | 描述 |
  | -------- | -------- |
  | --yaml-list | 指定需要编译的yaml文件路径列表，多个yaml文件路径之间用空格分隔。 |
  | --def-path | 指定编译生成的hisysevent.zip文件的生成路径。 |


### 打点及查询定义的事件

1. 通过[hdc_std工具](../subsystems/subsys-toolchain-hdc-guide.md)将从hisysevent.zip解压的hisysevent.def文件推送至设备的/data/system/hiview/unzip_configs/sys_event_def/目录下。

2. 触发yaml文件自定义的HiSysEvent事件完成打点，通过“[hisysevent -l](../subsystems/subsys-dfx-hisysevent-tool.md)”命令查询历史HiSysEvent事件，确认触发的自定义HiSysEvent事件是否打点成功。
