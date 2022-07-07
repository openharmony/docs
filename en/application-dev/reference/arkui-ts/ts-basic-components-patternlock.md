# PatternLock

The **\<PatternLock>** component allows users to use a pattern password for authentication. It enters the input state once being touched, and exits the input state and sends the entered password to the application once the finger leaves the screen.

> **NOTE**
> 
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None

## Child Components

Not supported

##  APIs

PatternLock(controller?: PatternLockController)

- Parameters

  | Name | Type | Mandatory | Default Value | Description |
  | ---- | ---- | ---- | ------ | ----------------------- |
  | controller | [PatternLockController](#patternlockcontroller) | No  | null | Controller of a component to reset the component status. |

## Attributes

Except for **backgroundColor**, universal attributes are not supported.

| Name | Type | Default Value | Description |
| ---- | ---- | ------------- | ----------- |
| sideLength | Length | 300vp | Width and height (same value) of the component. The minimum value is **0**. |
| circleRadius | Length | 14vp | Radius of a grid dot. |
| regularColor | [ResourceColor](../../ui/ts-types.md) | Color.Black | Fill color of the grid dot in unselected state. |
| selectedColor | [ResourceColor](../../ui/ts-types.md) | Color.Black | Fill color of the grid dot in selected state. |
| activeColor | [ResourceColor](../../ui/ts-types.md) | Color.Black | Fill color of the grid dot in active state. |
| pathColor | [ResourceColor](../../ui/ts-types.md) | Color.Blue  | Path color. |
| pathStrokeWidth | Length | 34vp | Width of the path stroke. The minimum value is **0**. |
| autoReset| boolean | true | Whether to allow the user to reset the component status (that is, clear the input) by touching the component again after the input is complete. The value **true** means that the user can reset the component status by touching the component again after the input is complete, and **false** means the opposite. |

## Events

| Name | Description |
| ---- | ----------- |
| onPatternComplete(callback: (input: Array\<number\>) => void) | Invoked when the pattern password input is complete.<br>**input** is an array of digits that represent the connected dots in the pattern (0 to 8) and are arranged in the same sequence as the dots are connected. |

## PatternLockController

Controller bound to the **\<PatternLock>** component for resetting the component status.

### Objects to Import

```typescript
patternLockController: PatternLockController = new PatternLockController()
```

### reset

reset(): void

Resets the component status.

##  Example

```ts
// xxx.ets
@Entry
@Component
struct PatternLockExample {
  @State passwords: Number[] = []
  @State message: string = 'please input password'
  private patternLockController: PatternLockController = new PatternLockController()
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(this.message).textAlign(TextAlign.Center)
      PatternLock(this.patternLockController)
        .sideLength(150)
        .circleRadius(7)
        .pathStrokeWidth(17)
        .backgroundColor(Color.White)
        .autoReset(true)
        .onPatternComplete((input: Array<number>) => {
          if (input == null || input == undefined || input.length < 5) {
            this.message = 'The password length needs to be greater than 5.'
            return
          }
          if (this.passwords.length > 0) {
            if (this.passwords.toString() == input.toString()) {
              this.passwords = input
              this.message = 'Set password successfully: ' + this.passwords.toString()
            } else {
              this.message = 'Inconsistent passwords, please enter again.'
            }
          } else {
            this.passwords = input
            this.message = "Please enter again."
          }
        })
      Button('reset button').margin(30).onClick(() => {
        this.patternLockController.reset()
        this.passwords = []
        this.message = 'Please input password'
      })
    }.width('100%').height('100%')
  }
}
```

![patternlock](figures/patternlock.gif)
