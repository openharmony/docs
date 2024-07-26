# Precisely Controlling Render Scope

In development of complex pages, precisely controlling the component render scope is especially important to speed up applications.

## Associating Multiple Components with Different Attributes of the Same Object

This document exemplifies why and how the component render scope may be precisely controlled. For starters, you need to understand the re-render mechanism with state management.

```ts
@Observed
class ClassA {
  prop1: number = 0;
  prop2: string = "This is Prop2";
}
@Component
struct CompA {
  @ObjectLink a: ClassA;
  private sizeFont: number = 30; // the private variable does not invoke rendering
  private isRenderText() : number {
    this.sizeFont++; // the change of sizeFont will not invoke rendering, but showing that the function is called
    console.log("Text prop2 is rendered");
    return this.sizeFont;
  }
  build() {
    Column() {
      Text(this.a.prop2) // when this.a.prop2 changes, it will invoke Text rerendering
        .fontSize(this.isRenderText()) // If the <Text> renders, the function isRenderText will be called.
    }
  }
}
@Entry
@Component
struct Page {
  @State a: ClassA = new ClassA();
  build() {
    Row() {
      Column() {
        Text("Prop1: " + this.a.prop1)
          .fontSize(50)
          .margin({ bottom: 20 })
        CompA({a: this.a})
        Button("Change prop1")
          .width(200)
          .margin({ top: 20 })
          .onClick(() => {
            this.a.prop1 = this.a.prop1 + 1 ;
          })
      }
      .width('100%')
    }
    .width('100%')
    .height('100%')
  }
}
```

In the preceding example, when the value of **prop1** changes at the click of the button, although the components in **CompA** do not use **prop1**, you can still observe that the **Text** component associated with **prop2** is re-rendered – reflected by the component's enlarged font size and the console log of "Text prop2 is rendered." This indicates that, when a property (**prop1** in this example) of an @Observed decorated class object is changed, all components associated with any property of this object are re-rendered at once, even though these components may not directly use the changed property (i.e., the **Text** component using **prop** in this example). In this case, invisible, redundant re-renders occur. When a large number of components are involved in redundant re-renders, the render performance is greatly affected.

The following figure shows the code running.

![precisely-control-render-scope-01.gif](figures/precisely-control-render-scope-01.gif)

The following is a typical example of redundant re-renders.

