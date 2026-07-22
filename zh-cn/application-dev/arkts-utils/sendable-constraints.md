# Sendable使用规则与约束
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

## 继承规则

### Sendable类必须继承自Sendable类

Sendable对象的布局和原型链不可变，而非Sendable对象可以通过特殊方式修改布局。因此，不允许互相继承。此处的继承规则针对类定义本身，不涉及类的实例变量。Sendable类只能继承自Sendable类的定义。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/inheritonly/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
@Sendable
class A {
  constructor() {
    console.info('hello world');
  }
}

@Sendable
class B extends A {
  constructor() {
    super()
  }
}
```

**反例：**

```ts
class A {
  constructor() {
  }
}

@Sendable
class B extends A { // A不是sendable class，B不能继承它，编译报错
  constructor() {
    super()
  }
}
```


### 非Sendable类必须继承自非Sendable类

Sendable对象的布局和原型链不可变，而非Sendable对象可以通过特殊方式修改布局，因此不允许互相继承。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/inheritedfromnon/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
class A {
  constructor() {
    console.info('hello world');
  }
}

class B extends A {
  constructor() {
    console.info('HELLO WORLD');
    super()
  }
}
```

**反例：**

```ts
@Sendable
class A {
  constructor() {
  }
}

class B extends A { // A是sendable class，B不能继承它，编译报错
  constructor() {
    super()
  }
}
```

## 接口实现规则

### 非Sendable类禁止实现Sendable接口

非Sendable类实现Sendable接口时，可能被误认为是Sendable类，导致错误使用。

**正例：**
<!-- @[counter_example_achieve_non](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/achievenon/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
interface I {
  a: string;
};

class B implements I {
  a: string = 'hello world';
};

// 反例：
// import { lang } from '@kit.ArkTS';

// type ISendable = lang.ISendable;

// interface I extends ISendable {};

// class B implements I {};
```

**反例：**

```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {};

class B implements I {};  // I是sendable interface，B不能实现，编译报错
```

## Sendable类/接口成员变量规则

### 必须是Sendable支持的数据类型

Sendable数据不得持有非Sendable数据，因此Sendable类或接口的成员变量必须是[Sendable支持的数据类型](arkts-sendable.md#sendable支持的数据类型)。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/variablesupport/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}

// 反例：
// @Sendable
// class A {
//   constructor() {}
//   b: Array<number> = [1, 2, 3] // 需使用collections.Array
// }
```

**反例：**

```ts
@Sendable
class A {
  constructor() {
  }
  b: Array<number> = [1, 2, 3] // 编译报错，需使用collections.Array
}
```


### 不支持使用!断言

Sendable对象的成员属性必须赋初值，而“!”修饰的变量可以不赋初值，因此不支持使用“!”。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/variablenotsupported/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}

// 反例：
// @Sendable
// class A {
//   constructor() {}
//   a!: number;
// }
```

**反例：**

```ts
@Sendable
class A {
  constructor() {
  }
  a!: number; // 编译报错，不支持使用“!”
}
```


### 不支持使用计算属性名

Sendable对象的布局不可更改，因为计算属性无法静态确定对象布局，所以不支持。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/nocalculationsupport/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
@Sendable
class A {
  num1: number = 1;
  num2: number = 2;

  add(): number {
    return this.num1 + this.num2;
  }
}
```

**反例：**

```ts
enum B {
    b1 = 'bbb'
}
@Sendable
class A {
    ['aaa']: number = 1; // 编译报错，不支持['aaa']
    [B.b1]: number = 2; // 编译报错，不支持[B.b1]
}
```

### 不支持使用类型别名

Sendable类的成员变量不能使用类型别名（即使用`type`关键字定义的别名）。

**正例：**

```ts
@Sendable
class B {
  num1: number = 1;
  num2: number = 2;
  add(): number {
    return this.num1 + this.num2;
  }
}
```

**反例：**

```ts
type A = number;

@Sendable
class B {
  num1: A = 1; // 运行报错，不支持使用类型别名
  num2: A = 2; // 运行报错，不支持使用类型别名
  add(): number {
    return this.num1 + this.num2;
  }
}
```

## 泛型规则

### 泛型类中的Sendable类、SendableLruCache、collections.Array、collections.ConcatArray、collections.Map和collections.Set的模板类型必须是Sendable类型

Sendable数据不能持有非Sendable数据，因此泛型类中的Sendable数据的模版类型必须是Sendable类型。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/templatetype/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { collections } from '@kit.ArkTS';

try {
  let arr: collections.Array<number> = new collections.Array<number>();
  let num: number = 1;
  arr.push(num);
} catch (e) {
  console.error(`create collections error: Code: ${e.code}, message: ${e.message}`);
}
```

**反例：**

```ts
import { collections } from '@kit.ArkTS';

