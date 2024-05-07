# 共享模块开发指导

共享模块是进程内只会加载一次的模块，使用"use shared"这一指令来标记一个模块是否为共享模块。
非共享模块在同一线程内只加载一次，在不同线程间会加载多次，在不同的线程内都会产生新的模块对象。

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

1. 共享模块内导出sendable对象，同时导入非共享模块"./test.ets"的testStr对象。

    ```ts
    // 共享模块sharedModule.ets
    import {testStr} from "./test"
    "use shared"

    // 导出sendable对象
    export {SingletonA}

    @Sendable
    class SingletonA {
        private static instance: SingletonA;
        private count: number = 0;
        private str: string = testStr;
        private constructor() {
            console.log("taskpool 生成单例 SingletonA");
        }

        public static getInstance(): SingletonA {
            if (!SingletonA.instance) {
                console.log("!SingletonA.instance");
                SingletonA.instance = new SingletonA();
            }
            return SingletonA.instance;
        }

        public incrementCount(): number {
            return this.count++;
        }
    }
    ```

    ```ts
    // 非共享模块test.ets
    export let testStr = "Hello World";

    ```

2. 非共享模块导入共享模块，并在多个线程中操作共享模块导出的对象。

    ```ts

    import {taskpool} from "@kit.ArkTS";
    import {SingletonA} from "./sharedModule"

    @Sendable
    class A {
        num: number = 100;
        say() {
            console.log("this is say !");
        }
    }

    @Concurrent
    function test(b: A) {
        // 生成共享模块导出对象的单例
        const instance = SingletonA.getInstance();
        console.log('tastpool点击累加 count当前的值为: ', instance.incrementCount());
        b.say();
        let n = Date.now();
        // 等待1000us,模拟实际业务
        while (Date.now() - n < 1000) {

        }
    }

    @Entry
    @Component
    struct Index {
        @State message: string = "Hello world";
        build() {
            Row() {
                Column() {
                    Button("taskpool use es module").onClick(()=>{
                        let a: A = new A;
                        let task = new taskpool.Task(test, a);
                        for (let i = 0; i < 2; i++) {
                            taskpool.execute(task).then((res)=>{
                                console.log("execute task sucess !");
                            })
                        }
                    })
                .width('100%')
                }
            .height('100%')
            }
        }
    }

    ```
