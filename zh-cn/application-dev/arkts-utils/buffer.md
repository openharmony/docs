# Buffer与FastBuffer

## 场景介绍

Buffer和FastBuffer模块将内存区域抽象为可读写、修改的逻辑对象，提供高效的二进制数据处理接口。每个Buffer实例是连续的字节序列，支持创建自定义大小的内存块，用于存储和操作序列化后的数据。

Buffer和FastBuffer模块的主要应用场景包括：

1. **大数据传输**：传输大量数据，如二进制文件、数据库记录或网络报文时，使用Buffer作为数据的存储和处理容器，可减少拷贝和内存消耗，提升效率。

2. **图像和音频处理**：在图像编码、解码和音频数据流处理中，Buffer帮助开发者操作像素或采样数据，确保数据的完整性。

3. **二进制数据操作**：Buffer提供接口解析和操作二进制数据。

## Buffer

Buffer模块的核心功能包括：

1. **创建和分配内存**：允许指定大小初始化Buffer，创建后内存容量固定。

2. **读写和复制数据**：支持按索引访问Buffer内的字节，按字节块读取和写入，复制Buffer的某部分到其他Buffer或数组。

3. **转换操作**：提供Buffer与基本类型（如Uint8Array、string）之间的转换方法，满足不同的数据处理需求。

4. **内存操作**：支持截取部分Buffer、切片和合并多个Buffer，便于数据流的处理和管理。

Buffer模块各接口使用详见：[@ohos.buffer](../reference/apis-arkts/js-apis-buffer.md)。

## FastBuffer

FastBuffer是一种高性能二进制数据容器，专为固定长度字节序列的存储与处理设计，相比Buffer，它在效率和读写速度上具有显著优势。

当构造FastBuffer的入参为number | FastBuffer | Uint8Array | ArrayBuffer | Array\<number\> | string时，推荐使用FastBuffer处理大量二进制数据，如图片处理和文件接收上传等。

FastBuffer模块的核心功能包括：

1. **创建和分配内存**：允许基于uint32指定大小初始化FastBuffer，创建后内存容量固定。

2. **读写和复制数据**：支持按索引访问Buffer内的字节，按字节块读取和写入，复制FastBuffer的某部分到其他FastBuffer或数组。

3. **转换操作**：提供FastBuffer与基本类型（如Uint8Array、string）之间的转换方法，满足不同的数据处理需求。

4. **内存操作**：支持截取部分FastBuffer、切片和合并多个FastBuffer，便于数据流的处理和管理。

FastBuffer模块各接口使用详见：[@ohos.fastbuffer](../reference/apis-arkts/js-apis-fastbuffer.md)。