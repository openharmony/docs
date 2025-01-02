# SwipeRefresher


The swipe refresher is a component used to obtain and load content, typically with a pull-down gesture.

> **NOTE**
>
> This component and its child components are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { SwipeRefresher } from '@kit.ArkUI'
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are supported.


## SwipeRefresher

SwipeRefresher ({content?: string, isLoading: boolean})

**Decorator**: \@Component

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| content | string | No| \@Prop | Text displayed when the content is loaded.|
| isLoading | boolean | If yes, | \@Prop | Whether content is being loaded.<br> The value **true** means that content is being loaded, and **false** means the opposite.|

## Events
The [universal events](ts-universal-events-click.md) are supported.

## Example
This example demonstrates how setting the **content** parameter to empty or non-empty strings and toggling the **isLoading** parameter between **true** and **false** affects the loading effect.
```ts
import { SwipeRefresher } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      SwipeRefresher({
        content: 'Loading',
        isLoading: true
      })
      SwipeRefresher({
        content: '',
        isLoading: true
      })
      SwipeRefresher({
        content: 'Loading',
        isLoading: false
      })
    }
  }
}
```

![Snipaste_2023-07-24_11-35-40](figures/Snipaste_2023-07-24_11-35-40.gif)