```ts
@Observed
class UIStyle {
  translateX: number = 0;
  translateY: number = 0;
  scaleX: number = 0.3;
  scaleY: number = 0.3;
  width: number = 336;
  height: number = 178;
  posX: number = 10;
  posY: number = 50;
  alpha: number = 0.5;
  borderRadius: number = 24;
  imageWidth: number = 78;
  imageHeight: number = 78;
  translateImageX: number = 0;
  translateImageY: number = 0;
  fontSize: number = 20;
}
@Component
struct SpecialImage {
  @ObjectLink uiStyle: UIStyle;
  private isRenderSpecialImage() : number { // Function to show whether the component is rendered.
    console.log("SpecialImage is rendered");
    return 1;
  }
  build() {
    Image($r('app.media.icon'))
      .width(this.uiStyle.imageWidth)
      .height(this.uiStyle.imageHeight)
      .margin({ top: 20 })
      .translate({
        x: this.uiStyle.translateImageX,
        y: this.uiStyle.translateImageY
      })
      .opacity(this.isRenderSpecialImage()) // If the <Image> is rendered, it will call the function.
  }
}
@Component
struct CompA {
  @ObjectLink uiStyle: UIStyle
  // The following functions are used to show whether the component is called to be rendered.
  private isRenderColumn() : number {
    console.log("Column is rendered");
    return 1;
  }
  private isRenderStack() : number {
    console.log("Stack is rendered");
    return 1;
  }
  private isRenderImage() : number {
    console.log("Image is rendered");
    return 1;
  }
  private isRenderText() : number {
    console.log("Text is rendered");
    return 1;
  }
  build() {
    Column() {
      // When you compile this code in API version 9, the IDE may tell you that
      // "Assigning the '@ObjectLink' decorated attribute 'uiStyle' to the '@ObjectLink' decorated attribute 'uiStyle' is not allowed. <etsLint>"
      // Yet, you can still run the code by Previewer.
      SpecialImage({
        uiStyle: this.uiStyle
      })
      Stack() {
        Column() {
            Image($r('app.media.icon'))
              .opacity(this.uiStyle.alpha)
              .scale({
                x: this.uiStyle.scaleX,
                y: this.uiStyle.scaleY
              })
              .padding(this.isRenderImage())
              .width(300)
              .height(300)
        }
        .width('100%')
        .position({ y: -80 })
        Stack() {
          Text("Hello World")
            .fontColor("#182431")
            .fontWeight(FontWeight.Medium)
            .fontSize(this.uiStyle.fontSize)
            .opacity(this.isRenderText())
            .margin({ top: 12 })
        }
        .opacity(this.isRenderStack())
        .position({
          x: this.uiStyle.posX,
          y: this.uiStyle.posY
        })
        .width('100%')
        .height('100%')
      }
      .margin({ top: 50 })
      .borderRadius(this.uiStyle.borderRadius)
      .opacity(this.isRenderStack())
      .backgroundColor("#FFFFFF")
      .width(this.uiStyle.width)
      .height(this.uiStyle.height)
      .translate({
        x: this.uiStyle.translateX,
        y: this.uiStyle.translateY
      })
      Column() {
        Button("Move")
          .width(312)
          .fontSize(20)
          .backgroundColor("#FF007DFF")
          .margin({ bottom: 10 })
          .onClick(() => {
            animateTo({
              duration: 500
            },() => {
              this.uiStyle.translateY = (this.uiStyle.translateY + 180) % 250;
            })
          })
        Button("Scale")
          .borderRadius(20)
          .backgroundColor("#FF007DFF")
          .fontSize(20)
          .width(312)
          .onClick(() => {
            this.uiStyle.scaleX = (this.uiStyle.scaleX + 0.6) % 0.8;
          })
      }
      .position({
        y:666
      })
      .height('100%')
      .width('100%')

    }
    .opacity(this.isRenderColumn())
    .width('100%')
    .height('100%')

  }
}
@Entry
@Component
struct Page {
  @State uiStyle: UIStyle = new UIStyle();
  build() {
    Stack() {
      CompA({
        uiStyle: this.uiStyle
      })
    }
    .backgroundColor("#F1F3F5")
  }
}
```

In the above example, **uiStyle** defines multiple properties, which are each associated with multiple components. When some of these properties are changed at the click of a button, all the components associated with **uiStyle** are re-rendered according to the mechanism described above, even though they actually do not need to be re-rendered (because the properties of these components are not changed). The re-renders of these components can be observed through a series of defined **isRender** functions. When **Move** is clicked to perform the translation animation, the values of **translateX** and **translateY** change multiple times. As a result, redundant re-renders occur at each frame, which greatly worsen the application performance.

The following figure shows the code running.

![precisely-control-render-scope-02.gif](figures/precisely-control-render-scope-02.gif)

To precisely control the component render scope and avoid redundant re-renders, it is recommended that you divide a large property object into several small property objects.

To achieve this purpose, it is first necessary to understand the mechanism for property change observation.

Below is sample code:

