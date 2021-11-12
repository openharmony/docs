# @Prop<a name="EN-US_TOPIC_0000001157388853"></a>

**@Prop**  and  **@State**  have the same semantics but different initialization modes. Variables decorated by  **@Prop**  must be initialized using the  **@State**  annotated variable provided by their parent components. The  **@Prop**  annotated variable can be modified in the component, but the modification is not notified to the parent component. That is,  **@Prop**  is unidirectional data binding.

The  **@Prop**  data has the following features:

-   **Support for simple types**: Only the following simple types are supported: number, string, and boolean.
-   **Private**: Data is accessed only within the component.
-   **Support for multiple instances**: A component can have multiple attributes decorated by  **@Prop**.
-   **Requiring a value for the @Prop annotated variable for initialization**: When a new instance of the component is created, all  **@Prop**  annotated variables must be initialized. Initialization inside the component is not supported.

## Example<a name="section599175705019"></a>

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

            // when creatng ChildComponent, the initial value of its @Prop variable must be supplied
            // in a named constructor parameter
            // also regular costOfOneAttempt (non-Prop) variable is initialied
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

In the preceding example, when you press  **+1**  or  **-1**, the status of the parent component changes and the  **build**  method is executed again. In this case, a new  **CountDownComponent**  is created. The  **countDownStartValue**  property of the parent component is used to initialize the  **@Prop**  annotated variable of the child component. When you click the  **Try again**  button of the child component, the value of the  **@Prop**  annotated  **count**variable is changed. As a result, the  **CountDownComponent**  is rendered again. However, changes to the  **count**  value do not affect the  **countDownStartValue**  value of the parent component.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>When a new component instance is created, all its  **@Prop**  annotated variables must be initialized.

