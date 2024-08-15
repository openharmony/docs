# ArkTS Asynchronous Lock

## Overview

To avoid data races between concurrent instances, the ArkTS common library introduces **AsyncLock**. Passing **AsyncLock** objects by reference across concurrent instances is supported.

ArkTS supports asynchronous operations, and blocking locks are prone to deadlocks. Therefore, only asynchronous locks (non-blocking locks) are used in ArkTS.

For details, see [AsyncLock APIs](../reference/apis-arkts/js-apis-arkts-utils.md#arktsutilslocks).

The method that uses an asynchronous lock must be marked as **async**, and the caller must use **await** in the call to ensure the correct call sequence. As a result, all outer functions are marked as **async**.


## Example

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { A, a } from './sendableTest'

@Concurrent
async function printInfo(a: A) {
  a.increaseCount()
  a.setName("sendableTest: this taskpool thread!")
  console.info("sendableTest: child thread count is: " + await a.getCount() + ", name is: " + await a.getName());
}


async function testFunc() {
  await taskpool.execute(printInfo, a);
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button("Main thread!")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(async () => {
            console.info("sendableTest: Main thread count is: " + await a.getCount() + ", name is: " + await a.getName());
          })
        Button("taskpool thread!")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(async () => {
            await testFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

```ts
// sendableTest.ets
import { ArkTSUtils } from '@kit.ArkTS';
@Sendable
export class A {
  private count_: number = 0;
  private name_: string = 'ClassA';
  lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock()

  public async getCount(): Promise<number> {
    return this.lock_.lockAsync(() => {
      return this.count_;
    })
  }

  public async increaseCount() {
    await this.lock_.lockAsync(() => {
      this.count_++;
    })
  }

  public async getName(): Promise<string> {
    return this.lock_.lockAsync(() => {
      return this.name_;
    })
  }

  public async setName(name: string) {
    await this.lock_.lockAsync(() => {
      this.name_ = name;
    })
  }
}

export let a:A = new A();
```
