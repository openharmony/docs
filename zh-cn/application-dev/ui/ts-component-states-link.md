# @Link

@Link装饰的变量可以和父组件的@State变量建立双向数据绑定：


- 支持多种类型：@Link变量的值与@State变量的类型相同，即class、number、string、boolean或这些类型的数组；

- 私有：仅在组件内访问；

- 单个数据源：初始化@Link变量的父组件的变量必须是@State变量；

- 双向通信：子组件对@Link变量的更改将同步修改父组件的@State变量；

- 创建自定义组件时需要将变量的引用传递给@Link变量：在创建组件的新实例时，必须使用命名参数初始化所有@Link变量。@Link变量可以使用@State变量或@Link变量的引用进行初始化，@State变量可以通过'$'操作符创建引用。


> ![icon-note.gif](public_sys-resources/icon-note.gif) 说明：
> @Link变量不能在组件内部进行初始化。


## 简单类型示例

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

@Link语义是从'$'操作符引出，即$isPlaying是this.isPlaying内部状态的双向数据绑定。当您单击PlayButton时，PlayButton 的Image组件和Text组件将同时进行刷新。


## 复杂类型示例

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

在上面的示例中，点击Button1和Button2更改父组件中显示的文本项目列表。


## @Link、@State和@Prop结合使用示例

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

上述示例中，ParentView包含ChildA和ChildB两个子组件，ParentView的状态变量counter分别初始化ChildA和ChildB。

- ChildB使用@Link建立双向状态绑定。当ChildB修改counterRef状态变量值时，该更改将同步到ParentView和ChildA共享；

- ChildA使用@Prop建立从ParentView到自身的单向状态绑定。当ChildA修改状态时，ChildA将重新渲染，但该更改不会传达给ParentView和ChildB。
