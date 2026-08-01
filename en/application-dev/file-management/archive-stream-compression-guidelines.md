# Streaming Compression and Decompression (C/C++)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rl123567-->
<!--Designer: @selina_jiang; @RainbowLLL-->
<!--Tester: @zheng1368-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=c7d936993002f781b8b9d24a87b7cc0e19cf8a23 translatedAt=2026-08-01T07:24:43.800Z pushedAt=2026-08-01T08:48:12.798Z -->

## When to Use

Starting from API version 26.0.0, streaming compression and decompression is supported. It is suitable for scenarios where continuous data streams require real-time compression or decompression. The main application scenarios include:

- Performing streaming compression on log data as it is generated, enabling on-the-fly compression.

- Performing real-time compression or decompression on network data streams to reduce the amount of data transmitted.

- Processes large volumes of data in chunks, eliminating the need to load all data into memory at once.

## Description

For detailed API descriptions, see [oh_archive.h](../reference/apis-core-file-kit/capi-oh-archive-h.md).

### Streaming Compression and Decompression APIs

| Name | Description |
| -------- | ---- |
| OH_Archive_StreamWrite_Create(OH_Archive_Stream_Config config) | Creates a streaming compression writer. |
| OH_Archive_StreamWrite_Start(OH_Archive_StreamWrite_Ctx ctx, OH_Archive_Stream_OutputHandler outputHandler, void *userData) | Starts streaming compression. |
| OH_Archive_StreamWrite_Update(OH_Archive_StreamWrite_Ctx ctx, const uint8_t *data, uint64_t size) | Inputs data into the streaming compressor for compression. |
| OH_Archive_StreamWrite_End(OH_Archive_StreamWrite_Ctx ctx, OH_Archive_StreamInfo *streamInfo) | Ends streaming compression and obtains compression result information. |
| OH_Archive_StreamWrite_Cancel(OH_Archive_StreamWrite_Ctx ctx) | Cancels streaming compression. |
| OH_Archive_StreamWrite_Destroy(OH_Archive_StreamWrite_Ctx ctx) | Destroys the streaming compression writer. |
| OH_Archive_StreamRead_Create(OH_Archive_Stream_Config config) | Creates a streaming decompression reader. |
| OH_Archive_StreamRead_Start(OH_Archive_StreamRead_Ctx ctx, OH_Archive_Stream_OutputHandler outputHandler, void *userData) | Starts streaming decompression. |
| OH_Archive_StreamRead_Update(OH_Archive_StreamRead_Ctx ctx, const uint8_t *data, uint64_t size) | Inputs data into the streaming decompressor for decompression. |
| OH_Archive_StreamRead_End(OH_Archive_StreamRead_Ctx ctx, OH_Archive_StreamInfo *streamInfo) | Ends streaming decompression and obtains decompression result information. |
| OH_Archive_StreamRead_Cancel(OH_Archive_StreamRead_Ctx ctx) | Cancels streaming decompression. |
| OH_Archive_StreamRead_Destroy(OH_Archive_StreamRead_Ctx ctx) | Destroys the streaming decompression reader. |

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

### Streaming Compression

1. Create a streaming compression configuration and call **OH_Archive_StreamWrite_Create** to create a streaming compression writer. You need to specify configuration information, including the block size, number of threads, compression algorithm, and verification method.

2. Call **OH_Archive_StreamWrite_Start** to start streaming compression. During compression, the compressed data is processed through the output callback function.

3. (Optional) Call **OH_Archive_StreamWrite_SetCompressLevel** to set the compression level. The default is level **6**.

4. Call **OH_Archive_StreamWrite_Update** multiple times to input data, which is suitable for streaming processing.

5. Call **OH_Archive_StreamWrite_End** to end streaming compression and obtain the result information.

6. Call **OH_Archive_StreamWrite_Destroy** to destroy the streaming compression writer and release resources.

