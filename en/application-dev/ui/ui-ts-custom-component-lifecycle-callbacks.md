# Custom Component Lifecycle Callbacks

The lifecycle callbacks of a custom component are used to notify users of the lifecycle of the component. These callbacks are private and are invoked by the development framework at a specified time at runtime. They cannot be manually invoked from applications.

> **NOTE**
>
> - Promise and asynchronous callback functions can be used in lifecycle functions, for example, network resource getters and timer setters.
>
> - Do not use **async await** in lifecycle functions.


## aboutToAppear

aboutToAppear?(): void

Invoked after a new instance of the custom component is created and before its **build** function is executed. You can change state variables in the **aboutToAppear** function. The change will take effect when you execute the **build** function next time.

## aboutToDisappear

aboutToDisappear?(): void

Invoked before the destructor of the custom component is consumed. Do not change state variables in the **aboutToDisappear** function as doing this can cause unexpected errors. For example, the modification of the **@Link** decorated variable may cause unstable application running.

**Example 1:**

```ts
// xxx.ets
@Entry
@Component
struct CountDownTimerComponent {
  @State countDownFrom: number = 10
  private timerId: number = -1

  aboutToAppear(): void {
    this.timerId = setInterval(() => {
      if (this.countDownFrom <= 1) {
        clearTimeout(this.timerId) // Clear the timer when the value of countDownFrom is less than or equal to 1.
      }
      this.countDownFrom -= 1
    }, 1000) // The value of countDownFrom decreases by 1 every second.
  }

  aboutToDisappear(): void {
    if (this.timerId > 0) {
      clearTimeout(this.timerId)
      this.timerId = -1
    }
  }

  build() {
    Column() {
      Text(`${this.countDownFrom} sec left`)
        .fontSize(30)
        .margin(30)
    }.width('100%')
  }
}
```

![aboutToAppear](figures/aboutToAppear.gif)

The example above shows that lifecycle functions are critical for **CountDownTimerComponent** to manage its timer resources. Similar functions include loading resources asynchronously from the network.

## onPageShow

onPageShow?(): void

Invoked each time when a page is displayed. This callback is used in the routing process or scenarios where the application is switched to the foreground or background. Only the custom components decorated by **@Entry** take effect.

## onPageHide

onPageHide?(): void

Invoked each time when a page is hidden. This callback is used in the routing process or scenarios where the application is switched to the foreground or background. Only the custom components decorated by **@Entry** take effect.

## onBackPress

onBackPress?(): void

Invoked when a user clicks the back button. Only the custom components decorated by **@Entry** take effect. If **true** is returned, the page processes the return logic and no page routing is performed. If **false** is returned, the default route return logic is used. If the return value is not set, the value **false** is used.

**Example 2:**

```ts
// xxx.ets
@Entry
@Component
struct IndexComponent {
  @State textColor: Color = Color.Black

  onPageShow() {
    this.textColor = Color.Blue
    console.info('IndexComponent onPageShow')
  }

  onPageHide() {
    this.textColor = Color.Transparent
    console.info('IndexComponent onPageHide')
  }

  onBackPress() {
    this.textColor = Color.Red
    console.info('IndexComponent onBackPress')
  }

  build() {
    Column() {
      Text('Hello World')
        .fontColor(this.textColor)
        .fontSize(30)
        .margin(30)
    }.width('100%')
  }
}
```

![lifecycle](figures/lifecycle.PNG)

## onLayout<sup>9+</sup>

onLayout?(children: Array\<LayoutChild\>, constraint: ConstraintSizeOptions): void

Invoked when the custom component lays out its child components. Through this callback the component receives its child component layout information and size constraint from the framework. The state variable cannot be changed in the **onLayout** function.

**Parameters**

