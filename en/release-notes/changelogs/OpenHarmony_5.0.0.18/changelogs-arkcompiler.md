# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Introduced New ArkTS Syntax Check Scenarios

**Access Level**

Other

**Reason for Change**

The ArkTS syntax check tool is designed for syntax validation in the following scenarios: full build, incremental build, initial preview, and initial hot reload. Previously, during the preview and hot reload processes, when changes were made to the code and saved, triggering real-time previews and hot reloads, no ArkTS syntax check is performed. With this change, the ArkTS syntax check is introduced for these scenarios to ensure that the check result is the same as that in other scenarios.

**Change Impact**

Prior to this change, in scenarios involving preview and hot reload, if code was modified incrementally and saved for another round of preview and hot reload, no ArkTS syntax check is performed. If the code introduces syntax errors according to ArkTS rules, the preview and hot reload processes will still proceed. However, with this change, introducing code that breaks ArkTS rules will interrupt the build process, thereby stopping real-time preview and hot reload.

**Start API Level**

API version 10

**Change Since**

OpenHarmony SDK 5.0.0.18

**Key API/Component Changes**

N/A

**Adaptation Guide**

No adaptation is required for applications that can be fully compiled successfully.


## cl.arkcompiler.2 Compilation Check Standardized for ArkTS Sendable Syntax Rules

**Access Level**

Other

**Reason for Change**

In API version 11, ArkTS introduces the concepts of the @Sendable decorator and Sendable class. However, some Sendable syntax constraints are not validated during compilation. In this change, compilation checks against these ArkTS Sendable syntax rules are added, providing clearer rules for you to use the ArkTS Sendable feature for development.

**Change Impact**

This change is an incompatible change. In this change, the following Sendable syntax rules are added.

#### Rule 1: A Sendable class can inherit only from another Sendable class.

The rule scenario is optimized. When a Sendable class inherits from a variable (even if the variable is assigned a Sendable class), a compilation error is reported.

```ts
@Sendable
class A {}    // Sendable class

let a = A

@Sendable
class B extends A {}

@Sendable
class C extends a {}    // Compilation error: The Sendable class cannot inherit from a variable.
```

Affected scenario: If the Sendable class inherits from a variable (even if the variable is assigned a Sendable class), the compilation fails after the change. This is an incompatible change.

---

#### Rule 2: A non-Sendable class can inherit only from another non-Sendable class.

If a non-Sendable class inherits from a Sendable class, a compilation error is reported.

```ts
@Sendable
class A {}

class B extends A {}    // Compilation error: A non-Sendable class cannot inherit from a Sendable class.
```

Affected scenario: If a non-Sendable class inherits from a Sendable class, the compilation fails after the change. This is an incompatible change.

---

#### Rule 3: The template type of a Sendable class, collections.Array, collections.Map, and collections.Set in the generic class must be Sendable.

During compilation, there is no longer any check or interception for the use of the template type by the Sendable class property, meaning that the Sendable class property can use the template type. The type of the generic class is checked during instantiation. If the template type of the Sendable class in the generic class is non-Sendable, an error is reported during compilation.

```ts
@Sendable
class B {}    // Sendable class

@Sendable
class C<T> {
  v: T;    // Allow the Sendable class property to use the template type. No compilation error is reported.
  constructor(v: T) {
    this.v = v;
  }
}

let c = new C<B>();

function foo(a: C<B>) {}
```

```ts
class B {}    // Non-sendable class

@Sendable
class C<T> {}

let c = new C<B>();    // Compilation error: The template type of the Sendable class in the generic class cannot be non-Sendable.
```

Affected scenarios: 1. If the Sendable class property uses the template type, no compilation error is reported. 2. If the template type of the Sendable class in the generic class is non-Sendable, the compilation fails. This is an incompatible change.

---

#### Rule 4: Do not use other decorators (class, property, method, or parameter decorators) for the Sendable class.

When the Sendable class uses other decorators, a compilation error is reported.

```ts
// a.ts
export function foo(a: Function) {
  a.prototype = String
}

// b.ets
import { foo } from 'a'

@foo
@Sendable
class A {}    // Compilation error: A Sendable class cannot use other decorators.
```

Affected scenario: If the Sendable class uses other decorators, the compilation fails after the change. This is an incompatible change.

---

#### Rule 5: The Sendable type cannot be initialized using an object literal or array literal.

When an object literal or array literal is used to initialize the Sendable type, a compilation error is reported.

```ts
@Sendable
class C {}

let c: C = {};    // Compilation error: Do not use object literals or array literals to initialize the Sendable type.
```

Affected scenario: When an object literal or array literal is used to initialize a variable of the Sendable type, the compilation fails.

---

#### Rule 6: Do not use as to forcibly convert the non-Sendable type to the Sendable type.

When **as** is used to forcibly convert the non-Sendable type to the Sendable type, a compilation error is reported.

```ts
class A {}

@Sendable
class B {}

function foo(a: A) {
  a as B;    // Compilation error: Do not use as to forcibly convert the non-Sendable type to the Sendable type.
}
```

Affected scenario: A non-Sendable variable after forcible conversion cannot be compiled.

---


**Start API Level**

API version 10

**Change Since**

OpenHarmony SDK 5.0.0.18

**Key API/Component Changes**

N/A

**Adaptation Guide**

Make adaptations in your ArkTS code involved in the preceding scenarios according to the specifications.