<!--@[stream_compress_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++

static void InitStreamConfig(OH_Archive_Stream_Config *config)
{
    config->blockSize = 65536; // Set the block size to 65536 bytes.
    config->threadNum = 4;     // Set the number of threads to 4.
    config->method = OH_ARCHIVE_COMPRESS_DEFLATE; // Set the compression algorithm to DEFLATE.
    config->checksum = OH_ARCHIVE_CRC32;          // Set the checksum method to CRC32.
}

static napi_value StreamCompress(napi_env env, napi_callback_info info)
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

    // Initialize the streaming compression configuration and create the streaming compression writer.
    OH_Archive_Stream_Config config = {0};
    InitStreamConfig(&config);
    OH_Archive_StreamWrite_Ctx ctx = OH_Archive_StreamWrite_Create(config);

    const int bufferSize = 32 * 1024 * 4 + 2; // Set the read buffer size.
    unsigned char buffer[bufferSize];

    CreateRandomFile(inPathBuf, 1024 * 1024); // Create a 1024K test file.

    // Open the output file for writing compressed data.
    FILE *fout = fopen(outPathBuf, "wb");
    if (!fout) {
        return nullptr;
    }
    OH_Archive_ErrCode result = OH_ARCHIVE_OK;
    result = OH_Archive_StreamWrite_SetCompressLevel(ctx, 6); // Set the compression level to 6.
    // Start streaming compression and write the compressed data to a file through the WriteCallBack callback.
    result = OH_Archive_StreamWrite_Start(ctx, WriteCallBack, fout);
    uint64_t totalSize = 0;
    FILE *fi = fopen(inPathBuf, "rb");
    if (!fi) {
        (void)fclose(fout);
        return nullptr;
    }
    (void)fseek(fi, 0, SEEK_SET);

    // Read file data in a loop and input it to the compressor for compression.
    uint64_t read = 0;
    while ((read = fread(buffer, 1, bufferSize, fi)) > 0) {
        totalSize += read;
        result = OH_Archive_StreamWrite_Update(ctx, buffer, read);
        if (result != OH_ARCHIVE_OK) {
            break;
        }
    }
    (void)fclose(fi);
    // End streaming compression and obtain the compression result information.
    OH_Archive_StreamInfo streamInfo;
    result = OH_Archive_StreamWrite_End(ctx, &streamInfo);
    (void)fclose(fout);

    napi_value retVal = nullptr;
    napi_create_int32(env, result, &retVal);
    return retVal;
}
```

### Canceling Streaming Compression

1. Call **OH_Archive_StreamWrite_Create** to create a streaming compression writer.

2. Call **OH_Archive_StreamWrite_Start** to start streaming compression.

3. Call **OH_Archive_StreamWrite_Update** multiple times to input compression data.

4. Call **OH_Archive_StreamWrite_Cancel** to cancel streaming compression.

5. Call **OH_Archive_StreamWrite_End** to end streaming compression.

6. Call **OH_Archive_StreamWrite_Destroy** to destroy the streaming compression writer and release resources.

<!--@[stream_compress_cancel_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++
static napi_value StreamCompressCancel(napi_env env, napi_callback_info info)
{
    // Obtain the input file path and output file path.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    char inPathBuf[PATH_BUFFER_SIZE];
    char outPathBuf[PATH_BUFFER_SIZE];
    napi_get_value_string_utf8(env, argv[0], inPathBuf, sizeof(inPathBuf), nullptr);
    napi_get_value_string_utf8(env, argv[1], outPathBuf, sizeof(outPathBuf), nullptr);

    // Initialize the streaming compression configuration and create the streaming compression writer.
    OH_Archive_Stream_Config config;
    InitStreamConfig(&config);
    OH_Archive_StreamWrite_Ctx ctx = OH_Archive_StreamWrite_Create(config);

    CreateRandomFile(inPathBuf, 1024 * 1024); // Create a 1024K test file.
    // Open the output file for writing compressed data.
    FILE *fout = fopen(outPathBuf, "wb");
    if (!fout) {
        return nullptr;
    }
    OH_Archive_ErrCode result = OH_ARCHIVE_OK;
    result = OH_Archive_StreamWrite_SetCompressLevel(ctx, 6); // Set the compression level to 6.
    // Start streaming compression and write the compressed data to the file through the WriteCallBack callback.
    result = OH_Archive_StreamWrite_Start(ctx, WriteCallBack, fout);
    const int bufferSize = 32 * 1024 * 4 + 2; // Set the read buffer size.
    unsigned char buffer[bufferSize];
    uint64_t totalSize = 0;
    FILE *fi = fopen(inPathBuf, "rb");
    if (!fi) {
        (void)fclose(fout);
        return nullptr;
    }

    // Read file data in a loop and input it to the compressor for compression. Cancel compression when the accumulated data exceeds the threshold.
    uint64_t read = 0;
    uint64_t cancelThreshold = 2000; // Set the cancel threshold to 2000 bytes.
    while ((read = fread(buffer, 1, bufferSize, fi)) > 0) {
        totalSize += read;
        if (totalSize > cancelThreshold) {
            // The accumulated data exceeds the threshold. Cancel streaming compression.
            result = OH_Archive_StreamWrite_Cancel(ctx);
            break;
        } else {
            result = OH_Archive_StreamWrite_Update(ctx, buffer, read);
        }
        if (result != OH_ARCHIVE_OK) {
            break;
        }
    }
    (void)fclose(fi);
    // End streaming compression. Do not obtain compression result information in the cancel scenario.
    result = OH_Archive_StreamWrite_End(ctx, nullptr);
    (void)fclose(fout);
    napi_value retVal = nullptr;
    napi_create_int32(env, result, &retVal);
    return retVal;
}
```