```TS
@Observed
class ClassB {
  subProp1: number = 100;
}
@Observed
class ClassA {
  prop1: number = 0;
  prop2: string = "This is Prop2";
  prop3: ClassB = new ClassB();
}
@Component
struct CompA {
  @ObjectLink a: ClassA;
  private sizeFont: number = 30; // the private variable does not invoke rendering
  private isRenderText() : number {
    this.sizeFont++; // the change of sizeFont will not invoke rendering, but showing that the function is called
    console.log("Text prop2 is rendered");
    return this.sizeFont;
  }
  build() {
    Column() {
      Text(this.a.prop2) // When this.a.prop1 changes, it will invoke <Text> re-rendering.
        .margin({ bottom: 10 })
        .fontSize(this.isRenderText()) // If the <Text> renders, the function isRenderText will be called.
      Text("subProp1 : " + this.a.prop3.subProp1) //the Text can not observe the change of subProp1
        .fontSize(30)
    }
  }
}
@Entry
@Component
struct Page {
  @State a: ClassA = new ClassA();
  build() {
    Row() {
      Column() {
        Text("Prop1: " + this.a.prop1)
          .margin({ bottom: 20 })
          .fontSize(50)
        CompA({a: this.a})
        Button("Change prop1")
          .width(200)
          .fontSize(20)
          .backgroundColor("#FF007DFF")
          .margin({
            top: 10,
            bottom: 10
          })
          .onClick(() => {
            this.a.prop1 = this.a.prop1 + 1 ;
          })
        Button("Change subProp1")
          .width(200)
          .fontSize(20)
          .backgroundColor("#FF007DFF")
          .onClick(() => {
            this.a.prop3.subProp1 = this.a.prop3.subProp1 + 1;
          })
      }
      .width('100%')
    }
    .width('100%')
    .height('100%')
  }
}
```

In the preceding example, when **Change subProp1** is clicked, you can find that the page is not re-rendered. This is because the change to **subProp1** is not observed by the component. When **Change prop1** is clicked, the page is re-rendered, with the latest values of **prop1** and **subProp1** displayed. According to the ArkUI state management mechanism, the state variable can only observe the change at the first layer. For **Change subProp1**, the property value changes at the second layer and therefore cannot be observed. In other words, the change of **this.a.prop3.subProp1** does not cause component re-renders, even if the value of **subProp1** has changed. In comparison, the change of **this.a.prop1** causes component re-renders.

The following figure shows the code running.

![precisely-control-render-scope-03.gif](figures/precisely-control-render-scope-03.gif)

With this mechanism of property change observation, the render scope of components can be precisely controlled.

```ts
@Observed
class ClassB {
  subProp1: number = 100;
}
@Observed
class ClassA {
  prop1: number = 0;
  prop2: string = "This is Prop2";
  prop3: ClassB = new ClassB();
}
@Component
struct CompA {
  @ObjectLink a: ClassA;
  @ObjectLink b: ClassB; // A new @ObjectLink decorated variable.
  private sizeFont: number = 30;
  private isRenderText() : number {
    this.sizeFont++;
    console.log("Text prop2 is rendered");
    return this.sizeFont;
  }
  private isRenderTextSubProp1() : number {
    this.sizeFont++;
    console.log("Text subProp1 is rendered");
    return this.sizeFont;
  }
  build() {
    Column() {
      Text(this.a.prop2) // When this.a.prop1 changes, it will invoke <Text> re-rendering.
        .margin({ bottom: 10 })
        .fontSize(this.isRenderText()) // If the <Text> renders, the function isRenderText will be called.
      Text("subProp1 : " + this.b.subProp1) // Use directly b rather than a.prop3.
        .fontSize(30)
        .opacity(this.isRenderTextSubProp1())
    }
  }
}
@Entry
@Component
struct Page {
  @State a: ClassA = new ClassA();
  build() {
    Row() {
      Column() {
        Text("Prop1: " + this.a.prop1)
          .margin({ bottom: 20 })
          .fontSize(50)
        CompA({
          a: this.a,
          b: this.a.prop3
        })
        Button("Change prop1")
          .width(200)
          .fontSize(20)
          .backgroundColor("#FF007DFF")
          .margin({
            top: 10,
            bottom: 10
          })
          .onClick(() => {
            this.a.prop1 = this.a.prop1 + 1 ;
          })
        Button("Change subProp1")
          .width(200)
          .fontSize(20)
          .backgroundColor("#FF007DFF")
          .margin({
            top: 10,
            bottom: 10
          })
          .onClick(() => {
            this.a.prop3.subProp1 = this.a.prop3.subProp1 + 1;
          })
      }
      .width('100%')
    }
    .width('100%')
    .height('100%')
  }
}
```

