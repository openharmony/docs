# @ohos.zlib    
本模块提供压缩解压缩文件的能力。  
> **说明**   
>本模块首批接口从API version -1开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import zlib from '@ohos.zlib'    
```  
    
## ErrorCode<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ERROR_CODE_OK | 0 | 函数调用成功。 |  
| ERROR_CODE_ERRNO | -1 | 函数调用失败。 |  
    
## CompressLevel<sup>(7+)</sup>    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COMPRESS_LEVEL_NO_COMPRESSION | 0 | 压缩率为0压缩等级。 |  
| COMPRESS_LEVEL_BEST_SPEED | 1 | 最佳速度压缩等级。 |  
| COMPRESS_LEVEL_BEST_COMPRESSION | 9 | 最佳压缩等级。 |  
| COMPRESS_LEVEL_DEFAULT_COMPRESSION | -1 | 默认压缩等级。 |  
    
## CompressStrategy<sup>(7+)</sup>    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COMPRESS_STRATEGY_DEFAULT_STRATEGY | 0 | 常规数据策略。 |  
| COMPRESS_STRATEGY_FILTERED | 1 | 过滤器产生的数据压缩策略。 |  
| COMPRESS_STRATEGY_HUFFMAN_ONLY | 2 | 霍夫曼编码格式压缩策略。 |  
| COMPRESS_STRATEGY_RLE | 3 | 游标编码压缩策略。 |  
| COMPRESS_STRATEGY_FIXED | 4 | 固定的压缩策略。 |  
    
## MemLevel<sup>(7+)</sup>    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MEM_LEVEL_MIN | 1 | zip 接口在压缩过程中最小使用内存。 |  
| MEM_LEVEL_MAX | 9 | zip 接口在压缩过程中最大使用内存。 |  
| MEM_LEVEL_DEFAULT | 8 | zip 接口在压缩过程中默认使用内存。 |  
    
## Options<sup>(7+)</sup>  
 **系统能力:**  SystemCapability.BundleManager.Zlib    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| level | CompressLevel | false | false | 参考[zip.CompressLevel枚举定义](#zipcompresslevel)。 |  
| memLevel | MemLevel | false | false | 参考[zip.MemLevel枚举定义](#zipmemlevel)。 |  
| strategy | CompressStrategy | false | false | 参考[zip.CompressStrategy枚举定义](#zipcompressstrategy)。 |  
    
## zipFile<sup>(deprecated)</sup>    
压缩接口，压缩完成后返回执行结果，使用Promise异步返回。  
 **调用形式：**     
- zipFile(inFile: string, outFile: string, options: Options): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.zlib#compressFile。  
 **系统能力:**  SystemCapability.BundleManager.Zlib    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inFile<sup>(deprecated)</sup> | string | true | 指定压缩的文件夹路径或者文件路径，路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](js-apis-inner-app-context.md)，[Stage模型](js-apis-inner-application-context.md)。 |  
| outFile<sup>(deprecated)</sup> | string | true | 指定压缩结果的文件路径（文件的扩展名zip）。 |  
| options<sup>(deprecated)</sup> | Options | true | 压缩的可选参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，无返回值。 |  
    
 **示例代码：**   
```ts    
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
  
    
## unzipFile<sup>(deprecated)</sup>    
解压文件，解压完成后返回执行结果，使用Promise异步返回。  
 **调用形式：**     
- unzipFile(inFile: string, outFile: string, options: Options): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.zlib#decompressFile。  
 **系统能力:**  SystemCapability.BundleManager.Zlib    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inFile<sup>(deprecated)</sup> | string | true | 指定的待解压缩文件的文件路径，路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](js-apis-inner-app-context.md)，[Stage模型](js-apis-inner-application-context.md)。 |  
| outFile<sup>(deprecated)</sup> | string | true | 指定的解压文件路径。 |  
| options<sup>(deprecated)</sup> | Options | true | 解压的可选参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，无返回值。 |  
    
 **示例代码：**   
```ts    
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
  
    
## compressFile<sup>(9+)</sup>    
压缩文件，压缩的结果，使用异步回调返回。成功返回null，失败返回错误码。  
 **调用形式：**     
    
- compressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void    
起始版本： 9    
- compressFile(inFile: string, outFile: string, options: Options): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.BundleManager.Zlib    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inFile | string | true |  |  
| outFile | string | true | 指定的压缩结果的文件路径。 |  
| options | Options | true | 压缩的配置参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取压缩结果之后的回调。成功返回null，失败返回错误码。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 900001 | The input source file is invalid. |  
| 900002 | The input destination file is invalid. |  
    
 **示例代码1：**   
示例(<span style="letter-spacing: 0px;">callback</span><span style="letter-spacing: 0px;">):</span>  
```ts    
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
  
    
 **示例代码2：**   
示例(<span style="letter-spacing: 0px;">Promise</span><span style="letter-spacing: 0px;">):</span>  
```ts    
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
  
    
## decompressFile<sup>(9+)</sup>    
解压文件，解压的结果，使用callback异步回调返回。成功时返回null，失败时返回错误码。  
 **调用形式：**     
    
- decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void    
起始版本： 9    
- decompressFile(inFile: string, outFile: string, options: Options, callback: AsyncCallback\<void>): void    
起始版本： 10    
- decompressFile(inFile: string, outFile: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- decompressFile(inFile: string, outFile: string, options?: Options): Promise\<void>    
起始版本： 9    
- decompressFile(inFile: string, outFile: string, options?: Options): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.BundleManager.Zlib    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inFile | string | true | 指定的待解压缩文件的文件路径，文件后缀需要以.zip结尾。文件路径必须为沙箱路径，沙箱路径可以通过context获取，可参考[FA模型](js-apis-inner-app-context.md)，[Stage模型](js-apis-inner-application-context.md)。 |  
| outFile | string | true | 指定的解压后的文件夹路径，文件夹目录路径需要在系统中存在，不存在则会解压失败。路径必须为沙箱路径，沙箱路径可以通过context获取，具体方法可参考 |  
| options | Options | true | 解压的配置参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取解压结果之后的回调。成功返回null，失败返回错误码。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 900001 | The input source file is invalid. |  
| 900002 | The input destination file is invalid. |  
| 900003 | The input source file is not ZIP format or damaged. |  
    
 **示例代码1：**   
示例(callback):  
  
```ts    
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
  
    
 **示例代码2：**   
示例(Promise):  
  
```ts    
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
  
