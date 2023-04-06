# 部件编译构建规范

## 前言

### 目的

编译构建是部件化设计落地的切入点，一个优秀的部件在编译态应该具备可维护、可移植、低耦合的特征。本规范用于引导部件开发人员编写符合部件化设计的编译脚本，使得部件在编译态依赖合理、可配置、可复用、可裁剪。

### 基本概念

**部件**

部件是OpenHarmony系统能力的基本单元，以源码为划分依据，具有独立的仓和目录，在不同的设备上可实例化为不同的库或二进制文件。

**特性**

部件特性为编译态可配置的编译选项，可供产品在编译时按需配置。不同的特性配置，编译出部件的不同形态，使得部件可以适应不同形态产品的差异化需求。部件特性的配置只影响部件内部功能的实现差异，不能影响部件的Public API（部件对应用提供的接口）以及inner api（部件间的接口）。

**依赖**

在编译态，部件的依赖分为：

- 有条件依赖：在特定场景下可裁剪的依赖，有条件的依赖裁剪后不影响部件的Public API 和inner api。比如音频对蓝牙的依赖。
- 强依赖：部件间合理的必要的依赖，不可裁剪。比如syscap部件对安全库函数的依赖。

### 总体原则

部件编译构建应遵循以下几个原则：

**独立自治**

部件编译态应内聚，新增外部依赖时应慎重，尽量减少编译时的静态依赖。

**合理依赖**

部件间的依赖都应基于部件间的接口，禁止依赖其他部件内部的模块和头文件。

**产品无关**

部件在编译态应是多产品通用的，禁止在编译脚本中使用产品名称。

### 约定

**规则：** 必须遵守的约定。

**建议：** 必须加以考虑的约定。

### 看护手段

为了维护部件编译构建规范，门禁会对构建配置文件做一些检查。

预编译检查：指在预编译阶段进行检查，检测到错误将报错并停止编译。

静态检查：指检查工具对配置文件进行扫描检查，非编译手段。

### 例外

在不违背总体原则，经过充分考虑，有充足的理由的前提下，可以适当违背规范中约定。

例外破坏了代码的一致性，请尽量避免。“规则”的例外应该是极少的。

## 命名

编译脚本中的变量、编译目标（target）、模板，gni文件，以及部件描述文件中的对象和数据的命名都应采用内核风格（unix_like），单词全小写，用下划线分割。如："startup_init"。

### 规则1.1 部件名格式须统一
- 名词形式，需体现部件的功能。
- 在系统内全局唯一。
- 不超过63个有效英文字符。
- 使用小写加下划线的内核风格命名，例如：unix_like。

> **例外：** 三方开源软件的使用对应社区的原生命名方式，比如：cJson。

### 规则1.2 特性名为部件名前缀+特性名称

特性是部件声明的可配置的编译选项，加上部件名前缀可避免系统内特性重名。示例：

```py
declare_args() {
  dsoftbus_conn_p2p = true  # dsoftbus 为部件名, conn_p2p 为特性名称
  dsoftbus_conn_ble = false # dsoftbus 为部件名, conn_ble 为特性名称
}
```

看护手段：预编译检查

### 建议1.1 编译目标名以部件名为前缀+模块名称

一个部件可能有多个编译目标（即模块），以“{部件名}_{模块名}”的方式命名可以根据编译产物（库、可执行文件）快速定位归属部件和避免重名。

反例：
```py
ohos_shared_library("data") # Bad: 不精确，过于通用，系统内易重名
```
正例：
```py
ohos_shared_library("cellular_data_napi") # Good
```

## 描述文件

bundle.json是定义部件的描述文件，包含了部件的根目录、名称、功能描述、版本号、接口定义和编译入口等信息，须保证其准确性。

### 规则2.1 部件描述文件中字段须准确

| 字段 | 类型 | 看护手段 |
|---|---|---|
|name|string。部件的HPM（OpenHarmony包管理器）包名称，必填。命名规则：@{organization}/{component_name}。"component_name"为部件的名称，须满足规则1.1。|静态检查|
|version|string。部件版本号，必填，命名和升级跟随OpenHarmony版本号。|静态检查|
|destPath|string。部件源码的根目录，必填。部件的根目录须独立唯一，不允许存在多个根目录。|静态检查|
|component:name|string。部件名，必填。须满足规则1.1。|静态检查|
|component:subsystem|string。部件归属的子系统名称，必填，子系统名为小写英文字母组合、不使用下划线。|静态检查|
|component:syscap|string list。系统能力的描述，可选。命名规则：大驼峰，"SystemCapability.Subsystem.部件能力.子能力（可选）"，如`SystemCapability.Media.Camera`,`SystemCapability.Media.Camera.Front`。|静态检查|
|component:features|string list，部件可配置的特性，可选，命名须满足规则1.2。|静态检查|
|component:adapted_system_type|string list。部件适用的系统类型，必填，值为`mini`、`small`和`standard`，可同时支持多种。|静态检查|
|component:rom|string。ROM基线值，必填，单位默认为KByte。|静态检查|
|component:ram|string。RAM基线值，必填，单位默认为KByte。|静态检查|
|component:deps|string list。deps对象描述了部件的外部依赖，必填，包括其他部件和三方开源软件，应该与部件编译脚本中依赖一致。|预编译检查|


