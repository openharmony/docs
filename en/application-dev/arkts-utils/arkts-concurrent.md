# \@Concurrent Decorator: Verifying Concurrent Functions

To pass function verification, the concurrent functions executed in a [TaskPool](../reference/apis/js-apis-taskpool.md) must be decorated using \@Concurrent.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.


## Decorator Description
| \@Concurrent Decorator| Description                                                                                      |
| --------------------- | ------------------------------------------------------------------------------------------ |
| Decorator parameters            | None.                                                                                      |
| Application scenarios              | This decorator can be used only in projects of the stage model.                                                             |
| Decorated function types        | This decorator can be used for asynchronous functions and common functions. It cannot be used for generators, arrow functions, or methods. It does not support class member functions or anonymous functions. |
| Variable types in decorated functions | Local variables, input parameters, and variables imported through **import** are supported. Closure variables are not allowed.                              |


## Example
  ```ts
  import taskpool from '@ohos.taskpool';
  
  @Concurrent
  function add(num1: number, num2: number): number {
    return num1 + num2;
  }
  
  async function ConcurrentFunc(): Promise<void> {
    try {
      let task: taskpool.Task = new taskpool.Task(add, 1, 2);
      console.info("taskpool res is: " + await taskpool.execute(task));
    } catch (e) {
      console.error("taskpool execute error is: " + e);
    }
  }
  
  @Entry
  @Component
  struct Index {
    @State message: string = 'Hello World'
  
    build() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              ConcurrentFunc();
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```
