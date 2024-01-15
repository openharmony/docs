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
