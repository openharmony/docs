# @Prop

@Prop与@State有相同的语义，但初始化方式不同。@Prop装饰的变量必须使用其父组件提供的@State变量进行初始化，允许组件内部修改@Prop变量，但更改不会通知给父组件，父组件变量的更改会同步到@prop装饰的变量，即@Prop属于单向数据绑定。

@Prop状态数据具有以下特征：


- 支持简单类型：仅支持number、string、boolean简单类型；

- 私有：仅在组件内访问；

- 支持多个实例：一个组件中可以定义多个标有@Prop的属性；

- 创建自定义组件时将值传递给@Prop变量进行初始化：在创建组件的新实例时，必须初始化所有@Prop变量，不支持在组件内部进行初始化。


## 示例

```
@Entry
@Component
struct ParentComponent {
    @State countDownStartValue: number = 10 // 10 Nuggets default start value in a Game
    build() {
        Column() {
            Text(`Grant ${this.countDownStartValue} nuggets to play.`)
            Button() {
                Text('+1 - Nuggets in New Game')
            }.onClick(() => {
                this.countDownStartValue += 1
            })
            Button() {
                Text('-1  - Nuggets in New Game')
            }.onClick(() => {
                this.countDownStartValue -= 1
            })
            // 创建子组件时，必须在构造函数参数中提供其@Prop变量的初始值，同时初始化常规变量CostOfOneAttump（非Prop）
            CountDownComponent({ count: this.countDownStartValue, costOfOneAttempt: 2})
        }
    }
}

@Component
struct CountDownComponent {
    @Prop count: number
    private costOfOneAttempt: number

    build() {
        Column() {
            if (this.count > 0) {
                Text(`You have ${this.count} Nuggets left`)
            } else {
                Text('Game over!')
            }

            Button() {
                Text('Try again')
            }.onClick(() => {
                this.count -= this.costOfOneAttempt
            })
        }
    }
}
```

在上述示例中，当按“+1”或“-1”按钮时，父组件状态发生变化，重新执行build方法，此时将创建一个新的CountDownComponent组件。父组件的countDownStartValue状态属性被用于初始化子组件的@Prop变量，当按下子组件的“Try again”按钮时，其@Prop变量count将被更改，CountDownComponent重新渲染。但是count值的更改不会影响父组件的countDownStartValue值。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：** 
> 创建新组件实例时，必须初始化其所有@Prop变量。