In the preceding example, a new variable **b** decorated by @ObjectLink is defined in **CompA**. When **CompA** is created on the page, **prop3** in object **a** is passed to **b**. In this way, **b** can be directly used in **CompA**. This means that, in effect, **CompA** is associated with **b** and can observe the change of **subProp1** in **b**. When **Change subProp1** is clicked, the associated **Text** component is re-rendered, but other components are not (because these components are associated with **a**). Similarly, changes to other properties in **a** do not cause the **Text** component to be re-rendered.

The following figure shows the code running.

![precisely-control-render-scope-04.gif](figures/precisely-control-render-scope-04.gif)

By using the aforementioned method, properties in the foregoing complex redundant re-render scenario can be divided to optimize performance.

```ts
@Observed
class NeedRenderImage { // Properties only used in the same component can be divided into the same new divided class.
  public translateImageX: number = 0;
  public translateImageY: number = 0;
  public imageWidth:number = 78;
  public imageHeight:number = 78;
}
@Observed
class NeedRenderScale { // Properties usually used together can be divided into the same new child class.
  public scaleX: number = 0.3;
  public scaleY: number = 0.3;
}
@Observed
class NeedRenderAlpha { // Properties that may be used in different places can be divided into the same new child class.
  public alpha: number = 0.5;
}
@Observed
class NeedRenderSize { // Properties usually used together can be divided into the same new child class.
  public width: number = 336;
  public height: number = 178;
}
@Observed
class NeedRenderPos { // Properties usually used together can be divided into the same new child class.
  public posX: number = 10;
  public posY: number = 50;
}
@Observed
class NeedRenderBorderRadius { // Properties that may be used in different places can be divided into the same new child class.
  public borderRadius: number = 24;
}
@Observed
class NeedRenderFontSize { // Properties that may be used in different places can be divided into the same new child class.
  public fontSize: number = 20;
}
@Observed
class NeedRenderTranslate { // Properties usually used together can be divided into the same new child class.
  public translateX: number = 0;
  public translateY: number = 0;
}
@Observed
class UIStyle {
  // Define a new variable instead of using the old one.
  needRenderTranslate: NeedRenderTranslate = new NeedRenderTranslate();
  needRenderFontSize: NeedRenderFontSize = new NeedRenderFontSize();
  needRenderBorderRadius: NeedRenderBorderRadius = new NeedRenderBorderRadius();
  needRenderPos: NeedRenderPos = new NeedRenderPos();
  needRenderSize: NeedRenderSize = new NeedRenderSize();
  needRenderAlpha: NeedRenderAlpha = new NeedRenderAlpha();
  needRenderScale: NeedRenderScale = new NeedRenderScale();
  needRenderImage: NeedRenderImage = new NeedRenderImage();
}
@Component
struct SpecialImage {
  @ObjectLink uiStyle : UIStyle;
  @ObjectLink needRenderImage: NeedRenderImage // Receive the new class from its parent component.
  private isRenderSpecialImage() : number { // Function to show whether the component is rendered.
    console.log("SpecialImage is rendered");
    return 1;
  }
  build() {
    Image($r('app.media.icon'))
      .width(this.needRenderImage.imageWidth) // Attention: Use this.needRenderImage.xxx rather than this.uiStyle.needRenderImage.xxx.
      .height(this.needRenderImage.imageHeight)
      .margin({top:20})
      .translate({
        x: this.needRenderImage.translateImageX,
        y: this.needRenderImage.translateImageY
      })
      .opacity(this.isRenderSpecialImage()) // If the <Image> is rendered, it will call the function.
  }
}
@Component
struct CompA {
  @ObjectLink uiStyle: UIStyle;
  @ObjectLink needRenderTranslate: NeedRenderTranslate; // Receive the new class from its parent component.
  @ObjectLink needRenderFontSize: NeedRenderFontSize;
  @ObjectLink needRenderBorderRadius: NeedRenderBorderRadius;
  @ObjectLink needRenderPos: NeedRenderPos;
  @ObjectLink needRenderSize: NeedRenderSize;
  @ObjectLink needRenderAlpha: NeedRenderAlpha;
  @ObjectLink needRenderScale: NeedRenderScale;
  // The following functions are used to show whether the component is called to be rendered.
  private isRenderColumn() : number {
    console.log("Column is rendered");
    return 1;
  }
  private isRenderStack() : number {
    console.log("Stack is rendered");
    return 1;
  }
  private isRenderImage() : number {
    console.log("Image is rendered");
    return 1;
  }
  private isRenderText() : number {
    console.log("Text is rendered");
    return 1;
  }
  build() {
    Column() {
      // When you compile this code in API version 9, the IDE may tell you that
      // "Assigning the '@ObjectLink' decorated attribute 'uiStyle' to the '@ObjectLink' decorated attribute 'uiStyle' is not allowed. <etsLint>"
      // "Assigning the '@ObjectLink' decorated attribute 'uiStyle' to the '@ObjectLink' decorated attribute 'needRenderImage' is not allowed. <etsLint>"
      // Yet, you can still run the code by Previewer.
      SpecialImage({
        uiStyle: this.uiStyle,
        needRenderImage: this.uiStyle.needRenderImage // Send it to its child.
      })
      Stack() {
        Column() {
          Image($r('app.media.icon'))
            .opacity(this.needRenderAlpha.alpha)
            .scale({
              x: this.needRenderScale.scaleX, // Use this.needRenderXxx.xxx rather than this.uiStyle.needRenderXxx.xxx.
              y: this.needRenderScale.scaleY
            })
            .padding(this.isRenderImage())
            .width(300)
            .height(300)
        }
        .width('100%')
        .position({ y: -80 })

        Stack() {
          Text("Hello World")
            .fontColor("#182431")
            .fontWeight(FontWeight.Medium)
            .fontSize(this.needRenderFontSize.fontSize)
            .opacity(this.isRenderText())
            .margin({ top: 12 })
        }
        .opacity(this.isRenderStack())
        .position({
          x: this.needRenderPos.posX,
          y: this.needRenderPos.posY
        })
        .width('100%')
        .height('100%')
      }
      .margin({ top: 50 })
      .borderRadius(this.needRenderBorderRadius.borderRadius)
      .opacity(this.isRenderStack())
      .backgroundColor("#FFFFFF")
      .width(this.needRenderSize.width)
      .height(this.needRenderSize.height)
      .translate({
        x: this.needRenderTranslate.translateX,
        y: this.needRenderTranslate.translateY
      })

      Column() {
        Button("Move")
          .width(312)
          .fontSize(20)
          .backgroundColor("#FF007DFF")
          .margin({ bottom: 10 })
          .onClick(() => {
            animateTo({
              duration: 500
            }, () => {
              this.needRenderTranslate.translateY = (this.needRenderTranslate.translateY + 180) % 250;
            })
          })
        Button("Scale")
          .borderRadius(20)
          .backgroundColor("#FF007DFF")
          .fontSize(20)
          .width(312)
          .margin({ bottom: 10 })
          .onClick(() => {
            this.needRenderScale.scaleX = (this.needRenderScale.scaleX + 0.6) % 0.8;
          })
        Button("Change Image")
          .borderRadius(20)
          .backgroundColor("#FF007DFF")
          .fontSize(20)
          .width(312)
          .onClick(() => { // In the parent component, still use this.uiStyle.needRenderXxx.xxx to change the properties.
            this.uiStyle.needRenderImage.imageWidth = (this.uiStyle.needRenderImage.imageWidth + 30) % 160;
            this.uiStyle.needRenderImage.imageHeight = (this.uiStyle.needRenderImage.imageHeight + 30) % 160;
          })
      }
      .position({
        y: 616
      })
      .height('100%')
      .width('100%')
    }
    .opacity(this.isRenderColumn())
    .width('100%')
    .height('100%')
  }
}
@Entry
@Component
struct Page {
  @State uiStyle: UIStyle = new UIStyle();
  build() {
    Stack() {
      CompA({
        uiStyle: this.uiStyle,
        needRenderTranslate: this.uiStyle.needRenderTranslate, // Send all the new class child need.
        needRenderFontSize: this.uiStyle.needRenderFontSize,
        needRenderBorderRadius: this.uiStyle.needRenderBorderRadius,
        needRenderPos: this.uiStyle.needRenderPos,
        needRenderSize: this.uiStyle.needRenderSize,
        needRenderAlpha: this.uiStyle.needRenderAlpha,
        needRenderScale: this.uiStyle.needRenderScale
      })
    }
    .backgroundColor("#F1F3F5")
  }
}
```

