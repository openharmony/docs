# ArkTS异步锁

## 概述

为了解决多并发实例间的数据竞争问题，ArkTS语言基础库引入了异步锁能力。为了开发者的开发效率，AsyncLock对象支持跨并发实例引用传递。

由于ArkTS语言支持异步操作，阻塞锁容易产生死锁问题，因此我们在ArkTS中仅支持异步锁（非阻塞式锁）。

异步锁各方法使用可详查[异步锁API](../reference/apis-arkts/js-apis-arkts-utils.md#arktsutilslocks)。

使用异步锁的方法需要标记为async，调用方需要await修饰调用，才能保证时序正确。因此会导致外层调用函数全部标记成async。


## 使用示例

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