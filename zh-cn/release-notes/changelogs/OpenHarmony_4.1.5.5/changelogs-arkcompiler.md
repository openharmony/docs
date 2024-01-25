# ArkCompiler子系统Changelog

## cl.ArkCompiler.1 ArkTS语法规则变更

从OpenHarmony SDK版本4.1.5.5起，以下ArkTS语法规则发生变更。

**移除规则**

规则`arkts-no-decorators-except-arkui`、`arkts-no-side-effects-imports`和`arkts-no-regexp-literals`被移除。

**降级规则**

规则`arkts-no-globalthis`和`arkts-no-classes-as-obj`等级降为警告，不再阻塞工程编译。

规则`arkts-no-func-apply-bind-call`被拆分成以下两条：
1. `arkts-no-func-apply-call`，等级：错误
2. `arkts-no-func-bind`，等级：警告

相比于之前版本，报错代码和报错总数不变。

**放宽规则**

规则`arkts-identifiers-as-prop-names`放宽，支持属性名为字符串字面量或枚举中的字符串值。

以下代码不再报错。

```
enum Test {
  A = 'aaa',
  B = 'bbb'
}

let obj: Record<string, number> = {
  [Test.A]: 1,   // 枚举中的字符串值
  [Test.B]: 2,   // 枚举中的字符串值
  ['value']: 3   // 字符串字面量
}
```

**变更影响**

开发者无需适配代码，无兼容性影响。

## cl.ArkCompiler.2 三方包ts检查变更

**访问级别**

其它

**变更原因**

oh_modules目录下的三方包中的代码应符合ts语法规范。以前oh_modules目录下不符合ts语法规范的代码会报错，但由于代码实现的原因，从4.0.10.3版本开始未报错。目前该问题已修复，oh_modules目录下不符合ts语法规范的代码现在会报错。

**变更发生版本**

OpenHarmony SDK 4.1.5.5

**变更影响**

需要使用ts语法正确的三方包，若在三方包内添加了不符合ts语法规范的代码则编译会报错。

如在三方包代码中加入如下代码：
```
let a: string = 1;
```

编译时会报错：

```
Type 'number' is not assignable to type 'string'.
```

**适配指导**

使用符合ts语法规范的三方包，不能往三方包中添加不符合ts语法规范的代码。