try {
  let arr1: collections.Array<Array<number>> = new collections.Array<Array<number>>(); // 编译报错，模板类型必须是Sendable类型
  let arr2: Array<number> = new Array<number>();
  arr2.push(1);
  arr1.push(arr2);
} catch (e) {
  console.error(`create collections error: Code: ${e.code}, message: ${e.message}`);
}
```


## 上下文访问规则

### Sendable类的内部不允许使用当前模块内上下文环境中定义的变量

由于Sendable对象在不同并发实例间的上下文环境不同，属于单个虚拟机实例，如果直接访问会有非预期行为。不支持Sendable对象使用当前模块内上下文环境中定义的变量，违反此规则会在编译阶段报错。

> **说明：**
>
> 从API version 12开始，Sendable class的内部支持使用top level的Sendable class对象。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/notallowedInside/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {}

@Sendable
class B implements I {
  static o: number = 1;

  static bar(): B {
    return new B();
  }
}

@Sendable
class C {
  v: I = new B();
  u: number = B.o;

  foo() {
    return B.bar();
  }
}
```

**反例：**

```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {}

@Sendable
class B implements I {}

function bar(): B {
  return new B();
}

let b = new B();

{
  @Sendable
  class A implements I {}

  @Sendable
  class C {
    u: I = bar(); // bar不是sendable function对象，编译报错
    v: I = new A(); // A不是定义在top level中，编译报错

    foo() {
      return b; // b不是sendable class对象，而是sendable class的实例，编译报错
    }
  }
}
```

## \@Sendable装饰器使用规则

### \@Sendable装饰器仅支持修饰类和函数

当前仅支持修饰类和函数。

