# Buffer Compression and Decompression (C/C++)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rl123567-->
<!--Designer: @selina_jiang; @RainbowLLL-->
<!--Tester: @zheng1368-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=c7d936993002f781b8b9d24a87b7cc0e19cf8a23 translatedAt=2026-08-01T07:23:43.169Z pushedAt=2026-08-01T08:43:03.059Z -->

## When to Use

Starting from API version 26.0.0, buffer compression and decompression capabilities are available for compressing or decompressing an entire block of data in memory in a single operation. They are primarily intended for scenarios involving relatively small and complete data sets, offering simple APIs and fast operation.

- Buffer compression: quickly compresses data in memory to save storage space.

- Buffer decompression: decompresses previously compressed data in memory to restore the original data.

## Description

For detailed API descriptions, see [oh_archive.h](../reference/apis-core-file-kit/capi-oh-archive-h.md).

| Name | Description |
| -------- | ---- |
| OH_Archive_BufferWriteCompressBound(OH_Archive_CompressMethod method, uint64_t sourceLen) | Calculates the output buffer size required for buffer compression. |
| OH_Archive_BufferWrite(uint8_t *dstBuffer, uint64_t *dstSize, const uint8_t *srcBuffer, uint64_t srcSize, OH_Archive_CompressMethod method, int32_t compressLevel) | Compresses buffer data. |
| OH_Archive_BufferRead(uint8_t *dstBuffer, uint64_t *dstSize, const uint8_t *srcBuffer, uint64_t srcSize, OH_Archive_CompressMethod method) | Decompresses buffer data. |

## Preparations

**Linking the Dynamic Library in CMake**

Add the following libraries to **CMakeLists.txt**:

```txt
target_link_libraries(sample PUBLIC liboharchive.so)
```

**Including the Header File**

```c++
#include <filemanagement/archive/oh_archive.h>
```

## How to Develop

### Buffer Compression

1. Call **OH_Archive_BufferWriteCompressBound** to calculate the output buffer size. Before compression, call this API to obtain the required output buffer size and ensure that the output buffer is large enough to hold the compressed data.

2. Call **OH_Archive_BufferWrite** to compress the data in the buffer. Specify the input data, output buffer, data size, compression method, and compression level. The actual size of the compressed data is returned through **dstSize**.

<!--@[buffer_compress_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++
static napi_value BufferCompress(napi_env env, napi_callback_info info)
{
    // Obtain the input file path and output file path.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    size_t inPathSize;
    size_t outPathSize;
    char inPathBuf[PATH_BUFFER_SIZE];
    char outPathBuf[PATH_BUFFER_SIZE];
    napi_get_value_string_utf8(env, argv[0], inPathBuf, sizeof(inPathBuf), &inPathSize);
    napi_get_value_string_utf8(env, argv[1], outPathBuf, sizeof(outPathBuf), &outPathSize);

    CreateRandomFile(inPathBuf, 1024 * 1024); // Create a 1024 KB test file.
    // Read file data into the memory buffer.
    char *source = nullptr;
    uint64_t sourceLen;
    ReadFileData(inPathBuf, &source, &sourceLen);

    uint64_t destLen = 0;
    uint8_t *dest = nullptr;

    // Calculate the maximum output buffer size required for compressed data.
    uint64_t bound = OH_Archive_BufferWriteCompressBound(OH_ARCHIVE_COMPRESS_DEFLATE, sourceLen);
    if (bound > MALLOC_THRESHOLD) {
        return nullptr;
    }
    dest = (uint8_t *)malloc(bound);
    if (dest == nullptr) {
        free(source);
        return nullptr;
    }
    destLen = bound;

    // Compress the buffer data using the DEFLATE algorithm at compression level 0.
    OH_Archive_ErrCode ret = OH_Archive_BufferWrite(dest, &destLen, reinterpret_cast<uint8_t *>(source), sourceLen,
                                                    OH_ARCHIVE_COMPRESS_DEFLATE, 0);

    free(source);
    free(dest);
    napi_value result = nullptr;
    napi_create_int32(env, ret, &result);
    return result;
}
```

### Buffer Decompression

Prepare the output buffer and call **OH_Archive_BufferRead** to decompress the data. Specify the compressed data buffer, output buffer, data length, and compression algorithm. The actual size of the decompressed data is returned through **dstSize**. It is recommended that the same algorithm parameters be used for both compression and decompression.

<!--@[buffer_decompress_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++
static napi_value BufferDecompress(napi_env env, napi_callback_info info)
{
    size_t argc = 0;
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);

    int ret;
    // Generate random test data.
    uint64_t dataSize = 1024 * 1024;
    uint8_t *srcBuffer = (uint8_t *)malloc(dataSize);
    if (srcBuffer == nullptr) {
        return nullptr;
    }

    for (size_t i = 0; i < dataSize; ++i) {
        srcBuffer[i] = static_cast<uint8_t>(TestRandomInt(0, 256)); // Less than 256, within the byte range.
    }

    // Compress the data first for subsequent decompression verification.
    uint64_t bound = OH_Archive_BufferWriteCompressBound(OH_ARCHIVE_COMPRESS_DEFLATE, dataSize);
    uint64_t compressedSize = bound;
    uint8_t *compressedBuffer = (uint8_t *)malloc(compressedSize);
    if (compressedBuffer == nullptr) {
        return nullptr;
    }
    ret = OH_Archive_BufferWrite(compressedBuffer, &compressedSize, srcBuffer, dataSize, OH_ARCHIVE_COMPRESS_DEFLATE,
                                 int32_t(6)); // Compression level: 6.
    // Allocate the decompression output buffer and perform decompression.
    uint8_t *decompressedBuffer = (uint8_t *)malloc(dataSize);
    if (decompressedBuffer == nullptr) {
        return nullptr;
    }
    uint64_t decompressedSize = dataSize;
    ret = OH_Archive_BufferRead(decompressedBuffer, &decompressedSize, compressedBuffer, compressedSize,
                                OH_ARCHIVE_COMPRESS_DEFLATE);
    // Check whether the decompressed data is consistent with the original data.
    bool isEqual = std::memcmp(decompressedBuffer, srcBuffer, dataSize) == 0;
    free(srcBuffer);
    free(compressedBuffer);
    free(decompressedBuffer);

    napi_value result = nullptr;
    napi_create_int32(env, !isEqual, &result);
    return result;
}
```

## Key Points for Debugging and Verification

Buffer compression and decompression: verify that the data decompressed after compression is completely consistent with the original data, with no data loss.

<!--no_check-->