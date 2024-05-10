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
