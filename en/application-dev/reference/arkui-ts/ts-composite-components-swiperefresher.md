# @ohos.arkui.advanced.SwipeRefresher (Swipe Refresher)


The swipe refresher is a component used to obtain and load content, typically with a pull-down gesture.



> **NOTE**
>
> This component and its child components are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { SwipeRefresher } from '@ohos.arkui.advanced.SwipeRefresher'
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are supported.


## SwipeRefresher

SwipeRefresher ({content: string, isLoading: boolean})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Decorator| Description| 
| -------- | -------- | -------- | -------- | -------- |
| content | string | No| \@Prop | Text displayed when the content is loaded.| 
| isLoading | boolean | If yes, | \@Prop | Whether content is being loaded.| 

## Events
The [universal events](ts-universal-events-click.md) are supported.

## Example
```ts
import { SwipeRefresher } from '@ohos.arkui.advanced.SwipeRefresher';

@Entry
@Component
struct Index {
  build() {
    Column() {
      SwipeRefresher({
        content: 'Loading',
        isLoading: true })
      SwipeRefresher({
        isLoading: true })
      SwipeRefresher({
        content: 'Loading',
        isLoading: false })
    }
  }
}
```

![Snipaste_2023-07-24_11-35-40](figures/Snipaste_2023-07-24_11-35-40.gif)
