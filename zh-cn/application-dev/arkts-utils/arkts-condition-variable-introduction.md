# 异步等待
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @dwhuawei-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

ArkTS引入了异步任务的等待和唤醒能力，以解决多线程任务时序控制问题。异步任务通过[ConditionVariable](../reference/apis-arkts/arkts-apis-arkts-utils-locks.md#conditionvariable18)对象实现等待和唤醒机制，该对象支持跨线程引用传递。

ArkTS语言支持异步操作，API18版本开始支持异步任务的等待和唤醒功能。当异步任务收到唤醒通知或等待超时后，将继续执行。

> **说明：**
>
> 使用异步方法需标记为async，调用时可用await修饰，确保时序正确。

## 使用示例

[Sendable](arkts-sendable.md)共享对象在不同线程控制异步任务等待和唤醒的示例如下：

   <!-- @[sendable_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/AsynchronousWaiting/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   import { ArkTSUtils, taskpool } from '@kit.ArkTS';
   
   @Concurrent
   function notifyAll(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
     console.info(`TaskPool Thread notifyAll`);
     conditionVariable.notifyAll();
   }
   
   @Concurrent
   function notifyOne(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
     console.info(`TaskPool Thread notifyOne`);
     conditionVariable.notifyOne();
   }
   
   @Concurrent
   async function wait(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
     conditionVariable.wait().then(() => {
       console.info(`TaskPool Thread Wait: success`);
     });
   }
   
   @Concurrent
   async function waitFor(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
     conditionVariable.waitFor(3000).then(() => {
       console.info(`TaskPool Thread WaitFor: success`);
     });
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string | ResourceStr = $r('app.string.AsyncButton'); // 加载资源，可根据项目实际资源自定义
   
     build() {
       Row() {
         Column() {
           Button(this.message)
             .fontSize(25)
             .fontWeight(FontWeight.Bold)
             .onClick(async () => {
               // 创建conditionVariable对象。
               const conditionVariable: ArkTSUtils.locks.ConditionVariable = new ArkTSUtils.locks.ConditionVariable();
               // 将实例conditionVariable传递给wait线程。
               await taskpool.execute(wait, conditionVariable);
               // 将实例conditionVariable传递给notifyAll线程，唤醒wait线程，日志输出"TaskPool Thread Wait: success"。
               await taskpool.execute(notifyAll, conditionVariable);
               // 将实例conditionVariable传递给waitFor线程。
               await taskpool.execute(waitFor, conditionVariable);
               // 将实例conditionVariable传递给notifyOne线程，唤醒waitFor线程，日志输出"TaskPool Thread WaitFor: success"。
               await taskpool.execute(notifyOne, conditionVariable);
   
               // 创建有name的conditionVariable对象。
               const conditionVariableRequest: ArkTSUtils.locks.ConditionVariable =
                 ArkTSUtils.locks.ConditionVariable.request('Request1');
               // 将实例conditionVariableRequest传递给wait线程。
               await taskpool.execute(wait, conditionVariableRequest);
               // 将实例conditionVariableRequest传递给notifyAll线程，唤醒wait线程，日志输出"TaskPool Thread Wait: success"。
               await taskpool.execute(notifyAll, conditionVariableRequest);
               // 将实例conditionVariableRequest传递给waitFor线程。
               await taskpool.execute(waitFor, conditionVariableRequest);
               // 将实例conditionVariableRequest传递给notifyOne线程，唤醒waitFor线程，日志输出"TaskPool Thread WaitFor: success"。
               await taskpool.execute(notifyOne, conditionVariableRequest);
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```


