# 自定义组件成员变量初始化

组件的成员变量可以通过两种方式初始化：


- 本地初始化，例如：
  ```ts
  @State counter: Counter = new Counter()
  ```

- 在构造组件时通过构造参数初始化，例如：
  ```ts
  MyComponent({counter: $myCounter})
  ```


具体允许哪种方式取决于[状态变量](../quick-start/arkts-state-mgmt-concepts.md)的装饰器：


| 装饰器类型        | 本地初始化 | 通过构造函数参数初始化 |
| ------------ | ----- | ----------- |
| @State       | 必须    | 可选          |
| @Prop        | 禁止    | 必须          |
| @Link        | 禁止    | 必须          |
| @StorageLink | 必须    | 禁止          |
| @StorageProp | 必须    | 禁止          |
| @Provide     | 必须    | 可选          |
| @Consume     | 禁止    | 禁止          |
| @ObjectLink  | 禁止    | 必须          |
| 常规成员变量       | 推荐    | 可选          |


从上表中可以看出：


- @State变量需要本地初始化，初始化的值可以被构造参数覆盖；

- @Prop和@Link变量必须且仅通过构造函数参数进行初始化。


通过构造函数方法初始化成员变量，需要遵循如下规则：


| 从父组件中的变量（下）到子组件中的变量（右） | @State | @Link | @Prop | 常规变量 |
| ---------------------- | ------ | ----- | ----- | ---- |
| @State                 | 不允许    | 允许    | 允许    | 允许   |
| @Link                  | 不允许    | 允许    | 不推荐   | 允许   |
| @Prop                  | 不允许    | 不允许   | 允许    | 允许   |
| @StorageLink           | 不允许    | 允许    | 不允许   | 允许   |
| @StorageProp           | 不允许    | 不允许   | 不允许   | 允许   |
| 常规变量                   | 允许     | 不允许   | 不允许   | 允许   |


从上表中可以看出：


- 父组件的常规变量可以用于初始化子组件的@State变量，但不能用于初始化@Link或@Prop变量。

- 父组件的@State变量可以初始化子组件的@Prop、@Link（通过$）或常规变量，但不能初始化子组件的@State变量。

- 父组件的@Link变量可以初始化子组件的@Link或常规变量。但是初始化子组件的@State成员是语法错误，此外不建议初始化@prop。

- 父组件的@Prop变量可以初始化子组件的常规变量或@Prop变量，但不能初始化子组件的@State或@Link变量。

- @StorageLink和@StorageProp不允许由父组件中传递到子组件。

- 除了上述规则外，还需要遵循TS的强类型规则。


## 示例

```ts
// xxx.ets
class ClassA {
  public a:number
  constructor(a: number) {
    this.a = a
  }
}
@Entry
@Component
struct Parent {
  @State parentState: ClassA = new ClassA(1)
  
  build() {
    Column() {
      Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
        CompA({ aState: new ClassA(2), aLink: $parentState })
      }
      Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
        CompA({ aLink: $parentState })
      }
      Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
        CompA({ aState: new ClassA(3), aLink: $parentState })
      }
    }
  }
}

@Component
struct CompA {
  @State aState: any = false
  @Link aLink: ClassA
  
  build() {
    Column() {
      CompB({ bLink: $aLink, bProp: this.aState })
      CompB({ bLink: $aState, bProp: false })
    }
  }
}

@Component
struct CompB {
  @Link bLink: ClassA
  @Prop bProp: boolean
  
  build() {
    Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
      Text(JSON.stringify(this.bLink.a)).fontSize(30)
      Text(JSON.stringify(this.bProp)).fontSize(30).fontColor(Color.Red)
     }.margin(10)
  }
}
```
