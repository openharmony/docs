# 代码混淆

## 代码混淆简介

针对工程源码的混淆可以降低工程被破解攻击的风险，缩短代码的类与成员的名称，减小应用的大小。  
DevEco Studio提供代码混淆的能力并默认开启，API 10及以上版本的Stage模型、[编译模式为release](#说明)时自动进行代码混淆。  

### 使用约束

* 仅支持Stage工程
* 编译模式为release
* 模块及模块依赖的HAR均未配置关闭混淆的规则`-disable-obfuscation`

### 混淆范围

在应用工程中，代码混淆支持以下格式文件混淆，混淆后的缓存文件保存在模块目录下的build/[...]/release目录下。

* ArkTS文件
* TS文件
* JS文件

## 开启代码混淆

代码混淆已经被集成了到SDK中，可以在DevEco Studio中很方便地使用。

代码混淆目前只提供名称混淆的能力(因为其它混淆能力会劣化性能)。 开启代码混淆可以混淆以下名称:

* 参数名和局部变量名  
* 顶层作用域的名称  
* 属性名称  

代码混淆默认使能对参数名和局部变量名的混淆。顶层作用域名称和属性名称的混淆是默认关闭的，因为默认打开可能会导致运行时错误。这些混淆功能通过混淆选项来开启它们。

创建一个新工程的时候，配置文件build-profile.json5中会自动生成以下内容:

```
"arkOptions": {
  "obfuscation": {
    "ruleOptions": {
      "enable": true,
      "files": ["./obfuscation-rules.txt"],
    }
  }
}
```

创建一个新的library的时候，还会额外生成consumerFiles属性:

```
"arkOptions": {
  "obfuscation": {
    "ruleOptions": {
      "enable": true,
      "files": ["./obfuscation-rules.txt"],
    }
    "consumerFiles": ["./consumer-rules.txt"]
  }
}
```

混淆功能默认开启，若被关闭希望重新开启混淆需要满足条件: 属性ruleOptions.enable的值为true。

属性ruleOptions.files中指定的混淆配置文件会在构建HAP、HSP或HAR的时候生效。  
属性consumerFiles中指定的混淆配置文件会在构建依赖这个library的模块时生效。 这些混淆配置文件的内容还会被合并到HAR包中的obfuscation.txt文件。

当构建HAP、HSP和HAR的时候，最终的混淆规则是当前构建模块的ruleOptions.files属性，依赖library的consumerFiles属性，以及依赖HAR包中的obfuscation.txt文件的合并。  
如果构建的是HAR，HAR包中的obfuscation.txt是自身的consumerFiles属性， 依赖library的consumerFiles属性，以及依赖HAR包中的obfuscation.txt文件的合并。构建HAP、HSP不会生成obfuscation.txt。详细合并的策略可以查看[混淆规则合并策略](#混淆规则合并策略)。

### 混淆规则配置文件

在创建工程或library的时候，DevEco Studio会自动生成`obfuscation-rules.txt`和`consumer-rules.txt`文件，
但是它们默认不会包含任何混淆规则。混淆规则可以写到这些文件中，或者其它自定义文件，
然后将文件路径放到`ruleOptions.files`和`consumerFiles`中，如下面的例子所示。

```
"buildOption": {
  "arkOptions": {
    "obfuscation": {
      "ruleOptions": {
        "enable": true,
        "files": ["./obfuscation-rules.txt", "./myrules.txt"], //myrules.txt放入配置文件build-profile.json5同级目录下
      }
      "consumerFiles": ["./consumer-rules.txt", "./my-consumer-rules.txt"]
    }
  }
}
```

## 配置混淆规则

混淆规则分为两种类型，一种是[混淆选项](#混淆选项)，一种是[保留选项](#保留选项)；前者是提供顶层作用域名称、属性名称、文件名称等多种混淆功能配置开关，后者是提供各种混淆功能的白名单配置能力。

### 混淆选项

#### -disable-obfuscation

关闭所有混淆。如果使用这个选项，那么构建出来的HAP、HSP或HAR将不会被混淆。

#### -enable-property-obfuscation

开启属性混淆。 如果使用这个选项，那么所有的属性名都会被混淆，除了下面场景:

* 被`import/export`直接导入或导出的类、对象的属性名不会被混淆。例如下面例子中的属性名`data`不会被混淆。

    ```
    export class MyClass {
       data: string;
    }
    ```

* ArkUI组件中的属性名不会被混淆。例如下面例子中的`message`和`data`不会被混淆。

    ```
    @Component struct MyExample {
        @State message: string = "hello";
        data: number[] = [];
        ...
    }
    ```

* 被[保留选项](#保留选项)指定的属性名不会被混淆。
* SDK API列表中的属性名不会被混淆。SDK API列表是构建时从SDK中自动提取出来的一个名称列表，其缓存文件为systemApiCache.json，路径为工程目录下build/cache/{...}/release/obfuscation中
* 在Native API场景中，so库对应的d.ts文件中声明的API不会被混淆。
* 字符串字面量属性名不会被混淆。例如下面例子中的`"name"`和`"age"`不会被混淆。

    ```
    let person = {"name": "abc"};
    person["age"] = 22;
    ```

    如果想混淆字符串字面量属性名，需要在该选项的基础上再使用`-enable-string-property-obfuscation`选项。例如

    ```
    -enable-property-obfuscation
    -enable-string-property-obfuscation
    ```

    **注意**：  

    **1.** 如果代码里面有字符串属性名包含特殊字符(除了`a-z, A-Z, 0-9, _`之外的字符)，例如`let obj = {"\n": 123, "": 4, " ": 5}`，建议不要开启`-enable-string-property-obfuscation`选项，因为可能无法通过[保留选项](#保留选项)来指定保留这些名字。  
    **2.** SDK API的属性白名单中不包含声明文件中使用的字符串常量值，例如示例中的字符串'ohos.want.action.home'未包含在属性白名单中

    ```
    // SDK API文件@ohos.app.ability.wantConstant片段：
    export enum Params {
      ACTION_HOME = 'ohos.want.action.home'
    }
    // 开发者源码示例：
    let params = obj['ohos.want.action.home'];
    ```

    因此在开启了`-enable-string-property-obfuscation`选项时，如果想保留代码中使用的SDK API字符串常量的属性不被混淆，例如obj['ohos.want.action.home'], 那么需要使用keep选项保留。

#### -enable-toplevel-obfuscation

开启顶层作用域名称混淆。如果使用这个选项，那么所有的顶层作用域的名称都会被混淆，除了下面场景:

* 被`import/export`的名称不会被混淆。
* 当前文件找不到声明的名称不会被混淆。
* 被[保留选项](#保留选项)指定的顶层作用域名称不会被混淆。
* SDK API列表中的顶层作用域名称不会被混淆。

#### -enable-filename-obfuscation

开启文件/文件夹名称混淆。如果使用这个选项，那么所有的文件/文件夹名称都会被混淆，除了下面场景:

* oh-package.json5文件中'main'、'types'字段配置的文件/文件夹名称不会被混淆。
* 模块内module.json5文件中'srcEntry'字段配置的文件/文件夹名称不会被混淆。
* 被[`-keep-file-name`](#保留选项)指定的文件/文件夹名称不会被混淆。
* 非ECMAScript模块引用方式（ECMAScript模块示例：`import {foo} from './filename'`）
* 非路径引用方式，例如例子中的json5不会被混淆 `import module from 'json5'`  

**注意**：  

由于系统会在应用运行时加载某些指定的文件，针对这类文件，开发者需要手动在[`-keep-file-name`]选项中配置相应的白名单，防止指定文件被混淆，导致运行失败。
上述需要手动配置白名单的情况，包括但不限于以下场景：  

* 当模块中包含Ability组件时。用户需要将`scr/main/module.json5`中，'abilities'字段下所有'srcEntry'对应的路径配置到白名单中。  
* 当模块中包含Worker多线程服务时，用户需要将`build-profiles.json5`中，'buildOption'-'sourceOption'-'workers'字段下所有的路径配置到白名单中。

#### -enable-export-obfuscation

开启直接导入或导出的类或对象的名称和属性名混淆。如果使用这个选项，那么模块中的直接导入或导出的名称都会被混淆，除了下面场景:

* 远程HAR(真实路径在oh_modules中的包)中导出的类或对象的名称和属性名不会被混淆。
* 被[保留选项](#保留选项)指定的名称与属性名不会被混淆。
* SDK API列表中的名称不会被混淆。

**注意**：

1. 混淆导入或导出的类中属性名称需要同时开启`-enable-property-obfuscation`与`-enable-export-obfuscation`选项。  
2. 编译HSP时，如果开启`-enable-export-obfuscation`选项，需要在模块中的混淆配置文件`obfuscation-rules.txt`中保留对外暴露的接口。
3. HAP/HSP/HAR依赖HSP场景下，编译时如果开启`-enable-export-obfuscation`选项，需要在模块中的混淆配置文件`obfuscation-rules.txt`中保留HSP导入的接口。  

    ```
    // 代码示例(HSP中入口文件Index.ets)：
    export { add, customApiName } from './src/main/ets/utils/Calc'

    // 保留接口名称配置示例：
    // HSP以及依赖此HSP的模块中obfuscation-rules.txt文件配置： 
    keep-global-name
    add
    customApiName
    ```

#### -compact

去除不必要的空格符和所有的换行符。如果使用这个选项，那么所有代码会被压缩到一行。

**注意**：

release模式构建的应用栈信息仅包含代码行号，不包含列号，因此compact功能开启后无法依据报错栈中的行号定位到源码具体位置。

#### -remove-log

删除以下场景中对 console.*语句的调用，要求console.*语句返回值未被调用。

1. 文件顶层的调用
2. 代码块Block中的调用
3. 模块Module中的调用
4. switch语句中的调用

#### `-print-namecache` filepath

将名称缓存保存到指定的文件路径。名称缓存包含名称混淆前后的映射。  

**注意**：

每次全量构建工程时都会生成新的namecache.json文件，因此您每次发布新版本时都要注意保存一个该文件的副本。

#### `-apply-namecache` filepath

复用指定的名称缓存文件。名字将会被混淆成缓存映射对应的名字，如果没有对应，将会被混淆成新的随机段名字。
该选项应该在增量编译场景中被使用。

默认情况下，DevEco Studio会在临时的缓存目录中保存缓存文件，并且在增量编译场景中自动应用该缓存文件。  
缓存目录：build/cache/{...}/release/obfuscation

#### -remove-comments

删除文件中的所有注释，包括单行、多行，及JsDoc注释。以下场景除外：
声明文件中，在`-keep-comments`中配置的类、方法、struct、枚举等名称上方的JsDoc注释。  

**注意**：  

编译生成的源码文件中的注释默认会被全部删除，不支持配置保留。

### 保留选项

#### `-keep-property-name` [,identifiers,...]

指定想保留的属性名，支持使用[名称类通配符](#名称类通配符)。例如下面的例子:

```
-keep-property-name
age
firstName
lastName
```

**注意**：

该选项在开启`-enable-property-obfuscation`时生效

**哪些属性名应该被保留?**

为了保障混淆的正确性，建议保留所有不通过点语法访问的属性。

例子:

```
var obj = {x0: 0, x1: 0, x2: 0};
for (var i = 0; i <= 2; i++) {
    console.log(obj['x' + i]);  // x0, x1, x2 应该被保留
}

Object.defineProperty(obj, 'y', {});  // y 应该被保留
console.log(obj.y);

obj.s = 0;
let key = 's';
console.log(obj[key]);        // s 应该被保留

obj.u = 0;
console.log(obj.u);           // u 可以被正确地混淆

obj.t = 0;
console.log(obj['t']);        // 在开启字符串字面量属性名混淆时t和't'会被正确地混淆，但是建议保留

obj['v'] = 0;
console.log(obj['v']);        // 在开启字符串字面量属性名混淆时'v'会被正确地混淆，但是建议保留
```

对于间接导出的场景，例如`export MyClass`和`let a = MyClass; export {a};`，如果不想混淆它们的属性名，那么需要使用[保留选项](#保留选项)来保留这些属性名。另外，对于直接导出的类或对象的属性的属性名，例如下面例子中的`name`和`age`, 如果不想混淆它们，那么也需要使用[保留选项](#保留选项)来保留这些属性名。

```
export class MyClass {
    person = {name: "123", age: 100};
}
```

没有在so库的d.ts文件中声明的API（例如示例中的foo），如果要在ArkTS/TS/JS文件中使用需手动保留API名称。

```
import testNapi from 'library.so'
testNapi.foo()
```

#### `-keep-global-name` [,identifiers,...]

指定要保留的顶层作用域的名称，支持使用[名称类通配符](#名称类通配符)。例如，

```
-keep-global-name
Person
printPersonName
```

**哪些顶层作用域的名称应该被保留?**

在Javascript中全局变量是`globalThis`的属性。如果在代码中使用`globalThis`去访问全局变量，那么该变量名应该被保留。

示例:

```
var a = 0;
console.log(globalThis.a);  // a 应该被保留

function foo(){}
globalThis.foo();           // foo 应该被保留

var c = 0;
console.log(c);             // c 可以被正确地混淆

function bar(){}
bar();                      // bar 可以被正确地混淆

class MyClass {}
let d = new MyClass();      // MyClass 可以被正确地混淆
```

#### `-keep-file-name` [,identifiers,...]

指定要保留的文件/文件夹的名称(不需要写文件后缀)，支持使用[名称类通配符](#名称类通配符)。例如，

```
-keep-file-name
index
entry
```

**哪些文件名应该被保留?**

```
const module1 = require('./file1')   // ArkTS不支持CommonJS语法，这种路径引用应该被保留
const moduleName = './file2'
const module2 = import(moduleName)    // 动态引用方式无法识别moduleName是否是路径，应该被保留
```

#### `-keep-comments` [,identifiers,...]

保留声明文件中元素上方的JsDoc注释，支持使用[名称类通配符](#名称类通配符)。例如想保留声明文件中Human类上方的JsDoc注释，可进行以下配置：

```
-keep-comments
Human
```

**注意**：

1. 该选项在开启`-remove-comments`时生效
2. 当声明文件中某个元素名称被混淆时，该元素上方的JsDoc注释无法通过`-keep-comments`保留。例如当在`-keep-comments`中配置了exportClass时，如果下面的类名被混淆，其JsDoc注释无法被保留：

```
/*
 * @class exportClass
 */
export class exportClass {}
```

#### `-keep-dts` filepath

保留指定路径的`.d.ts`文件中的名称。这里的文件路径可以是一个目录，这种情况下目录中所有`.d.ts`文件中的名称都会被保留。
如果在构建HAR时使用了这个选项，那么文件中的名称会被合并到最后的`obfuscation.txt`文件中。

#### `-keep` path

保留指定路径中的所有名称(例如变量名、类名、属性名等)不被混淆。这个路径可以是文件与文件夹，若是文件夹，则文件夹下的文件及子文件夹中文件都不混淆。  
路径仅支持相对路径，`./`与`../`为相对于混淆配置文件所在目录，支持使用[路径类通配符](#路径类通配符)。

```
-keep
./src/main/ets/fileName.ts   // fileName.ts中的名称不混淆
../folder                    // folder目录下文件及子文件夹中的名称都不混淆
../oh_modules/json5          // 引用的三方库json5里所有文件中的名称都不混淆
```

注：该功能不影响文件名混淆`-enable-filename-obfuscation`的功能

#### 保留选项支持的通配符
##### 名称类通配符

名称类通配符使用方式如下：

| 通配符 | 含义                   | 示例                                       |
| ------ | ---------------------- | ------------------------------------------ |
| ?      | 匹配任意单个字符       | "AB?"能匹配"ABC"等，但不能匹配"AB"         |
| \*     | 匹配任意数量的任意字符 | "\*AB\*"能匹配"AB"、"aABb"、"cAB"、"ABc"等 |

**使用示例**：

保留所有以a开头的属性名称：
```
-keep-property-name
a*
```

保留所有单个字符的属性名称：
```
-keep-property-name
?
```

保留所有属性名称：
```
-keep-property-name
*
```

##### 路径类通配符

路径类通配符使用方式如下：

| 通配符 | 含义                                                                     | 示例                                              |
| ------ | ------------------------------------------------------------------------ | ------------------------------------------------- |
| ?     | 匹配任意单个字符，除了路径分隔符'/'                                      | "../a?"能匹配"../ab"等，但不能匹配"../a/"         |
| \*      | 匹配任意数量的任意字符，除了路径分隔符'/'                                | "../a*/c"能匹配"../ab/c"，但不能匹配"../ab/d/s/c" |
| \*\*   | 匹配任意数量的任意字符                                                   | "../a**/c"能匹配"../ab/c"，也能匹配"../ab/d/s/c"  |
| !      | 表示非，只能写在某个路径最前端，用来排除用户配置的白名单中已有的某种情况 | "!../a/b/c.ets"表示除"../a/b/c.ets"以外           |

**使用示例**：

表示路径../a/b/中所有文件夹（不包含子文件夹）中的c.ets文件不会被混淆：
```
-keep
../a/b/*/c.ets
```

表示路径../a/b/中所有文件夹（包含子文件夹）中的c.ets文件不会被混淆：
```
-keep
../a/b/**/c.ets
```

表示路径../a/b/中，除了c.ets文件以外的其它文件都不会被混淆。其中，'!'不可单独使用，只能用来排除白名单中已有的情况：
```
-keep
../a/b/
!../a/b/c.ets
```

表示所有文件都不会被混淆：
```
-keep
*
```

**注意**：

(1)以上选项，不支持配置通配符'*'、'?'、'!'作其它含义使用。
例如：
```
class A {
  '*'= 1
}

-keep-property-name
*
```

此时'\*'表示匹配任意数量的任意字符，配置效果为所有属性名称都不混淆，而不是只有'\*'属性不被混淆。

(2)-keep选项中只允许使用'/'路径格式，不支持'\\'或'\\\\'。

(3)白名单中不支持配置以下特殊字符：'\\'、'\^'、'\$'、'\+'、'\|'、'\['、'\]'、'\{'、'\}'、'\('、'\)'。

### 注释

可以使用`#`在混淆规则文件中进行注释。每行以`#`开头的文本会被当做是注释，例如下面的例子:

```
# white list for MainAbility.ets
-keep-global-name
MyComponent
GlobalFunction

-keep-property-name # white list for dynamic property names
firstName
lastName
age
```

构建HAR时，注释不会被合并到最后的`obfuscation.txt`文件中。

### 混淆规则合并策略

一个工程中经常会有许多混淆规则文件，这些文件来自于:

* 主工程的`ruleOptions.files` (这里主工程指的是正在构建的工程)
* 本地依赖的library中的`consumerFiles`选项中指定的文件
* 远程依赖的HAR包中的`obfuscate.txt`文件

当构建主工程的时候，这些文件中的混淆规则会按照下面的合并策略(伪代码)进行合并:

```
let `listRules` 表示上面提到的所有混淆规则文件的列表
let finalRule = {
    disableObfuscation: false,
    enablePropertyObfuscation: false,
    enableToplevelObfuscation: false,
    compact: false,
    removeLog: false,
    keepPropertyName: [],
    keepGlobalName: [],
    keepDts: [],
    printNamecache: string,
    applyNamecache: string
}
for each file in `listRules`:
    for each option in file:
        switch(option) {
            case -disable-obfuscation:
                finalRule.disableObfuscation = true;
                continue;
            case -enable-property-obfuscation:
                finalRule.enablePropertyObfuscation = true;
                continue;
            case -enable-toplevel-obfuscation:
                finalRule.enableToplevelObfuscation = true;
                continue;
            case -compact:
                finalRule.compact = true;
                continue;
            case -remove-log:
                finalRule.removeLog = true;
                continue;
            case -print-namecache:
                finalRule.printNamecache = #{指定的路径名};
                continue;
            case -apply-namecache:
                finalRule.applyNamecache = #{指定的路径名};
                continue;
            case -keep-property-name:
                finalRule.keepPropertyName.push(#{指定的名称});
                continue;
            case -keep-global-name:
                finalRule.keepGlobalName.push(#{指定的名称});
                continue;
            case -keep-dts:
                finalRule.keepDts.push(#{指定的路径});
                continue;
        }
    end-for
end-for
```

最后使用的混淆规则来自于对象`finalRule`。

如果构建的是HAR，那么最终的`obfuscate.txt`文件内容来自于主工程和本地依赖的library的`consumerFiles`选项，
以及依赖的HAR的`obfuscate.txt`文件的合并。合并策略和上面一样，除了以下的不同:

* `-keep-dts`选项会被转换成`-keep-global-name`和`-keep-property-name`。
* `-print-namecache`和`apply-namecache`选项会被忽略，不会出现在最后的`obfuscate.txt`文件中。

## 报错栈还原

经过混淆的应用程序中代码名称会发生更改，crash时打印的报错栈更难以理解，因为报错栈与源码不完全一致。开发人员可使用DevEco Studio命令工具Command Line Tools中的hstack插件来还原源码堆栈。

## 说明

* 目前不支持在hvigor构建流程中插入自定义混淆插件
* 混淆的HAR包被模块依赖，若模块开启混淆，则HAR包会被二次混淆
* DevEco Studio右上角Product选项，将其中Build Mode选择release，可开启release编译模式
![product-release](figures/product-release.png)
