# Custom Component Built-in APIs

Custom component built-in APIs are APIs predefined on the base class of custom components in the ArkUI framework. You can call these APIs on the instance of a custom component to obtain information, such as the UI context, about the instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## getUIContext

getUIContext(): UIContext

Obtains the **UIContext** instance.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                     | Description                   |
| --------------------------------------------------------- | ----------------------- |
| [UIContext](../js-apis-arkui-UIContext.md#uicontext) | **UIContext** instance obtained.|

**Example**

```ts
import { UIContext } from '@ohos.arkui.UIContext';

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    let uiContext: UIContext = this.getUIContext();
  }

  build() {
    // ...
  }
}
```

## queryNavDestinationInfo

queryNavDestinationInfo(): NavDestinationInfo | undefined;

Obtains the **NavDestinationInfo** instance.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                                      | Description     |
| -------------------------------------------------------------------------- | --------- |
| [NavDestinationInfo](../js-apis-arkui-observer.md#navdestinationinfo) \| undefined | **NavDestinationInfo** instance obtained.|

**Example**

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    let info: observer.NavDestinationInfo | undefined = this.queryNavDestinationInfo();
  }

  build() {
    // ...
  }
}
```
