# Sendable Usage Rules and Constraints

## A sendable class can inherit only from another sendable class.

> **Note**
>
> The class here does not include variables. In other words, a sendable class cannot inherit from a variable.

**Positive Example:**

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

**Negative Example:**

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


## A non-sendable class can inherit only from a non-sendable class.

**Positive Example:**

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

**Negative Example:**

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


## A non-sendable class can implement only a non-sendable interface.

**Positive Example:**

```ts
interface I {};

class B implements I {};
```

**Negative Example:**

```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {};

class B implements I {};
```


## The member variables of a sendable class or interface must be of a sendable data type.

**Positive Example:**

```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**Negative Example:**

```ts
@Sendable
class A {
  constructor() {
  }
  b: Array<number> = [1, 2, 3] // collections.Array must be used.
}
```


## The member variables of a sendable class or interface cannot use the exclamation mark (!) for assertion.

**Positive Example:**

```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**Negative Example:**

```ts
@Sendable
class A {
  constructor() {
  }
  a!: number;
}
```


## The member variables of a sendable class or interface do not support computed property names.

**Positive Example:**

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

**Negative Example:**

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


## The template type of a sendable class, collections.Array, collections.Map, and collections.Set in the generic class must be Sendable.

**Positive Example:**

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

**Negative Example:**

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


## Variables defined in the context of the current module cannot be used in a sendable class.

Because the context of a sendable object varies among concurrent instances, direct access may cause unexpected behavior. A sendable object cannot use the variables defined in the context of the current module. Otherwise, a compile-time error is reported.

> **Note**
>
> Since API version 12, a sendable class object of the top level can be used internally by the sendable class itself.

**Positive Example:**

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

**Negative Example:**

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
    u: I = bar(); // bar is not a sendable class object. A compile-time error is reported.
    v: I = new A(); // A is not defined in the top level. A compile-time error is reported.

    foo() {
      return b; // b is not a sendable class object but an instance of the sendable class. A compile-time error is reported.
    }
  }
}
```


## A sendable class and sendable function can only use the @Sendable decorator.

If the class decorator is defined in a .ts file, any modification to the class layout causes a runtime error.

**Positive Example:**

```ts
@Sendable
class A {
  num: number = 1;
}
```

**Negative Example:**

```ts
@Sendable
@Observed
class C {
  num: number = 1;
}
```


## The Sendable type cannot be initialized using an object literal or array literal.

A sendable data type can be created only by using the **new** expression of the Sendable type.

**Positive Example:**

```ts
import { collections } from '@kit.ArkTS';

let arr1: collections.Array<number> = new collections.Array<number>(1, 2, 3); // The type is Sendable.
```

**Negative Example:**

```ts
import { collections } from '@kit.ArkTS';

let arr2: collections.Array<number> = [1, 2, 3]; // The type is not Sendable. A compile-time error is reported.
let arr3: number[] = [1, 2, 3]; // The type is not Sendable. No error is reported.
let arr4: number[] = new collections.Array<number>(1, 2, 3); // A compile-time error is reported.
```


## A non-sendable type cannot be converted to a sendable type using **as**.

> **Note**
>
> A sendable type must be compatible with a non-sendable type without violating the sendable usage rules. Therefore, a sendable type can be converted to a non-sendable type using **as**.

**Positive Example:**

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

**Negative Example:**

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


## An arrow function is not sendable.

An arrow function cannot be decorated by @Sendable.

**Positive Example:**

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

**Negative Example:**

```ts
@Sendable
type SendableFuncType = () => void;
let func: SendableFuncType = () => {}; // A compile-time error is reported.

@Sendable
class SendableClass {
  func: SendableFuncType = () => {}; // A compile-time error is reported.
}
```


## The @Sendable decorator supports type decoration for functions only.

The @Sendable decorator supports type decoration for functions only.

**Positive Example:**

```ts
@Sendable
type SendableFuncType = () => void;
```

**Negative Example:**

```ts
@Sendable
type A = number; // A compile-time error is reported.

@Sendable
class C {}

@Sendable
type D = C; // A compile-time error is reported.
```


## Notice


When using **Sendable** in HAR, enable the configuration of generating TS files. For details, see [Building TS Files](../quick-start/har-package.md#building-ts-files).


## Rules for Interaction with TS/JS


### ArkTS General Rules (Only for Sendable Objects Currently)

| Rule Description|
| -------- |
| When a sendable object is passed to a TS/JS interface, the object layout cannot be operated (adding or deleting properties, or changing property types).|
| When a sendable object is set to a TS/JS object, the object layout cannot be operated (adding or deleting properties, or changing property types) after the TS/JS object obtains the sendable object.|
| When a sendable object is placed in a TS/JS container, the object layout cannot be operated (adding or deleting properties, or changing property types) after the TS/JS object obtains the sendable object.|

> **Note**
>
> Changes of the property types do not include changes of the sendable object types, for example, from Sendable class A to Sendable class B.


### Native API Rules (Only for Sendable Objects Currently)

| Rule Description|
| -------- |
| Do not delete properties. The **napi_delete_property** interface cannot be used.|
| Do not add properties. The following interfaces cannot be used: **napi_set_property**, **napi_set_named_property**, and **napi_define_properties**.|
| Do not modify property types. The following interfaces cannot be used: **napi_set_property**, **napi_set_named_property**, and **napi_define_properties**.|
| Symbol-related interfaces and types are not supported. The following interfaces cannot be used: **napi_create_symbol**, **napi_is_symbol_object**, and **napi_symbol**.|


## Rules for Interaction with the UI

The Sendable data needs to be used together with the [makeObserved](../quick-start/arkts-new-makeObserved.md) to observe the data changes of the Sendable object. For details, see [Using makeObserved Together with @Sendable Decorated Classes](../quick-start/arkts-new-makeObserved.md#using-makeobserved-together-with-sendable-decorated-classes).
