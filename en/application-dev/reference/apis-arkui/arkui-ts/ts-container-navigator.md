# Navigator

The **Navigator** component provides redirection.

> **NOTE**
>
> This component is no longer maintained since API version 13. You are advised to use the [Navigation](ts-basic-components-navigation.md) component for page routing.
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported


## APIs

Navigator(value?: {target: string, type?: NavigationType})

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type      | Mandatory| Description                                      |
| ------ | -------------- | ---- | ---------------------------------------------- |
| target | string         | Yes  | Path of the target page to be redirected to.    |
| type   | [NavigationType](#navigationtype) | No  | Navigation type.<br>Default value: **NavigationType.Push**|

## NavigationType

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Value | Description                        |
| ------- | ------- | -------------------------- |
| Push    | 1 | Navigates to the specified page in the application.              |
| Replace | 2 | Replaces the current page with another one in the application and destroys the current page.|
| Back    | 3 | Returns to the specified page. If the specified page does not exist in the stack, no response is returned. If no page is specified, the previous page is returned to.|

## Attributes

### active

active(value: boolean)

Sets whether the **Navigator** component is activated. If the component is activated, the corresponding navigation takes effect.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                      |
| ------ | ------- | ---- | -------------------------- |
| value  | boolean | Yes  | Whether the **Navigator** component is activated.|

### params

params(value: object)

Sets the data that needs to be passed to the target page during redirection.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | object | Yes  | Data that needs to be passed to the target page during redirection. You can use [router.getParams()](../js-apis-router.md#routergetparams) to obtain the data on the target page.|

### target

target(value: string)

Path of the target page to be redirected to. The target page must be added to the **main_pages.json** file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| value  | string | Yes  | Path of the target page to be redirected to.|

### type
type(value: NavigationType)

Sets the navigation type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                          |
| ------ | ------ | ---- | ---------------------------------------------- |
| value  | [NavigationType](#navigationtype) | Yes  | Navigation type.<br>Default value: **NavigationType.Push**|


## Example

```ts
// Navigator.ets
@Entry
@Component
struct NavigatorExample {
  @State active: boolean = false
  @State name: NameObject = { name: 'news' }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Detail', type: NavigationType.Push }) {
        Text('Go to ' + this.name.name + ' page')
          .width('100%').textAlign(TextAlign.Center)
      }.params(new TextObject(this.name)) // Pass parameters to the Detail page.

      Navigator() {
        Text('Back to previous page').width('100%').textAlign(TextAlign.Center)
      }.active(this.active)
      .onClick(() => {
        this.active = true
      })
    }.height(150).width(350).padding(35)
  }
}

interface NameObject {
  name: string;
}

class TextObject {
  text: NameObject;

  constructor(text: NameObject) {
    this.text = text;
  }
}
```

```ts
// Detail.ets
import { router } from '@kit.ArkUI'

@Entry
@Component
struct DetailExample {
  // Receive the input parameters of Navigator.ets.
  params: Record<string, NameObject> = router.getParams() as Record<string, NameObject>
  @State name: NameObject = this.params.text

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Back', type: NavigationType.Push }) {
        Text('Go to back page').width('100%').height(20)
      }

      Text('This is ' + this.name.name + ' page')
        .width('100%').textAlign(TextAlign.Center)
    }
    .width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}

interface NameObject {
  name: string;
}
```

```ts
// Back.ets
@Entry
@Component
struct BackExample {
  build() {
    Column() {
      Navigator({ target: 'pages/container/navigator/Navigator', type: NavigationType.Back }) {
        Text('Return to Navigator Page').width('100%').textAlign(TextAlign.Center)
      }
    }.width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![en-us_image_0000001212058486](figures/en-us_image_0000001212058486.gif)
