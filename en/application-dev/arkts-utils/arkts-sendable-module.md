# Shared Module Development

A shared module, marked with **use shared**, is loaded only once in a process.

A non-shared module is loaded only once in the same thread and multiple times in different threads. New module objects are generated in all these threads.

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

    export { SingletonA }
    
    // Shared module. SingletonA is globally unique.
    @Sendable
    class SingletonA {
      private static instance: SingletonA = new SingletonA;
      private count_: number = 0;
      lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock()
    
      public static getInstance(): SingletonA {
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
    import taskpool from '@ohos.taskpool';
    import { SingletonA } from './sharedModule'
    
    let sig: SingletonA = SingletonA.getInstance();
    
    @Concurrent
    async function test2(sig: SingletonA) {
      console.info("sendable: taskpool count is:" + await sig.getCount());
      let n = Date.now();
      // Wait for 1000 us to simulate the actual service.
      while (Date.now() - n < 1000) {
    
      }
    }
    
    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World';
    
      build() {
        Row() {
          Column() {
            Button("MainThread")
              .onClick(async () => {
                // The main thread calls singletons sig.incrementCount() and fetchCount().
                sig.increaseCount();
                console.info("sendable: main thread count is:" + await sig.getCount());
              })
            Button("TaskpoolTest")
              .onClick(async () => {
                let task = new taskpool.Task(test2, sig);
                await taskpool.execute(task);
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```
