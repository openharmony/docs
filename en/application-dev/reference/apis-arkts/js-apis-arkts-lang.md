# @arkts.lang (ArkTS Base Capability)

<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @huanghello-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=d6200ee580e2d2b406a92c0e4a15bf6480d0d39a translatedAt=2026-08-18T15:27:38.893Z pushedAt=2026-08-19T01:46:21.115Z -->

This module provides the basic type definitions of the ArkTS language, supporting cross-thread transfer of data structures, annotation retention policy control, and other features. Currently, it provides the ISendable type, the RetentionPolicy enum type, and the Retention annotation.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported and used only in ArkTS files (with the .ets file name extension).

## Modules to Import

```ts
import { lang, Retention, RetentionPolicy } from '@kit.ArkTS';
```

## lang.ISendable

Is the parent type of all [Sendable](../../arkts-utils/arkts-sendable.md#basic-concepts) object types (except `null` and `undefined`). After this interface is implemented, instances of a custom class support cross-thread transfer. It does not define any methods or properties.

In ArkTS, an object of the ISendable type is an instance of the Object type. It follows the basic characteristics of the Object type and supports cross-thread transfer.

ISendable is mainly used in scenarios where developers customize sendable data structures. Sendable container types in the ArkTS language standard library (such as [Array](arkts-apis-arkts-collections-Array.md), [Map](arkts-apis-arkts-collections-Map.md), and [Set](arkts-apis-arkts-collections-Set.md)) implicitly inherit and implement ISendable.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
// Declare a class that can be passed across threads using the @Sendable decorator.
@Sendable
// Implement the lang.ISendable interface to define a custom Sendable data structure.
class CustomData implements lang.ISendable {
    id: number;
    name: string;
    constructor(id: number, name: string) {
        this.id = id;
        this.name = name;
    }
}
```

## RetentionPolicy<sup>24+</sup>

Enumerates the retention policies of [annotation](../../quick-start/arkts-language-guide-annotations.md#basic-concepts-of-annotations) types. Its enum values are used together with [Retention](#retention24) to specify the lifecycle of an annotation.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Utils.Lang

| Name | Value | Description |
| --------- | --------- | ------------- |
| SOURCE | "source" | The annotation is removed at compile time. |
| BYTECODE | "bytecode" | The annotation is retained in the compilation output. |

## Retention<sup>24+</sup>

An API annotation capability provided by the system, which can be used to specify the lifecycle of a custom annotation. This annotation can only be applied to other annotation declarations. After the Retention annotation is applied to a custom annotation, the compiler executes different retention policies for the custom annotation based on the value of policy.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Utils.Lang

| Name | Type | Read-Only | Optional | Description |
| ---- | ------ | ---- | ---- | ---------- |
| policy | [RetentionPolicy](#retentionpolicy24) | No | No | Retention policy of the annotation. |

**Example**

```ts
import { Retention, RetentionPolicy } from '@kit.ArkTS';

// Construct a user-defined source-level annotation.
@Retention({policy: RetentionPolicy.SOURCE})
@interface sourceAnnotation {
    prop1: number
    prop2: number
}

// Construct a user-defined bytecode-level annotation.
@Retention({policy: RetentionPolicy.BYTECODE})
@interface bytecodeAnnotation {
    prop1: number
    prop2: number
}
```