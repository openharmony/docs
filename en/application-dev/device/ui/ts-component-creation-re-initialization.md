# Component Creation and Re-initialization


## Initial Creation and Rendering

1. Create the parent component ParentComp.

2. Locally initialize the state variable isCountDown of ParentComp.

3. Execute the build function of ParentComp.

4. Create a preset &lt;Column&gt; component.
   1. Create a preset &lt;Text&gt; component, set the text content to be displayed, and add the &lt;Text&gt; component instance to the &lt;Column&gt; component.
   2. Create the component on the true branch based on the if condition.
       1. Create a preset &lt;Image&gt; component and set the image source address.
       2. Create a TimerComponent using the given constructor.
           1. Create a TimerComponent object.
           2. Initialize the values of member variables locally.
           3. Use the parameters provided by the TimerComponent constructor to update the values of member variables.
           4. Execute the aboutToAppear function of TimerComponent.
           5. Execute the build function of TimerComponent to create the corresponding UI description structure.
   3. Create a preset &lt;Button&gt; component and set the corresponding content.


## Status Update

When a user clicks a button:

1. The value of the isCountDown state variable of ParentComp is changed to false.

2. The build function of ParentComp is executed.

3. The preset &lt;Column&gt; component is reused by the framework and reinitialized.

4. The child components of &lt;Column&gt; reuse and reinitialize the objects in the memory.
   1. Reuse the preset &lt;Text&gt; component after re-initializing the component using new text content.
   2. Reuse the component on the false branch based on the if condition.
       1. Destroy the components on the original true branch as these components are no longer used.
           1. Destroy the created preset &lt;image&gt; component instance.
           2. Destroy the TimerComponent component instance, and call the aboutToDisappear function.
       2. Create components on the false branch.
           1. Create a preset &lt;Image&gt; component and set the image source address.
           2. Create a TimerComponent again using the given constructor.
           3. Initialize the newly created TimerComponent and call the aboutToAppear and build functions.
   3. Reuse the preset &lt;Button&gt; component, with the new image source address.


## Example


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
                .onClick(() =&gt; {this.isCountDown = !this.isCountDown})
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
        this.timerId = setInterval(() =&gt; {this.counter += this.changePerSec}, 1000)
    }

    aboutToDisappear() {
        if (this.timerId &gt; 0) {
            clearTimeout(this.timerId)
            this.timerId = -1
        }
    }
}   
```
