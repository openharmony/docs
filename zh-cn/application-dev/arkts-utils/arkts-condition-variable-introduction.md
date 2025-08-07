# 异步等待
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

ArkTS引入了异步任务的等待和被唤醒能力，以解决多线程任务时序控制问题。异步任务的等待和被唤醒[ConditionVariable](../reference/apis-arkts/arkts-apis-arkts-utils-locks.md#conditionvariable18)对象支持跨线程引用传递。

ArkTS语言支持异步操作，现已增加异步任务的等待和唤醒功能。当异步任务收到唤醒通知或等待超时后，将继续执行。

> **说明：**
>
> 使用异步方法需标记为async，调用时需用await修饰，确保时序正确。

## 使用示例

[Sendable](arkts-sendable.md)共享对象在不同线程控制异步任务等待和唤醒的示例如下：

```ts
import { ArkTSUtils, taskpool } from '@kit.ArkTS';

@Concurrent
function notifyAll(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
  conditionVariable.notifyAll();
}

@Concurrent
function notifyOne(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
  conditionVariable.notifyOne();
}

@Concurrent
async function wait(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
  await conditionVariable.wait().then(() => {
    console.log(`TaskPool Thread Wait: success`);
  });
}

@Concurrent
async function waitFor(conditionVariable: ArkTSUtils.locks.ConditionVariable) {
  await conditionVariable.waitFor(3000).then(() => {
    console.log(`TaskPool Thread WaitFor: success`);
  });
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // 创建conditionVariable对象
            const conditionVariable: ArkTSUtils.locks.ConditionVariable = new ArkTSUtils.locks.ConditionVariable();
            // 将实例conditionVariable传递给wait线程
            taskpool.execute(wait, conditionVariable);
            // 将实例conditionVariable传递给notifyAll线程，唤醒wait线程，日志输出"TaskPool Thread Wait: success"
            taskpool.execute(notifyAll, conditionVariable);
            // 将实例conditionVariable传递给waitFor线程
            taskpool.execute(waitFor, conditionVariable);
            // 将实例conditionVariable传递给notifyOne线程，唤醒waitFor线程，日志输出"TaskPool Thread WaitFor: success"
            taskpool.execute(notifyOne, conditionVariable);

            // 创建有name的conditionVariable对象
            const conditionVariableRequest: ArkTSUtils.locks.ConditionVariable =
                ArkTSUtils.locks.ConditionVariable.request("Request1");
            // 将实例conditionVariableRequest传递给wait线程
            taskpool.execute(wait, conditionVariableRequest);
            // 将实例conditionVariableRequest传递给notifyAll线程，唤醒wait线程，日志输出"TaskPool Thread Wait: success"
            taskpool.execute(notifyAll, conditionVariableRequest);
            // 将实例conditionVariableRequest传递给waitFor线程
            taskpool.execute(waitFor, conditionVariableRequest);
            // 将实例conditionVariableRequest传递给notifyOne线程，唤醒waitFor线程，日志输出"TaskPool Thread WaitFor: success"
            taskpool.execute(notifyOne, conditionVariableRequest);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
