# 生成器函数内使用TS语言的限制



TS语言的使用在生成器函数中存在一定的限制：


- 表达式仅允许在字符串(${expression})、if条件、ForEach的参数和组件的参数中使用；

- 这些表达式中的任何一个都不能导致任何应用程序状态变量（@State、@Link、@Prop）的改变，否则会导致未定义和潜在不稳定的框架行为；

- 允许在生成器函数体的第一行使用console.log，以便开发人员更容易跟进组件重新渲染。对日志字符串文字中表达式仍遵循上述限制。

- 生成器函数内部不能有局部变量。


上述限制都不适用于事件处理函数（例如**onClick**）的匿名函数实现，它们也不适用于UI组件描述外的其余部分。


非法示例：


```
build() {
    let a: number = 1 // invalid: variable declaration not allowed
    console.log(`a: ${a}`) // invalid: console.log only allowed in first line of build
    Column() {
        Text('Hello ${this.myName.toUpperCase()}') // ok.
        ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array varible in place
    }
    buildSpecial()  // invalid: no function calls
    Text(this.calcTextValue()) // this function call is ok.
}
```
