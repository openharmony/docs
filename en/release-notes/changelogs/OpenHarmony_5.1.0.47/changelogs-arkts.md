# ArkTS Changelog

## cl.arkts.1 Change in JSON.parse() Return Value for Number.MIN_VALUE

**Access Level**

Public API

**Reason for Change**

 The static data property **Number.MIN_VALUE** represents the smallest positive number that can be represented in JavaScript, which is approximately 5e-324. This change introduces support for parsing this value in **JSON.parse()**.

**Impact of the Change**

This change requires application adaptation.

Before the change, the return value of **Number.MIN_VALUE** parsed by **JSON.parse()** is **Infinity**.

After the change, the return value of **Number.MIN_VALUE** parsed by **JSON.parse()** is **5e-324**.

**Start API Level**

6

**Change Since**

OpenHarmony SDK 5.1.0.47

**Key API/Component Changes**

N/A

**Adaptation Guide**

Currently, the smallest number that **JSON.parse()** can parse is **Number.MIN_VALUE**, which is approximately 5e-324. Before this change, the smallest number that could be parsed was approximately 2.22e-308.

Example:

```typescript
let res = JSON.parse('{"num":5e-324}')
console.info(res.num)
```

Before the change, the output of this example is:

```
Infinity
```

After the change, the output of this example is:

```
5e-324
```
