# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 ArkTS Syntax Rule Change

Since OpenHarmony SDK 4.1.5.5, the ArkTS syntax rules are changed as follows.

**Removed**

**arkts-no-decorators-except-arkui**, **arkts-no-side-effects-imports**, **arkts-no-regexp-literals**

**Downgraded**

The severity level of **rules arkts-no-globalthis** and **arkts-no-classes-as-obj** is lowered to warning, which means that they do not block project compilation.

Rule **arkts-no-func-apply-bind-call** is split into the following two rules:
1. **arkts-no-func-apply-call**, at error level
2. **arkts-no-func-bind**, at level warning

Compared with that in the earlier version, the quantity of highlighted code and total number of errors remain unchanged.

**Relaxed**

Rule **arkts-identifiers-as-prop-names** is relaxed. Attribute names can be string literals or string type enumeration constants.

No error is reported in the following code:

```
enum Test {
  A = 'aaa',
  B = 'bbb'
}

let obj: Record<string, number> = {
  [Test.A]: 1,   // String type enumeration constants
  [Test.B]: 2,   // String type enumeration constants
  ['value']: 3   // String literal
}
```

**Change Impact**

There is no compatibility impact. No code adaptation is required.
