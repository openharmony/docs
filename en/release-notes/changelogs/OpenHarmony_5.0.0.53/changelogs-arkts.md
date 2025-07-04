# ArkTS Changelog

## cl.arkts.1 Changed the Return Value of Exponentiation (\*\*) with Base 1 and NaN Exponent

**Access Level**

Others

**Reason for Change**

 When you perform exponentiation in ArkTS with a base of 1 and an exponent of NaN (or a value that converts to NaN via **ToNumber**), the result is incorrectly returned as 1. This does not comply with the description in [ECMAScript® 2021 Language Specification](https://262.ecma-international.org/12.0/index.html#sec-numeric-types-number-exponentiate).

**Impact of the Change**

This change is a non-compatible change.

Before change: When the base is 1 and the exponent is NaN or a value that converts to NaN via **ToNumber**, the return value is 1.

After change: When the base is 1 and the exponent is NaN or a value that converts to NaN via **ToNumber**, the return value is NaN.

**Start API Level**

6

**Change Since**

OpenHarmony SDK 5.0.0.53

**Key API/Component Changes**

N/A

**Adaptation Guide**

Check for exponentiation operations matching this pattern.

Example:

```typescript
console.log((1 ** NaN).toString())
```

Before the change, the output of this example is:

```
1
```

After the change, the output of this example is:

```
NaN
```

> **NOTE**

> While expressions like `1 ** "test"` are invalid in ETS files, they may exist in third-party libraries. These will now also return NaN.

This change fixes this issue. Exponentiation operations returns NaN if the base number is 1 and the exponent is NaN or a value that converts to NaN via **ToNumber**.



## cl.arkts.2 Changed Behavior for String.prototype.lastIndexOf with Empty Strings

**Access Level**

Others

**Reason for Change**

When **String.prototype.lastIndexOf** is used to search for an empty string, the return value is -1. This does not comply with the description in [ECMAScript® 2021 Language Specification](https://262.ecma-international.org/12.0/index.html#sec-string.prototype.lastindexof).

**Impact of the Change**

This change is a non-compatible change.

Before change: If the string to search for is empty, the return value of **String.prototype.lastIndexOf** is -1.

After change: If the string to search for is empty, the return value of **String.prototype.lastIndexOf** is the index of the last character plus 1.

**Start API Level**

6

**Change Since**

OpenHarmony SDK 5.0.0.53

**Key API/Component Changes**

String.prototype.lastIndexOf

**Adaptation Guide**

Check for empty string searches.

Example:

```typescript
console.log("abcde".lastIndexOf("").toString())
```

Before the change, the output of this example is:

```
-1
```

After the change, the output of this example is:

```
5
```

This change is made to fix the issue. The **String.prototype.lastIndexOf** API now returns the index of the last character plus 1 when searching for an empty string.
