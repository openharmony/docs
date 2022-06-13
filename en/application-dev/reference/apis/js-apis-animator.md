# Animation

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

**requestAnimationFrame**: none

**cancelAnimationFrame**: none

**createAnimator**:

```
import animator from '@ohos.animator';
```

## Required Permissions

None

## requestAnimationFrame

requestAnimationFrame\(handler\[, \[ ...args\]\]\): number

Requests an animation frame.

- Parameters

  | Name    | Type        | Mandatory | Description                                                  |
  | ------- | ----------- | --------- | ------------------------------------------------------------ |
  | handler | Function    | Yes       | Handler used to request a frame. When **requestAnimationFrame** calls the **handler**, the timestamp is passed to the first parameter to indicate the time when **requestAnimationFrame** starts to execute the callback. |
  | ...args | Array\<any> | No        | Additional parameter, which is passed to the **handler** as a parameter during function callback. |

-   Return values

    | Type   | Description |
    | ------ | ----------- |
    | number | Request ID. |
    
-   Example

    ```
    <!-- xxx.hml -->
    <div class="container">
      <button type="capsule" class="btn" onclick="beginAnimation">beginAnimation</button>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 100%;
      height: 100%;
    }
    .btn{
      width: 300px;
      margin-top: 40px;
    }
    ```

    ```
    /* xxx.js */
    export default {
      data: {
        requestId: 0,
        startTime: 0,
      },
      beginAnimation() {
        cancelAnimationFrame(this.requestId);
        this.requestId = requestAnimationFrame(this.runAnimation);
      },
      runAnimation(timestamp) {
        if (this.startTime == 0) {
          this.startTime = timestamp;
        }
        var elapsed = timestamp - this.startTime;
        if (elapsed < 500) {
          console.log('callback handler timestamp: ' + timestamp);
          this.requestId = requestAnimationFrame(this.runAnimation);
        }
      }
    }
    ```


## cancelAnimationFrame

cancelAnimationFrame\(requestId: number\): void

Cancels the animation frame request.

-   Parameters

   | Name      | Type   | Mandatory | Description              |
| --------- | ------ | --------- | ------------------------ |
   | requestId | number | Yes       | ID of the frame request. |
   
-   Example

    ```
    <!-- xxx.hml -->
    <div class="container">
      <button type="capsule" class="btn" onclick="beginAnimation">beginAnimation</button>
      <button type="capsule" class="btn" onclick="beginAnimation">stopAnimation</button>
    </div>
    ```

    ```
    /* xxx.css */
    .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
      width: 100%;
      height: 100%;
    }
    .btn{
      width: 300px;
      margin-top: 40px;
    }
    ```

    ```
    /* xxx.js */
    export default {
      data: {
        requestId: 0,
        startTime: 0,
      },
      beginAnimation() {
        cancelAnimationFrame(this.requestId);
        this.requestId = requestAnimationFrame(this.runAnimation);
      },
      runAnimation(timestamp) {
        if (this.startTime == 0) {
          this.startTime = timestamp;
        }
        var elapsed = timestamp - this.startTime;
        if (elapsed < 500) {
          console.log('callback handler timestamp: ' + timestamp);
          this.requestId = requestAnimationFrame(this.runAnimation);
        }
      },
      stopAnimation() {
        cancelAnimationFrame(this.requestId);
      }
    }
    ```


## createAnimator

createAnimator\(options\[...\]\): void

Creates an animation object.

- Parameters

  | Name    | Type   | Mandatory | Description                                                  |
  | ------- | ------ | --------- | ------------------------------------------------------------ |
  | options | Object | Yes       | Attributes of the **Animator** to be created. For details, see the options table. |

- Description of options

  | Name       | Type   | Mandatory | Description                                                  |
  | ---------- | ------ | --------- | ------------------------------------------------------------ |
  | duration   | number | No        | Duration for playing an animation, in milliseconds. The default value is **0**. |
  | easing     | string | No        | Animation easing curve. The default value is **ease**.       |
  | delay      | number | No        | Animation delay duration, in milliseconds. The default value is **0**, indicating that there is no delay. |
  | fill       | string | No        | Animation start/stop mode. The default value is **none**.    |
  | direction  | string | No        | Animation playback mode. The default value is **normal**.    |
  | iterations | number | No        | Number of times that an animation is played. The default value is **1**. If this parameter is set to **0**, the animation is not played. If this parameter is set to **-1**, the animation is played for an unlimited number of times. |
  | begin      | number | No        | Start point of the animation easing. If this parameter is not set, the default value **0** is used. |
  | end        | number | No        | End point of the animation easing. If this parameter is not set, the default value **1** is used. |

-   animator interfaces

    | Name    | Type    | Description                                                  |
    | ------- | ------- | ------------------------------------------------------------ |
    | update  | options | Updates the animation parameters. The input parameters are the same as those of **createAnimator**. |
    | play    | -       | Starts an animation.                                         |
    | finish  | -       | Ends an animation.                                           |
    | pause   | -       | Pauses an animation.                                         |
    | cancel  | -       | Cancels an animation.                                        |
    | reverse | -       | Reverses an animation.                                       |


-   **animator**  supported events:

    | Name   | Type   | Description                         |
    | ------ | ------ | ----------------------------------- |
    | frame  | number | The frame is requested.             |
    | cancel | -      | The animation is forcibly canceled. |
    | finish | -      | The animation playback is complete. |
    | repeat | -      | The animation replays.              |
    
-   Example

    ```
    <!-- hml -->
    <div class="container">
      <div class="Animation" style="height: {{divHeight}}px; width: {{divWidth}}px; background-color: red;" onclick="Show">
      </div>
    </div>
    ```

    ```
    // js
    export default {
      data : {
        divWidth: 200,
        divHeight: 200,
        animator: null
      },
      onInit() {
        var options = {
          duration: 1500,
          easing: 'friction',
          fill: 'forwards',
          iterations: 2,
          begin: 200.0,
          end: 400.0
        };
        this.animator = animator.createAnimator(options);
      },
      Show() {
        var options1 = {
          duration: 2000,
          easing: 'friction',
          fill: 'forwards',
          iterations: 1,
          begin: 200.0,
          end: 400.0
        };
        this.animator.update(options1);
        var _this = this;
        this.animator.onframe = function(value) {
          _this.divWidth = value;
          _this.divHeight = value;
        };
        this.animator.play();
      }
    }
    ```