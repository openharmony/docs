# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Repair of the Sendable Class Assignment Check in Hotspot Functions

**Reason for Change**

This change is made to fix the Sendable class assignment check issues in hotspot functions.

**Change Impact**

This change is non-compatible.

- Sendable data is used to address performance issues with cross-thread data transfer. For an introduction to its use, see [Sendable Development](../../../application-dev/arkts-utils/arkts-sendable.md).
- Some constraints were not checked in hotspot functions. As a result, these constraints may be bypassed.
- The following are the constraints bypassed in this change.

    | \@Sendable Class Decorator         | Description                                                                   |
    | ------------------------- | ---------------------------------------------------------------------- |
    | Property type restrictions for decorated objects | 1. The following types are supported: string, number, boolean, bigint, null, undefined, Sendable class, collections.Array, collections.Map, and collections.Set.<br/>2. Closure variables are not allowed.<br/>3. Private properties must be defined using **private**, rather than the number sign (#).<br/>4. Computed properties are not supported. |

- For violations of the **property type restrictions**:
    - Before change: The program runs normally without errors.
    - After change: The program throws an exception at the point of constraint violation, indicating that the assignment type does not match. You need to adapt according to the requirements of **property type restrictions** in [Sendable Development](../../../application-dev/arkts-utils/arkts-sendable.md).

**API Level**

11

**Change Since**

OpenHarmony_4.1.6.5

**Key API/Component Changes**

@Sendable decorator

**Adaptation Guide**

After this change, if a type mismatch exception occurs at runtime, it may violate the usage constraints, and it is necessary to check the assignment types. For detailed instructions, see [Sendable Development](../../../application-dev/arkts-utils/arkts-sendable.md).
