# zlib Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

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

The input source file is not in ZIP format or is damaged.

**Description**

This error code is reported when the format of the source file is incorrect or the source file is damaged when the **decompressFile** API is called.


**Possible Causes**

1. When the **decompressFile** API is called, the format of the source file is incorrect.
2. When the **decompressFile** API is called, the source file is incomplete or damaged.

**Solution**

1. Check whether the source file is in ZIP format.
2. Check whether the source file is complete. If the file is downloaded from the network, ensure that the file download is complete before calling the **decompressFile** API.

## 17800002 Incorrect File or Access Mode

**Error Message**

No such file or access mode error.

**Description**

This error code is reported when the input file path, file descriptor, or file access mode is incorrect when the **gzopen** or **gzdopen** API is called.

**Possible Causes**

1. When the **gzopen** API is called, the input file path or file access mode is incorrect.
2. When the **gzdopen** API is called, the input file descriptor or file access mode is incorrect.

**Solution**

1. Check whether the .gz file path or file descriptor is correct. If a .gz file is created, ensure that the file access is in compression mode (such as **w** or **wb**).
2. Check whether the file access mode is **w**, **wb**, **r**, **rb**, **a**, and **ab**.

## 17800004 Compressed or Decompressed Flow Error

**Error Message**

Compression or decompression stream error, which may be caused by an initialization error in the zlib stream structure or a modified structure.

**Description**

This error code is reported when an error occurs in compression or decompression stream when the **deflate** or **inflate** API is called.

**Possible Causes**

1. When the **deflate** or **inflate** API is called, the **deflateInit** or **inflateInit** API is not used to initialize the compression or decompression stream.
2. When the **gzsetparams**, **gzclose**, or **gzflush** API is called, the input refresh mode is incorrect. When the API for opening a .gz file is called, the input file access mode is incorrect.

**Solution**

1. Before calling the **deflate** or **inflate** API, use the **deflateInit** or **inflateInit** API to initialize the compression or decompression stream.
2. Check whether the API for opening the .gz file is not called or fails to be called.
3. Check whether the input access mode matches the API when the API for opening the .gz file is called. For example, **gzprintf** is a compression API. When the API for opening a .gz file is called, the input access mode must be the compression mode (such as **w** or **wb**).
4. Check whether the input enum parameter is correct.

## 17800005 Incorrect Input Data

**Error Message**

The input data is incorrect. For example, the data does not conform to the zlib compression format, the compressed data is corrupted, or the data is not compressed.

**Description**

This error code is reported when the input data is incorrect when the **uncompress** or **uncompress2** API is called.

**Possible Causes**

When the **uncompress** or **uncompress2** API is called, the **compress** API is not used for compression.

**Solution**

Use the **compress** API to compress the file before using the **uncompress2** or **uncompress** API to decompress the file.

## 17800006 Memory Allocation Failure

**Error Message**

Memory allocation failed.

**Description**

This error code is reported when the memory allocation fails when the **gzclose** or **gzclosew** API is called.

**Possible Causes**

The **gzsetparams** API is called before calling the **gzclose** or **gzclosew** API. As a result, an incorrect compression level or compression strategy is passed in.

**Solution**

Check the whether the **gzsetparams** API is called and pass in the correct compression level and compression strategy.

## 17800007 Incorrect Input Buffer

**Error Message**

The input buffer is incorrect, and the output buffer is too small to accommodate the compressed or decompressed data.

**Description**

This error code is reported when the input buffer is incorrect when the **compress**, **compress2**, **uncompress**, or **uncompress2** API is called.

**Possible Causes**

1. When the **uncompress** or **uncompress2** API is called, the input buffer size is greater than the output buffer size after decompression.
2. When the **compress** or **compress2** API is called, the input buffer size is greater than the output buffer size after compression.
3. When the **compress**, **compress2**, **uncompress**, or **uncompress2** API is called, the input buffer size is 0.

**Solution**

Increase the size of the corresponding buffer.

## 17800009 Internal Structure Error

**Error Message**

Internal structure error.

**Description**

This error code is reported when the input parameter is incorrect when the **gzputc**, **gzwrite**, or **gzread** API is called, or when the input file access mode is incorrect when the API for opening the .gz file is called.

**Possible Causes**

1. The API for opening the .gz file is not called or fails to be called.
2. When the API for opening the .gz file is called, the input file access mode is incorrect.
3. When the **gzwrite** API is called, the length of the input uncompressed byte is 0.
4. When the **gzfwrite** or **gzfread** API is called, the size or number of input data blocks is 0.
5. When the **gzprintf** API is called, the input format descriptor and plain text are empty strings.
6. When the **gzgets** API is called, the input **ArrayBuffer** is empty.
7. When the **gzgetc** API is called, the .gz file is empty.

**Solution**

1. Check whether the API for opening the .gz file is not called or fails to be called.
2. Check whether the input access mode matches the API when the API for opening the .gz file is called. For example, **gzgetc** is a decompression API, so the input access mode should be decompression mode (such **r** or **rb**).
3. Check whether the input parameter is correct.