The following figure shows the code running.

![precisely-control-render-scope-05.gif](figures/precisely-control-render-scope-05.gif)

In the preceding example, the 15 properties in the original class are divided into eight child classes, and the corresponding adaptation is performed on the binding between properties and components. Division of properties complies with the following principles:

- Properties that are only used in the same component can be divided into the same new child class, that is, **NeedRenderImage** in the example. This mode of division is applicable to the scenario where components are frequently re-rendered due to changes of unassociated properties. In this scenario, divide the properties or review the view model design.
- Properties that are frequently used together can be divided into the same new child class, that is, **NeedRenderScale**, **NeedRenderTranslate**, **NeedRenderPos**, and **NeedRenderSize** in the example. This mode of division is applicable to the scenario where properties often appear in pairs or are applied to the same style, for example, **.translate**, **.position**, and **.scale** (which usually receive an object as a parameter).
- Properties that may be used in different places should be divided into a new child class, that is, **NeedRenderAlpha**, **NeedRenderBorderRadius**, and **NeedRenderFontSize** in the example. This mode of division is applicable to the scenario where a property works on multiple components or is not related to other properties, for example, **.opacity** and **.borderRadius** (which usually work on their own).

After properties are divided, use the following format to bind components using the properties:

```ts
.property(this.needRenderXxx.xxx)

// sample
Text("some text")
.width(this.needRenderSize.width)
.height(this.needRenderSize.height)
.opacity(this.needRenderAlpha.alpha)
```

