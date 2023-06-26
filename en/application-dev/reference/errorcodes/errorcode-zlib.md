# zlib Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 900001 Invalid Source File

**Error Message**

The input source file is invalid.

**Description**

This error code is reported when the source file passed in the **compressFile()** or **decompressFile()** API is invalid.

**Possible Causes**

When the **compressFile()** API is called, the file to compress does not exist. When the **decompressFile()** API is called, the file to decompress does not exist.

**Solution**

1. Make sure the source file exists.
2. Ensure that the source file is in ZIP format.
3. Make sure the path of the source file exists and the path is the correct sandbox path.

## 900002 Invalid Destination File

**Error Message**

The input destination file is invalid.

**Description**

This error code is reported when the destination file passed in the **compressFile()** or **decompressFile()** API is invalid.

**Possible Causes**

1. When the **compressFile()** API is called, the passed destination file path is invalid, for example, a non-exist sandbox path.
2. When the **decompressFile()** API is called, the destination folder does not exist.

**Solution**

1. Check whether the destination file path is correct. If not, enter the correct sandbox path.
2. Check whether the destination folder exists. If not, create the folder.

## 900003 Source File in Incorrect Format or Damaged

**Error Message**

The input source file is not ZIP format or damaged.

**Description**

This error code is reported when the format of the source file is incorrect or the source file is damaged when the **decompressFile** API is called.


**Possible Causes**

1. When the **decompressFile** API is called, the format of the source file is incorrect.
2. When the **decompressFile** API is called, the source file is incomplete or damaged.

**Solution**

1. Check whether the source file is in ZIP format.
2. Check whether the source file is complete. If the file is downloaded from the network, ensure that the file download is complete before calling the **decompressFile** API.
