# 压缩与解压
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @jinsenjun-->
<!--Designer: @jinsenjun-->
<!--Tester: @lixueqing-->
<!--Adviser: @Brilliantry_Rui-->

本文针对常见的几种压缩、解压场景，介绍相关函数的使用方法。

## 接口说明

以下是示例中使用的主要接口，更多接口及使用方式请见[接口文档](../../reference/apis-basic-services-kit/js-apis-zlib.md)。

| 接口名                                                       | 接口描述                     |
| ------------------------------------------------------------ | ---------------------------- |
| compressFile(inFile: string, outFile: string, options: Options): Promise&lt;void&gt; | 压缩文件。               |
| decompressFile(inFile: string, outFile: string, options?: Options): Promise&lt;void&gt; | 解压文件。               |
| compress(dest: ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt; | 将源缓冲区压缩到目标缓冲区。               |
| compressBound(sourceLen: number): Promise&lt;number&gt; | 计算返回压缩大小的上限。              |
| uncompress(dest:ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt; | 将压缩后的数据解压缩为原始的未压缩形式。               |
| deflate(strm: ZStream, flush: CompressFlushMode): Promise&lt;ReturnStatus&gt; | 压缩数据。               |
| inflate(strm: ZStream, flush: CompressFlushMode): Promise&lt;ReturnStatus&gt; | 解压数据。|

## 开发步骤

### 环境准备

在应用沙箱目录下创建一个测试文件data.txt，并写入测试数据。示例代码如下。

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     @State dataSize: number = 0;

     build() {
       Row() {
         Column() {
           // 在应用沙箱目录下创建文件data.txt，并写入测试数据
           Button('创建测试文件data.txt').onClick(() => {
             let path = this.getUIContext()?.getHostContext()?.filesDir;
             // 创建文件data.txt
             let inFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
             // 写入测试数据
             for (let index = 0; index < 100; index++) {
               fs.writeSync(inFile.fd, index + ': hello world, hello world, hello world, hello world, hello world.\n');
             }
             // 获取测试数据原始大小，并保存到dataSize中
             let stat = fs.statSync(inFile.path);
             this.dataSize = stat.size;
             console.info('dataSize: ' + this.dataSize);
             // 关闭文件
             fs.closeSync(inFile);
           })
         }
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

### Zip文件的压缩与解压

采用接口[zlib.compressFile()](../../reference/apis-basic-services-kit/js-apis-zlib.md#zlibcompressfile9-1)将文件data.txt压缩并归档到data.zip中，采用接口[zlib.decompressFile()](../../reference/apis-basic-services-kit/js-apis-zlib.md#zlibdecompressfile9-1)将data.zip解压到应用沙箱目录下，示例代码如下。

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         // 示例一：将测试文件data.txt压缩并归档到data.zip中。
         Button('compressFile').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = path + '/data.txt';
           let outFile = path + '/data.zip';
           let options: zlib.Options = {};
           zlib.compressFile(inFile, outFile, options).then((data: void) => {
             console.info('compressFile success, data: ' + JSON.stringify(data));
           }).catch((errData: BusinessError) => {
             console.error(`compressFile errCode: ${errData.code}, message: ${errData.message}`);
           })
         })

         // 示例二：将data.zip文件解压到应用沙箱目录下。
         Button('decompressFile').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = path + '/data.zip';
           let outFile = path;
           let options: zlib.Options = {};
           zlib.decompressFile(inFile, outFile, options).then((data: void) => {
             console.info('decompressFile success, data: ' + JSON.stringify(data));
           }).catch((errData: BusinessError) => {
             console.error(`decompressFile errCode: ${errData.code}, message: ${errData.message}`);
           })
         })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

### 已知大小缓冲区的压缩与解压

针对一个已知大小的缓冲区中的数据，使用接口[compress()](../../reference/apis-basic-services-kit/js-apis-zlib.md#compress12)将其压缩到一个目的缓冲区中，使用接口[compressBound()](../../reference/apis-basic-services-kit/js-apis-zlib.md#compressbound12)计算压缩目的缓冲区大小的上限值，使用接口[uncompress()](../../reference/apis-basic-services-kit/js-apis-zlib.md#uncompress12)对存储压缩数据的缓冲区进行解压。由于解压时无法获取解压后原始数据的大小，为了确认解压后目的缓冲区的大小，需要在压缩前获取原始数据的大小并保存，示例代码如下。

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     @State dataSize: number = 0;  //用于保存原始数据的大小

     build() {
       Row() {
         // 示例一：读取data.txt文件内容并存入一个缓冲区，调用compress接口压缩缓冲区中的数据到目标缓冲区，并将目标缓冲区的内容写入文件data.bin
         Button('compress buffer').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.bin', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           // 读取data.txt文件的内容，并存入缓冲区inBuf
           let stat = fs.statSync(inFile.path);
           let inBuf = new ArrayBuffer(stat.size);
           let readLen = fs.readSync(inFile.fd, inBuf);
           console.info(`original size: ${stat.size}, read len: ${readLen}`);
           // 获取原始数据的大小，并保存
           this.dataSize = stat.size;
           // 创建一个压缩对象实例
           let zip = zlib.createZipSync();
           // 获取一个目标缓冲区的上限
           zip.compressBound(stat.size).then((data) => {
             console.info(`the max dest buf len is ${data}`);
             // 目标缓冲区outBuf
             let outBuf = new ArrayBuffer(data);
             // 将inBuf中的数据压缩到outBuf中
             zip.compress(outBuf, inBuf, readLen).then((zipOutInfo) => {
               console.info(`compress success, status ${zipOutInfo.status}, destLen  ${zipOutInfo.destLen}`);
               // 将outBuf中的数据写入到data.bin文件
               let writeLen = fs.writeSync(outFile.fd, outBuf, { length: zipOutInfo.destLen });
               console.info(`write destBuf to data.bin, writeLen ${writeLen}`);
               // 关闭文件
               fs.closeSync(inFile.fd);
               fs.closeSync(outFile.fd);
             }).catch((errData: BusinessError) => {
               console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
             })
           }).catch((errData: BusinessError) => {
             console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
           })
         })

         // 示例二：读取data.bin文件中的压缩数据并存入一个缓冲区，调用uncompress接口将缓冲区中的数据解压到目标缓冲区，并将目标缓冲区的内容写入文件data.txt
         Button('uncompress buffer').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.bin', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           // 读取data.bin文件中的压缩数据，并存入缓冲区inBuf
           let stat = fs.statSync(inFile.path);
           let inBuf = new ArrayBuffer(stat.size);
           let readLen = fs.readSync(inFile.fd, inBuf);
           console.info(`compressed data size: ${stat.size}, read len: ${readLen}`);
           // 创建一个目标缓冲区，此处的dataSize是我们进行数据压缩前保存的数据的原始大小
           let outBuf = new ArrayBuffer(this.dataSize);
           console.info(`the dest buf size is ${this.dataSize}`);
           // 创建一个压缩对象实例
           let zip = zlib.createZipSync();
           // 将inBuf中的数据解压缩outBuf中
           zip.uncompress(outBuf, inBuf, readLen).then((zipOutInfo) => {
             console.info(`uncompress success, status ${zipOutInfo.status}, destLen  ${zipOutInfo.destLen}`);
             // 将outBuf中的数据写入到data.txt文件
             let writeLen = fs.writeSync(outFile.fd, outBuf, { length: zipOutInfo.destLen });
             console.info(`write destBuf to data.txt, writeLen ${writeLen}`);
             // 关闭文件
             fs.closeSync(inFile.fd);
             fs.closeSync(outFile.fd);
           }).catch((errData: BusinessError) => {
             console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
           })
         })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

