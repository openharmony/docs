# \@Require装饰器：校验构造传参


\@Require是校验\@Prop、\@State、\@Provide、\@BuilderParam和普通变量(无状态装饰器修饰的变量)是否需要构造传参的一个装饰器。


> **说明：**
>
> 从API version 11开始对\@Prop/\@BuilderParam进行校验。
>
> 从API version 12开始对\@State/\@Provide/普通变量(无状态装饰器修饰的变量)进行校验。
> 从API version 11开始，该装饰器支持在原子化服务中使用。


## 概述

当\@Require装饰器和\@Prop、\@State、\@Provide、\@BuilderParam、普通变量(无状态装饰器修饰的变量)结合使用时，在构造该自定义组件时，\@Prop、\@State、\@Provide、\@BuilderParam和普通变量(无状态装饰器修饰的变量)必须在构造时传参。

## 限制条件

\@Require装饰器仅用于装饰struct内的\@Prop、\@State、\@Provide、\@BuilderParam和普通变量(无状态装饰器修饰的变量)。

预览器限制场景请参考[PreviewChecker检测规则](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-previewer-previewchecker-V5)。

## 使用场景

当Child组件内使用\@Require装饰器和\@Prop、\@State、\@Provide、\@BuilderParam和普通变量(无状态装饰器修饰的变量)结合使用时，父组件Index在构造Child时必须传参，否则编译不通过。

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  @Builder buildTest() {
    Row() {
      Text('Hello, world')
        .fontSize(30)
    }
  }

  build() {
    Row() {
      Child({ regular_value: this.message, state_value: this.message, provide_value: this.message, initMessage: this.message, message: this.message,
        buildTest: this.buildTest, initBuildTest: this.buildTest })
    }
  }
}

@Component
struct Child {
  @Builder buildFunction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
  @Require @BuilderParam buildTest: () => void;
  @Require @BuilderParam initBuildTest: () => void = this.buildFunction;
  @Require @Prop initMessage: string = 'Hello';
  @Require @Prop message: string;

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      Text(this.message)
        .fontSize(30)
      this.initBuildTest();
      this.buildTest();
    }
    .width('100%')
    .height('100%')
  }
}
```

 ![img](figures/9e2d58bc-b0e1-4613-934b-8e4237bd5c05.png) 

使用@ComponentV2修饰的自定义组件ChildPage通过父组件ParentPage进行初始化，因为有@Require装饰，所以父组件必须进行构造赋值。

```ts
@ObservedV2
class Info {
  @Trace name: string = '';
  @Trace age: number = 0;
}

@ComponentV2
struct ChildPage {
  @Require @Param childInfo: Info = new Info();
  @Require @Param state_value: string = "Hello";
  build() {
    Column() {
      Text(`ChildPage childInfo name :${this.childInfo.name}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`ChildPage childInfo age :${this.childInfo.age}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Text(`ChildPage state_value age :${this.state_value}`)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
    }
  }
}

@Entry
@ComponentV2
struct ParentPage {
  info1: Info = { name: "Tom", age: 25 };
  label1: string = "Hello World";
  @Local info2: Info = { name: "Tom", age: 25 };
  @Local label2: string = "Hello World";

  build() {
    Column() {
      Text(`info1: ${this.info1.name}  ${this.info1.age}`) // Text1
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({ childInfo: this.info1, state_value: this.label1}) // 调用自定义组件
      Line()
        .width('100%')
        .height(5)
        .backgroundColor('#000000').margin(10)
      Text(`info2: ${this.info2.name}  ${this.info2.age}`) // Text2
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      ChildPage({ childInfo: this.info2, state_value: this.label2}) // 调用自定义组件
      Line()
        .width('100%')
        .height(5)
        .backgroundColor('#000000').margin(10)
      Button("change info1&info2")
        .onClick(() => {
          this.info1 = { name: "Cat", age: 18} // Text1不会刷新，原因是没有装饰器修饰监听不到值的改变。
          this.info2 = { name: "Cat", age: 18} // Text2会刷新，原因是有装饰器修饰，可以监听到值的改变。
          this.label1 = "Luck"; // 不会刷新，原因是没有装饰器修饰监听不到值的改变。
          this.label2 = "Luck"; // 会刷新，原因是有装饰器修饰，可以监听到值的改变。
        })
    }
  }
}
```

## 错误场景

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  @Builder buildTest() {
    Row() {
      Text('Hello, world')
        .fontSize(30)
    }
  }

  build() {
    Row() {
      Child()
    }
  }
}

@Component
struct Child {
  @Builder buildFunction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  // 使用@Require必须构造时传参。
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
  @Require @BuilderParam initBuildTest: () => void = this.buildFunction;
  @Require @Prop initMessage: string = 'Hello';

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      this.initBuildTest();
    }
  }
}
```

