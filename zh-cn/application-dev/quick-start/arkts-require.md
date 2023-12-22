# \@Require装饰器：校验构造传参


\@Require是校验\@Prop和\@BuilderParam是否需要构造传参的一个装饰器， \@Require装饰器不能单独使用。


> **说明：**
>
> 从API version 11开始使用。

## 概述

当\@Require装饰器和\@Prop或者\@BuilderParam结合使用时，在构造该自定义组件时，\@Prop和\@BuilderParam必须在构造时传参。\@Require是校验\@Prop或者\@BuilderParam是否需要构造传参的一个装饰器。

## 限制条件

 \@Require装饰器仅用于装饰struct内的\@Prop和\@BuilderParam成员状态变量。

## 使用场景

当Child组件内使用\@Require装饰器和\@Prop或者\@BuilderParam结合使用时，父组件Index在构造Child时必须传参，否则编译不通过。

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
      Child({ initMessage: this.message, message: this.message,
        buildTest: this.buildTest, initbuildTest: this.buildTest })
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

  @Require @BuilderParam buildTest: () => void;
  @Require @BuilderParam initbuildTest: () => void = this.buildFuction;
  @Require @Prop initMessage: string = 'Hello';
  @Require @Prop message: string;

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      Text(this.message)
        .fontSize(30)
      this.initbuildTest();
      this.buildTest();
    }
    .width('100%')
    .height('100%')
  }
}
```

 ![img](figures/9e2d58bc-b0e1-4613-934b-8e4237bd5c05.png) 

## 错误场景

```
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
  @Require @BuilderParam initbuildTest: () => void = this.buildFuction;
  @Require @Prop initMessage: string = 'Hello';

  build() {
    Column() {
      Text(this.initMessage)
        .fontSize(30)
      this.initbuildTest();
    }
  }
}
```

