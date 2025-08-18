# 线程间通信对象概述
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

在多线程并发场景中，例如通过TaskPool或Worker创建后台线程，不同线程间需要进行数据交互。由于线程间内存隔离，线程间通信对象必须通过序列化实现值拷贝或内存共享。

> **说明：**
>
> - 单次序列化传输的数据量大小限制为16MB。
> - 序列化不支持使用[@State装饰器](../ui/state-management/arkts-state.md)、[@Prop装饰器](../ui/state-management/arkts-prop.md)、[@Link装饰器](../ui/state-management/arkts-link.md)等装饰器修饰的复杂类型。

目前ArkTS支持线程间通信的对象有以下几种：

- [普通对象](normal-object.md)：可直接传递基本数据类型及自定义对象（需满足序列化规范）。
- [ArrayBuffer对象](arraybuffer-object.md)：用于二进制数据的高效传递，适用于大段连续内存数据（如图片、音频原始数据）。
- [SharedArrayBuffer对象](shared-arraybuffer-object.md)：支持多线程共享内存，允许线程间直接访问同一块内存区域，提升数据传递效率。
- [Transferable对象（NativeBinding对象）](transferabled-object.md)：支持跨线程转移对象所有权（如文件描述符、图形资源等），转移后原线程不再拥有访问权限。
- [Sendable对象](arkts-sendable.md)：符合ArkTS语言规范的可共享对象，需通过[@Sendable装饰器](arkts-sendable.md#sendable装饰器)标记，并且满足Sendable约束，详情可查[Sendable使用规则与约束](sendable-constraints.md)。
