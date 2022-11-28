# Zip模块(JS端SDK接口)

本模块提供压缩解压缩文件的能力

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```javascript
import zlib from '@ohos.zlib';
```

## zlib.zipFile<sup>(deprecated)</sup>
zipFile(inFile: string, outFile: string, options: Options): Promise&lt;void&gt;

压缩接口（Promise形式）。

> 从api9开始不再维护，建议使用[zlib.compressFile](#zlibcompressfile9)

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定压缩的文件夹路径或者文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[Stage模型](js-apis-application-context.md)。 |
| outFile | string              | 是   | 指定压缩结果的文件路径（文件的扩展名zip）。                  |
| options | [Options](#options) | 是   | 压缩的可选参数。                                             |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | [ERROR_CODE_OK](#ziperrorcode)：压缩成功；<br />[ERROR_CODE_ERRNO](#ziperrorcode)：压缩失败。 |

**示例1：**

```typescript
//【压缩文件 例子1】
import zlib from '@ohos.zlib';
let inFile = '/xxx/filename.xxx';
let outFile = '/xxx/xxx.zip';
let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.zipFile(inFile, outFile, options).then((data) => {
    console.log('zipFile result is ' + JSON.Stringify(data));
}).catch((err) => {
    console.log('error is ' + JSON.Stringify(err));
});
```

**示例2：**

```typescript
// 【压缩文件夹 例子2】
import zlib from '@ohos.zlib';
let inFile = '/xxx/xxx';
let outFile = '/xxx/xxx.zip';
let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.zipFile(inFile , outFile, options).then((data) => {
    console.log('zipFile result is ' + JSON.Stringify(data));
}).catch((err)=>{
    console.log('error is ' + JSON.Stringify(err));
});
```

## zlib.unzipFile<sup>(deprecated)</sup>

unzipFile(inFile:string, outFile:string, options: Options): Promise&lt;void&gt;

解压文件，解压完成返回执行结果（Promise形式）。

> 从api9开始不再看护，建议使用[zlib.decompressFile](#zlibdecompressfile9)

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定压缩的文件夹路径或者文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[stage模型](js-apis-application-context.md)。 |
| outFile | string              | 是   | 指定的解压文件路径。                                         |
| options | [Options](#options) | 是   | 解压的可选参数。                                             |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | [ERROR_CODE_OK](#ziperrorcode)：解压成功；<br />[ERROR_CODE_ERRNO](#ziperrorcode)：解压失败返回执行结果。 |

**示例：**

```typescript
// 【解压缩 例子1】
import zlib from '@ohos.zlib';
let inFile = '/xx/xxx.zip';
let outFile = '/xxx';

let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};
zlib.unzipFile(inFile, outFile, options).then((data) => {
    console.log('unzipFile result is ' + JSON.Stringify(data));
}).catch((err)=>{
    console.log('error is ' + JSON.Stringify(err));
})
```

## zlib.compressFile<sup>9+</sup>

compressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;

压缩文件，压缩的结果通过callback返回。成功时返回null，失败时返回错误码ID。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名                  | 类型                | 必填 | 说明                                                         |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | 是   | 指定压缩的文件夹路径或者文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[stage模型](js-apis-application-context.md)。 |
| outFile                 | string              | 是   | 指定的解压文件路径。                                           |
| options                 | [Options](#options) | 是   | 压缩的配置参数。                                               |
| AsyncCallback<**void**> | callback            | 否   | 压缩时的回调函数。                                             |

**相关错误码**

以下错误码的详细介绍请参见[ohos.zlib错误码](../errorcodes/errorcode-zlib.md)。
| 错误码ID | 错误信息                               |
| -------- | --------------------------------------|
| 900001   | The Input source file is invalid.      |
| 900002   | The Input destination file is invalid. |

**示例**

```typescript
// 【压缩文件 例子1】
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取
import zlib from '@ohos.zlib';
let inFile = '/xxx/filename.xxx';
let outFile = '/xxx/xxx.zip';
let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

try {
    zlib.compressFile(inFile, outFile, options, (errData) => {
        if (errData !== null) {
            console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
        }
    })
} catch(errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

compressFile(inFile: string, outFile: string, options: Options): Promise\<void>;

压缩文件，压缩的结果通过promise返回，成功时返回null，失败时返回错误码。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定压缩的文件夹路径或者文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[stage模型](js-apis-application-context.md)。 |
| outFile | string              | 是   | 指定的解压文件路径。                                           |
| options | [Options](#options) | 是   | 压缩的配置参数。                                               |

**相关错误码**

以下错误码的详细介绍请参见[ohos.zlib错误码](../errorcodes/errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| -------- | ------------------------------------- |
| 900001   | The Input source file is invalid.      |
| 900002   | The Input destination file is invalid. |

```typescript
// 【压缩文件 例子2】
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取
import zlib from '@ohos.zlib';
let inFile = '/xxx/filename.xxx';
let outFile = '/xxx/xxx.zip';
let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

try {
    zlib.compressFile(inFile, outFile, options).then((data) => {
        console.info('compressFile success');
    }).catch((errData) => {
        console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
} catch(errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```



## zlib.decompressFile<sup>9+</sup>

decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void;

解压文件，解压的结果通过callback返回，成功时返回null，失败时返回错误码。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名                  | 类型                | 必填 | 说明                                                         |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile                  | string              | 是   | 指定的待解压缩文件的文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[stage模型](js-apis-application-context.md)。 |
| outFile                 | string              | 是   | 指定的解压后的目录路径。                                       |
| options                 | [Options](#options) | 是   | 解压的配置参数。                                               |
| AsyncCallback<**void**> | callback            | 否   | 解压是的回调函数。                                             |

**相关错误码**

以下错误码的详细介绍请参见[ohos.zlib错误码](../errorcodes/errorcode-zlib.md)。

| 错误码ID | 错误信息
| -------- | --------------------------------------|
| 900001   | The Input source file is invalid.      |
| 900002   | The Input destination file is invalid. |

**示例**

```typescript
// 【解压缩 例子1】
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取
import zlib from '@ohos.zlib';
let inFile = '/xx/xxx.zip';
let outFile = '/xxx';
let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

try {
    zlib.decompressFile(inFile, outFile, options, (errData) => {
        if (errData !== null) {
            console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
        }
    })
} catch(errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

decompressFile(inFile: string, outFile: string, options: Options): Promise\<void>;

解压文件，解压的结果通过promise返回，成功时返回null，失败时返回错误码。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定的待解压缩文件的文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[stage模型](js-apis-application-context.md)。 |
| outFile | string              | 是   | 指定的解压后的目录路径。                                       |
| options | [Options](#options) | 是   | 解压时的配置参数。                                             |

**相关错误码**

以下错误码的详细介绍请参见[ohos.zlib错误码](../errorcodes/errorcode-zlib.md)。

| 错误码ID | 错误信息                               |
| ------ | ------------------------------------- |
| 900001 | The Input source file is invalid.      |
| 900002 | The Input destination file is invalid. |

```typescript
// 【解压缩 例子2】
// 代码中使用的路径需为应用的沙箱路径，如/data/storage/el2/base/haps,也可以通过context获取
import zlib from '@ohos.zlib';
let inFile = '/xx/xxx.zip';
let outFile = '/xxx';
let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

try {
    zlib.decompressFile(inFile, outFile, options).then((data) => {
        console.info('decompressFile success');
    }).catch((errData) => {
        console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
} catch(errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## Options

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称     | 类型             | 可读 | 可写 | 说明                                                       |
| -------- | ---------------- | ---- | ---- | ---------------------------------------------------------- |
| level    | CompressLeve     | 是   | 否   | 参考[zip.CompressLevel枚举定义](#zipcompresslevel)。       |
| memLevel | MemLevel         | 是   | 否   | 参考[zip.MemLevel枚举定义](#zipmemlevel)。                 |
| strategy | CompressStrategy | 是   | 否   | 参考[zip.CompressStrategy枚举定义](#zipcompressstrategy)。 |

## zip.CompressLevel

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称                               | 值   | 说明              |
| ---------------------------------- | ---- | ----------------- |
| COMPRESS_LEVEL_NO_COMPRESSION      | 0    | 压缩率为0压缩等级。 |
| COMPRESS_LEVEL_BEST_SPEED          | 1    | 最佳速度压缩等级。  |
| COMPRESS_LEVEL_BEST_COMPRESSION    | 9    | 最佳压缩等级。      |
| COMPRESS_LEVEL_DEFAULT_COMPRESSION | -1   | 默认压缩等级。      |

## zip.MemLevel

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称              | 值   | 说明                             |
| ----------------- | ---- | -------------------------------- |
| MEM_LEVEL_MIN     | 1    | zip 接口在压缩过程中最小使用内存。 |
| MEM_LEVEL_MAX     | 9    | zip 接口在压缩过程中最大使用内存。 |
| MEM_LEVEL_DEFAULT | 8    | zip 接口在压缩过程中默认使用内存。 |

## zip.CompressStrategy

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
