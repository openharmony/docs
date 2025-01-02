# Asynchronous Lock

To solve the data contention problem between multi-thread concurrent tasks, ArkTS introduces the asynchronous lock capability. An asynchronous lock may be held by a class object. Therefore, to facilitate obtaining of the same asynchronous lock object between concurrent instances, the [AsyncLock object](../reference/apis-arkts/js-apis-arkts-utils.md#asynclock) supports cross-thread reference transfer.

ArkTS supports asynchronous operations, and blocking locks are prone to deadlocks. Therefore, only asynchronous locks (non-blocking locks) are used in ArkTS. In addition, the asynchronous lock may be further used to ensure time sequence consistency of asynchronous tasks in a single thread, to prevent a synchronization problem caused by an uncertain time sequence of the asynchronous tasks.

For more APIs related to asynchronous locks, see [ArkTSUtils.locks](../reference/apis-arkts/js-apis-arkts-utils.md#arktsutilslocks).

> **Note**
>
> The method that uses an asynchronous lock must be marked as **async**, and the caller must use **await** in the call to ensure the correct call sequence.

## Example

To solve the contention problem caused by the modification of shared variables in different threads of the [@Sendable object](arkts-sendable.md), asynchronous locks can be used for data protection. Example:

```ts
import { ArkTSUtils, taskpool } from '@kit.ArkTS';

@Sendable
export class A {
  private count_: number = 0;
  lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();

  public async getCount(): Promise<number> {
    // Add an asynchronous lock to the data to be protected.
    return this.lock_.lockAsync(() => {
      return this.count_;
    })
  }

  public async increaseCount() {
    // Add an asynchronous lock to the data to be protected.
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
          // Create the sendable object a.
          let a: A = new A();
          // Transfer instance a to the subthread.
          await taskpool.execute(printCount, a);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
