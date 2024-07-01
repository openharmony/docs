# ArkCompiler子系统变更说明

## cl.arkcompiler.1 ArkTS Linter修复规则告警场景遗漏

**访问级别**

其他

**变更原因**

在interface字段名声明为数字字面量的情况下既不符合ArkTS语言规则也无法直接使用。

**变更影响**

变更前，interface可以声明数字字面量为属性名；变更后，interface不可以使用数字字面量为属性名。但实例前后均不能直接调用数字字面量命名的属性。

下面的场景将会报错：

```ts
interface I {
    one: string,
    2: string // ERROR
}
```

**起始 API Level**

ArkTS语法检查从API 10起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.29 开始。

**变更的接口/组件**

不涉及。

**适配指导**

建议声明阶段变更数字字面量命名为字符串命名或者添加下划线前缀。