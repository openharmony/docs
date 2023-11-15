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
| Decorated function types        | This decorator can be used for asynchronous functions or common functions. It cannot be used for generators, arrow functions, or methods. It does not support class member functions or anonymous functions. |
| Variable types in decorated functions | Local variables, input parameters, and variables imported through **import** are supported. Closure variables are not allowed.                              |


## Example
  ```ts
  import taskpool from '@ohos.taskpool';

  async function concurrentFunc() {
    @Concurrent
    function printLog(): void {
      console.log("This is printLog");
    }

    let task: taskpool.Task = new taskpool.Task(printLog);
    await taskpool.execute(task);
  }

  concurrentFunc();
  ```
