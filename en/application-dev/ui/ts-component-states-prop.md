# @Prop

**@Prop** and **@State** have the same semantics but different initialization modes. A **@Prop** decorated variable in a component must be initialized using the **@State** decorated variable in its parent component. The **@Prop** decorated variable can be modified in the component, but the modification is not updated to the parent component; the modification to the **@State** decorated variable is synchronized to the **@Prop** decorated variable. That is, **@Prop** establishes one-way data binding.


The **@Prop** decorated state variable has the following features:


- Support for simple types: The number, string, and boolean types are supported.

- Private: Data is accessed only within the component.

- Support for multiple instances: A component can have multiple attributes decorated by **@Prop**.

- Support for initialization with a value passed to the **@Prop** decorated variable: When a new instance of the component is created, all **@Prop** decorated variables must be initialized. Initialization inside the component is not supported.


## Example


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
            // When creating a child component, you must provide the initial value of its @Prop decorated variable in the constructor parameter and initialize the regular variable CostOfOneAttump (not Prop).
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

In the preceding example, when the user presses **+1** or **-1**, the status of the parent component changes and the **build** method is executed again. In this case, a new **CountDownComponent** instance is created. The **countDownStartValue** attribute of the parent component is used to initialize the **@Prop** decorated variable of the child component. When the **Try again** button of the child component is touched, the value of the **@Prop** decorated variable **count** is changed. As a result, the **CountDownComponent** is rendered again. However, the change of the **count** value does not affect the **countDownStartValue** value of the parent component.

> **NOTE**
>
> When a new component instance is created, all its **@Prop** decorated variables must be initialized.
