# 使用Worker进行线程间通信


[Worker](../reference/apis/js-apis-worker.md)是与主线程并行的独立线程。创建Worker的线程被称为宿主线程，Worker工作的线程被称为Worker线程。创建Worker时传入的脚本文件在Worker线程中执行，通常在Worker线程中处理耗时的操作，需要注意的是，Worker中不能直接更新Page。


Worker的开发步骤如下：


1. 在工程的[模块级build-profile.json5](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-building-configuration-0000001218440654#section6887184182020)文件的buildOption属性中添加配置信息。

   ```ts
     "buildOption": {
       "sourceOption": {
         "workers": [
           "./src/main/ets/workers/worker.ts"
         ]
       }
     }
   ```

2. 根据build-profile.json5中的配置创建对应的worker.js文件。

   ```ts
   import worker from '@ohos.worker';

   let parent = worker.workerPort;

   // 处理来自主线程的消息
   parent.onmessage = function(message) {
       console.info("onmessage: " + message)
       // 发送消息到主线程
       parent.postMessage("message from worker thread.")
   }
   ```

3. 主线程中使用如下方式初始化和使用worker。
   - Stage模型：

      ```ts
      import worker from '@ohos.worker';

      let wk = new worker.ThreadWorker("entry/ets/workers/worker.ts");

      // 发送消息到worker线程
      wk.postMessage("message from main thread.")

      // 处理来自worker线程的消息
      wk.onmessage = function(message) {
          console.info("message from worker: " + message)

          // 根据业务按需停止worker线程
          wk.terminate()
      }
      ```

   - FA模型：

      ```ts
      import worker from '@ohos.worker';

      let wk = new worker.ThreadWorker("../workers/worker.js");

      // 发送消息到worker线程
      wk.postMessage("message from main thread.")

      // 处理来自worker线程的消息
      wk.onmessage = function(message) {
          console.info("message from worker: " + message)

          // 根据业务按需停止worker线程
          wk.terminate()
      }
      ```

**说明：**

- build-profile.json5中配置的worker.ts的相对路径都为`./src/main/ets/workers/worker.ts`时，在Stage模型下创建worker需要传入路径`entry/ets/workers/worker.ts`；在FA模型下创建worker需要传入路径`../workers/worker.js`。

- 主线程与Worker线程间支持的数据类型参考[序列化支持类型](../reference/apis/js-apis-worker.md#%E5%BA%8F%E5%88%97%E5%8C%96%E6%94%AF%E6%8C%81%E7%B1%BB%E5%9E%8B)。
