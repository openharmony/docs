# Zip

## Constraints
None
## Modules to Import

```javascript
import zlib from '@ohos.zlib';
```

## zlib.zipFile
zipFile(inFile:string, outFile:string, options: Options): Promise\<void>
Zips a file. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type                               | Mandatory| Description                                       |
| ------- | ----------------------------------- | ---- | ------------------------------------------- |
| inFile  | string                              | Yes  | Path of the folder or file to zip.           |
| outFile | string                              | Yes  | Path of the zipped file. The file name extension is .zip.|
| options | [Options](#options)| No  | Optional parameters for the zip operation.                             |

**Return value**

| Type          | Description                                                |
| -------------- | ---------------------------------------------------- |
| Promise\<void> | Returns **ERROR_CODE_OK** if the operation is successful; returns **ERROR_CODE_ERRNO** otherwise.|

**Example 1**

```javascript

// Zip a file.
import zlib from '@ohos.zlib'
var inFile = "/xxx/filename.xxx";
var outFile = "/xxx/xxx.zip";
var options = {};
options.level = zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION;
options.memLevel = zlib.MemLevel.MEM_LEVEL_DEFAULT;
options.strategy = zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY;

zlib.zipFile(inFile, outFile, options).then((data) => {
    if (data == zlib.ErrorCode.ERROR_CODE_OK) {
        console.log("zipFile OK");
    } else {
        console.log("zipFile NG");
    }
}).catch((err)=>{
    console.log("catch((err)=>" + err);
});

```

**Example 2**

```
// Zip a folder.
import zlib from '@ohos.zlib'
var inFile = "/xxx/xxx";
var outFile = "/xxx/xxx.zip";
var options = {};
options.level = zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION;
options.memLevel = zlib.MemLevel.MEM_LEVEL_DEFAULT;
options.strategy = zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY;

zlib.zipFile(inFile , unzipDir, options).then((data) => {
    if (data == zlib.ErrorCode.ERROR_CODE_OK) {
        console.log("zipFile OK");
    } else {
        console.log("zipFile NG");
    }
}).catch((err)=>{
    console.log("catch((err)=>" + err);
});
```

## zlib.unzipFile

unzipFile(inFile:string, outFile:string, options: Options): Promise\<void>

Unzips a file. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type                               | Mandatory| Description                               |
| ------- | ----------------------------------- | ---- | ----------------------------------- |
| inFile  | string                              | Yes  | Path of the file to unzip. The file name extension is .zip.|
| outFile | string                              | Yes  | Path of the unzipped file.                 |
| options | [Options](#options)| No  | Optional parameters for the unzip operation.                     |

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Returns **ERROR_CODE_OK** if the operation is successful; returns **ERROR_CODE_ERRNO** otherwise.|

**Example**

```javascript
// Unzip a file.
import zlib from '@ohos.zlib'
var inFile = "/xx/xxx.zip";
var outFile = "/xxx";

var options = {};
options.level = zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION;
options.memLevel = zlib.MemLevel.MEM_LEVEL_DEFAULT;
options.strategy = zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY;

zlib.unzipFile(inFile, outFile, options).then((data) => {
    if (data == zlib.ErrorCode.ERROR_CODE_OK) {
        console.log("unzipFile OK");
    } else {
        console.log("unzipFile NG");
    }
}).catch((err)=>{
    console.log("catch((err)=>" + err);
})
	
```

## options

| Name                       | Description                                                        |
| --------------------------- | ------------------------------------------------------------ |
| level?: CompressLeve        | See [zip.CompressLevel](#zipcompresslevel). |
| memLevel?: MemLevel         | See [zip.MemLevel](#zipmemlevel)     |
| strategy?: CompressStrategy | See [zip.CompressStrategy](#zipcompressstrategy) |

## zip.MemLevel

| Name                       | Description                                                        |
| ----------------- | -------------------------------- |
| MEM_LEVEL_MIN     | Minimum memory used by the **zip** API during compression.|
| MEM_LEVEL_MAX     | Maximum memory used by the **zip** API during compression.|
| MEM_LEVEL_DEFAULT | Default memory used by the **zip** API during compression.|

## Zip.CompressLevel

| Name                                   | Description             |
| --------------------------------------- | ----------------- |
| COMPRESS_LEVEL_NO_COMPRESSION : 0       | Compress level 0 that indicates uncompressed.|
| COMPRESS_LEVEL_BEST_SPEED : 1           | Compression level 1 that gives the best speed. |
| COMPRESS_LEVEL_BEST_COMPRESSION :9      | Compression level 9 that gives the best compression.     |
| COMPRESS_LEVEL_DEFAULT_COMPRESSION : -1| Default compression level.     |

## Zip.CompressStrategy

| Name                                  | Description                    |
| -------------------------------------- | ------------------------ |
| COMPRESS_STRATEGY_DEFAULT_STRATEGY : 0 | Default compression strategy.            |
| COMPRESS_STRATEGY_FILTERED : 1         | Filtered compression strategy.|
| COMPRESS_STRATEGY_HUFFMAN_ONLY : 2     | Huffman coding compression strategy.  |
| COMPRESS_STRATEGY_RLE : 3              | RLE compression strategy.        |
| COMPRESS_STRATEGY_FIXED : 4            | Fixed compression strategy.          |

## zip.ErrorCode

| Name                | Description        |
| -------------------- | ------------ |
| ERROR_CODE_OK: 0     | The API is successfully called.|
| ERROR_CODE_ERRNO:- 1 | Failed to call the API.|
