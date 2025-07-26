# Compressing and Decompressing Files

This topic describes how to use functions in common compression and decompression scenarios.

## Available APIs

For details about more APIs and their usage, see [Zip](../../reference/apis-basic-services-kit/js-apis-zlib.md).

| API                                                      | Description                    |
| ------------------------------------------------------------ | ---------------------------- |
| compressFile(inFile: string, outFile: string, options: Options): Promise&lt;void&gt; | Compresses a file.              |
| decompressFile(inFile: string, outFile: string, options?: Options): Promise&lt;void&gt; | Decompresses a file.              |
| compress(dest: ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt; | Compresses the source buffer into the destination buffer.              |
| compressBound(sourceLen: number): Promise&lt;number&gt; | Calculates the upper limit of the compression size to return.             |
| uncompress(dest:ArrayBuffer, source: ArrayBuffer, sourceLen?: number): Promise&lt;ZipOutputInfo&gt; | Decompresses the compressed data into an original uncompressed one.              |
| deflate(strm: ZStream, flush: CompressFlushMode): Promise&lt;ReturnStatus&gt; | Deflates data.              |
| inflate(strm: ZStream, flush: CompressFlushMode): Promise&lt;ReturnStatus&gt; | Inflates data.|

## How to Develop

### Environment Preparations

Create a test file **data.txt** in the application sandbox directory and write data for testing. The sample code is as follows:

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
           // Create the data.txt file and write test data.
           Button('Create a test file data.txt').onClick(() => {
             let path = this.getUIContext()?.getHostContext()?.filesDir;
             // Create the data.txt file.
             let inFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
             // Write test data.
             for (let index = 0; index < 100; index++) {
               fs.writeSync(inFile.fd, index + ': hello world, hello world, hello world, hello world, hello world.\n');
             }
             // Obtain the original size of the test data and save it to dataSize.
             let stat = fs.statSync(inFile.path);
             this.dataSize = stat.size;
             console.info('dataSize: ' + this.dataSize);
             // Close the file.
             fs.closeSync(inFile);
           })
         }
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

### Compressing and Decompressing .zip Files

