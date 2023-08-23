# I/O Intensive Task Development


Asynchronous concurrency can solve the problem of a single blocking I/O operation. In the case of I/O intensive tasks, the execution of other tasks in the thread is still blocked. To resolve this issue, multithread concurrency is introduced.


The performance focus of I/O intensive tasks is not the CPU processing capability, but the speed and efficiency of I/O operations, since such a task usually requires frequent operations such as disk read/write and network communication. The following uses frequent read/write operations on a system file to simulate concurrency processing of I/O intensive tasks.


1. Define a concurrency function that internally calls I/O capabilities intensively.

   ```ts
   import fs from '@ohos.file.fs';

   // Define a concurrency function that internally calls I/O capabilities intensively.
   @Concurrent
   async function concurrentTest(fileList: string[]) {
     // Implement file writing.
     async function write(data, filePath) {
       let file = await fs.open(filePath, fs.OpenMode.READ_WRITE);
       await fs.write(file.fd, data);
       fs.close(file);
     }
     // Write the file cyclically.
     for (let i = 0; i < fileList.length; i++) {
       write('Hello World!', fileList[i]).then(() => {
         console.info(`Succeeded in writing the file. FileList: ${fileList[i]}`);
       }).catch((err) => {
         console.error(`Failed to write the file. Code is ${err.code}, message is ${err.message}`)
         return false;
       })
     }
     return true;
   }
   ```

2. Use **TaskPool** to execute the concurrency function that contains the intensive I/O operations. Specifically, call [execute()](../reference/apis/js-apis-taskpool.md#taskpoolexecute) to execute the tasks and process the scheduling result in a callback. For details about how to obtain **filePath1** and **filePath2** in the example, see [Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths).

   ```ts
   import taskpool from '@ohos.taskpool';

   let filePath1 =...; // Application file path
   let filePath2 = ...;

   // Use TaskPool to execute the concurrency function that contains the intensive I/O operations.
   // In the case of a large array, the distribution of I/O intensive tasks also preempts the main thread. Therefore, multiple threads are required.
   taskpool.execute(concurrentTest, [filePath1, filePath2]).then((ret) => {
     // Process the scheduling result.
     console.info(`The result: ${ret}`);
   })
   ```
