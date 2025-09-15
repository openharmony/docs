# Overview of Inter-Thread Communication Objects
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

In multithreaded concurrency scenarios, such as creating background threads via TaskPool or Worker, data interaction between different threads is necessary. Due to memory isolation between threads, inter-thread communication objects must implement value copying or memory sharing through serialization.

> **NOTE**
>
> - A maximum of 16 MB data can be serialized at a time.
> - Serialization does not support complex types decorated with decorators such as [@State](../ui/state-management/arkts-state.md), [@Prop](../ui/state-management/arkts-prop.md), and [@Link](../ui/state-management/arkts-link.md).

Currently, ArkTS supports the following types of objects for inter-thread communication:

- [Regular objects](normal-object.md): ArkTS supports direct passing of basic data types and custom objects (which must comply with serialization specifications).
- [ArrayBuffer objects](arraybuffer-object.md): used for efficient transmission of binary data, suitable for large segments of contiguous memory data (such as image or audio raw data).
- [SharedArrayBuffer objects](shared-arraybuffer-object.md): ArkTS supports shared memory across multiple threads, allowing direct access to the same memory area between threads, enhancing data transfer efficiency.
- [Transferable objects (NativeBinding objects)](transferabled-object.md): ArkTS supports transferring object ownership across threads (such as file descriptors and graphics resources), after which the original thread no longer has access rights.
- [Sendable objects](arkts-sendable.md): Objects that comply with the ArkTS language specification and can be shared, must be marked with the [@Sendable decorator](arkts-sendable.md#sendable-decorator) and meet Sendable constraints. For details, see [Usage Rules and Constraints for Sendable](sendable-constraints.md).
