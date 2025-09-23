# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Added ArkTS Syntax Rule Compilation Check Scenario

**Access Level**

Others

**Reason for Change**

An interface can use a numeric literal as a property name. This does not comply with the ArkTS syntax rules. However, no compilation syntax check is provided for this scenario.

**Change Impact**

This change is a non-compatible change.

Before change: An interface can declare a numeric literal as a property name.

```ts
interface I {
  one: string,
  2: string // no compile-time error
}
```

After change: An interface cannot use a numeric literal as a property name.

```ts
interface I {
  one: string,
  2: string // compile-time error
}
```

Numeric literals cannot be used as property names in classes and object literals. Therefore, if an interface with a numeric literal declared as a property name is used, there is no compatibility problem.

This change is incompatible only when such an interface is declared but not used.

**Start API Level**

API version 10

**Change Since**

OpenHarmony SDK 5.0.0.29

**Key API/Component Changes**

N/A

**Adaptation Guide**

You are advised to change the property name from a numeric literal to a constant string or identifier in the declaration phase. For details about the description and modification method, see [Recipes](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md#objects-with-property-names-that-are-not-identifiers-are-not-supported).
