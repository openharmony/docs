# ArkCompiler子系统变更说明

## cl.arkcompiler.1 ArkTS语法检查工具检查场景增加

**访问级别**

其他

**变更原因**

ArkTS语法检查工具的检查场景包括应用完整编译、增量编译、首次预览、首次热重载等，在预览和热重载场景下，增量修改代码保存后触发实时预览和热重载时，未进行ArkTS语法检查，本次变更在该场景下的编译流程中新增ArkTS语法检查，以和其他场景检查结果保持一致。

**变更影响**

变更前，在预览器和热重载场景下，增量修改再次预览和热重载时，不会进行ArkTS语法检查，如果引入违反ArkTS语法规则问题的代码，可以继续实时预览和热重载；变更后，在该场景下，如果引入违反ArkTS语法规则问题的代码，会阻塞编译，停止实时预览和热重载。

**起始 API Level**

ArkTS语法检查从API 10起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.18 开始。

**变更的接口/组件**

不涉及。

**适配指导**

能够完整编译成功的应用，无需额外适配。


## cl.arkcompiler.2 ArkTS Sendable语法规则编译检查规范化

**访问级别**

其他

**变更原因**

API 11中ArkTS语言规范首次引入@Sendable装饰器和Sendable class相关概念，但部分Sendable语法约束规则存在编译期未校验等问题。因此在本次版本更新中我们对ArkTS Sendable语法规则在编译期检查作规范化处理，旨在明确Sendable规范定义和限制场景，以更加清晰的规则指导开发者使用ArkTS Sendable特性进行开发。

**变更影响**

此变更为非兼容变更，本次更新中有如下Sendable语法规则约束新增和变更：

#### 规则1. *Sendable class只能继承自Sendable class*

现在我们对本规则场景进行完善，当Sendable class继承自变量（即使该变量赋值为Sendable class）时，编译报错。

```ts
@Sendable
class A {}    // Sendable class

let a = A

@Sendable
class B extends A {}

@Sendable
class C extends a {}    // 编译报错: Sendable class无法继承自变量
```

影响场景：Sendable class继承自变量场景（即使该变量赋值为Sendable class），在本次更新后将无法通过编译，存在兼容性影响

---

#### 规则2. *Non-sendable class只能继承自Non-sendable class*

当Non-sendable class继承自Sendable class时，编译报错。

```ts
@Sendable
class A {}

class B extends A {}    // 编译报错: Non-sendable class无法继承自Sendable class
```

影响场景：当Non-sendable class继承自Sendable class时，原本在运行时报错，在本次更新后将无法通过编译，存在兼容性影响

---

#### 规则3. *泛型类中的Sendable class, collections.Array, collections.Map, collections.Set的模板类型必须是Sendable类型*

现在编译期对Sendable类属性使用模板类型不再检查拦截，允许Sendable类属性使用模板类型；同时将检查泛型类在实例化位置的类型，当泛型类中的Sendable class的模板类型是Non-sendable类型时，编译报错。

```ts
@Sendable
class B {}    // Sendable class

@Sendable
class C<T> {
  v: T;    // 允许Sendable类属性使用模板类型，不再编译报错
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

let c = new C<B>();    // 编译报错：泛型类中的Sendable class的模板类型禁止为Non-sendable类型
```

影响场景：1. Sendable模板类属性使用模板类型场景，将不再编译报错；2.泛型类中的Sendable class的模板类型为Non-sendable类型的场景，在本次更新后将无法通过编译，存在兼容性影响

---

#### 规则4. *Sendable class禁止使用其他装饰器（类装饰器、属性装饰、方法装饰器、参数装饰器）*

当Sendable class使用其他装饰器时，编译报错

```ts
// a.ts
export function foo(a: Function) {
  a.prototype = String
}

// b.ets
import { foo } from 'a'

@foo
@Sendable
class A {}    // 编译报错: Sendable class禁止使用其他装饰器
```

影响场景：对于Sendable class使用了其他装饰器，在本次更新后将无法通过编译，存在兼容性影响

---

#### 规则5. *禁止使用对象字面量或数组字面量初始化Sendable类型*

现在当使用对象字面量或数组字面量初始化Sendable类型时，编译报错

```ts
@Sendable
class C {}

let c: C = {};    // 编译报错: 禁止使用对象字面量或数组字面量初始化Sendable类型
```

影响场景：使用对象字面量或数组字面量初始化Sendable类型的变量，在本次更新后将无法通过编译，存在兼容性影响

---

#### 规则6. *禁止使用as将Non-sendable类型强转成Sendable类型*

现在当使用as将Non-sendable类型强转成Sendable类型时，编译报错

```ts
class A {}

@Sendable
class B {}

function foo(a: A) {
  a as B;    // 编译报错: 禁止使用as将Non-sendable类型强转成Sendable类型
}
```

影响场景：强转后的Non-sendable类型的变量，在本次更新后将无法通过编译，存在兼容性影响

---


**起始 API Level**

ArkTS语法检查从API 10起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.18 开始。

**变更的接口/组件**

不涉及。

**适配指导**

存在上述规则影响场景的ArkTS代码需按照规范要求进行适配修改
