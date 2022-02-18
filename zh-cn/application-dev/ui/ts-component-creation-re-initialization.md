# 组件创建和重新初始化

## 初始创建和渲染

1. 创建父组件**ParentComp**；

2. 本地初始化**ParentComp**的状态变量**isCountDown**；

3. 执行**ParentComp**的**build**函数；

4. 创建**Column**内置组件；
   1. 创建**Text**内置组件，设置其文本展示内容，并将**Text**组件实例添加到**Column**中；
   2. 判断if条件，创建**true**分支上的组件；
       1. 创建**Image**内置组件，并设置其图片源地址；
       2. 使用给定的构造函数创建**TimerComponent**；
           1. 创建**TimerComponent**对象；
           2. 本地初始化成员变量初始值；
           3. 使用**TimerComponent**构造函数提供的参数更新成员变量的值；
           4. 执行**TimerComponent**的**aboutToAppear**函数；
           5. 执行**TimerComponent**的**build**函数，创建相应的UI描述结构；
   3. 创建**Button**内置组件，设置相应的内容。


## 状态更新

用户单击按钮时：

1. **ParentComp**的**isCountDown**状态变量的值更改为false；

2. 执行**ParentComp**的**build**函数；

3. **Column**内置组件会被框架重用并执行重新初始化；

4. **Column**的子组件会重用内存中的对象，但会进行重新初始化；
   1. **Text**内置组件会被重用，但使用新的文本内容进行重新初始化；
   2. 判断if条件，使用false分支上的组件；
       1. 原来true分支上的组件不在使用，这些组件会进行销毁；
           1. 创建的**Image**内置组件实例进行销毁；
           2. **TimerComponent**组件实例进行销毁，**aboutToDisappear**函数被调用；
       2. 创建false分支上的组件；
           1. 创建**Image**内置组件，并设置其图片源地址；
           2. 使用给定的构造函数重新创建**TimerComponent**；
           3. 新创建的**TimerComponent**进行初始化，并调用**aboutToAppear**函数和**build**函数。
   3. **Button**内置组件会被重用，但使用新的图片源地址。


## 示例

```
@Entry
@Component
struct ParentComp {
    @State isCountDown: boolean = true
    build() {
        Column() {
            Text(this.isCountDown ? 'Count Down' : 'Stopwatch')
            if (this.isCountDown) {
                Image('countdown.png')
                TimerComponent({counter: 10, changePerSec: -1, showInColor: Color.Red})
            } else {
                Image('stopwatch.png')
                TimerComponent({counter: 0, changePerSec: +1, showInColor: Color.Black })
            }
            Button(this.isCountDown ? 'Swtich to Stopwatch' : 'Switch to Count Down')
                .onClick(() => {this.isCountDown = !this.isCountDown})
        }
    }
}

// Manage and display a count down / stop watch timer
@Component
struct TimerComponent {
    @State counter: number = 0
    private changePerSec: number = -1
    private showInColor: Color = Color.Black
    private timerId : number = -1

    build() {
        Text(`${this.counter}sec`)
            .fontColor(this.showInColor)
    }

    aboutToAppear() {
        this.timerId = setInterval(() => {this.counter += this.changePerSec}, 1000)
    }

    aboutToDisappear() {
        if (this.timerId > 0) {
            clearTimeout(this.timerId)
            this.timerId = -1
        }
    }
}   
```