**正例：**
<!-- @[counter_example_only_support](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/achievenon/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
@Sendable
type SendableFuncType = () => void;

// 反例：
// @Sendable
// type A = number; // 编译报错

// @Sendable
// class C {}

// @Sendable
// type D = C; // 编译报错
```

**反例：**

```ts
@Sendable
type A = number; // 编译报错

@Sendable
class C {}

@Sendable
type D = C; // 编译报错
```

### Sendable类和Sendable函数禁止使用除\@Sendable外的装饰器

在ts文件中定义类装饰器时，可能会改变类的结构，进而引发运行时错误。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/cannotbeused/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
@Sendable
class A {
  num: number = 1;
}

// 反例：
// @Sendable
// @Observed
// class C {
//   num: number = 1;
// }
```

**反例：**

```ts
@Sendable
@Observed // 编译报错
class C {
  num: number = 1;
}
```

### 支持在Sendable class上叠加自定义装饰器

从API version 22开始，支持在Sendable class上叠加使用除@Sendable装饰器之外的其他自定义装饰器。 

通过在[工程级build-profile.json5文件](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app)的"buildOption"字段下的"strictMode"中增加"disableSendableCheckRules"字段，配置该能力。

"disableSendableCheckRules"字段及其具体取值示例如下： 

```json5
"buildOption": {
  "strictMode": {
    "caseSensitiveCheck": true,
    "useNormalizedOHMUrl": true,
    "disableSendableCheckRules": ["arkts-sendable-class-decorator"]
  }
}
```

> **说明：**
>
> - "disableSendableCheckRules"字段值为包含Sendable规则的数组。
> 
>   - 默认不展示，即默认不支持在Sendable class上叠加使用除@Sendable之外的其他自定义装饰器。
>
>   - 禁止配置为空数组。
>   
>   - 当数组中配置了"arkts-sendable-class-decorator"规则时，支持在Sendable class上叠加除@Sendable之外的其他自定义装饰器。
>   
> - @Sendable和其他自定义装饰器叠加使用可能造成运行时异常，需要开发者适配装饰器函数的实现。

## 初始化规则

### 禁止使用对象字面量/数组字面量初始化Sendable对象

对象字面量和数组字面量不是Sendable类型。Sendable类型必须通过Sendable类型的new表达式创建。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/objectliterals/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
import { collections } from '@kit.ArkTS';

let arr1: collections.Array<number> = new collections.Array<number>(1, 2, 3); // 是Sendable类型

// 反例：
// import { collections } from '@kit.ArkTS';

// let arr2: collections.Array<number> = [1, 2, 3]; // 不是Sendable类型，编译报错
// let arr3: number[] = [1, 2, 3]; // 不是Sendable类型，正例，不报错
// let arr4: number[] = new collections.Array<number>(1, 2, 3); // 编译报错
```

**反例：**

```ts
import { collections } from '@kit.ArkTS';

let arr2: collections.Array<number> = [1, 2, 3]; // 不是Sendable类型，编译报错
let arr3: number[] = [1, 2, 3]; // 不是Sendable类型，正例，不报错
let arr4: number[] = new collections.Array<number>(1, 2, 3); // 编译报错
```

## 类型转换规则

### 禁止非Sendable类型强制转换为Sendable

除了Object类型，非Sendable类型不能强转成Sendable类型。非Sendable类型通过as强转成Sendable类型后，实际数据仍为非Sendable类型，会导致错误使用。Sendable类型在不违反Sendable规则的前提下，需要和非Sendable类型行为兼容，因此Sendable类型可以通过as强转成非Sendable类型。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/typecannot/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
class A {
  state: number = 0;
}

@Sendable
class SendableA {
  state: number = 0;
}

let a1: A = new SendableA() as A;

// 反例：
// class A {
//   state: number = 0;
// }

// @Sendable
// class SendableA {
//   state: number = 0;
// }

// let a2: SendableA = new A() as SendableA;
```

**反例：**

```ts
class A {
  state: number = 0;
}

@Sendable
class SendableA {
  state: number = 0;
}

let a2: SendableA = new A() as SendableA; // 编译报错
```

## 函数规则

### 箭头函数不可标记为Sendable

箭头函数不支持\@Sendable装饰器，因此它是非Sendable函数，不支持共享。

**正例：**
<!-- @[counter_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/RulesAndRestrictions/arrowfunctions/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// 正例：
@Sendable
type SendableFuncType = () => void;

@Sendable
function sendableFunc() {
  console.info('Sendable func');
}

@Sendable
class SendableClass {
  constructor(f: SendableFuncType) {
    this.func = f;
  }

  func: SendableFuncType;
}

let sendableClass = new SendableClass(sendableFunc);

// 反例：
// @Sendable
// type SendableFuncType = () => void;
// let func: SendableFuncType = () => {}; // 编译报错

// @Sendable
// class SendableClass {
//   func: SendableFuncType = () => {}; // 编译报错
// }
```

**反例：**

```ts
@Sendable
type SendableFuncType = () => void;
let func: SendableFuncType = () => {}; // 编译报错

@Sendable
class SendableClass {
  func: SendableFuncType = () => {}; // 编译报错
}
```

## 与TS/JS交互的规则

### ArkTS通用规则（目前只针对Sendable对象）

| 规则 |
| -------- |
| Sendable对象传入TS/JS的接口中，禁止操作其对象布局（增、删属性，改变属性类型）。 |
| Sendable对象设置到TS/JS的对象上，TS中获取到Sendable对象后，禁止操作其对象布局（增、删属性，改变属性类型）。 |
| Sendable对象放入TS/JS的容器中，TS中获取到Sendable对象后，禁止操作其对象布局（增、删属性，改变属性类型）。 |

> **说明：**
>
> 改变属性类型不包括Sendable对象类型的改变，例如从Sendable class A变为Sendable class B。


### NAPI规则（目前只针对Sendable对象）

NAPI相关接口请参考[Sendable相关的NAPI接口](../napi/use-napi-about-extension.md#sendable相关)，具体使用请参考[Native与Sendable ArkTS对象绑定](../napi/use-sendable-napi.md)。

| 规则 |
| -------- |
| 禁止删除属性。不能使用napi_delete_property接口。 |
| 禁止新增属性。不能使用napi_set_property、napi_set_named_property、napi_define_properties接口。 |
| 禁止修改属性类型。不能使用napi_set_property、napi_set_named_property、napi_define_properties接口。 |
| 不支持Symbol相关接口和类型。不能使用napi_create_symbol、napi_is_symbol_object、napi_symbol接口。 |


## 与UI交互的规则

Sendable数据需要与[makeObserved](../ui/state-management/arkts-new-makeObserved.md)配合使用，才可以观察Sendable对象的数据变化，具体使用请参考[makeObserved和@Sendable装饰的class配合文档](../ui/state-management/arkts-new-makeObserved.md#makeobserved和sendable装饰的class配合使用)。


## 在HAR包中的使用规则

Sendable可在[HAR](../quick-start/har-package.md)包中使用。当在字节码HAR中使用Sendable时，无需进行额外配置，可直接使用。当在TS HAR中使用Sendable时，需在HAR模块下的module.json5文件中将"metadata"字段下的"name"设置为“UseTsHar”，配置如下所示。

<!-- @[har_package_014](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HarPackage/library/src/main/module.json5) -->

``` JSON5
{
  "module": {
    "name": "library",
    "type": "har",
    "deviceTypes": [
      "tablet",
      "2in1"
    ],
    "metadata": [
      {
        "name": "UseTsHar",
        "value": "true"
      }
    ]
  }
}
```