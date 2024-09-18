# 共享模块开发指导

共享模块是进程内只会加载一次的模块，使用"use shared"这一指令来标记一个模块是否为共享模块。
非共享模块在同一线程内只加载一次，在不同线程间会加载多次，在不同的线程内都会产生新的模块对象。因此可以使用共享模块来实现进程单例。

## 使用规格

共享模块遵循以下约束：

- "use shared"需要与"use strict"一样写在文件顶层，写在import语句之后其他语句之前。

  共享属性不存在传递性，即非共享模块A不会引入了共享模块B而使A变成共享。

- 共享模块只支持ets文件。

- 共享模块内不允许使用side-effects-import。

  共享模块可在线程间共享，共享后函数对依赖的非共享模块会懒加载，这种类型的import不涉及导出变量，所以不会被加载。
  
  ```ts
    //不允许使用
    import "./sharedModule"
  ```

- 共享模块导出的变量必须都是可共享对象。

  共享模块在线程间可共享，则模块导出的对象都要是可共享的，可共享对象参考[Sendable规格](arkts-sendable.md)。

- 共享模块中不允许直接导出模块。

  ```ts
  // test.ets
  export let num = 1;
  export let str = 'aaa';

  // 共享模块
  'use shared'

  export * from './test'; // 编译报错，不允许直接导出模块
  export {num, str} from './test'; // 正确示例，导出对象合集
  ```

- 共享模块可以引用共享模块或非共享模块。

  不限制共享模块的引用和被引用场景。

## 使用示例

1. 共享模块内导出sendable对象。

    ```ts
    // 共享模块sharedModule.ets
    import { ArkTSUtils } from '@kit.ArkTS';

    // 声明当前模块为共享模块，只能导出可Sendable数据
    "use shared"

    // 共享模块，SingletonA全局唯一
    @Sendable
    export class SingletonA {
      private count_: number = 0;
      lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();
      private static instance: SingletonA = new SingletonA();
      static getInstance(): SingletonA {
        // 返回单例对象
        return SingletonA.instance;
      }

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
    }
    ```

2. 在多个线程中操作共享模块导出的对象。

    ```ts
    import { ArkTSUtils, taskpool } from '@kit.ArkTS';
    import { SingletonA } from './sharedModule'

    @Concurrent
    async function increaseCount() {
      await SingletonA.getInstance().increaseCount();
      console.info("SharedModule: count is:" + await SingletonA.getInstance().getCount());
    }

    @Concurrent
    async function printCount() {
      console.info("SharedModule: count is:" + await SingletonA.getInstance().getCount());
    }

    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World';

      build() {
        Row() {
          Column() {
            Button("MainThread print count")
              .onClick(async () => {
                console.info("this is MainThread print count");
                await printCount();
              })
            Button("Taskpool print count")
              .onClick(async () => {
                console.info("this is Taskpool print count");
                await taskpool.execute(printCount);
              })
            Button("MainThread increase count")
              .onClick(async () => {
                console.info("this is MainThread increase count");
                await increaseCount();
              })
            Button("Taskpool increase count")
              .onClick(async () => {
                console.info("this is Taskpool increase count");
                await taskpool.execute(increaseCount);
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```
