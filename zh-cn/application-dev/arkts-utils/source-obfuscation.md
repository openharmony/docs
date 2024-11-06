# ArkGuard源码混淆工具

## 代码混淆简介

针对工程源码的混淆可以降低工程被破解攻击的风险，缩短代码的类与成员的名称，减小应用的大小。 

>**说明：** 
>
> 1. 在 DevEco Studio5.0.3.600之前，新建工程的默认设置是开启代码混淆功能，它会自动对 API10及更高版本的 Stage 模型进行代码混淆。此操作仅适用于以[release模式](#说明)编译的代码，并且混淆仅限于参数名和局部变量名。
> 2. 在 DevEco Studio5.0.3.600及之后，新建工程的默认设置已更改为关闭代码混淆功能。如果开发者希望开启代码混淆，需要将模块的`build-profile.json5`文件中的`ruleOptions.enable`字段的值设置为 true。此外，混淆规则配置文件`obfuscation-rules.txt`默认开启了四项推荐的混淆选项：`-enable-property-obfuscation`、`-enable-toplevel-obfuscation`、`-enable-filename-obfuscation`和`-enable-export-obfuscation`，开发者可以根据需要进一步修改混淆配置。需要注意的是，开启这四项规则可能会导致应用在运行时崩溃，因此建议开发者参考[排查指南](#如何排查功能异常)来修正应用功能。

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

代码混淆能力已在系统中集成，可通过以下方式在DevEco Studio开启使用。

代码混淆目前只提供名称混淆的能力(因为其它混淆能力会劣化性能)。 开启代码混淆可以混淆以下名称:

* 参数名和局部变量名  
* 顶层作用域的名称  
* 属性名称
* 导出名称
* 文件名称

混淆开启后，默认使能对参数名和局部变量名的混淆，无需选项配置。顶层作用域名称混淆、属性名称的混淆、导出名称混淆、文件名混淆打开可能会导致运行时错误，这些混淆功能通过混淆配置选项来开启/关闭它们。

创建一个模块的时候，模块级`build-profile.json5`中会自动生成以下内容:

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

混淆功能被关闭希望重新开启混淆需要满足条件: 属性ruleOptions.enable的值为true。

属性ruleOptions.files中指定的混淆配置文件会在构建HAP、HSP或HAR的时候生效。  
属性consumerFiles中指定的混淆配置文件会在构建依赖这个library的模块时生效。这些混淆配置文件的内容还会被合并到HAR包中的obfuscation.txt文件。

当构建HAP、HSP和HAR的时候，最终的混淆规则是当前构建模块的ruleOptions.files属性，依赖library的consumerFiles属性，以及依赖HAR包中的obfuscation.txt文件的合并。  
如果构建的是HAR，HAR包中的obfuscation.txt是自身的consumerFiles属性， 依赖library的consumerFiles属性，以及依赖HAR包中的obfuscation.txt文件的合并。构建HAP、HSP不会生成obfuscation.txt。详细合并的策略可以查看[混淆规则合并策略](#混淆规则合并策略)。

### 混淆规则配置文件

在创建工程或library的时候，DevEco Studio会自动生成`obfuscation-rules.txt`和`consumer-rules.txt`文件。混淆规则可以写到这些文件中，或者其它自定义文件，然后将文件路径放到`ruleOptions.files`和`consumerFiles`中，如下面的例子所示。

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

**注意**

若修改应用混淆配置，新配置需要重新全量编译应用才能生效。

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
* SDK API列表中的属性名不会被混淆。SDK API列表是构建时从SDK中自动提取出来的一个名称列表，其缓存文件为systemApiCache.json，路径为工程目录下build/default/cache/{...}/release/obfuscation中
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

开启文件/文件夹名称混淆。如果使用这个选项，那么所有的文件/文件夹名称都会被混淆，例如：

```
// directory和filename都会混淆
import func from '../directory/filename';
import { foo } from '../directory/filename';
const module = import('../directory/filename');
```

除了下面场景:

* oh-package.json5文件中'main'、'types'字段配置的文件/文件夹名称不会被混淆。
* 模块内module.json5文件中'srcEntry'字段配置的文件/文件夹名称不会被混淆。
* 被[-keep-file-name](#保留选项)指定的文件/文件夹名称不会被混淆。
* 非ECMAScript模块引用方式（ECMAScript模块示例：`import {foo} from './filename'`）
* 非路径引用方式，例如例子中的json5不会被混淆 `import module from 'json5'`  

**注意**：  

由于系统会在应用运行时加载某些指定的文件，针对这类文件，开发者需要手动在[-keep-file-name](#保留选项)选项中配置相应的白名单，防止指定文件被混淆，导致运行失败。
上述需要手动配置白名单的情况，包括但不限于以下场景：  

* 当模块中包含Ability组件时。用户需要将`src/main/module.json5`中，'abilities'字段下所有'srcEntry'对应的路径配置到白名单中。  
* 当模块中包含Worker多线程服务时，用户需要将`build-profiles.json5`中，'buildOption'-'sourceOption'-'workers'字段下所有的路径配置到白名单中。

**提醒**：

编译入口、Ability组件、Worker多线程，这三种不能混淆的文件名在DevEco Studio 5.0.3.500版本已被自动收集进白名单中，无需再手动配置，其它不能混淆文件名的场景仍需开发者手动配置

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
    -keep-global-name
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

#### -print-namecache *filepath*

将名称缓存保存到指定的文件路径。名称缓存包含名称混淆前后的映射。  

**注意**：

每次全量构建工程时都会生成新的namecache.json文件，因此您每次发布新版本时都要注意保存一个该文件的副本。

#### -apply-namecache *filepath*

复用指定的名称缓存文件。名字将会被混淆成缓存映射对应的名字，如果没有对应，将会被混淆成新的随机段名字。
该选项应该在增量编译场景中被使用。

默认情况下，DevEco Studio会在临时的缓存目录中保存缓存文件，并且在增量编译场景中自动应用该缓存文件。  
缓存目录：build/default/cache/{...}/release/obfuscation

#### -remove-comments

删除编译生成的声明文件中的JsDoc注释。  

**注意**：  

编译生成的源码文件中的注释默认会被全部删除，不支持配置保留。  
可通过`keep-comments`配置来保留编译生成的声明文件中的JsDoc注释。

### 保留选项

#### `-keep-property-name` [,identifiers,...]

指定想保留的属性名，支持使用名称类通配符。例如下面的例子:

```
-keep-property-name
age
firstName
lastName
```

> **注意**：
>
> - 该选项在开启`-enable-property-obfuscation`时生效
>
> - 属性白名单作用于全局。即代码中出现多个重名属性，只要与`-keep-property-name`配置白名单名称相同，均不会被混淆。

**哪些属性名应该被保留?**

为了保障混淆的正确性，建议保留所有不通过点语法访问的属性。

例子:

```
var obj = {x0: 0, x1: 0, x2: 0};
for (var i = 0; i <= 2; i++) {
    console.info(obj['x' + i]);  // x0, x1, x2 应该被保留
}

Object.defineProperty(obj, 'y', {});  // y 应该被保留
console.info(obj.y);

obj.s = 0;
let key = 's';
console.info(obj[key]);        // s 应该被保留

obj.u = 0;
console.info(obj.u);           // u 可以被正确地混淆

obj.t = 0;
console.info(obj['t']);        // 在开启字符串字面量属性名混淆时t和't'会被正确地混淆，但是建议保留

obj['v'] = 0;
console.info(obj['v']);        // 在开启字符串字面量属性名混淆时'v'会被正确地混淆，但是建议保留
```

对于间接导出的场景，例如`export MyClass`和`let a = MyClass; export {a};`，如果不想混淆它们的属性名，那么需要使用[保留选项](#保留选项)来保留这些属性名。另外，对于直接导出的类或对象的属性的属性名，例如下面例子中的`name`和`age`, 如果不想混淆它们，那么也需要使用[保留选项](#保留选项)来保留这些属性名。

```
export class MyClass {
    person = {name: "123", age: 100};
}
```

so库的API（例如示例中的foo），如果要在ArkTS/TS/JS文件中使用需手动保留API名称。

```
import testNapi from 'library.so'
testNapi.foo() // foo需要保留，示例如：-keep-property-name foo
```

使用到的json文件中的字段，需要手动保留。

```
const jsonData = ('./1.json')
let jsonStr = JSON.parse(jsonData)
let jsonObj = jsonStr.jsonProperty  // jsonProperty 需要被保留
```

使用到的数据库相关的字段，需要手动保留。

```
const dataToInsert = {  
  value1: 'example1',   // value1 需要被保留
};
```

源码中自定义装饰器修饰了成员变量、成员方法、参数，同时其源码编译的中间产物为js文件时（如编译release源码HAR或者源码包含@ts-ignore、@ts-nocheck），这些装饰器所在的成员变量/成员方法名称需要被保留。这是由于ts高级语法特性转换为js标准语法时，将上述装饰器所在的成员变量/成员方法名称硬编码为字符串常量。

示例：

```
class A {
  // 1.成员变量装饰器
  @CustomDecoarter
  propetyName: string = ""   // propetyName 需要被保留
  // 2.成员方法装饰器
  @MethodDecoarter
  methodName1(){} // methodName1 需要被保留
  // 3.方法参数装饰器
  methodName2(@ParamDecorator param: string): void { // methodName2 需要被保留
  }
}
```

#### `-keep-global-name` [,identifiers,...]

指定要保留的顶层作用域的名称，支持使用名称类通配符。例如，

```
-keep-global-name
Person
printPersonName
```

namespace中导出的名称也可以通过`-keep-global-name`保留。

```
export namespace Ns {
  export const age = 18; // -keep-global-name age 保留变量age
  export function myFunc () {}; // -keep-global-name myFunc 保留函数myFunc
}
```

> **注意**
>
> `-keep-global-name`指定的白名单作用于全局。即代码中出现多个顶层作用域名称或者导出名称，只要与`-keep-global-name`配置的白名单名称相同，均不会被混淆。

**哪些顶层作用域的名称应该被保留?**

在JavaScript中全局变量是`globalThis`的属性。如果在代码中使用`globalThis`去访问全局变量，那么该变量名应该被保留。

示例:

```
var a = 0;
console.info(globalThis.a);  // a 应该被保留

function foo(){}
globalThis.foo();           // foo 应该被保留

var c = 0;
console.info(c);             // c 可以被正确地混淆

function bar(){}
bar();                      // bar 可以被正确地混淆

class MyClass {}
let d = new MyClass();      // MyClass 可以被正确地混淆
```

当以命名导入的方式导入 so 库的 API时，若同时开启`-enable-toplevel-obfuscation`和`-enable-export-obfuscation`选项，需要手动保留 API 的名称。

```
import { testNapi, testNapi1 as myNapi } from 'library.so' // testNapi 和 testNapi1 应该被保留
```

#### `-keep-file-name` [,identifiers,...]

指定要保留的文件/文件夹的名称(不需要写文件后缀)，支持使用名称类通配符。例如，

```
-keep-file-name
index
entry
```

**哪些文件名应该被保留?**

1.在使用`require`引入文件路径时，由于`ArkTS`不支持[CommonJS](../arkts-utils/module-principle.md#commonjs模块)语法，因此这种情况下路径应该被保留。

```
const module1 = require('./file1')   // file1 应该被保留
```

2.对于动态引用方式，由于无法识别`import`函数中的参数是否为路径，因此这种情况下路径应该被保留。

```
const moduleName = './file2'         // file2 应该被保留
const module2 = import(moduleName)
```

3.在使用[动态路由](../ui/arkts-navigation-navigation.md#跨包动态路由)进行路由跳转时，传递给路由的路径应该被保留。动态路由提供系统路由表和自定义路由表两种方式。若采用自定义路由表进行跳转，配置白名单的方式与上述第二种动态引用场景一致。而若采用系统路由表进行跳转，则需要将模块下`resources/base/profile/route_map.json`文件中`pageSourceFile`字段对应的路径添加到白名单中。

```
  {
    "routerMap": [
      {
        "name": "PageOne",
        "pageSourceFile": "src/main/ets/pages/directory/PageOne.ets",  // 路径都应该被保留
        "buildFunction": "PageOneBuilder",
        "data": {
          "description" : "this is PageOne"
        }
      }
    ]
  }
```

#### `-keep-comments` [,identifiers,...]

保留编译生成的声明文件中class, function, namespace, enum, struct, interface, module, type及属性上方的JsDoc注释，支持使用名称类通配符。例如想保留声明文件中Human类上方的JsDoc注释，可进行以下配置：

```
-keep-comments
Human
```

**注意**：

1. 该选项在开启`-remove-comments`时生效
2. 当编译生成的声明文件中class, function, namespace, enum, struct, interface, module, type及属性的名称被混淆时，该元素上方的JsDoc注释无法通过`-keep-comments`保留。例如当在`-keep-comments`中配置了exportClass时，如果exportClass类名被混淆，其JsDoc注释无法被保留：

```
/*
 * @class exportClass
 */
export class exportClass {}
```

#### `-keep-dts` filepath

指定路径的`.d.ts`文件中的名称（例如变量名、类名、属性名等）会被添加至`-keep-global-name`和`-keep-property-name`白名单中。请注意，`filepath`仅支持绝对路径，并且可以指定为一个目录。在这种情况下，该目录中所有`.d.ts`文件中的名称都将被保留。

#### `-keep` filepath

保留指定相对路径中的所有名称（例如变量名、类名、属性名等）不被混淆。这个路径可以是文件与文件夹，若是文件夹，则文件夹下的文件及子文件夹中文件都不混淆。  
路径仅支持相对路径，`./`与`../`为相对于混淆配置文件所在目录，支持使用路径类通配符。

```
-keep
./src/main/ets/fileName.ts   // fileName.ts中的名称不混淆
../folder                    // folder目录下文件及子文件夹中的名称都不混淆
../oh_modules/json5          // 引用的三方库json5里所有文件中的名称都不混淆
```

**注意**：

1. 被`-keep filepath`所保留的文件，其依赖链路上的文件中导出名称及其属性都会被保留。
2. 该功能不影响文件名混淆`-enable-filename-obfuscation`的功能。

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
| ?     | 匹配任意单个字符，除了路径分隔符`/`                                      | "../a?"能匹配"../ab"等，但不能匹配"../a/"         |
| \*      | 匹配任意数量的任意字符，除了路径分隔符`/`                                | "../a*/c"能匹配"../ab/c"，但不能匹配"../ab/d/s/c" |
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

表示路径../a/b/中，除了c.ets文件以外的其它文件都不会被混淆。其中，`!`不可单独使用，只能用来排除白名单中已有的情况：

```
-keep
../a/b/
!../a/b/c.ets
```

表示路径../a/中的所有文件（不包含子文件夹）不会被混淆：

```
-keep
../a/*
```

表示路径../a/下的所有文件夹（包含子文件夹）中的所有文件不会被混淆：

```
-keep
../a/**
```

表示模块内的所有文件不会被混淆：

```
-keep
./**
```

**注意**：

(1)以上选项，不支持配置通配符`*`、`?`、`!`作其它含义使用。
例如：

```
class A {
  '*'= 1
}

-keep-property-name
*
```

此时`*`表示匹配任意数量的任意字符，配置效果为所有属性名称都不混淆，而不是只有`*`属性不被混淆。

(2)-keep选项中只允许使用`/`路径格式，不支持`\`或`\\`。

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
* 远程依赖的HAR包中的`obfuscation.txt`文件

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

如果构建的是HAR，那么最终的`obfuscation.txt`文件内容来自于自身和本地依赖的library的`consumerFiles`选项，以及依赖的HAR的`obfuscation.txt`文件的合并。

当`consumerFiles`指定的混淆配置文件中包含以下混淆规则时，这些混淆规则会被合并到HAR包的`obfuscation.txt`文件中，而其他混淆规则不会。

```
// 混淆选项
-enable-property-obfuscation
-enable-string-property-obfuscation
-enable-toplevel-obfuscation
-compact
-remove-log

// 保留选项
-keep-property-name
-keep-global-name
```

**library中混淆注意事项**

1. 如果`consumerFiles`指定的混淆配置文件中包含上述混淆选项，当其他模块依赖该HAR包时，这些混淆选项会与主模块的混淆规则合并，从而影响主模块。因此不建议开发者在`consumer-rules.txt`文件中配置混淆选项，建议仅配置保留选项。

2. 如果在`consumerFiles`指定的混淆配置文件中添加`-keep-dts`选项，会被转换成`-keep-global-name`和`-keep-property-name`。

## 报错栈还原

经过混淆的应用程序中代码名称会发生更改，crash时打印的报错栈更难以理解，因为报错栈与源码不完全一致。开发人员可使用DevEco Studio命令工具Command Line Tools中的hstack插件来还原源码堆栈，进而分析问题。反混淆工具需要使用应用编译过程中生成的sourceMaps.map文件以及混淆名称映射文件nameCache.json文件，因此请本地备份它们。

![obfuscation-product](figures/obfuscation-product.png)

## 说明

* 目前不支持在hvigor构建流程中插入自定义混淆插件
* 混淆的HAR包被模块依赖，若模块开启混淆，则HAR包会被二次混淆
* DevEco Studio右上角Product选项，将其中Build Mode选择release，可开启release编译模式
![product-release](figures/product-release.png)

## FAQ

### 混淆各功能上线SDK版本

| 混淆选项 | 功能描述  | 最低版本号 |
| ------- | --------- | ------ |
| -disable-obfuscation         | 关闭混淆 | 4.0.9.2 |
| -enable-property-obfuscation | 属性混淆 | 4.0.9.2 |
| -enable-string-property-obfuscation | 字符串字面量属性名混淆 | 4.0.9.2 |
| -enable-toplevel-obfuscation | 顶层作用域名称混淆 | 4.0.9.2 |
| -enable-filename-obfuscation | HAR包文件/文件夹名称混淆 <br> HAP/HSP文件/文件夹名称混淆 | 4.1.5.3 <br> 5.0.0.19 |
| -enable-export-obfuscation   | 向外导入或导出的名称混淆 | 4.1.5.3 |
| -compact                     | 去除不必要的空格符和所有的换行符 | 4.0.9.2 |
| -remove-log                  | 删除特定场景中的console.* | 4.0.9.2 |
| -print-namecache             | 将名称缓存保存到指定的文件路径 | 4.0.9.2 |
| -apply-namecache             | 复用指定的名称缓存文件 | 4.0.9.2 |
| -remove-comments             | 删除文件中所有注释 | 4.1.5.3 |
| -keep-property-name          | 保留属性名 | 4.0.9.2 |
| -keep-global-name            | 保留顶层作用域的名称 | 4.0.9.2 |
| -keep-file-name              | 保留HAR包的文件/文件夹的名称 <br> 保留HAP/HSP包的文件/文件夹的名称 | 4.1.5.3 <br> 5.0.0.19 |
| -keep-dts                    | 保留指定路径的.d.ts文件中的名称 | 4.0.9.2 |
| -keep-comments               | 保留编译生成的声明文件中class, function, namespace, enum, struct, interface, module, type及属性上方的JsDoc注释 | 4.1.5.3 |
| -keep                        | 保留指定路径中的所有名称 | 5.0.0.18 |
| 通配符                       | 名称类和路径类的保留选项支持通配符 | 5.0.0.24 |

### 如何查看混淆效果

开发人员可以在编译产物build目录中找到混淆后的文件，以及混淆生成的名称映射表及系统API白名单文件。

* 混淆后的文件目录：`build/default/[...]/release/模块名`
* 混淆名称映射表及系统API白名单目录：`build/default/[...]/release/obfuscation`
  * 名称映射表文件：nameCache.json，该文件记录了源码名称混淆的映射关系。
  * 系统API白名单文件：systemApiCache.json，该文件记录了SDK中的接口与属性名称，与其重名的源码不会被混淆。

  ![build-product](figures/build-product.png)

### 如何排查功能异常

1. 先在obfuscation-rules.txt配置-disable-obfuscation选项关闭混淆，确认问题是否由混淆引起。
2. 若确认是开启混淆后功能出现异常，请先阅读文档了解[-enable-property-obfuscation](#混淆选项)、[-enable-toplevel-obfuscation](#混淆选项)、[-enable-filename-obfuscation](#混淆选项)、[-enable-export-obfuscation](#混淆选项)等混淆规则的能力以及哪些语法场景需要配置白名单来保证应用功能正常。下文简要介绍默认开启的四项选项功能，细节还请阅读对应选项的完整描述。
    1.[-enable-toplevel-obfuscation](#混淆选项)为顶层作用域名称混淆开关。
    2.[-enable-property-obfuscation](#混淆选项)为属性混淆开关，配置白名单的主要场景为网络数据访问、json字段访问、动态属性访问、调用so库接口等不能混淆场景，需要使用[-keep-property-name](#保留选项)来保留指定的属性名称。
    3.[-enable-export-obfuscation](#混淆选项)为导出名称混淆，一般与1、2选项配合使用；配置白名单的主要场景为模块对外接口不能混淆，需要使用[-keep-global-name](#保留选项)来指定保留导出/导入名称。
    4.[-enable-filename-obfuscation](#混淆选项)为文件名混淆，配置白名单的主要场景为动态import或运行时直接加载的文件路径，需要使用[-keep-file-name](#保留选项)来保留这些文件路径及名称。
3. 参考FAQ中的[常见报错案例](#常见报错案例)，若是相似场景可参考对应的解决方法快速解决。
4. 若常见案例中未找到相似案例，建议依据各项配置功能正向定位（若不需要相应功能，可删除对应配置项）。
5. 应用运行时崩溃分析方法：
    1.打开应用运行日志或者点击DevEco Studio中出现的Crash弹窗，找到运行时崩溃栈。
    2.应用运行时崩溃栈中的行号为[编译产物](#如何查看混淆效果)的行号，方法名也可能为混淆后名称；因此排查时建议直接根据崩溃栈查看编译产物，进而分析哪些名称不能被混淆，然后将其配置进白名单中。
6. 应用在运行时未崩溃但出现功能异常的分析方法（比如白屏）：
    1.打开应用运行日志：选择HiLog，检索与功能异常直接相关的日志，定位问题发生的上下文。
    2.定位异常代码段：通过分析日志，找到导致功能异常的具体代码块。
    3.增强日志输出：在疑似异常的功能代码中，对处理的数据字段增加日志记录。
    4.分析并确定关键字段：通过对新增日志输出的分析，识别是否由于混淆导致该字段的数据异常。
    5.配置白名单保护关键字段：将确认在混淆后对应用功能产生直接影响的关键字段添加到白名单中。

### 常见报错案例

#### 开启-enable-property-obfuscation选项可能出现的问题

**案例一：报错内容为 Cannot read property 'xxx' of undefined**

```
// 混淆前
const jsonData = ('./1.json')
let jsonStr = JSON.parse(jsonData)
let jsonObj = jsonStr.jsonProperty

// 混淆后
const jsonData = ('./1.json')
let jsonStr = JSON.parse(jsonData)
let jsonObj = jsonStr.i
```

开启属性混淆后，"jsonProperty" 被混淆成随机字符 "i"，但json文件中为原始名称，从而导致值为undefined。

**解决方案：** 使用`-keep-property-name`选项将json文件里的字段配置到白名单。

**案例二：使用了数据库相关的字段，开启属性混淆后，出现报错**

报错内容为 `table Account has no column named a23 in 'INSET INTO Account(a23)'`

代码里使用了数据库字段，混淆时该SQL语句中字段名称被混淆，但数据库中字段为原始名称，从而导致报错。

**解决方案：** 使用`-keep-property-name`选项将使用到的数据库字段配置到白名单。

#### 开启-enable-export-obfuscation和-enable-toplevel-obfuscation选项可能出现的问题

**当开启这两个选项时，主模块调用其他模块方法时涉及的方法名称混淆情况如下：**

| 主模块 | 依赖模块 | 导入与导出的名称混淆情况 |
| ------- | ------- | ----------------------------|
| HAP/HSP | HSP     | HSP和主模块是独立编译的，混淆后名称会不一致，因此都需要配置白名单 |
| HAP/HSP | 本地HAR | 本地HAR与主模块一起编译，混淆后名称一致 |
| HAP/HSP | 三方库  | 三方库中导出的名称及其属性会被收集到白名单，因此导入和导出时都不会被混淆 |

HSP需要将给其他模块用的方法配置到白名单中。因为主模块里也需要配置相同的白名单，所以推荐将HSP配置了白名单的混淆文件(假设名称为hsp-white-list.txt)添加到依赖它的模块的混淆配置项里，即下图files字段里。

![obfuscation-config](figures/obfuscation-config.png)

**案例一：动态导入某个类，类定义的地方被混淆，导入类名时却没有混淆，导致报错**

```
// 混淆前
export class Test1 {}

let mytest = (await import('./file')).Test1

// 混淆后
export class w1 {}

let mytest = (await import('./file')).Test1
```

导出的类 "Test1" 是一个顶层作用域名，当 "Test1" 被动态使用时，它是一个属性。因为没有开启`-enable-property-obfuscation`选项，所以名称混淆了，但属性没有混淆。

**解决方案：** 使用`-keep-global-name`选项将 "Test1" 配置到白名单。

**案例二：在使用namespace中的方法时，该方法定义的地方被混淆了，但使用的地方却没有被混淆，导致报错**

```
// 混淆前
export namespace ns1 {
  export class person1 {}
}

import {ns1} from './file1'
let person1 = new ns1.person1()

// 混淆后
export namespace a3 {
  export class b2 {}
}

import {a3} from './file1'
let person1 = new a3.person1()
```

namespace里的 "person1" 属于顶层作用域的class名称，通过 "ns1.person1" 来调用时，它是属于一个属性，由于未开启属性混淆，所以在使用它时没有被混淆。

**解决方案：**

1. 开启`-enable-property-obfuscation`选项。
2. 将namespace里导出的方法使用`-keep-global-name`选项添加到白名单。

**案例三：使用了`declare global`，混淆后报语法错误**

```
// 混淆前
declare global {
  var age : string
}

// 混淆后
declare a2 {
  var b2 : string
}
```

报错内容为 `SyntaxError: Unexpected token`

**解决方案：** 使用`-keep-global-name`选项将`__global`配置到白名单中。

#### 未开启-enable-string-property-obfuscation混淆选项，字符串字面量属性名却被混淆，导致字符串字面量属性名的值为undefined

```
person["age"] = 22; // 混淆前

person["b"] = 22; // 混淆后
```

**解决方案：**

1. 确认是否有依赖的HAR包开启了字符串属性名混淆，若开启了，则会影响主工程，需将其关闭。
2. 若不能关闭`-enable-string-property-obfuscation`选项，将属性名配置到白名单中。
3. 若依赖HAR包未开启字符串属性名混淆，同时SDK版本小于4.1.5.3，请更新SDK。

#### 开启-enable-filename-obfuscation选项后，可能会出现的问题

**案例一：报错为 Error Failed to get a resolved OhmUrl for 'D:code/MyApplication/f12/library1/pages/d.ets' imported by 'undefined'**

工程的目录结构如下图所示，模块library1的外层还有目录 "directory"，开启文件名混淆后，"directory" 被混淆为f12，导致路径找不到。

![directory-offuscation](figures/directory-obfuscation.png)

**解决方案：**

1. 如果工程的目录结构和报错内容都相似，请将SDK更新至最低5.0.0.26版本。
2. 使用`-keep-file-name`将模块外层的目录名 "directory" 配置到白名单中。

**案例二：报错为 Cannot find module 'ets/appability/AppAbility' which is application Entry Point**

由于系统会在应用运行时加载ability文件，用户需要手动配置相应的白名单，防止指定文件被混淆，导致运行失败。

**解决方案：** 使用`-keep-file-name`选项，将`src/main/module.json5`文件中，'srcEntry'字段所对应的路径配置到白名单中。

```
-keep-file-name
appability
AppAbility
```

#### 使用-keep-global-name选项配置白名单时，可能会出现的问题

报错内容为 `Cannot read properties of undefined (reading 'has')`

**解决方案：** 将SDK更新至最低4.1.6.3版本。

#### HAP与HSP依赖相同的本地源码HAR模块，可能会出现的问题

* 若开启文件名混淆，会出现以下问题：
  * 问题一：单例功能异常问题。原因是HAP与HSP独立执行构建与混淆流程，本地源码HAR模块在HAP与HSP的包中可能会出现相同的文件名被混淆成不同文件名的情况。
  * 问题二：接口调用失败问题。原因是HAP与HSP独立执行构建与混淆流程，本地源码HAR模块在HAP与HSP的包中可能会出现不同的文件名被混淆成相同的文件名的情况。
* 若开启`-enable-export-obfuscation`和`-enable-toplevel-obfuscation`选项，在应用运行时会出现加载接口失败的问题。
原因是HAP与HSP独立执行构建与混淆流程，本地源码HAR模块中暴露的接口在HAP与HSP中被混淆成不同的名称。

**解决方案：**
1. 将HAP与HSP共同依赖的本地源码HAR改造为[字节码HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-hvigor-build-har-V5#section179161312181613)，这样此HAR在被依赖时不会被二次混淆。
2. 将HAP与HSP共同依赖的本地源码HAR以[release模式构建打包](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-hvigor-build-har-V5#section19788284410)，这样此HAR在被依赖时，其文件名与对外接口不会被混淆。

