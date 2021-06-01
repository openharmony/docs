# How to Develop<a name="EN-US_TOPIC_0000001161817809"></a>

The Clock app displays the current time through a clock face and numbers.

As shown in  [Figure 1 Clock display effect](overview-7.md#fig7763172132019), the page consists of two parts:

-   Clock face area: displays a dynamic analog clock whose hands rotate accurately.
-   Digital time area: displays the current time in numerals.

To build such an app, we can create a page that has a flexible layout with two rows vertically arranged. The development procedure is as follows:

1.  Add a root  **<div\>**  to the  **.hml**  file. Note that each  **.hml**  file can contain only one root component. The example code is as follows:

    ```
    <div class="container">
    </div>
    ```

    **class="container"**  indicates the style used by the component. The  **container**  is a style class defined in the  **index.css**  file.

    ```
    .container {     
        flex-direction: column;
        justify-content: center;
        align-items: center;
        width: 100%;
        height: 100%;
    }
    ```

    The height and width of the root component  **<div\>**  are set in the style class. Note that the height and width must be explicitly specified \(except for some components, such as  **<text\>**\). Otherwise, the component may fail to display. In the  **container**  style class, the  **flex-direction**  attribute is set to  **column**, which means that child components of  **<div\>**  are vertically arranged from top to bottom for implementing the flexible page layout.

2.  Implement clock hand rotation using the  **<stack\>**  component. The  **<stack\>**  component provides a stack container where child components are successively stacked and the latter one overwrites the previous one.

    Add a stack container to the root component. The example code is as follows:

    ```
    <div class="container">    
        <stack class="stack">
            <image src="/common/clock_bg.png" class="clock-bg"></image> <!--Set the clock face image.-->
            <image src="/common/hour_hand.png" class="clock-hand"
                   style="transform : rotate({{ hour * 30 + minute / 2 }}deg);"></image> <!--Set the hour hand image. (hour * 30) indicates that the hour hand rotates 30 degrees every hour. (minute / 2) indicates the rotation degrees per minute.-->
            <image src="/common/minute_hand.png" class="clock-hand"
                   style="transform : rotate({{ minute * 6 + second / 10 }}deg);"></image> <!--Set the minute hand image. (minute * 6) indicates that the minute hand rotates 6 degrees every minute. (second / 10) indicates the rotation degrees per second.-->
            <image src="/common/second_hand.png" class="clock-hand"
                   style="transform : rotate({{ second * 6 }}deg);"></image> <!--Set the second hand image. (second * 6) indicates that the second hand rotates 6 degrees per second.-->
       </stack>
    </div>
    ```

    **style="transform: rotate\(\{\{ second \* 6 \}\}deg\)**  sets the rotation event of a component.  **transform**  translates, rotates, or scales an element.  **rotate**  rotates an element. You can set the element to rotate around its x-axis or y-axis.

    Set attributes, such as the height, width, and position, of the <stack\> component in the CSS file. The example code is as follows:

    ```
    .stack {
        flex-direction: column;
        justify-content: center;
        align-items: center;
        width: 100%;
        height: 50%;
    }
    ```

    Set attributes, such as the height and width, of the <clock-bg\> component in the CSS file. The example code is as follows:

    ```
    .clock-bg {
        width: 80%;
        height: 80%;
        object-fit: scale-down;
    }
    ```

    Set attributes, such as the height and width of the hour, minute, and second hands, of the <clock-hand\> component in the CSS file. The example code is as follows:

    ```
    .clock-hand {
        width: 25%;
        height: 65%;
        object-fit: contain;
    }
    ```

    Add a timer in the  **index.js**  file to update the hour, minute, and second variables in real time so that time can be automatically updated on the app UI. The example code is as follows:

    ```
    export default {
        timer: undefined,
        // Define parameters.
        data: {
          hour: 0,   // Define hours.
          minute: 0, // Define minutes.
          second: 0  // Define seconds.
        },
        onInit () {
            this.updateTime();
            this.timer = setInterval(this.updateTime, 1000)// Set the update time of the timer to 1 second.
        },  
        updateTime: function () {       
            var nowTime = new Date()    
            this.hour = nowTime.getHours()    
            this.minute = nowTime.getMinutes()   
            this.second = nowTime.getSeconds()    
            if (this.hour < 10) {        
                this.hour = '0' + this.hour    
            }  
            if (this.minute < 10) {       
                this.minute = '0' + this.minute   
            }    
            if (this.second < 10) {      
                this.second = '0' + this.second   
            }
        },
    }
    ```

3.  Display the current time in digital form under the analog clock. Add the  **<text\>**  component at the end of the root layout. The following example shows the page structure:

    ```
    <text class="digit-clock"> {{ hour }}:{{ minute }}:{{ second }}</text>
    ```

    **class="digit-clock"**  sets the height, width, and font size of the component. The example code is as follows:

    ```
    .digit-clock {    
        font-size: 58px;   
        width: 100%;
        margin-top: 0px;
        text-align: center;
    }
    ```

4.  Set the style, animation effect, and dynamic data binding for all components. The complete example code is as follows:

    -   **index.hml**

    ```
    <div class="container">
        <stack class="stack">
            <image src="/common/clock_bg.png" class="clock-bg"></image>
            <image src="/common/hour_hand.png" class="clock-hand"
                   style="transform : rotate({{ hour * 30 + minute / 2 }}deg);"></image>
            <image src="/common/minute_hand.png" class="clock-hand"
                   style="transform : rotate({{ minute * 6 + second / 10 }}deg);"></image>
            <image src="/common/second_hand.png" class="clock-hand"
                   style="transform : rotate({{ second * 6 }}deg);"></image>
        </stack>
        <text class="digit-clock">{{ hour }}:{{ minute }}:{{ second }}</text>
    </div>
    ```

    -   **index.css**

    ```
    .container {
        flex-direction: column;
        justify-content: center;
        align-items: center;
        width: 100%;
        height: 100%;
    }
    
    .stack {
        flex-direction: column;
        justify-content: center;
        align-items: center;
        width: 100%;
        height: 50%;
    }
    
    .digit-clock {
        font-size: 58px;
        width: 100%;
        margin-top: 0px;
        text-align: center;
    }
    
    .clock-bg {
        width: 80%;
        height: 80%;
        object-fit: scale-down;
    }
    
    .clock-hand {
        width: 25%;
        height: 65%;
        object-fit: contain;
    }
    ```

    -   **index.js**

    A  **.js**  file is used to implement interaction logic of your app. In the  **.js**  file of the page, implement the function of periodically obtaining the system time.

    ```
    export default {
        timer: undefined,
        data: {
            hour: 0,
            minute: 0,
            second: 0
        },
        onInit() {
            this.updateTime()
            this.timer = setInterval(this.updateTime, 1000)
        },
        updateTime: function () {
            var nowTime = new Date()
            this.hour = nowTime.getHours()
            this.minute = nowTime.getMinutes()
            this.second = nowTime.getSeconds()
            if (this.hour < 10) {
                this.hour = '0' + this.hour
            }
            if (this.minute < 10) {
                this.minute = '0' + this.minute
            }
            if (this.second < 10) {
                this.second = '0' + this.second
            }
        },
        onDestroy() {
            clearInterval(this.timer);
        }
    }
    ```


