# Transition Animation Within a Component


The process of inserting and deleting a component is the transition process of the component. The animation of inserting and deleting a component is called the transition animation in the component. You can define the appearance and disappearance effects of a component through the transition animation in the component.


The API of the transition animation in the component is as follows:



```ts
transition(value: TransitionOptions)
```


The input parameter of the [transition](../reference/arkui-ts/ts-transition-animation-component.md) function is the transition effect in the component. You can define the transition effect of one or more transition styles such as translation, transparency, rotation, and scaling. This parameter must be used together with [animateTo] (arkts-layout-update-animation.md# uses explicit animation to generate layout update animation). The component transition effect can be generated only when they are used together.


## Common Usage of Transition

The type parameter is used to specify the gadget change scenario where the current transition dynamic effect takes effect. The type is [TransitionType](../reference/arkui-ts/ts-appendix-enums.md#transitiontype).

- The same animation effect is used for inserting and deleting components.

  ```ts
  Button()
    .transition({ type: TransitionType.All, scale: { x: 0, y: 0 } })
  ```

  When the type attribute is TransitionType.All, the specified transition effect takes effect in all change (insertion and deletion) scenarios of the component. In this case, deleting the animation and inserting the animation are reverse processes, and deleting the animation is reverse playing of inserting the animation. For example, the preceding code defines a Button control. When a component is inserted, the component changes from the state where x and y of the scale are both 0 to the default state where x and y of the scale are both 1 (complete display). The component is gradually zoomed in. When a component is deleted, the component changes from the default state where x and y of the scale are 1 to the state where x and y of the specified scale are 0 and gradually shrinks to 0.


- Different animation effects are used for inserting and deleting components.

  ```ts
  Button()
    .transition({ type: TransitionType.Insert, translate: { x: 200, y: -200 }, opacity: 0 })
    .transition({ type: TransitionType.Delete, rotate: { x: 0, y: 0, z: 1, angle: 360 } })
  ```

  When different transition animation effects need to be implemented for component insertion and deletion, you can call the transition function twice to set the type attribute to TransitionType.Insert and TransitionType.Delete respectively. For example, the preceding code defines a Button control. When the component is inserted, the component changes from an initial state in which the position is translated by 200 vp in the x direction and the position is translated by –200 vp in the y direction relative to the normal layout position of the component, and the transparency is 0 in the x and y directions to a default state in which the translation amount is 0 and the transparency is 1. The inserted animation is a combination of a translation animation and a transparency animation. When the component is deleted, the component changes from the default state in which the rotation angle is 0 to the end state in which the component rotates 360 degrees around the z axis, that is, rotates around the z axis for one week.


- Define only one of the animation effects of inserting or deleting a component.

  ```ts
  Button()
    .transition({ type: TransitionType.Delete, translate: { x: 200, y: -200 } })
  ```

  If only the transition animation effect of component insertion or deletion is required, you only need to set the transition effect whose type attribute is TransitionType.Insert or TransitionType.Delete. For example, the preceding code defines a Button control. When a component is deleted, the component is moved from the normal position without translation to the position of 200 vp in the x direction and -200 vp in the y direction relative to the normal layout position. Inserting the component does not generate a transition animation for the component.


## if/else: generates transition animations in components.

The if/else statement can control the insertion and deletion of components. The following code can be used to control whether the if condition is met through the button click event to control whether to display the Image component under if.



```ts
@Entry
@Component
struct IfElseTransition {
  @State flag: boolean = true;
  @State show: string = 'show';

  build() {
    Column() {
      Button(this.show).width(80).height(30).margin(30)
        .onClick(() => {
          if (this.flag) {
            this.show = 'hide';
          } else {
            this.show = 'show';
          }
          //Click the button to control the display and disappearance of the image.
          this.flag = !this.flag;
        })
      if (this.flag) {
          Image($r('app.media.mountain')).width(200).height(200)
      }
    }.height('100%').width('100%')
  }
}
```


No animation is configured in the preceding code. Next, we'll add the in-component transition effect to the above code. The Image component is controlled by if. You need to add the transition parameter to the Image component to specify the transition effect in the component. For example, you can add the translation effect when inserting the file, and add the scaling and transparency effects when deleting the file.



```ts
if (this.flag) {
  Image($r('app.media.mountain')).width(200).height(200)
    .transition({ type: TransitionType.Insert, translate: { x: 200, y: -200 } })
    .transition({ type: TransitionType.Delete, opacity: 0, scale: { x: 0, y: 0 } })
}
```


Although the preceding code specifies the animation style, the animation parameters are not specified. Therefore, you do not know how long and how to use the curve to complete the animation. Transition must be used together with animateTo. In the closure of animateTo, transition controls the insertion and deletion of components. The preceding sample code is used to change the value of flag in the animateTo closure. The code is as follows: Set the animation duration to 1000 ms, use the default curve of the animateTo function, and change the value of flag. Animation is generated based on the animation parameter for all changes caused by flag changes. Here, the flag affects the appearance and disappearance of the image.



```ts
animateTo({ duration: 1000 }, () => {
  this.flag = !this.flag;
})
```


After the preceding process, when animateTo and transition are used together, the transition animation in the component is generated. The complete sample code is as follows:



```ts
@Entry
@Component
struct IfElseTransition {
  @State flag: boolean = true;
  @State show: string = 'show';

  build() {
    Column() {
      Button(this.show).width(80).height(30).margin(30)
        .onClick(() => {
          if (this.flag) {
            this.show = 'hide';
          } else {
            this.show = 'show';
          }
          
          animateTo({ duration: 1000 }, () => {
            //Control the appearance and disappearance of the Image component in the animation closure.
            this.flag = !this.flag;
          })
        })
      if (this.flag) {
        //The appearance and disappearance of the image are configured as different transition effects.
        Image($r('app.media.mountain')).width(200).height(200)
          .transition({ type: TransitionType.Insert, translate: { x: 200, y: -200 } })
          .transition({ type: TransitionType.Delete, opacity: 0, scale: { x: 0, y: 0 } })
      }
    }.height('100%').width('100%')
  }
}
```


![ifElseTransition](figures/ifElseTransition.gif)


>**NOTE**
>
>When the transition effect is set to translate or scale, the animation process may exceed the range of the parent component after the translation or magnification is overlaid on the position. If you want the child component to be completely displayed when the parent component is beyond the range of the parent component, you can set the clip attribute of the parent component to false so that the parent component does not tailor the child component. If you want the excess child components not to be displayed when the parent component is exceeded, you can set the clip attribute of the parent component to true to tailor the excess child components.


## Forach generates transition animations in components.

Similar to if/else, Forach can control the insertion and deletion of components by controlling the number of elements in an array. To use Forach to generate an intra-component transition animation, the following conditions must be met:

- The transition effect is configured for the component in Forach.

- Controls the insertion or deletion of components in the closure of animateTo, that is, controls the addition and deletion of array elements.


The following code is an example of using Forach to generate an in-component transition animation.



```ts
@Entry
@Component
struct ForEachTransition {
  @State numbers: string[] = ["1", "2", "3", "4", "5"]
  startNumber: number = 6;

  build() {
    Column({ space: 10 }) {
      Column() {
        ForEach(this.numbers, (item) => {
          // The transition effect needs to be configured for the direct component under Forach.
          Text(item)
            .width(240)
            .height(60)
            .fontSize(18)
            .borderWidth(1)
            .backgroundColor(Color.Orange)
            .textAlign(TextAlign.Center)
            .transition({ type: TransitionType.All, translate: { x: 200 }, scale: { x: 0, y: 0 } })
        }, item => item)
      }
      .margin(10)
      .justifyContent(FlexAlign.Start)
      .alignItems(HorizontalAlign.Center)
      .width("90%")
      .height("70%")

      Button ('Add element to header')
        .fontSize(16)
        .width(160)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            //Insert an element to the array header. As a result, Forach adds the corresponding component to the header.
            this.numbers.unshift(this.startNumber.toString());
            this.startNumber++;
          })
        })
      Button ('Add element to tail')
        .width(160)
        .fontSize(16)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            //Insert an element to the end of the array. As a result, Forach adds the corresponding component to the end.
            this.numbers.push(this.startNumber.toString());
            this.startNumber++;
          })
        })
      Button ('Delete Header Element')
        .width(160)
        .fontSize(16)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            //Delete the header element of the array. As a result, Forach deletes the header component.
            this.numbers.shift();
          })
        })
      Button ('Delete Tail Element')
        .width(160)
        .fontSize(16)
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            //Delete the tail element of the array. As a result, Forach deletes the header component.
            this.numbers.pop();
          })
        })
    }
    .width('100%')
    .height('100%')
  }
}
```


The display effect is shown below.


![forEachTransition2](figures/forEachTransition2.gif)


The column layout mode is set to FlexAlign.Start, that is, the vertical layout starts from the head. Therefore, when an element is added to the end of an array, the position of the component corresponding to the existing element in the array is not affected, and only the insertion animation of the new component is triggered. When an element is added to the array header, the subscripts of all elements in the original array are added. Although the addition or deletion of the element is not triggered, the location of the corresponding component is affected. Therefore, in addition to the transition animation for new components, the position animation is also performed for components in Forach.


>**NOTE**
>
>If/else and ForEach are syntax nodes. The component for configuring the transition effect in the component should be directly used as the child of the syntax node. If a component is added or deleted due to the addition or deletion of a syntax node, only the intra-component transition animation of the direct child component can be triggered. Developers should not expect the component transition animation to be generated for deeper components.
