# 模块化运行简介
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @yao_dashuai-->
<!--SE: @yao_dashuai-->
<!--TSE: @kirl75;@zsw_zhushiwei-->

为了解决大型或复杂应用开发过程中，部分代码编译时被多次拷贝导致包体积增大、文件依赖、代码与资源共享困难以及单例和全局变量污染等问题，ArkTS支持应用模块化编译、打包和运行，简化代码的编写与维护。

模块化是将ArkTS/TS/JS模块（一个文件对应一个模块）以及so模块通过编译工具或运行时机制将这些[模块加载](#模块化运行加载流程)、解析、组合并执行的过程。

ArkTS支持的模块类型包括ets/ts/js文件、json文件、Native模块。ArkTS中支持[ECMAScript模块规范](#ecmascript模块)及[CommonJS模块规范](#commonjs模块)，此外，ArkTS也对加载方式进行了拓展，包含[动态加载](arkts-dynamic-import.md)、静态加载、[延迟加载](arkts-lazy-import.md)、[同步动态加载Native模块](js-apis-load-native-module.md)和[Node-API接口加载文件](load-module-base-nodeapi.md)。

## 模块化运行加载流程

ArkTS模块化运行根据ECMAScript模块规范实现，以后序遍历的方式执行模块：从模块图的最左侧子树开始，执行模块，然后执行它们的同级，然后执行它们的父级。此算法递归运行，直至执行到模块图的根。

以下图为例，每个父节点加载对应子节点，并按import顺序执行同级。模块图文件执行顺序为：D-&gt;F-&gt;G-&gt;E-&gt;B-&gt;I-&gt;H-&gt;C-&gt;A。

![zh-cn_image_0000002043487154](figures/zh-cn_image_0000002043487154.png)

A文件称为入口文件，即执行起点。一些内置的加载接口，如[windowStage.loadContent](../reference/apis-arkui/arkts-apis-window-Window.md#loadcontent9)和[路由跳转](../ui/arkts-navigation-navigation.md)等页面拉起接口（即不是通过import写法拉起的文件），入参文件都会作为入口文件执行。

以A文件为入口，会加载一整套文件，包括A文件及其依赖文件，以及这些文件后续依赖的文件，直到各分支的叶节点。

普通模块在同一线程内只加载一次，而在不同线程中会加载多次，每个线程都会生成新的模块对象。如果需要在进程内只加载一次，请使用[共享模块](./arkts-sendable-module.md)。

## ArkTS支持的模块化规范

### ECMAScript模块

ECMAScript模块（ECMAScript Modules，后文称ES Module）是JavaScript自ECMAScript6.0之后，从标准层面（ECMAScript® 2025 Language Specification (tc39.es)）实现的模块功能。其模块功能由两个命令组成：export和import。

ArkTS中export和import用法详见[ArkTS语言介绍](../quick-start/introduction-to-arkts.md#模块)。

### CommonJS模块

CommonJS模块是JavaScript社区2009年提出的标准，首先在Node.js采用部分标准并实现。CommonJS将每个文件视为一个模块，通过module变量代表当前模块，module.exports即为该模块对外导出的变量，每个模块还拥有exports变量（exports === module.exports）。

模块导入和模块导出写法参考下表：

| 加载类型 | 模块导入 | 模块导出（不能把module.exports与exports混用） |
| -------- | -------- | -------- |
| 变量 | const ohos = require('ohos') | exports.add = add或module.exports.name = name |
| 变量 | const ohos = require('ohos') | module.exports = add |
| 函数 | const ohos = require('ohos')<br/>ohos.fun(); | exports.fun = function foo () {}或module.exports.fun = function foo () {} |

> **说明：**
>
> CommonJS模块仅适用于第三方包的导出，不支持在工程中创建和使用。


### CommonJS与ES Module支持规格

CommonJS与ES Module互相引用的规格如下表所示，导入和导出语法需遵循各自的模块规范。
| 互相引用关系 | ES Module 导出 | CommonJS导出 |
| -------- | -------- | -------- |
| **ES Module 导入** | 支持 | 支持 |
| **CommonJS导入** | 不支持 | 支持 |

## ArkTS支持加载的模块类型

### ets/ts/js

加载ets/ts/js模块类型时，需遵循[ECMAScript模块规范](#ecmascript模块)及[CommonJS模块规范](#commonjs模块)。

### JSON文件

JSON（JavaScript Object Notation）是一种轻量级的数据交互格式，采用完全独立于编程语言的文本格式来存储和表示数据。

JSON文件只能使用default方式导入，如下所示：

```
import data from './example.json'
```

### Native模块

Native模块（so）的导入导出与加载ets/ts/js语法规格一致。详情请参考：[静态方式加载native模块](./arkts-import-native-module.md)。

> **说明：**
>
> Native模块不支持在CommonJS模块中导入。

示例：

```
// libentry.so对应的index.d.ts
export const add: (a: number, b: number) => number;
```

```
// test.ets
import { add } from 'libentry.so'
add(2, 3)
```