If changes of a property apply to the parent component, the property can be changed through the outer parent class.

```ts
// In parent Component
this.parent.needRenderXxx.xxx = x;

// Example
this.uiStyle.needRenderImage.imageWidth = (this.uiStyle.needRenderImage.imageWidth + 20) % 60;
```

If changes of a property apply to the child component, it is recommended that the property be changed through the new child class.

```ts
// In child Component
this.needRenderXxx.xxx = x;

// Example
this.needRenderScale.scaleX = (this.needRenderScale.scaleX + 0.6) % 1
```

When dividing properties to speed up applications, focus on properties that change frequently.

If you want to use the divided properties in the parent component, you are advised to define a new @State decorated state variable and use them together.

```ts
@Observed
class NeedRenderProperty {
  public property: number = 1;
};
@Observed
class SomeClass {
  needRenderProperty: NeedRenderProperty = new NeedRenderProperty();
}
@Entry
@Component
struct Page {
  @State someClass: SomeClass = new SomeClass();
  @State needRenderProperty: NeedRenderProperty = this.someClass.needRenderProperty
  build() {
    Row() {
      Column() {
        Text("property value: " + this.needRenderProperty.property)
          .fontSize(30)
          .margin({ bottom: 20 })
        Button("Change property")
          .onClick(() => {
            this.needRenderProperty.property++;
          })
      }
      .width('100%')
    }
    .width('100%')
    .height('100%')
  }
}
```

## Condition Refreshing When Multiple Components Are Associated with the Same Data

When multiple components depend on different attributes of an object, if the object is directly associated, all components are refreshed when any attribute is changed. You can split and combine attributes in a class into a new class to accurately control component refreshing.

If multiple components depend on the same data source and the components are updated based on the data source change, directly associating the data source causes all components to be updated each time the data source changes. To accurately control component updates, the following policies can be used:
  1. Using the @Watch decorator: The @Watch decorator is used in the component to listen to the data source. When data changes, the service logic is executed to ensure that only the components that meet the conditions are refreshed.
  2. Event-driven update: For complex component relationships or cross-level situations, use the Emitter custom event publishing and subscription mechanism. When the data source changes, the corresponding event is triggered. After receiving the notification, the component that subscribes to the event determines whether to update the component based on the change value.

