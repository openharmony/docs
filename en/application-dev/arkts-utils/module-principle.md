# Introduction to Modular Operation

During the development of large-scale and complex applications, some code is copied for multiple times during compilation. As a result, the package size increases, file dependency, code and resource sharing is difficult, and singleton and global variable pollution occurs. In addition, ArkTS supports modular compilation, packaging, and running of applications to facilitate code compilation and function maintenance.

Modularization refers to the process of splitting ArkTS/TS/JS into multiple modules (files or fragments) and loading, parsing, combining, and executing these modules using compilation tools or runtime mechanisms.

ArtTS supports ETS/TS/JS files, JSON files, and native modules. ArkTS supports [ECMAScript module specifications](#ecmascript-module) and [CommonJS module specifications](#commonjs-module). In addition, ArkTS extends the loading modes, including dynamic loading (arkts-dynamic-import.md), delayed loading (arkts-lazy-import.md), and synchronous dynamic loading of native modules (js-apis-load-native-module.md). [Node-API interface loading file](load-module-base-nodeapi.md)

## Loading Process of Modular Operation

ArkTS modular runs are implemented according to the ECMA specification, and modules are executed in a later sequential traversal manner: starting from the leftmost subtree of the module diagram, executing the modules, then executing their peers, and then executing their parent. This algorithm runs recursively until it reaches the root of the module graph.

As shown in the following figure, each parent node loads the corresponding child nodes and executes the child nodes at the same level based on the import sequence in the code. The following module diagram files are executed in the sequence of D-&gt;F-&gt;G-&gt;E-&gt;B-&gt;I-&gt;H-&gt;C-&gt;A.

![image_0000002043487154](figures/image_0000002043487154.png)

The file A is referred to as an entry file, that is, the file is an execution start point. Some built-in loading interfaces, such as [windowStage.loadContent](../reference/apis-arkui/js-apis-window.md#loadcontent9) and [Navigation](../ui/arkts-navigation-navigation.md), are used to start pages (that is, files that are not started by using the import method). The input parameter file is executed as the entry file.

File A is used as the entry to load a complete set of files, including file A, files on which file A depends, and files on which file A depends until each branch leaf node.

## Modular Specifications Supported by ArkTS

### ECMAScript Module

The ECMAScript module (ES Module) is a module function implemented by JavaScript from the standard level (ECMAScript® 2025 Language Specification (tc39.es)) since ECMAScript6.0. The module function consists of two commands: export and import.

For details about how to use export and import in ArkTS, see [ArkTS Introduction](../quick-start/introduction-to-arkts.md#module).

### CommonJS Module

The CommonJS module is a standard proposed by the JavaScript community in 2009. Some standards are first adopted and implemented in Node.js. The CommonJS considers each file as a module and uses the module variable to represent the current module. The module.exports variable is the variable exported by the module. Each module has the exports variable (exports = = = module.exports).

The following table lists the import and export methods.

| Loading Type| Module import| Module export (module.exports and exports cannot be used together.)|
| -------- | -------- | -------- |
| Name| const ohos = require('ohos') | exports.add = add<br>module.exports.name = name |
| const ohos = require('ohos') | module.exports = add |
| Functions| const ohos = require('ohos')<br>ohos.fun(); | exports.fun = function foo () {}<br>module.exports.fun = function foo () {} |

> **Note**
>
> The CommonJS module applies only to third-party package export and cannot be created or used by developers in projects.


### Specifications Supported by CommonJS and ES Modules

The following table lists the specifications for mutual reference between CommonJS and ES Module. The import and export syntax complies with the specifications of each module.
| Mutual reference relationship| ES Module Export| CommonJS export|
| -------- | -------- | -------- |
| ES Module Import| Yes.| Yes.|
| Importing CommonJS| Not supported| Yes|

## Types of Modules That Can Be Loaded by ArkTS

### ets/ts/js

The loading of the ETS, TS, and JS modules complies with [ECMAScript](#ecmascript-module) and [CommonJS](#commonjs-module) module specifications.

### JSON File

JavaScript Object Notation (JSON) is a lightweight data interaction format that uses a text format that is completely independent of programming languages to store and represent data.

The JSON file can be imported only in default mode, as shown in the following:

```
import data from './example.json'
```

### Native Module

The syntax specifications for importing and exporting the native module (.so) are the same as those for loading the ETS, TS, and JS files.

> **Note**
>
> The Native module cannot be imported to the CommonJS module.

Example:

```
// index.d.ts corresponding to libentry.so
export const add: (a: number, b: number) => number;
```

```
// test.ets
import { add } from 'libentry.so'
add(2, 3)
```

ArkTS does not support namespaces for both native module export and import.

Non-compliant code example:

```
// test1.ets
export * from'libentry.so' // Use the namespace to export data.
```

```
// test2.ets
import('./test1').then((ns:ESObject) => {
  // The ns object cannot be obtained during dynamic loading.
  // If you want to use this method to load the Native module, change the export mode in test1.ets to named export or default export.
})
```

> **Note**
>
> You are not advised to import data in import \* as xxx from 'xxx' mode. This import mode will cause runtime exceptions. You are advised to use the default import mode.
