# @ohos.file.fs    
该模块为基础文件操作API，提供基础文件操作能力，包括文件基本管理、文件目录管理、文件信息统计、文件流式读写等常用功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import fileIo from '@ohos.file.fs'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| READ_ONLY | number | 0o0 | 只读打开。 |  
| WRITE_ONLY | number | 0o1 | 只写打开。 |  
| READ_WRITE | number | 0o2 | 读写打开。 |  
| CREATE | number | 0o100 | 若文件不存在，则创建文件。 |  
| TRUNC | number | 0o1000 | 如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。 |  
| APPEND | number | 0o2000 | 以追加方式打开，后续写将追加到文件末尾。 |  
| NONBLOCK | number | 0o4000 | 如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续 IO 进行非阻塞操作。 |  
| DIR | number | 0o200000 | 如果path不指向目录，则出错。 |  
| NOFOLLOW | number | 0o400000 | 如果path指向符号链接，则出错。 |  
| SYNC | number | 0o4010000 | 以同步IO的方式打开文件。 |  
    
## access    
检查文件是否存在。  
 **调用形式：**     
    
- access(path: string): Promise\<boolean>    
起始版本： 9    
- access(path: string): Promise\<boolean>    
起始版本： 10    
- access(path: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- access(path: string, callback: AsyncCallback\<boolean>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步检查文件是否存在的回调，如果存在，回调返回true，否则返回false。 |  
| Promise<boolean> | Promise对象。返回boolean，表示文件是否存在。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900023 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.access(filePath, (err: BusinessError, res: boolean) => {  
  if (err) {  
    console.info("access failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    if (res) {  
      console.info("file exists");  
    } else {  
      console.info("file not exists");  
    }  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.access(filePath).then((res: boolean) => {  
  if (res) {  
    console.info("file exists");  
  } else {  
    console.info("file not exists");  
  }  
}).catch((err: BusinessError) => {  
  console.info("access failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## accessSync    
以同步方法检查文件是否存在。  
 **调用形式：**     
- accessSync(path: string): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true，表示文件存在；返回false，表示文件不存在。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900023 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
try {  
  let res = fs.accessSync(filePath);  
  if (res) {  
    console.info("file exists");  
  } else {  
    console.info("file not exists");  
  }  
} catch(error) {  
  let err: BusinessError = error as BusinessError;  
  console.info("accessSync failed with error message: " + err.message + ", error code: " + err.code);  
}  
    
```    
  
    
## close    
关闭文件。  
 **调用形式：**     
    
- close(file: number | File): Promise\<void>    
起始版本： 9    
- close(file: number | File): Promise\<void>    
起始版本： 10    
- close(file: number | File, callback: AsyncCallback\<void>): void    
起始版本： 9    
- close(file: number | File, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 已打开的File对象或已打开的文件描述符fd。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步关闭文件之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900025 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.close(file, (err: BusinessError) => {  
  if (err) {  
    console.info("close file failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("close file succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.close(file).then(() => {  
  console.info("close file succeed");  
}).catch((err: BusinessError) => {  
  console.info("close file failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## closeSync    
以同步方法关闭文件。  
 **调用形式：**     
- closeSync(file: number | File): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 已打开的File对象或已打开的文件描述符fd。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900025 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.closeSync(file);    
```    
  
    
## copyDir<sup>(10+)</sup>    
复制源文件夹至目标路径下。  
 **调用形式：**     
    
- copyDir(src: string, dest: string, mode?: number): Promise\<void>    
起始版本： 10    
- copyDir(src: string, dest: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- copyDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void    
起始版本： 10    
- copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 源文件夹的应用沙箱路径。 |  
| dest | string | true | 目标文件夹的应用沙箱路径。 |  
| mode | number | false | 复制模式。默认mode为0。<br/>- mode为0，文件级别抛异常。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则抛出异常。源文件夹下未冲突的文件全部移动至目标文件夹下，目标文件夹下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>- mode为1，文件级别强制覆盖。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则强制覆盖冲突文件夹下所有同名文件，未冲突文件将继续保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步复制文件夹之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900030 |  |  
| 13900031 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900042 |  |  
| 13900015 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
import fs, { ConflictFiles } from '@ohos.file.fs';  
// copy directory from srcPath to destPath  
let srcPath = pathDir + "/srcDir/";  
let destPath = pathDir + "/destDir/";  
fs.copyDir(srcPath, destPath, 0, (err: BusinessError<Array<ConflictFiles>>) => {  
  if (err  err.code == 13900015) {  
    for (let i = 0; i < err.data.length; i++) {  
      console.info("copy directory failed with conflicting files: " + err.data[i].srcFile + " " + err.data[i].destFile);  
    }  
  } else if (err) {  
    console.info("copy directory failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("copy directory succeed");  
  }    
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
// copy directory from srcPath to destPath  
let srcPath = pathDir + "/srcDir/";  
let destPath = pathDir + "/destDir/";  
fs.copyDir(srcPath, destPath, 0).then(() => {  
  console.info("copy directory succeed");  
}).catch((err: BusinessError) => {  
  console.info("copy directory failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## copyDirSync<sup>(10+)</sup>    
以同步方法复制源文件夹至目标路径下。  
 **调用形式：**     
- copyDirSync(src: string, dest: string, mode?: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 源文件夹的应用沙箱路径。 |  
| dest | string | true | 目标文件夹的应用沙箱路径。 |  
| mode | number | false | 复制模式。默认mode为0。<br/>- mode为0，文件级别抛异常。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则抛出异常。源文件夹下未冲突的文件全部移动至目标文件夹下，目标文件夹下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles)>形式提供。<br/>- mode为1，文件级别强制覆盖。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则强制覆盖冲突文件夹下所有同名文件，未冲突文件将继续保留。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900030 |  |  
| 13900031 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
// copy directory from srcPath to destPath  
let srcPath = pathDir + "/srcDir/";  
let destPath = pathDir + "/destDir/";  
try {  
  fs.copyDirSync(srcPath, destPath, 0);  
  console.info("copy directory succeed");  
} catch (error) {  
  let err: BusinessError = error as BusinessError;  
  console.info("copy directory failed with error message: " + err.message + ", error code: " + err.code);  
}  
    
```    
  
    
## copyFile    
复制文件。  
 **调用形式：**     
    
- copyFile(src: string | number, dest: string | number, mode?: number): Promise\<void>    
起始版本： 9    
- copyFile(src: string | number, dest: string | number, mode?: number): Promise\<void>    
起始版本： 10    
- copyFile(src: string | number, dest: string | number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- copyFile(src: string | number, dest: string | number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- copyFile(   src: string | number,   dest: string | number,   mode: number,   callback: AsyncCallback\<void> ): void    
起始版本： 9    
- copyFile(   src: string | number,   dest: string | number,   mode: number,   callback: AsyncCallback\<void> ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 待复制文件的路径或待复制文件的文件描述符。 |  
| dest | string | true | 目标文件路径或目标文件的文件描述符。 |  
| mode | number | false | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步复制文件之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900030 |  |  
| 13900031 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let srcPath = pathDir + "/srcDir/test.txt";  
let dstPath = pathDir + "/dstDir/test.txt";  
fs.copyFile(srcPath, dstPath, 0, (err: BusinessError) => {  
  if (err) {  
    console.info("copy file failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("copy file succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcPath = pathDir + "/srcDir/test.txt";  
let dstPath = pathDir + "/dstDir/test.txt";  
fs.copyFile(srcPath, dstPath, 0).then(() => {  
  console.info("copy file succeed");  
}).catch((err: BusinessError) => {  
  console.info("copy file failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## copyFileSync    
以同步方法复制文件。  
 **调用形式：**     
- copyFileSync(src: string | number, dest: string | number, mode?: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 待复制文件的路径或待复制文件的文件描述符。 |  
| dest | string | true | 目标文件路径或目标文件的文件描述符。 |  
| mode | number | false | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁切掉。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900030 |  |  
| 13900031 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let srcPath = pathDir + "/srcDir/test.txt";  
let dstPath = pathDir + "/dstDir/test.txt";  
fs.copyFileSync(srcPath, dstPath);    
```    
  
    
## createStream    
基于文件路径打开文件流。  
 **调用形式：**     
    
- createStream(path: string, mode: string): Promise\<Stream>    
起始版本： 9    
- createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件的应用沙箱路径。 |  
| mode | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步打开文件流之后的回调。 |  
| Promise<Stream> | Promise对象。返回文件流的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.createStream(filePath, "r+", (err: BusinessError, stream: fs.Stream) => {  
  if (err) {  
    console.info("create stream failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("createStream succeed");  
  }  
  stream.closeSync();  
})  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.createStream(filePath, "r+").then((stream: fs.Stream) => {  
  console.info("createStream succeed");  
}).catch((err: BusinessError) => {  
  console.info("createStream failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  stream.closeSync();  
});  
    
```    
  
    
## createStreamSync    
以同步方法基于文件路径打开文件流。  
 **调用形式：**     
- createStreamSync(path: string, mode: string): Stream  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件的应用沙箱路径。 |  
| mode | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stream | 返回文件流的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
console.info("createStream succeed");  
stream.closeSync();    
```    
  
    
## createRandomAccessFile<sup>(10+)</sup>    
基于文件路径或文件对象创建RandomAccessFile文件对象。  
 **调用形式：**     
    
- createRandomAccessFile(file: string | File, mode?: number): Promise\<RandomAccessFile>    
起始版本： 10    
- createRandomAccessFile(file: string | File, callback: AsyncCallback\<RandomAccessFile>): void    
起始版本： 10    
- createRandomAccessFile(file: string | File, mode: number, callback: AsyncCallback\<RandomAccessFile>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 文件的应用沙箱路径或已打开的File对象 |  
| mode | number | false | 创建文件RandomAccessFile对象的[选项](#openmode)，仅当传入文件沙箱路径时生效，必须指定如下选项中的一个，默认以只读方式创建：<br/>-OpenMode.READ_ONLY(0o0)：只读创建。<br/>-OpenMode.WRITE_ONLY(0o1)：只写创建。<br/>-OpenMode.READ_WRITE(0o2)：读写创建。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-OpenMode.TRUNC(0o1000)：如果RandomAccessFile对象存在且以只写或读写的方式创建文件，则将其长度裁剪为零。<br/>-OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到RandomAccessFile对象末尾。<br/>-OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-OpenMode.SYNC(0o4010000)：以同步IO的方式创建RandomAccessFile对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步创建RandomAccessFile对象之后的回调。 |  
| Promise<RandomAccessFile> | Promise对象。返回RandomAccessFile文件对象的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
fs.createRandomAccessFile(file, fs.OpenMode.READ_ONLY (err: BusinessError, randomAccessFile: fs.RandomAccessFile) => {  
  if (err) {  
    console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("randomAccessFile fd: " + randomAccessFile.fd);  
    randomAccessFile.close();  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
fs.createRandomAccessFile(file).then((randomAccessFile: fs.RandomAccessFile) => {  
  console.info("randomAccessFile fd: " + randomAccessFile.fd);  
  randomAccessFile.close();  
}).catch((err: BusinessError) => {  
  console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  fs.closeSync(file);  
});  
    
```    
  
    
## createRandomAccessFileSync<sup>(10+)</sup>    
基于文件路径或文件对象创建RandomAccessFile文件对象。  
 **调用形式：**     
- createRandomAccessFileSync(file: string | File, mode?: number): RandomAccessFile  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 文件的应用沙箱路径或已打开的File对象 |  
| mode | number | false | 创建文件RandomAccessFile对象的[选项](#openmode)，仅当传入文件沙箱路径时生效，必须指定如下选项中的一个，默认以只读方式创建：<br/>-OpenMode.READ_ONLY(0o0)：只读创建。<br/>-OpenMode.WRITE_ONLY(0o1)：只写创建。<br/>-OpenMode.READ_WRITE(0o2)：读写创建。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-OpenMode.TRUNC(0o1000)：如果RandomAccessFile对象存在且以只写或读写的方式创建文件，则将其长度裁剪为零。<br/>-OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到RandomAccessFile对象末尾。<br/>-OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-OpenMode.SYNC(0o4010000)：以同步IO的方式创建RandomAccessFile对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RandomAccessFile | 返回RandomAccessFile文件对象的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
let randomAccessFile = fs.createRandomAccessFileSync(file);  
randomAccessFile.close();    
```    
  
    
## createWatcher<sup>(10+)</sup>    
创建Watcher对象，用来监听文件或目录变动。  
 **调用形式：**     
- createWatcher(path: string, events: number, listener: WatchEventListener): Watcher  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 监听文件或目录的沙箱路径。 |  
| events | number | true | 监听变动的事件集，多个事件通过或(\|)的方式进行集合。<br/>-0x1: IN_ACCESS， 文件被访问。<br/>-0x2: IN_MODIFY，文件内容被修改。<br/>-0x4: IN_ATTRIB，文件元数据被修改。<br/>-0x8: IN_CLOSE_WRITE，打开进行写操作的文件被关闭。<br/>-0x10: IN_CLOSE_NOWRITE，打开未进行写操作的文件或目录被关闭。<br/>-0x20: IN_OPEN，文件或目录被打开。 <br/>-0x40: IN_MOVED_FROM，监听目录中文件被移动走。<br/>-0x80: IN_MOVED_TO，监听目录中文件被移动过来。<br/>-0x100: IN_CREATE，监听目录中文件或子目录被创建。<br/>-0x200: IN_DELETE，监听目录中文件或子目录被删除。<br/>-0x400: IN_DELETE_SELF，监听的目录被删除，删除后监听停止。<br/>-0x800: IN_MOVE_SELF，监听的文化或目录被移动，移动后监听继续。<br/>-0xfff: IN_ALL_EVENTS，监听以上所有事件。 |  
| listener | WatchEventListener | true | 监听事件发生后的回调。监听事件每发生一次，回调一次。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Watcher | 返回Watcher对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900021 |  |  
| 13900022 |  |  
| 13900025 |  |  
| 13900030 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
import fs, { WatchEvent } from '@ohos.file.fs';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
let watcher = fs.createWatcher(filePath, 0x2 | 0x10, (watchEvent: WatchEvent) => {  
  if (watchEvent.event == 0x2) {  
    console.info(watchEvent.fileName + 'was modified');  
  } else if (watchEvent.event == 0x10) {  
    console.info(watchEvent.fileName + 'was closed');  
  }  
});  
watcher.start();  
fs.writeSync(file.fd, 'test');  
fs.closeSync(file);  
watcher.stop();    
```    
  
    
## dup<sup>(10+)</sup>    
将文件描述符转化为File。  
 **调用形式：**     
- dup(fd: number): File  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| File | 打开的File对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900014 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file1 = fs.openSync(filePath, fs.OpenMode.READ_WRITE);  
let fd: number = file1.fd;  
let file2 = fs.dup(fd);  
console.info("The name of the file2 is " + file2.name);  
fs.closeSync(file1);  
fs.closeSync(file2);    
```    
  
    
## fdatasync    
实现文件内容数据同步。  
 **调用形式：**     
    
- fdatasync(fd: number): Promise\<void>    
起始版本： 9    
- fdatasync(fd: number): Promise\<void>    
起始版本： 10    
- fdatasync(fd: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- fdatasync(fd: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步将文件内容数据同步之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.fdatasync (file.fd, (err: BusinessError) => {  
  if (err) {  
    console.info("fdatasync failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("fdatasync succeed");  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.fdatasync(file.fd).then(() => {  
  console.info("sync data succeed");  
}).catch((err: BusinessError) => {  
  console.info("sync data failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  fs.closeSync(file);  
});  
    
```    
  
    
## fdatasyncSync    
以同步方法实现文件内容数据同步。  
 **调用形式：**     
- fdatasyncSync(fd: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.fdatasyncSync(file.fd);  
fs.closeSync(file);    
```    
  
    
## fdopenStream    
基于文件描述符打开文件流。  
 **调用形式：**     
    
- fdopenStream(fd: number, mode: string): Promise\<Stream>    
起始版本： 9    
- fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
| mode | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步打开文件流之后的回调。 |  
| Promise<Stream> | Promise对象。返回文件流的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);  
fs.fdopenStream(file.fd, "r+", (err: BusinessError, stream: fs.Stream) => {  
  if (err) {  
    console.info("fdopen stream failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("fdopen stream succeed");  
    stream.closeSync();  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.fdopenStream(file.fd, "r+").then((stream: fs.Stream) => {  
  console.info("openStream succeed");  
  stream.closeSync();  
}).catch((err: BusinessError) => {  
  console.info("openStream failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  fs.closeSync(file);  
});  
    
```    
  
    
## fdopenStreamSync    
以同步方法基于文件描述符打开文件流。  
 **调用形式：**     
- fdopenStreamSync(fd: number, mode: string): Stream  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
| mode | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stream | 返回文件流的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY | fs.OpenMode.CREATE);  
let stream = fs.fdopenStreamSync(file.fd, "r+");  
stream.closeSync();  
fs.closeSync(file);    
```    
  
    
## fsync    
同步文件数据。  
 **调用形式：**     
    
- fsync(fd: number): Promise\<void>    
起始版本： 9    
- fsync(fd: number): Promise\<void>    
起始版本： 10    
- fsync(fd: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- fsync(fd: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步将文件数据同步之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.fsync(file.fd, (err: BusinessError) => {  
  if (err) {  
    console.info("fsync failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("fsync succeed");  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.fsync(file.fd).then(() => {  
  console.info("sync data succeed");  
}).catch((err: BusinessError) => {  
  console.info("sync data failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  fs.closeSync(file);  
});  
    
```    
  
    
## fsyncSync    
以同步方法同步文件数据。  
 **调用形式：**     
- fsyncSync(fd: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath);  
fs.fsyncSync(file.fd);  
fs.closeSync(file);    
```    
  
    
## listFile    
列出文件夹下所有文件名，支持递归列出所有文件名（包含子目录下），支持文件过滤。  
 **调用形式：**     
    
- listFile(   path: string,   options?: {     recursion?: boolean;     listNum?: number;     filter?: Filter;   } ): Promise\<string[]>    
起始版本： 9    
- listFile(   path: string,   options?: {     recursion?: boolean;     listNum?: number;     filter?: Filter;   } ): Promise\<string[]>    
起始版本： 10    
- listFile(path: string, callback: AsyncCallback\<string[]>): void    
起始版本： 9    
- listFile(path: string, callback: AsyncCallback\<string[]>): void    
起始版本： 10    
- listFile(   path: string,   options: {     recursion?: boolean;     listNum?: number;     filter?: Filter;   },   callback: AsyncCallback\<string[]> ): void    
起始版本： 9    
- listFile(   path: string,   options: {     recursion?: boolean;     listNum?: number;     filter?: Filter;   },   callback: AsyncCallback\<string[]> ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件夹的应用沙箱路径。 |  
| options | {     recursion?: boolean;     listNum?: number;     filter?: Filter;   } | false | 文件过滤选项。默认不进行过滤。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步列出文件名数组之后的回调。 |  
| Promise<string[]> | Promise对象。返回文件名数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900018 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
import fs, { Filter } from '@ohos.file.fs';  
class ListFileOption {  
  public recursion: boolean = false;  
  public listNum: number = 0;  
  public filter: Filter = {};  
}  
let option = new ListFileOption();  
option.filter.suffix = [".png", ".jpg", ".jpeg"];  
option.filter.displayName = ["*abc", "efg*"];  
option.filter.fileSizeOver = 1024;  
option.filter.lastModifiedAfter = new Date().getTime();  
fs.listFile(pathDir, option, (err: BusinessError, filenames: Array<string>) => {  
  if (err) {  
    console.info("list file failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("listFile succeed");  
    for (let i = 0; i < filenames.length; i++) {  
      console.info("filename: %s", filenames[i]);  
    }  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
import fs, { Filter } from '@ohos.file.fs';  
class ListFileOption {  
  public recursion: boolean = false;  
  public listNum: number = 0;  
  public filter: Filter = {};  
}  
let option = new ListFileOption();  
option.filter.suffix = [".png", ".jpg", ".jpeg"];  
option.filter.displayName = ["*abc", "efg*"];  
option.filter.fileSizeOver = 1024;  
option.filter.lastModifiedAfter = new Date().getTime();  
fs.listFile(pathDir, option).then((filenames: Array<string>) => {  
  console.info("listFile succeed");  
  for (let i = 0; i < filenames.length; i++) {  
    console.info("fileName: %s", filenames[i]);  
  }  
}).catch((err: BusinessError) => {  
  console.info("list file failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## listFileSync    
以同步方式列出文件夹下所有文件名，支持递归列出所有文件名（包含子目录下），支持文件过滤。  
 **调用形式：**     
- listFileSync(   path: string,   options?: {     recursion?: boolean;     listNum?: number;     filter?: Filter;   } ): string[]  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件夹的应用沙箱路径。 |  
| options | {     recursion?: boolean;     listNum?: number;     filter?: Filter;   } | false | 文件过滤选项。默认不进行过滤。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | 返回文件名数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900018 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
import fs, { Filter } from '@ohos.file.fs';  
  class ListFileOption {  
    public recursion: boolean = false;  
    public listNum: number = 0;  
    public filter: Filter = {};  
  }  
  let option = new ListFileOption();  
  option.filter.suffix = [".png", ".jpg", ".jpeg"];  
  option.filter.displayName = ["*abc", "efg*"];  
  option.filter.fileSizeOver = 1024;  
  option.filter.lastModifiedAfter = new Date().getTime();  
  let filenames = fs.listFileSync(pathDir, option);  
  console.info("listFile succeed");  
  for (let i = 0; i < filenames.length; i++) {  
    console.info("filename: %s", filenames[i]);  
  }  
    
```    
  
    
## lstat    
获取链接文件信息。  
 **调用形式：**     
    
- lstat(path: string): Promise\<Stat>    
起始版本： 9    
- lstat(path: string, callback: AsyncCallback\<Stat>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回文件的具体信息。 |  
| Promise<Stat> | promise对象，返回文件对象，表示文件的具体信息，详情见stat。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900038 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/linkToFile";  
fs.lstat(filePath, (err: BusinessError, stat: fs.Stat) => {  
  if (err) {  
    console.info("lstat failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("lstat succeed, the size of file is" + stat.size);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/linkToFile";  
fs.lstat(filePath).then((stat: fs.Stat) => {  
  console.info("lstat succeed, the size of file is " + stat.size);  
}).catch((err: BusinessError) => {  
  console.info("lstat failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## lstatSync    
以同步方法获取链接文件信息。  
 **调用形式：**     
- lstatSync(path: string): Stat  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stat | 表示文件的具体信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900038 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/linkToFile";  
let fileStat = fs.lstatSync(filePath);  
console.info("lstat succeed, the size of file is" + fileStat.size);    
```    
  
    
## mkdir    
创建目录。  
 **调用形式：**     
    
- mkdir(path: string): Promise\<void>    
起始版本： 9    
- mkdir(path: string): Promise\<void>    
起始版本： 10    
- mkdir(path: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- mkdir(path: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 目录的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步创建目录操作完成之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900028 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + "/testDir1/testDir2/testDir3";  
fs.mkdir(dirPath, true, (err: BusinessError) => {  
  if (err) {  
    console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("mkdir succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + "/testDir1/testDir2/testDir3";  
fs.mkdir(dirPath, true).then(() => {  
  console.info("mkdir succeed");  
}).catch((err: BusinessError) => {  
  console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## mkdirSync    
以同步方法创建目录。  
 **调用形式：**     
- mkdirSync(path: string): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 目录的应用沙箱路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900028 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let dirPath = pathDir + "/testDir";  
fs.mkdirSync(dirPath);    
```    
  
    
## mkdtemp    
创建临时目录。  
 **调用形式：**     
    
- mkdtemp(prefix: string): Promise\<string>    
起始版本： 9    
- mkdtemp(prefix: string): Promise\<string>    
起始版本： 10    
- mkdtemp(prefix: string, callback: AsyncCallback\<string>): void    
起始版本： 9    
- mkdtemp(prefix: string, callback: AsyncCallback\<string>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix | string | true | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步创建临时目录之后的回调。 |  
| Promise<string> | Promise对象。返回生成的唯一目录路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900028 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
fs.mkdtemp(pathDir + "/XXXXXX", (err: BusinessError, res: string) => {  
  if (err) {  
    console.info("mkdtemp failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("mkdtemp succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
fs.mkdtemp(pathDir + "/XXXXXX").then((dir: string) => {  
  console.info("mkdtemp succeed:" + dir);  
}).catch((err: BusinessError) => {  
  console.info("mkdtemp failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## mkdtempSync    
以同步的方法创建临时目录。  
 **调用形式：**     
- mkdtempSync(prefix: string): string  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix | string | true | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 产生的唯一目录路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900028 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let res = fs.mkdtempSync(pathDir + "/XXXXXX");    
```    
  
    
## moveDir<sup>(10+)</sup>    
移动源文件夹至目标路径下。  
 **调用形式：**     
    
- moveDir(src: string, dest: string, mode?: number): Promise\<void>    
起始版本： 10    
- moveDir(src: string, dest: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- moveDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void    
起始版本： 10    
- moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 源文件夹的应用沙箱路径。 |  
| dest | string | true | 目标文件夹的应用沙箱路径。 |  
| mode | number | false | 移动模式。默认mode为0。<br/>-mode为0，文件夹级别抛异常。若目标文件夹下存在与源文件夹名冲突的非空文件夹，则抛出异常。<br/>-mode为1，文件级别抛异常。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则抛出异常。源文件夹下未冲突的文件全部移动至目标文件夹下，目标文件夹下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>- mode为2，文件级别强制覆盖。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则强制覆盖冲突文件夹下所有同名文件，未冲突文件将继续保留。<br/>- mode为3，文件夹级别强制覆盖。移动源文件夹至目标文件夹下，目标文件夹下移动的文件夹内容与源文件夹完全一致。若目标文件夹下存在与源文件夹名冲突的文件夹，该文件夹下所有原始文件将不会保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步移动文件夹之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900016 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900028 |  |  
| 13900032 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
import fs, { ConflictFiles } from '@ohos.file.fs';  
// move directory from srcPath to destPath  
let srcPath = pathDir + "/srcDir/";  
let destPath = pathDir + "/destDir/";  
fs.moveDir(srcPath, destPath, 1, (err: BusinessError<Array<ConflictFiles>>) => {  
  if (err  err.code == 13900015) {  
    for (let i = 0; i < data.length; i++) {  
      console.info("move directory failed with conflicting files: " + data[i].srcFile + " " + data[i].destFile);  
    }  
  } else if (err) {  
    console.info("move directory failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("move directory succeed");  
  }    
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
// move directory from srcPath to destPath  
let srcPath = pathDir + "/srcDir/";  
let destPath = pathDir + "/destDir/";  
fs.moveDir(srcPath, destPath, 1).then(() => {  
  console.info("move directory succeed");  
}).catch((err: BusinessError) => {  
  console.info("move directory failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## moveDirSync<sup>(10+)</sup>    
以同步方法移动源文件夹至目标路径下。  
 **调用形式：**     
- moveDirSync(src: string, dest: string, mode?: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 源文件夹的应用沙箱路径。 |  
| dest | string | true | 目标文件夹的应用沙箱路径。 |  
| mode | number | false | 移动模式。默认mode为0。<br/>-mode为0，文件夹级别抛异常。若目标文件夹下存在与源文件夹名冲突的文件夹，则抛出异常。<br/>-mode为1，文件级别抛异常。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则抛出异常。源文件夹下未冲突的文件全部移动至目标文件夹下，目标文件夹下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles)>形式提供。<br/>- mode为2，文件级别强制覆盖。目标文件夹下存在与源文件夹名冲突的文件夹，若冲突文件夹下存在同名文件，则强制覆盖冲突文件夹下所有同名文件，未冲突文件将继续保留。<br/>- mode为3，文件夹级别强制覆盖。移动源文件夹至目标文件夹下，目标文件夹下移动的文件夹内容与源文件夹完全一致。若目标文件夹下存在与源文件夹名冲突的文件夹，该文件夹下所有原始文件将不会保留。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900016 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900028 |  |  
| 13900032 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
// move directory from srcPath to destPath  
let srcPath = pathDir + "/srcDir/";  
let destPath = pathDir + "/destDir/";  
try {  
  fs.moveDirSync(srcPath, destPath, 1);  
  console.info("move directory succeed");  
} catch (err) {  
  console.info("move directory failed with error message: " + err.message + ", error code: " + err.code);  
}  
    
```    
  
    
## moveFile    
移动文件。  
 **调用形式：**     
    
- moveFile(src: string, dest: string, mode?: number): Promise\<void>    
起始版本： 9    
- moveFile(src: string, dest: string, mode?: number): Promise\<void>    
起始版本： 10    
- moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 源文件的应用沙箱路径。 |  
| dest | string | true | 目的文件的应用沙箱路径。 |  
| mode | number | false | 移动模式。若mode为0，移动位置存在同名文件时，强制移动覆盖。若mode为1，移动位置存在同名文件时，抛出异常。默认为0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步移动文件之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900016 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900028 |  |  
| 13900032 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let srcPath = pathDir + "/source.txt";  
let destPath = pathDir + "/dest.txt";  
fs.moveFile(srcPath, destPath, 0, (err: BusinessError) => {  
  if (err) {  
    console.info("move file failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("move file succeed");  
  }    
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcPath = pathDir + "/source.txt";  
let destPath = pathDir + "/dest.txt";  
fs.moveFile(srcPath, destPath, 0).then(() => {  
  console.info("move file succeed");  
}).catch((err: BusinessError) => {  
  console.info("move file failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## moveFileSync    
以同步方式移动文件。  
 **调用形式：**     
- moveFileSync(src: string, dest: string, mode?: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src | string | true | 源文件的应用沙箱路径。 |  
| dest | string | true | 目的文件的应用沙箱路径。 |  
| mode | number | false | 移动模式。若mode为0，移动位置存在同名文件时，强制移动覆盖。若mode为1，移动位置存在同名文件时，抛出异常。默认为0。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900016 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900028 |  |  
| 13900032 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let srcPath = pathDir + "/source.txt";  
let destPath = pathDir + "/dest.txt";  
fs.moveFileSync(srcPath, destPath, 0);  
console.info("move file succeed");    
```    
  
    
## open    
打开文件。支持使用URI打开文件。  
 **调用形式：**     
    
- open(path: string, mode?: number): Promise\<File>    
起始版本： 9    
- open(path: string, mode?: number): Promise\<File>    
起始版本： 10    
- open(path: string, callback: AsyncCallback\<File>): void    
起始版本： 9    
- open(path: string, callback: AsyncCallback\<File>): void    
起始版本： 10    
- open(path: string, mode: number, callback: AsyncCallback\<File>): void    
起始版本： 9    
- open(path: string, mode: number, callback: AsyncCallback\<File>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true |  |  
| mode | number | false | 打开文件的[选项](#openmode)，必须指定如下选项中的一个，默认以只读方式打开：<br/>-OpenMode.READ_ONLY(0o0)：只读打开。<br/>-OpenMode.WRITE_ONLY(0o1)：只写打开。<br/>-OpenMode.READ_WRITE(0o2)：读写打开。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-OpenMode.TRUNC(0o1000)：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到文件末尾。<br/>-OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-OpenMode.SYNC(0o4010000)：以同步IO的方式打开文件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<File> | Promise对象。返回File对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE, (err: BusinessError, file: fs.File) => {  
  if (err) {  
    console.info("open failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("file fd: " + file.fd);  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE).then((file: fs.File) => {  
  console.info("file fd: " + file.fd);  
  fs.closeSync(file);  
}).catch((err: BusinessError) => {  
  console.info("open file failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## openSync    
以同步方法打开文件。支持使用URI打开文件。  
 **调用形式：**     
- openSync(path: string, mode?: number): File  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 打开文件的应用沙箱路径或URI。 |  
| mode | number | false | 打开文件的[选项](#openmode)，必须指定如下选项中的一个，默认以只读方式打开：<br/>-OpenMode.READ_ONLY(0o0)：只读打开。<br/>-OpenMode.WRITE_ONLY(0o1)：只写打开。<br/>-OpenMode.READ_WRITE(0o2)：读写打开。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-OpenMode.TRUNC(0o1000)：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到文件末尾。<br/>-OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-OpenMode.SYNC(0o4010000)：以同步IO的方式打开文件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| File | 打开的File对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900006 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900017 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900022 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900029 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900034 |  |  
| 13900038 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
console.info("file fd: " + file.fd);  
fs.closeSync(file);    
```    
  
    
## read    
从文件读取数据。  
 **调用形式：**     
    
- read(   fd: number,   buffer: ArrayBuffer,   options?: {     offset?: number;     length?: number;   } ): Promise\<number>    
起始版本： 9    
- read(   fd: number,   buffer: ArrayBuffer,   options?: {     offset?: number;     length?: number;   } ): Promise\<number>    
起始版本： 10    
- read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<number>): void    
起始版本： 9    
- read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<number>): void    
起始版本： 10    
- read(   fd: number,   buffer: ArrayBuffer,   options: {     offset?: number;     length?: number;   },   callback: AsyncCallback\<number> ): void    
起始版本： 9    
- read(   fd: number,   buffer: ArrayBuffer,   options: {     offset?: number;     length?: number;   },   callback: AsyncCallback\<number> ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
| buffer | ArrayBuffer | true | 用于保存读取到的文件数据的缓冲区。 |  
| options | {     offset?: number;     length?: number;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步读取数据之后的回调。 |  
| Promise<number> | Promise对象。返回读取的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
import buffer from '@ohos.buffer';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);  
let arrayBuffer = new ArrayBuffer(4096);  
fs.read(file.fd, arrayBuffer, (err: BusinessError, readLen: number) => {  
  if (err) {  
    console.info("read failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("read file data succeed");  
    let buf = buffer.from(arrayBuffer, 0, readLen);  
    console.info(`The content of file: ${buf.toString()}`);  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
import buffer from '@ohos.buffer';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);  
let arrayBuffer = new ArrayBuffer(4096);  
fs.read(file.fd, arrayBuffer).then((readLen: number) => {  
  console.info("read file data succeed");  
  let buf = buffer.from(arrayBuffer, 0, readLen);  
  console.info(`The content of file: ${buf.toString()}`);  
}).catch((err: BusinessError) => {  
  console.info("read file data failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  fs.closeSync(file);  
});  
    
```    
  
    
## readSync    
以同步方法从文件读取数据。  
 **调用形式：**     
- readSync(   fd: number,   buffer: ArrayBuffer,   options?: {     offset?: number;     length?: number;   } ): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
| buffer | ArrayBuffer | true | 用于保存读取到的文件数据的缓冲区。 |  
| options | {     offset?: number;     length?: number;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际读取的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
 let filePath = pathDir + "/test.txt";  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);  let buf = new ArrayBuffer(4096);  fs.readSync(file.fd, buf);  fs.closeSync(file);    
```    
  
    
## readText    
基于文本方式读取文件（即直接读取文件的文本内容）。  
 **调用形式：**     
    
- readText(   filePath: string,   options?: {     offset?: number;     length?: number;     encoding?: string;   } ): Promise\<string>    
起始版本： 9    
- readText(   filePath: string,   options?: {     offset?: number;     length?: number;     encoding?: string;   } ): Promise\<string>    
起始版本： 10    
- readText(filePath: string, callback: AsyncCallback\<string>): void    
起始版本： 9    
- readText(filePath: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- readText(   filePath: string,   options: {     offset?: number;     length?: number;     encoding?: string;   },   callback: AsyncCallback\<string> ): void    
起始版本： 9    
- readText(   filePath: string,   options: {     offset?: number;     length?: number;     encoding?: string;   },   callback: AsyncCallback\<string> ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filePath | string | true | 文件的应用沙箱路径。 |  
| options | {     offset?: number;     length?: number;     encoding?: string;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读取。<br/>-length，number类型，表示期望读取数据的长度。可选，默认文件长度。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'，仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回读取文件的内容。 |  
| Promise<string> | Promise对象。返回读取文件的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
class Option {  
  offset: number = 0;  
  length: number = 0;  
  encoding: string = 'utf-8';  
}  
let stat = fs.statSync(filePath);  
let option = new Option();  
option.offset = 1;  
option.length = stat.size;  
fs.readText(filePath, option, (err: BusinessError, str: string) => {  
  if (err) {  
    console.info("readText failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("readText succeed:" + str);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.readText(filePath).then((str: string) => {  
  console.info("readText succeed:" + str);  
}).catch((err: BusinessError) => {  
  console.info("readText failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## readTextSync    
以同步方法基于文本方式读取文件（即直接读取文件的文本内容）。  
 **调用形式：**     
- readTextSync(   filePath: string,   options?: {     offset?: number;     length?: number;     encoding?: string;   } ): string  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filePath | string | true | 文件的应用沙箱路径。 |  
| options | {     offset?: number;     length?: number;     encoding?: string;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读取。<br/>-length，number类型，表示期望读取数据的长度。可选，默认文件长度。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'，仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
  class Option {  
    offset: number = 0;  
    length: number = 0;  
    encoding: string = 'utf-8';  
  }  
  let stat = fs.statSync(filePath);  
  let option = new Option();  
  option.offset = 1;  
  option.length = stat.size;  
  let str = fs.readTextSync(filePath, option);  
  console.info("readText succeed:" + str);  
    
```    
  
    
## rename    
重命名文件或文件夹。  
 **调用形式：**     
    
- rename(oldPath: string, newPath: string): Promise\<void>    
起始版本： 9    
- rename(oldPath: string, newPath: string): Promise\<void>    
起始版本： 10    
- rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| oldPath | string | true | 文件的应用沙箱原路径。 |  
| newPath | string | true | 文件的应用沙箱新路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步重命名文件之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900016 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900028 |  |  
| 13900032 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + "/new.txt";  
fs.rename(srcFile, dstFile, (err: BusinessError) => {  
  if (err) {  
    console.info("rename failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("rename succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + "/new.txt";  
fs.rename(srcFile, dstFile).then(() => {  
  console.info("rename succeed");  
}).catch((err: BusinessError) => {  
  console.info("rename failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## renameSync    
以同步方法重命名文件或文件夹。  
 **调用形式：**     
- renameSync(oldPath: string, newPath: string): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| oldPath | string | true | 文件的应用沙箱原路径。 |  
| newPath | string | true | 文件的应用沙箱新路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900015 |  |  
| 13900016 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900028 |  |  
| 13900032 |  |  
| 13900033 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + "/new.txt";  
fs.renameSync(srcFile, dstFile);    
```    
  
    
## rmdir    
删除整个目录。  
 **调用形式：**     
    
- rmdir(path: string): Promise\<void>    
起始版本： 9    
- rmdir(path: string): Promise\<void>    
起始版本： 10    
- rmdir(path: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- rmdir(path: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 目录的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步删除目录之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900032 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + "/testDir";  
fs.rmdir(dirPath, (err: BusinessError) => {  
  if (err) {  
    console.info("rmdir failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("rmdir succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + "/testDir";  
fs.rmdir(dirPath).then(() => {  
  console.info("rmdir succeed");  
}).catch((err: BusinessError) => {  
  console.info("rmdir failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## rmdirSync    
以同步方法删除目录。  
 **调用形式：**     
- rmdirSync(path: string): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 目录的应用沙箱路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900032 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let dirPath = pathDir + "/testDir";  
fs.rmdirSync(dirPath);    
```    
  
    
## stat    
获取文件详细属性信息。  
 **调用形式：**     
    
- stat(file: string | number): Promise\<Stat>    
起始版本： 9    
- stat(file: string | number): Promise\<Stat>    
起始版本： 10    
- stat(file: string | number, callback: AsyncCallback\<Stat>): void    
起始版本： 9    
- stat(file: string | number, callback: AsyncCallback\<Stat>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 文件应用沙箱路径path或已打开的文件描述符fd。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取文件的信息之后的回调。 |  
| Promise<Stat> | Promise对象。返回文件的具体信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900030 |  |  
| 13900031 |  |  
| 13900033 |  |  
| 13900038 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
fs.stat(pathDir, (err: BusinessError, stat: fs.Stat) => {  
  if (err) {  
    console.info("get file info failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("get file info succeed, the size of file is " + stat.size);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.stat(filePath).then((stat: fs.Stat) => {  
  console.info("get file info succeed, the size of file is " + stat.size);  
}).catch((err: BusinessError) => {  
  console.info("get file info failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## statSync    
以同步方法获取文件详细属性信息。  
 **调用形式：**     
- statSync(file: string | number): Stat  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 文件应用沙箱路径path或已打开的文件描述符fd。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stat | 表示文件的具体信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900030 |  |  
| 13900031 |  |  
| 13900033 |  |  
| 13900038 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let stat = fs.statSync(pathDir);  
console.info("get file info succeed, the size of file is " + stat.size);    
```    
  
    
## symlink    
基于文件路径创建符号链接。  
 **调用形式：**     
    
- symlink(target: string, srcPath: string): Promise\<void>    
起始版本： 9    
- symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | string | true | 源文件的应用沙箱路径。 |  
| srcPath | string | true | 符号链接文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步创建符号链接信息之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + "/test";  
fs.symlink(srcFile, dstFile, (err: BusinessError) => {  
  if (err) {  
    console.info("symlink failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("symlink succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + "/test";  
fs.symlink(srcFile, dstFile).then(() => {  
  console.info("symlink succeed");  
}).catch((err: BusinessError) => {  
  console.info("symlink failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## symlinkSync    
以同步的方法基于文件路径创建符号链接。  
 **调用形式：**     
- symlinkSync(target: string, srcPath: string): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | string | true | 源文件的应用沙箱路径。 |  
| srcPath | string | true | 符号链接文件的应用沙箱路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900025 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + "/test";  
fs.symlinkSync(srcFile, dstFile);    
```    
  
    
## truncate    
截断文件。  
 **调用形式：**     
    
- truncate(file: string | number, len?: number): Promise\<void>    
起始版本： 9    
- truncate(file: string | number, len?: number): Promise\<void>    
起始版本： 10    
- truncate(file: string | number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- truncate(file: string | number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- truncate(file: string | number, len: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- truncate(file: string | number, len: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 文件的应用沙箱路径或已打开的文件描述符fd。 |  
| len | number | false | 文件截断后的长度，以字节为单位。默认为0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，本调用无返回值。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let len: number = 5;  
fs.truncate(filePath, len, (err: BusinessError) => {  
  if (err) {  
    console.info("truncate failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("truncate succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let len: number = 5;  
fs.truncate(filePath, len).then(() => {  
  console.info("truncate file succeed");  
}).catch((err: BusinessError) => {  
  console.info("truncate file failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## truncateSync    
以同步方法截断文件。  
 **调用形式：**     
- truncateSync(file: string | number, len?: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| file | string | true | 文件的应用沙箱路径或已打开的文件描述符fd。 |  
| len | number | false | 文件截断后的长度，以字节为单位。默认为0。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900023 |  |  
| 13900024 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let len: number = 5;  
fs.truncateSync(filePath, len);    
```    
  
    
## unlink    
删除单个文件。  
 **调用形式：**     
    
- unlink(path: string): Promise\<void>    
起始版本： 9    
- unlink(path: string): Promise\<void>    
起始版本： 10    
- unlink(path: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- unlink(path: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步删除文件之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.unlink(filePath, (err: BusinessError) => {  
  if (err) {  
    console.info("remove file failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("remove file succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fs.unlink(filePath).then(() => {  
  console.info("remove file succeed");  
}).catch((err: BusinessError) => {  
  console.info("remove file failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## unlinkSync    
以同步方法删除文件。  
 **调用形式：**     
- unlinkSync(path: string): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件的应用沙箱路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900002 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900014 |  |  
| 13900018 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900027 |  |  
| 13900030 |  |  
| 13900033 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
fs.unlinkSync(filePath);    
```    
  
    
## write    
将数据写入文件。  
 **调用形式：**     
    
- write(   fd: number,   buffer: ArrayBuffer | string,   options?: {     offset?: number;     length?: number;     encoding?: string;   } ): Promise\<number>    
起始版本： 9    
- write(   fd: number,   buffer: ArrayBuffer | string,   options?: {     offset?: number;     length?: number;     encoding?: string;   } ): Promise\<number>    
起始版本： 10    
- write(fd: number, buffer: ArrayBuffer | string, callback: AsyncCallback\<number>): void    
起始版本： 9    
- write(fd: number, buffer: ArrayBuffer | string, callback: AsyncCallback\<number>): void    
起始版本： 10    
- write(   fd: number,   buffer: ArrayBuffer | string,   options: {     offset?: number;     length?: number;     encoding?: string;   },   callback: AsyncCallback\<number> ): void    
起始版本： 9    
- write(   fd: number,   buffer: ArrayBuffer | string,   options: {     offset?: number;     length?: number;     encoding?: string;   },   callback: AsyncCallback\<number> ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
| buffer | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options | {     offset?: number;     length?: number;     encoding?: string;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。当前仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步将数据写入完成后执行的回调函数。 |  
| Promise<number> | Promise对象。返回实际写入的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
let str: string = "hello, world";  
fs.write(file.fd, str, (err: BusinessError, writeLen: number) => {  
  if (err) {  
    console.info("write data to file failed with error message:" + err.message + ", error code: " + err.code);  
  } else {  
    console.info("write data to file succeed and size is:" + writeLen);  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
let str: string = "hello, world";  
fs.write(file.fd, str).then((writeLen: number) => {  
  console.info("write data to file succeed and size is:" + writeLen);  
}).catch((err: BusinessError) => {  
  console.info("write data to file failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  fs.closeSync(file);  
});  
    
```    
  
    
## writeSync    
以同步方法将数据写入文件。  
 **调用形式：**     
- writeSync(   fd: number,   buffer: ArrayBuffer | string,   options?: {     offset?: number;     length?: number;     encoding?: string;   } ): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 已打开的文件描述符。 |  
| buffer | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options | {     offset?: number;     length?: number;     encoding?: string;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。当前仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际写入的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  let str: string = "hello, world";  let writeLen = fs.writeSync(file.fd, str);  console.info("write data to file succeed and size is:" + writeLen);  fs.closeSync(file);    
```    
  
    
## File    
由open接口打开的File对象。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fd | number | true | true | 打开的文件描述符。 |  
| path<sup>(10+)</sup> | string | true | true | 文件路径。 |  
| name<sup>(10+)</sup> | string | true | true | 文件名。 |  
    
### lock    
文件阻塞式施加共享锁或独占锁。  
 **调用形式：**     
    
- lock(exclusive?: boolean): Promise\<void>    
起始版本： 9    
- lock(callback: AsyncCallback\<void>): void    
起始版本： 9    
- lock(exclusive: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| exclusive | boolean | false | 是否施加独占锁，默认false。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步文件上锁之后的回调。 |  
| Promise<void> | Promise对象。无返回值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
| 13900043 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
file.lock(true, (err: BusinessError) => {  
  if (err) {  
    console.info("lock file failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.log("lock file succeed");  
  }  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
file.lock(true).then(() => {  
  console.log("lock file succeed");  
}).catch((err: BusinessError) => {  
  console.info("lock file failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  fs.closeSync(file);  
});  
    
```    
  
    
### tryLock    
文件非阻塞式施加共享锁或独占锁。  
 **调用形式：**     
- tryLock(exclusive?: boolean): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| exclusive | boolean | false | 是否施加独占锁，默认false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
| 13900043 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
file.tryLock(true);  
console.log("lock file succeed");  
fs.closeSync(file);    
```    
  
    
### unlock    
以同步方式给文件解锁。  
 **调用形式：**     
- unlock(): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
| 13900043 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
file.tryLock(true);  
file.unlock();  
console.log("unlock file succeed");  
fs.closeSync(file);    
```    
  
    
## RandomAccessFile<sup>(10+)</sup>    
随机读写文件流，在调用RandomAccessFile的方法前，需要先通过createRandomAccess()方法（同步或异步）来构建一个RandomAccessFile实例。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fd<sup>(10+)</sup> | number | true | true | 打开的文件描述符。 |  
| filePointer<sup>(10+)</sup> | number | true | true | RandomAccessFile对象的偏置指针。 |  
    
### setFilePointer<sup>(10+)</sup>    
设置文件偏置指针。  
 **调用形式：**     
- setFilePointer(filePointer: number): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filePointer | number | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900020 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
randomAccessFile.setFilePointer(1);  
randomAccessFile.close();    
```    
  
    
### close<sup>(10+)</sup>    
同步关闭RandomAccessFile对象。  
 **调用形式：**     
- close(): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900025 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let randomAccessFile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
randomAccessFile.close();    
```    
  
    
### write<sup>(10+)</sup>    
将数据写入文件。  
 **调用形式：**     
    
- write(     buffer: ArrayBuffer | string,     options?: {       offset?: number;       length?: number;       encoding?: string;     }   ): Promise\<number>    
起始版本： 10    
- write(buffer: ArrayBuffer | string, callback: AsyncCallback\<number>): void    
起始版本： 10    
- write(     buffer: ArrayBuffer | string,     options: {       offset?: number;       length?: number;       encoding?: string;     },     callback: AsyncCallback\<number>   ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options | {       offset?: number;       length?: number;       encoding?: string;     } | false | 支持如下选项：<br/>-length，number类型，表示期望写入数据的长度。默认缓冲区长度。<br/>-offset，number类型，表示期望写入文件位置（基于当前filePointer加上offset的位置）。可选，默认从偏置指针（filePointer）开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步写入完成后执行的回调函数。 |  
| Promise<number> | Promise对象。返回实际写入的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
let randomAccessFile = fs.createRandomAccessFileSync(file);  
let bufferLength: number = 4096;  
class Option {  
  offset: number = 0;  
  length: number = bufferLength;  
  encoding: string = 'utf-8';  
}  
let option = new Option();  
option.offset = 1;  
let arrayBuffer = new ArrayBuffer(bufferLength);  
randomAccessFile.write(arrayBuffer, option, (err: BusinessError, bytesWritten: number) => {  
  if (err) {  
    console.info("write failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    if (bytesWritten) {  
      console.info("write succeed and size is:" + bytesWritten);  
    }  
  }  
  randomAccessFile.close();  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
let randomAccessFile = fs.createRandomAccessFileSync(file);  
let bufferLength: number = 4096;  
class Option {  
  offset: number = 0;  
  length: number = 0;  
  encoding: string = 'utf-8';  
}  
let option = new Option();  
option.offset = 1;  
option.length = 5;  
let arrayBuffer = new ArrayBuffer(bufferLength);  
randomaccessfile.write(arrayBuffer, option).then((bytesWritten: number) => {  
  console.info("randomAccessFile bytesWritten: " + bytesWritten);  
}).catch((err: BusinessError) => {  
  console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  randomAccessFile.close();  
  fs.closeSync(file);  
});  
    
```    
  
    
### writeSync<sup>(10+)</sup>    
以同步方法将数据写入文件。  
 **调用形式：**     
- writeSync(     buffer: ArrayBuffer | string,     options?: {       offset?: number;       length?: number;       encoding?: string;     }   ): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options | {       offset?: number;       length?: number;       encoding?: string;     } | false | 支持如下选项：<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度。<br/>-offset，number类型，表示期望写入文件位置（基于当前filePointer加上offset的位置）。可选，默认从偏置指针（filePointer）开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际写入的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
  let randomaccessfile = fs.createRandomAccessFileSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
  class Option {  
    offset: number = 0;  
    length: number = 0;  
    encoding: string = 'utf-8';  
  }  
  let option = new Option();  
  option.offset = 5;  
  option.length = 5;  
  let bytesWritten = randomaccessfile.writeSync("hello, world", option);  
  randomaccessfile.close();  
    
```    
  
    
### read<sup>(10+)</sup>    
从文件读取数据。  
 **调用形式：**     
    
- read(     buffer: ArrayBuffer,     options?: {       offset?: number;       length?: number;     }   ): Promise\<number>    
起始版本： 10    
- read(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void    
起始版本： 10    
- read(     buffer: ArrayBuffer,     options: {       offset?: number;       length?: number;     },     callback: AsyncCallback\<number>   ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | ArrayBuffer | true | 用于读取文件的缓冲区。 |  
| options | {       offset?: number;       length?: number;     } | false | 支持如下选项：<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度。<br/>-offset，number类型，表示期望读取文件位置（基于当前filePointer加上offset的位置）。可选，默认从偏置指针（filePointer）开始读。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步从流文件读取数据之后的回调。 |  
| Promise<number> | Promise对象。返回读取的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
let randomAccessFile = fs.createRandomAccessFileSync(file);  
let length: number = 20;  
class Option {  
  offset: number = 0;  
  length: number = length;  
}  
let option = new Option();  
option.offset = 1;  
option.length = 5;  
let arrayBuffer = new ArrayBuffer(length);  
randomaccessfile.read(arrayBuffer, option, (err: BusinessError, readLength: number) => {  
  if (err) {  
    console.info("read failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    if (readLength) {  
      console.info("read succeed and size is:" + readLength);  
    }  
  }  
  randomAccessFile.close();  
  fs.closeSync(file);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
let randomAccessFile = fs.createRandomAccessFileSync(file);  
let bufferLength: number = 4096;  
class Option {  
  offset: number = 0;  
  length: number = bufferLength;  
}  
let option = new Option();  
option.offset = 1;  
option.length = 5;  
let arrayBuffer = new ArrayBuffer(bufferLength);  
randomaccessfile.read(arrayBuffer, option).then((readLength: number) => {  
  console.info("randomAccessFile readLength: " + readLength);  
}).catch((err: BusinessError) => {  
  console.info("create randomAccessFile failed with error message: " + err.message + ", error code: " + err.code);  
}).finally(() => {  
  randomAccessFile.close();  
  fs.closeSync(file);  
});  
    
```    
  
    
### readSync<sup>(10+)</sup>    
以同步方法从文件读取数据。  
 **调用形式：**     
- readSync(     buffer: ArrayBuffer,     options?: {       offset?: number;       length?: number;     }   ): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | ArrayBuffer | true | 用于读取文件的缓冲区。 |  
| options | {       offset?: number;       length?: number;     } | false | 支持如下选项：<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度。<br/>-offset，number类型，表示期望读取文文件位置（基于当前filePointer加上offset的位置）。可选，默认从偏置指针（filePointer）开始读。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际读取的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + "/test.txt";  
  let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);  
  let randomaccessfile = fs.createRandomAccessFileSync(file);  
  let length: number = 4096;  
  let arrayBuffer = new ArrayBuffer(length);  
  let readLength = randomaccessfile.readSync(arrayBuffer);  
  randomaccessfile.close();  
  fs.closeSync(file);  
    
```    
  
    
## Stat    
文件具体信息，在调用Stat的方法前，需要先通过[stat()](#fsstat)方法（同步或异步）来构建一个Stat实例。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ino | bigint | true | true | 标识该文件。通常同设备上的不同文件的INO不同。 |  
| mode | number | true | true | 表示文件权限，各特征位的含义如下：<br/>**说明：** 以下值为八进制，取得的返回值为十进制，请换算后查看。<br/>-0o400：用户读，对于普通文件，所有者可读取文件；对于目录，所有者可读取目录项。<br/>-0o200：用户写，对于普通文件，所有者可写入文件；对于目录，所有者可创建/删除目录项。<br/>-0o100：用户执行，对于普通文件，所有者可执行文件；对于目录，所有者可在目录中搜索给定路径名。<br/>-0o040：用户组读，对于普通文件，所有用户组可读取文件；对于目录，所有用户组可读取目录项。<br/>-0o020：用户组写，对于普通文件，所有用户组可写入文件；对于目录，所有用户组可创建/删除目录项。<br/>-0o010：用户组执行，对于普通文件，所有用户组可执行文件；对于目录，所有用户组是否可在目录中搜索给定路径名。<br/>-0o004：其他读，对于普通文件，其余用户可读取文件；对于目录，其他用户组可读取目录项。<br/>-0o002：其他写，对于普通文件，其余用户可写入文件；对于目录，其他用户组可创建/删除目录项。<br/>-0o001：其他执行，对于普通文件，其余用户可执行文件；对于目录，其他用户组可在目录中搜索给定路径名。 |  
| uid | number | true | true | 文件所有者的ID。 |  
| gid | number | true | true | 文件所有组的ID。 |  
| size | number | true | true | 文件的大小，以字节为单位。仅对普通文件有效。 |  
| atime | number | true | true | 上次访问该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |  
| mtime | number | true | true | 上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |  
| ctime | number | true | true | 最近改变文件状态的时间，表示距1970年1月1日0时0分0秒的秒数。 |  
    
### isBlockDevice    
用于判断文件是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。  
 **调用形式：**     
- isBlockDevice(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是块特殊设备。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isBLockDevice = fs.statSync(filePath).isBlockDevice();    
```    
  
    
### isCharacterDevice    
用于判断文件是否是字符特殊文件。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。  
 **调用形式：**     
- isCharacterDevice(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是字符特殊设备。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isCharacterDevice = fs.statSync(filePath).isCharacterDevice();    
```    
  
    
### isDirectory    
用于判断文件是否是目录。  
 **调用形式：**     
- isDirectory(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是目录。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let dirPath = pathDir + "/test";  
let isDirectory = fs.statSync(dirPath).isDirectory();     
```    
  
    
### isFIFO    
用于判断文件是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。  
 **调用形式：**     
- isFIFO(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是FIFO。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isFIFO = fs.statSync(filePath).isFIFO();     
```    
  
    
### isFile    
用于判断文件是否是普通文件。  
 **调用形式：**     
- isFile(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是普通文件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isFile = fs.statSync(filePath).isFile();    
```    
  
    
### isSocket    
用于判断文件是否是套接字。  
 **调用形式：**     
- isSocket(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是套接字。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isSocket = fs.statSync(filePath).isSocket();     
```    
  
    
### isSymbolicLink    
用于判断文件是否是符号链接。  
 **调用形式：**     
- isSymbolicLink(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是符号链接。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900005 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test";  
let isSymbolicLink = fs.statSync(filePath).isSymbolicLink();     
```    
  
    
## Stream    
文件流，在调用Stream的方法前，需要先通过createStream()方法（同步或异步）来构建一个Stream实例。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### close    
关闭文件流。  
 **调用形式：**     
    
- close(): Promise\<void>    
起始版本： 9    
- close(callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步关闭文件流之后的回调。 |  
| Promise<void> | Promise对象。返回表示异步关闭文件流的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900025 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
stream.close((err: BusinessError) => {  
  if (err) {  
    console.info("close stream failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("close stream succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
stream.close().then(() => {  
  console.info("close fileStream succeed");  
}).catch((err: BusinessError) => {  
  console.info("close fileStream  failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
### closeSync    
同步关闭文件流。  
 **调用形式：**     
- closeSync(): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900025 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
stream.flush().then(() => {  
  console.info("flush succeed");  
}).catch((err: BusinessError) => {  
  console.info("flush failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
### flush    
刷新文件流。  
 **调用形式：**     
    
- flush(): Promise\<void>    
起始版本： 9    
- flush(callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步刷新文件流后的回调函数。 |  
| Promise<void> | Promise对象。返回表示异步刷新文件流的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
stream.flush((err: BusinessError) => {  
  if (err) {  
    console.info("flush stream failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("flush succeed");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
stream.flush().then(() => {  
  console.info("flush succeed");  
}).catch((err: BusinessError) => {  
  console.info("flush failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
### flushSync    
同步刷新文件流。  
 **调用形式：**     
- flushSync(): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
stream.flushSync();    
```    
  
    
### write    
将数据写入流文件。  
 **调用形式：**     
    
- write(     buffer: ArrayBuffer | string,     options?: {       offset?: number;       length?: number;       encoding?: string;     }   ): Promise\<number>    
起始版本： 9    
- write(buffer: ArrayBuffer | string, callback: AsyncCallback\<number>): void    
起始版本： 9    
- write(     buffer: ArrayBuffer | string,     options: {       offset?: number;       length?: number;       encoding?: string;     },     callback: AsyncCallback\<number>   ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options | {       offset?: number;       length?: number;       encoding?: string;     } | false | 支持如下选项：<br/>-length，number类型，表示期望写入数据的长度。默认缓冲区长度。<br/>-offset，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步写入完成后执行的回调函数。 |  
| Promise<number> | Promise对象。返回实际写入的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
class Option {  
  offset: number = 0;  
  length: number = 0;  
  encoding: string = 'utf-8';  
}  
let option = new Option();  
option.offset = 5;  
option.length = 5;  
stream.write("hello, world", option, (err: BusinessError, bytesWritten: number) => {  
  if (err) {  
    console.info("write stream failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    if (bytesWritten) {  
      console.info("write succeed and size is:" + bytesWritten);  
    }  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
class Option {  
  offset: number = 0;  
  length: number = 0;  
  encoding: string = 'utf-8';  
}  
let option = new Option();  
option.offset = 5;  
option.length = 5;  
stream.write("hello, world", option).then((number: number) => {  
  console.info("write succeed and size is:" + number);  
}).catch((err: BusinessError) => {  
  console.info("write failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
### writeSync    
以同步方法将数据写入流文件。  
 **调用形式：**     
- writeSync(     buffer: ArrayBuffer | string,     options?: {       offset?: number;       length?: number;       encoding?: string;     }   ): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options | {       offset?: number;       length?: number;       encoding?: string;     } | false | 支持如下选项：<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度。<br/>-offset，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际写入的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 |  |  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900020 |  |  
| 13900024 |  |  
| 13900025 |  |  
| 13900034 |  |  
| 13900041 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
  let ss = fs.createStreamSync(filePath,"r+");  
  class Option {  
    offset: number = 0;  
    length: number = 0;  
    encoding: string = 'utf-8';  
  }  
  let option = new Option();  
  option.offset = 5;  
  option.length = 5;  
  let num = ss.writeSync("hello, world", option);  
    
```    
  
    
### read    
从流文件读取数据。  
 **调用形式：**     
    
- read(     buffer: ArrayBuffer,     options?: {       offset?: number;       length?: number;     }   ): Promise\<number>    
起始版本： 9    
- read(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void    
起始版本： 9    
- read(     buffer: ArrayBuffer,     options: {       offset?: number;       length?: number;     },     callback: AsyncCallback\<number>   ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | ArrayBuffer | true | 用于读取文件的缓冲区。 |  
| options | {       offset?: number;       length?: number;     } | false | 支持如下选项：<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度。<br/>-offset，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步从流文件读取数据之后的回调。 |  
| Promise<number> | Promise对象。返回读取的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
import buffer from '@ohos.buffer';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
let arrayBuffer = new ArrayBuffer(4096);  
class Option {  
  offset: number = 0;  
  length: number = 0;  
}  
let option = new Option();  
option.offset = 5;  
option.length = 5;  
stream.read(arrayBuffer, option, (err: BusinessError, readLen: number) => {  
  if (err) {  
    console.info("read stream failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("read data succeed");  
    let buf = buffer.from(arrayBuffer, 0, readLen);  
    console.log(`The content of file: ${buf.toString()}`);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
import buffer from '@ohos.buffer';  
let filePath = pathDir + "/test.txt";  
let stream = fs.createStreamSync(filePath, "r+");  
let arrayBuffer = new ArrayBuffer(4096);  
class Option {  
  offset: number = 0;  
  length: number = 0;  
}  
let option = new Option();  
option.offset = 5;  
option.length = 5;  
stream.read(arrayBuffer, option).then((readLen: number) => {  
  console.info("read data succeed");  
  let buf = buffer.from(arrayBuffer, 0, readLen);  
  console.log(`The content of file: ${buf.toString()}`);  
}).catch((err: BusinessError) => {  
  console.info("read data failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
### readSync    
以同步方法从流文件读取数据。  
 **调用形式：**     
- readSync(     buffer: ArrayBuffer,     options?: {       offset?: number;       length?: number;     }   ): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer | ArrayBuffer | true | 用于读取文件的缓冲区。 |  
| options | {       offset?: number;       length?: number;     } | false | 支持如下选项：<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度。<br/>-offset，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际读取的长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900004 |  |  
| 13900005 |  |  
| 13900008 |  |  
| 13900010 |  |  
| 13900013 |  |  
| 13900019 |  |  
| 13900020 |  |  
| 13900034 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let ss = fs.createStreamSync(filePath, "r+");  
class Option {  
offset: number = 0;  
length: number = 0;  
}  
let option = new Option();  
option.offset = 5;  
option.length = 5;  
let buf = new ArrayBuffer(4096);  
let num = ss.readSync(buf, option);  
    
```    
  
    
## WatchEventListener<sup>(10+)</sup>    
事件监听类。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### null<sup>(10+)</sup>  
 **调用形式：**     
- (event: WatchEvent): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | WatchEvent | true | 回调的事件类。 |  
    
## WatchEvent<sup>(10+)</sup>    
事件类  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fileName<sup>(10+)</sup> | string | true | true | 发生监听事件的文件名。 |  
| event<sup>(10+)</sup> | number | true | true | 发生的监听事件。与[createWatcher](#fscreatewatcher10)中events事件集一致。 |  
| cookie<sup>(10+)</sup> | number | true | true | 绑定相关事件的cookie。当前仅支持事件IN_MOVED_FROM与IN_MOVED_TO，同一个文件的移动事件IN_MOVED_FROM和IN_MOVED_TO具有相同的cookie值。 |  
    
## Watcher<sup>(10+)</sup>    
文件目录变化监听对象。由createWatcher接口获得。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### start<sup>(10+)</sup>    
开启监听。  
 **调用形式：**     
- start(): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900021 |  |  
| 13900022 |  |  
| 13900025 |  |  
| 13900030 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let watcher = fs.createWatcher(filePath, 0xfff, () => {});  
watcher.start();  
watcher.stop();    
```    
  
    
### stop<sup>(10+)</sup>    
停止监听。  
 **调用形式：**     
- stop(): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 |  |  
| 13900008 |  |  
| 13900011 |  |  
| 13900012 |  |  
| 13900013 |  |  
| 13900015 |  |  
| 13900018 |  |  
| 13900020 |  |  
| 13900021 |  |  
| 13900022 |  |  
| 13900025 |  |  
| 13900030 |  |  
| 13900042 |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let watcher = fs.createWatcher(filePath, 0xfff, () => {});  
watcher.start();  
watcher.stop();    
```    
  
    
## Filter<sup>(10+)</sup>    
文件过滤配置项类型，支持listFile接口使用。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| suffix<sup>(10+)</sup> | Array<string> | false | false | 文件后缀名完全匹配，各个关键词OR关系。 |  
| displayName<sup>(10+)</sup> | Array<string> | false | false | 文件名模糊匹配，各个关键词OR关系。当前仅支持通配符*。 |  
| mimeType<sup>(10+)</sup> | Array<string> | false | false | mime类型完全匹配，各个关键词OR关系。 |  
| fileSizeOver<sup>(10+)</sup> | number | false | false | 文件大小匹配，大于等于指定大小的文件。 |  
| lastModifiedAfter<sup>(10+)</sup> | number | false | false | 文件最近修改时间匹配，在指定时间点及之后的文件。 |  
| excludeMedia<sup>(10+)</sup> | boolean | false | false | 是否排除Media中已有的文件。 |  
    
## ConflictFiles<sup>(10+)</sup>    
冲突文件信息，支持copyDir及moveDir接口使用。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| srcFile<sup>(10+)</sup> | string | false | true | 源冲突文件路径。 |  
| destFile<sup>(10+)</sup> | string | false | true | 目标冲突文件路径。 |  
