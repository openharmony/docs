# @Builder


The **@Builder** decorated method is used to define the declarative UI description of a component and quickly generate multiple layouts in a custom component. The functionality and syntax of the **@Builder** decorator are the same as those of the [build Function](ts-function-build.md).


```
@Entry
@Component
struct CompA {
  size : number = 100;

  @Builder SquareText(label: string) {
    Text(label)
      .width(1 * this.size)
      .height(1 * this.size)
  }

  @Builder RowOfSquareTexts(label1: string, label2: string) {
    Row() {
      this.SquareText(label1)
      this.SquareText(label2)
    }
    .width(2 * this.size)
    .height(1 * this.size)
  }

  build() {
    Column() {
      Row() {
        this.SquareText("A")
        this.SquareText("B")
        // or as long as tsc is used
      }
      .width(2 * this.size)
      .height(1 * this.size)
      this.RowOfSquareTexts("C", "D")
    }
    .width(2 * this.size)
    .height(2 * this.size)
  }
}
```
## @BuilderParam<sup>8+<sup>
The **@BuilderParam** decorator is used to modify the function type attributes (for example, `@BuilderParam content: () => any;`) in a custom component. When the custom component is initialized, the attributes modified by the **@BuilderParam** decorator must be assigned values.

### Background

In certain circumstances, you may need to add a specific function, such as a click-to-jump action, to a custom component. However, embedding an event method directly inside of the component will add the function to all places where the component is initialized. This is where the **@BuilderParam** decorator comes into the picture. When initializing a custom component, you can assign a **@Builder** decorated method to the **@BuilderParam** decorated attribute, thereby adding the specific function to the custom component.

### Component Initialization Through Parameters
When initializing a custom component through parameters, assign a **@Builder** decorated method to the **@BuilderParam** decorated attribute — **content**, and call the value of **content** in the custom component. If no parameter is passed when assigning a value to the **@BuilderParam** decorated attribute (for example, `content: this.specificParam`), define the type of the attribute as a function without a return value (for example, `@BuilderParam content: () => void`). If any parameter is passed when assigning a value to the **@BuilderParam** decorated attribute (for example, `callContent: this.specificParam1("111")`), define the type of the attribute as `any` (for example,`@BuilderParam callContent: any;`).

```
@Component
struct CustomContainer {
  header: string = "";
  @BuilderParam noParam: () => void;
  @BuilderParam withParam: any;
  footer: string = "";
  build() {
    Column() {
      Text(this.header)
        .fontSize(50)
      this.noParam()
      this.withParam()
      Text(this.footer)
        .fontSize(50)
    }
  }
}

@Entry
@Component
struct CustomContainerUser {
  @Builder specificNoParam() {
    Column() {
      Text("noParam").fontSize(50)
    }
  }
  @Builder SpecificWithParam(label: string) {
    Column() {
      Text(label).fontSize(50)
    }
  }

  build() {
    Column() {
      CustomContainer({
        header: "Header",
        noParam: this.specificNoParam,
        withParam: this.SpecificWithParam("WithParam"),
        footer: "Footer",
      })
    }
  }
}
```
### Component Initialization Through Trailing Closure
In a custom component, use the **@BuilderParam** decorated attribute to receive a trailing closure. When the custom component is initialized, the component name is followed by a pair of braces ({}) to form a trailing closure (`CustomComponent(){}`). You can consider a trailing closure as a container and add content to it. For example, you can add a component (`{Column(){Text("content")}`) to a trailing closure. The syntax of the closure is the same as that of [build](../ui/ts-function-build.md). In this scenario, the custom component has one and only one **@BuilderParam** decorated attribute.

Example: Add a **\<Column>** component and a click event to the closure, and call the **specificParam** method decorated by **@Builder** in the new **\<Column>** component. After the **\<Column>** component is clicked, the value of the component's `header` attribute will change to `changeHeader`. In addition, when the component is initialized, the content of the trailing closure will be assigned to the `closer` attribute decorated by **@BuilderParam**.
```
@Component
struct CustomContainer {
  header: string = "";
  @BuilderParam closer: () => void;
  build() {
    Column() {
      Text(this.header)
        .fontSize(50)
      this.closer()
    }
  }
}
@Builder function specificParam(label1: string, label2: string) {
  Column() {
    Text(label1)
      .fontSize(50)
    Text(label2)
      .fontSize(50)
  }
}
@Entry
@Component
struct CustomContainerUser {
  @State text: string = "header"
  build() {
    Column() {
      CustomContainer({
        header: this.text,
      }){
        Column(){
          specificParam("111", "22")
        }.onClick(()=>{
          this.text = "changeHeader"
        })
      }
    }
  }
}
```
