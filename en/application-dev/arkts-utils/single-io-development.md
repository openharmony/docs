# Single I/O Task Development


Asynchronous concurrency provided by Promise and async/await is applicable to the development of a single I/O task. The following uses the asynchronous concurrency capability to write a file as an example.


1. Implement the logic of a single I/O task.

   ```js
   import fs from '@ohos.file.fs';

   async function write(data: string, filePath: string) {
     let file = await fs.open(filePath, fs.OpenMode.READ_WRITE);
     fs.write(file.fd, data).then((writeLen) => {
       fs.close(file);
     }).catch((err) => {
       console.error(`Failed to write data. Code is ${err.code}, message is ${err.message}`);
     })
   }
   ```

2. Use the asynchronous capability to invoke the single I/O task. For details about how to obtain **filePath** in the example, see [Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths).

   ```js
   let filePath = ...; // Application file path
   write('Hello World!', filePath).then(() => {
     console.info('Succeeded in writing data.');
   })
   ```
