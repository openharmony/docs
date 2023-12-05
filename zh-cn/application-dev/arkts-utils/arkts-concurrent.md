# \@Concurrent装饰器：校验并发函数

在使用[TaskPool](../reference/apis/js-apis-taskpool.md)时，执行的并发函数需要使用该装饰器修饰，否则无法通过相关校验。


> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。


## 装饰器说明
| \@Concurrent并发装饰器 | 说明                                                                                       |
| --------------------- | ------------------------------------------------------------------------------------------ |
| 装饰器参数             | 无。                                                                                       |
| 使用场景               | 仅支持在Stage模型的工程中使用。                                                              |
| 装饰的函数类型         | 允许标注async函数或普通函数。禁止标注generator、箭头函数、method。不支持类成员函数或者匿名函数。  |
| 装饰的函数内的变量类型  | 允许使用local变量、入参和通过import引入的变量。禁止使用闭包变量。                               |


## 装饰器使用示例
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