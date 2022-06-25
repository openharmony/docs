# @Styles


The **@Styles** decorator adds new attribute functions to basic components, such as **\<Text>**, **\<Column>**, and **\<Button>**. Currently, **@Styles** supports only universal attributes. You can use the **@Styles** decorator to quickly define and reuse the custom styles of a component.

**@Styles** can be defined inside or outside a component. When it is defined outside a component, the keyword function must be included.



```
@Styles function globalFancy() {
  .backgroundColor(Color.Red)
}

@Entry
@Component
struct FancyUse {
  @Styles componentFancy() {
    .backgroundColor(Color.Blue)
  }
  build() {
    Column({ space: 10 }) {
      Text("Fancy")
        .globalFancy()
        .width(100)
        .height(100)
        .fontSize(30)
      Text("Fancy")
        .componentFancy()
        .width(100)
        .height(100)
        .fontSize(30)
    }
  }
}
```

**@Styles** can also be used inside the **StateStyles** attribute to assign state-specific attributes to components.


In **StateStyles**, styles defined outside the component can be directly called. However, the keyword **this** must be used to call styles defined in the component.



```
@Styles function globalFancy() {
  .width(100)
  .height(100)
}

@Entry
@Component
struct FancyUse {
  @Styles componentFancy() {
    .width(50)
    .height(50)
  }
  build() {
    Row({ space: 10 }) {
      Button() {
      	Text("Fancy")
      }
      .stateStyles({
      	normal: {
      	  .width(80)
      	  .height(80)
      	},
      	disabled: this.componentFancy,
      	pressed: globalFancy
      })
    }
  }
}
```
