# Archive File Compression and Decompression (C/C++)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rl123567-->
<!--Designer: @selina_jiang; @RainbowLLL-->
<!--Tester: @zheng1368-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=c7d936993002f781b8b9d24a87b7cc0e19cf8a23 translatedAt=2026-08-01T07:24:09.723Z pushedAt=2026-08-01T08:43:22.377Z -->

## When to Use

Starting from API version 26.0.0, file archive compression and decompression is supported. It is applicable to scenarios where multiple files and directories are packaged into a single archive file, or files are extracted from an archive file to a specified directory. Main application scenarios include:

- Packaging and compressing multiple files or directories into a single archive file for easier storage and transmission.

- Decompressing an archive file to extract files from the compressed package to a specified directory.

## Constraints

- The input and output paths for the archive compression and decompression APIs must be sandbox paths. For details, see [Application Sandbox](app-sandbox-directory.md).

- Currently, only ZIP archive files are supported.

## Description

For detailed API descriptions, see [oh_archive.h](../reference/apis-core-file-kit/capi-oh-archive-h.md).

### Archive File Compression APIs

| Name | Description |
| -------- | ---- |
| OH_Archive_Writer_OpenFile(const char *outFile, OH_Archive_OpenMode openMode, OH_Archive_Format fmt) | Opens an archive file and creates a writer. |
| OH_Archive_Writer_Add(OH_Archive_Writer_Ctx arc, const char **infiles, uint64_t fileNum) | Adds files or directories to the archive file. |
| OH_Archive_Writer_Close(OH_Archive_Writer_Ctx arc) | Closes the archive writer. |

### Archive File Decompression APIs

| Name | Description |
| -------- | ---- |
| OH_Archive_Reader_OpenFile(const char *inFile) | Opens an archive file and creates a reader. |
| OH_Archive_Reader_ExtractAllFile(OH_Archive_Reader_Ctx arc, const char *outDir) | Extracts all files from the archive file to a specified directory. |
| OH_Archive_Reader_Close(OH_Archive_Reader_Ctx arc) | Closes the archive reader. |

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

### Compressing Archive Files

1. Call **OH_Archive_Writer_OpenFile** to create an archive writer. Specify the output file path, open mode (such as **OH_ARCHIVE_OPEN_MODE_CREATE**), and archive format (such as **OH_ARCHIVE_FMT_ZIP**).

2. (Optional) Call **OH_Archive_Writer_SetCompressMethod** to set the compression algorithm and compression level. The **DEFLATE** compression algorithm is used by default, with a compression level of 6. You can adjust it as needed.

3. (Optional) Call **OH_Archive_Writer_SetProgressHandlerWithData** to set a progress callback for obtaining compression progress information.

4. Call **OH_Archive_Writer_Add** to add files or directories to the archive. Multiple files or directories can be added at the same time.

5. Call **OH_Archive_Writer_Close** to complete archive writing and release resources. You must call this API to release resources after compression is complete.

<!--@[zip_file_compress_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++
static napi_value ZipFileCompress(napi_env env, napi_callback_info info)
{
    // Obtain the input file path and output archive file path.
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    size_t inPathSize;
    size_t zipPathSize;
    char inPathBuf[PATH_BUFFER_SIZE];
    char zipPathBuf[PATH_BUFFER_SIZE];
    napi_get_value_string_utf8(env, argv[0], inPathBuf, sizeof(inPathBuf), &inPathSize);
    napi_get_value_string_utf8(env, argv[1], zipPathBuf, sizeof(zipPathBuf), &zipPathSize);

    // Create a test file and write content.
    std::string content = "test content this is test content Hello, hello! first line of data";
    std::string file(inPathBuf);
    std::ofstream stdfile(file, std::ios::out | std::ios::trunc);
    if (stdfile.is_open()) {
        stdfile << content;
        stdfile.close();
    }
    std::vector<const char *> srcFiles;
    srcFiles.push_back(file.c_str());

    int ret;
    // Open the archive file and create a writer, specifying the ZIP format.
    OH_Archive_Writer_Ctx arc = OH_Archive_Writer_OpenFile(zipPathBuf, OH_ARCHIVE_OPEN_MODE_CREATE, OH_ARCHIVE_FMT_ZIP);
    // Set the compression algorithm to DEFLATE and the compression level to 6.
    ret = OH_Archive_Writer_SetCompressMethod(arc, OH_ARCHIVE_COMPRESS_DEFLATE, int32_t(6)); // Compression level: 6.

    // Set the progress callback to obtain compression progress information.
    OH_Archive_ProgressHandlerWithData progressHandlerFunc = ProgressHandler;
    ret = OH_Archive_Writer_SetProgressHandlerWithData(arc, progressHandlerFunc, nullptr);
    // Add files to the archive.
    ret = OH_Archive_Writer_Add(arc, srcFiles.data(), srcFiles.size());
    // Close the archive writer to complete compression and release resources.
    ret = OH_Archive_Writer_Close(arc);
    napi_value retVal = nullptr;
    napi_create_int32(env, ret, &retVal);
    return retVal;
}
```

### Extracting an Archive File

1. Call **OH_Archive_Reader_OpenFile** to open the archive file and create a reader. Specify the path of the ZIP file.

2. (Optional) Call **OH_Archive_Reader_SetProgressHandlerWithData** to set the decompression progress callback.

3. Call **OH_Archive_Reader_ExtractAllFile** to extract the archive file to the specified directory. The extracted files will retain the original directory structure.

4. Call **OH_Archive_Reader_Close** to close the archive reader. This API must be called to release resources after decompression is complete.

<!--@[zip_file_decompress_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKCompressSample/entry/src/main/cpp/napi_init.cpp)-->

``` C++
static napi_value ZipFileDecompress(napi_env env, napi_callback_info info)
{
    // Obtain the input file path, archive file path, and decompression output directory path.
    size_t argc = 3;
    napi_value argv[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    size_t inPathSize;
    size_t zipPathSize;
    size_t outDirSize;
    char inPathBuf[PATH_BUFFER_SIZE];
    char zipPathBuf[PATH_BUFFER_SIZE];
    char outDirBuf[PATH_BUFFER_SIZE];
    napi_get_value_string_utf8(env, argv[0], inPathBuf, sizeof(inPathBuf), &inPathSize);
    napi_get_value_string_utf8(env, argv[1], zipPathBuf, sizeof(zipPathBuf), &zipPathSize);
    napi_get_value_string_utf8(env, argv[2], outDirBuf, sizeof(outDirBuf), &outDirSize); // The second parameter.

    // Compress the file to generate an archive file for subsequent decompression.
    int ret = ArchiveCompressFile(inPathBuf, zipPathBuf);
    // Open the archive file and create a reader.
    OH_Archive_Reader_Ctx ctx = OH_Archive_Reader_OpenFile(zipPathBuf);
    int userData[2] = {0};
    // Set the decompression progress callback.
    ret = OH_Archive_Reader_SetProgressHandlerWithData(ctx, ProgressHandler, (void *)userData);
    // Extract all files from the archive file to the specified directory.
    ret = OH_Archive_Reader_ExtractAllFile(ctx, outDirBuf);
    // Close the archive reader and release resources.
    ret = OH_Archive_Reader_Close(ctx);

    napi_value result = nullptr;
    napi_create_int32(env, ret, &result);
    return result;
}
```

## Key Points for Debugging and Verification

- Archive file compression: Verify that the generated ZIP file can be opened using standard decompression tools, with complete file content and correct directory structure.

- Archive file decompression: Verify that the decompressed file and directory structure are consistent with those before compression, and that the file content is not corrupted.