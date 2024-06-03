# \@Require装饰器：校验构造传参


\@Require是校验\@Prop、\@State、\@Provide、\@BuilderParam和普通变量(无状态装饰器修饰的变量)是否需要构造传参的一个装饰器。


> **说明：**
>
> 从API version 11开始对\@Prop/\@BuilderParam进行校验。
>
> 从API version 12开始对\@State/\@Provide/普通变量(无状态装饰器修饰的变量)进行校验。
> 从API version 11开始，该装饰器支持在元服务中使用。


## 概述

当\@Require装饰器和\@Prop、\@State、\@Provide、\@BuilderParam、普通变量(无状态装饰器修饰的变量)结合使用时，在构造该自定义组件时，\@Prop、\@State、\@Provide、\@BuilderParam和普通变量(无状态装饰器修饰的变量)必须在构造时传参。

## 限制条件

\@Require装饰器仅用于装饰struct内的\@Prop、\@State、\@Provide、\@BuilderParam和普通变量(无状态装饰器修饰的变量)。

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
  @Builder buildFuction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
  @Require @BuilderParam buildTest: () => void;
  @Require @BuilderParam initBuildTest: () => void = this.buildFuction;
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
  @Builder buildFuction() {
    Column() {
      Text('initBuilderParam')
        .fontSize(30)
    }
  }
  // 使用@Require必须构造时传参。
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
  @Require @BuilderParam initBuildTest: () => void = this.buildFuction;
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

