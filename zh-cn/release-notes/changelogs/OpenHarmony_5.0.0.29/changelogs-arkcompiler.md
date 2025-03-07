# ArkCompiler子系统变更说明

## cl.arkcompiler.1 ArkTS编译语法检查场景遗漏

**访问级别**

其他

**变更原因**

interface的属性名为数字字面量不符合ArkTS语法规则，编译语法检查场景遗漏，需要修复。

**变更影响**

此变更为不兼容变更。

变更前，interface可以声明数字字面量为属性名。

```ts
interface I {
  one: string,
  2: string // no compile-time error
}
```

变更后，interface不可以使用数字字面量为属性名。

```ts
interface I {
  one: string,
  2: string // compile-time error
}
```

由于class和对象字面量中均不可以使用数字字面量作为属性名，因此如果使用了包含数字字面量作为属性名的interface不会有兼容性问题。

只有在声明了这类interface但不使用它们的场景下为不兼容变更。

**起始 API Level**

ArkTS语法检查从API 10起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.29 开始。

**变更的接口/组件**

不涉及。

**适配指导**

建议声明阶段变更数字字面量的属性名为常量字符串或者标识符。具体说明和修改方式请参考[适配指导案例](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md#对象的属性名必须是合法的标识符)。
