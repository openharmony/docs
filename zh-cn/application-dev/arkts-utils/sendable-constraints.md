# Sendable使用规则与约束

## Sendable class只能继承自Sendable class

Sendable对象布局及原型链不可变，非Sendable对象可以通过特殊方式修改布局，不允许互相继承。这里的class不包括变量。Sendable class不能继承自变量。

**正例：**

```ts
@Sendable
class A {
  constructor() {
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
class B extends A {
  constructor() {
    super()
  }
}
```


## 非Sendable class只能继承自非Sendable class

Sendable对象布局及原型链不可变，由于非Sendable对象可以通过特殊方式修改布局，因此不允许互相继承。

**正例：**

```ts
class A {
  constructor() {
  }
}

class B extends A {
  constructor() {
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

class B extends A {
  constructor() {
    super()
  }
}
```


## 非Sendable class只能实现非Sendable interface

如果非Sendable class实现了Sendable interface，可能会被认为是Sendable的，实际是非Sendable的，导致错误使用。

**正例：**

```ts
interface I {};

class B implements I {};
```

**反例：**

```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {};

class B implements I {};
```


## Sendable class/interface成员变量必须是Sendable支持的数据类型

Sendable数据不能持有非Sendable数据，因此Sendable数据的成员属性必须为Sendable数据。

**正例：**

```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**反例：**

```ts
@Sendable
class A {
  constructor() {
  }
  b: Array<number> = [1, 2, 3] // 需使用collections.Array
}
```


## Sendable class/interface的成员变量不支持使用!断言

Sendable对象的成员属性必须赋初值，“!”修饰的变量可以不赋初值，因此不支持使用“!” 。

**正例：**

```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**反例：**

```ts
@Sendable
class A {
  constructor() {
  }
  a!: number;
}
```


## Sendable class/interface的成员变量不支持使用计算属性名

Sendable对象的布局不可变，计算属性不能静态确定对象布局，因此不支持。

**正例：**

```ts
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
    b1 = "bbb"
}
@Sendable
class A {
    ["aaa"]: number = 1; // ["aaa"] is allowed in other classes in ets files
    [B.b1]: number = 2; // [B.b1] is allowed in other classes in ets files
}
```


## 泛型类中的Sendable class，collections.Array，collections.Map，collections.Set的模板类型必须是Sendable类型

Sendable数据不能持有非Sendable数据，因此泛型类中的Sendable数据的模版类型必须是Sendable类型。

**正例：**

```ts
import { collections } from '@kit.ArkTS';

try {
  let arr1: collections.Array<number> = new collections.Array<number>();
  let num: number = 1;
  arr1.push(num);
} catch (e) {
  console.error(`taskpool execute: Code: ${e.code}, message: ${e.message}`);
}
```

**反例：**

```ts
import { collections } from '@kit.ArkTS';

try {
  let arr1: collections.Array<Array<number>> = new collections.Array<Array<number>>();
  let arr2: Array<number> = new Array<number>();
  arr2.push(1);
  arr1.push(arr2);
} catch (e) {
  console.error(`taskpool execute: Code: ${e.code}, message: ${e.message}`);
}
```


## Sendable class的内部不允许使用当前模块内上下文环境中定义的变量

由于Sendable对象在不同并发实例间的上下文环境不同，属于单个虚拟机实例，如果直接访问会有非预期行为。不支持Sendable对象使用当前模块内上下文环境中定义的变量，如果违反，编译阶段会报错。

> **说明：**
>
> 从API version 12开始，sendable class的内部支持使用top level的sendable class对象。

**正例：**

```ts
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
    u: I = bar(); // bar不是sendable class对象，编译报错
    v: I = new A(); // A不是定义在top level中，编译报错

    foo() {
      return b; // b不是sendable class对象，而是sendable class的实例，编译报错
    }
  }
}
```


## Sendable class和Sendable function不能使用除了\@Sendable的其它装饰器

如果类装饰器定义在ts文件中，产生修改类的布局的行为，那么会造成运行时的错误。

