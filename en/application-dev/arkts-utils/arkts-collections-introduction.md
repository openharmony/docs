# ArkTS Collections

## Overview

The collections module provides ArkTS containers for efficient data transfer in concurrency scenarios. The ArkTS containers provide similar functionalities as their JavaScript counterparts, except that their properties cannot be added through . or [].

By default, ArkTS containers are passed by reference between concurrent instances. This means that multiple concurrent instances can simultaneously operate the same container instance. Pass-by-copy is also supported. In this mode, each concurrent instance holds an ArkTS container instance.

ArkTS containers are not thread-safe. They adopt the fail-fast approach. An exception is thrown if multiple concurrent instances make structural changes to a container instance at the same time. Therefore, in update scenarios, you must use the ArkTS [asynchronous lock](arkts-async-lock-introduction.md) to ensure secure access to the ArkTS containers.

Currently, the ArkTS collections contain the following containers: Array, Map, Set, and TypedArray.

For details about how to use the ArkTS containers, see [ArkTS Collections](../reference/apis-arkts/js-apis-arkts-collections.md).

For details about the behavior differences between ArkTS collections APIs and native APIs, see [Behavior Differences](arkts-collections-vs-native-api-comparison.md).

## Example

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
