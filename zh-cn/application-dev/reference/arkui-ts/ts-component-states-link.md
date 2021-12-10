# @Link<a name="ZH-CN_TOPIC_0000001110948894"></a>

**@Link**装饰的变量可以和父组件的**@State**变量建立双向数据绑定：

-   **支持多种类型：@Link**变量的值与**@State**变量的类型相同，即class、number、string、boolean或这些类型的数组；
-   **私有：**仅在组件内访问；
-   **单个数据源：**初始化**@Link**变量的父组件的变量必须是**@State**变量；
-   **双向通信：**子组件对**@Link**变量的更改将同步修改父组件的**@State**变量；
-   **创建自定义组件时需要将变量的引用传递给@Link变量：**在创建组件的新实例时，必须使用命名参数初始化所有**@Link**变量。**@Link**变量可以使用**@State**变量或**@Link**变量的引用进行初始化。**@State**变量可以通过'**$**'操作符创建引用。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>**@Link**变量不能在组件内部进行初始化。

## 简单类型示例<a name="section19793192619582"></a>

```
@Entry
@Component
struct Player {
    @State isPlaying: boolean = false
    build() {
        Column() {
            PlayButton({buttonPlaying: $isPlaying})
            Text(`Player is ${this.isPlaying? '':'not'} playing`)
        }
    }
}

@Component
struct PlayButton {
    @Link buttonPlaying: boolean
    build() {
        Column() {
            Button() {
                Image(this.buttonPlaying? 'play.png' : 'pause.png')
            }.onClick(() => {
                this.buttonPlaying = !this.buttonPlaying
            })
        }
    }
}
```

**@Link**语义是从'**$**'操作符引出，即**$isPlaying**是**this.isPlaying**内部状态的双向数据绑定。当您单击**PlayButton**时，PlayButton 的**Image**组件和**Text**组件将同时进行刷新。

## 复杂类型示例<a name="section2921131712010"></a>

```
@Entry
@Component
struct Parent {
    @State arr: number[] = [1, 2, 3]
    build() {
        Column() {
            Child({items: $arr})
            ForEach(this.arr,
                item => Text(`${item}`),
                item => item.toString())
        }
    }
}

@Component
struct Child {
    @Link items: number[]
    build() {
        Column() {
            Button() {
                Text('Button1: push')
            }.onClick(() => {
                this.items.push(100)
            })
            Button() {
                Text('Button2: replace whole item')
            }.onClick(() => {
                this.items = [100, 200, 300]
            })
        }
    }
}
```

在上面的示例中，点击**Button1**和**Button2**以更改父组件中显示的文本项目列表。

## @Link和@State、@Prop结合使用示例<a name="section17490315415"></a>

```
@Entry
@Component
struct ParentView {
    @State counter: number = 0
    build() {
        Column() {
            ChildA({counterVal: this.counter})  // pass by value
            ChildB({counterRef: $counter})      // $ creates a Reference that can be bound to counterRef
        }
    }
}

@Component
struct ChildA {
    @Prop counterVal: number
    build() {
        Button() {
            Text(`ChildA: (${this.counterVal}) + 1`)
        }.onClick(() => {this.counterVal+= 1})
    }
}

@Component
struct ChildB {
    @Link counterRef: number
    build() {
        Button() {
            Text(`ChildB: (${this.counterRef}) + 1`)
        }.onClick(() => {this.counterRef+= 1})
    }
}
```

上述示例中，ParentView包含ChildA和ChildB两个子组件，ParentView的状态变量**counter**分别初始化ChildA和ChildB：

-   ChildB使用**@Link**建立双向状态绑定。当**ChildB**修改**counterRef**状态变量值时，该更改将同步到**ParentView**和**ChildA**共享；
-   ChildA使用**@Prop**建立从**ParentView**到自身的单向状态绑定。当**ChildA**修改状态时，**ChildA**将重新渲染，但该更改不会传达给**ParentView**和**ChildB。**

