# Asynchronous Waiting

To address timing control issues in multithreaded tasks, ArkTS has introduced asynchronous waiting and notification capabilities. The [ConditionVariable](../reference/apis-arkts/js-apis-arkts-utils.md#conditionvariable16) object supports pass-by-reference across threads.

ArkTS, which supports asynchronous operations, now provides the capability for asynchronous tasks to wait and be awakened. When a wake-up notification is received or the waiting times out, the asynchronous execution continues.

> **NOTE**
>
> Methods using asynchronous waiting must be marked as **async**, and the caller must use the **await** keyword to ensure correct timing.

## Usage Example

The following example demonstrates how to control asynchronous task waiting and awakening using [Sendable](arkts-sendable.md) objects across threads.

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
            // Create a conditionVariable object.
            const conditionVariable: ArkTSUtils.locks.ConditionVariable = new ArkTSUtils.locks.ConditionVariable();
            // Pass the conditionVariable object to the wait thread.
            taskpool.execute(wait, conditionVariable);
            // Pass the conditionVariable object to the notify thread to wake up the wait thread. The log information "TaskPool Thread Wait: success" is displayed.
            taskpool.execute(notifyAll, conditionVariable);
            // Pass the conditionVariable object to the waitFor thread.
            taskpool.execute(waitFor, conditionVariable);
            // Pass the conditionVariable object to the notifyOne thread to wake up the waitFor thread. The log information "TaskPool Thread WaitFor: success" is displayed.
            taskpool.execute(notifyOne, conditionVariable);

            // Create a conditionVariable object with a name.
            const conditionVariableRequest: ArkTSUtils.locks.ConditionVariable =
                ArkTSUtils.locks.ConditionVariable.request("Request1");
            // Pass the conditionVariableRequest object to the wait thread.
            taskpool.execute(wait, conditionVariableRequest);
            // Pass the conditionVariableRequest object to the notify thread to wake up the wait thread. The log information "TaskPool Thread Wait: success" is displayed.
            taskpool.execute(notifyAll, conditionVariableRequest);
            // Pass the conditionVariableRequest object to the waitFor thread.
            taskpool.execute(waitFor, conditionVariableRequest);
            // Pass the conditionVariableRequest object to the notifyOne thread to wake up the waitFor thread. The log information "TaskPool Thread WaitFor: success" is displayed.
            taskpool.execute(notifyOne, conditionVariableRequest);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

 <!--no_check--> 