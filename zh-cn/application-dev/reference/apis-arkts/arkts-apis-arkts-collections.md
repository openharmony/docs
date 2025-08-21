# 模块描述
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->
> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 此模块仅支持在ArkTS文件（文件后缀为.ets）中导入使用。

本模块提供的ArkTS容器集，可以用于并发场景下的高性能数据传递。功能与JavaScript内建的对应容器类似，但ArkTS容器实例无法通过`.`或者`[]`添加或更新属性。

ArkTS容器在多个并发实例间传递时，其默认行为是引用传递，支持多个并发实例可以同时操作同一个容器实例。另外，也支持拷贝传递，即每个并发实例持有一个ArkTS容器实例。

ArkTS容器并不是线程安全的，内部使用了fail-fast（快速失败）机制：当检测多个并发实例同时对容器进行结构性改变时，会触发异常。因此，在多线程读写容器时，容器使用方需要使用ArkTS提供的异步锁机制保证ArkTS容器的安全访问。

当前ArkTS容器集主要包含以下几种容器：[Array](arkts-apis-arkts-collections-Array.md)、[Map](arkts-apis-arkts-collections-Map.md)、[Set](arkts-apis-arkts-collections-Set.md)、TypedArray（[Int8Array](arkts-apis-arkts-collections-Int8Array.md)、[Uint8Array](arkts-apis-arkts-collections-Uint8Array.md)、[Int16Array](arkts-apis-arkts-collections-Int16Array.md)、[Uint16Array](arkts-apis-arkts-collections-Uint16Array.md)、[Int32Array](arkts-apis-arkts-collections-Int32Array.md)、[Uint32Array](arkts-apis-arkts-collections-Uint32Array.md)、[Uint8ClampedArray](arkts-apis-arkts-collections-Uint8ClampedArray.md)、[Float32Array](arkts-apis-arkts-collections-Float32Array.md)）、[ArrayBuffer](arkts-apis-arkts-collections-ArrayBuffer.md)、[BitVector](arkts-apis-arkts-collections-BitVector.md)、[ConcatArray](arkts-apis-arkts-collections-ConcatArray.md)。

## 导入模块

```ts
import { collections } from '@kit.ArkTS';
```