**正例：**

```ts
@Sendable
class A {
  num: number = 1;
}
```

**反例：**

```ts
@Sendable
@Observed
class C {
  num: number = 1;
}
```


## 不能使用对象字面量/数组字面量初始化Sendable类型

对象字面量/数组字面量是非Sendable类型，Sendable数据类型只能通过Sendable类型的new表达式创建。

**正例：**

```ts
import { collections } from '@kit.ArkTS';

let arr1: collections.Array<number> = new collections.Array<number>(1, 2, 3); // 是Sendable类型
```

**反例：**

```ts
import { collections } from '@kit.ArkTS';

let arr2: collections.Array<number> = [1, 2, 3]; // 不是Sendable类型，编译报错
let arr3: number[] = [1, 2, 3]; // 不是Sendable类型，正例，不报错
let arr4: number[] = new collections.Array<number>(1, 2, 3); // 编译报错
```


## 非Sendable类型不可以as成Sendable类型

除了Object类型，非Sendable类型不可以as成Sendable类型。非Sendable类型通过as强转成Sendable类型后实际是非Sendable的类型数据，会导致错误使用。Sendable类型在不违反Sendable规则的前提下需要和非Sendable类型行为兼容，因此Sendable类型可以as成非Sendable类型。

**正例：**

```ts
class A {
  state: number = 0;
}

@Sendable
class SendableA {
  state: number = 0;
}

let a1: A = new SendableA() as A;
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

let a2: SendableA = new A() as SendableA;
```


## 箭头函数不支持共享

箭头函数不支持使用Sendable装饰器，是非Sendable函数，因此不支持共享。

**正例：**

```ts
@Sendable
type SendableFuncType = () => void;

@Sendable
function SendableFunc() {
  console.info("Sendable func");
}

@Sendable
class SendableClass {
  constructor(f: SendableFuncType) {
    this.func = f;
  }
  func: SendableFuncType;
}

let sendableClass = new SendableClass(SendableFunc);
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


## Sendable装饰器修饰类型时仅支持修饰函数类型

当前仅支持声明Sendable函数类型，因此只能修饰函数类型。

**正例：**

```ts
@Sendable
type SendableFuncType = () => void;
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


## 注意事项


在HAR中使用Sendable时，需开启编译生成TS文件的配置。详情可查[编译生成TS文件](../quick-start/har-package.md#编译生成ts文件)。


## 与TS/JS交互的规则


### ArkTS通用规则（目前只针对Sendable对象）

| 规则 |
| -------- |
| Sendable对象传入TS/JS的接口中，禁止操作其对象布局（增、删属性，改变属性类型）。 |
| Sendable对象设置到TS/JS的对象上，TS中获取到这个Sendable对象后，禁止操作其对象布局（增、删属性，改变属性类型）。 |
| Sendable对象放入TS/JS的容器中，TS中获取到这个Sendable对象后，禁止操作其对象布局（增、删属性，改变属性类型）。 |

> **说明：**
>
> 此处改变属性类型不包括Sendable对象类型的改变，比如从Sendable class A 变为Sendable class B。


### NAPI规则（目前只针对Sendable对象）

| 规则 |
| -------- |
| 禁止删除属性，不能使用的接口有：napi_delete_property。 |
| 禁止新增属性，不能使用的接口有：napi_set_property、napi_set_named_property、napi_define_properties。 |
| 禁止修改属性类型，不能使用的接口有：napi_set_property、napi_set_named_property、napi_define_properties。 |
| 不支持Symbol相关接口和类型，不能使用的接口有：napi_create_symbol、napi_is_symbol_object、napi_symbol。 |


## 与UI交互的规则

Sendable数据需要与[makeObserved](../quick-start/arkts-new-makeObserved.md)联用，才可以观察Sendable对象的数据变化，具体使用请参考[makeObserved和@Sendable装饰的class配合文档](../quick-start/arkts-new-makeObserved.md#makeobserved和sendable装饰的class配合使用)。
