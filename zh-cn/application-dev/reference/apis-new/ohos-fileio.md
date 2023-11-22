# @ohos.fileio    
该模块提供文件存储管理能力，包括文件基本管理、文件目录管理、文件信息统计、文件流式读写等常用功能。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import fileIO from '@ohos.fileio'    
```  
    
## access<sup>(deprecated)</sup>    
检查当前进程是否可访问某文件，使用Promise异步回调。  
 **调用形式：**     
- access(path: string, mode?: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.access。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待访问文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | false | 访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。<br/>确认当前进程是否具有对应权限：<br/>-0：确认文件是否存在。<br/>-1：确认当前进程是否具有可执行权限。<br/>-2：确认当前进程是否具有写权限。<br/>-4：确认当前进程是否具有读权限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.access(filePath).then(() => {  
  console.info("access succeed");  
}).catch((err: BusinessError) => {  
  console.info("access failed with error:" + err);  
});  
    
```    
  
    
## access<sup>(deprecated)</sup>    
检查当前进程是否可访问某文件，使用callback异步回调。  
 **调用形式：**     
- access(path: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.access。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待访问文件的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步检查当前进程是否可访问某文件之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.access(filePath, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## access<sup>(deprecated)</sup>    
检查当前进程是否可访问某文件，使用callback异步回调。  
 **调用形式：**     
- access(path: string, mode: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.access。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待访问文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | true | 访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。<br/>确认当前进程是否具有对应权限：<br/>-0：确认文件是否存在。<br/>-1：确认当前进程是否具有可执行权限。<br/>-2：确认当前进程是否具有写权限。<br/>-4：确认当前进程是否具有读权限。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步检查当前进程是否可访问某文件之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.access(filePath, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## accessSync<sup>(deprecated)</sup>    
以同步方法检查当前进程是否可访问某文件。  
 **调用形式：**     
- accessSync(path: string, mode?: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.accessSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待访问文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | false | 访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。<br/>确认当前进程是否具有对应权限：<br/>-0：确认文件是否存在。<br/>-1：确认当前进程是否具有可执行权限。<br/>-2：确认当前进程是否具有写权限。<br/>-4：确认当前进程是否具有读权限。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
try {  
  fileio.accessSync(filePath);  
} catch(err: unknown) {  
  console.info("accessSync failed with error:" + err);  
}  
    
```    
  
    
## close<sup>(deprecated)</sup>    
关闭文件，使用Promise异步回调。  
 **调用形式：**     
- close(fd: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.close。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待关闭文件的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.close(fd).then(() => {  
  console.info("close file succeed");  
}).catch((err: BusinessError) => {  
  console.info("close file failed with error:" + err);  
});  
    
```    
  
    
## close<sup>(deprecated)</sup>    
关闭文件，使用callback异步回调。  
 **调用形式：**     
- close(fd: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.close。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待关闭文件的文件描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步关闭文件之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.close(fd, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## closeSync<sup>(deprecated)</sup>    
以同步方法关闭文件。  
 **调用形式：**     
- closeSync(fd: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.closeSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待关闭文件的文件描述符。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.closeSync(fd);    
```    
  
    
## copyFile<sup>(deprecated)</sup>    
复制文件，使用Promise异步回调。  
 **调用形式：**     
- copyFile(src: string | number, dest: string | number, mode?: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.copyFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | true | 待复制文件的路径或待复制文件的描述符。 |  
| dest<sup>(deprecated)</sup> | string | true | 目标文件路径或目标文件描述符。 |  
| mode<sup>(deprecated)</sup> | number | false | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁切掉。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcPath = pathDir + "srcDir/test.txt";  
let dstPath = pathDir + "dstDir/test.txt";  
fileio.copyFile(srcPath, dstPath).then(() => {  
  console.info("copyFile succeed");  
}).catch((err: BusinessError) => {  
  console.info("copyFile failed with error:" + err);  
});  
    
```    
  
    
## copyFile<sup>(deprecated)</sup>    
复制文件，使用callback异步回调。  
 **调用形式：**     
- copyFile(src: string | number, dest: string | number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.copyFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | true | 待复制文件的路径或待复制文件的描述符。 |  
| dest<sup>(deprecated)</sup> | string | true | 目标文件路径或目标文件描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步复制文件之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcPath = pathDir + "srcDir/test.txt";  
let dstPath = pathDir + "dstDir/test.txt";  
fileio.copyFile(srcPath, dstPath, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## copyFile<sup>(deprecated)</sup>  
 **调用形式：**     
- copyFile(   src: string | number,   dest: string | number,   mode: number,   callback: AsyncCallback\<void> ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.copyFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | true |  |  
| dest<sup>(deprecated)</sup> | string | true |  |  
| mode<sup>(deprecated)</sup> | number | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
    
## copyFileSync<sup>(deprecated)</sup>    
以同步方法复制文件。  
 **调用形式：**     
- copyFileSync(src: string | number, dest: string | number, mode?: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.copyFileSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | true | 待复制文件的路径或待复制文件的描述符。 |  
| dest<sup>(deprecated)</sup> | string | true | 目标文件路径或目标文件描述符。 |  
| mode<sup>(deprecated)</sup> | number | false | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁切掉。 |  
    
 **示例代码：**   
```ts    
let srcPath = pathDir + "srcDir/test.txt";  
let dstPath = pathDir + "dstDir/test.txt";  
fileio.copyFileSync(srcPath, dstPath);    
```    
  
    
## createStream<sup>(deprecated)</sup>    
基于文件路径打开文件流，使用Promise异步回调。  
 **调用形式：**     
- createStream(path: string, mode: string): Promise\<Stream>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.createStream。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Stream> | Promise对象。返回文件流的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.createStream(filePath, "r+").then((stream: fileio.Stream) => {  
  console.info("createStream succeed");  
}).catch((err: BusinessError) => {  
  console.info("createStream failed with error:" + err);  
});  
    
```    
  
    
## createStream<sup>(deprecated)</sup>    
基于文件路径打开文件流，使用callback异步回调。  
 **调用形式：**     
- createStream(path: string, mode: string, callback: AsyncCallback\<Stream>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.createStream。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Stream> | true | 异步打开文件流之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.createStream(filePath, "r+", (err: BusinessError, stream: fileio.Stream) => {  
  // do something  
});  
    
```    
  
    
## createStreamSync<sup>(deprecated)</sup>    
以同步方法基于文件路径打开文件流。  
 **调用形式：**     
- createStreamSync(path: string, mode: string): Stream  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.createStreamSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。  |  
| mode<sup>(deprecated)</sup> | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stream | 返回文件流的结果。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let ss = fileio.createStreamSync(filePath, "r+");    
```    
  
    
## chown<sup>(deprecated)</sup>    
基于文件路径改变文件所有者，使用Promise异步回调。  
 **调用形式：**     
- chown(path: string, uid: number, gid: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待改变文件的应用沙箱路径。 |  
| uid<sup>(deprecated)</sup> | number | true | 新的UID（UserID）。 |  
| gid<sup>(deprecated)</sup> | number | true | 新的GID（GroupID）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stat = fileio.statSync(filePath);  
fileio.chown(filePath, stat.uid, stat.gid).then(() => {  
  console.info("chown succeed");  
}).catch((err: BusinessError) => {  
  console.info("chown failed with error:" + err);  
});  
    
```    
  
    
## chown<sup>(deprecated)</sup>    
以同步的方法基于文件路径改变文件所有者。  
 **调用形式：**     
- chown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待改变文件的应用沙箱路径。 |  
| uid<sup>(deprecated)</sup> | number | true | 新的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 新的GID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步改变文件所有者之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let stat = fileio.statSync(filePath)  
fileio.chown(filePath, stat.uid, stat.gid, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## chownSync<sup>(deprecated)</sup>    
以同步的方法基于文件路径改变文件所有者。  
 **调用形式：**     
- chownSync(path: string, uid: number, gid: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待改变文件的应用沙箱路径。 |  
| uid<sup>(deprecated)</sup> | number | true | 新的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 新的GID。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let stat = fileio.statSync(filePath)  
fileio.chownSync(filePath, stat.uid, stat.gid);    
```    
  
    
## chmod<sup>(deprecated)</sup>    
改变文件权限，使用Promise异步回调。  
 **调用形式：**     
- chmod(path: string, mode: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 所需变更权限的文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | true | 改变文件权限，可给定如下权限，以按位或的方式追加权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.chmod(filePath, 0o700).then(() => {  
  console.info("chmod succeed");  
}).catch((err: BusinessError) => {  
  console.info("chmod failed with error:" + err);  
});  
    
```    
  
    
## chmod<sup>(deprecated)</sup>    
改变文件权限，使用callback异步回调。  
 **调用形式：**     
- chmod(path: string, mode: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 所需变更权限的文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | true | 改变文件权限，可给定如下权限，以按位或的方式追加权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步改变文件权限之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.chmod(filePath, 0o700, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## chmodSync<sup>(deprecated)</sup>    
以同步方法改变文件权限。  
 **调用形式：**     
- chmodSync(path: string, mode: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 所需变更权限的文件的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | true |  改变文件权限，可给定如下权限，以按位或的方式追加权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
fileio.chmodSync(filePath, 0o700);    
```    
  
    
## ftruncate<sup>(deprecated)</sup>    
基于文件描述符截断文件，使用Promise异步回调。  
 **调用形式：**     
- ftruncate(fd: number, len?: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncate。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待截断文件的文件描述符。 |  
| len<sup>(deprecated)</sup> | number | false | 文件截断后的长度，以字节为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.ftruncate(fd, 5).then(() => {  
  console.info("truncate file succeed");  
}).catch((err: BusinessError) => {  
  console.info("truncate file failed with error:" + err);  
});  
    
```    
  
    
## ftruncate<sup>(deprecated)</sup>    
基于文件描述符截断文件，使用callback异步回调。  
 **调用形式：**     
- ftruncate(fd: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncate。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待截断文件的文件描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数，本调用无返回值。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let len = 5;  
fileio.ftruncate(fd, 5, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## ftruncate<sup>(deprecated)</sup>    
基于文件描述符截断文件，使用callback异步回调。  
 **调用形式：**     
- ftruncate(fd: number, len: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncate。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待截断文件的文件描述符。 |  
| len<sup>(deprecated)</sup> | number | true | 文件截断后的长度，以字节为单位。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数，本调用无返回值。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let len = 5;  
fileio.ftruncate(fd, 5, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## ftruncateSync<sup>(deprecated)</sup>    
以同步方法基于文件描述符截断文件。  
 **调用形式：**     
- ftruncateSync(fd: number, len?: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncateSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待截断文件的文件描述符。 |  
| len<sup>(deprecated)</sup> | number | false | 文件截断后的长度，以字节为单位。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let len = 5;  
fileio.ftruncateSync(fd, len);    
```    
  
    
## fsync<sup>(deprecated)</sup>    
同步文件数据，使用Promise异步回调。  
 **调用形式：**     
- fsync(fd: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fsync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待同步文件的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fsync(fd).then(() => {  
  console.info("sync data succeed");  
}).catch((err: BusinessError) => {  
  console.info("sync data failed with error:" + err);  
});  
    
```    
  
    
## fsync<sup>(deprecated)</sup>    
同步文件数据，使用callback异步回调。  
 **调用形式：**     
- fsync(fd: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fsync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待同步文件的文件描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步将文件数据同步之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fsync(fd, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## fsyncSync<sup>(deprecated)</sup>    
以同步方法同步文件数据。  
 **调用形式：**     
- fsyncSync(fd: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fsyncSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fsyncSync(fd);    
```    
  
    
## fstat<sup>(deprecated)</sup>    
同步文件数据，使用Promise异步回调。  
 **调用形式：**     
- fstat(fd: number): Promise\<Stat>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.stat。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待同步文件的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Stat> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fstat(fd).then((stat: fileio.Stat) => {  
  console.info("fstat succeed, the size of file is " + stat.size);  
}).catch((err: BusinessError) => {  
  console.info("fstat failed with error:" + err);  
});  
    
```    
  
    
## fstat<sup>(deprecated)</sup>    
同步文件数据，使用callback异步回调。  
 **调用形式：**     
- fstat(fd: number, callback: AsyncCallback\<Stat>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.stat。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待同步文件的文件描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Stat> | true | 异步将文件数据同步之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fstat(fd, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## fstatSync<sup>(deprecated)</sup>    
以同步方法基于文件描述符获取文件状态信息。  
 **调用形式：**     
- fstatSync(fd: number): Stat  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.statSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待获取文件状态的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stat | 表示文件状态的具体信息。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let stat = fileio.fstatSync(fd);    
```    
  
    
## fdatasync<sup>(deprecated)</sup>    
实现文件内容数据同步，使用Promise异步回调。  
 **调用形式：**     
- fdatasync(fd: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fdatasync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待获取文件状态的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fdatasync(fd).then(() => {  
  console.info("sync data succeed");  
}).catch((err: BusinessError) => {  
  console.info("sync data failed with error:" + err);  
});  
    
```    
  
    
## fdatasync<sup>(deprecated)</sup>    
实现文件内容数据同步，使用callback异步回调。  
 **调用形式：**     
- fdatasync(fd: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fdatasync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待获取文件状态的文件描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步将文件内容数据同步之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fdatasync (fd, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## fdatasyncSync<sup>(deprecated)</sup>    
以同步方法实现文件内容数据同步。  
 **调用形式：**     
- fdatasyncSync(fd: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fdatasyncSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待同步文件的文件描述符。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let stat = fileio.fdatasyncSync(fd);    
```    
  
    
## fchown<sup>(deprecated)</sup>    
基于文件描述符改变文件所有者，使用Promise异步回调。  
 **调用形式：**     
- fchown(fd: number, uid: number, gid: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待改变文件的文件描述符。 |  
| uid<sup>(deprecated)</sup> | number | true | 文件所有者的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 文件所有组的GID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let stat = fileio.statSync(filePath);  
fileio.fchown(fd, stat.uid, stat.gid).then(() => {  
  console.info("chown succeed");  
}).catch((err: BusinessError) => {  
  console.info("chown failed with error:" + err);  
});  
    
```    
  
    
## fchown<sup>(deprecated)</sup>    
基于文件描述符改变文件所有者，使用callback异步回调。  
 **调用形式：**     
- fchown(fd: number, uid: number, gid: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待改变文件的文件描述符。 |  
| uid<sup>(deprecated)</sup> | number | true | 文件所有者的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 文件所有组的GID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步改变文件所有者之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let stat = fileio.statSync(filePath);  
fileio.fchown(fd, stat.uid, stat.gid, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## fchownSync<sup>(deprecated)</sup>    
以同步方法基于文件描述符改变文件所有者。  
 **调用形式：**     
- fchownSync(fd: number, uid: number, gid: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待改变文件的文件描述符。 |  
| uid<sup>(deprecated)</sup> | number | true | 文件所有者的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 文件所有组的GID。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let stat = fileio.statSync(filePath);  
fileio.fchownSync(fd, stat.uid, stat.gid);    
```    
  
    
## fchmod<sup>(deprecated)</sup>    
基于文件描述符改变文件权限，使用Promise异步回调。  
 **调用形式：**     
- fchmod(fd: number, mode: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待改变文件的文件描述符。 |  
| mode<sup>(deprecated)</sup> | number | true | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let mode: number = 0o700;  
fileio.fchmod(fd, mode).then(() => {  
  console.info("chmod succeed");  
}).catch((err: BusinessError) => {  
  console.info("chmod failed with error:" + err);  
});  
    
```    
  
    
## fchmod<sup>(deprecated)</sup>    
基于文件描述符改变文件权限，使用callback异步回调。  
 **调用形式：**     
- fchmod(fd: number, mode: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待改变文件的文件描述符。 |  
| mode<sup>(deprecated)</sup> | number | true | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步改变文件权限之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let mode: number = 0o700;  
fileio.fchmod(fd, mode, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## fchmodSync<sup>(deprecated)</sup>    
以同步方法基于文件描述符改变文件权限。  
 **调用形式：**     
- fchmodSync(fd: number, mode: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待改变文件的文件描述符。 |  
| mode<sup>(deprecated)</sup> | number | true | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let mode: number = 0o700;  
fileio.fchmodSync(fd, mode);    
```    
  
    
## fdopenStream<sup>(deprecated)</sup>    
基于文件描述符打开文件流，使用Promise异步回调。  
 **调用形式：**     
- fdopenStream(fd: number, mode: string): Promise\<Stream>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fdopenStream。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待打开文件的文件描述符。 |  
| mode<sup>(deprecated)</sup> | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Stream> | Promise对象。返回文件流的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fdopenStream(fd, "r+").then((stream: fileio.Stream) => {  
  console.info("openStream succeed");  
}).catch((err: BusinessError) => {  
  console.info("openStream failed with error:" + err);  
});  
    
```    
  
    
## fdopenStream<sup>(deprecated)</sup>    
基于文件描述符打开文件流，使用callback异步回调。  
 **调用形式：**     
- fdopenStream(fd: number, mode: string, callback: AsyncCallback\<Stream>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fdopenStream。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待打开文件的文件描述符。 |  
| mode<sup>(deprecated)</sup> | string | true |  -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Stream> | true | 异步打开文件流之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
fileio.fdopenStream(fd, "r+", (err: BusinessError, stream: fileio.Stream) => {  
  // do something  
});  
    
```    
  
    
## fdopenStreamSync<sup>(deprecated)</sup>    
以同步方法基于文件描述符打开文件流。  
 **调用形式：**     
- fdopenStreamSync(fd: number, mode: string): Stream  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.fdopenStreamSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待打开文件的文件描述符。 |  
| mode<sup>(deprecated)</sup> | string | true | -r：打开只读文件，该文件必须存在。<br/>-r+：打开可读写的文件，该文件必须存在。<br/>-w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stream | 返回文件流的结果。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath);  
let ss = fileio.fdopenStreamSync(fd, "r+");    
```    
  
    
## hash<sup>(deprecated)</sup>    
计算文件的哈希值，使用Promise异步回调。  
 **调用形式：**     
- hash(path: string, algorithm: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.hash.hash。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待计算哈希值文件的应用沙箱路径。 |  
| algorithm<sup>(deprecated)</sup> | string | true | 哈希计算采用的算法。可选"md5"、"sha1"或"sha256"。建议采用安全强度更高的"sha256"。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象。返回文件的哈希值。表示为十六进制数字串，所有字母均大写。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.hash(filePath, "sha256").then((str: string) => {  
  console.info("calculate file hash succeed:" + str);  
}).catch((err: BusinessError) => {  
  console.info("calculate file hash failed with error:" + err);  
});  
    
```    
  
    
## hash<sup>(deprecated)</sup>    
计算文件的哈希值，使用callback异步回调。  
 **调用形式：**     
- hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.hash.hash。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待计算哈希值文件的应用沙箱路径。 |  
| algorithm<sup>(deprecated)</sup> | string | true | 哈希计算采用的算法。可选"md5"、"sha1"或"sha256"。建议采用安全强度更高的"sha256"。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 异步计算文件哈希操作之后的回调函数（其中给定文件哈希值表示为十六进制数字串，所有字母均大写）。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.hash(filePath, "sha256", (err: BusinessError, hashStr: string) => {  
  if (hashStr) {  
    console.info("calculate file hash succeed:" + hashStr);  
  }  
});  
    
```    
  
    
## lchown<sup>(deprecated)</sup>    
基于文件路径改变文件所有者，更改符号链接本身的所有者，而不是符号链接所指向的实际文件，使用Promise异步回调。  
 **调用形式：**     
- lchown(path: string, uid: number, gid: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| uid<sup>(deprecated)</sup> | number | true | 新的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 新的GID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.chmod(filePath, 0o700).then(() => {  
  console.info("chmod succeed");  
}).catch((err: BusinessError) => {  
  console.info("chmod failed with error:" + err);  
});  
    
```    
  
    
## lchown<sup>(deprecated)</sup>    
基于文件路径改变文件所有者，更改符号链接本身的所有者，而不是更改符号链接所指向的实际文件，使用callback异步回调。  
 **调用形式：**     
- lchown(path: string, uid: number, gid: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| uid<sup>(deprecated)</sup> | number | true | 新的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 新的GID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步改变文件所有者之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.chmod(filePath, 0o700, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## lchownSync<sup>(deprecated)</sup>    
以同步方法基于文件路径改变文件所有者，更改符号链接本身的所有者，而不是更改符号链接所指向的实际文件。  
 **调用形式：**     
- lchownSync(path: string, uid: number, gid: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| uid<sup>(deprecated)</sup> | number | true | 新的UID。 |  
| gid<sup>(deprecated)</sup> | number | true | 新的GID。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
fileio.chmodSync(filePath, 0o700);    
```    
  
    
## lstat<sup>(deprecated)</sup>    
获取链接信息，使用Promise异步回调。  
 **调用形式：**     
- lstat(path: string): Promise\<Stat>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.lstat。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 目标文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Stat> | promise对象，返回文件对象，表示文件的具体信息，详情见stat |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.lstat(filePath).then((stat: fileio.Stat) => {  
  console.info("get link status succeed, the size of file is" + stat.size);  
}).catch((err: BusinessError) => {  
  console.info("get link status failed with error:" + err);  
});  
    
```    
  
    
## lstat<sup>(deprecated)</sup>    
获取链接信息，使用callback异步回调。  
 **调用形式：**     
- lstat(path: string, callback: AsyncCallback\<Stat>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.lstat。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 目标文件的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Stat> | true | 回调函数，返回文件的具体信息。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.lstat(filePath, (err: BusinessError, stat: fileio.Stat) => {  
  // do something  
});  
    
```    
  
    
## lstatSync<sup>(deprecated)</sup>    
以同步方法获取链接信息。  
 **调用形式：**     
- lstatSync(path: string): Stat  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.lstatSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 目标文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stat | 表示文件的具体信息。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let stat = fileio.lstatSync(filePath);    
```    
  
    
## mkdir<sup>(deprecated)</sup>    
创建目录，使用Promise异步回调。  
 **调用形式：**     
- mkdir(path: string, mode?: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.mkdir。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待创建目录的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | false | 创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。<br/>-0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + '/testDir';  
fileio.mkdir(dirPath).then(() => {  
  console.info("mkdir succeed");  
}).catch((error: BusinessError) => {  
  console.info("mkdir failed with error:" + error);  
});  
    
```    
  
    
## mkdir<sup>(deprecated)</sup>    
创建目录，使用callback异步回调。  
 **调用形式：**     
- mkdir(path: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.mkdir。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待创建目录的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步创建目录操作完成之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + '/testDir';  
fileio.mkdir(dirPath, (err: BusinessError) => {  
  console.info("mkdir succeed");  
});  
    
```    
  
    
## mkdir<sup>(deprecated)</sup>    
创建目录，使用callback异步回调。  
 **调用形式：**     
- mkdir(path: string, mode: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.mkdir。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待创建目录的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | true | 创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。<br/>-0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步创建目录操作完成之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + '/testDir';  
fileio.mkdir(dirPath, (err: BusinessError) => {  
  console.info("mkdir succeed");  
});  
    
```    
  
    
## mkdirSync<sup>(deprecated)</sup>    
以同步方法创建目录。  
 **调用形式：**     
- mkdirSync(path: string, mode?: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.mkdirSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待创建目录的应用沙箱路径。 |  
| mode<sup>(deprecated)</sup> | number | false | 创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。<br/>-0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
    
 **示例代码：**   
```ts    
let dirPath = pathDir + '/testDir';  
fileio.mkdirSync(dirPath);    
```    
  
    
## mkdtemp<sup>(deprecated)</sup>    
创建临时目录，使用Promise异步回调。  
 **调用形式：**     
- mkdtemp(prefix: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.mkdtemp。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix<sup>(deprecated)</sup> | string | true | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象。返回生成的唯一目录路径。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
fileio.mkdtemp(pathDir + "/XXXXXX").then((pathDir: string) => {  
  console.info("mkdtemp succeed:" + pathDir);  
}).catch((err: BusinessError) => {  
  console.info("mkdtemp failed with error:" + err);  
});  
    
```    
  
    
## mkdtemp<sup>(deprecated)</sup>    
创建临时目录，使用callback异步回调。  
 **调用形式：**     
- mkdtemp(prefix: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.mkdtemp。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix<sup>(deprecated)</sup> | string | true | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 异步创建临时目录之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
fileio.mkdtemp(pathDir + "/XXXXXX", (err: BusinessError, res: string) => {  
  // do something  
});  
    
```    
  
    
## mkdtempSync<sup>(deprecated)</sup>    
以同步的方法创建临时目录。  
 **调用形式：**     
- mkdtempSync(prefix: string): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.mkdtempSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix<sup>(deprecated)</sup> | string | true | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 产生的唯一目录路径。 |  
    
 **示例代码：**   
```ts    
let res = fileio.mkdtempSync(pathDir + "/XXXXXX");    
```    
  
    
## open<sup>(deprecated)</sup>    
打开文件，使用Promise异步回调。  
 **调用形式：**     
- open(path: string, flags?: number, mode?: number): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.open。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| flags<sup>(deprecated)</sup> | number | false | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-0o0：只读打开。<br/>-0o1：只写打开。<br/>-0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数mode。<br/>-0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-0o200000：如果path不指向目录，则出错。<br/>-0o400000：如果path指向符号链接，则出错。<br/>-0o4010000：以同步IO的方式打开文件。 |  
| mode<sup>(deprecated)</sup> | number | false | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o660。<br/>-0o660：所有者具有读、写权限，所有用户组具有读、写权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象。返回打开文件的文件描述符。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.open(filePath, 0o1, 0o0200).then((number: number) => {  
  console.info("open file succeed");  
}).catch((err: BusinessError) => {  
  console.info("open file failed with error:" + err);  
});  
    
```    
  
    
## open<sup>(deprecated)</sup>    
打开文件，使用callback异步回调。  
 **调用形式：**     
- open(path: string, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.open。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步打开文件之后的回调。 |  
    
## open<sup>(deprecated)</sup>    
打开文件，使用callback异步回调。  
 **调用形式：**     
- open(path: string, flags: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.open。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| flags<sup>(deprecated)</sup> | number | true | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-0o0：只读打开。<br/>-0o1：只写打开。<br/>-0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数mode。<br/>-0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-0o200000：如果path不指向目录，则出错。<br/>-0o400000：如果path指向符号链接，则出错。<br/>-0o4010000：以同步IO的方式打开文件。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步打开文件之后的回调。 |  
    
## open<sup>(deprecated)</sup>    
打开文件，使用callback异步回调。  
 **调用形式：**     
- open(path: string, flags: number, mode: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.open。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| flags<sup>(deprecated)</sup> | number | true | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-0o0：只读打开。<br/>-0o1：只写打开。<br/>-0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数mode。<br/>-0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-0o200000：如果path不指向目录，则出错。<br/>-0o400000：如果path指向符号链接，则出错。<br/>-0o4010000：以同步IO的方式打开文件。 |  
| mode<sup>(deprecated)</sup> | number | true | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o660。<br/>-0o660：所有者具有读、写权限，所有用户组具有读、写权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步打开文件之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.open(filePath, 0, (err: BusinessError, fd: number) => {  
  // do something  
});  
    
```    
  
    
## openSync<sup>(deprecated)</sup>    
以同步方法打开文件。  
 **调用形式：**     
- openSync(path: string, flags?: number, mode?: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.openSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件的应用沙箱路径。 |  
| flags<sup>(deprecated)</sup> | number | false | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-0o0：只读打开。<br/>-0o1：只写打开。<br/>-0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数mode。<br/>-0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续IO进行非阻塞操作。<br/>-0o200000：如果path不指向目录，则出错。<br/>-0o400000：如果path指向符号链接，则出错。<br/>-0o4010000：以同步IO的方式打开文件。 |  
| mode<sup>(deprecated)</sup> | number | false | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o660。<br/>-0o660：所有者具有读、写权限，所有用户组具有读、写权限。<br/>-0o640：所有者具有读、写权限，所有用户组具有读权限。<br/>-0o700：所有者具有读、写及可执行权限。<br/>-0o400：所有者具有读权限。<br/>-0o200：所有者具有写权限。<br/>-0o100：所有者具有可执行权限。<br/>-0o070：所有用户组具有读、写及可执行权限。<br/>-0o040：所有用户组具有读权限。<br/>-0o020：所有用户组具有写权限。<br/>-0o010：所有用户组具有可执行权限。<br/>-0o007：其余用户具有读、写及可执行权限。<br/>-0o004：其余用户具有读权限。<br/>-0o002：其余用户具有写权限。<br/>-0o001：其余用户具有可执行权限。<br/>创建出的文件权限受umask影响，umask随进程启动确定，其修改当前不开放。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 打开文件的文件描述符。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath, 0o102, 0o640);    
```    
  
    
## opendir<sup>(deprecated)</sup>    
打开文件目录，使用Promise异步回调。  
 **调用形式：**     
- opendir(path: string): Promise\<Dir>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件目录的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Dir> | Promise对象。返回Dir对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + "/testDir";  
fileio.opendir(dirPath).then((dir: fileio.Dir) => {  
  console.info("opendir succeed");  
}).catch((err: BusinessError) => {  
  console.info("opendir failed with error:" + err);  
});  
    
```    
  
    
## opendir<sup>(deprecated)</sup>    
打开文件目录，使用callback异步回调。  
 **调用形式：**     
- opendir(path: string, callback: AsyncCallback\<Dir>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件目录的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Dir> | true | 异步打开文件目录之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
fileio.opendir(pathDir, (err: BusinessError, dir: fileio.Dir) => {  
  // example code in Dir struct  
  // use read/readSync/close  
});  
    
```    
  
    
## opendirSync<sup>(deprecated)</sup>    
以同步方法打开文件目录。  
 **调用形式：**     
- opendirSync(path: string): Dir  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFileSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待打开文件目录的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Dir | 返回Dir对象。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
// example code in Dir struct  
// use read/readSync/close    
```    
  
    
## readText<sup>(deprecated)</sup>    
基于文本方式读取文件（即直接读取文件的文本内容），使用Promise异步回调。  
 **调用形式：**     
- readText(   filePath: string,   options?: {     position?: number;     length?: number;     encoding?: string;   } ): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.readText。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filePath<sup>(deprecated)</sup> | string | true | 待读取文件的应用沙箱路径。 |  
| options<sup>(deprecated)</sup> | {     position?: number;     length?: number;     encoding?: string;   } | false | 支持如下选项：<br/>-position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读取。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'，仅支持'utf-8'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象。返回读取文件的内容。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + "/test.txt";  
  fileio.readText(filePath).then((str: string) => {  
    console.info("readText succeed:" + str);  
  }).catch((err: BusinessError) => {  
    console.info("readText failed with error:" + err);  
  });  
    
```    
  
    
## readText<sup>(deprecated)</sup>    
基于文本方式读取文件（即直接读取文件的文本内容），使用callback异步回调。  
 **调用形式：**     
- readText(   filePath: string,   options: {     position?: number;     length?: number;     encoding?: string;   },   callback: AsyncCallback\<string> ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.readText。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filePath<sup>(deprecated)</sup> | string | true | 待读取文件的应用沙箱路径。 |  
| options<sup>(deprecated)</sup> | {     position?: number;     length?: number;     encoding?: string;   } | true | 支持如下选项：<br/>-position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读取。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-encoding，string类型，表示数据的编码方式，默认'utf-8'，仅支持'utf-8'。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数，返回读取文件的内容。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + "/test.txt";  
  class Option {  
    length: number = 4096;  
    position: number = 0;  
    encoding: string = 'utf-8';  
  }  
  let option = new Option();  
  option.position = 1;  
  option.encoding = 'utf-8';  
  fileio.readText(filePath, option, (err: BusinessError, str: string) => {  
    // do something  
  });  
    
```    
  
    
## readTextSync<sup>(deprecated)</sup>    
以同步方法基于文本方式读取文件（即直接读取文件的文本内容）。  
 **调用形式：**     
- readTextSync(   filePath: string,   options?: {     position?: number;     length?: number;     encoding?: string;   } ): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.readTextSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filePath<sup>(deprecated)</sup> | string | true |  |  
| options<sup>(deprecated)</sup> | {     position?: number;     length?: number;     encoding?: string;   } | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string |  |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
  class Option {  
    length: number = 4096;  
    position: number = 0;  
    encoding: string = 'utf-8';  
  }  
  let option = new Option();  
  option.position = 1;  
  option.length = 3;  
  let str = fileio.readTextSync(filePath, option);  
    
```    
  
    
## read<sup>(deprecated)</sup>    
从文件读取数据，使用Promise异步回调。  
 **调用形式：**     
- read(   fd: number,   buffer: ArrayBuffer,   options?: {     offset?: number;     length?: number;     position?: number;   } ): Promise\<ReadOut>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.read。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待读取文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true | 用于保存读取到的文件数据的缓冲区。 |  
| options<sup>(deprecated)</sup> | {     offset?: number;     length?: number;     position?: number;   } | false | 支持如下选项：<br/>-offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ReadOut> | Promise对象。返回读取的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  import buffer from '@ohos.buffer';  
  import { ReadOut } from '@ohos.fileio';  
  let filePath = pathDir + "/test.txt";  
  let fd = fileio.openSync(filePath, 0o2);  
  let arrayBuffer = new ArrayBuffer(4096);  
  fileio.read(fd, arrayBuffer).then((readResult: fileio.ReadOut) => {  
    console.info("read file data succeed");  
    let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);  
    console.log(`The content of file: ${buf.toString()}`);  
  }).catch((err: BusinessError) => {  
    console.info("read file data failed with error:" + err);  
  });  
    
```    
  
    
## read<sup>(deprecated)</sup>    
从文件读取数据，使用callback异步回调。  
 **调用形式：**     
- read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.read。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待读取文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true | 用于保存读取到的文件数据的缓冲区。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ReadOut> | true | 异步读取数据之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
import buffer from '@ohos.buffer';  
let filePath = pathDir + "/test.txt";  
let fd = fileio.openSync(filePath, 0o2);  
let arrayBuffer = new ArrayBuffer(4096);  
fileio.read(fd, arrayBuffer, (err: BusinessError, readResult: fileio.ReadOut) => {  
  if (readLen) {  
    console.info("read file data succeed");  
    let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);  
    console.info(`The content of file: ${buf.toString()}`);  
  }  
});  
    
```    
  
    
## read<sup>(deprecated)</sup>  
 **调用形式：**     
- read(   fd: number,   buffer: ArrayBuffer,   options: {     offset?: number;     length?: number;     position?: number;   },   callback: AsyncCallback\<ReadOut> ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.read。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待读取文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true | 用于保存读取到的文件数据的缓冲区。 |  
| options<sup>(deprecated)</sup> | {     offset?: number;     length?: number;     position?: number;   } | true | 支持如下选项：<br/>-offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ReadOut> | true | 异步读取数据之后的回调。 |  
    
## readSync<sup>(deprecated)</sup>    
以同步方法从文件读取数据。  
 **调用形式：**     
- readSync(   fd: number,   buffer: ArrayBuffer,   options?: {     offset?: number;     length?: number;     position?: number;   } ): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.readSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待读取文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true | 用于保存读取到的文件数据的缓冲区。 |  
| options<sup>(deprecated)</sup> | {     offset?: number;     length?: number;     position?: number;   } | false | 支持如下选项：<br/>-offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际读取的长度。 |  
    
## rename<sup>(deprecated)</sup>    
重命名文件，使用Promise异步回调。  
 **调用形式：**     
- rename(oldPath: string, newPath: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.rename。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| oldPath<sup>(deprecated)</sup> | string | true | 目标文件的当前应用沙箱路径。 |  
| newPath<sup>(deprecated)</sup> | string | true | 目标文件的新应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + '/new.txt';  
fileio.rename(srcFile, dstFile).then(() => {  
  console.info("rename succeed");  
}).catch((err: BusinessError) => {  
  console.info("rename failed with error:" + err);  
});  
    
```    
  
    
## rename<sup>(deprecated)</sup>    
重命名文件，使用callback异步回调。  
 **调用形式：**     
- rename(oldPath: string, newPath: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.rename。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| oldPath<sup>(deprecated)</sup> | string | true | 目标文件的当前应用沙箱路径。 |  
| newPath<sup>(deprecated)</sup> | string | true | 目标文件的新应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步重命名文件之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + '/new.txt';  
fileio.rename(srcFile, dstFile, (err: BusinessError) => {  
});  
    
```    
  
    
## renameSync<sup>(deprecated)</sup>    
以同步方法重命名文件。  
 **调用形式：**     
- renameSync(oldPath: string, newPath: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.renameSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| oldPath<sup>(deprecated)</sup> | string | true | 目标文件的当前应用沙箱路径。 |  
| newPath<sup>(deprecated)</sup> | string | true | 目标文件的新应用沙箱路径。 |  
    
 **示例代码：**   
```ts    
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + '/new.txt';  
fileio.renameSync(srcFile, dstFile);    
```    
  
    
## rmdir<sup>(deprecated)</sup>    
删除目录，使用Promise异步回调。  
 **调用形式：**     
- rmdir(path: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.rmdir。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待删除目录的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + '/testDir';  
fileio.rmdir(dirPath).then(() => {  
  console.info("rmdir succeed");  
}).catch((err: BusinessError) => {  
  console.info("rmdir failed with error:" + err);  
});  
    
```    
  
    
## rmdir<sup>(deprecated)</sup>    
删除目录，使用callback异步回调。  
 **调用形式：**     
- rmdir(path: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.rmdir。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待删除目录的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步删除目录之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let dirPath = pathDir + '/testDir';  
fileio.rmdir(dirPath, (err: BusinessError) => {  
  // do something  
  console.info("rmdir succeed");  
});  
    
```    
  
    
## rmdirSync<sup>(deprecated)</sup>    
以同步方法删除目录。  
 **调用形式：**     
- rmdirSync(path: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.rmdirSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待删除目录的应用沙箱路径。 |  
    
 **示例代码：**   
```ts    
let dirPath = pathDir + '/testDir';  
fileio.rmdirSync(dirPath);    
```    
  
    
## stat<sup>(deprecated)</sup>    
获取文件信息，使用Promise异步回调。  
 **调用形式：**     
- stat(path: string): Promise\<Stat>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.stat。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待获取文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Stat> | Promise对象。返回文件的具体信息。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "test.txt";  
fileio.stat(filePath).then((stat: fileio.Stat) => {  
  console.info("getFileInfo succeed, the size of file is " + stat.size);  
}).catch((err: BusinessError) => {  
  console.info("getFileInfo failed with error:" + err);  
});  
    
```    
  
    
## stat<sup>(deprecated)</sup>    
获取文件信息，使用callback异步回调。  
 **调用形式：**     
- stat(path: string, callback: AsyncCallback\<Stat>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.stat。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待获取文件的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Stat> | true | 异步获取文件的信息之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
fileio.stat(pathDir, (err: BusinessError, stat: fileio.Stat) => {  
  // example code in Stat  
});  
    
```    
  
    
## statSync<sup>(deprecated)</sup>    
以同步方法获取文件的信息。  
 **调用形式：**     
- statSync(path: string): Stat  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.statSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待获取文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Stat | 表示文件的具体信息。 |  
    
 **示例代码：**   
```ts    
let stat = fileio.statSync(pathDir);  
// example code in Stat    
```    
  
    
## symlink<sup>(deprecated)</sup>    
基于文件路径创建符号链接，使用Promise异步回调。  
 **调用形式：**     
- symlink(target: string, srcPath: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.symlink。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target<sup>(deprecated)</sup> | string | true | 目标文件的应用沙箱路径。 |  
| srcPath<sup>(deprecated)</sup> | string | true | 符号链接文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + '/test';  
fileio.symlink(srcFile, dstFile).then(() => {  
  console.info("symlink succeed");  
}).catch((err: BusinessError) => {  
  console.info("symlink failed with error:" + err);  
});  
    
```    
  
    
## symlink<sup>(deprecated)</sup>    
基于文件路径创建符号链接，使用callback异步回调。  
 **调用形式：**     
- symlink(target: string, srcPath: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.symlink。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target<sup>(deprecated)</sup> | string | true | 目标文件的应用沙箱路径。 |  
| srcPath<sup>(deprecated)</sup> | string | true | 符号链接文件的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步创建符号链接信息之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + '/test';  
fileio.symlink(srcFile, dstFile, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## symlinkSync<sup>(deprecated)</sup>    
以同步的方法基于文件路径创建符号链接。  
 **调用形式：**     
- symlinkSync(target: string, srcPath: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.symlinkSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target<sup>(deprecated)</sup> | string | true | 目标文件的应用沙箱路径。 |  
| srcPath<sup>(deprecated)</sup> | string | true | 符号链接文件的应用沙箱路径。 |  
    
 **示例代码：**   
```ts    
let srcFile = pathDir + "/test.txt";  
let dstFile = pathDir + '/test';  
fileio.symlinkSync(srcFile, dstFile);    
```    
  
    
## truncate<sup>(deprecated)</sup>    
基于文件路径截断文件，使用Promise异步回调。  
 **调用形式：**     
- truncate(path: string, len?: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncate。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待截断文件的应用沙箱路径。 |  
| len<sup>(deprecated)</sup> | number | false | 文件截断后的长度，以字节为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let len = 5;  
fileio.truncate(filePath, len).then(() => {  
  console.info("truncate file succeed");  
}).catch((err: BusinessError) => {  
  console.info("truncate file failed with error:" + err);  
});  
    
```    
  
    
## truncate<sup>(deprecated)</sup>    
基于文件路径截断文件，使用callback异步回调。  
 **调用形式：**     
- truncate(path: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncate。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待截断文件的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数，本调用无返回值。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let len = 5;  
fileio.truncate(filePath, len, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## truncate<sup>(deprecated)</sup>    
基于文件路径截断文件，使用callback异步回调。  
 **调用形式：**     
- truncate(path: string, len: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncate。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待截断文件的应用沙箱路径。 |  
| len<sup>(deprecated)</sup> | number | true | 文件截断后的长度，以字节为单位。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数，本调用无返回值。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let len = 5;  
fileio.truncate(filePath, len, (err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
## truncateSync<sup>(deprecated)</sup>    
以同步方法基于文件路径截断文件。  
 **调用形式：**     
- truncateSync(path: string, len?: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.truncateSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待截断文件的应用沙箱路径。 |  
| len<sup>(deprecated)</sup> | number | false | 文件截断后的长度，以字节为单位。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let len = 5;  
fileio.truncateSync(filePath, len);    
```    
  
    
## unlink<sup>(deprecated)</sup>    
删除文件，使用Promise异步回调。  
 **调用形式：**     
- unlink(path: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.unlink。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待删除文件的应用沙箱路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。无返回值。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.unlink(filePath).then(() => {  
  console.info("remove file succeed");  
}).catch((error: BusinessError) => {  
  console.info("remove file failed with error:" + error);  
});  
    
```    
  
    
## unlink<sup>(deprecated)</sup>    
删除文件，使用callback异步回调。  
 **调用形式：**     
- unlink(path: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.unlink。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待删除文件的应用沙箱路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步删除文件之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
fileio.unlink(filePath, (err: BusinessError) => {  
  console.info("remove file succeed");  
});  
    
```    
  
    
## unlinkSync<sup>(deprecated)</sup>    
以同步方法删除文件。  
 **调用形式：**     
- unlinkSync(path: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.unlinkSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 待删除文件的应用沙箱路径。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
fileio.unlinkSync(filePath);    
```    
  
    
## write<sup>(deprecated)</sup>    
将数据写入文件，使用Promise异步回调。  
 **调用形式：**     
- write(   fd: number,   buffer: ArrayBuffer | string,   options?: {     offset?: number;     length?: number;     position?: number;     encoding?: string;   } ): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待写入文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options<sup>(deprecated)</sup> | {     offset?: number;     length?: number;     position?: number;     encoding?: string;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。<br/>约束：offset+length<=buffer.size。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象。返回实际写入的长度。 |  
    
## write<sup>(deprecated)</sup>    
将数据写入文件，使用callback异步回调。  
 **调用形式：**     
- write(fd: number, buffer: ArrayBuffer | string, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待写入文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步将数据写入完成后执行的回调函数。 |  
    
## write<sup>(deprecated)</sup>    
将数据写入文件，使用callback异步回调。  
 **调用形式：**     
- write(   fd: number,   buffer: ArrayBuffer | string,   options: {     offset?: number;     length?: number;     position?: number;     encoding?: string;   },   callback: AsyncCallback\<number> ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待写入文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options<sup>(deprecated)</sup> | {     offset?: number;     length?: number;     position?: number;     encoding?: string;   } | true | 支持如下选项：<br/>-offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。<br/>约束：offset+length<=buffer.size。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步将数据写入完成后执行的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + "/test.txt";  
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);  
  fileio.write(fd, "hello, world", (err: BusinessError, bytesWritten: number) => {  
    if (bytesWritten) {  
      console.info("write data to file succeed and size is:" + bytesWritten);  
    }  
  });  
    
```    
  
    
## writeSync<sup>(deprecated)</sup>    
以同步方法将数据写入文件。  
 **调用形式：**     
- writeSync(   fd: number,   buffer: ArrayBuffer | string,   options?: {     offset?: number;     length?: number;     position?: number;     encoding?: string;   } ): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.writeSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 待写入文件的文件描述符。 |  
| buffer<sup>(deprecated)</sup> | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options<sup>(deprecated)</sup> | {     offset?: number;     length?: number;     position?: number;     encoding?: string;   } | false | 支持如下选项：<br/>-offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。<br/>约束：offset+length<=buffer.size。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际写入的长度。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);  let num = fileio.writeSync(fd, "hello, world");    
```    
  
    
## createWatcher<sup>(deprecated)</sup>    
监听文件或者目录的变化，使用callback异步回调。  
 **调用形式：**     
- createWatcher(filename: string, events: number, callback: AsyncCallback\<number>): Watcher  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.createWatcher。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filename<sup>(deprecated)</sup> | string | true |  |  
| events<sup>(deprecated)</sup> | number | true | -1:监听文件或者目录是否发生重命名。<br/>-2：监听文件或者目录内容的是否修改。<br/>-3：两者都有。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 每发生变化一次，调用一次此函数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Watcher | Promise对象。返回文件变化监听的实例。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
let filePath = pathDir + "/test.txt";  
fileio.createWatcher(filePath, 1, async (event: number) => {  
  console.info("event: " + event);  
});    
```    
  
    
## Dir<sup>(deprecated)</sup>    
管理目录，在调用Dir的方法前，需要先通过opendir方法（同步或异步）来构建一个Dir实例。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.listFile替代。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### read<sup>(deprecated)</sup>    
读取下一个目录项，使用Promise异步回调。  
 **调用形式：**     
- read(): Promise\<Dirent>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Dirent> | Promise对象。返回表示异步读取目录项的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
dir.read().then((dirent: fileio.Dirent) => {  
  console.log("read succeed, the name of dirent is " + dirent.name);  
}).catch((err: BusinessError) => {  
  console.info("read failed with error:" + err);  
});  
    
```    
  
    
### read<sup>(deprecated)</sup>    
读取下一个目录项，使用callback异步回调。  
 **调用形式：**     
- read(callback: AsyncCallback\<Dirent>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Dirent> | true | 异步读取下一个目录项之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
dir.read((err: BusinessError, dirent: fileio.Dirent) => {  
  if (dirent) {  
    // do something  
    console.log("read succeed, the name of file is " + dirent.name);  
  }  
});  
    
```    
  
    
### readSync<sup>(deprecated)</sup>    
同步读取下一个目录项。  
 **调用形式：**     
- readSync(): Dirent  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Dirent | 表示一个目录项。 |  
    
 **示例代码：**   
```ts    
let dirent = dir.readSync();    
```    
  
    
### close<sup>(deprecated)</sup>    
异步关闭目录，使用promise形式返回结果。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。  
 **调用形式：**     
- close(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
dir.close().then(() => {  
  console.info("close dir successfully");  
});  
    
```    
  
    
### close<sup>(deprecated)</sup>    
异步关闭目录，使用callback形式返回结果。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。  
 **调用形式：**     
- close(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
dir.close((err: BusinessError) => {  
  console.info("close dir successfully");  
});  
    
```    
  
    
### closeSync<sup>(deprecated)</sup>    
用于关闭目录。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。  
 **调用形式：**     
- closeSync(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **示例代码：**   
```ts    
dir.closeSync();    
```    
  
    
## Dirent<sup>(deprecated)</sup>    
在调用Dirent的方法前，需要先通过[dir.read()](#read)方法（同步或异步）来构建一个Dirent实例。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.listFile替代。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.listFile替代。<br>目录项的名称。 |  
    
### isBlockDevice<sup>(deprecated)</sup>    
用于判断当前目录项是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。  
 **调用形式：**     
- isBlockDevice(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示当前目录项是否是块特殊设备。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
let isBLockDevice = dir.readSync().isBlockDevice();    
```    
  
    
### isCharacterDevice<sup>(deprecated)</sup>    
用于判断当前目录项是否是字符特殊设备。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。  
 **调用形式：**     
- isCharacterDevice(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示当前目录项是否是字符特殊设备。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
let isCharacterDevice = dir.readSync().isCharacterDevice();     
```    
  
    
### isDirectory<sup>(deprecated)</sup>    
用于判断当前目录项是否是目录。  
 **调用形式：**     
- isDirectory(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示当前目录项是否是目录。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
let isDirectory = dir.readSync().isDirectory();     
```    
  
    
### isFIFO<sup>(deprecated)</sup>    
用于判断当前目录项是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。  
 **调用形式：**     
- isFIFO(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示当前目录项是否是FIFO。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
let isFIFO = dir.readSync().isFIFO();     
```    
  
    
### isFile<sup>(deprecated)</sup>    
用于判断当前目录项是否是普通文件。  
 **调用形式：**     
- isFile(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示当前目录项是否是普通文件。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
let isFile = dir.readSync().isFile();     
```    
  
    
### isSocket<sup>(deprecated)</sup>    
用于判断当前目录项是否是套接字。  
 **调用形式：**     
- isSocket(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示当前目录项是否是套接字。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
let isSocket = dir.readSync().isSocket();     
```    
  
    
### isSymbolicLink<sup>(deprecated)</sup>    
用于判断当前目录项是否是符号链接。  
 **调用形式：**     
- isSymbolicLink(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示当前目录项是否是符号链接。 |  
    
 **示例代码：**   
```ts    
let dir = fileio.opendirSync(pathDir);  
let isSymbolicLink = dir.readSync().isSymbolicLink();    
```    
  
    
## Stat<sup>(deprecated)</sup>    
文件具体信息，在调用Stat的方法前，需要先通过[stat()](#fileiostat)方法（同步或异步）来构建一个Stat实例。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat替代。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| dev<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>标识包含该文件的主设备号。 |  
| ino<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.ino替代。<br>标识该文件。通常同设备上的不同文件的INO不同。 |  
| mode<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.mode替代。<br>表示文件类型及权限，其首4位表示文件类型，后12位表示权限。各特征位的含义如下：<br/>-0o170000：可用于获取文件类型的掩码。<br/>-0o140000：文件是套接字。<br/>-0o120000：文件是符号链接。<br/>-0o100000：文件是一般文件。<br/>-0o060000：文件属于块设备。<br/>-0o040000：文件是目录。<br/>-0o020000：文件是字符设备。<br/>-0o010000：文件是命名管道，即FIFO。<br/>-0o0700：可用于获取用户权限的掩码。<br/>-0o0400：用户读，对于普通文件，所有者可读取文件；对于目录，所有者可读取目录项。<br/>-0o0200：用户写，对于普通文件，所有者可写入文件；对于目录，所有者可创建/删除目录项。<br/>-0o0100：用户执行，对于普通文件，所有者可执行文件；对于目录，所有者可在目录中搜索给定路径名。<br/>-0o0070：可用于获取用户组权限的掩码。<br/>-0o0040：用户组读，对于普通文件，所有用户组可读取文件；对于目录，所有用户组可读取目录项。<br/>-0o0020：用户组写，对于普通文件，所有用户组可写入文件；对于目录，所有用户组可创建/删除目录项。<br/>-0o0010：用户组执行，对于普通文件，所有用户组可执行文件；对于目录，所有用户组是否可在目录中搜索给定路径名。<br/>-0o0007：可用于获取其他用户权限的掩码。<br/>-0o0004：其他读，对于普通文件，其余用户可读取文件；对于目录，其他用户组可读取目录项。<br/>-0o0002：其他写，对于普通文件，其余用户可写入文件；对于目录，其他用户组可创建/删除目录项。<br/>-0o0001：其他执行，对于普通文件，其余用户可执行文件；对于目录，其他用户组可在目录中搜索给定路径名。 |  
| nlink<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>文件的硬链接数。 |  
| uid<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.uid替代。<br>文件所有者的ID。 |  
| gid<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.gid替代。<br>文件所有组的ID。 |  
| rdev<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>标识包含该文件的从设备号。 |  
| size<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.size替代。<br>文件的大小，以字节为单位。仅对普通文件有效。 |  
| blocks<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>文件占用的块数，计算时块大小按512B计算。 |  
| atime<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.atime替代。<br>上次访问该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |  
| mtime<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.mtime替代。<br>上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |  
| ctime<sup>(deprecated)</sup> | number | true | true | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stat.ctime替代。<br>最近改变文件状态的时间，表示距1970年1月1日0时0分0秒的秒数。 |  
    
### isBlockDevice<sup>(deprecated)</sup>    
用于判断文件是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。  
 **调用形式：**     
- isBlockDevice(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stat.isBlockDevice。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是块特殊设备。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isBLockDevice = fileio.statSync(filePath).isBlockDevice();    
```    
  
    
### isCharacterDevice<sup>(deprecated)</sup>    
用于判断文件是否是字符特殊文件。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。  
 **调用形式：**     
- isCharacterDevice(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stat.isCharacterDevice。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是字符特殊设备。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isCharacterDevice = fileio.statSync(filePath).isCharacterDevice();    
```    
  
    
### isDirectory<sup>(deprecated)</sup>    
用于判断文件是否是目录。  
 **调用形式：**     
- isDirectory(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stat.isDirectory。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是目录。 |  
    
 **示例代码：**   
```ts    
let dirPath = pathDir + "/test";  
let isDirectory = fileio.statSync(dirPath).isDirectory();     
```    
  
    
### isFIFO<sup>(deprecated)</sup>    
用于判断文件是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。  
 **调用形式：**     
- isFIFO(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stat.isFIFO。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是FIFO。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isFIFO = fileio.statSync(filePath).isFIFO();     
```    
  
    
### isFile<sup>(deprecated)</sup>    
用于判断文件是否是普通文件。  
 **调用形式：**     
- isFile(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stat.isFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是普通文件。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isFile = fileio.statSync(filePath).isFile();    
```    
  
    
### isSocket<sup>(deprecated)</sup>    
用于判断文件是否是套接字。  
 **调用形式：**     
- isSocket(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stat.isSocket。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是套接字。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let isSocket = fileio.statSync(filePath).isSocket();     
```    
  
    
### isSymbolicLink<sup>(deprecated)</sup>    
用于判断文件是否是符号链接。  
 **调用形式：**     
- isSymbolicLink(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stat.isSymbolicLink。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示文件是否是符号链接。 |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test";  
let isSymbolicLink = fileio.statSync(filePath).isSymbolicLink();     
```    
  
    
## Stream<sup>(deprecated)</sup>    
文件流，在调用Stream的方法前，需要先通过createStream()方法（同步或异步）来构建一个Stream实例。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.fs.Stream替代。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### close<sup>(deprecated)</sup>    
关闭文件流，使用Promise异步回调。  
 **调用形式：**     
- close(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.close。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。返回表示异步关闭文件流的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let ss = fileio.createStreamSync(filePath, "r+");  
ss.close().then(() => {  
  console.info("close fileStream succeed");  
}).catch((err: BusinessError) => {  
  console.info("close fileStream  failed with error:" + err);  
});  
    
```    
  
    
### close<sup>(deprecated)</sup>    
异步关闭文件流，使用callback异步回调。  
 **调用形式：**     
- close(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.close。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步关闭文件流之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let ss = fileio.createStreamSync(filePath, "r+");  
ss.close((err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
### closeSync<sup>(deprecated)</sup>    
同步关闭文件流。  
 **调用形式：**     
- closeSync(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.closeSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let ss = fileio.createStreamSync(filePath, "r+");  
ss.closeSync();    
```    
  
    
### flush<sup>(deprecated)</sup>    
刷新文件流，使用Promise异步回调。  
 **调用形式：**     
- flush(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.flush。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象。返回表示异步刷新文件流的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let ss = fileio.createStreamSync(filePath, "r+");  
ss.flush().then(() => {  
  console.info("flush succeed");  
}).catch((err: BusinessError) => {  
  console.info("flush failed with error:" + err);  
});  
    
```    
  
    
### flush<sup>(deprecated)</sup>    
异步刷新文件流，使用callback异步回调。  
 **调用形式：**     
- flush(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.flush。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步刷新文件流后的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let filePath = pathDir + "/test.txt";  
let ss = fileio.createStreamSync(filePath, "r+");  
ss.flush((err: BusinessError) => {  
  // do something  
});  
    
```    
  
    
### flushSync<sup>(deprecated)</sup>    
同步刷新文件流。  
 **调用形式：**     
- flushSync(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.flushSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test.txt";  
let ss = fileio.createStreamSync(filePath, "r+");  
ss.flushSync();    
```    
  
    
### write<sup>(deprecated)</sup>    
将数据写入流文件，使用Promise异步回调。  
 **调用形式：**     
- write(     buffer: ArrayBuffer | string,     options?: {       offset?: number;       length?: number;       position?: number;       encoding?: string;     }   ): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options<sup>(deprecated)</sup> | {       offset?: number;       length?: number;       position?: number;       encoding?: string;     } | false | 支持如下选项：<br/>-offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。<br/>约束：offset+length<=buffer.size。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象。返回实际写入的长度。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + "/test.txt";  
  let ss = fileio.createStreamSync(filePath, "r+");  
  class Option {  
    offset: number = 0;  
    length: number = 4096;  
    position: number = 0;  
    encoding: string = 'utf-8';  
  }  
  let option = new Option();  
  option.offset = 1;  
  option.length = 5;  
  option.position = 5;  
  ss.write("hello, world", option).then((number: number) => {  
    console.info("write succeed and size is:" + number);  
  }).catch((err: BusinessError) => {  
    console.info("write failed with error:" + err);  
  });  
    
```    
  
    
### write<sup>(deprecated)</sup>    
。  
 **调用形式：**     
- write(buffer: ArrayBuffer | string, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | string | true | <br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | <br/> |  
    
### write<sup>(deprecated)</sup>    
将数据写入流文件，使用callback异步回调。  
 **调用形式：**     
- write(     buffer: ArrayBuffer | string,     options: {       offset?: number;       length?: number;       position?: number;       encoding?: string;     },     callback: AsyncCallback\<number>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | string | true | 待写入文件的数据，可来自缓冲区或字符串。 |  
| options<sup>(deprecated)</sup> | {       offset?: number;       length?: number;       position?: number;       encoding?: string;     } | true | 支持如下选项：<br/>-offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认'utf-8'。仅支持'utf-8'。<br/>约束：offset+length<=buffer.size。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步写入完成后执行的回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + "/test.txt";  
  let ss = fileio.createStreamSync(filePath, "r+");  
  class Option {  
    offset: number = 0;  
    length: number = 4096;  
    position: number = 0;  
    encoding: string = 'utf-8';  
  }  
  let option = new Option();  
  option.offset = 1;  
  option.length = 5;  
  option.position = 5;  
  ss.write("hello, world", option, (err: BusinessError, bytesWritten: number) => {  
    if (bytesWritten) {  
      // do something  
      console.info("write succeed and size is:" + bytesWritten);  
    }  
  });  
    
```    
  
    
### writeSync<sup>(deprecated)</sup>  
 **调用形式：**     
- writeSync(     buffer: ArrayBuffer | string,     options?: {       offset?: number;       length?: number;       position?: number;       encoding?: string;     }   ): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.writeSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | string | true |  |  
| options<sup>(deprecated)</sup> | {       offset?: number;       length?: number;       position?: number;       encoding?: string;     } | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
### read<sup>(deprecated)</sup>    
从流文件读取数据，使用Promise异步回调。  
 **调用形式：**     
- read(     buffer: ArrayBuffer,     options?: {       position?: number;       offset?: number;       length?: number;     }   ): Promise\<ReadOut>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.read。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true | 用于读取文件的缓冲区。 |  
| options<sup>(deprecated)</sup> | {       position?: number;       offset?: number;       length?: number;     } | false | 支持如下选项：<br/>-offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ReadOut> | Promise对象。返回读取的结果。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  import buffer from '@ohos.buffer';  
  let filePath = pathDir + "/test.txt";  
  let ss = fileio.createStreamSync(filePath, "r+");  
  let arrayBuffer = new ArrayBuffer(4096);  
  class Option {  
    offset: number = 0;  
    length: number = 4096;  
    position: number = 0;  
  }  
  let option = new Option();  
  option.offset = 1;  
  option.length = 5;  
  option.position = 5;  
  ss.read(arrayBuffer, option).then((readResult: fileio.ReadOut) => {  
    console.info("read data succeed");  
    let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);  
    console.info(`The content of file: ${buf.toString()}`);  
  }).catch((err: BusinessError) => {  
    console.info("read data failed with error:" + err);  
  });  
    
```    
  
    
### read<sup>(deprecated)</sup>    
从流文件读取数据，使用callback异步回调。  
 **调用形式：**     
- read(buffer: ArrayBuffer, callback: AsyncCallback\<ReadOut>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.read。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true | 用于读取文件的缓冲区。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ReadOut> | true | 异步从流文件读取数据之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  import buffer from '@ohos.buffer';  
  let filePath = pathDir + "/test.txt";  
  let ss = fileio.createStreamSync(filePath, "r+");  
  let arrayBuffer = new ArrayBuffer(4096);  
  class Option {  
    offset: number = 0;  
    length: number = 4096;  
    position: number = 0;  
  }  
  let option = new Option();  
  option.offset = 1;  
  option.length = 5;  
  option.position = 5;  
  ss.read(arrayBuffer, option, (err: BusinessError, readResult: fileio.ReadOut) => {  
    if (readResult.bytesRead) {  
      console.info("read data succeed");  
      let buf = buffer.from(arrayBuffer, 0, readResult.bytesRead);  
      console.info(`The content of file: ${buf.toString()}`);  
    }  
  });  
    
```    
  
    
### read<sup>(deprecated)</sup>  
 **调用形式：**     
- read(     buffer: ArrayBuffer,     options: {       position?: number;       offset?: number;       length?: number;     },     callback: AsyncCallback\<ReadOut>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.read。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true |  |  
| options<sup>(deprecated)</sup> | {       position?: number;       offset?: number;       length?: number;     } | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ReadOut> | true |  |  
    
### readSync<sup>(deprecated)</sup>  
 **调用形式：**     
- readSync(     buffer: ArrayBuffer,     options?: {       position?: number;       offset?: number;       length?: number;     }   ): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.fs.Stream.readSync。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | true |  |  
| options<sup>(deprecated)</sup> | {       position?: number;       offset?: number;       length?: number;     } | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
## ReadOut<sup>(deprecated)</sup>    
仅用于read方法，获取文件的读取结果。    
从API version 6 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bytesRead<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>实际读取长度。 |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>读取数据相对于缓冲区首地址的偏移。 |  
| buffer<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>保存读取数据的缓冲区。 |  
    
## Watcher<sup>(deprecated)</sup>    
Watcher是文件变化监听的实例，调用Watcher.stop()方法（同步或异步）来停止文件监听。    
从API version 7 开始支持，从API version 10 开始废弃。建议使用ohos.file.fs.Watcher替代。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
### stop<sup>(deprecated)</sup>    
关闭watcher监听，使用Promise异步回调。  
 **调用形式：**     
- stop(): Promise\<void>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.Watcher.stop。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
let filePath = pathDir + "/test.txt";  
let watcher = fileio.createWatcher(filePath, 1, (event: number) => {  
  console.info("event: " + event);  
});  
watcher.stop().then(() => {  
  console.info("close watcher succeed");  
});    
```    
  
    
### stop<sup>(deprecated)</sup>    
关闭watcher监听，使用callback异步回调。  
 **调用形式：**     
- stop(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.Watcher.stop。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 以异步方法关闭watcher监听之后的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
let filePath = pathDir + "/test.txt";  
let watcher = fileio.createWatcher(filePath, 1, async(event: number) => {  
  console.info("event: " + event);  
});  
watcher.stop(() => {  
  console.info("close watcher succeed");  
})    
```    
  
