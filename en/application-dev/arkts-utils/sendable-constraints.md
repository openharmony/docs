# Usage Rules and Constraints for Sendable

## Sendable Classes Must Inherit Only from Other Sendable Classes

The layout and prototype chain of Sendable objects are immutable. Non-Sendable objects can modify their layout in special ways, but they cannot inherit from or be inherited by Sendable classes. This rule applies to classes, not variables. In other words, Sendable classes cannot inherit from variables.

**Correct Example**

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

**Incorrect Example**

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


## Non-Sendable Classes Must Inherit Only from Other Non-Sendable Classes

The layout and prototype chain of Sendable objects are immutable. Since non-Sendable objects can modify their layout in special ways, they cannot inherit from or be inherited by Sendable classes.

**Correct Example**

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

**Incorrect Example**

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


## Non-Sendable Classes Can Only Implement Non-Sendable Interfaces

If a non-Sendable class implements a Sendable interface, it may be mistakenly considered as Sendable, leading to incorrect usage.

**Correct Example**

```ts
interface I {};

class B implements I {};
```

**Incorrect Example**

```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {};

class B implements I {};
```


## Member Variables of Sendable Classes/Interfaces Must Be Sendable Data Types 

Sendable objects cannot hold non-Sendable data. Therefore, member properties of Sendable objects must be of Sendable data types.

**Correct Example**

```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**Incorrect Example**

```ts
@Sendable
class A {
  constructor() {
  }
  b: Array<number> = [1, 2, 3] // collections.Array must be used.
}
```


## Member Variables of Sendable Classes/Interfaces Cannot Use the Exclamation Mark (!) for Assertion

Member properties of Sendable objects must be initialized. The assertion using the exclamation mark (!) allows variables to remain uninitialized. Therefore, using the exclamation mark (!) for assertion is not supported.

**Correct Example**

```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**Incorrect Example**

```ts
@Sendable
class A {
  constructor() {
  }
  a!: number;
}
```


## Member Variables of Sendable Classes/Interfaces Cannot Use Computed Property Names

The layout of Sendable objects is immutable. Computed properties cannot statically determine the object layout, and therefore they cannot be used for Sendable objects.

**Correct Example**

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

**Incorrect Example**

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


## Template Types for Sendable Classes, collections.Array, collections.Map, and collections.Set Must Be Sendable

Sendable objects cannot hold non-Sendable data. Therefore, template types for Sendable data in generic classes must be Sendable.

**Correct Example**

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

**Incorrect Example**

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


## Sendable Classes Cannot Use Variables Defined in the Context of the Current Module

Sendable objects operate in different concurrent instances with distinct context environments within a single virtual machine instance. Direct access to variables defined in the context of the current module can lead to unexpected behavior. Therefore, Sendable objects cannot use variables defined in the context of the current module. Violations will result in compile-time errors.

> **NOTE**
>
> Since API version 12, Sendable classes can use top-level Sendable class objects.

**Correct Example**

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

**Incorrect Example**

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
    u: I = bar(); // bar is not a Sendable class object. A compile-time error is reported.
    v: I = new A(); // A is not defined at the top level. A compile-time error is reported.

    foo() {
      return b; // b is not a Sendable class object but an instance of the Sendable class. A compile-time error is reported.
    }
  }
}
```


## Sendable Classes and Functions Cannot Use Decorators Other Than @Sendable

If a class decorator modifies the class layout and is defined in a .ts file, it can cause runtime errors.

**Correct Example**

```ts
@Sendable
class A {
  num: number = 1;
}
```

**Incorrect Example**

```ts
@Sendable
@Observed
class C {
  num: number = 1;
}
```


## Object Literals/Array Literals Cannot Be Used to Initialize Sendable Types 

Object literals and array literals are non-Sendable types. Sendable data types can only be created using **new** expressions of Sendable types.

**Correct Example**

```ts
import { collections } from '@kit.ArkTS';

let arr1: collections.Array<number> = new collections.Array<number>(1, 2, 3); // The type is Sendable.
```

**Incorrect Example**

```ts
import { collections } from '@kit.ArkTS';

let arr2: collections.Array<number> = [1, 2, 3]; // The type is not Sendable. A compile-time error is reported.
let arr3: number[] = [1, 2, 3]; // The type is not Sendable. No error is reported.
let arr4: number[] = new collections.Array<number>(1, 2, 3); // A compile-time error is reported.
```


## Non-Sendable Types Cannot Be Cast to Sendable Types Using **as**

Except for the Object type, non-Sendable types cannot be cast to Sendable types using **as**. Using **as** to cast a non-Sendable type to a Sendable type results in an object that is still non-Sendable, leading to incorrect usage. Sendable types, however, can be cast to non-Sendable types using **as** to maintain compatibility, provided they do not violate Sendable rules.

**Correct Example**

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

**Incorrect Example**

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


## Arrow Functions Are Not Supported for Sharing

Arrow functions do not support the @Sendable decorator and are non-Sendable. Therefore, they cannot be shared.

**Correct Example**

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

**Incorrect Example**

```ts
@Sendable
type SendableFuncType = () => void;
let func: SendableFuncType = () => {}; // A compile-time error is reported.

@Sendable
class SendableClass {
  func: SendableFuncType = () => {}; // A compile-time error is reported.
}
```


## @Sendable Can Only Be Applied to Function Types

Currently, The @Sendable decorator only supports declaring Sendable function types.

**Correct Example**

```ts
@Sendable
type SendableFuncType = () => void;
```

**Incorrect Example**

```ts
@Sendable
type A = number; // A compile-time error is reported.

@Sendable
class C {}

@Sendable
type D = C; // A compile-time error is reported.
```


## Notice


When using Sendable in HAR, you must enable the configuration for compiling and generating TS files. For details, see [Building TS Files](../quick-start/har-package.md#building-ts-files).


## Rules for Interaction with TS/JS


### ArkTS General Rules (Only for Sendable Objects Currently)

| Rule|
| -------- |
| Do not modify the object layout (add or delete properties, or change property types) of Sendable objects when passing them to TS/JS interfaces.|
| Do not modify the object layout (add or delete properties, or change property types) of Sendable objects when setting them to TS/JS objects.|
| Do not modify the object layout (add or delete properties, or change property types) of Sendable objects when placing them in TS/JS containers.|

> **NOTE**
>
> Changing the property type does not include changing the type of a Sendable object, such as from Sendable class A to Sendable class B.


### NAPI Rules (Only for Sendable Objects Currently)

| Rule|
| -------- |
| Do not delete properties. Prohibited interfaces: **napi_delete_property**.|
| Do not add properties. Prohibited interfaces: **napi_set_property**, **napi_set_named_property**, and **napi_define_properties**.|
| Do not change property types. Prohibited interfaces: **napi_set_property**, **napi_set_named_property**, and **napi_define_properties**.|
| Symbol-related interfaces and types are not supported. Prohibited interfaces: **napi_create_symbol**, **napi_is_symbol_object**, and **napi_symbol**.|


## Rules for Interaction with the UI

To observe data changes in Sendable objects when interacting with UI, Sendable data must be used in conjunction with [makeObserved](../quick-start/arkts-new-makeObserved.md). For more information, see [Using makeObserved and @Sendable Decorated Class Together](../quick-start/arkts-new-makeObserved.md#using-makeobserved-and-sendable-decorated-class-together).