### 建议2.1 部件的描述文件应存放在部件根目录下

部件目录是独立的，应将bundle.json文件存放到部件根目录下。

## 变量

编译目标（target）的内置变量赋值决定了编译内容、依赖和打包等信息，与实现部件化设计强相关。

### 规则3.1 部件编译脚本中只允许引用本部件的路径，禁止引用其他部件的绝对或相对路径

部件间的依赖都必须使用"externel_deps"，部件编译目标的变量sources、include_dirs、configs、public_configs、deps、public_deps引用其他部件的相对和绝对路径属于非法引入依赖：

- sources

  sources只允许包含本部件的源码，包含其他部件的源码破坏了部件源码目录独立的原则。

- include_dirs

  include_dirs只允许引用本部件的头文件搜索路径，编译单元对其他部件的接口的依赖都通过externel_deps自动导入。

- configs

  configs只允许引用本部件的配置路径，引用其他部件的configs可能会引入接口依赖。

- pulic_configs

  pulic_configs只允许引用本部件的配置路径，引用其他部件的configs可能会引入接口依赖。

- deps

  deps只允许用于部件内模块的依赖，直接引用其他部件的模块可能会导致依赖其他部件的内部模块和接口。

  例：

  base/foos/foo_a/BUILD.gn

  ```py
  deps = [ "//base/foo/foo_b:b" ] # Bad, 绝对路径依赖其他部件
  deps = [ "../../foo_b:b" ] # Bad, 相对路径依赖其他部件
  deps = [ "a" ] # Good, 依赖当前部件内的其他模块
  ```

  > **例外：** 对三方开源软件的引用除外。

- public_deps

  public_deps只允许用于部件内模块的依赖，直接引用其他部件的模块可能会导致依赖其他部件的内部模块和接口。

  > **例外：** 对三方开源软件的引用除外。
  

看护手段：静态检查

### 规则3.2 部件编译目标必须指定部件和子系统名

部件的编译单元ohos_shared_library、ohos_static_library、ohos_executable_library、ohos_source_set都必须指定"part_name"和"subsystem_name"。

以developtools/syscap_codec/BUILD.gn的ohos_shared_library编译单元为例：

```py
ohos_shared_library("syscap_interface_shared") {
  include_dirs = [
    "include",
    "src",
  ]
  public_configs = [ ":syscap_interface_public_config" ]
  sources = [
    "./interfaces/inner_api/syscap_interface.c",
    "./src/endian_internal.c",
    "./src/syscap_tool.c",
  ]
  deps = [
    "//third_party/bounds_checking_function:libsec_static",
    "//third_party/cJSON:cjson_static",
  ]

  subsystem_name = "developtools" # 必须指定subsystem_name
  part_name = "syscap_codec" # 必须指定part_name
}
```

看护手段：静态检查

### 建议3.1 部件内部的引用使用相对路径

部件内的引用使用相对路径的优点：

- 脚本更简洁

- 部件的编译脚本与部件的根目录解耦。

例：

base/foos/foo_a/BUILD.gn

```py
include_dirs = [
    "./include", # Good, 相对路径引用
    "//base/foo/foo_a/include" # Bad, 绝对路径引用
]

deps = [
    "sub_module:foo", # Good, 相对路径引用
    "base/foo/foo_a/sub_moudule:foo" # Bad, 绝对路径引用
]
```

看护手段：静态检查

### 建议3.2 部件内部模块的可见度设置为部件内可见

部件内部的模块应使用`"visibility"`字段标识，防止被其他部件依赖。示例：

base/foos/foo_a/BUILD.gn

```py
ohos_shared_library("foo_a") {
    visibility = [ "./*" ] # foo_a只在base/foo/foo_a及其子目录下可见
}

ohos_shared_library("foo_a") {
    visibility = [ ":*" ] # foo_a只在本BUILD.gn可见
}
```

## 其他

### 规则4.1 部件编译脚本中禁止使用产品名称变量

部件是通用的系统能力，与特定产品无关。编译脚本中使用产品名称，将导致部件功能与产品绑定，不具备通用性。部件不同产品形态上的差异应抽象为特性或者运行时的插件。

> **例外：** vendor和device目录下三方厂商部件的编译脚本例外。

看护手段：静态检查

### 建议4.1 避免import其他部件目录下的gni文件

部件内的gni文件用于声明部件内部编译变量和模板，import其他部件的gni文件等同于使用其他部件内部的变量和模板，即引入对其他部件的依赖。影响多个部件的变量、args和模板应定义在编译框架的gni文件中。

> **例外：** build目录下编译框架定义全局的编译选项的gni可以被所有部件import。

看护手段：静态检查

### 建议4.2 部件使用统一的编译单元模板

轻量、小型和标准的系统的编译单元都应使用ohos定义的模板，比如`ohos_shared_library`、`ohos_static_library`、`ohos_executable`、`ohos_source_set`等以"ohos_"为前缀的模板。

例如：

```py
  executable("foundation") { # Bad, 不推荐使用内置的模板
    ...
  }

  ohos_executable("foundation") { # Good, 推荐使用ohos定制模板
    ...
  }
```

