# OH_Archive_StreamInfo

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rl123567-->
<!--Designer: @selina_jiang; @RainbowLLL-->
<!--Tester: @zheng1368-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=bb49b7ed5e4e9e800a0691df554198c36528b3e0 translatedAt=2026-08-14T11:48:27.141Z pushedAt=2026-08-17T03:45:57.705Z -->

```c
typedef struct {...} OH_Archive_StreamInfo
```

## Overview

Defines a struct for compression and decompression of streaming information.

**Since**: 26.0.0

**Related module:** [Archive](capi-archive.md)

**File to include:** [oh_archive.h](capi-oh-archive-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint64_t totalInSize | Size of the input data before compression/decompression, in bytes.<br>**Since:** 26.0.0 |
| uint64_t totalOutSize | Size of the output data after compression/decompression, in bytes.<br>**Since:** 26.0.0 |
| uint32_t checksum | Checksum of the uncompressed data. When [OH_Archive_StreamChecksumAlg](capi-oh-archive-h.md#oh_archive_streamchecksumalg) is set to **OH_ARCHIVE_NO_CHECKSUM**, the checksum is 0.<br>**Since:** 26.0.0 |