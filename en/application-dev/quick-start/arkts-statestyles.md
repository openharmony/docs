# stateStyles: Polymorphic Style


Unlike \@Styles and \@Extend, which are used to reuse styles only on static pages, stateStyles enables you to set state-specific styles.  


## Overview

stateStyles is an attribute method that sets the style based on the internal state of a component. It is similar to a CSS pseudo-class, with different syntax. ArkUI provides the following states:

- focused

- normal

- pressed

- disabled

- selected<sup>10+</sup>


## Application Scenarios


### Common Scenarios

This example shows the most basic application scenario of stateStyles. The **\<Button>** component is the first component and is in the default focused state, where the pink style specified for **focused** takes effect. When the component is pressed, the black style specified for **pressed** takes effect. If you place another component before the **\<Button>** component and have it in the normal state, the yellow style specified for **normal** takes effect.


```ts
@Entry
@Component
struct StateStylesSample {
  build() {
    Column() {
      Button('Click me')
        .stateStyles({
          focused: {
            .backgroundColor(Color.Pink)
          },
          pressed: {
            .backgroundColor(Color.Black)
          },
          normal: {
            .backgroundColor(Color.Yellow)
          }
        })
    }.margin('30%')
  }
}
```


  **Figure 1** Focused and pressed states 

![Video_2023-03-17_120758](figures/Video_2023-03-17_120758.gif)


### Combined Use of \@Styles and stateStyles

The following example uses \@Styles to specify different states of stateStyles.



```ts
@Entry
@Component
struct MyComponent {
  @Styles normalStyle() {
    .backgroundColor(Color.Gray)
  }

  @Styles pressedStyle() {
    .backgroundColor(Color.Red)
  }

  build() {
    Column() {
      Text('Text1')
        .fontSize(50)
        .fontColor(Color.White)
        .stateStyles({
          normal: this.normalStyle,
          pressed: this.pressedStyle,
        })
    }
  }
}
```

  **Figure 2** Normal and pressed states 

![Video_2023-03-17_144824](figures/Video_2023-03-17_144824.gif)


### Using Regular Variables and State Variables in stateStyles

stateStyles can use **this** to bind regular variables and state variables in a component.


```ts
@Entry
@Component
struct CompWithInlineStateStyles {
  @State focusedColor: Color = Color.Red;
  normalColor: Color = Color.Green

  build() {
    Button('clickMe').height(100).width(100)
      .stateStyles({
        normal: {
          .backgroundColor(this.normalColor)
        },
        focused: {
          .backgroundColor(this.focusedColor)
        }
      })
      .onClick(() => {
        this.focusedColor = Color.Pink
      })
      .margin('30%')
  }
}
```

By default, the **\<Button>** component is in red when focused. After a click event is triggered, it turns to pink when focused.

  **Figure 3** Change of the styles in focused state by a click 

![Video_2023-03-17_144605](figures/Video_2023-03-17_144605.gif)