### Streaming Decompression

1. Create a streaming decompression configuration and call **OH_Archive_StreamRead_Create** to create a streaming decompression reader. The configuration information must be specified and must be consistent with the configuration used during compression.

2. Call **OH_Archive_StreamRead_Start** to start streaming decompression. During decompression, the decompressed original data is processed through the output callback function.

3. Call **OH_Archive_StreamRead_Update** multiple times to input compressed data for decompression.

4. Call **OH_Archive_StreamRead_End** to end streaming decompression and obtain the result information.

5. Call **OH_Archive_StreamRead_Destroy** to destroy the streaming decompression reader and release resources.

<!--@[stream_decompress_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++
static napi_value StreamDecompress(napi_env env, napi_callback_info info)
{
    size_t argc = 0;
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);

    int ret;
    // Initialize the streaming compression configuration. The decompression configuration must be consistent with that used during compression.
    OH_Archive_Stream_Config config = {0};
    InitStreamConfig(&config);

    // Generate test compressed data through streaming compression first.
    uint64_t srcSize = 30 * 1024; // The data length is 30 * 1024.
    uint64_t zipSize = srcSize * 1.1;
    void *zipBuffer = reinterpret_cast<void *>(malloc(zipSize));
    OH_Archive_StreamInfo compressInfo = {0, 0, 0};
    CreateFileWithStreamWrite(&config, srcSize, zipBuffer, &compressInfo);

    // Create a streaming decompression reader.
    OH_Archive_StreamRead_Ctx readCtx = OH_Archive_StreamRead_Create(config);

    uint64_t unzipSize = srcSize;
    void *unzipBuffer = reinterpret_cast<void *>(malloc(unzipSize));

    // Start streaming decompression, and write the decompressed data to unzipBuffer through the WriteHandler callback.
    ret = OH_Archive_StreamRead_Start(readCtx, WriteHandler, unzipBuffer);

    // Input compressed data in segments for decompression.
    uint8_t *unzPtr = (uint8_t *)zipBuffer;
    size_t unzLeft = compressInfo.totalOutSize;

    while (unzLeft > 0) {
        size_t unzchunk = (unzLeft > 1024) ? 1024 : unzLeft; // Process at most 1024 bytes at a time.
        ret = OH_Archive_StreamRead_Update(readCtx, unzPtr, unzchunk);

        unzPtr += unzchunk;
        unzLeft -= unzchunk;
    }

    // End streaming decompression and obtain decompression result information.
    OH_Archive_StreamInfo decompressInfo2 = {};
    ret = OH_Archive_StreamRead_End(readCtx, &decompressInfo2);

    // Destroy the streaming decompression reader and release resources.
    OH_Archive_StreamRead_Destroy(readCtx);

    free(zipBuffer);
    free(unzipBuffer);
    napi_value result = nullptr;
    napi_create_int32(env, ret, &result);
    return result;
}
```

### Canceling Streaming Decompression

1. Call **OH_Archive_StreamRead_Create** to create a streaming decompression reader.

2. Call **OH_Archive_StreamRead_Start** to start streaming decompression.

3. Call **OH_Archive_StreamRead_Update** multiple times to input compressed data.

4. Call **OH_Archive_StreamRead_Cancel** to cancel streaming decompression.

5. Call **OH_Archive_StreamRead_End** to end streaming decompression.

6. Call **OH_Archive_StreamRead_Destroy** to destroy the streaming decompression reader and release resources.

<!--@[stream_decompress_cancel_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++
static napi_value StreamDecompressCancel(napi_env env, napi_callback_info info)
{
    size_t argc = 0;
    napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);

    int ret;

    // Initialize the streaming compression configuration. The decompression configuration must be consistent with the compression settings.
    OH_Archive_Stream_Config config = {0};
    InitStreamConfig(&config);

    // Generate test compressed data through streaming compression.
    uint64_t srcSize = 30 * 1024; // The data length is 30 * 1024.
    uint64_t zipSize = srcSize * 1.1;
    void *zipBuffer = reinterpret_cast<void *>(malloc(zipSize));
    OH_Archive_StreamInfo compressInfo = {0, 0, 0};
    CreateFileWithStreamWrite(&config, srcSize, zipBuffer, &compressInfo);
    // Create a streaming decompression reader.
    OH_Archive_StreamRead_Ctx readCtx = OH_Archive_StreamRead_Create(config);

    uint64_t unzipSize = srcSize;
    void *unzipBuffer = reinterpret_cast<void *>(malloc(unzipSize));

    // Start streaming decompression and write the decompressed data to unzipBuffer through the WriteHandler callback.
    ret = OH_Archive_StreamRead_Start(readCtx, WriteHandler, unzipBuffer);
    uint8_t *unzPtr = (uint8_t *)zipBuffer;
    size_t unzLeft = compressInfo.totalOutSize;

    // Input compressed data in segments for decompression. Cancel decompression when the remaining data is less than the threshold.
    while (unzLeft > 0) {
        size_t unzchunk = (unzLeft > 1024) ? 1024 : unzLeft; // Process at most 1024 bytes each time.
        if (unzLeft < 20 * 1024) { // Cancel when the remaining data is less than 20 * 1024 bytes.
            // Cancel streaming decompression.
            ret = OH_Archive_StreamRead_Cancel(readCtx);
            ret = OH_Archive_StreamRead_Update(readCtx, unzPtr, unzchunk);
            break;
        }
        ret = OH_Archive_StreamRead_Update(readCtx, unzPtr, unzchunk);

        unzPtr += unzchunk;
        unzLeft -= unzchunk;
    }

    // End streaming decompression. In the cancel scenario, decompression result information is not obtained.
    OH_Archive_StreamInfo *decompressInfo2 = nullptr;
    ret = OH_Archive_StreamRead_End(readCtx, decompressInfo2);
    // Destroy the streaming decompression reader and release resources.
    OH_Archive_StreamRead_Destroy(readCtx);

    free(zipBuffer);
    free(unzipBuffer);
    napi_value result = nullptr;
    napi_create_int32(env, ret, &result);
    return result;
}
```

## Key Points for Debugging and Verification

- Streaming compression and decompression: Verify that data provided in multiple chunks can be correctly decompressed after compression, and that the decompressed result is identical to the original data.

- Canceling streaming compression: Verify that streaming compression is terminated successfully after cancellation, with no resource leaks.

- Canceling streaming decompression: Verify that streaming decompression is terminated successfully after cancellation, with no resource leaks.