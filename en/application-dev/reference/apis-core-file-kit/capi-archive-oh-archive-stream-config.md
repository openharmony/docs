# OH_Archive_Stream_Config

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rl123567-->
<!--Designer: @selina_jiang; @RainbowLLL-->
<!--Tester: @zheng1368-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=bb49b7ed5e4e9e800a0691df554198c36528b3e0 translatedAt=2026-08-14T11:48:07.642Z pushedAt=2026-08-17T03:45:52.259Z -->

```c
typedef struct {...} OH_Archive_Stream_Config
```

## Overview

Defines a struct for streaming compression configuration.

**Since**: 26.0.0

**Related module:** [Archive](capi-archive.md)

**File to include:** [oh_archive.h](capi-oh-archive-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint32_t blockSize | Size of the memory block, in bytes. When [OH_Archive_CompressMethod](capi-oh-archive-h.md#oh_archive_compressmethod) is set to **OH_ARCHIVE_COMPRESS_DEFLATE**, the memory block size must be greater than or equal to 32,768 bytes.<br>**Since:** 26.0.0 |
| int32_t threadNum | Number of threads. The value must be a positive integer. If the value is greater than the number of device cores, the number of device cores is used.<br>**Since:** 26.0.0 |
| [OH_Archive_StreamChecksumAlg](capi-oh-archive-h.md#oh_archive_streamchecksumalg) checksum | Hash algorithm used to calculate the checksum.<br>**Since:** 26.0.0 |
| [OH_Archive_CompressMethod](capi-oh-archive-h.md#oh_archive_compressmethod) method | Compression algorithm. Only **OH_ARCHIVE_COMPRESS_DEFLATE** can be used for streaming compression and streaming decompression.<br>**Since:** 26.0.0 |