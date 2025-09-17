# Module Description
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->
> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

The collections module provides ArkTS containers for efficient data transfer in concurrency scenarios. The ArkTS containers provide similar functionalities as their JavaScript counterparts, except that their properties cannot be added or updated through `.` or `[]`.

By default, ArkTS containers are passed by reference between concurrent instances. This means that multiple concurrent instances can simultaneously operate the same container instance. Pass-by-copy is also supported. In this mode, each concurrent instance holds an ArkTS container instance.

ArkTS containers are not thread-safe. They adopt the fail-fast approach. An exception is thrown if multiple concurrent instances make structural changes to a container instance at the same time. Therefore, in multi-thread read/write scenarios, you must use the ArkTS asynchronous lock to ensure secure access to the ArkTS containers.

Currently, the following ArkTS containers are provided: [Array](arkts-apis-arkts-collections-Array.md), [Map](arkts-apis-arkts-collections-Map.md), [Set](arkts-apis-arkts-collections-Set.md), TypedArray ([Int8Array](arkts-apis-arkts-collections-Int8Array.md), [Uint8Array](arkts-apis-arkts-collections-Uint8Array.md), [Int16Array](arkts-apis-arkts-collections-Int16Array.md), [Uint16Array](arkts-apis-arkts-collections-Uint16Array.md), [Int32Array](arkts-apis-arkts-collections-Int32Array.md), [Uint32Array](arkts-apis-arkts-collections-Uint32Array.md), [Uint8ClampedArray](arkts-apis-arkts-collections-Uint8ClampedArray.md) and [Float32Array](arkts-apis-arkts-collections-Float32Array.md)), [ArrayBuffer](arkts-apis-arkts-collections-ArrayBuffer.md), [BitVector](arkts-apis-arkts-collections-BitVector.md), and [ConcatArray](arkts-apis-arkts-collections-ConcatArray.md).

## Modules to Import

```ts
import { collections } from '@kit.ArkTS';
```
