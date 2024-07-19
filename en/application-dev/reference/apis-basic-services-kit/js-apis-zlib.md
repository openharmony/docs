# @ohos.zlib (Zip)

The **Zip** module provides APIs for file compression and decompression.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```javascript
import { zlib } from '@kit.BasicServicesKit';
```

## zlib.zipFile<sup>(deprecated)</sup>
zipFile(inFile: string, outFile: string, options: Options): Promise&lt;void&gt;

Zips a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [zlib.compressFile](#zlibcompressfile9) instead.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory | Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | Yes  | Path of the folder or file to zip. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). |
| outFile | string              | Yes  | Path of the zipped file. The file name extension is .zip.                 |
| options | [Options](#options) | Yes  | Optional parameters for the zip operation.                                            |

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/haps. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xxx/filename.xxx';
let outFile = '/xxx/xxx.zip';
let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.zipFile(inFile, outFile, options).then((data: void) => {
  console.info('zipFile result is ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('error is ' + JSON.stringify(err));
});
```

## zlib.unzipFile<sup>(deprecated)</sup>

unzipFile(inFile:string, outFile:string, options: Options): Promise&lt;void&gt;

Unzips a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [zlib.decompressFile](#zlibdecompressfile9) instead.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory | Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | Yes  | Path of the file to unzip. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). |
| outFile | string              | Yes  | Path of the unzipped file.                                        |
| options | [Options](#options) | Yes  | Optional parameters for the unzip operation.                                            |

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/haps. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xx/xxx.zip';
let outFile = '/xxx';
let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.unzipFile(inFile, outFile, options).then((data: void) => {
  console.info('unzipFile result is ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('error is ' + JSON.stringify(err));
})
```

## zlib.compressFile<sup>9+</sup>

compressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void

Compresses a file. This API uses an asynchronous callback to return the result.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name                 | Type               | Mandatory | Description                                                        |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | Yes  | Path of the folder or file to compress. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). The folder to compress cannot be empty. Otherwise, an error will be reported when [decompressFile](#zlibdecompressfile9) is used to decompress the folder. |
| outFile                 | string              | Yes  | Path of the compressed file. When multiple threads compress files at the same time, the values of **outFile** must be different.                                          |
| options                 | [Options](#options) | Yes  | Compression parameters.                                              |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **null** is returned; otherwise, a specific error code is returned.            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/haps. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xxx/filename.xxx';
let outFile = '/xxx/xxx.zip';
let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

try {
  zlib.compressFile(inFile, outFile, options, (errData: BusinessError) => {
    if (errData !== null) {
      console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    }
  })
} catch (errData) {
  let code = (errData as BusinessError).code;
  let message = (errData as BusinessError).message;
  console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.compressFile<sup>9+</sup>

compressFile(inFile: string, outFile: string, options: Options): Promise\<void>

Compresses a file. This API uses a promise to return the result.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory | Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | Yes  | Path of the folder or file to compress. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). The folder to compress cannot be empty. Otherwise, an error will be reported when [decompressFile](#zlibdecompressfile9) is used to decompress the folder. |
| outFile | string              | Yes  | Path of the compressed file. When multiple threads compress files at the same time, the values of **outFile** must be different.                                          |
| options | [Options](#options) | Yes  | Compression parameters.                                              |

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                              |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/haps. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xxx/filename.xxx';
let outFile = '/xxx/xxx.zip';
let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

try {
  zlib.compressFile(inFile, outFile, options).then((data: void) => {
    console.info('compressFile success. data: ' + JSON.stringify(data));
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
} catch (errData) {
  let code = (errData as BusinessError).code;
  let message = (errData as BusinessError).message;
  console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.decompressFile<sup>9+</sup>

decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void

Decompresses a file. This API uses an asynchronous callback to return the result.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name                 | Type               | Mandatory | Description                                                        |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | Yes  | Path of the file to decompress. The file name extension must be .zip. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). |
| outFile                 | string              | Yes  | Path of the decompressed file. The path must exist in the system. Otherwise, the decompression fails. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). If a file or folder with the same name already exists in the path, they will be overwritten. When multiple threads decompress files at the same time, the values of **outFile** must be different. |
| options                 | [Options](#options) | Yes  | Decompression parameters.                                            |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **null** is returned; otherwise, a specific error code is returned.                                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |
| 900003 | The input source file is not ZIP format or damaged. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/haps. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xx/xxx.zip';
let outFileDir = '/xxx';
let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION
};

try {
  zlib.decompressFile(inFile, outFileDir, options, (errData: BusinessError) => {
    if (errData !== null) {
      console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    }
  })
} catch (errData) {
  let code = (errData as BusinessError).code;
  let message = (errData as BusinessError).message;
  console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.decompressFile<sup>9+</sup>

decompressFile(inFile: string, outFile: string, options?: Options): Promise\<void>

Decompresses a file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory | Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | Yes  | Path of the file to decompress. The file name extension must be .zip. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). |
| outFile | string              | Yes  | Path of the decompressed file. The path must exist in the system. Otherwise, the decompression fails. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). If a file or folder with the same name already exists in the path, they will be overwritten. When multiple threads decompress files at the same time, the values of **outFile** must be different. |
| options | [Options](#options) | No  | Decompression parameters.                                          |

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                              |
| ------ | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001 | The input source file is invalid.      |
| 900002 | The input destination file is invalid. |
| 900003 | The input source file is not ZIP format or damaged. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/haps. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xx/xxx.zip';
let outFileDir = '/xxx';
let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION
};

try {
  zlib.decompressFile(inFile, outFileDir, options).then((data: void) => {
    console.info('decompressFile success. data: ' + JSON.stringify(data));
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
} catch (errData) {
  let code = (errData as BusinessError).code;
  let message = (errData as BusinessError).message;
  console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.decompressFile<sup>10+</sup>

decompressFile(inFile: string, outFile: string, callback: AsyncCallback\<void\>): void

Decompresses a file. This API uses an asynchronous callback to return the result.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name                 | Type               | Mandatory | Description                                                        |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | Yes  | Path of the file to decompress. The file name extension must be .zip. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). |
| outFile                 | string              | Yes  | Path of the decompressed file. The path must exist in the system. Otherwise, the decompression fails. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). If a file or folder with the same name already exists in the path, they will be overwritten. When multiple threads decompress files at the same time, the values of **outFile** must be different. |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **null** is returned; otherwise, a specific error code is returned.                                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |
| 900003 | The input source file is not ZIP format or damaged. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/haps. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xx/xxx.zip';
let outFileDir = '/xxx';

try {
  zlib.decompressFile(inFile, outFileDir, (errData: BusinessError) => {
    if (errData !== null) {
      console.error(`decompressFile failed. code is ${errData.code}, message is ${errData.message}`);
    }
  })
} catch (errData) {
  let code = (errData as BusinessError).code;
  let message = (errData as BusinessError).message;
  console.error(`decompressFile failed. code is ${code}, message is ${message}`);
}
```

## zlib.getOriginalSize<sup>12+</sup>

getOriginalSize(compressedFile: string): Promise\<number>

Obtains the original size of a compressed file and uses a promise to asynchronously return the result. The original size of the compressed file is returned upon a success. Otherwise, an error code is returned.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory | Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| compressedFile  | string              | Yes  | Specifies the path of the compressed file. Only .zip files are supported. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). |

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<number> | Promise object, which returns the original size of the compressed file, in bytes. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                              |
| ------ | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 900001 | The input source file is invalid.      |
| 900003 | The input source file is not ZIP format or damaged. |

**Example**

```ts
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/temp. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let compressedFile = '/data/storage/el2/base/temp/test.zip';

try {
  zlib.getOriginalSize(compressedFile).then((data: number) => {
    console.info(`getOriginalSize success. getOriginalSize: ${data}`);
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
} catch (errData) {
  let code = (errData as BusinessError).code;
  let message = (errData as BusinessError).message;
  console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.compressFiles<sup>12+</sup>

compressFiles(inFiles: Array&lt;string&gt;, outFile: string, options: Options): Promise&lt;void&gt;

Compresses multiple specified files and uses a promise to asynchronously return the result.  

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type               | Mandatory | Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFiles | Array&lt;string&gt; | Yes  | Path of the folder or file to compress. The path must be an application sandbox path, which can be obtained from the context. For details about the context, see [FA Model](../apis-ability-kit/js-apis-inner-app-context.md) and [Stage Model](../apis-ability-kit/js-apis-inner-application-context.md). The folder to compress cannot be empty. Otherwise, an error will be reported when [decompressFile](#zlibdecompressfile9) is used to decompress the folder. |
| outFile | string              | Yes  | Path of the compressed file. When multiple threads compress files at the same time, the values of **outFile** must be different. |
| options | [Options](#options) | Yes  | Compression parameters.                                            |

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 900001   | The input source file is invalid.                            |
| 900002   | The input destination file is invalid.                       |

**Example**

```typescript
// The path used in the code must be an application sandbox path, for example, /data/storage/el2/base/temp. You can obtain the path through the context.
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let inFile = '/xxx/filename.xxx';
let pathDir = '';
let outFile = '/xxx/xxx.zip';
let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

try {
  zlib.compressFiles([inFile, pathDir, pathDir], outFile, options).then((data: void) => {
    console.info('compressFiles success. data: ' + JSON.stringify(data));
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
} catch (errData) {
  let code = (errData as BusinessError).code;
  let message = (errData as BusinessError).message;
  console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.createChecksum<sup>12+</sup>

createChecksum(): Promise&lt;Checksum&gt;

Creates a checksum object and uses a promise to asynchronously return the result. A checksum object instance is returned upon a success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                                  | Description                           |
| -------------------------------------- | ------------------------------- |
| Promise&lt;[Checksum](#checksum12)&gt; | Promise used to return the result.   |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

zlib.createChecksum().then((data) => {
  console.info('createChecksum success');
})
```

## zlib.createChecksumSync<sup>12+</sup>

createChecksumSync():  Checksum

Creates a checksum object. A checksum object instance is returned upon a success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                   | Description          |
| ----------------------- | -------------- |
| [Checksum](#checksum12) | Checksum object instance. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

let checksum = zlib.createChecksumSync()
```

## Checksum<sup>12+</sup>

Checksum object.

### adler32<sup>12+</sup>

adler32(adler: number, buf: ArrayBuffer): Promise&lt;number&gt;

Calculates the Adler-32 checksum and uses a promise to asynchronously return the result. The calculated Adler-32 checksum is returned upon a success. Otherwise, an error code is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type       | Mandatory | Description                    |
| ------ | ----------- | ---- | ------------------------ |
| adler  | number      | Yes  | Initial value of the Adler-32 checksum. |
| buf    | ArrayBuffer | Yes  | Data buffer for calculating the checksum.  |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(12);
let data = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  data[i] = str.charCodeAt(i);
}

let checksum = zlib.createChecksumSync()

checksum.adler32(0, arrayBufferIn).then(data => {
  console.info('adler32 success', data);
})
```

### adler32Combine<sup>12+</sup>

adler32Combine(adler1: number, adler2: number, len2: number): Promise&lt;number&gt;

Combines two Adler-32 checksums and uses a promise to asynchronously return the result. The combined Adler-32 checksum is returned upon a success. Otherwise, an error code is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type  | Mandatory | Description                                |
| ------ | ------ | ---- | ------------------------------------ |
| adler1 | number | Yes  | The first Adler-32 checksum to be combined.      |
| adler2 | number | Yes  | The second Adler-32 checksum to be combined.      |
| len2   | number | Yes  | Length of the data block of the second Adler-32 checksum. |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(12);
  let data = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    data[i] = str.charCodeAt(i);
  }
  let checksum = zlib.createChecksumSync()
  let adler1 = 0;
  let adler2 = 1;
  await checksum.adler32(0, arrayBufferIn).then(data => {
    console.info('adler32 success', data);
    adler1 = data;
  })
  await checksum.adler32(1, arrayBufferIn).then(data => {
    console.info('adler32 success', data);
    adler2 = data;
  })
  await checksum.adler32Combine(adler1, adler2, 12).then((data) => {
    console.info('adler32Combine success', data);
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### crc32<sup>12+</sup>

crc32(crc: number, buf: ArrayBuffer): Promise&lt;number&gt;

Updates the CRC-32 checksum and uses a promise to asynchronously return the result. The updated CRC-32 checksum is returned upon a success. Otherwise, an error code is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type       | Mandatory | Description                |
| ------ | ----------- | ---- | -------------------- |
| crc    | number      | Yes  | Initial value of the CRC-32 checksum. |
| buf    | ArrayBuffer | Yes  | Data buffer for calculating the checksum. |

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(12);
let data = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  data[i] = str.charCodeAt(i);
}

let checksum = zlib.createChecksumSync()

checksum.crc32(0, arrayBufferIn).then((data) => {
  console.info('crc32 success', data);
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### crc32Combine<sup>12+</sup>

crc32Combine(crc1: number, crc2: number, len2: number): Promise&lt;number&gt;

Combines two CRC-32 checksums and uses a promise to asynchronously return the result. The combined CRC-32 checksum is returned upon a success. Otherwise, an error code is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type  | Mandatory | Description                            |
| ------ | ------ | ---- | -------------------------------- |
| crc1 | number | Yes  | The first CRC-32 checksum to be combined.      |
| crc2 | number | Yes  | The second CRC-32 checksum to be combined.      |
| len2   | number | Yes  | Indicates the length of the second data block checked by CRC-32 |

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(12);
  let data = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    data[i] = str.charCodeAt(i);
  }
  let checksum = zlib.createChecksumSync()
  let crc1 = 0;
  let crc2 = 1;
  await checksum.crc32(0, arrayBufferIn).then(data => {
    console.info('crc32 success', data);
    crc1 = data;
  })
  await checksum.crc32(1, arrayBufferIn).then(data => {
    console.info('crc32 success', data);
    crc2 = data;
  })
  await checksum.crc32Combine(crc1, crc2, 12).then((data) => {
    console.info('crc32Combine success', data);
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### crc64<sup>12+</sup>

crc64(crc: number, buf: ArrayBuffer): Promise&lt;number&gt;

Updates the CRC-64 checksum and uses a promise to asynchronously return the result. The updated CRC-64 checksum is returned upon a success. Otherwise, an error code is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type       | Mandatory | Description                |
| ------ | ----------- | ---- | -------------------- |
| crc    | number      | Yes  | Initial value of the CRC-64 checksum. |
| buf    | ArrayBuffer | Yes  | Data buffer for calculating the checksum. |

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                              |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(12);
let data = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  data[i] = str.charCodeAt(i);
}

let checksum = zlib.createChecksumSync()

checksum.crc64(0, arrayBufferIn).then((data) => {
  console.info('crc64 success', data);
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### getCrcTable<sup>12+</sup>

getCrcTable(): Promise&lt;Array&lt;number&gt;&gt;

Outputs the CRC-32 checksum table and uses a promise to asynchronously return the result. The CRC-32 check table is returned upon a success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                              | Description                           |
| ---------------------------------- | ------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the result.   |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let checksum = zlib.createChecksumSync()

checksum.getCrcTable().then((data) => {
  console.info('getCrcTable success');
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### getCrc64Table<sup>12+</sup>

getCrc64Table(): Promise&lt;Array&lt;number&gt;&gt;

Outputs the CRC-64 checksum table and uses a promise to asynchronously return the result. The CRC-64 check table is returned upon a success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                              | Description                           |
| ---------------------------------- | ------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the result.   |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let checksum = zlib.createChecksumSync()

checksum.getCrc64Table().then((data) => {
  console.info('getCrc64Table success');
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

## zlib.createZip<sup>12+</sup>

createZip(): Promise&lt;Zip&gt;

Creates an instance of a compressed or decompressed object and uses a promise to asynchronously return the result. The instance of the compressed or decompressed object is returned upon a success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                        | Description                                 |
| ---------------------------- | ------------------------------------- |
| Promise&lt;[Zip](#zip12)&gt; | Promise used to return the result.   |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let zip = zlib.createZipSync();

zlib.createZip().then(data => {
  console.info('createZip success');
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

## zlib.createZipSync<sup>12+</sup>

createZipSync(): Zip

Creates an instance of a compressed or decompressed object. The instance of the compressed or decompressed object is returned upon a success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type         | Description                    |
| ------------- | ------------------------ |
| [Zip](#zip12) | Returned instance of a compressed or decompressed object. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

let zip = zlib.createZipSync();
```

## Zip<sup>12+</sup>

Compresses and decompresses an object instance.

### getZStream<sup>12+</sup>

getZStream(): Promise&lt;ZStream&gt;

Outputs a stream and uses a promise to asynchronously return the result. A zlib stream is returned upon success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| Promise&lt;[ZStream](#zstream12)&gt; | Promise used to return the result.   |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

let zip = zlib.createZipSync();

zip.getZStream().then(data => {
  console.info('getZStream success');
})
```

### zlibVersion<sup>12+</sup>

zlibVersion(): Promise&lt;string&gt;

Obtains the version information of the currently linked zlib library and uses a promise to asynchronously return the version information. The version of the current zlib library is returned upon success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                 | Description                                   |
| --------------------- | --------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. Returns the version of the current zlib library. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

let zip = zlib.createZipSync();

zip.zlibVersion().then((data) => {
  console.info('zlibVersion success')
})
```

### zlibCompileFlags<sup>12+</sup>

zlibCompileFlags(): Promise&lt;number&gt;

Returns a flag indicating a compile-time option, returned asynchronously using Promise. Returns a flag indicating compile-time options on success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                 | Description                                   |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. Returns a flag indicating compile-time options. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

let zip = zlib.createZipSync();

zip.zlibCompileFlags().then((data) => {
  console.info('zlibCompileFlags success')
})
```

### compress<sup>12+</sup>

compress(dest: ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt;

Compresses the source buffer to the target buffer and uses a promise to asynchronously return the result. On success, the result status and the total size of the destination buffer are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type       | Mandatory | Description          |
| --------- | ----------- | ---- | -------------- |
| dest      | ArrayBuffer | Yes  | Target buffer.  |
| source    | ArrayBuffer | Yes  | Source data buffer. |
| sourceLen | number      | No  | Length of the source data.  |

**Return value**

| Type                                            | Description                                           |
| ------------------------------------------------ | ----------------------------------------------- |
| Promise&lt;[ZipOutputInfo](#zipoutputinfo12)&gt; | Promise used to return the result. Returns the result status and the total size of the destination buffer. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800007 | Buffer error.                                                |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  byteArray[i] = str.charCodeAt(i)
}

let arrayBufferOut = new ArrayBuffer(100);
let zip = zlib.createZipSync();

zip.compress(arrayBufferOut, arrayBufferOut, 20).then((data) => {
  console.info('compress success:');
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### compress2<sup>12+</sup>

compress2(dest: ArrayBuffer, source: ArrayBuffer, level: CompressLevel, sourceLen?: number): Promise&lt;ZipOutputInfo&gt;

Compresses the source buffer to the target buffer and uses a promise to asynchronously return the result. On success, the result status and the total size of the destination buffer are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type         | Mandatory | Description                                                |
| --------- | ------------- | ---- | ---------------------------------------------------- |
| dest      | ArrayBuffer   | Yes  | Target buffer.                                        |
| source    | ArrayBuffer   | Yes  | Source data buffer.                                      |
| level     | CompressLevel | Yes  | See [zip.CompressLevel](#zipcompresslevel). |
| sourceLen | number        | No  | Length of the source data.                                        |

**Return value**

| Type                                            | Description                                           |
| ------------------------------------------------ | ----------------------------------------------- |
| Promise&lt;[ZipOutputInfo](#zipoutputinfo12)&gt; | Promise used to return the result. Returns the result status and the total size of the destination buffer. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800007 | Buffer error.                                                |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  byteArray[i] = str.charCodeAt(i)
}

let arrayBufferOut = new ArrayBuffer(100);
let zip = zlib.createZipSync();

zip.compress2(arrayBufferOut, arrayBufferIn, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
  console.info('compress2 success');
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### uncompress<sup>12+</sup>

uncompress(dest:ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt;

Decompresses the compressed data into the original uncompressed form and returns the data asynchronously using Promise. On success, the result status and the total size of the destination buffer are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type       | Mandatory | Description          |
| --------- | ----------- | ---- | -------------- |
| dest      | ArrayBuffer | Yes  | Target buffer.  |
| source    | ArrayBuffer | Yes  | Source data buffer. |
| sourceLen | number      | No  | Length of the source data.  |

**Return value**

| Type                                            | Description                                           |
| ------------------------------------------------ | ----------------------------------------------- |
| Promise&lt;[ZipOutputInfo](#zipoutputinfo12)&gt; | Promise used to return the result. Returns the result status and the total size of the destination buffer. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800005 | Data error.                                                  |
| 17800007 | Buffer error.                                                |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.compress(arrayBufferOut, arrayBufferIn, 12).then((data) => {
    console.info('compress success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.uncompress(arrayBufferIn, arrayBufferOut, 20).then((data) => {
    console.info('uncompress success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### uncompress2<sup>12+</sup>

uncompress2(dest: ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;DecompressionOutputInfo&gt;

Decompresses the compressed data into the original uncompressed form and returns the data asynchronously using Promise. If the operation is successful, the result status, total size of the destination buffer, and length of the source data are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type       | Mandatory | Description          |
| --------- | ----------- | ---- | -------------- |
| dest      | ArrayBuffer | Yes  | Target buffer.  |
| source    | ArrayBuffer | Yes  | Source data buffer. |
| sourceLen | number      | No  | Length of the source data.  |

**Return value**

| Type                                                        | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| Promise&lt;[DecompressionOutputInfo](#decompressionoutputinfo12)&gt; | Promise used to return the result. Returns the result status, total size of the destination buffer, and length of the source data. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800005 | Data error.                                                  |
| 17800007 | Buffer error.                                                |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.compress2(arrayBufferOut, arrayBufferIn, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('compress2 success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.uncompress2(arrayBufferIn, arrayBufferOut, 20).then((data) => {
    console.info('uncompress2 success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### compressBound<sup>12+</sup>

compressBound(sourceLen: number): Promise&lt;number&gt;

Calculate the upper limit of the returned compression size and use Promise to asynchronously return the size. The upper limit of the compression size is returned upon success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type  | Mandatory | Description        |
| --------- | ------ | ---- | ------------ |
| sourceLen | number | Yes  | Length of the source data. |

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. Added the API for returning the upper limit of a buffer to hold the compressed data. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  byteArray[i] = str.charCodeAt(i)
}

let zip = zlib.createZipSync();

zip.compressBound(str.length).then((data) => {
  console.info('compressBound success')
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### inflateValidate<sup>12+</sup>

inflateValidate(strm: ZStream, check: number): Promise&lt;ReturnStatus&gt;

Verify the checksum inside the compressed stream structure and use Promise to asynchronously return the checksum. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |
| check  | number  | Yes  | Indicates the expected checksum.                 |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateValidate({ availableIn: 1 }, 1).then(data => {
    console.info('inflateValidate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateSyncPoint<sup>12+</sup>

inflateSyncPoint(strm: ZStream): Promise&lt;ReturnStatus&gt;

Finds the synchronization point of the current decompression stream and uses a promise to return the synchronization point asynchronously. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateSyncPoint({ availableIn: 1 }).then(data => {
    console.info('inflateSyncPoint success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateSync<sup>12+</sup>

inflateSync(strm: ZStream): Promise&lt;ReturnStatus&gt;

Skip invalid compressed data until a possible complete refresh point is found, and use Promise to return asynchronously. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800005 | Data error.                                                  |
| 17800007 | Buffer error.                                                |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello, hello!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.deflateInit({}, zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflate({ nextIn: arrayBufferIn, availableIn: 3, nextOut: arrayBufferOut, availableOut: 100 }, zlib.CompressFlushMode.FULL_FLUSH).then((data) => {
    console.info('deflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflate({ availableIn: 11 }, zlib.CompressFlushMode.FINISH).then((data) => {
    console.info('deflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateEnd({}).then(data => {
    console.info('deflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  try {
    await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 2 }).then(data => {
      console.info('inflateInit2 success')
    })
  } catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  }
  await zip.inflate({ nextOut: arrayBufferIn, availableOut: 28 }, zlib.CompressFlushMode.NO_FLUSH).then((data) => {
    console.info('inflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateSync({ availableIn: 26 }).then(data => {
    console.info('inflateSync success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateEnd({ nextOut: arrayBufferOut }).then((data) => {
    console.info('inflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateResetKeep<sup>12+</sup>

inflateResetKeep(strm: ZStream): Promise&lt;ReturnStatus&gt;

Resets the state of the decompressed stream to preserve the allocated Huffman decoding tree and preset dictionary, returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateResetKeep({ availableIn: 1 }).then(data => {
    console.info('inflateResetKeep success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateSetDictionary<sup>12+</sup>

inflateSetDictionary(strm: ZStream, dictionary: ArrayBuffer): Promise&lt;ReturnStatus&gt;

Initializes the decompression dictionary from a given sequence of uncompressed bytes, returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type       | Mandatory | Description                           |
| ---------- | ----------- | ---- | ------------------------------- |
| strm       | ZStream     | Yes  | For details, see [ZStream Definition](#zstream12). |
| dictionary | ArrayBuffer | Yes  | Dictionary data.                     |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800005 | Data error.                                                  |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello, hello!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  let dictionary = 'hello'
  let dictionarybuf = new ArrayBuffer(dictionary.length);
  let dictionarybufdata = new Uint8Array(dictionarybuf);
  for (let i = 0, j = dictionary.length; i < j; i++) {
    dictionarybufdata[i] = str.charCodeAt(i);
  }
  await zip.deflateInit({}, zlib.CompressLevel.COMPRESS_LEVEL_BEST_COMPRESSION).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflateSetDictionary({}, dictionarybuf).then((data) => {
    console.info('deflateSetDictionary success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflate({ nextIn: arrayBufferIn, availableIn: 14, nextOut: arrayBufferOut, availableOut: 100 }, zlib.CompressFlushMode.FINISH).then((data) => {
    console.info('deflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflateEnd({}).then(data => {
    console.info('deflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  try {
    await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 100 }).then(data => {
      console.info('inflateInit success')
    })
  } catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  }
  await zip.inflate({ nextOut: arrayBufferIn, availableOut: 28 }, zlib.CompressFlushMode.NO_FLUSH).then((data) => {
    console.info('inflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.inflateSetDictionary({}, dictionarybuf).then((data) => {
    console.info('inflateSetDictionary success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.inflateEnd({ nextOut: arrayBufferOut }).then((data) => {
    console.info('inflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
}
```

### inflateReset2<sup>12+</sup>

inflateReset2(strm: ZStream, windowBits: number): Promise&lt;ReturnStatus&gt;

Initializes the decompression dictionary from a given sequence of uncompressed bytes, returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type   | Mandatory | Description                           |
| ---------- | ------- | ---- | ------------------------------- |
| strm       | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |
| windowBits | number  | Yes  | The base-2 logarithm of the maximum window size.  |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateReset2({ availableOut: 8 }, 15).then(data => {
    console.info('inflateReset2 success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateReset<sup>12+</sup>

inflateReset(strm: ZStream): Promise&lt;ReturnStatus&gt;

This function is equivalent to calling inflateEnd and then inflateInit. However, this function does not release or reallocate the internal decompression status. Promise is used to asynchronously return the status. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateReset({ availableIn: 1, availableOut: 8 }).then(data => {
    console.info('inflateReset success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflatePrime<sup>12+</sup>

inflatePrime(strm: ZStream, bits: number, value: number): Promise&lt;ReturnStatus&gt;

Initializes the decompression dictionary from a given sequence of uncompressed bytes, returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |
| bits   | number  | Yes  | bit provided.                     |
| value  | number  | Yes  | Indicates the provided value.                     |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflatePrime({ nextOut: arrayBufferOut }, 5, 2).then(data => {
    console.info('inflatePrime success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateMark<sup>12+</sup>

inflateMark(strm: ZStream): Promise&lt;number&gt;

It is used to mark the location in the input data for random access and is returned asynchronously using Promise. The location information is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. Promise used to return the current location. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateMark({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }).then(data => {
    console.info('inflateMark success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateInit2<sup>12+</sup>

inflateInit2(strm: ZStream, windowBits: number): Promise&lt;ReturnStatus&gt;

Initializes the internal stream state for decompression and returns asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type   | Mandatory | Description                           |
| ---------- | ------- | ---- | ------------------------------- |
| strm       | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |
| windowBits | number  | Yes  | The base-2 logarithm of the maximum window size.  |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  byteArray[i] = str.charCodeAt(i)
}

let arrayBufferOut = new ArrayBuffer(100);
let zip = zlib.createZipSync();

zip.inflateInit2({ nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }, 28
).then(data => {
  console.info('inflateInit2 success');
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### inflateInit<sup>12+</sup>

inflateInit(strm: ZStream): Promise&lt;ReturnStatus&gt;

Initializes the internal stream state for decompression and returns asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);

for (let i = 0, j = str.length; i < j; i++) {
  byteArray[i] = str.charCodeAt(i)
}

let arrayBufferOut = new ArrayBuffer(100);
let zip = zlib.createZipSync();

zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
).then(data => {
  console.info('inflateInit success');
}).catch((errData: BusinessError) => {
  console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### inflateGetHeader<sup>12+</sup>

inflateGetHeader(strm: ZStream, header: GzHeader): Promise&lt;ReturnStatus&gt;

Sets the gzip file header information before decompressing data. The information is returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type                   | Mandatory | Description                            |
| ------ | ----------------------- | ---- | -------------------------------- |
| strm   | ZStream                 | Yes  | For details, see [ZStream Definition](#zstream12). |
| header | [GzHeader](#gzheader12) | Yes  | gzip header information extracted from the compressed data stream. |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit2({ nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }, 28
  ).then(data => {
    console.info('inflateInit2 success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateGetHeader({ availableIn: 1, availableOut: 1 }, { isText: true, os: 1, time: 1, xflags: 1, extra: arrayBufferIn, extraLen: 12, name: arrayBufferIn, comment: arrayBufferOut, hcrc: true, done: true }).then(data => {
    console.info('inflateGetHeader success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateGetDictionary<sup>12+</sup>

inflateGetDictionary(strm: ZStream, dictionary: ArrayBuffer): Promise&lt;DictionaryOutputInfo&gt;

Obtains the content and length of the decompression dictionary used in the current decompression stream, and uses a promise to asynchronously return the content and length. When the operation is successful, the result status and dictionary length are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type       | Mandatory | Description                           |
| ---------- | ----------- | ---- | ------------------------------- |
| strm       | ZStream     | Yes  | For details, see [ZStream Definition](#zstream12). |
| dictionary | ArrayBuffer | Yes  | Receives the actual contents of the decompression dictionary.     |

**Return value**

| Type                                                        | Description                                   |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[DictionaryOutputInfo](#dictionaryoutputinfo12)&gt; | Promise used to return the result. Length of the returned result status and dictionary. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit2({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }, 28
  ).then(data => {
    console.info('inflateInit2 success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateGetDictionary({ nextOut: arrayBufferOut }, arrayBufferOut).then((data) => {
    console.info('inflateGetDictionary success:')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateEnd<sup>12+</sup>

inflateEnd(strm: ZStream): Promise&lt;ReturnStatus&gt;

All dynamically allocated data structures of the decompressed stream are released and returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflate({ availableIn: 8, availableOut: 8 }, 0).then((data) => {
    console.info('inflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateEnd({ nextOut: arrayBufferOut }).then((data) => {
    console.info('inflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateCopy<sup>12+</sup>

inflateCopy(source: Zip): Promise&lt;ReturnStatus&gt;

Copy the decompression stream and use Promise to asynchronously return the stream. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type | Mandatory | Description                   |
| ------ | ---- | ---- | ----------------------- |
| source | Zip  | Yes  | For details, see [Zip Definition](#zip12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateCopy(zip).then((data) => {
    console.info('inflateCopy success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateCodesUsed<sup>12+</sup>

inflateCodesUsed(strm: ZStream): Promise&lt;number&gt;

Number of Huffman coding trees used in the current decompressed stream, which is returned asynchronously using Promise. The number of used Huffman coding trees is returned on success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                 | Description                                         |
| --------------------- | --------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. Returns the number of used Huffman coding trees. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zip = zlib.createZipSync();
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateCodesUsed({ nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 8 }).then(data => {
    console.info('inflateCodesUsed success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### inflateBackInit<sup>12+</sup>

inflateBackInit(strm: ZStream, windowBits: number, window: ArrayBuffer): Promise&lt;ReturnStatus&gt;

Initialize the internal stream state for decompression before using the inflateBack() function, and use Promise to return asynchronously. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type       | Mandatory | Description                                         |
| ---------- | ----------- | ---- | --------------------------------------------- |
| strm       | ZStream     | Yes  | For details, see [ZStream Definition](#zstream12).              |
| windowBits | number      | Yes  | Indicates the base-2 logarithm of the maximum window size. The value ranges from 8 to 15. |
| window     | ArrayBuffer | Yes  | Preset window buffer.                           |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

Example: See [inflateBack](#inflateback12).

### inflateBackEnd<sup>12+</sup>

inflateBackEnd(strm: ZStream): Promise&lt;ReturnStatus&gt;

All memory allocated by the inflateBackInit() function is released and returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

Example: See [inflateBack](#inflateback12).

### inflateBack<sup>12+</sup>

inflateBack(strm: ZStream, backIn: InflateBackInputCallback, inDesc: object, backOut: InflateBackOutputCallback, outDesc: object): Promise&lt;ReturnStatus&gt;

Implement original decompression, use callback APIs to process input and output, and use Promise to asynchronously return. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type                     | Mandatory | Description                                                        |
| ------- | ------------------------- | ---- | ------------------------------------------------------------ |
| strm    | ZStream                   | Yes  | For details, see [ZStream Definition](#zstream12).                             |
| backIn  | InflateBackInputCallback  | Yes  | A function used to decompress data from the end to read raw compressed data from the input source. |
| inDesc  | object                    | Yes  | Common object.                                                  |
| backOut | InflateBackOutputCallback | Yes  | Writes the decompressed data to the target output.                                |
| outDesc | object                    | Yes  | Common object.                                                  |

Description of InflateBackInputCallback:

InflateBackInputCallback = (inDesc: object) => ArrayBuffer

| Name  | Type  | Mandatory | Description            |
| ------ | ------ | ---- | ---------------- |
| inDesc | object | Yes  | User-defined Data Object |

Description of InflateBackOutputCallback:

InflateBackOutputCallback = (outDesc: object, buf: ArrayBuffer, length: number) => number

| Name   | Type       | Mandatory | Description                  |
| ------- | ----------- | ---- | ---------------------- |
| outDesc | object      | Yes  | User-defined Data Object      |
| buf     | ArrayBuffer | Yes  | It is used to store the data to be written. |
| length  | number      | Yes  | Length of the data written to the output buffer. |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let readIn: (inDesc: object) => ArrayBuffer = (inDesc: object): ArrayBuffer => {
    console.info("inDesc = ", JSON.stringify(inDesc));
    let buffer = new ArrayBuffer(26)
    let array = new Uint8Array(buffer);
    array.set([31, 139, 8, 0, 0, 0, 0, 0, 0, 10, 243, 72, 205, 201, 201, 231, 2, 0, 22, 53, 150, 49, 6, 0, 0, 0]);
    return buffer;
  }

  let writeOut: (outDesc: object, buffer: ArrayBuffer, length: number) => number = (outDesc: object, buffer: ArrayBuffer, length: number): number => {
    console.info("outDesc = ", outDesc);
    console.info("buffer = ", buffer);
    console.info("length = ", length);
    let array = new Uint8Array(buffer);
    let dataString = "";
    for (let i = 0; i < length; i++) {
      dataString += String.fromCharCode(array[i]);
    }
    console.info('writeOut ', dataString);
    return 0;
  }

  let have = 0;
  let first = 1;
  let arrayBuffer = new ArrayBuffer(26);
  let next = new Uint8Array(arrayBuffer);
  let last = 0;
  let index = 0;
  let flags = 0;
  let NEXT2: () => number = (): number => {
    let o6: object = new Object()
    if (!have) {
      arrayBuffer = readIn(o6)
      next = new Uint8Array(arrayBuffer);
      console.info('readIn next = ', next.length)
      have = next.length;
    }
    if (have) {
      have--;
      last = next[index];
      index++;
    }
    else {
      last = -1;
    }
    return last;
  }

  let inflateBackTest: () => void = (async () => {
    try {
      have = 0;
      first = 1;
      arrayBuffer = new ArrayBuffer(26);
      next = new Uint8Array(arrayBuffer);
      last = 0;
      index = 0;
      flags = 0;
      let sr = zlib.createZipSync();
      let buffer = new ArrayBuffer(1024)
      await sr.inflateBackInit({}, 15, buffer).then((result) => {
        console.info('inflateBackInit Call result res', result)
      })
      let ret = 0;
      for (; ;) {
        if (NEXT2() == -1) {
          ret = 0;
          console.info('inflateBackTest Call result NEXT2() == -1')
          break;
        }
        console.info('have =  last = ', have, last)
        if (last != 31 || (NEXT2() != 139 && last >= 157 && last <= 157)) {
          ret = first ? -3 : -1;
          console.info('inflateBackTest Call result last != 31 || (NEXT2() != 139 && last != 157)')
          break;
        }
        first = 0;
        ret = -5;
        if (NEXT2() != 8) {
          if (last < 0) {
            console.info('inflateBackTest Call result 1 last == -1')
            break;
          }
        }
        flags = NEXT2();
        NEXT2();
        NEXT2();
        NEXT2();
        NEXT2();
        NEXT2();
        NEXT2();
        if (last < 0) {
          console.info('inflateBackTest Call result 2 last == -1')
          break;
        }
        console.info('index =  have = ', next[index], have)
        let newArrayBuffer = new ArrayBuffer(have);
        let newNext = new Uint8Array(newArrayBuffer);
        for (let i = 0; i < have; i++) {
          newNext[i] = next[26 - have + i];
        }
        console.info('newArrayBuffer.length = ', newArrayBuffer.byteLength)
        console.info('newNext.length = ', newNext.length)
        let zStream: zlib.ZStream = {
          nextIn: newArrayBuffer,
          availableIn: have,
        };
        await sr.inflateBack(
          zStream,
          readIn,
          { fileName: 'test.gz' },
          writeOut,
          { fileName: 'test.gz' }).then((result) => {
            ret = result;
            console.info('inflateBack Call result res', result)
          })
        if (ret == 1) {
          console.info('inflateBackTest Call result success')
          break;
        }
      }
      await sr.inflateBackEnd({}).then((result) => {
        console.info('inflateBackEnd Call result res', result)
      })
    }
    catch (errData) {
      console.error(`errData is message:${errData}`);
    }
  })
  inflateBackTest();
}
```

### inflate<sup>12+</sup>

inflate(strm: ZStream, flush: CompressFlushMode): Promise&lt;ReturnStatus&gt;

Decompress the data and use Promise to asynchronously return the data. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type             | Mandatory | Description                                                  |
| ------ | ----------------- | ---- | ------------------------------------------------------ |
| strm   | ZStream           | Yes  | For details, see [ZStream Definition](#zstream12).                       |
| flush  | CompressFlushMode | Yes  | For details, see [Definition of CompressFlushMode](#zipcompressflushmode12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800005 | Data error.                                                  |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflate({ availableOut: 8 }, zlib.CompressFlushMode.FINISH).then((data) => {
    console.info('deflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflateEnd({ nextOut: arrayBufferOut }).then(data => {
    console.info('deflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateInit({ nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }
  ).then(data => {
    console.info('inflateInit success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflate({ availableIn: 8, availableOut: 8 }, 0).then((data) => {
    console.info('inflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.inflateEnd({ nextOut: arrayBufferOut }).then((data) => {
    console.info('inflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateInit<sup>12+</sup>

deflateInit(strm: ZStream, level: CompressLevel): Promise&lt;ReturnStatus&gt;

Initializes the internal stream state for compression and returns asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type         | Mandatory | Description                                                |
| ------ | ------------- | ---- | ---------------------------------------------------- |
| strm   | ZStream       | Yes  | For details, see [ZStream Definition](#zstream12).                     |
| level  | CompressLevel | Yes  | See [zip.CompressLevel](#zipcompresslevel). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
}
```

### deflateInit2<sup>12+</sup>

deflateInit2(strm: ZStream, level: CompressLevel, method: CompressMethod, windowBits: number, memLevel: MemLevel, strategy: CompressStrategy): Promise&lt;ReturnStatus&gt;

Initializes the internal stream state for compression and returns asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type            | Mandatory | Description                                                      |
| ---------- | ---------------- | ---- | ---------------------------------------------------------- |
| strm       | ZStream          | Yes  | For details, see [ZStream Definition](#zstream12).                           |
| level      | CompressLevel    | Yes  | See [zip.CompressLevel](#zipcompresslevel).      |
| method     | CompressMethod   | Yes  | For details, see [zip.CompressMethod Enumeration Definition](#zipcompressmethod12).  |
| windowBits | number           | Yes  | The base-2 logarithm of the maximum window size.                             |
| memLevel   | MemLevel         | Yes  | See [zip.MemLevel](#zipmemlevel).                |
| strategy   | CompressStrategy | Yes  | See [zip.CompressStrategy](#zipcompressstrategy). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync()
  await zip.deflateInit2(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED, zlib.CompressMethod.DEFLATED, 28,
    zlib.MemLevel.MEM_LEVEL_DEFAULT, zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY).then((data) => {
      console.info('deflateInit2 success');
    }).catch((errData: BusinessError) => {
      console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
}
```

### deflate<sup>12+</sup>

deflate(strm: ZStream, flush: CompressFlushMode): Promise&lt;ReturnStatus&gt;

Compresses data and uses a promise to asynchronously return the data. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type             | Mandatory | Description                                                  |
| ------ | ----------------- | ---- | ------------------------------------------------------ |
| strm   | ZStream           | Yes  | For details, see [ZStream Definition](#zstream12).                       |
| flush  | CompressFlushMode | Yes  | For details, see [Definition of CompressFlushMode](#zipcompressflushmode12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800007 | Buffer error.                                                |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflate({ availableOut: 8 }, zlib.CompressFlushMode.FINISH).then((data) => {
    console.info('deflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
}
```

### deflateEnd<sup>12+</sup>

deflateEnd(strm: ZStream): Promise&lt;ReturnStatus&gt;

All dynamically allocated data structures of the compressed stream are released and returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflate({ availableOut: 8 }, zlib.CompressFlushMode.FINISH).then((data) => {
    console.info('deflate success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
  await zip.deflateEnd({ nextOut: arrayBufferOut }).then(data => {
    console.info('deflateEnd success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateBound<sup>12+</sup>

deflateBound(strm: ZStream, sourceLength: number): Promise&lt;number&gt;

Calculate the upper limit of the compression size and use Promise to asynchronously return the result. The upper limit of the compression size is returned upon success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name   | Type   | Mandatory | Description                           |
| --------- | ------- | ---- | ------------------------------- |
| strm      | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |
| sourceLength | number  | Yes  | Length of the source data.                   |

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. Added the API for returning the upper limit of a buffer to hold the compressed data. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateBound({ nextOut: arrayBufferOut }, 12).then((data) => {
    console.info('deflateBound success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateSetHeader<sup>12+</sup>

deflateSetHeader(strm: ZStream, head: GzHeader): Promise&lt;ReturnStatus&gt;

When deflateInit2() requests a gzip stream, the gzip header information is provided and returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type                   | Mandatory | Description                            |
| ------ | ----------------------- | ---- | -------------------------------- |
| strm   | ZStream                 | Yes  | For details, see [ZStream Definition](#zstream12). |
| head   | [GzHeader](#gzheader12) | Yes  | gzip header information extracted from the compressed data stream. |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync()
  await zip.deflateInit2(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED, zlib.CompressMethod.DEFLATED, 28,
    zlib.MemLevel.MEM_LEVEL_DEFAULT, zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY).then((data) => {
      console.info('deflateInit2 success');
    }).catch((errData: BusinessError) => {
      console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
  await zip.deflateSetHeader({ nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1 }, { isText: true, os: 1, time: 1, xflags: 1, extra: arrayBufferIn, extraLen: 12, name: arrayBufferIn, comment: arrayBufferOut, hcrc: true, done: true }).then((data) => {
    console.info('deflateSetHeader success');
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
  })
}
```

### deflateCopy<sup>12+</sup>

deflateCopy(source: Zip): Promise&lt;ReturnStatus&gt;

Copy the compressed stream and use Promise to asynchronously return the stream. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type | Mandatory | Description                   |
| ------ | ---- | ---- | ----------------------- |
| source | Zip  | Yes  | For details, see [Zip Definition](#zip12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateCopy(zip).then((data) => {
    console.info('deflateCopy success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateSetDictionary<sup>12+</sup>

deflateSetDictionary(strm: ZStream, dictionary: ArrayBuffer): Promise&lt;ReturnStatus&gt;

Initializes the compression dictionary from a given sequence of bytes, returned asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type       | Mandatory | Description                           |
| ---------- | ----------- | ---- | ------------------------------- |
| strm       | ZStream     | Yes  | For details, see [ZStream Definition](#zstream12). |
| dictionary | ArrayBuffer | Yes  | Dictionary data.                     |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateSetDictionary({ nextOut: arrayBufferOut }, arrayBufferOut).then((data) => {
    console.info('deflateSetDictionary success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateGetDictionary<sup>12+</sup>

deflateGetDictionary(strm: ZStream, dictionary: ArrayBuffer): Promise&lt;DictionaryOutputInfo&gt;

Obtains the content and length of the decompression dictionary used in the current decompression stream, and uses a promise to asynchronously return the content and length. When the operation is successful, the result status and dictionary length are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type       | Mandatory | Description                           |
| ---------- | ----------- | ---- | ------------------------------- |
| strm       | ZStream     | Yes  | For details, see [ZStream Definition](#zstream12). |
| dictionary | ArrayBuffer | Yes  | Receives the actual contents of the decompression dictionary.     |

**Return value**

| Type                                                        | Description                                   |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[DictionaryOutputInfo](#dictionaryoutputinfo12)&gt; | Promise used to return the result. Length of the returned result status and dictionary. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateSetDictionary({ nextOut: arrayBufferOut }, arrayBufferOut).then((data) => {
    console.info('deflateSetDictionary success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateGetDictionary({ nextOut: arrayBufferOut }, arrayBufferOut).then((data) => {
    console.info('deflateGetDictionary success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateTune<sup>12+</sup>

deflateTune(strm: ZStream, goodLength: number, maxLazy: number, niceLength: number, maxChain: number): Promise&lt;ReturnStatus&gt;

Fine-tunes the internal compression parameters of deflate and uses a promise to asynchronously return the parameters. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name    | Type   | Mandatory | Description                           |
| ---------- | ------- | ---- | ------------------------------- |
| strm       | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |
| goodLength | number  | Yes  | Indicates the matching length threshold.               |
| maxLazy    | number  | Yes  | Indicates the maximum matching delay.             |
| niceLength | number  | Yes  | Appropriate delay length threshold             |
| maxChain   | number  | Yes  | Maximum Chain Length                   |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateTune({ nextOut: arrayBufferOut }, 2, 2, 2, 2).then((data) => {
    console.info('deflateTune success:')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateReset<sup>12+</sup>

deflateReset(strm: ZStream): Promise&lt;ReturnStatus&gt;

This function is equivalent to calling deflateEnd and then deflateInit. However, this function does not release or reallocate the internal decompression status. Promise is used to asynchronously return the status. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateReset({ nextOut: arrayBufferOut }).then((data) => {
    console.info('deflateReset success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateResetKeep<sup>12+</sup>

deflateResetKeep(strm: ZStream): Promise&lt;ReturnStatus&gt;

Resets the initialized deflate compression stream, but retains the compression parameters and dictionaries set by it, and returns asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateResetKeep({ nextOut: arrayBufferOut }).then((data) => {
    console.info('deflateResetKeep success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflatePending<sup>12+</sup>

deflatePending(strm: ZStream): Promise&lt;DeflatePendingOutputInfo&gt;

Returns the number of bytes and bits of the output that has been generated but has not yet been provided in the available output, using Promise asynchronous return. If the operation is successful, the result status, number of output bits, and number of output bytes are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |

**Return value**

| Type                                                        | Description                                             |
| ------------------------------------------------------------ | ------------------------------------------------- |
| Promise&lt;[DeflatePendingOutputInfo](#deflatependingoutputinfo12)&gt; | Promise used to return the result. Returns the result status, number of output bits, and number of output bytes. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflatePending({ nextOut: arrayBufferOut }).then((data) => {
    console.info('deflatePending success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflateParams<sup>12+</sup>

deflateParams(strm: ZStream, level: CompressLevel, strategy: CompressStrategy): Promise&lt;ReturnStatus&gt;

The compression level and compression policy are dynamically updated, and Promise is used for asynchronous return. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name  | Type            | Mandatory | Description                                                      |
| -------- | ---------------- | ---- | ---------------------------------------------------------- |
| strm     | ZStream          | Yes  | For details, see [ZStream Definition](#zstream12).                           |
| level    | CompressLevel    | Yes  | See [zip.CompressLevel](#zipcompresslevel).      |
| strategy | CompressStrategy | Yes  | See [zip.CompressStrategy](#zipcompressstrategy). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync()
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflateParams(zStream, zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION, zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY).then((data) => {
    console.info('deflateParams success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

### deflatePrime<sup>12+</sup>

deflatePrime(strm: ZStream, bits: number, value: number): Promise&lt;ReturnStatus&gt;

Inserts bits and values into the compressed stream and returns them asynchronously using Promise. The result status is returned when the operation is successful.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type   | Mandatory | Description                           |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | Yes  | For details, see [ZStream Definition](#zstream12). |
| bits   | number  | Yes  | Number of digits to be inserted. The value ranges from 0 to 16. |
| value  | number  | Yes  | Bit value corresponding to the number of bits.           |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise used to return the result. Returned result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib, BusinessError } from '@kit.BasicServicesKit';

async function demo() {
  let str = 'hello world!';
  let arrayBufferIn = new ArrayBuffer(str.length);
  let byteArray = new Uint8Array(arrayBufferIn);
  for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
  }
  let arrayBufferOut = new ArrayBuffer(100);
  let zStream: zlib.ZStream = {
    nextIn: arrayBufferIn,
    availableIn: 1,
    nextOut: arrayBufferOut,
    availableOut: 1
  };
  let zip = zlib.createZipSync();
  await zip.deflateInit(zStream, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED).then((data) => {
    console.info('deflateInit success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
  await zip.deflatePrime({ nextOut: arrayBufferOut }, 5, 2).then((data) => {
    console.info('deflatePrime success')
  }).catch((errData: BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
  })
}
```

## Options

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

| Name    | Type            | Readable | Writable | Description                                                      |
| -------- | ---------------- | ---- | ---- | ---------------------------------------------------------- |
| level    | CompressLevel     | Yes  | No  | See [zip.CompressLevel](#zipcompresslevel).      |
| memLevel | MemLevel         | Yes  | No  | See [zip.MemLevel](#zipmemlevel).                |
| strategy | CompressStrategy | Yes  | No  | See [zip.CompressStrategy](#zipcompressstrategy). |

## zip.CompressLevel

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

| Name                              | Value  | Description             |
| ---------------------------------- | ---- | ----------------- |
| COMPRESS_LEVEL_NO_COMPRESSION      | 0    | Compress level 0 that indicates uncompressed. |
| COMPRESS_LEVEL_BEST_SPEED          | 1    | Compression level 1 that gives the best speed. |
| COMPRESS_LEVEL_BEST_COMPRESSION    | 9    | Compression level 9 that gives the best compression.     |
| COMPRESS_LEVEL_DEFAULT_COMPRESSION | -1   | Default compression level.     |

## zip.MemLevel

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

| Name             | Value  | Description                            |
| ----------------- | ---- | -------------------------------- |
| MEM_LEVEL_MIN     | 1    | Minimum memory used by the **zip** API during compression. |
| MEM_LEVEL_MAX     | 9    | Maximum memory used by the **zip** API during compression. |
| MEM_LEVEL_DEFAULT | 8    | Default memory used by the **zip** API during compression. |

## zip.CompressStrategy

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.Zlib

| Name                              | Value  | Description                    |
| ---------------------------------- | ---- | ------------------------ |
| COMPRESS_STRATEGY_DEFAULT_STRATEGY | 0    | Default compression strategy.            |
| COMPRESS_STRATEGY_FILTERED         | 1    | Filtered compression strategy. |
| COMPRESS_STRATEGY_HUFFMAN_ONLY     | 2    | Huffman coding compression strategy.  |
| COMPRESS_STRATEGY_RLE              | 3    | RLE compression strategy.        |
| COMPRESS_STRATEGY_FIXED            | 4    | Fixed compression strategy.          |

## zip.ErrorCode

**System capability**: SystemCapability.BundleManager.Zlib

| Name            | Value  | Description        |
| ---------------- | ---- | ------------ |
| ERROR_CODE_OK    | 0    | The API is successfully called. |
| ERROR_CODE_ERRNO | -1   | Failed to call the API. |

## zip.CompressFlushMode<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name         | Value  | Description                                        |
| ------------- | ---- | -------------------------------------------- |
| NO_FLUSH      | 0    | Default value, indicating a normal operation.                      |
| PARTIAL_FLUSH | 1    | Some refresh points are generated in the stream.                      |
| SYNC_FLUSH    | 2    | Forcibly outputs all compressed data while maintaining the compressed stream state. |
| FULL_FLUSH    | 3    | Resets the compression status.                              |
| FINISH        | 4    | The compression or decompression process ends.                      |
| BLOCK         | 5    | Allow more precise control.                          |
| TREES         | 6    | There are special purposes during the implementation.                      |

## zip.CompressMethod<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name    | Value  | Description      |
| -------- | ---- | ---------- |
| DEFLATED | 8    | Compression method. |

## zip.ReturnStatus<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name      | Value  | Description                                          |
| ---------- | ---- | ---------------------------------------------- |
| OK         | 0    | The API is successfully called.                                |
| STREAM_END | 1    | If the function is successfully called, the entire data has been processed.          |
| NEED_DICT  | 2    | If the function is successfully called, a dictionary needs to be preset to continue decompression. |

## ZStream<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name        | Type       | Readable | Writable | Description                                                        |
| ------------ | ----------- | ---- | ---- | ------------------------------------------------------------ |
| nextIn       | ArrayBuffer | Yes  | No  | Input bytes to be compressed                                          |
| availableIn  | number      | Yes  | No  | Number of bytes available for nextIn                                          |
| totalIn      | number      | Yes  | No  | Total number of input bytes read so far                                |
| nextOut      | ArrayBuffer | Yes  | No  | Output bytes after compression                                            |
| availableOut | number      | Yes  | No  | Number of remaining bytes of nextOut                                     |
| totalOut     | number      | Yes  | No  | Total number of output bytes so far                                      |
| dataType     | number      | Yes  | No  | Best guesses about data types: binary or text of deflate, or decoding state of inflate |
| adler        | number      | Yes  | No  | Adler-32 or CRC-32 value of uncompressed data                              |

## ZipOutputInfo<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name   | Type        | Readable | Writable | Description                                                 |
| ------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status  | ReturnStatus | Yes  | No  | For details, see [zlib.ReturnStatus Enumeration Definition](#zipreturnstatus12). |
| destLen | number       | Yes  | No  | Total length of the destination buffer.                                 |

## DictionaryOutputInfo<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name            | Type        | Readable | Writable | Description                                                 |
| ---------------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status           | ReturnStatus | Yes  | No  | For details, see [zlib.ReturnStatus Enumeration Definition](#zipreturnstatus12). |
| dictionaryLength | number       | Yes  | No  | Length of a dictionary.                                         |

## DecompressionOutputInfo<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name            | Type        | Readable | Writable | Description                                                 |
| ---------------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status           | ReturnStatus | Yes  | No  | For details, see [zlib.ReturnStatus Enumeration Definition](#zipreturnstatus12). |
| destLength       | number       | Yes  | No  | Length of the destination buffer.                                    |
| sourceLength     | number       | Yes  | No  | Length of the source buffer.                                      |

## DeflatePendingOutputInfo<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name   | Type        | Readable | Writable | Description                                                 |
| ------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status  | ReturnStatus | Yes  | No  | For details, see [zlib.ReturnStatus Enumeration Definition](#zipreturnstatus12). |
| pending | number       | Yes  | No  | Number of output bytes that have been generated.                                 |
| bits    | number       | Yes  | No  | Number of output bits that have been generated.                                   |

## GzHeader<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name    | Type       | Readable | Writable | Description                                |
| -------- | ----------- | ---- | ---- | ------------------------------------ |
| isText   | boolean     | Yes  | No  | True if the compressed data is considered text. |
| os       | number      | Yes  | No  | Operating system.                          |
| time     | number      | Yes  | No  | Indicates the modification time.                          |
| xflags   | number      | Yes  | No  | Extra flag.                          |
| extra    | ArrayBuffer | Yes  | No  | Extra field.                          |
| extraLen | number      | Yes  | No  | Length of the extra field.                    |
| name     | ArrayBuffer | Yes  | No  | File name.                            |
| comment  | ArrayBuffer | Yes  | No  | Comment.                              |
| hcrc     | boolean     | Yes  | No  | True if the crc header exists.         |
| done     | boolean     | Yes  | No  | True after reading the gzip header.              |

## zlib.createGZip<sup>12+</sup>

createGZip(): Promise&lt;GZip&gt;

Creates a GZip object and uses a promise to asynchronously return the object. On success, a Gzip object instance is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                          | Description                           |
| ------------------------------ | ------------------------------- |
| Promise&lt;[GZip](#gzip12)&gt; | Promise used to return the result. The GZip object instance is returned. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

zlib.createGZip().then((data) => {
  console.info('createGZip success');
})
```

## zlib.createGZipSync<sup>12+</sup>

createGZipSync():  GZip

Create a GZip object. A GZip object instance is returned on success.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type           | Description          |
| --------------- | -------------- |
| [GZip](#gzip12) | GZip object instance. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';

let gzip = zlib.createGZipSync();
```

## GZip<sup>12+</sup>

Gzip-related APIs.

### gzdopen<sup>12+</sup>

gzdopen(fd: number, mode: string): Promise&lt;void&gt;

Associates gzFile with the file descriptor fd and opens the file for reading and decompressing, or compressing and writing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type  | Mandatory | Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | Yes  | File descriptor. Generally, the value is obtained by invoking the open method or other methods. |
| mode   | string | Yes  | This parameter specifies the access mode.                                          |

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800002 | No such file or access mode error.                           |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzdopenDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzdopen");
  let path = pathDir + "/gzdopen/test.gz";
  let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  let gzip = zlib.createGZipSync();
  await gzip.gzdopen(file.fd, "wb");
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzdopenDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzbuffer<sup>12+</sup>

gzbuffer(size: number):Promise&lt;number&gt;

Sets the internal buffer size for the current library function.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| size   | number | Yes  | Size of the internal buffer to be set. |

**Return value**

| Type                 | Description                        |
| --------------------- | ---------------------------- |
| Promise&lt;number&gt; | Promise object. If the operation is successful, 0 is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |

**Example**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { zlib } from '@kit.BasicServicesKit'

async function gzbufferDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzbuffer");
  let path = pathDir + "/gzbuffer/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let result = await gzip.gzbuffer(648);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzbufferDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzopen<sup>12+</sup>

gzopen(path: string, mode: string): Promise&lt;void&gt;

Opens the gzip (.gz) file in the specified path for reading and decompressing, or compressing and writing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type  | Mandatory | Description                |
| ------ | ------ | ---- | -------------------- |
| path   | string | Yes  | Path of the file to be opened. |
| mode   | string | Yes  | Specifies the method of opening a file.  |

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800002 | No such file or No such file or access mode error.                           |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzopenDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzopen");
  let path = pathDir + "/gzopen/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzopenDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzeof<sup>12+</sup>

gzeof(): Promise&lt;number&gt;

Check whether the read location of the gzip compressed file has reached the end of the file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise object. If the end-of-file indicator of the file is set when the file is read, 1 is returned. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzeofDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzeof");
  let path = pathDir + "/gzeof/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let writeBufferWithData = new ArrayBuffer(16);
  let uint8View = new Uint8Array(writeBufferWithData);
  for (let i = 0; i < uint8View.length; i++) {
    uint8View[i] = i;
  }
  let writeNum = await gzip.gzwrite(writeBufferWithData, 16)
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let readBufferWithData = new ArrayBuffer(20);
  let readNum = await gzip.gzread(readBufferWithData);
  let eofNum = await gzip.gzeof();
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzeofDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzdirect<sup>12+</sup>

gzdirect(): Promise&lt;number&gt;

Check whether the specified gzip file handle file directly accesses the original uncompressed data and reallocates the buffer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                 | Description                                              |
| --------------------- | -------------------------------------------------- |
| Promise&lt;number&gt; | Promise object. If the original uncompressed data is directly accessed, 1 is returned. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzdirectDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzdirect");
  let path = pathDir + "/gzdirect/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let directNum = await gzip.gzdirect();
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzdirectDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzclose<sup>12+</sup>

gzclose(): Promise&lt;ReturnStatus&gt;

Clears all pending output of the file, closes the file if necessary, and releases (decompresses) the compression state.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise object, which returns the result status. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message                 |
| -------- | ------------------------- |
| 17800004 | ZStream error.            |
| 17800006 | Memory allocation failed. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzcloseDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzclose");
  let path = pathDir + "/gzclose/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzcloseDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzclearerr<sup>12+</sup>

gzclearerr(): Promise&lt;void&gt;

Clears the errors and end-of-file flags of a file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzclearerrDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzclearerr");
  let path = pathDir + "/gzclearerr/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let writeBufferWithData = new ArrayBuffer(16);
  let uint8View = new Uint8Array(writeBufferWithData);
  for (let i = 0; i < uint8View.length; i++) {
    uint8View[i] = i;
  }
  let writeNum = await gzip.gzwrite(writeBufferWithData, 16)
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let readBufferWithData = new ArrayBuffer(20);
  let readNum = await gzip.gzread(readBufferWithData);
  let eofNum = await gzip.gzeof();
  await gzip.gzclearerr();
  let eofNumClear = await gzip.gzeof();
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzclearerrDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzerror<sup>12+</sup>

gzerror(): Promise&lt;GzErrorOutputInfo&gt;

Error message of the last error that occurred on the file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                                                       | Description                                                     |
| ----------------------------------------------------------- | --------------------------------------------------------- |
| Promise&lt;[GzErrorOutputInfo](#zipgzerroroutputinfo12)&gt; | Promise object, which returns the result status and the status message of the last status that appears. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message      |
| -------- | -------------- |
| 17800004 | ZStream error. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzerrorDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzerror");
  let path = pathDir + "/gzerror/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let writeBufferWithData = new ArrayBuffer(16);
  let uint8View = new Uint8Array(writeBufferWithData);
  for (let i = 0; i < uint8View.length; i++) {
    uint8View[i] = i;
  }
  try {
    await gzip.gzwrite(writeBufferWithData, -1);
  } catch (errData) {
    await gzip.gzerror().then((GzErrorOutputInfo) => {
      console.info('errCode', GzErrorOutputInfo.status);
      console.info('errMsg', GzErrorOutputInfo.statusMsg);
    })
  }
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzerrorDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzgetc<sup>12+</sup>

gzgetc(): Promise&lt;number&gt;

Reads and decompresses a byte from a file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                 | Description                                |
| --------------------- | ------------------------------------ |
| Promise&lt;number&gt; | Promise object, which returns the ASCII value of the read character. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message                 |
| -------- | ------------------------- |
| 17800009 | Internal structure error. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzgetcDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzgetc");
  let path = pathDir + "/gzgetc/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzputc(1);
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let resulit = await gzip.gzgetc();
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzgetcDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzflush<sup>12+</sup>

gzflush(flush: CompressFlushMode): Promise&lt;ReturnStatus&gt;

Refreshes all suspended output to the file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type             | Mandatory | Description                                                        |
| ------ | ----------------- | ---- | ------------------------------------------------------------ |
| flush  | CompressFlushMode | Yes  | Controls the refresh operation. For details, see the definition of [CompressFlushMode enumeration](#zipcompressflushmode12). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise object, which returns the result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzflushDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzflush");
  let path = pathDir + "/gzflush/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let flushNum = await gzip.gzflush(zlib.CompressFlushMode.NO_FLUSH);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzflushDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzfwrite<sup>12+</sup>

gzfwrite(buf: ArrayBuffer, size: number, nitems: number): Promise&lt;number&gt;

Compresses data blocks whose size is size and quantity is nitems from the buffer and writes the data blocks to a file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type       | Mandatory | Description                  |
| ------ | ----------- | ---- | ---------------------- |
| buf    | ArrayBuffer | Yes  | Buffer to which data is to be written. |
| size   | number      | Yes  | Number of bytes in a single data block. |
| nitems | number      | Yes  | Number of data blocks to be written.    |

**Return value**

| Type                 | Description                                               |
| --------------------- | --------------------------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the number of complete data blocks whose size is size. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzfwriteDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzfwrite");
  let path = pathDir + "/gzfwrite/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let bufferWithData = new ArrayBuffer(16);
  let uint8View = new Uint8Array(bufferWithData);
  for (let i = 0; i < uint8View.length; i++) {
    uint8View[i] = i;
  }
  let resulit = await gzip.gzfwrite(bufferWithData, 8, 2)
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzfwriteDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzfread<sup>12+</sup>

gzfread(buf: ArrayBuffer, size: number, nitems: number): Promise&lt;number&gt;

Decompresses and reads data from a gzip compressed file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type       | Mandatory | Description                          |
| ------ | ----------- | ---- | ------------------------------ |
| buf    | ArrayBuffer | Yes  | Target buffer for storing read results. |
| size   | number      | Yes  | Number of bytes in a single data block.        |
| nitems | number      | Yes  | Number of data blocks to be written.            |

**Return value**

| Type                 | Description                                               |
| --------------------- | --------------------------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the number of complete data blocks whose size is size. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzfreadDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzfread");
  let path = pathDir + "/gzfread/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let writeBuffer = new ArrayBuffer(16);
  let uint8View = new Uint8Array(writeBuffer);
  for (let i = 0; i < uint8View.length; i++) {
    uint8View[i] = i;
  }
  await gzip.gzfwrite(writeBuffer, 8, 2);
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let readBuffer = new ArrayBuffer(16);
  let result = await gzip.gzfread(readBuffer, 8, 2);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzfreadDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzclosew<sup>12+</sup>

gzclosew(): Promise&lt;ReturnStatus&gt;

It has the same function as gzclose() and applies only to writing or appending.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise object, which returns the result status. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message                 |
| -------- | ------------------------- |
| 17800004 | ZStream error.            |
| 17800006 | Memory allocation failed. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzclosewDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzclosew");
  let path = pathDir + "/gzclosew/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzclosew();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzclosewDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzcloser<sup>12+</sup>

gzcloser(): Promise&lt;ReturnStatus&gt;

It has the same function as gzclose () and is only applicable when reading.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise object, which returns the result status. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message      |
| -------- | -------------- |
| 17800004 | ZStream error. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzcloserDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzcloser");
  let path = pathDir + "/gzcloser/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  await gzip.gzcloser();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzcloserDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzwrite<sup>12+</sup>

gzwrite(buf: ArrayBuffer, len: number): Promise&lt;number&gt;

Compresses the uncompressed bytes of the len length in the buffer and writes them to the file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name | Type       | Mandatory | Description                        |
| ------ | ----------- | ---- | ---------------------------- |
| buf    | ArrayBuffer | Yes  | The object points to the data buffer to be written. |
| len    | number      | Yes  | Length of uncompressed bytes.            |

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the number of uncompressed bytes written. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzwriteDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzwrite");
  let path = pathDir + "/gzwrite/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let bufferWithData = new ArrayBuffer(16);
  let uint8View = new Uint8Array(bufferWithData);
  for (let i = 0; i < uint8View.length; i++) {
    uint8View[i] = i;
  }
  let result = await gzip.gzwrite(bufferWithData, 16);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzwriteDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzungetc<sup>12+</sup>

gzungetc(c: number): Promise&lt;number&gt;

Pushes c back into the stream so that it will be read as the first character the next time the file is read.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name | Type  | Mandatory | Description                    |
| ------ | ------ | ---- | ------------------------ |
| c      | number | Yes  | Returns to the character before the input stream. |

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the pushed characters. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzungetcDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzungetc");
  let path = pathDir + "/gzungetc/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  await gzip.gzread(new ArrayBuffer(1));
  let result = await gzip.gzungetc(1);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzungetcDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gztell<sup>12+</sup>

gztell(): Promise&lt;number&gt;

Returns the start position of the next gzread or gzwrite in the file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                 | Description                                                    |
| --------------------- | -------------------------------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the start position of the next gzread or gzwrite of a file. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message                 |
| -------- | ------------------------- |
| 17800009 | Internal structure error. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gztellDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gztell");
  let path = pathDir + "/gztell/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let result = await gzip.gztell();
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gztellDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzsetparams<sup>12+</sup>

gzsetparams(level: CompressLevel, strategy: CompressStrategy): Promise&lt;ReturnStatus&gt;

Dynamically updates the compression level and policy of a file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name  | Type            | Mandatory | Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| level    | CompressLevel    | Yes  | Compression level. For details, see [zip.CompressLevel enumeration definition](#zipcompresslevel). |
| strategy | CompressStrategy | Yes  | Compression policy. For details, see [zip.CompressStrategy enumeration definition](#zipcompressstrategy). |

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise object, which returns the result status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzsetparamsDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzsetparams");
  let path = pathDir + "/gzsetparams/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let result = await gzip.gzsetparams(zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
    zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzsetparamsDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzseek<sup>12+</sup>

gzseek(offset: number, whence: OffsetReferencePoint): Promise&lt;number&gt;

Sets the start position to the offset position relative to the next gzread or gzwrite in the file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type                | Mandatory | Description                                                        |
| ------ | -------------------- | ---- | ------------------------------------------------------------ |
| offset | number               | Yes  | Target offset position.                                              |
| whence | OffsetReferencePoint | Yes  | Reference point for defining the offset. For details, see [zip.OffsetReferencePoint Enumeration Definition](#zipoffsetreferencepoint12). |

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise object, which returns the result offset position measured in bytes from the beginning of an uncompressed stream. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzseekDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzseek");
  let path = pathDir + "/gzseek/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let result = await gzip.gzseek(2, zlib.OffsetReferencePoint.SEEK_CUR);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzseekDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzrewind<sup>12+</sup>

gzrewind(): Promise&lt;ReturnStatus&gt;

Repositions the file pointer to the beginning of the file. This function is used only for reading.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                                             | Description                       |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise object, which returns the result status. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message                 |
| -------- | ------------------------- |
| 17800009 | Internal structure error. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzrewindDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzrewind");
  let path = pathDir + "/gzrewind/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let result = await gzip.gzrewind();
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzrewindDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzread<sup>12+</sup>

gzread(buf: ArrayBuffer): Promise&lt;number&gt;

Reads up to len uncompressed bytes from a file and decompresses them into buf.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type       | Mandatory | Description          |
| ------ | ----------- | ---- | -------------- |
| buf    | ArrayBuffer | Yes  | Target offset position. |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the number of uncompressed bytes that are actually read. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzreadDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzread");
  let path = pathDir + "/gzread/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let writeBuffer = new ArrayBuffer(16);
  let uint8View = new Uint8Array(writeBuffer);
  for (let i = 0; i < uint8View.length; i++) {
    uint8View[i] = i;
  }
  await gzip.gzwrite(writeBuffer, 16);
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let readBuffer = new ArrayBuffer(16);
  let result = await gzip.gzread(readBuffer);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzreadDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzputs<sup>12+</sup>

gzputs(str: string): Promise&lt;number&gt;

Compresses the given null-terminated string and writes it to the file, excluding the terminated null character.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type  | Mandatory | Description                  |
| ------ | ------ | ---- | ---------------------- |
| str    | string | Yes  | Format descriptors and plain text. |

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the number of written characters. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzputsDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzputs");
  let path = pathDir + "/gzputs/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let result = await gzip.gzputs("hello");
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzputsDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzputc<sup>12+</sup>

gzputc(char: number): Promise&lt;number&gt;

Compresses c converted to an unsigned character and writes it to a file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type  | Mandatory | Description           |
| ------ | ------ | ---- | --------------- |
| char   | number | Yes  | Write character ASCII. |

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the written value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzputcDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzputc");
  let path = pathDir + "/gzputc/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let result = await gzip.gzputc(0);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzputcDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzprintf<sup>12+</sup>

gzprintf(format: string, ...args: Array&lt;string | number&gt;): Promise&lt;number&gt;

After parameters are converted and formatted under the control of the string format, the parameters are compressed and written to a file, as shown in fprintf.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type                         | Mandatory | Description                  |
| ------ | ----------------------------- | ---- | ---------------------- |
| format | string                        | Yes  | Format descriptors and plain text. |
| args   | Array&lt;string \| number&gt; | No  | List of variable parameters.        |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the number of uncompressed bytes that are actually written. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzprintfDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzprintf");
  let path = pathDir + "/gzprintf/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let result = await gzip.gzprintf("name is %s, age is %d", "Tom", 23);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzprintfDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzoffset<sup>12+</sup>

gzoffset(): Promise&lt;number&gt;

Returns the current compressed (actual) read or write offset of the file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Return value**

| Type                 | Description                                                 |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;number&gt; | Promise object, which returns the current compressed (actual) read or write offset of the file. |

**Error codes**

For details about the error codes, see [zlib Error Codes](errorcode-zlib.md).

| ID | Error Message                 |
| -------- | ------------------------- |
| 17800009 | Internal structure error. |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzoffsetDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzoffset");
  let path = pathDir + "/gzoffset/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  let result = await gzip.gzoffset();
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzoffsetDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### gzgets<sup>12+</sup>

gzgets(buf: ArrayBuffer): Promise&lt;string&gt;

Reads bytes from a file and decompresses them into buf until the len-1 character is read, or until a newline character is read and transferred to buf, or an end-of-file condition is encountered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

**Parameters**

| Name | Type       | Mandatory | Description              |
| ------ | ----------- | ---- | ------------------ |
| buf    | ArrayBuffer | Yes  | Stores the read row data. |

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise object, which returns a null-terminated string. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [zlib Error Codes](./errorcode-zlib.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed. |
| 17800009 | Internal structure error.                                    |

**Example**

```ts
import { zlib } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function gzgetsDemo(pathDir: string) {
  fs.mkdirSync(pathDir + "/gzgets");
  let path = pathDir + "/gzgets/test.gz";
  let gzip = zlib.createGZipSync();
  await gzip.gzopen(path, "wb");
  await gzip.gzputs("hello");
  await gzip.gzclose();
  await gzip.gzopen(path, "rb");
  let bufferWithData = new ArrayBuffer(16);
  let result = await gzip.gzgets(bufferWithData);
  await gzip.gzclose();
}

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('test gzip interface')
          .type(ButtonType.Capsule)
          .height(60)
          .width(200)
          .onClick(() => {
            let context = getContext(this);
            let pathDir = context.cacheDir;
            gzgetsDemo(pathDir);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## zip.GzErrorOutputInfo<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name     | Type        | Readable | Writable | Description                                            |
| --------- | ------------ | ---- | ---- | ------------------------------------------------ |
| status    | ReturnStatus | Yes  | No  | Returns the zlib file status code. For details, see the definition of zip.ReturnStatus. |
| statusMsg | string       | Yes  | No  | Status message of the last state that occurs on the zlib file.        |

## zip.OffsetReferencePoint<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.Zlib

| Name    | Value  | Description            |
| -------- | ---- | ---------------- |
| SEEK_SET | 0    | Searches from the beginning of a file. |
| SEEK_CUR | 1    | Search from the current location. |
