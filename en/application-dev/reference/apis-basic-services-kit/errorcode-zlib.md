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

The input source file is not ZIP format or damaged.

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

When the gzopen or gzdopen API is called, the input file path, file descriptor, or file access mode is incorrect.

**Possible Causes**

1. When the gzopen API is called, the input file path or file access mode is incorrect.
2. When the gzdopen API is called, the input file descriptor or file access mode is incorrect.

**Solution**

1. Check whether the GZ file path or file descriptor is correct. If a GZ file is created, ensure that the file access mode is compression mode (such as w or wb).
2. Check whether the file access mode is "w", "wb", "r", "rb", "a" or ab.

## 17800004 Compressed or Decompressed Stream Error

**Error Message**

ZStream error.

**Description**

When an API such as deflate or inflate is called, an error occurs in compressing or decompressing streams.

**Possible Causes**

1. When the deflate or inflate API is called, the deflateInit or inflateInit API is not used to initialize the compression or decompression stream.
2. When the gzsetparams, gzclose, or gzflush API is called, the input refresh mode is incorrect, or the input file access mode is incorrect when the API for opening the GZ file is called before the API is called.

**Solution**

1. Before calling APIs such as deflate or inflate, use the deflateInit or inflateInit API to initialize the compression or decompression stream.
2. Check whether the related API for opening the .gz file is not called or fails to be called before the API is called.
3. Check whether the access mode transferred when the API for opening the .gz file is called matches the API before the API is called. For example, gzprintf is a compression API. When the API for opening a GZ file is called, the input access mode must be the compression mode (such as w or wb).
4. Check whether the input enumeration parameter is correct.

## 17800005 Incorrect Input Data

**Error Message**

Data error.

**Description**

When the uncompress or uncompress2 API is called, the input data is incorrect.

**Possible Causes**

When the uncompress or uncompress2 API is called, the compress API is not used for compression.

**Solution**

Run the compress command to compress the file and then run the uncompress2 or uncompress command to decompress the file.

## 17800006 Memory Allocation Failure

**Error Message**

Memory allocation failed.

**Description**

When the gzclose or gzclosew API is called, memory allocation fails.

**Possible Causes**

Before the gzclose or gzclosew API is called, the gzsetparams API is called and an incorrect compression level or compression policy is transferred.

**Solution**

Check the invoking of the gzsetparams API and transfer the correct compression level and compression policy.

## 17800007 Incorrect Input Buffer

**Error Message**

Buffer error.

**Description**

When the compress, compress2, uncompress, or uncompress2 API is called, the input buffer is incorrect.

**Possible Causes**

1. When the uncompress or uncompress2 API is called, the input buffer size is greater than the output buffer size after decompression.
2. When the compress or compress2 API is called, the input buffer size is greater than the output buffer size after compression.
3. When the compress, compress2, uncompress, or uncompress2 API is called, the input buffer size is 0.

**Solution**

Increase the size of the corresponding buffer.

## 17800009 Internal Structure Error

**Error Message**

Internal structure error.

**Description**

When the gzputc, gzwrite, or gzread API is called, the input parameter is incorrect, or the input file access mode is incorrect when the API for opening the GZ file is called before the API is called.

**Possible Causes**

1. Before an API is called, the API for opening the GZ file is not called or fails to be called.
2. Before the API is called, the input file access mode is incorrect when the API for opening the GZ file is called.
3. When the gzwrite API is called, the length of the input uncompressed byte is 0.
4. When the gzfwrite or gzfread API is called, the size or number of input data blocks is 0.
5. When the gzprintf API is called, the input formatting descriptor and plain text are null characters.
6. When the gzgets API is called, an empty ArrayBuffer is transferred.
7. When the gzgetc API is called, the gz file is empty.

**Solution**

1. Check whether the related API for opening the .gz file is not called or fails to be called before the API is called.
2. Check whether the access mode transferred when the API for opening the .gz file is called matches the API before the API is called. For example, gzgetc is a decompression API. When the API for opening a GZ file is called, the input access mode must be decompression mode (r or rb).
3. Check whether the input parameter is correct.
