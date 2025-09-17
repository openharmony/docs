# Buffer and FastBuffer
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

## When to Use

The Buffer and FastBuffer modules abstract memory regions into logical objects that can be read, written, and modified, aiming to provide an efficient interface for handling binary data. Each Buffer instance is a contiguous sequence of bytes. It supports the creation of custom-sized memory blocks for storing and manipulating serialized data.

The Buffer and FastBuffer modules are primarily used in the following scenarios:

1. **Large data transfers**: When transmitting large volumes of data, like binary files, database records, or network packets, buffers serve as efficient containers for data storage and processing, reducing memory overhead and enhancing transfer efficiency.

2. **Image and audio processing**: Buffers help you manipulate pixel and sample data during image encoding/decoding and audio stream processing, ensuring data integrity.

3. **Binary data operation**: The Buffer module offers an interface for parsing and manipulating binary data.

## Buffer

The core functionalities of the Buffer module are as follows:

1. **Memory allocation**: You can initialize a buffer with a specified size, which is fixed upon creation.

2. **Data read/write and copying**: You can access bytes within a buffer by index, read and write data byte-by-byte, and copy parts of a buffer to another buffer or array.

3. **Conversion operations**: You can convert between Buffer and basic types (such as Uint8Array and string) to meet different data processing requirements.

4. **Memory manipulation**: Buffers can be sliced, spliced, and concatenated, making it easier to manage and process data streams.

For details about the APIs of the Buffer module, see [@ohos.buffer](../reference/apis-arkts/js-apis-buffer.md).

## FastBuffer

FastBuffer is a high-performance binary data container designed for storing and processing fixed-length byte sequences. Compared with Buffer, FastBuffer has higher efficiency and read/write speed.

When initializing a FastBuffer with parameters such as number, FastBuffer, Uint8Array, ArrayBuffer, Array\<number>, or string, it is highly recommended for handling large volumes of binary data, such as in image processing and file uploads/downloads.

The core functionalities of the FastBuffer module are as follows:

1. **Memory allocation**: You can initialize a FastBuffer based on the uint32 size specified. The memory capacity is fixed after the FastBuffer is created.

2. **Data read/write and copying**: You can access bytes within a buffer by index, read and write data byte-by-byte, and copy parts of a buffer to another buffer or array.

3. **Conversion operations**: You can convert between FastBuffer and basic types (such as Uint8Array and string) to meet different data processing requirements.

4. **Memory manipulation**: FastBuffers can be sliced, spliced, and concatenated, making it easier to manage and process data streams.

For details about the APIs of the FastBuffer module, see [@ohos.fastbuffer](../reference/apis-arkts/js-apis-fastbuffer.md).
