# Shared Module Development

A shared module, marked with **use shared**, is loaded only once in a process.

A non-shared module is loaded only once in the same thread and multiple times in different threads. New module objects are generated in all these threads. Therefore, a shared module can be used to implement a singleton of a process.

## Specifications

A shared module complies with the following restrictions:

- Similar to **use strict**, **use shared** must be written at the top of the file after the **import** statement but before other statements.

  The shared attribute cannot be passed on. That is, importing a shared module does not make a non-shared module shared.

- A shared module supports only .ets files.

- **side-effects-import** is not allowed within a shared module.

  After a module is shared between threads, functions are lazy loaded to dependent non-shared modules. This type of import does not involve variable export and therefore is not loaded.
  
  ```ts
    // Not allowed
    import "./sharedModule"
  ```

- Variables exported by a shared module must be sendable objects.

  Objects exported by a shared module must be sendable. For details about the sendable objects, see [Sendable Development](arkts-sendable.md).

- Modules cannot be directly exported from a shared module.

  ```ts
  // test.ets
  export let num = 1;
  export let str = 'aaa';

  // Shared module
  'use shared'

  export * from './test'; // A compile-time error is reported. The module cannot be directly exported.
  export {num, str} from './test'; // Correct example. Export the object set.
  ```

- A shared module can reference a shared module or a non-shared module.

  The reference and reference scenarios of shared modules are not restricted.

## Example

1. Export the sendable object in a shared module.

    ```ts
    // Shared module sharedModule.ets
    import { ArkTSUtils } from '@kit.ArkTS';

    // Declare the current module as a shared module. Only sendable data can be exported.
    "use shared"

    // Shared module. SingletonA is globally unique.
    @Sendable
    export class SingletonA {
      private count_: number = 0;
      lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();
      private static instance: SingletonA = new SingletonA();
      static getInstance(): SingletonA {
        // Return a singleton object.
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

2. Operate the object exported from the shared module in multiple threads.

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