[Incorrect Usage]

In the following sample code, multiple components are directly associated with the same data source, but the @Watch decorator and Emitter event-driven update are not used. As a result, redundant components are refreshed.

```ts
@Entry  
@Component  
struct Index {  
  @State currentIndex: number = 0; //Subscript of the currently selected list item
  private listData: string[] = [];
  
  aboutToAppear(): void {  
    for (let i = 0; i < 10; i++) {  
      this.listData.push(`ListItemComponent ${i}`);  
    }  
  }  
  
  build() {  
    Row() {  
      Column() {  
        List() {  
          ForEach(this.listData, (item: string, index: number) => {  
            ListItem() {  
              ListItemComponent({ item: item, index: index, currentIndex: this.currentIndex })  
            }  
          })  
        }
        .alignListItem(ListItemAlign.Center)
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
  
@Component  
struct ListItemComponent {  
  @Prop item: string;
  @Prop index: number; //Subscript of a list item
  @Link currentIndex: number; 
  private sizeFont: number = 50; 
  
  isRender(): number {  
    console.info(`ListItemComponent ${this.index} Text is rendered`);  
    return this.sizeFont;  
  }  
  
  build() {  
    Column() {  
      Text(this.item)  
        .fontSize(this.isRender())
        // Dynamically set the text color based on the difference between the index and currentIndex of the current list item.
        .fontColor(Math.abs(this.index - this.currentIndex) <= 1 ? Color.Red : Color.Blue)  
        .onClick(() => {  
          this.currentIndex = this.index;  
        })  
    }  
  }  
}
```
In the preceding example, after clicking Text, each ListItemComponent component assigns the index of the currently clicked list item to currentIndex. The status variable currentIndex decorated by @Link transfers the change to the parent component Index and all ListItemComponent components. Then, in all ListItemComponent components, the text color is determined based on whether the absolute value of the difference between the list item subscript index and currentIndex is less than or equal to 1. If the condition is met, the text is displayed in red. Otherwise, the text is displayed in blue.

The following figure shows the running effect.
![redundant_refresh](./figures/redundant_refresh.gif)

After each click, all Text components are refreshed even if the colors of some Text components do not change. This is because the Text component in the ListItemComponent component is directly associated with currentIndex instead of the color calculated based on currentIndex.

In the preceding scenario, you are advised to use the status decorator @Watch to listen to data sources. When the data source changes, the service logic is executed in the listening callback of @Watch. The component associates the callback processing result instead of directly associating the data source.

[Correct Usage]

The following is an optimization of the preceding example, showing how to use the @Watch decorator to implement precise refresh.

```ts
@Entry
@Component
struct Index {
  @State currentIndex: number = 0; //Subscript of the currently selected list item
  private listData: string[] = [];


  aboutToAppear(): void {
    for (let i = 0; i < 10; i++) {
      this.listData.push (`Component ${i}`);
    }
  }

  build() {
    Row() {
      Column() {
        List() {
          ForEach(this.listData, (item: string, index: number) => {
            ListItem() {
              ListItemComponent({ item: item, index: index, currentIndex: this.currentIndex })
            }
          })
        }
        .alignListItem(ListItemAlign.Center)
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component
struct ListItemComponent {
  @Prop item: string;
  @Prop index: number; //Subscript of a list item
  @Link @Watch('onCurrentIndexUpdate') currentIndex: number;
  @State color: Color = Math.abs(this.index - this.currentIndex) <= 1 ? Color.Red : Color.Blue;

  isRender(): number {
    console.info(`ListItemComponent ${this.index} Text is rendered`);
    return 50;
  }

  onCurrentIndexUpdate() {
    // Dynamically change the color value based on the difference between the index and currentIndex of the current list item.
    this.color = Math.abs(this.index - this.currentIndex) <= 1 ? Color.Red : Color.Blue;
  }

  build() {
    Column() {
      Text(this.item)
        .fontSize(this.isRender())
        .fontColor(this.color)
        .onClick(() => {
          this.currentIndex = this.index;
        })
    }
  }
}
```
In the preceding code, the status variable currentIndex in the ListItemComponent component is decorated using @Watch, and the Text component is directly associated with the new status variable color. When currentIndex changes, the onCurrentIndexUpdate method is triggered to assign the calculation result of the expression to the status variable color. The Text component is rendered again only when the value of color changes.