| Name    | Type                                                                            | Description                  |
| ---------- | -------------------------------------------------------------------------------- | ---------------------- |
| children   | Array\<[LayoutChild](#layoutchild9)\>                                            | Child component layout information.      |
| constraint | [ConstraintSizeOptions](../reference/arkui-ts/ts-types.md#constraintsizeoptions) | Size constraint information of the parent component.|

## onMeasure<sup>9+</sup>

onMeasure?(children: Array\<LayoutChild\>, constraint: ConstraintSizeOptions): void

Invoked when the custom component needs to determine its size. Through this callback the component receives its child component layout information and size constraint from the framework. The state variable cannot be changed in the onMeasure function.

**Parameters**

| Name    | Type                                                                            | Description                  |
| ---------- | -------------------------------------------------------------------------------- | ---------------------- |
| children   | Array\<[LayoutChild](#layoutchild9)\>                                            | Child component layout information.      |
| constraint | [ConstraintSizeOptions](../reference/arkui-ts/ts-types.md#constraintsizeoptions) | Size constraint information of the parent component.|

## LayoutChild<sup>9+</sup>

Provides the child component layout information.

| Name      | Type                                                                                                   | Description                                  |
| ---------- | ----------------------------------------------------------------------------------------------------------- | -------------------------------------- |
| name       | string                                                                                                      | Name of the child component.                          |
| id         | string                                                                                                      | ID of the child component.                            |
| constraint | [ConstraintSizeOptions](../reference/arkui-ts/ts-types.md#constraintsizeoptions)                            | Size constraint of the child component.                      |
| borderInfo | [LayoutBorderInfo](#layoutborderinfo9)                                                                      | Border information of the child component.                    |
| position   | [Position](../reference/arkui-ts/ts-types.md#position)                                                      | Position coordinates of the child component.                      |
| measure    | (childConstraint: [ConstraintSizeOptions](../reference/arkui-ts/ts-types.md#constraintsizeoptions)) => void | Method called to apply the size constraint to the child component.|
| layout     | (LayoutInfo: [LayoutInfo](#layoutinfo9)) => void                                                          | Method called to apply the layout information to the child component.|

## LayoutBorderInfo<sup>9+</sup>

Provides the border information of the child component.

| Name       | Type                                                  | Description                                          |
| ----------- | ---------------------------------------------------------- | ---------------------------------------------- |
| borderWidth | [EdgeWidths](../reference/arkui-ts/ts-types.md#edgewidths) | Edge widths in different directions of the child component.|
| margin      | [Margin](../reference/arkui-ts/ts-types.md#margin)         | Margin areas in different directions of the child component.    |
| padding     | [Padding](../reference/arkui-ts/ts-types.md#padding)       | Padding areas in different directions of the child component.    |

## LayoutInfo<sup>9+</sup>

Provides the layout information of the child component.

| Name      | Type                                                                        | Description            |
| ---------- | -------------------------------------------------------------------------------- | ---------------- |
| position   | [Position](../reference/arkui-ts/ts-types.md#position)                           | Position coordinates of the child component.|
| constraint | [ConstraintSizeOptions](../reference/arkui-ts/ts-types.md#constraintsizeoptions) | Size constraint of the child component.|

Example 3:

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      CustomLayout() {
        ForEach([1, 2, 3], (index) => {
          Text('Sub' + index)
            .fontSize(30)
            .borderWidth(2)
        })
      }
    }
  }
}


@Component
struct CustomLayout {
  @BuilderParam builder: () => {}

  onLayout(children: Array<LayoutChild>, constraint: ConstraintSizeOptions) {
    let pos = 0
    children.forEach((child) => {
      child.layout({ position: { x: pos, y: pos }, constraint: constraint })
      pos += 100
    })
  }

  onMeasure(children: Array<LayoutChild>, constraint: ConstraintSizeOptions) {
    let size = 100
    children.forEach((child) => {
      child.measure({ minHeight: size, minWidth: size, maxWidth: size, maxHeight: size })
      size += 50
    })
  }

  build() {
    this.builder()
  }
}
```

![customlayout](figures/customLayout.png)
