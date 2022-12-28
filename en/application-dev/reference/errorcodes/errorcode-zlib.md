# zlib Error Codes

## 900001 Invalid Source File

**Error Message**

The input source file is invalid.

**Description**

This error code is reported when the source file passed in the **compress** or **decompress** API is invalid.

**Possible Causes**

When the **compress** API is called, the file to compress does not exist. When the **decompress** API is called, the file to decompress does not exist.

**Solution**

1. Make sure the source file exists.
2. Make sure the path of the source file exists and the path is the correct sandbox path.

## 900002 Invalid Destination File

**Error Message**

The input destination file is invalid.

**Description**

This error code is reported when the destination file passed in the **compress** or **decompress** API is invalid.

**Possible Causes**

1. When the **compress** API is called, the passed destination file path is invalid, for example, a non-exist sandbox path.
2. When the **decompress** API is called, the destination folder does not exist.

**Solution**

1. Check whether the destination file path is correct. If not, enter the correct sandbox path.
2. Check whether the destination folder exists. If not, create the folder.