Use [zlib.compressFile()](../../reference/apis-basic-services-kit/js-apis-zlib.md#zlibcompressfile9-1) to compress the **data.txt** into to the **data.zip** file, and use [zlib.decompressFile()](../../reference/apis-basic-services-kit/js-apis-zlib.md#zlibdecompressfile9-1) to decompress the .zip file to the application sandbox directory. The sample code is as follows:

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         // Example 1: Compress the data.txt file into the data.zip file.
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

         // Example 2: Decompress the data.zip file to the application sandbox directory.
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

### Compressing and Decompressing Buffers of Known Sizes

For data in a buffer with a known size, use [compress()](../../reference/apis-basic-services-kit/js-apis-zlib.md#compress12) to compress the data into a destination buffer, [compressBound()](../../reference/apis-basic-services-kit/js-apis-zlib.md#compressbound12) to calculate the upper limit of the compression size of the destination buffer, and [uncompress()](../../reference/apis-basic-services-kit/js-apis-zlib.md#uncompress12) to decompress the buffer that stores the compressed data. To check the size of the destination buffer after decompression, obtain and save the original data size before compression. The sample code is as follows:

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     @State dataSize: number = 0; // Size of the original data.

     build() {
       Row() {
         // Example 1: Read the data.txt file and save it to a buffer. Call the compress API to compress the data in the source buffer to the destination buffer and write the content in the destination buffer to the data.bin file.
         Button('compress buffer').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.bin', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           // Read the content of the data.txt file and save the content to the buffer inBuf.
           let stat = fs.statSync(inFile.path);
           let inBuf = new ArrayBuffer(stat.size);
           let readLen = fs.readSync(inFile.fd, inBuf);
           console.info(`original size: ${stat.size}, read len: ${readLen}`);
           // Obtain the size of the original data and save it.
           this.dataSize = stat.size;
           // Create a compressed object instance.
           let zip = zlib.createZipSync();
           // Obtain the upper limit of a destination buffer.
           zip.compressBound(stat.size).then((data) => {
             console.info(`the max dest buf len is ${data}`);
             // Destination buffer outBuf.
             let outBuf = new ArrayBuffer(data);
             // Compress the data in inBuf to outBuf.
             zip.compress(outBuf, inBuf, readLen).then((zipOutInfo) => {
               console.info(`compress success, status ${zipOutInfo.status}, destLen  ${zipOutInfo.destLen}`);
               // Write the data in outBuf to the data.bin file.
               let writeLen = fs.writeSync(outFile.fd, outBuf, { length: zipOutInfo.destLen });
               console.info(`write destBuf to data.bin, writeLen ${writeLen}`);
               // Close the file.
               fs.closeSync(inFile.fd);
               fs.closeSync(outFile.fd);
             }).catch((errData: BusinessError) => {
               console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
             })
           }).catch((errData: BusinessError) => {
             console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
           })
         })

         // Example 2: Read the compressed data in the data.bin file and save it to a buffer. Call the uncompress API to decompress the data in the source buffer to the destination buffer and write the content in the destination buffer to the data.txt file.
         Button('uncompress buffer').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.bin', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           // Read the compressed data in the data.bin file and save the data to the buffer inBuf.
           let stat = fs.statSync(inFile.path);
           let inBuf = new ArrayBuffer(stat.size);
           let readLen = fs.readSync(inFile.fd, inBuf);
           console.info(`compressed data size: ${stat.size}, read len: ${readLen}`);
           // Create a destination buffer. dataSize indicates the original size of the data saved before compression.
           let outBuf = new ArrayBuffer(this.dataSize);
           console.info(`the dest buf size is ${this.dataSize}`);
           // Create a compressed object instance.
           let zip = zlib.createZipSync();
           // Decompress the data in inBuf to outBuf.
           zip.uncompress(outBuf, inBuf, readLen).then((zipOutInfo) => {
             console.info(`uncompress success, status ${zipOutInfo.status}, destLen  ${zipOutInfo.destLen}`);
             // Write the data in outBuf to the data.txt file.
             let writeLen = fs.writeSync(outFile.fd, outBuf, { length: zipOutInfo.destLen });
             console.info(`write destBuf to data.txt, writeLen ${writeLen}`);
             // Close the file.
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

### Compressing and Decompressing Buffers of Unknown Sizes (.zlib Format)

For data in a buffer with an unknown size, use [deflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#deflate12) to compress the data read from an original input stream and [inflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#inflate12) to decompress the data read from a compressed input stream. The sample code is as follows:

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         // Example 1: Continuously read data from a file for compression.
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

         // Example 2: Continuously read compressed data from the file for decompression.
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

   // Continuously read data from a file, compress the data, and write the data to another file.
   async function deflateFile(src: fs.File, dest: fs.File) {
     let flush = zlib.CompressFlushMode.NO_FLUSH;
     let strm: zlib.ZStream = {};  // Initialize a compression stream.
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // Initialize an input buffer.
     let outBuf = new ArrayBuffer(BUFLEN); // Initialize an output buffer.
     // Create a compressed object instance.
     let zip = zlib.createZipSync();
     // Initialize the stream status.
     let initStatus = zip.deflateInit(strm, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED);
     console.info('deflateInit ret: ' + (await initStatus).valueOf());
     do {
       // Read data from a file to a buffer.
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       flush = readLen == 0 ? zlib.CompressFlushMode.FINISH : zlib.CompressFlushMode.NO_FLUSH;
       // Set the input buffer.
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // Set the output buffer.
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // Compress the data in the input buffer to the output buffer.
           let deflateStatus = zip.deflate(strm, flush);
           console.info('deflate ret: ' + (await deflateStatus).valueOf());
           // Update the stream status.
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // Write the compressed data to the output file.
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('deflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0); // Compress the remaining data in the input buffer cyclically until all data is compressed.
     } while (flush != zlib.CompressFlushMode.FINISH); // Read data from the file cyclically until all data is read.
     // Release resources.
     zip.deflateEnd(strm);
   }

   // Continuously read compressed data from a file, decompress the data, and write the data to another file.
   async function inflateFile(src: fs.File, dest: fs.File) {
     let status: zlib.ReturnStatus = zlib.ReturnStatus.OK;
     let strm: zlib.ZStream = {};  // Initialize a compression stream.
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // Initialize an input buffer.
     let outBuf = new ArrayBuffer(BUFLEN); // Initialize an output buffer.
     // Create a compressed object instance.
     let zip = zlib.createZipSync();
     // Initialize the stream status.
     let initStatus = zip.inflateInit(strm);
     console.info('inflateInit ret: ' + (await initStatus).valueOf());
     do {
       // Read the compressed data from the file to the buffer.
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       if (readLen == 0) {
         break;
       }
       // Set the input buffer.
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // Set the output buffer.
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // Decompress the data in the input buffer to the output buffer.
           let inflateStatus = zip.inflate(strm, zlib.CompressFlushMode.NO_FLUSH);
           console.info('inflate ret: ' + (await inflateStatus).valueOf());
           // Update the stream status.
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // Write the decompressed data to the output file.
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('inflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0)  // Decompress the remaining data in the input buffer cyclically until all data is decompressed.
     } while (status != zlib.ReturnStatus.STREAM_END.valueOf())  // Read data from the file cyclically until all data is read.
     // Release resources.
     zip.inflateEnd(strm);
   }
   ```

### Compressing and Decompressing Buffers of Unknown Sizes (.gzip Format)

For data in a buffer with an unknown size, use [deflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#deflate12) to compress the data read from an original input stream and [inflate()](../../reference/apis-basic-services-kit/js-apis-zlib.md#inflate12) to decompress the data read from a compressed input stream. The sample code is as follows:

   ```ts
   import { fileIo as fs} from '@kit.CoreFileKit';
   import { BusinessError, zlib } from '@kit.BasicServicesKit';

   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         // Example 1: Continuously read data from a file for compression.
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

         // Example 2: Continuously read compressed data from the file for decompression.
         Button('inflateGzipFile').onClick(() => {
           let path = this.getUIContext()?.getHostContext()?.filesDir;
           let inFile = fs.openSync(path + '/data.gz', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           let outFile = fs.openSync(path + '/data.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
           inflateGzipFile(inFile, outFile).then(() => {
             console.info('deflateGzipFile success');
             fs.closeSync(inFile.fd);
             fs.closeSync(outFile.fd);
           })
         })
       }
       .height('100%')
       .width('100%')
     }
   }

   // Continuously read data from a file, compress the data, and write the data to another file.
   async function deflateGzipFile(src: fs.File, dest: fs.File) {
     let flush = zlib.CompressFlushMode.NO_FLUSH;
     let strm: zlib.ZStream = {};  // Initialize a compression stream.
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // Initialize an input buffer.
     let outBuf = new ArrayBuffer(BUFLEN); // Initialize an output buffer.
     // Create a compressed object instance.
     let zip = zlib.createZipSync();
     // Initialize the stream status. If windowBits is greater than 15, the .gzip format is used.
     let windowBits = 15 + 16;
     let initStatus = zip.deflateInit2(strm, zlib.CompressLevel.COMPRESS_LEVEL_BEST_SPEED,
       zlib.CompressMethod.DEFLATED, windowBits, zlib.MemLevel.MEM_LEVEL_DEFAULT,
       zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY);
     console.info('deflateInit2 ret: ' + (await initStatus).valueOf());
     do {
       // Read data from a file to a buffer.
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       flush = readLen == 0 ? zlib.CompressFlushMode.FINISH : zlib.CompressFlushMode.NO_FLUSH;
       // Set the input buffer.
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // Set the output buffer.
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // Compress the data in the input buffer to the output buffer.
           let deflateStatus = zip.deflate(strm, flush);
           console.info('deflate ret: ' + (await deflateStatus).valueOf());
           // Update the stream status.
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // Write the compressed data to the output file.
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('deflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0); // Compress the remaining data in the input buffer cyclically until all data is compressed.
     } while (flush != zlib.CompressFlushMode.FINISH); // Read data from the file cyclically until all data is read.
     // Release resources.
     zip.deflateEnd(strm);
   }

   // Continuously read compressed data from a file, decompress the data, and write the data to another file.
   async function inflateGzipFile(src: fs.File, dest: fs.File) {
     let status: zlib.ReturnStatus = zlib.ReturnStatus.OK;
     let strm: zlib.ZStream = {};  // Initialize a compression stream.
     const BUFLEN = 4096;
     let inBuf = new ArrayBuffer(BUFLEN);  // Initialize an input buffer.
     let outBuf = new ArrayBuffer(BUFLEN); // Initialize an output buffer.
     // Create a compressed object instance.
     let zip = zlib.createZipSync();
     // Initialize the stream status. If windowBits is greater than 15, the .gzip format is used.
     let windowBits = 15 + 16;
     let initStatus = zip.inflateInit2(strm, windowBits);
     console.info('inflateInit2 ret: ' + (await initStatus).valueOf());
     do {
       // Read the compressed data from the file to the buffer.
       let readLen = fs.readSync(src.fd, inBuf);
       console.info("readSync readLen: " + readLen);
       if (readLen == 0) {
         break;
       }
       // Set the input buffer.
       strm.availableIn = readLen;
       strm.nextIn = inBuf;
       do {
         // Set the output buffer.
         strm.availableOut = BUFLEN;
         strm.nextOut = outBuf;
         try {
           // Decompress the data in the input buffer to the output buffer.
           let inflateStatus = zip.inflate(strm, zlib.CompressFlushMode.NO_FLUSH);
           console.info('inflate ret: ' + (await inflateStatus).valueOf());
           // Update the stream status.
           let innerStrm = zip.getZStream();
           strm.availableIn = (await innerStrm).availableIn;
           strm.nextIn = (await innerStrm).nextIn;
           strm.availableOut = (await innerStrm).availableOut;
           strm.nextOut = (await innerStrm).nextOut;
           strm.totalIn = (await innerStrm).totalIn;
           strm.totalOut = (await innerStrm).totalOut;

           if (strm.availableOut != undefined) {
             // Write the decompressed data to the output file.
             let have = BUFLEN - strm.availableOut;
             let writeLen = fs.writeSync(dest.fd, outBuf, { length: have });
             console.info(`writeSync writeLen: ${writeLen}`);
           }
         } catch (err) {
           console.error('inflate err: ' + JSON.stringify(err));
         }
       } while (strm.availableOut == 0)  // Decompress the remaining data in the input buffer cyclically until all data is decompressed.
     } while (status != zlib.ReturnStatus.STREAM_END.valueOf())  // Read data from the file cyclically until all data is read.
     // Release resources.
     zip.inflateEnd(strm);
   }
   ```

## FAQs

1. 17800005 Incorrect Input Data

   For details about the possible causes and solution, see [error code 17800005](../../reference/apis-basic-services-kit/errorcode-zlib.md#17800005-incorrect-input-data).

2. 17800007 Incorrect Input Buffer

   For details about the possible causes and solution, see [error code 17800007](../../reference/apis-basic-services-kit/errorcode-zlib.md#17800007-incorrect-input-buffer).
