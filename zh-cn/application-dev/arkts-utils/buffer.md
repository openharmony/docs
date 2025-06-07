# Buffer与FastBuffer

## 场景介绍

Buffer和FastBuffer模块基于内存管理机制，将内存区域抽象为可以读写、修改的逻辑对象，旨在提供二进制数据处理的高效接口。每个Buffer实例对象都是连续的字节序列，支持创建自定义大小的内存块，方便存储和操作各种不同类型的数据。

Buffer和FastBuffer模块的主要应用场景包括：

1. **大数据传输**：当需要传输大量数据，如二进制文件、数据库记录或网络报文时，使用Buffer作为数据的存储和处理容器，可减少拷贝和内存消耗，提升传输效率。

2. **图像和音频处理**：在图像编码、解码，音频数据流处理等方面，Buffer可帮助开发者方便地操作像素或采样数据，确保数据的完整性。

3. **二进制数据操作**：Buffer提供稳定的接口解析和操作二进制数据。

## Buffer

Buffer模块的核心功能包括：

1. **创建和分配内存**：允许开发者基于uint32限制的指定大小初始化Buffer，创建后拥有固定的内存容量。

2. **读写和复制数据**：通过索引访问Buffer内的字节，支持按字节块读取和写入，支持将Buffer的某部分复制到另一个Buffer或数组。

3. **转换操作**：提供了将Buffer与基本类型（如Uint8Array、string等）之间互相转换的方法，满足不同数据处理需求。

4. **内存操作**：能够截取部分Buffer、切片以及合并多个Buffer，便于数据流的处理和管理。

Buffer模块各接口使用详见：[@ohos.buffer](../reference/apis-arkts/js-apis-buffer.md)。

## FastBuffer

FastBuffer是一种高性能二进制数据容器，专为固定长度字节序列的存储与处理设计。相比 Buffer，它在效率、读写速度上具有显著优势。

当构造FastBuffer的入参为number | FastBuffer | Uint8Array | ArrayBuffer | Array\<number\> | string时，推荐使用FastBuffer，可以高效处理大量二进制数据，如图片处理和文件接收上传等。

FastBuffer模块的核心功能包括：

1. **创建和分配内存**：允许开发者基于uint32限制的指定大小初始化Buffer，创建后拥有固定的内存容量。

2. **读写和复制数据**：通过索引访问Buffer内的字节，支持按字节块读取和写入，支持将FastBuffer的某部分复制到另一个FastBuffer或数组。

3. **转换操作**：提供了将FastBuffer与基本类型（如Uint8Array、string等）之间互相转换的方法，满足不同数据处理需求。

4. **内存操作**：能够截取部分FastBuffer、切片以及合并多个FastBuffer，便于数据流的处理和管理。

FastBuffer模块各接口使用详见：[@ohos.fastbuffer](../reference/apis-arkts/js-apis-fastbuffer.md)。