The following figure shows the running effect.

![precise_refresh.gif](./figures/precise_refresh.gif)

When the depended data source is transferred only in a parent-child or sibling component, you can refer to the preceding example to use the @State/@Link/@Watch decorator to manage the status and implement precise component refresh.

If there are many component relationship levels but all components belong to the same component tree, you are advised to use @Provide/@Consume to transfer data, use the @Watch decorator to listen to data changes, and execute service logic in the listening callback. For details, see the following pseudocode.

```ts
// in ParentComponent
@Provide @Watch('onCurrentValueUpdate') currentValue: number = 0;
@State parentComponentResult: number = 0;
onCurrentValueUpdate() {
  // Execute the service logic.
  this.parentComponentResult = X; // X indicates the value that needs to be assigned to parentComponentResult based on service logic.
}
Component.property(this.parentComponentResult)

// in ChildComponent
@Provide @Watch('onCurrentValueUpdate') currentValue: number = 0;
@State childComponentResult: number = 0;
onCurrentValueUpdate() {
  // Execute the service logic.
  this.childComponentResult = X; // X indicates the value that needs to be assigned to childComponentResult based on service logic.
}
Component.property(this.childComponentResult)

// in NestedComponent
@Provide @Watch('onCurrentValueUpdate') currentValue: number = 0;
@State nestedComponentResult: number = 0;
onCurrentValueUpdate() {
  // Execute the service logic.
  this.nestedComponentResult = X; // X indicates the value that needs to be assigned to nestedComponentResult based on service logic.
}
Component.property(this.nestedComponentResult)
```

When component relationships are complex or cross too many levels, you are advised to use the [Emitter] (../reference/apis-basic-services-kit/js-apis-emitter.md) customized event release and subscription mode. When the data source changes, an event is released. Components that depend on the data source obtain the data source change through event subscription to complete service logic processing, implementing precise component update.

The following uses some sample codes to describe how to use the tool.

The ButtonComponent component functions as an interaction component to trigger data changes. The ListItemComponent component receives data and refreshes the UI accordingly.

```ts
Column() {
  Row() {
    Column() {
      ButtonComponent()
    }
  }
  Column() {
    Column() {
      List() {
        ForEach(this.listData, (item: string, index: number) => {
          ListItemComponent({ myItem: item, index: index })
        })
      }
      .alignListItem(ListItemAlign.Center)
    }
  }
}
```
The relationship between the ButtonComponent and ListItemComponent components is complex. Therefore, in the Button callback of the ButtonComponent component, you can use emitter.emit to send events and subscribe to events in the ListItemComponent component. The data value is received in the callback triggered by the event. The service logic determines whether to modify the status variable color to accurately control the update of Text in the ListItemComponent component.

```ts
// in ButtonComponent
Button (`The component text whose subscript is a multiple of ${this.value} turns red`.)
  .onClick(() => {
    let event: emitter.InnerEvent = {
      eventId: 1,
      priority: emitter.EventPriority.LOW
    };
    let eventData: emitter.EventData = {
      data: {
        value: this.value
      }
    };
    // Emit the event with eventId 1 and event content eventData.
    emitter.emit(event, eventData);
    this.value++;
  })

```

```ts
// in ListItemComponent
@State color: Color = Color.Black;
aboutToAppear(): void {
  let event: emitter.InnerEvent = {
    eventId: 1
  };
  // Trigger the callback after the event with eventId 1 is received.
  let callback = (eventData: emitter.EventData): void => {
    if (eventData.data?.value !== 0 && this.index % eventData.data?.value === 0) {
      this.color = Color.Red;
    }
  };
  // Subscribe to the event with eventId 1.
  emitter.on(event, callback);
}
build() {
  Column() {
    Text(this.myItem)
      .fontSize(this.isRender())
      .fontColor(this.color)
  }
}
```
