# @ohos.zlib (Zip模块)

本模块提供压缩解压缩文件的能力。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```javascript
import zlib from '@ohos.zlib';
```

## zlib.zipFile<sup>(deprecated)</sup>
zipFile(inFile: string, outFile: string, options: Options): Promise&lt;void&gt;

压缩接口，压缩完成后返回执行结果，使用Promise异步返回。

> **说明：**
>
> 从API version 7 开始支持，从API 9 开始废弃。建议使用[zlib.compressFile](#zlibcompressfile9)。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定压缩的文件夹路径或者文件路径，路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| outFile | string              | 是   | 指定压缩结果的文件路径（文件的扩展名zip）。                  |
| options | [Options](#options) | 是   | 压缩的可选参数。                                             |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回值。 |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';

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

解压文件，解压完成后返回执行结果，使用Promise异步返回。

> **说明：**
>
> 从API version 7 开始支持，从API 9 开始废弃。建议使用[zlib.decompressFile](#zlibdecompressfile9)。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定的待解压缩文件的文件路径，路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| outFile | string              | 是   | 指定的解压文件路径。                                         |
| options | [Options](#options) | 是   | 解压的可选参数。                                             |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回值。 |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';

let inFile = '/xx/xxx.zip';
let outFile = '/xxx';

let options: zlib.Options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};
zlib.unzipFile(inFile, outFile, options).then((data: void) => {
    console.info('unzipFile result is ' + JSON.stringify(data));
}).catch((err: BusinessError)=>{
    console.error('error is ' + JSON.stringify(err));
})
```

## zlib.compressFile<sup>9+</sup>

compressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void

压缩文件，压缩的结果，使用callback异步回调返回。成功返回null，失败返回错误码。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名                  | 类型                | 必填 | 说明                                                         |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | 是   | 指定压缩的文件夹路径或者文件路径，路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。待压缩的文件夹不可为空，否则使用[decompressFile](#zlibdecompressfile9)对压缩后的文件解压时会报错。 |
| outFile                 | string              | 是   | 指定的压缩结果的文件路径。多个线程同时压缩文件时，outFile不能相同。                                           |
| options                 | [Options](#options) | 是   | 压缩的配置参数。                                               |
| callback | AsyncCallback\<void>            | 是   | 异步获取压缩结果之后的回调。成功返回null，失败返回错误码。             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';

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
} catch(errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.compressFile<sup>9+</sup>

compressFile(inFile: string, outFile: string, options: Options): Promise\<void>

压缩文件，压缩的结果，使用Promise异步返回。成功时返回null，失败时返回错误码。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定压缩的文件夹路径或者文件路径，路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。待压缩的文件夹不可为空，否则使用[decompressFile](#zlibdecompressfile9)对压缩后的文件解压时会报错。 |
| outFile | string              | 是   | 指定的压缩结果的文件路径。多个线程同时压缩文件时，outFile不能相同。                                           |
| options | [Options](#options) | 是   | 压缩的配置参数。                                               |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';

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
} catch(errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.decompressFile<sup>9+</sup>

decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void

解压文件，解压的结果，使用callback异步回调返回。成功时返回null，失败时返回错误码。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名                  | 类型                | 必填 | 说明                                                         |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | 是   | 指定的待解压缩文件的文件路径，文件后缀需要以.zip结尾。文件路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| outFile                 | string              | 是   | 指定的解压后的文件夹路径，文件夹目录路径需要在系统中存在，不存在则会解压失败。路径必须为沙箱路径，沙箱路径可以通过context获取，具体方法可参考[application/context（Stage模型）](../apis-ability-kit/js-apis-inner-application-context.md)或 [app/context（FA模型）](../apis-ability-kit/js-apis-inner-app-context.md)。如果待解压的文件或文件夹在解压后的路径下已经存在，则会直接覆盖同名文件或同名文件夹中的同名文件。多个线程同时解压文件时，outFile不能相同。 |
| options                 | [Options](#options) | 是   | 解压的配置参数。                                             |
| callback | AsyncCallback\<void>            | 是   | 异步获取解压结果之后的回调。成功返回null，失败返回错误码。                                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |
| 900003 | The input source file is not ZIP format or damaged. |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';

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
} catch(errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.decompressFile<sup>9+</sup>

decompressFile(inFile: string, outFile: string, options?: Options): Promise\<void>

解压文件，解压的结果，使用Promise异步返回，成功时返回null，失败时返回错误码。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定的待解压缩文件的文件路径，文件后缀需要以.zip结尾。文件路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| outFile | string              | 是   | 指定的解压后的文件夹路径，文件夹目录路径需要在系统中存在，不存在则会解压失败。路径必须为沙箱路径，沙箱路径可以通过context获取，具体方法可参考[application/context（Stage模型）](../apis-ability-kit/js-apis-inner-application-context.md)或 [app/context（FA模型）](../apis-ability-kit/js-apis-inner-app-context.md)。如果待解压的文件或文件夹在解压后的路径下已经存在，则会直接覆盖同名文件或同名文件夹中的同名文件。多个线程同时解压文件时，outFile不能相同。 |
| options | [Options](#options) | 否   | 解压时的配置参数。                                           |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<void> | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| ------ | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001 | The input source file is invalid.      |
| 900002 | The input destination file is invalid. |
| 900003 | The input source file is not ZIP format or damaged. |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';

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
} catch(errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.decompressFile<sup>10+</sup>

decompressFile(inFile: string, outFile: string, callback: AsyncCallback\<void\>): void

解压文件，解压的结果，使用callback异步回调返回。成功时返回null，失败时返回错误码。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名                  | 类型                | 必填 | 说明                                                         |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | 是   | 指定的待解压缩文件的文件路径，文件后缀需要以.zip结尾。文件路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| outFile                 | string              | 是   | 指定的解压后的文件夹路径，文件夹目录路径需要在系统中存在，不存在则会解压失败。路径必须为沙箱路径，沙箱路径可以通过context获取，具体方法可参考[application/context（Stage模型）](../apis-ability-kit/js-apis-inner-application-context.md)或 [app/context（FA模型）](../apis-ability-kit/js-apis-inner-app-context.md)。如果待解压的文件或文件夹在解压后的路径下已经存在，则会直接覆盖同名文件或同名文件夹中的同名文件。多个线程同时解压文件时，outFile不能相同。 |
| callback | AsyncCallback\<void>            | 是   | 异步获取解压结果之后的回调。成功返回null，失败返回错误码。                                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001   | The input source file is invalid.      |
| 900002   | The input destination file is invalid. |
| 900003 | The input source file is not ZIP format or damaged. |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';
let inFile = '/xx/xxx.zip';
let outFileDir = '/xxx';

try {
    zlib.decompressFile(inFile, outFileDir, (errData: BusinessError) => {
        if (errData !== null) {
            console.error(`decompressFile failed. code is ${errData.code}, message is ${errData.message}`);
        }
    })
} catch(errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`decompressFile failed. code is ${code}, message is ${message}`);
}
```

## zlib.getOriginalSize<sup>12+</sup>

getOriginalSize(compressedFile: string): Promise\<number>

获取压缩文件的原始大小，使用Promise异步返回。成功时返回压缩文件的原始大小，失败时返回错误码。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| compressedFile  | string              | 是   | 指定的压缩文件的文件路径，只支持zip格式压缩文件。文件路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](../apis-ability-kit/js-apis-inner-app-context.md)，[Stage模型](../apis-ability-kit/js-apis-inner-application-context.md)。 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise\<number> | Promise对象，返回压缩文件的原始大小，单位字节。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| ------ | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 900001 | The input source file is invalid.      |
| 900003 | The input source file is not ZIP format or damaged. |

**示例：**

```typescript
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/temp，也可以通过context获取。
import zlib from '@ohos.zlib';
import { BusinessError } from '@ohos.base';

let compressedFile = '/data/storage/el2/base/temp/test.zip';

try {
    zlib.getOriginalSize(compressedFile).then((data: number) => {
        console.info(`getOriginalSize success. getOriginalSize: ${data}`);
    }).catch((errData: BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
} catch(errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## zlib.createChecksum<sup>12+</sup>

createChecksum(): Promise&lt;Checksum&gt;

创建校验对象，使用Promise异步返回。成功时返回Checksum对象实例。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                                   | 说明                            |
| -------------------------------------- | ------------------------------- |
| Promise&lt;[Checksum](#checksum12)&gt; | Promise对象。返回校验对象实例。 |

**示例：**

```ts
import zlib from '@ohos.zlib';

zlib.createChecksum().then((data) => {
   console.info('createChecksum success');
})
```

## zlib.createChecksumSync<sup>12+</sup>

createChecksumSync():  Checksum

创建校验对象。成功时返回Checksum对象实例。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                    | 说明           |
| ----------------------- | -------------- |
| [Checksum](#checksum12) | 校验对象实例。 |

**示例：**

```ts
import zlib from '@ohos.zlib';

let checksum = zlib.createChecksumSync()
```

## Checksum<sup>12+</sup>

校验对象。

### adler32<sup>12+</sup>

adler32(adler: number, buf: ArrayBuffer): Promise&lt;number&gt;

计算Adler-32校验和，使用Promise异步返回。成功时返回计算后的Adler-32校验和，失败时返回错误码。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型        | 必填 | 说明                     |
| ------ | ----------- | ---- | ------------------------ |
| adler  | number      | 是   | Adler-32校验和的初始值。 |
| buf    | ArrayBuffer | 是   | 计算校验和数据缓冲区。   |

**返回值：**

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回计算后的Adler-32校验和。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';

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

将两个Adler-32校验和合并，使用Promise异步返回。成功时返回合并后的Adler-32校验和，失败时返回错误码。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型   | 必填 | 说明                                 |
| ------ | ------ | ---- | ------------------------------------ |
| adler1 | number | 是   | 第一个要合并的Adler-32校验和。       |
| adler2 | number | 是   | 第二个要合并的Adler-32校验和。       |
| len2   | number | 是   | 第二个Adler-32校验和的数据块的长度。 |

**返回值：**

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回合并后的Adler-32校验和。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### crc32<sup>12+</sup>

crc32(crc: number, buf: ArrayBuffer): Promise&lt;number&gt;

更新CRC-32校验，使用Promise异步返回。成功时返回更新后的CRC-32校验，失败时返回错误码。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型        | 必填 | 说明                 |
| ------ | ----------- | ---- | -------------------- |
| crc    | number      | 是   | CRC-32校验的初始值。 |
| buf    | ArrayBuffer | 是   | 计算校验数据缓冲区。 |

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回更新后的CRC-32校验。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(12);
let data = new Uint8Array(arrayBufferIn);
for (let i = 0, j = str.length; i < j; i++) {
    data[i] = str.charCodeAt(i);
}
let checksum = zlib.createChecksumSync()
checksum.crc32(0, arrayBufferIn).then((data) => {
    console.info('crc32 success', data);
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### crc32Combine<sup>12+</sup>

crc32Combine(crc1: number, crc2: number, len2: number): Promise&lt;number&gt;

将两个CRC-32校验合并，使用Promise异步返回。成功时返回合并后的CRC-32校验，失败时返回错误码。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型   | 必填 | 说明                             |
| ------ | ------ | ---- | -------------------------------- |
| adler1 | number | 是   | 第一个要合并的CRC-32校验。       |
| adler2 | number | 是   | 第二个要合并的CRC-32校验。       |
| len2   | number | 是   | 第二个CRC-32校验的数据块的长度。 |

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回合并后的CRC-32校验。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### crc64<sup>12+</sup>

crc64(crc: number, buf: ArrayBuffer): Promise&lt;number&gt;

更新CRC-64校验，使用Promise异步返回。成功时返回更新后的CRC-64校验，失败时返回错误码。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型        | 必填 | 说明                 |
| ------ | ----------- | ---- | -------------------- |
| crc    | number      | 是   | CRC-64校验的初始值。 |
| buf    | ArrayBuffer | 是   | 计算校验数据缓冲区。 |

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回更新后的CRC-64校验。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(12);
let data = new Uint8Array(arrayBufferIn);
for (let i = 0, j = str.length; i < j; i++) {
    data[i] = str.charCodeAt(i);
}
let checksum = zlib.createChecksumSync()
checksum.crc64(0, arrayBufferIn).then((data) => {
    console.info('crc64 success', data);
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### getCrcTable<sup>12+</sup>

getCrcTable(): Promise&lt;Array&lt;number&gt;&gt;

输出CRC-32校验表，使用Promise异步返回。成功时返回CRC-32校验表。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                               | 说明                            |
| ---------------------------------- | ------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象。返回CRC-32校验表。 |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let checksum = zlib.createChecksumSync()
checksum.getCrcTable().then((data) => {
    console.info('getCrcTable success');
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### getCrc64Table<sup>12+</sup>

getCrc64Table(): Promise&lt;Array&lt;number&gt;&gt;

输出CRC-64校验表，使用Promise异步返回。成功时返回CRC-64校验表。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                               | 说明                            |
| ---------------------------------- | ------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象。返回CRC-64校验表。 |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let checksum = zlib.createChecksumSync()
checksum.getCrc64Table().then((data) => {
    console.info('getCrc64Table success');
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

## zlib.createZip12+

createZip(): Promise&lt;Zip&gt;

创建压缩解压缩对象实例，使用Promise异步返回，成功时返回压缩解压缩对象实例。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                         | 说明                                  |
| ---------------------------- | ------------------------------------- |
| Promise&lt;[Zip](#zip12)&gt; | Promise对象。返回压缩解压缩对象实例。 |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let zip = zlib.createZipSync();
zlib.createZip().then(data => {
    console.info('createZip success');
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

## zlib.createZipSync12+

createZipSync(): Zip

创建压缩解压缩对象实例，成功时返回压缩解压缩对象实例。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型          | 说明                     |
| ------------- | ------------------------ |
| [Zip](#zip12) | 返回压缩解压缩对象实例。 |

**示例：**

```ts
import zlib from '@ohos.zlib';

let zip = zlib.createZipSync();
```

## Zip12+

压缩解压缩对象实例。

### getZStream12+

getZStream(): Promise&lt;ZStream&gt;

输出流，使用Promise异步返回。成功时返回zlib流。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| Promise&lt;[ZStream](#zstream12)&gt; | Promise对象。返回zlib流。 |

**示例：**

```ts
import zlib from '@ohos.zlib';

let zip = zlib.createZipSync();
zip.getZStream().then(data => {
    console.info('getZStream success');
})
```

### zlibVersion12+

zlibVersion(): Promise&lt;string&gt;

获取当前链接的zlib库的版本信息，使用Promise异步返回。成功时返回当前zlib库的版本信息。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | --------------------------------------- |
| Promise&lt;string&gt; | Promise对象。返回当前zlib库的版本信息。 |

**示例：**

```ts
import zlib from '@ohos.zlib';

let zip = zlib.createZipSync();
zip.zlibVersion().then((data) => {
    console.info('zlibVersion success')
})
```

### zlibCompileFlags12+

zlibCompileFlags(): Promise&lt;number&gt;

返回指示编译时选项的标志，使用Promise异步返回。成功时返回指示编译时选项的标志。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回指示编译时选项的标志。 |

**示例：**

```ts
import zlib from '@ohos.zlib';

let zip = zlib.createZipSync();
zip.zlibCompileFlags().then((data) => {
    console.info('zlibCompileFlags success')
})
```

### compress12+

compress(dest: ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt;

将源缓冲区压缩到目标缓冲区，使用Promise异步返回。成功时返回结果状态和目标缓冲区的总大小。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名    | 类型        | 必填 | 说明           |
| --------- | ----------- | ---- | -------------- |
| dest      | ArrayBuffer | 是   | 目标缓冲区。   |
| source    | ArrayBuffer | 是   | 源数据缓冲区。 |
| sourceLen | number      | 否   | 源数据长度。   |

**返回值：**

| 类型                                             | 说明                                            |
| ------------------------------------------------ | ----------------------------------------------- |
| Promise&lt;[ZipOutputInfo](#zipoutputinfo12)&gt; | Promise对象。返回结果状态和目标缓冲区的总大小。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800007 | Buffer error.                                                |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### compress212+

compress2(dest: ArrayBuffer, source: ArrayBuffer, level: CompressLevel, sourceLen?: number,): Promise&lt;ZipOutputInfo&gt;

将源缓冲区压缩到目标缓冲区，使用Promise异步返回。成功时返回结果状态和目标缓冲区的总大小。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名    | 类型          | 必填 | 说明                                                 |
| --------- | ------------- | ---- | ---------------------------------------------------- |
| dest      | ArrayBuffer   | 是   | 目标缓冲区。                                         |
| source    | ArrayBuffer   | 是   | 源数据缓冲区。                                       |
| level     | CompressLevel | 是   | 参考[zip.CompressLevel枚举定义](#zipcompresslevel)。 |
| sourceLen | number        | 否   | 源数据长度。                                         |

**返回值：**

| 类型                                             | 说明                                            |
| ------------------------------------------------ | ----------------------------------------------- |
| Promise&lt;[ZipOutputInfo](#zipoutputinfo12)&gt; | Promise对象。返回结果状态和目标缓冲区的总大小。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800007 | Buffer error.                                                |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### uncompress12+

uncompress(dest:ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt;

将压缩后的数据解压缩为原始的未压缩形式，使用Promise异步返回。成功时返回结果状态和目标缓冲区的总大小。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名    | 类型        | 必填 | 说明           |
| --------- | ----------- | ---- | -------------- |
| dest      | ArrayBuffer | 是   | 目标缓冲区。   |
| source    | ArrayBuffer | 是   | 源数据缓冲区。 |
| sourceLen | number      | 否   | 源数据长度。   |

**返回值：**

| 类型                                             | 说明                                            |
| ------------------------------------------------ | ----------------------------------------------- |
| Promise&lt;[ZipOutputInfo](#zipoutputinfo12)&gt; | Promise对象。返回结果状态和目标缓冲区的总大小。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800005 | Data error.                                                  |
| 17800007 | Buffer error.                                                |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.uncompress(arrayBufferIn, arrayBufferOut, 20).then((data) => {
        console.info('uncompress success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### uncompress212+

uncompress2(dest: ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;DecompressionOutputInfo&gt;

将压缩后的数据解压缩为原始的未压缩形式，使用Promise异步返回。成功时返回结果状态、目标缓冲区的总大小和源数据长度。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名    | 类型        | 必填 | 说明           |
| --------- | ----------- | ---- | -------------- |
| dest      | ArrayBuffer | 是   | 目标缓冲区。   |
| source    | ArrayBuffer | 是   | 源数据缓冲区。 |
| sourceLen | number      | 否   | 源数据长度。   |

**返回值：**

| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| Promise&lt;[DecompressionOutputInfo](#decompressionoutputinfo12)&gt; | Promise对象。返回结果状态、目标缓冲区的总大小和源数据长度。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800005 | Data error.                                                  |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.uncompress2(arrayBufferIn, arrayBufferOut, 20).then((data) => {
        console.info('uncompress2 success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### compressBound12+

compressBound(sourceLen: number): Promise&lt;number&gt;

计算返回压缩大小的上限，使用Promise异步返回。成功时返回压缩大小的上限。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名    | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ------------ |
| sourceLen | number | 是   | 源数据长度。 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回压缩大小的上限。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);
for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
}
let zip = zlib.createZipSync();
zip.compressBound(str.length).then((data) => {
    console.info('compressBound success')
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### inflateValidate12+

inflateValidate(strm: ZStream, check: number): Promise&lt;ReturnStatus&gt;

验证压缩流结构内部的校验和，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |
| check  | number  | 是   | 预期的校验和。                  |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateValidate({availableIn: 1}, 1).then(data => {
        console.info('inflateValidate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateUndermine12+

inflateUndermine(strm: ZStream, subvert: number): Promise&lt;ReturnStatus&gt;

验证压缩流结构内部的校验和，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型    | 必填 | 说明                            |
| ------- | ------- | ---- | ------------------------------- |
| strm    | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |
| subvert | number  | 是   | 是否破坏内部的标志。            |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800005 | Data error                                                   |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateUndermine({availableOut: 1}, 5).then(data => {
        console.info('inflateUndermine success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateSyncPoint12+

inflateSyncPoint(strm: ZStream): Promise&lt;ReturnStatus&gt;

查找当前解压缩流的同步点，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateSyncPoint({availableIn: 1}).then(data => {
        console.info('inflateSyncPoint success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateSync12+

inflateSync(strm: ZStream): Promise&lt;ReturnStatus&gt;

跳过无效的压缩数据，直到找到一个可能的完整刷新点为止，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800005 | Data error.                                                  |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.deflate({nextIn: arrayBufferIn, availableIn: 3, nextOut: arrayBufferOut, availableOut: 100}, zlib.CompressFlushMode.FULL_FLUSH).then((data) => {
        console.info('deflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.deflate({ availableIn: 11}, zlib.CompressFlushMode.FINISH).then((data) => {
        console.info('deflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.deflateEnd({}).then(data => {
        console.info('deflateEnd success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    try {
        await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 2}).then(data => {
            console.info('inflateInit2 success')
        })
    } catch (errData) {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    }
    await zip.inflate({nextOut: arrayBufferIn, availableOut: 28}, zlib.CompressFlushMode.NO_FLUSH).then((data) => {
        console.info('inflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateSync({availableIn: 26}).then(data => {
        console.info('inflateSync success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateEnd({nextOut: arrayBufferOut}).then((data) => {
        console.info('inflateEnd success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateResetKeep12+

inflateResetKeep(strm: ZStream): Promise&lt;ReturnStatus&gt;

重置解压缩流的状态，以保留分配的霍夫曼解码树和预设字典，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateResetKeep({availableIn: 1}).then(data => {
        console.info('inflateResetKeep success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateSetDictionary12+

inflateSetDictionary(strm: ZStream, dictionary: ArrayBuffer): Promise&lt;ReturnStatus&gt;

从给定的未压缩字节序列初始化解压缩字典，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名     | 类型        | 必填 | 说明                            |
| ---------- | ----------- | ---- | ------------------------------- |
| strm       | ZStream     | 是   | 参考[ZStream定义](#zstream12)。 |
| dictionary | ArrayBuffer | 是   | 字典数据。                      |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    await zip.deflateSetDictionary({}, dictionarybuf).then((data) => {
        console.info('deflateSetDictionary success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    await zip.deflate({nextIn: arrayBufferIn, availableIn: 14, nextOut: arrayBufferOut, availableOut: 100}, zlib.CompressFlushMode.FINISH).then((data) => {
        console.info('deflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    await zip.deflateEnd({}).then(data => {
        console.info('deflateEnd success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    try {
        await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 100}).then(data => {
            console.info('inflateInit success')
        })
    } catch (errData) {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    }
    await zip.inflate({nextOut: arrayBufferIn, availableOut: 28}, zlib.CompressFlushMode.NO_FLUSH).then((data) => {
        console.info('inflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    await zip.inflateSetDictionary({}, dictionarybuf).then((data) => {
        console.info('inflateSetDictionary success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    await zip.inflateEnd({nextOut: arrayBufferOut}).then((data) => {
        console.info('inflateEnd success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
}
```

### inflateReset212+

inflateReset2(strm: ZStream, windowBits: number): Promise&lt;ReturnStatus&gt;

从给定的未压缩字节序列初始化解压缩字典，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名     | 类型    | 必填 | 说明                            |
| ---------- | ------- | ---- | ------------------------------- |
| strm       | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |
| windowBits | number  | 是   | 最大窗口大小的以2为底的对数。   |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateReset2({availableOut: 8}, 15).then(data => {
        console.info('inflateReset2 success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateReset12+

inflateReset(strm: ZStream): Promise&lt;ReturnStatus&gt;

这个函数相当于先调用inflateEnd再调用inflateInit，但是并不会释放和重新分配内部解压缩状态，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateReset({availableIn: 1, availableOut: 8}).then(data => {
        console.info('inflateReset success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflatePrime12+

inflatePrime(strm: ZStream, bits: number, value: number): Promise&lt;ReturnStatus&gt;

从给定的未压缩字节序列初始化解压缩字典，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |
| bits   | number  | 是   | 提供的位。                      |
| value  | number  | 是   | 提供的值。                      |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflatePrime({nextOut: arrayBufferOut}, 5, 2).then(data => {
        console.info('inflatePrime success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateMark12+

inflateMark(strm: ZStream): Promise&lt;number&gt;

用于标记输入数据中的位置以供随机访问，使用Promise异步返回。成功时返回位置信息。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                  | 说明                        |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise对象。返回位置信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateMark({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}).then(data => {
        console.info('inflateMark success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateInit212+

inflateInit2(strm: ZStream, windowBits: number): Promise&lt;ReturnStatus&gt;

初始化内部流状态以进行解压缩，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名     | 类型    | 必填 | 说明                            |
| ---------- | ------- | ---- | ------------------------------- |
| strm       | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |
| windowBits | number  | 是   | 最大窗口大小的以2为底的对数。   |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);
for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
}
let arrayBufferOut = new ArrayBuffer(100);
let zip = zlib.createZipSync();
zip.inflateInit2({nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}, 28
).then(data => {
    console.info('inflateInit2 success');
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### inflateInit12+

inflateInit(strm: ZStream): Promise&lt;ReturnStatus&gt;

初始化内部流状态以进行解压缩，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

let str = 'hello world!';
let arrayBufferIn = new ArrayBuffer(str.length);
let byteArray = new Uint8Array(arrayBufferIn);
for (let i = 0, j = str.length; i < j; i++) {
    byteArray[i] = str.charCodeAt(i)
}
let arrayBufferOut = new ArrayBuffer(100);
let zip = zlib.createZipSync();
zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
).then(data => {
    console.info('inflateInit success');
}).catch((errData: base.BusinessError) => {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
})
```

### inflateGetHeader12+

inflateGetHeader(strm: ZStream, header: GzHeader): Promise&lt;ReturnStatus&gt;

用于在解压缩数据前设置gzip文件头部信息，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型                    | 必填 | 说明                             |
| ------ | ----------------------- | ---- | -------------------------------- |
| strm   | ZStream                 | 是   | 参考[ZStream定义](#zstream12)。  |
| header | [GzHeader](#gzheader12) | 是   | 从压缩数据流中提取的gzip头信息。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit2({nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}, 28
    ).then(data => {
        console.info('inflateInit2 success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateGetHeader({availableIn: 1, availableOut: 1},{isText: true, os: 1, time: 1, xflags: 1, extra: arrayBufferIn, extraLen: 12, name: arrayBufferIn, comment: arrayBufferOut, hcrc: true, done: true}).then(data => {
        console.info('inflateGetHeader success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateGetDictionary12+

inflateGetDictionary(strm: ZStream, dictionary: ArrayBuffer): Promise&lt;DictionaryOutputInfo&gt;

获取当前解压缩流中使用的解压缩字典内容及其长度，使用Promise异步返回。成功时返回结果状态和字典的长度。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名     | 类型        | 必填 | 说明                            |
| ---------- | ----------- | ---- | ------------------------------- |
| strm       | ZStream     | 是   | 参考[ZStream定义](#zstream12)。 |
| dictionary | ArrayBuffer | 是   | 接收解压缩字典的实际内容。      |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[DictionaryOutputInfo](#dictionaryoutputinfo12)&gt; | Promise对象。返回结果状态和字典的长度。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit2({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}, 28
    ).then(data => {
        console.info('inflateInit2 success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateGetDictionary({nextOut: arrayBufferOut}, arrayBufferOut).then((data) => {
        console.info('inflateGetDictionary success:')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateEnd12+

inflateEnd(strm: ZStream): Promise&lt;ReturnStatus&gt;

解压流的所有动态分配的数据结构都被释放，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflate({availableIn: 8, availableOut: 8}, 0).then((data) => {
        console.info('inflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateEnd({nextOut: arrayBufferOut}).then((data) => {
        console.info('inflateEnd success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateCopy12+

inflateCopy(source: Zip): Promise&lt;Zip&gt;

复制解压流，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型 | 必填 | 说明                    |
| ------ | ---- | ---- | ----------------------- |
| source | Zip  | 是   | 参考[Zip定义](#zip12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateCopy(zip).then((data) => {
        console.info('inflateCopy success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateCodesUsed12+

inflateCodesUsed(strm: ZStream): Promise&lt;number&gt;

当前解压缩流中使用的霍夫曼编码树的数量，使用Promise异步返回。成功时返回已使用的霍夫曼编码树的数量。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                  | 说明                                          |
| --------------------- | --------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回已使用的霍夫曼编码树的数量。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let str = 'hello world!';
    let arrayBufferIn = new ArrayBuffer(str.length);
    let byteArray = new Uint8Array(arrayBufferIn);
    for (let i = 0, j = str.length; i < j; i++) {
        byteArray[i] = str.charCodeAt(i)
    }
    let arrayBufferOut = new ArrayBuffer(100);
    let zip = zlib.createZipSync();
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateCodesUsed({nextIn: arrayBufferIn, availableIn: 1, nextOut: arrayBufferOut, availableOut: 8}).then(data => {
        console.info('inflateCodesUsed success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

### inflateBackInit12+

inflateBackInit(strm: ZStream, windowBits: number, window: ArrayBuffer): Promise&lt;ReturnStatus&gt;

使用inflateBack()函数前初始化内部流状态以进行解压缩，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名     | 类型        | 必填 | 说明                            |
| ---------- | ----------- | ---- | ------------------------------- |
| strm       | ZStream     | 是   | 参考[ZStream定义](#zstream12)。 |
| windowBits | number      | 是   | 最大窗口大小的以2为底的对数。   |
| window     | ArrayBuffer | 是   | 预设的窗口缓冲区。              |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |

**示例：**参考[inflateBack](#inflateback12)

### inflateBackEnd12+

inflateBackEnd(strm: ZStream): Promise&lt;ReturnStatus&gt;

inflateBackInit()函数分配的所有内存都被释放，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型    | 必填 | 说明                            |
| ------ | ------- | ---- | ------------------------------- |
| strm   | ZStream | 是   | 参考[ZStream定义](#zstream12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**参考[inflateBack](#inflateback12)

### inflateBack12+

inflateBack(strm: ZStream, backIn: InflateBackInputCallback, inDesc: object, backOut: InflateBackOutputCallback, outDesc: object): Promise&lt;ReturnStatus&gt;

实现原始解压缩，采用回调接口来处理输入和输出，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                      | 必填 | 说明                                                         |
| ------- | ------------------------- | ---- | ------------------------------------------------------------ |
| strm    | ZStream                   | 是   | 参考[ZStream定义](#zstream12)。                              |
| backIn  | InflateBackInputCallback  | 是   | 参考[InflateBackInputCallback定义](#inflatebackinputcallback12)。 |
| inDesc  | object                    | 是   | 通用对象。                                                   |
| backOut | InflateBackOutputCallback | 是   | 参考[InflateBackOutputCallback定义](#inflatebackoutputcallback12)。 |
| outDesc | object                    | 是   | 通用对象。                                                   |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

async function demo() {
    let readIn:(inDesc:object) => ArrayBuffer = (inDesc:object): ArrayBuffer => {
        console.info("inDesc = ", JSON.stringify(inDesc));
        let buffer = new ArrayBuffer(26)
        let array = new Uint8Array(buffer);
        array.set([31,139,8,0,0,0,0,0,0,10,243,72,205,201,201,231,2,0,22,53,150,49,6,0,0,0]);
        return buffer;
    }

    let writeOut:(outDesc: object, buffer: ArrayBuffer, length: number) => number = (outDesc: object, buffer: ArrayBuffer, length: number): number => {
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
    let arrayBuffer =  new ArrayBuffer(26);
    let next = new Uint8Array(arrayBuffer);
    let last = 0;
    let index = 0;
    let flags = 0;
    let NEXT2:() => number = (): number => {
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

    let inflateBackTest:() => void = ( async() => {
        try {
            have = 0;
            first = 1;
            arrayBuffer =  new ArrayBuffer(26);
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
            for (;;) {
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
                for (let i = 0 ; i < have; i++) {
                    newNext[i] = next[26-have+i];
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
                    {fileName:'test.gz'},
                    writeOut,
                    {fileName:'test.gz'}).then((result) => {
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
        catch(errData) {
            console.error(`errData is message:${errData}`);
        }
    })
    inflateBackTest();
}
```

### inflate12+

inflate(strm: ZStream, flush: CompressFlushMode): Promise&lt;ReturnStatus&gt;

解压数据，使用Promise异步返回。成功时返回结果状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名 | 类型              | 必填 | 说明                                                   |
| ------ | ----------------- | ---- | ------------------------------------------------------ |
| strm   | ZStream           | 是   | 参考[ZStream定义](#zstream12)。                        |
| flush  | CompressFlushMode | 是   | 参考[CompressFlushMode定义](#zipcompressflushmode12)。 |

**返回值：**

| 类型                                              | 说明                        |
| ------------------------------------------------- | --------------------------- |
| Promise&lt;[ReturnStatus](#zipreturnstatus12)&gt; | Promise对象。返回结果状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.zlib错误码](./errorcode-zlib.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed. Possible causes: <br />1. Mandatory parameters are left unspecified;<br />2. Incorrect parameter types;<br />3. Parameter verification failed. |
| 17800004 | ZStream error.                                               |
| 17800005 | Data error.                                                  |

**示例：**

```ts
import zlib from '@ohos.zlib';
import base from '@ohos.base';

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
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    await zip.deflate({availableOut: 8}, zlib.CompressFlushMode.FINISH).then((data) => {
        console.info('deflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`)
    })
    await zip.deflateEnd({ nextOut: arrayBufferOut }).then(data => {
        console.info('deflateEnd success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateInit({nextIn: arrayBufferOut, availableIn: 1, nextOut: arrayBufferOut, availableOut: 1}
    ).then(data => {
        console.info('inflateInit success');
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflate({availableIn: 8, availableOut: 8}, 0).then((data) => {
        console.info('inflate success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
    await zip.inflateEnd({nextOut: arrayBufferOut}).then((data) => {
        console.info('inflateEnd success')
    }).catch((errData: base.BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
}
```

## Options

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称     | 类型             | 可读 | 可写 | 说明                                                       |
| -------- | ---------------- | ---- | ---- | ---------------------------------------------------------- |
| level    | CompressLevel     | 是   | 否   | 参考[zip.CompressLevel枚举定义](#zipcompresslevel)。       |
| memLevel | MemLevel         | 是   | 否   | 参考[zip.MemLevel枚举定义](#zipmemlevel)。                 |
| strategy | CompressStrategy | 是   | 否   | 参考[zip.CompressStrategy枚举定义](#zipcompressstrategy)。 |

## zip.CompressLevel

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称                               | 值   | 说明              |
| ---------------------------------- | ---- | ----------------- |
| COMPRESS_LEVEL_NO_COMPRESSION      | 0    | 压缩率为0压缩等级。 |
| COMPRESS_LEVEL_BEST_SPEED          | 1    | 最佳速度压缩等级。  |
| COMPRESS_LEVEL_BEST_COMPRESSION    | 9    | 最佳压缩等级。      |
| COMPRESS_LEVEL_DEFAULT_COMPRESSION | -1   | 默认压缩等级。      |

## zip.MemLevel

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称              | 值   | 说明                             |
| ----------------- | ---- | -------------------------------- |
| MEM_LEVEL_MIN     | 1    | zip 接口在压缩过程中最小使用内存。 |
| MEM_LEVEL_MAX     | 9    | zip 接口在压缩过程中最大使用内存。 |
| MEM_LEVEL_DEFAULT | 8    | zip 接口在压缩过程中默认使用内存。 |

## zip.CompressStrategy

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称                               | 值   | 说明                     |
| ---------------------------------- | ---- | ------------------------ |
| COMPRESS_STRATEGY_DEFAULT_STRATEGY | 0    | 常规数据策略。             |
| COMPRESS_STRATEGY_FILTERED         | 1    | 过滤器产生的数据压缩策略。 |
| COMPRESS_STRATEGY_HUFFMAN_ONLY     | 2    | 霍夫曼编码格式压缩策略。   |
| COMPRESS_STRATEGY_RLE              | 3    | 游标编码压缩策略。         |
| COMPRESS_STRATEGY_FIXED            | 4    | 固定的压缩策略。           |

## zip.ErrorCode

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称             | 值   | 说明         |
| ---------------- | ---- | ------------ |
| ERROR_CODE_OK    | 0    | 函数调用成功。 |
| ERROR_CODE_ERRNO | -1   | 函数调用失败。 |

## zip.CompressFlushMode<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称          | 值   | 说明                                         |
| ------------- | ---- | -------------------------------------------- |
| NO_FLUSH      | 0    | 默认值，表示正常操作。                       |
| PARTIAL_FLUSH | 1    | 在流中生成部分刷新点。                       |
| SYNC_FLUSH    | 2    | 在保持压缩流状态的同时强制输出所有压缩数据。 |
| FULL_FLUSH    | 3    | 重置压缩状态。                               |
| FINISH        | 4    | 压缩或解压缩过程结束。                       |
| BLOCK         | 5    | 允许更精确的控制。                           |
| TREES         | 6    | 实施过程中有特殊目的。                       |

## zip.CompressMethod<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称     | 值   | 说明       |
| -------- | ---- | ---------- |
| DEFLATED | 8    | 压缩方法。 |

## zip.ReturnStatus<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称       | 值   | 说明                                           |
| ---------- | ---- | ---------------------------------------------- |
| OK         | 0    | 函数调用成功。                                 |
| STREAM_END | 1    | 函数调用成功，表示已处理了整个数据。           |
| NEED_DICT  | 2    | 函数调用成功，表示需要预设字典才能继续解压缩。 |

## ZStream<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称         | 类型        | 可读 | 可写 | 说明                                                         |
| ------------ | ----------- | ---- | ---- | ------------------------------------------------------------ |
| nextIn       | ArrayBuffer | 是   | 否   | 需要压缩的输入字节                                           |
| availableIn  | number      | 是   | 否   | nextIn可用的字节数                                           |
| totalIn      | number      | 是   | 否   | 到目前为止读取的输入字节总数                                 |
| nextOut      | ArrayBuffer | 是   | 否   | 压缩后的输出字节                                             |
| availableOut | number      | 是   | 否   | nextOut的剩余可用字节数                                      |
| totalOut     | number      | 是   | 否   | 到目前为止输出字节总数                                       |
| dataType     | number      | 是   | 否   | 关于数据类型的最佳猜测：deflate的二进制或文本，或inflate的解码状态 |
| adler        | number      | 是   | 否   | 未压缩数据的Adler-32或CRC-32值                               |

## ZipOutputInfo<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称    | 类型         | 可读 | 可写 | 说明                                                  |
| ------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status  | ReturnStatus | 是   | 否   | 参考[zlib.ReturnStatus枚举定义](#zipreturnstatus12)。 |
| destLen | number       | 是   | 否   | 目标缓冲区的总长度。                                  |

## DictionaryOutputInfo<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称             | 类型         | 可读 | 可写 | 说明                                                  |
| ---------------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status           | ReturnStatus | 是   | 否   | 参考[zlib.ReturnStatus枚举定义](#zipreturnstatus12)。 |
| dictionaryLength | number       | 是   | 否   | 字典的长度。                                          |

## DecompressionOutputInfo<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称             | 类型         | 可读 | 可写 | 说明                                                  |
| ---------------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status           | ReturnStatus | 是   | 否   | 参考[zlib.ReturnStatus枚举定义](#zipreturnstatus12)。 |
| dictionaryLength | number       | 是   | 否   | 字典的长度。                                          |

## DeflatePendingOutputInfo<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称    | 类型         | 可读 | 可写 | 说明                                                  |
| ------- | ------------ | ---- | ---- | ----------------------------------------------------- |
| status  | ReturnStatus | 是   | 否   | 参考[zlib.ReturnStatus枚举定义](#zipreturnstatus12)。 |
| pending | number       | 是   | 否   | 已生成的输出字节数。                                  |
| bits    | number       | 是   | 否   | 已生成的输出位数。                                    |

## GzHeader<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称     | 类型        | 可读 | 可写 | 说明                                 |
| -------- | ----------- | ---- | ---- | ------------------------------------ |
| text     | boolean     | 是   | 否   | 如果压缩数据被认为是文本，则为True。 |
| os       | number      | 是   | 否   | 操作系统。                           |
| time     | number      | 是   | 否   | 修改时间。                           |
| xflags   | number      | 是   | 否   | 额外标志。                           |
| extra    | ArrayBuffer | 是   | 否   | 额外字段。                           |
| extraLen | number      | 是   | 否   | 额外字段的长度。                     |
| name     | ArrayBuffer | 是   | 否   | 文件名。                             |
| comment  | ArrayBuffer | 是   | 否   | 注释。                               |
| hcrc     | boolean     | 是   | 否   | 如果存在crc标头，则为True。          |
| done     | boolean     | 是   | 否   | 读取gzip标头后为True。               |

## InflateBackInputCallback<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称         | 类型   | 可读 | 可写 | 说明                 |
| ------------ | ------ | ---- | ---- | -------------------- |
| inDesc       | object | 是   | 否   | 用户定义数据对象     |
| destLength   | number | 是   | 否   | 目标缓冲区的总长度。 |
| sourceLength | number | 是   | 否   | 源数据缓冲区长度。   |

## InflateBackOutputCallback<sup>12+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称         | 类型   | 可读 | 可写 | 说明                 |
| ------------ | ------ | ---- | ---- | -------------------- |
| inDesc       | object | 是   | 否   | 用户定义数据对象     |
| destLength   | number | 是   | 否   | 目标缓冲区的总长度。 |
| sourceLength | number | 是   | 否   | 源数据缓冲区长度。   |