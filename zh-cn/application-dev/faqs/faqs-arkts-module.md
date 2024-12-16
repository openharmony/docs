# ArkTS语言模块化加载异常常见问题


##  ArkTS 应用运行时出现模块化加载相关的异常报错提示，可能导致报错原因以及解决方法
### "Cannot find dynamic-import module 'xxxx'"

报错表示当前加载的模块未被编译到当前应用包内

**报错原因:**

通过动态加载传入表达式作为入参时，模块路径参数书写有误。
``` typescript
  import(module).then(m=>{m.foo();}).catch((e: Error)=>{console.info(e.message)});
```

**定位方法:**

将待加载module路径信息打印出来，评估模块路径是否计算有误。

### "Cannot find module 'xxxx' , which is application Entry Point" 
报错表示拉起应用abc时，执行入口文件查找失败

**报错原因:**

应用拉起时，应用入口文件模块查找失败。

**定位方法:**

(1) 打开应用工程级编译构建文件: entry > src/main/module.json5

([OpenHarmony工程管理介绍](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V3/ohos-project-overview-0000001218440650-V3))
module.json5部分参数示例如下:
```
{
  "module": {
    "name": "entry",
    "type": "entry",
    ...
    "abilities": [
      {
        "name": "EntryAbility", // 模块名称
        "srcEntry": "./ets/entryability/EntryAbility.ts",  // 标明src目录相对工程根目录的相对路径
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ]
  }
}
```
(2) 其中，"abilities":"srcEntry" 参数标记了该应用拉起的入口文件。如报错入口文件加载失败，请检查module.json5内的"srcEntry"参数是否书写正确。

### "No export named 'xxxx' which exported by 'xxxx'"
报错表示加载应用hap或har包内so时，该模块内未查找到特定对象

**报错原因:**

ets在模块化静态编译阶段，会预解析模块间依赖关系。ets文件内的导入变量名书写错误时，ide编译器与应用编译阶段均会报错提示。但目前对于应用内native C++模块的依赖关系检测会在运行阶段。

**定位方法:**

检查应用内so是否存在报错提示的导出变量，与加载应用内so导入变量处进行比较，不一致则适配修改。


## ArkTS/Ts/Js加载so失败，表现行为是怎么样的

加载so失败后，不显式抛出加载失败的js异常。开发者可以通过导出对象是否为undefined判断so的加载状态。

**加载失败具体表现**  

| 加载类型 | ts/js模块 | 系统库so或应用so |
| -------- | -------- | -------- |
| 静态加载 | 虚拟机自动抛出异常，进程退出 | 无异常抛出，加载到的对象为undefined |
| 动态加载 | 不主动抛出异常，走到reject分支，开发者可以调用catch方法来捕获这个错误 | 不主动抛出异常，依然进入resolve分支，开发者可以在resolve分支中检查模块导出变量是否为undefined |
 
**示例1：系统库so或应用so静态加载失败**

```
import testNapi from 'libentry.so'

if (testNapi == undefined) {
  console.error('load libentry.so failed.');
}
```

执行结果
```
load libentry.so failed.
```

**示例2：系统库so或应用so动态加载失败**

```
import('libentry.so')
  .then(m => {
    if (typeof m.default === 'undefined') {
      console.warn(`load libentry.so failed.`);
    } else {
      console.info('load libentry.so success:', m);
    }
    return m;
  })
  .catch((e: Error) => {
    console.error('load libentry.so error:', e);
  });
```

执行结果
```
load libentry.so failed.
```

**so加载失败可能的原因、定位方式以及解决方法**  

参考([Node-API常见问题](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/napi/use-napi-faqs.md))文档


## 模块间循环依赖导致运行时未初始化异常问题定位

模块间的循环依赖往往是存在这种文件依赖情况：
```ts
// file1
  export {b} from './file2'
  export {a} from './A'

// file2
  import {a} from './file1'
  export let b:number = a;

// A
  export let a:number = 50;
```
如上代码会报错：
```
Error message:a is not initialized
```

但如果仅仅是更换file1的加载顺序：
```ts
// file1
  export {a} from './A'
  export {b} from './file2'
// file2
  import {a} from './file1'
  export let b:number = a;
// A
  export let a:number = 50;
```
以上代码就不会报错。此时执行顺序：file1加载A, A文件无依赖；返回file1继续加载file2, file2文件加载file1时，变量a文件所在的A已经执行完成，因此正常加载。
开发者需注意，模块化编译采用的是深度遍历加载。

### 循环依赖的解决方法：
[安全规则@security/no-cycle](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide_no-cycle-V5)


##  ArkTS 符号未初始化报错场景示例

ArkTS语言规范是基于ECMAScript规范的子集，根据语言规范，当访问一个还未完成初始化的符号时，运行时会抛出异常，为便于开发者定位解决源码问题，提供以下常见报错场景示例用于参考。

### const/let声明前访问

``` typescript
console.log(a); // 报错信息：Variable 'a' is used before being assigned.
console.log(b); // 报错信息：Variable 'b' is used before being assigned.

let a = '1';
const b = '2';
```
**正例**

```
let a = '1';
const b = '2';

console.log(a);
console.log(b);
```


### class声明前实例化

``` typescript
let a = new A(); // 报错信息：Class 'A' used before its declaration.

class A {}
```

**正例**

```
class A {}

let a = new A();
```

### class声明前访问其静态属性

``` typescript
let a = A.a; // 报错信息：Class 'A' used before its declaration.

class A {
  static a = 1;
}
```

**正例**

```
class A {
  static a = 1;
}

let a = A.a;
```

### 在函数中访问未提前声明的let和const变量

``` typescript
foo(); // 报错信息：Error message:a is not initialized

let a = 1;
const b = 2;

function foo() {
  let v = a + b;
}
```

**正例**

```
let a = 1;
const b = 2;

function foo() {
  let v = a + b;
}

foo();
```

### 在函数中访问未提前声明的类的静态属性

``` typescript
foo(); // 报错信息：Error message:A is not initialized

class A {
  static a = 1;
}

function foo() {
  let v = A.a;
  let w = new A();
}
```

**正例**

```
class A {
  static a = 1;
}

function foo() {
  let v = A.a;
  let w = new A();
}

foo();
```

### 模块间循环依赖 - const/let

``` typescript
// module1.ets
import { a, b } from './module2'

export let i = 1;
export let m = a;
export const j = 2;
export const n = b;

// ---------------------

// module2.ets
import { i, j } from './module1'

export let a = i; // 报错信息：Error message:i is not initialized
export const b = j; // 报错信息：Error message:j is not initialized
```

**解决方法**

详见[循环依赖的解决方法](#循环依赖的解决方法)


### 模块间循环依赖 - class

``` typescript
// class1.ets
import { b } from './class2'

export class A {
  static a = b;
}

// ---------------------

// class2.ets
import { A } from './class1'
export let b = 1;

const i = A.a; // 报错信息：Error message:A is not initialized
const j = new A(); // 报错信息：Error message:A is not initialized
```

**解决方法**

详见[循环依赖的解决方法](#循环依赖的解决方法)