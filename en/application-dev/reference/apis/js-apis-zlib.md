# Zip

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Constraints

None
## Modules to Import

```javascript
import zlib from '@ohos.zlib';
```

## zlib.zipFile
zipFile(inFile:string, outFile:string, options: Options): Promise&lt;void&gt;

Zips a file. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory| Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | Yes  | Path of the folder or file to zip. For details about the path, see [FA Model](js-apis-Context.md) and [Stage Model](js-apis-application-context.md).|
| outFile | string              | Yes  | Path of the zipped file. The file name extension is .zip.                 |
| options | [Options](#options) | No  | Optional parameters for the zip operation.                                              |

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Returns [ERROR_CODE_OK](#ziperrorcode) if the operation is successful.<br>Returns [ERROR_CODE_ERRNO](#ziperrorcode) if the operation fails.|

**Example 1**

```javascript

// Zip a file.
import zlib from '@ohos.zlib'
var inFile = "/xxx/filename.xxx";
var outFile = "/xxx/xxx.zip";
var options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.zipFile(inFile, outFile, options).then((data) => {
    console.log("zipFile result: " + data);
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
var options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.zipFile(inFile , outFile, options).then((data) => {
    console.log("zipFile result: " + data);
}).catch((err)=>{
    console.log("catch((err)=>" + err);
});
```

## zlib.unzipFile

unzipFile(inFile:string, outFile:string, options: Options): Promise&lt;void&gt;

Unzips a file. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory| Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | Yes  | Path of the folder or file to zip. For details about the path, see [FA Model](js-apis-Context.md) and [Stage Model](js-apis-application-context.md).|
| outFile | string              | Yes  | Path of the unzipped file.                                          |
| options | [Options](#options) | No  | Optional parameters for the unzip operation.                                              |

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Returns [ERROR_CODE_OK](#ziperrorcode) if the operation is successful.<br>Returns [ERROR_CODE_ERRNO](#ziperrorcode) if the operation fails.|

**Example**

```javascript
// Unzip a file.
import zlib from '@ohos.zlib'
var inFile = "/xx/xxx.zip";
var outFile = "/xxx";

let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};
zlib.unzipFile(inFile, outFile, options).then((data) => {
    console.log("unzipFile result: " + data);
}).catch((err)=>{
    console.log("catch((err)=>" + err);
})
	
```

## Options

**System capability**: SystemCapability.BundleManager.Zlib

| Name  | Type            | Mandatory| Description                                                     |
| -------- | ---------------- | ---- | --------------------------------------------------------- |
| level    | CompressLeve     | No  | See [zip.CompressLevel](#zipcompresslevel).      |
| memLevel | MemLevel         | No  | See [zip.MemLevel](#zipmemlevel).                |
| strategy | CompressStrategy | No  | See [zip.CompressStrategy](#zipcompressstrategy).|

## zip.MemLevel

**System capability**: SystemCapability.BundleManager.Zlib

| Name             | Value  | Description                            |
| ----------------- | ---- | -------------------------------- |
| MEM_LEVEL_MIN     | 1    | Minimum memory used by the **zip** API during compression.|
| MEM_LEVEL_MAX     | 9    | Maximum memory used by the **zip** API during compression.|
| MEM_LEVEL_DEFAULT | 8    | Default memory used by the **zip** API during compression.|

## zip.CompressLevel

**System capability**: SystemCapability.BundleManager.Zlib

| Name                              | Value  | Description             |
| ---------------------------------- | ---- | ----------------- |
| COMPRESS_LEVEL_NO_COMPRESSION      | 0    | Compress level 0 that indicates uncompressed.|
| COMPRESS_LEVEL_BEST_SPEED          | 1    | Compression level 1 that gives the best speed. |
| COMPRESS_LEVEL_BEST_COMPRESSION    | 9    | Compression level 9 that gives the best compression.     |
| COMPRESS_LEVEL_DEFAULT_COMPRESSION | -1   | Default compression level.     |

## zip.CompressStrategy

**System capability**: SystemCapability.BundleManager.Zlib

| Name                              | Value  | Description                    |
| ---------------------------------- | ---- | ------------------------ |
| COMPRESS_STRATEGY_DEFAULT_STRATEGY | 0    | Default compression strategy.            |
| COMPRESS_STRATEGY_FILTERED         | 1    | Filtered compression strategy.|
| COMPRESS_STRATEGY_HUFFMAN_ONLY     | 2    | Huffman coding compression strategy.  |
| COMPRESS_STRATEGY_RLE              | 3    | RLE compression strategy.        |
| COMPRESS_STRATEGY_FIXED            | 4    | Fixed compression strategy.          |

## zip.ErrorCode

**System capability**: SystemCapability.BundleManager.Zlib

| Name            | Value  | Description        |
| ---------------- | ---- | ------------ |
| ERROR_CODE_OK    | 0    | The API is successfully called.|
| ERROR_CODE_ERRNO | -1   | Failed to call the API.|
