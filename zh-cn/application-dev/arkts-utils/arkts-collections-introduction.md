# ArkTS容器集 (ArkTS Collections)

## 概述

ArkTS容器集可以用于并发场景下的高性能数据传递。功能与JavaScript内建的对应容器类似，但ArkTS容器实例无法通过.或者[]添加属性。

ArkTS容器在多个并发实例间传递时，其默认行为是引用传递，支持多个并发实例可以同时操作同一个容器实例。另外，也支持拷贝传递，即每个并发实例持有一个ArkTS容器实例。

ArkTS容器并不是线程安全的，内部使用了fail-fast（快速失败）机制：当检测多个并发实例同时对容器进行结构性改变时，会触发异常。因此，在修改场景下，容器使用方需要使用ArkTS提供的[异步锁机制](arkts-async-lock-introduction.md)保证ArkTS容器的安全访问。

当前ArkTS容器集主要包含以下几种容器：Array、Map、Set、TypedArray。

ArkTS容器集使用方法具体可查[容器集](../reference/apis-arkts/js-apis-arkts-collections.md)各容器的使用方法。

ArkTS容器集与原生容器API方法的行为对比详查[ArkTS Collections与原生API方法的行为差异对比](arkts-collections-vs-native-api-comparison.md)。


## 使用示例

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { SendableTest } from './sendableTest'

@Concurrent
async function createSendableData(data: SendableTest): Promise<void> {
  console.info("sendableTest: this is createSendableData");
  for(let i = 0;i < 1000;i++) {
    data.v1.push(i);
  }
  data.v2.set(100, "aaa");
  data.v3.add("one");
  data.v3.add("two");
  data.v3.add("three");
}


async function sendableTask(): Promise<void> {
  let sendableClass = new SendableTest();
  await taskpool.execute(createSendableData, sendableClass);
  console.info("sendableTest: sendableClass.v1.length is: " + sendableClass.v1.length);
  console.info("sendableTest: sendableClass.v2.has key is: " + sendableClass.v2.has(100));
  console.info("sendableTest: sendableClass.v3.size is: " + sendableClass.v3.size);
}
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(async () => {
            await sendableTask();
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
import { collections } from '@kit.ArkTS';

@Sendable
export class SendableTest {
  v1: collections.Array<number> = new collections.Array<number>();
  v2: collections.Map<number, string> = new collections.Map<number, string>();
  v3: collections.Set<string> = new collections.Set<string>();

  constructor() {
  }
}
```