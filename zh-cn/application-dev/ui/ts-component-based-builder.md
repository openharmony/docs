# @Builder


@Builder装饰的方法用于定义组件的声明式UI描述，在一个自定义组件内快速生成多个布局内容。\@Builder装饰方法的功能和语法规范与[build函数](ts-function-build.md)相同。


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
@BuilderParam装饰器用于修饰自定义组件内函数类型的属性（例如：`@BuilderParam content: () => any;`），并且在初始化自定义组件时被@BuilderParam修饰的属性必须赋值。

### 引入动机

当开发者创建自定义组件，想对该组件添加特定功能时（如：仅对自定义组件添加一个点击跳转操作）。若直接在组件内嵌入事件方法，将会导致所有初始化该组件的地方均增加了该功能。为解决此问题，引入了@BuilderParam装饰器，此装饰器修饰的属性值可为@Builder修饰的方法，开发者可在初始化自定义组件时对此属性进行赋值，为自定义组件增加特定的的功能。

### 参数初始化组件
通过参数初始化组件时，将@Builder装饰的方法赋值给@BuilderParam修饰的属性，并在自定义组件内调用content属性值。对@BuilderParam修饰的属性进行赋值时不带参数（如：`content: this.specificParam`），则此属性的类型需定义成无返回值的函数（如：`@BuilderParam content: () => void`）。若带参数（如：`callContent: this.specificParam1("111")`），则此属性的类型需定义成any（如：`@BuilderParam callContent: any;`）。

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
### 尾随闭包初始化组件
在自定义组件中使用@BuilderParam修饰的属性接收尾随闭包（在初始化自定义组件时，组件名称紧跟一个大括号“{}”形成尾随闭包场景（`CustomComponent(){}`）。开发者可把尾随闭包看做一个容器，向其填充内容，如在闭包内增加组件（`{Column(){Text("content")}`），闭包内语法规范与[build](../ui/ts-function-build.md)一致。此场景下自定义组件内有且仅有一个使用@BuilderParam修饰的属性。

示例：在闭包内增加Column组件并添加点击事件，在新增的Column组件内调用@Builder修饰的specificParam方法，点击Column组件后该改变自定义组件中header的属性值为“changeHeader”。并且在初始化自定义组件时会把尾随闭包的内容赋值给使用@BuilderParam修饰的closer属性。
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