### 未知大小缓冲区的压缩与解压（zlib格式）

针对一个未知大小的缓冲区中的数据，使用接口[deflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#deflate12)将从一个原始输入流中读取的数据进行压缩，使用接口[inflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#inflate12)将从一个压缩输入流中读取的数据进行解压，示例代码如下。

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         // 示例一：从文件中不断读取数据进行压缩
         Button('deflateFile').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.bin', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           deflateFile(inFile, outFile).then(() => {
             console.info('deflateFile success');
             fs.closeSync(inFile.fd);
             fs.closeSync(outFile.fd);
           })
         })

         // 示例二：从文件中不断读取压缩数据进行解压
         Button('inflateFile').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.bin', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           inflateFile(inFile, outFile).then(() => {
             console.info('deflateFile success');
             fs.closeSync(inFile.fd);
             fs.closeSync(outFile.fd);
           })
         })
       }
       .height('100%')
       .width('100%')
     }
   }

   // 从一个文件中，不断的读入数据，进行压缩，并写入到另一个文件中
   async function deflateFile(src: fs.File, dest: fs.File) {
     let flush = zlib.CompressFlushMode.NO_FLUSH;
     let strm: zlib.ZStream = {};  //初始化一个压缩流
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // 初始化一个输入缓冲区
     let outBuf = new ArrayBuffer(BUFLEN); // 初始化一个输出缓冲区
     // 创建一个压缩对象实例
     let zip = zlib.createZipSync();
     // 初始化流的状态
     let initStatus = zip.deflateInit(strm, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED);
     console.info('deflateInit ret: ' + (await initStatus).valueOf());
     do {
       // 从文件中读取数据到缓冲区
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       flush = readLen == 0 ? zlib.CompressFlushMode.FINISH : zlib.CompressFlushMode.NO_FLUSH;
       // 设置输入缓冲区
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // 设置输出缓冲区
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // 压缩输入缓冲区中数据到输出缓冲区
           let deflateStatus = zip.deflate(strm, flush);
           console.info('deflate ret: ' + (await deflateStatus).valueOf());
           // 更新流的状态
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // 将已完成压缩的数据，写入到输出文件中
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('deflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0); // 循环压缩输入缓冲区中剩余的数据，直到全部完成压缩
     } while (flush != zlib.CompressFlushMode.FINISH); // 循环从文件中读取数据，直到数据全部读取
     // 释放资源
     zip.deflateEnd(strm);
   }

   // 从一个文件中，不断的读入已压缩的数据，进行解压，并写入到另一个文件中
   async function inflateFile(src: fs.File, dest: fs.File) {
     let status: zlib.ReturnStatus = zlib.ReturnStatus.OK;
     let strm: zlib.ZStream = {};  //初始化一个压缩流
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // 初始化一个输入缓冲区
     let outBuf = new ArrayBuffer(BUFLEN); // 初始化一个输出缓冲区
     // 创建一个压缩对象实例
     let zip = zlib.createZipSync();
     // 初始化流的状态
     let initStatus = zip.inflateInit(strm);
     console.info('inflateInit ret: ' + (await initStatus).valueOf());
     do {
       // 从文件中读取已压缩的数据到缓冲区
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       if (readLen == 0) {
         break;
       }
       // 设置输入缓冲区
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // 设置输出缓冲区
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // 解压输入缓冲区中数据到输出缓冲区
           let inflateStatus = zip.inflate(strm, zlib.CompressFlushMode.NO_FLUSH);
           console.info('inflate ret: ' + (await inflateStatus).valueOf());
           status = await inflateStatus;
           // 更新流的状态
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // 将已完成解压的数据，写入到输出文件中
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('inflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0)  // 循环解压输入缓冲区中剩余的数据，直到全部完成解压
     } while (status != zlib.ReturnStatus.STREAM_END.valueOf())  // 循环从文件中读取数据，直到数据全部读取
     // 释放资源
     zip.inflateEnd(strm);
   }
   ```

### 未知大小缓冲区的压缩与解压（gzip格式）

采用gzip格式，针对一个未知大小的缓冲区中的数据，使用接口[deflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#deflate12)将从一个原始输入流中读取的数据进行压缩，使用接口[inflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#inflate12)将从一个压缩输入流中读取的数据进行解压，示例代码如下。

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         // 示例一：从文件中不断读取数据进行压缩
         Button('deflateGzipFile').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.gz', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           deflateGzipFile(inFile, outFile).then(() => {
             console.info('deflateGzipFile success');
             fs.closeSync(inFile.fd);
             fs.closeSync(outFile.fd);
           })
         })

         // 示例二：从文件中不断读取压缩数据进行解压
         Button('inflateGzipFile').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.gz', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           inflateGzipFile(inFile, outFile).then(() => {
             console.info('inflateGzipFile success');
             fs.closeSync(inFile.fd);
             fs.closeSync(outFile.fd);
           })
         })
       }
       .height('100%')
       .width('100%')
     }
   }

   // 从一个文件中，不断的读入数据，进行压缩，并写入到另一个文件中
   async function deflateGzipFile(src: fs.File, dest: fs.File) {
     let flush = zlib.CompressFlushMode.NO_FLUSH;
     let strm: zlib.ZStream = {};  //初始化一个压缩流
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // 初始化一个输入缓冲区
     let outBuf = new ArrayBuffer(BUFLEN); // 初始化一个输出缓冲区
     // 创建一个压缩对象实例
     let zip = zlib.createZipSync();
     // 初始化流的状态，windowBits > 15时，启用gzip格式
     let windowBits = 15 + 16;
     let initStatus = zip.deflateInit2(strm, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED,
       zlib.CompressMethod.DEFLATED, windowBits, zlib.MemLevel.MEM_LEVEL_DEFAULT,
       zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY);
     console.info('deflateInit2 ret: ' + (await initStatus).valueOf());
     do {
       // 从文件中读取数据到缓冲区
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       flush = readLen == 0 ? zlib.CompressFlushMode.FINISH : zlib.CompressFlushMode.NO_FLUSH;
       // 设置输入缓冲区
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // 设置输出缓冲区
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // 压缩输入缓冲区中数据到输出缓冲区
           let deflateStatus = zip.deflate(strm, flush);
           console.info('deflate ret: ' + (await deflateStatus).valueOf());
           // 更新流的状态
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // 将已完成压缩的数据，写入到输出文件中
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('deflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0); // 循环压缩输入缓冲区中剩余的数据，直到全部完成压缩
     } while (flush != zlib.CompressFlushMode.FINISH); // 循环从文件中读取数据，直到数据全部读取
     // 释放资源
     zip.deflateEnd(strm);
   }

   // 从一个文件中，不断的读入已压缩的数据，进行解压，并写入到另一个文件中
   async function inflateGzipFile(src: fs.File, dest: fs.File) {
     let status: zlib.ReturnStatus = zlib.ReturnStatus.OK;
     let strm: zlib.ZStream = {};  //初始化一个压缩流
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // 初始化一个输入缓冲区
     let outBuf = new ArrayBuffer(BUFLEN); // 初始化一个输出缓冲区
     // 创建一个压缩对象实例
     let zip = zlib.createZipSync();
     // 初始化流的状态，windowBits > 15时，启用gzip格式
     let windowBits = 15 + 16;
     let initStatus = zip.inflateInit2(strm, windowBits);
     console.info('inflateInit2 ret: ' + (await initStatus).valueOf());
     do {
       // 从文件中读取已压缩的数据到缓冲区
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       if (readLen == 0) {
         break;
       }
       // 设置输入缓冲区
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // 设置输出缓冲区
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // 解压输入缓冲区中数据到输出缓冲区
           let inflateStatus = zip.inflate(strm, zlib.CompressFlushMode.NO_FLUSH);
           console.info('inflate ret: ' + (await inflateStatus).valueOf());
           status = await inflateStatus;
           // 更新流的状态
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // 将已完成解压的数据，写入到输出文件中
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('inflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0)  // 循环解压输入缓冲区中剩余的数据，直到全部完成解压
     } while (status != zlib.ReturnStatus.STREAM_END.valueOf())  // 循环从文件中读取数据，直到数据全部读取
     // 释放资源
     zip.inflateEnd(strm);
   }
   ```

## 常见问题

1. 17800005 传入的数据错误

   可能原因和处理步骤，请参见[错误码17800005](../../reference/apis-basic-services-kit/errorcode-zlib.md#17800005-传入的数据错误)。

2. 17800007 传入的缓冲区错误

   可能原因和处理步骤，请参见[错误码17800007](../../reference/apis-basic-services-kit/errorcode-zlib.md#17800007-传入的缓冲区错误)。