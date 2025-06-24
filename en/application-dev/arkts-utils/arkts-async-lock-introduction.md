# Asynchronous Lock

To address data race issues in concurrent multithreading instances, ArkTS introduces asynchronous locks. These locks can be held by class objects. To simplify access across concurrent instances, the [AsyncLock object](../reference/apis-arkts/js-apis-arkts-utils.md#asynclock) supports pass-by-reference across threads.

Given that ArkTS supports asynchronous operations, blocking locks are prone to deadlocks. Therefore, ArkTS only supports asynchronous locks (non-blocking locks). In addition, asynchronous locks can ensure the temporal consistency of asynchronous tasks within a single thread, preventing synchronization issues caused by uncertain task timing.

For more details about asynchronous lock APIs, see [ArkTSUtils.locks](../reference/apis-arkts/js-apis-arkts-utils.md#arktsutilslocks).

> **NOTE**
>
> Methods using asynchronous locks must be marked as **async**, and the caller must use the **await** keyword to ensure correct timing.

## Usage Example

To prevent data races when modifying shared variables across threads with [@Sendable objects](arkts-sendable.md), asynchronous locks can be used for data protection. The sample code is as follows:

```ts
import { ArkTSUtils, taskpool } from '@kit.ArkTS';

@Sendable
export class A {
  private count_: number = 0;
  lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();

  public async getCount(): Promise<number> {
    // Add an asynchronous lock to protect the data.
    return this.lock_.lockAsync(() => {
      return this.count_;
    })
  }

  public async increaseCount() {
    // Add an asynchronous lock to protect the data.
    await this.lock_.lockAsync(() => {
      this.count_++;
    })
  }
}

@Concurrent
async function printCount(a: A) {
  console.info("InputModule: count is:" + await a.getCount());
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(async () => {
          // Create the Sendable object a.
          let a: A = new A();
          // Pass object a to a child thread.
          await taskpool.execute(printCount, a);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
<!-- @[example_protect](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableObjectRelated/entry/src/main/ets/managers/ArktsAsyncLockIntroduction.ets) -->
