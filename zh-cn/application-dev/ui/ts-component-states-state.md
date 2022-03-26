# @State

@State装饰的变量是组件内部的状态数据，当这些状态数据被修改时，将会调用所在组件的build方法进行UI刷新。

@State状态数据具有以下特征：


- 支持多种类型：允许class、number、boolean、string强类型的按值和按引用类型。允许这些强类型构成的数组，即Array&lt;class&gt;、Array&lt;string&gt;、Array&lt;boolean&gt;、Array&lt;number&gt;。不允许object和any。

- 支持多实例：组件不同实例的内部状态数据独立。

- 内部私有：标记为@State的属性是私有变量，只能在组件内访问。

- 需要本地初始化：必须为所有@State变量分配初始值，将变量保持未初始化可能导致框架行为未定义。

- 创建自定义组件时支持通过状态变量名设置初始值：在创建组件实例时，可以通过变量名显式指定@State状态属性的初始值。


## 简单类型的状态属性示例

```
@Entry
@Component
struct MyComponent {
    @State count: number = 0
    // MyComponent provides a method for modifying the @State status data member.
    private toggleClick() {
        this.count += 1
    }

    build() {
        Column() {
            Button() {
                Text(`click times: ${this.count}`)
                    .fontSize(10)
            }.onClick(this.toggleClick.bind(this))
        }
    }
}
```


## 复杂类型的状态变量示例

```
// Customize the status data class.
class Model {
    value: string
    constructor(value: string) {
        this.value = value
    }
}

@Entry
@Component
struct EntryComponent {
    build() {
        Column() {
            MyComponent({count: 1, increaseBy: 2})  // MyComponent1 in this document            MyComponent({title: {value: 'Hello, World 2'}, count: 7})   //MyComponent2 in this document
        }
    }
}

@Component
struct MyComponent {
    @State title: Model = {value: 'Hello World'}
    @State count: number = 0
    private toggle: string = 'Hello World'
    private increaseBy: number = 1

    build() {
        Column() {
            Text(`${this.title.value}`).fontSize(30)
            Button() {
                Text(`Click to change title`).fontSize(20).fontColor(Color.White)
            }.onClick(() => {
                this.title.value = (this.toggle == this.title.value) ? 'Hello World' : 'Hello UI'
            }) // Modify the internal state of MyComponent using the anonymous method.

            Button() {
                Text(`Click to increase count=${this.count}`).fontSize(20).fontColor(Color.White)
            }.onClick(() => {
                this.count += this.increaseBy
            }) // Modify the internal state of MyComponent using the anonymous method.
        }
    }
}
```


在上述示例中：


- 用户定义的组件MyComponent定义了@State状态变量count和title。如果count或title的值发生变化，则执行MyComponent的build方法来重新渲染组件；

- EntryComponent中有多个MyComponent组件实例，第一个MyComponent内部状态的更改不会影响第二个MyComponent；

- 创建MyComponent实例时通过变量名给组件内的变量进行初始化，如：
  ```
  MyComponent({title: {value: 'Hello, World 2'}, count: 7})
  ```
