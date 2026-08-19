# oh_archive.h

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rl123567-->
<!--Designer: @selina_jiang; @RainbowLLL-->
<!--Tester: @zheng1368-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=bb49b7ed5e4e9e800a0691df554198c36528b3e0 translatedAt=2026-08-14T11:50:06.466Z pushedAt=2026-08-17T03:46:06.825Z -->

## Overview

Defines APIs of the compression and decompression module, and provides native APIs for file compression and decompression, streaming data compression and decompression, and buffer compression and decompression.

**File to include:** <filemanagement/archive/oh_archive.h>

**Library:** liboharchive.so

**System capability**: SystemCapability.FileManagement.File.FileIO

**Since**: 26.0.0

**Related module:** [Archive](capi-archive.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_Archive_StreamInfo](capi-archive-oh-archive-streaminfo.md) | OH_Archive_StreamInfo | Defines a struct for compression and decompression of streaming information. |
| [OH_Archive_Stream_Config](capi-archive-oh-archive-stream-config.md) | OH_Archive_Stream_Config | Defines a struct for streaming compression configuration. |
| [ArchiveWriteCtx*](capi-archive-archivewritectx.md) | OH_Archive_Writer_Ctx | Defines a pointer to the file compressor context. |
| [ArchiveReadCtx*](capi-archive-archivereadctx.md) | OH_Archive_Reader_Ctx | Defines a pointer to the file decompressor context. |
| [ArchiveStreamWriteCtx*](capi-archive-archivestreamwritectx.md) | OH_Archive_StreamWrite_Ctx | Defines a pointer to the streaming compressor context. |
| [ArchiveStreamReadCtx*](capi-archive-archivestreamreadctx.md) | OH_Archive_StreamRead_Ctx | Defines a pointer to the streaming decompressor context. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_Archive_Format](#oh_archive_format) | OH_Archive_Format | Enumerates the file formats. |
| [OH_Archive_CompressMethod](#oh_archive_compressmethod) | OH_Archive_CompressMethod | Enumerates the compression algorithms. |
| [OH_Archive_OpenMode](#oh_archive_openmode) | OH_Archive_OpenMode | Enumerates the file opening modes. |
| [OH_Archive_ProgressType](#oh_archive_progresstype) | OH_Archive_ProgressType | Enumerates the file progress control types. |
| [OH_Archive_StreamChecksumAlg](#oh_archive_streamchecksumalg) | OH_Archive_StreamChecksumAlg | Enumerates the Hash algorithms used to calculate the checksum. |

### Functions

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [typedef OH_Archive_ProgressType (\*OH_Archive_ProgressHandlerWithData)(int32_t progress, void *userData)](#oh_archive_progresshandlerwithdata) | OH_Archive_ProgressHandlerWithData | Defines a callback for progress processing. |
| [typedef uint64_t (\*OH_Archive_Stream_OutputHandler)(const void* data, uint64_t size, void* userData)](#oh_archive_stream_outputhandler) | OH_Archive_Stream_OutputHandler | Defines a pointer to the user-defined callback, which is used to process the compressed data. |
| [OH_Archive_Reader_Ctx OH_Archive_Reader_OpenFile(const char *infile)](#oh_archive_reader_openfile) | - | Opens a file and reads it. |
| [OH_Archive_ErrCode OH_Archive_Reader_SetProgressHandlerWithData(OH_Archive_Reader_Ctx arc, OH_Archive_ProgressHandlerWithData progressHandler, void *userData)](#oh_archive_reader_setprogresshandlerwithdata) | - | Sets a callback for the progress and user data of the file decompressor. |
| [OH_Archive_ErrCode OH_Archive_Reader_ExtractAllFile(OH_Archive_Reader_Ctx arc, const char *outDir)](#oh_archive_reader_extractallfile) | - | Extracts all files from the package. |
| [OH_Archive_ErrCode OH_Archive_Reader_Close(OH_Archive_Reader_Ctx arc)](#oh_archive_reader_close) | - | Closes an opened compressed file and releases related resources. |
| [OH_Archive_Writer_Ctx OH_Archive_Writer_OpenFile(const char *outfile, OH_Archive_OpenMode openMode, OH_Archive_Format fmt)](#oh_archive_writer_openfile) | - | Creates and opens a compressed file. |
| [OH_Archive_ErrCode OH_Archive_Writer_SetCompressMethod(OH_Archive_Writer_Ctx arc, OH_Archive_CompressMethod method, int32_t compressLevel)](#oh_archive_writer_setcompressmethod) | - | Sets the compression algorithm for a compressed file. |
| [OH_Archive_ErrCode OH_Archive_Writer_SetProgressHandlerWithData(OH_Archive_Writer_Ctx arc, OH_Archive_ProgressHandlerWithData progressHandler, void *userData)](#oh_archive_writer_setprogresshandlerwithdata) | - | Sets a callback for the progress and user data of the file compressor. |
| [OH_Archive_ErrCode OH_Archive_Writer_Add(OH_Archive_Writer_Ctx arc, const char **infiles, uint64_t fileNum)](#oh_archive_writer_add) | - | Adds a file list to the package.|
| [OH_Archive_ErrCode OH_Archive_Writer_Close(OH_Archive_Writer_Ctx arc)](#oh_archive_writer_close) | - | Closes the file compressor. This function completes the archive writing process, flushes buffered data to the output, and releases resources related to the context struct of the file compressor. |
| [uint64_t OH_Archive_BufferWriteCompressBound(OH_Archive_CompressMethod method, uint64_t sourceLen)](#oh_archive_bufferwritecompressbound) | - | Calculates the maximum compressed data size for a given source data length. |
| [OH_Archive_ErrCode OH_Archive_BufferWrite(uint8_t *dstBuffer, uint64_t *dstSize, const uint8_t *srcBuffer, uint64_t srcSize, OH_Archive_CompressMethod method, int32_t compressLevel)](#oh_archive_bufferwrite) | - | Writes data to the buffer and compresses the data. |
| [OH_Archive_ErrCode OH_Archive_BufferRead(uint8_t *dstBuffer, uint64_t *dstSize, const uint8_t *srcBuffer, uint64_t srcSize, OH_Archive_CompressMethod method)](#oh_archive_bufferread) | - | Reads data from the buffer and decompresses the data. |
| [OH_Archive_StreamWrite_Ctx OH_Archive_StreamWrite_Create(OH_Archive_Stream_Config config)](#oh_archive_streamwrite_create) | - | Creates a context struct for streaming compression. |
| [OH_Archive_ErrCode OH_Archive_StreamWrite_Start(OH_Archive_StreamWrite_Ctx ctx, OH_Archive_Stream_OutputHandler outputHandler, void* userData)](#oh_archive_streamwrite_start) | - | Starts a compression task and initializes the user callback function and user data. |
| [OH_Archive_ErrCode OH_Archive_StreamWrite_SetCompressLevel(OH_Archive_StreamWrite_Ctx ctx, int32_t compressLevel)](#oh_archive_streamwrite_setcompresslevel) | - | Sets the compression level of streaming compression. |
| [OH_Archive_ErrCode OH_Archive_StreamWrite_Cancel(OH_Archive_StreamWrite_Ctx ctx)](#oh_archive_streamwrite_cancel) | - | Forcefully cancels the current compression operation. |
| [OH_Archive_ErrCode OH_Archive_StreamWrite_Update(OH_Archive_StreamWrite_Ctx ctx, const uint8_t* data, uint64_t size)](#oh_archive_streamwrite_update) | - | Submits the compressed data. |
| [OH_Archive_ErrCode OH_Archive_StreamWrite_End(OH_Archive_StreamWrite_Ctx ctx, OH_Archive_StreamInfo *streamInfo)](#oh_archive_streamwrite_end) | - | Stops compression and refreshes all remaining data. |
| [void OH_Archive_StreamWrite_Destroy(OH_Archive_StreamWrite_Ctx ctx)](#oh_archive_streamwrite_destroy) | - | Destroys the compression instance and releases related resources. |
| [OH_Archive_StreamRead_Ctx OH_Archive_StreamRead_Create(OH_Archive_Stream_Config config)](#oh_archive_streamread_create) | - | Creates a context struct for streaming decompression. |
| [OH_Archive_ErrCode OH_Archive_StreamRead_Start(OH_Archive_StreamRead_Ctx ctx, OH_Archive_Stream_OutputHandler outputHandler, void* userData)](#oh_archive_streamread_start) | - | Starts a decompression task and initializes the user callback function and user data. |
| [OH_Archive_ErrCode OH_Archive_StreamRead_Cancel(OH_Archive_StreamRead_Ctx ctx)](#oh_archive_streamread_cancel) | - | Forcefully cancels the current decompression operation. |
| [OH_Archive_ErrCode OH_Archive_StreamRead_Update(OH_Archive_StreamRead_Ctx ctx, const uint8_t* data, uint64_t size)](#oh_archive_streamread_update) | - | Submits the decompressed data. |
| [OH_Archive_ErrCode OH_Archive_StreamRead_End(OH_Archive_StreamRead_Ctx ctx, OH_Archive_StreamInfo *streamInfo)](#oh_archive_streamread_end) | - | Stops decompression, refreshes all remaining data, and clears the memory. |
| [void OH_Archive_StreamRead_Destroy(OH_Archive_StreamRead_Ctx ctx)](#oh_archive_streamread_destroy) | - | Destroys the decompression instance and releases related resources. |

## Enum Description

### OH_Archive_Format

```c
enum OH_Archive_Format
```

**Description**

Enumerates the file formats.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ARCHIVE_FMT_ZIP = 0 | ZIP format.<br>**Since:** 26.0.0 |

### OH_Archive_CompressMethod

```c
enum OH_Archive_CompressMethod
```

**Description**

Enumerates the compression algorithms.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ARCHIVE_NO_COMPRESSION = 0 | No compression.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_COMPRESS_DEFLATE = 8 | DEFLATE compression algorithm.<br>**Since:** 26.0.0 |

### OH_Archive_OpenMode

```c
enum OH_Archive_OpenMode
```

**Description**

Enumerates the file opening modes.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ARCHIVE_OPEN_MODE_CREATE = 0 | Creation mode. A file will be created in this mode. If the file already exists, it will be overwritten.<br>**Since:** 26.0.0 |

### OH_Archive_ProgressType

```c
enum OH_Archive_ProgressType
```

**Description**

Enumerates the file progress control types.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ARCHIVE_PROGRESS_CONTINUE = 0 | Continues the compression/decompression operation.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_PROGRESS_CANCEL = 1 | Cancels the compression/decompression operation.<br>**Since:** 26.0.0 |

### OH_Archive_StreamChecksumAlg

```c
enum OH_Archive_StreamChecksumAlg
```

**Description**

Enumerates the Hash algorithms used to calculate the checksum.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ARCHIVE_NO_CHECKSUM = 0 | No additional hash value is calculated.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_CRC32 = 1 | Use cyclic redundancy check (CRC32) to calculate the checksum.<br>**Since:** 26.0.0 |

## Function Description

### OH_Archive_ProgressHandlerWithData()

```c
typedef OH_Archive_ProgressType (*OH_Archive_ProgressHandlerWithData)(int32_t progress, void *userData)
```

**Description**

Defines a callback for progress processing.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| int32_t progress | Processing progress, in percentage. The value range is [0, 100]. |
| void \*userData | Pointer to the user-defined data, which is passed in when the callback is invoked. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ProgressType](capi-oh-archive-h.md#oh_archive_progresstype) | **OH_ARCHIVE_PROGRESS_CONTINUE**: continues the current compression/decompression operation.<br>         **OH_ARCHIVE_PROGRESS_CANCEL**: cancels the current compression/decompression operation. |

### OH_Archive_Stream_OutputHandler()

```c
typedef uint64_t (*OH_Archive_Stream_OutputHandler)(const void* data, uint64_t size, void* userData)
```

**Description**

Defines a pointer to the user-defined callback, which is used to process the compressed data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| const void\* data | Pointer to the compressed data. |
| uint64_t size | Length of the compressed data. |
| void\* userData | User-defined context, which is returned in the callback. |

**Returns**

| Type | Description |
| -- | -- |
| uint64_t | Number of bytes that are successfully processed. |

### OH_Archive_Reader_OpenFile()

```c
OH_Archive_Reader_Ctx OH_Archive_Reader_OpenFile(const char *infile)
```

**Description**

Opens a file and reads it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| const char *infile | Path of the source file. The app must have the read permission. The absolute path length cannot exceed 4096 bytes. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_Reader_Ctx](capi-archive-archivereadctx.md) | Context struct of the file reader. If the operation fails, **NULL** is returned. |

### OH_Archive_Reader_SetProgressHandlerWithData()

```c
OH_Archive_ErrCode OH_Archive_Reader_SetProgressHandlerWithData(OH_Archive_Reader_Ctx arc, OH_Archive_ProgressHandlerWithData progressHandler, void *userData)
```

**Description**

Sets a callback for the progress and user data of the file decompressor.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Reader_Ctx](capi-archive-archivereadctx.md) arc | Context handle of the file decompressor. |
| [OH_Archive_ProgressHandlerWithData](capi-oh-archive-h.md#oh_archive_progresshandlerwithdata) progressHandler | Callback for processing progress updates. |
| void *userData | User-defined context data during processing of the progress callback. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_Reader_ExtractAllFile()

```c
OH_Archive_ErrCode OH_Archive_Reader_ExtractAllFile(OH_Archive_Reader_Ctx arc, const char *outDir)
```

**Description**

Extracts all files from the package.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Reader_Ctx](capi-archive-archivereadctx.md) arc | Context handle of the file decompressor. |
| const char *outDir | Output directory. The app must have the write permission. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_Reader_Close()

```c
OH_Archive_ErrCode OH_Archive_Reader_Close(OH_Archive_Reader_Ctx arc)
```

**Description**

Closes an opened compressed file and releases related resources.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Reader_Ctx](capi-archive-archivereadctx.md) arc | Context handle of the file decompressor. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_Writer_OpenFile()

```c
OH_Archive_Writer_Ctx OH_Archive_Writer_OpenFile(const char *outfile, OH_Archive_OpenMode openMode, OH_Archive_Format fmt)
```

**Description**

Creates and opens a compressed file.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| const char *outfile | Path of the target compressed file. The app must have the write permission. The absolute path length cannot exceed 4096 bytes. |
| [OH_Archive_OpenMode](capi-oh-archive-h.md#oh_archive_openmode) openMode | File opening mode. |
| [OH_Archive_Format](capi-oh-archive-h.md#oh_archive_format) fmt | Archive format. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_Writer_Ctx](capi-archive-archivewritectx.md) | Context handle of the file compressor. If the operation fails, **NULL** is returned. |

### OH_Archive_Writer_SetCompressMethod()

```c
OH_Archive_ErrCode OH_Archive_Writer_SetCompressMethod(OH_Archive_Writer_Ctx arc, OH_Archive_CompressMethod method, int32_t compressLevel)
```

**Description**

Sets the compression algorithm for a compressed file.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Writer_Ctx](capi-archive-archivewritectx.md) arc | Context handle of the file compressor. |
| [OH_Archive_CompressMethod](capi-oh-archive-h.md#oh_archive_compressmethod) method | Compression algorithm. |
| int32_t compressLevel | Compression level. For **OH_ARCHIVE_COMPRESS_DEFLATE**, the compression level ranges from 0 to 9. The default level is **6**. The value **0** indicates no compression. The higher the compression level, the higher the compression rate, and the slower the speed. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_Writer_SetProgressHandlerWithData()

```c
OH_Archive_ErrCode OH_Archive_Writer_SetProgressHandlerWithData(OH_Archive_Writer_Ctx arc, OH_Archive_ProgressHandlerWithData progressHandler, void *userData)
```

**Description**

Sets a callback for the progress and user data of the file compressor.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Writer_Ctx](capi-archive-archivewritectx.md) arc | Context handle of the file compressor. |
| [OH_Archive_ProgressHandlerWithData](capi-oh-archive-h.md#oh_archive_progresshandlerwithdata) progressHandler | Callback for processing progress updates. |
| void *userData | User-defined context data during processing of the progress callback. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_Writer_Add()

```c
OH_Archive_ErrCode OH_Archive_Writer_Add(OH_Archive_Writer_Ctx arc, const char **infiles, uint64_t fileNum)
```

**Description**

Adds a file list to the package.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Writer_Ctx](capi-archive-archivewritectx.md) arc | Context handle of the file compressor. |
| const char **infiles | Files to be compressed. |
| uint64_t fileNum | Number of files. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_Writer_Close()

```c
OH_Archive_ErrCode OH_Archive_Writer_Close(OH_Archive_Writer_Ctx arc)
```

**Description**

Closes the file compressor. This function completes the package write process, flushes the buffered data to the output, and releases the resources related to the context structure of the file compressor.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Writer_Ctx](capi-archive-archivewritectx.md) arc | Context handle of the file compressor. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_BufferWriteCompressBound()

```c
uint64_t OH_Archive_BufferWriteCompressBound(OH_Archive_CompressMethod method, uint64_t sourceLen)
```

**Description**

Calculates the maximum size of the compressed data for a given source data length.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_CompressMethod](capi-oh-archive-h.md#oh_archive_compressmethod) method | Compression algorithm type. Currently, only **OH_ARCHIVE_COMPRESS_DEFLATE** is supported. |
| uint64_t sourceLen | Length of the source data to be compressed, in bytes. |

**Returns**

| Type | Description |
| -- | -- |
| uint64_t | Maximum size of the compressed data, in bytes. |

### OH_Archive_BufferWrite()

```c
OH_Archive_ErrCode OH_Archive_BufferWrite(uint8_t *dstBuffer, uint64_t *dstSize, const uint8_t *srcBuffer, uint64_t srcSize, OH_Archive_CompressMethod method, int32_t compressLevel)
```

**Description**

Writes data to the buffer and compresses the data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| uint8_t *dstBuffer | Pointer to the destination buffer, which is used to store the compressed data. |
| uint64_t *dstSize | Pointer to the size of the destination buffer. The input is the buffer size, and the output is the actual size of data written, in bytes. |
| const uint8_t *srcBuffer | Pointer to the source buffer that contains the data to be compressed. |
| uint64_t srcSize | Size of the source buffer, in bytes. |
| [OH_Archive_CompressMethod](capi-oh-archive-h.md#oh_archive_compressmethod) method | Compression algorithm type. Currently, only **OH_ARCHIVE_COMPRESS_DEFLATE** is supported. |
| int32_t compressLevel | Compression level. For **OH_ARCHIVE_COMPRESS_DEFLATE**, the compression level ranges from 0 to 9. The default level is **6**. The value **0** indicates no compression. The higher the compression level, the higher the compression rate, and the slower the speed. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_BufferRead()

```c
OH_Archive_ErrCode OH_Archive_BufferRead(uint8_t *dstBuffer, uint64_t *dstSize, const uint8_t *srcBuffer, uint64_t srcSize, OH_Archive_CompressMethod method)
```

**Description**

Reads data from the buffer and decompresses the data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| uint8_t *dstBuffer | Pointer to the destination buffer, which is used to store the decompressed data. |
| uint64_t *dstSize | Pointer to the size of the destination buffer. The input is the buffer size, and the output is the actual size of decompressed data, in bytes. |
| const uint8_t *srcBuffer | Pointer to the source buffer that contains the data to be decompressed. |
| uint64_t srcSize | Size of the source buffer, in bytes. |
| [OH_Archive_CompressMethod](capi-oh-archive-h.md#oh_archive_compressmethod) method | Decompression algorithm type. Currently, only **OH_ARCHIVE_COMPRESS_DEFLATE** is supported. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamWrite_Create()

```c
OH_Archive_StreamWrite_Ctx OH_Archive_StreamWrite_Create(OH_Archive_Stream_Config config)
```

**Description**

Creates a context struct for streaming compression.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Stream_Config](capi-archive-oh-archive-stream-config.md) config | Compression configuration. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_StreamWrite_Ctx](capi-archive-archivestreamwritectx.md) | Pointer to the context struct for streaming compression. If the creation fails, **NULL** is returned. |

### OH_Archive_StreamWrite_Start()

```c
OH_Archive_ErrCode OH_Archive_StreamWrite_Start(OH_Archive_StreamWrite_Ctx ctx, OH_Archive_Stream_OutputHandler outputHandler, void* userData)
```

**Description**

Starts a compression task and initializes the user callback function and user data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamWrite_Ctx](capi-archive-archivestreamwritectx.md) ctx | Pointer to the context struct for streaming compression. |
| [OH_Archive_Stream_OutputHandler](capi-oh-archive-h.md#oh_archive_stream_outputhandler) outputHandler | Pointer to the user-defined callback for compressed data. |
| void* userData | User-defined context, which is returned in the callback. **userData** is held by the caller and must be valid before [OH_Archive_StreamWrite_End](capi-oh-archive-h.md#oh_archive_streamwrite_end) is complete. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamWrite_SetCompressLevel()

```c
OH_Archive_ErrCode OH_Archive_StreamWrite_SetCompressLevel(OH_Archive_StreamWrite_Ctx ctx, int32_t compressLevel)
```

**Description**

Sets the compression level of streaming compression.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamWrite_Ctx](capi-archive-archivestreamwritectx.md) ctx | Pointer to the context struct for streaming compression. |
| int32_t compressLevel | Compression level. For **OH_ARCHIVE_COMPRESS_DEFLATE**, the compression level ranges from 0 to 9. The default level is **6**. The value **0** indicates no compression. The higher the compression level, the higher the compression rate, and the slower the speed. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamWrite_Cancel()

```c
OH_Archive_ErrCode OH_Archive_StreamWrite_Cancel(OH_Archive_StreamWrite_Ctx ctx)
```

**Description**

Forcibly cancels the current compression operation.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamWrite_Ctx](capi-archive-archivestreamwritectx.md) ctx | Pointer to the context struct for streaming compression. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the cancellation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamWrite_Update()

```c
OH_Archive_ErrCode OH_Archive_StreamWrite_Update(OH_Archive_StreamWrite_Ctx ctx, const uint8_t* data, uint64_t size)
```

**Description**

Submits the compressed data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamWrite_Ctx](capi-archive-archivestreamwritectx.md) ctx | Pointer to the context struct for streaming compression. |
| const uint8_t* data | Raw data to be compressed |
| uint64_t size | Size of the data to be compressed, in bytes. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the compression is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamWrite_End()

```c
OH_Archive_ErrCode OH_Archive_StreamWrite_End(OH_Archive_StreamWrite_Ctx ctx, OH_Archive_StreamInfo *streamInfo)
```

**Description**

Stops compression and refreshes all remaining data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamWrite_Ctx](capi-archive-archivestreamwritectx.md) ctx | Pointer to the context struct for streaming compression. |
| [OH_Archive_StreamInfo](capi-archive-oh-archive-streaminfo.md) *streamInfo | Pointer to the compression information, including the size of raw data, size of the compressed data, and CRC32 value. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the compression is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamWrite_Destroy()

```c
void OH_Archive_StreamWrite_Destroy(OH_Archive_StreamWrite_Ctx ctx)
```

**Description**

Destroys the compression instance and releases related resources.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamWrite_Ctx](capi-archive-archivestreamwritectx.md) ctx | Pointer to the context struct for streaming compression. |

### OH_Archive_StreamRead_Create()

```c
OH_Archive_StreamRead_Ctx OH_Archive_StreamRead_Create(OH_Archive_Stream_Config config)
```

**Description**

Creates a context struct for streaming decompression.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_Stream_Config](capi-archive-oh-archive-stream-config.md) config | Decompression configuration information. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_StreamRead_Ctx](capi-archive-archivestreamreadctx.md) | Pointer to the context struct for streaming decompression. If the creation fails, **NULL** is returned. |

### OH_Archive_StreamRead_Start()

```c
OH_Archive_ErrCode OH_Archive_StreamRead_Start(OH_Archive_StreamRead_Ctx ctx, OH_Archive_Stream_OutputHandler outputHandler, void* userData)
```

**Description**

Starts a decompression task and initializes the user callback function and user data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamRead_Ctx](capi-archive-archivestreamreadctx.md) ctx | Pointer to the context struct for streaming decompression. |
| [OH_Archive_Stream_OutputHandler](capi-oh-archive-h.md#oh_archive_stream_outputhandler) outputHandler | Pointer to the user-defined callback for decompressed data. |
| void* userData | User-defined context data, which is returned in the callback. **userData** is owned by the caller and must remain valid until [OH_Archive_StreamRead_End](capi-oh-archive-h.md#oh_archive_streamread_end) is complete. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamRead_Cancel()

```c
OH_Archive_ErrCode OH_Archive_StreamRead_Cancel(OH_Archive_StreamRead_Ctx ctx)
```

**Description**

Forcibly cancels the current decompression operation.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamRead_Ctx](capi-archive-archivestreamreadctx.md) ctx | Pointer to the context struct for streaming decompression. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the cancellation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamRead_Update()

```c
OH_Archive_ErrCode OH_Archive_StreamRead_Update(OH_Archive_StreamRead_Ctx ctx, const uint8_t* data, uint64_t size)
```

**Description**

Submits the decompressed data.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamRead_Ctx](capi-archive-archivestreamreadctx.md) ctx | Pointer to the context struct for streaming decompression. |
| const uint8_t* data | Data to be decompressed. |
| uint64_t size | Data size, in bytes. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamRead_End()

```c
OH_Archive_ErrCode OH_Archive_StreamRead_End(OH_Archive_StreamRead_Ctx ctx, OH_Archive_StreamInfo *streamInfo)
```

**Description**

Stops decompression, refreshes all remaining data, and clears the memory.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamRead_Ctx](capi-archive-archivestreamreadctx.md) ctx | Pointer to the context struct for streaming decompression. |
| [OH_Archive_StreamInfo](capi-archive-oh-archive-streaminfo.md) *streamInfo | Pointer to the decompression information, including the original data size, compressed data size, and CRC32 value. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_Archive_ErrCode](capi-oh-archive-errcode-h.md#oh_archive_errcode) | API execution result. If the operation is successful, **OH_ARCHIVE_OK** is returned. If the operation fails, an error code is returned. |

### OH_Archive_StreamRead_Destroy()

```c
void OH_Archive_StreamRead_Destroy(OH_Archive_StreamRead_Ctx ctx)
```

**Description**

Destroys the decompression instance and releases related resources.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_Archive_StreamRead_Ctx](capi-archive-archivestreamreadctx.md) ctx | Pointer to the context struct for streaming decompression. |