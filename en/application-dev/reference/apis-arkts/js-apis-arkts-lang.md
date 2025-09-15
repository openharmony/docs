# @arkts.lang (ArkTS Base Capability)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

The module provides the basic type definition of ArkTS. Currently, the **ISendable** interface is provided.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

## Modules to Import

```ts
import { lang } from '@kit.ArkTS';
```

## lang.ISendable
Parent type of all sendable types except null and undefined. It does not have any necessary methods or properties.

An **ISendable** object is an instance of the Object type in ArkTS.

**ISendable** is mainly used when you want to customize the sendable data structure. Container types in the ArkTS common library implicitly inherit and implement **ISendable**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
// Construct a custom sendable data structure.
@Sendable
class CustomData implements lang.ISendable {
    data1: number;
    data2: string;
    constructor(data1: number, data2: string) {
        this.data1 = data1;
        this.data2 = data2;
    }
}
```
