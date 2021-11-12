# Example: Component Creation and Re-Initialization<a name="EN-US_TOPIC_0000001110788992"></a>

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

## Initial Creation and Rendering<a name="section136047306160"></a>

1.  Create the parent component  **ParentComp**.
2.  Locally initialize the state variable  **isCountDown**  of  **ParentComp**.
3.  Execute the  **build**  function of  **ParentComp**.
4.  Create a preset  **<Column\>**  component.
    1.  Create a preset  **<Text\>**  component, set the text content to be displayed, and add the  **<Text\>**  component instance to the  **<Column\>**  component.
    2.  The component on the  **true**  branch is created based on the  **if**  condition.
        1.  Create a preset  **<Image\>**  component and set the image source address.
        2.  Creates a  **TimerComponent**  using the given constructor.
            1.  Create a  **TimerComponent**  object.
            2.  Initialize the values of member variables locally.
            3.  Use the parameters provided by the  **TimerComponent**  constructor to update the values of member variables.
            4.  Execute the  **aboutToAppear**  function of  **TimerComponent**.
            5.  Execute the  **build**  function of  **TimerComponent**  to create the corresponding UI description structure.

    3.  Create a preset  **<Button\>**  component and set the corresponding content.


## Status Update<a name="section157507235171"></a>

When a user clicks a button:

1.  The value of the  **isCountDown**  state variable of  **ParentComp**  is changed to  **false**.
2.  The  **build**  function of  **ParentComp**  is executed.
3.  The preset  **<Column\>**  component is reused by the framework and reinitialized.
4.  The child components of  **<Column\>**  reuse and reinitialize the objects in the memory.
    1.  The preset  **<Text\>**  component is reused, but the new text content will be used for re-initialization.
    2.  The component on the  **false**  branch is created based on the  **if**  condition.
        1.  The components on the original  **true**  branch are not used and will be destroyed.
            1.  Destroy the created preset  **<image\>**  component instance.
            2.  The  **TimerComponent**  component instance is destroyed, and the  **aboutToDisappear**  function is called.

        2.  Create components on the  **false**  branch.
            1.  Create a preset  **<Image\>**  component and set the image source address.
            2.  Create a  **TimerComponent**  again using the given constructor.
            3.  Initialize the newly created  **TimerComponent**  and call the  **aboutToAppear**  and  **build**  functions.

    3.  The preset  **<Button\>**  component will be reused, with the new image source address.


