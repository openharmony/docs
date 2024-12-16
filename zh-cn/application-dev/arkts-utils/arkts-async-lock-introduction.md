# 异步锁

为了解决多线程并发任务间的数据竞争问题，ArkTS引入了异步锁能力。异步锁可能会被类对象持有，因此为了更方便地在并发实例间获取同一个异步锁对象，[AsyncLock对象](../reference/apis-arkts/js-apis-arkts-utils.md#asynclock)支持跨线程引用传递。

由于ArkTS语言支持异步操作，阻塞锁容易产生死锁问题，因此在ArkTS中仅支持异步锁（非阻塞式锁）。同时，异步锁还可以用于保证单线程内的异步任务时序一致性，防止异步任务时序不确定导致的同步问题。

更多异步锁相关接口，可见[异步锁ArkTSUtils.locks](../reference/apis-arkts/js-apis-arkts-utils.md#arktsutilslocks)。

> **说明：**
>
> 使用异步锁的方法需要标记为async，调用方需要使用await修饰，才能保证时序正确。

## 使用示例

为了解决[@Sendable共享对象](arkts-sendable.md)在不同线程修改共享变量导致的竞争问题，可以采用异步锁进行数据保护。示例如下：

```ts
import { ArkTSUtils, taskpool } from '@kit.ArkTS';

@Sendable
export class A {
  private count_: number = 0;
  lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();

  public async getCount(): Promise<number> {
    // 对需要保护的数据加异步锁
    return this.lock_.lockAsync(() => {
      return this.count_;
    })
  }

  public async increaseCount() {
    // 对需要保护的数据加异步锁
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
          // 创建sendable对象a
          let a: A = new A();
          // 将实例a传递给子线程
          await taskpool.execute(printCount, a);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
