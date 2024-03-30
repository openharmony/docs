# ArkUI子系统变更说明

## cl.arkui.1 @Require装饰器增加对@State/@Provide/普通变量(无状态装饰器修饰的变量)校验的变更

**访问级别**

公开接口

**变更原因**

开发者提出，当使用@Require修饰@State/@Provide/常规成员变量时，需要进行构造赋值校验。

**变更影响**

变更前：@Require支持校验的装饰器有@Prop和@BuilderParam。

变更后：@Require支持校验的装饰器有@Prop、@BuilderParam、@State、@Provide和普通变量(无状态装饰器修饰的变量)。

错误示例如下：

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

**起始API Level**

起始支持版本为 API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.12开始。

**适配指导**

开发者需要根据告警提示信息，对@Require变量的赋值进行适配整改。 


## cl.arkui.2 编译转换增加对自定义组件成员属性访问限定符的使用限制

**访问级别**

公开接口

**增加原因**

开发者提出，当不按规范使用访问限定符private/public/protected时，需要进行编译校验。

**增加影响**

控制台输出告警日志信息。

错误使用示例如下：

1.当成员变量被private访问限定符和@State/@Prop/@Provide/@BuilderParam装饰器同时修饰时，ArkTS会进行校验并产生告警日志。

```ts
@Entry
@Component
struct AccessRestrictions {
  @Builder buildTest() {
    Text("Parent builder")
  }
  build() {
    Column() {
      ComponentsChild({state_value: "Hello", prop_value: "Hello", provide_value: "Hello", builder_value: this.buildTest, regular_value: "Hello"})
    }
    .width('100%')
  }
}

@Component
struct ComponentsChild {
  @State private state_value: string = "Hello";
  @Prop private prop_value: string = "Hello";
  @Provide private provide_value: string = "Hello";
  @BuilderParam private builder_value: () => void = this.buildTest;
  private regular_value: string = "Hello";
  @Builder buildTest() {
    Text("Child builder")
  }
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

2.当成员变量被public访问限定符和@StorageLink/@StorageProp/@LocalStorageLink/@LocalStorageLink/@Consume装饰器同时修饰时，ArkTS会进行校验并产生告警日志。

```ts
@Entry
@Component
struct AccessRestrictions {
  build() {
    Column() {
      ComponentChild()
    }
    .width('100%')
  }
}

@Component
struct ComponentChild {
  @LocalStorageProp("sessionLocalProp") public local_prop_value: string = "Hello";
  @LocalStorageLink("sessionLocalLink") public local_link_value: string = "Hello";
  @StorageProp("sessionProp") public storage_prop_value: string = "Hello";
  @StorageLink("sessionLink") public storage_link_value: string = "Hello";
  @Consume public consume_value: string;
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

3.当成员变量被private访问限定符和@Link/@ObjectLink装饰器同时修饰时，ArkTS会进行校验并产生告警日志。

```ts
@Entry
@Component
struct AccessRestrictions {
  build() {
    Column() {
      ComponentChild({link_value: "Hello", objectLink_value: new ComponentObj()})
    }
    .width('100%')
  }
}

@Observed
class ComponentObj {
  count: number = 0;
}
@Component
struct ComponentChild {
  @Link private link_value: string;
  @ObjectLink private objectLink_value: ComponentObj;
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

4.当成员变量被protected访问限定符修饰时，ArkTS会进行校验并产生告警日志。

```ts
@Entry
@Component
struct AccessRestrictions {
  build() {
    Column() {
      ComponentChild({regular_value: "Hello"})
    }
    .width('100%')
  }
}

@Component
struct ComponentChild {
  protected regular_value: string = "Hello";
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

5.当成员变量被private访问限定符、@Require和@State/@Prop/@Provide/@BuilderParam装饰器同时修饰时，ArkTS会进行校验并产生告警日志。

```ts
@Entry
@Component
struct AccessRestrictions {
  build() {
    Column() {
      ComponentChild({prop_value: "Hello"})
    }
    .width('100%')
  }
}
@Component
struct ComponentChild {
  @Require @Prop private prop_value: string = "Hello";
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

**API Level**

起始支持版本为 API 12。

**增加发生版本**

从OpenHarmony SDK 5.0.0.12开始。

**适配指导**

开发者需要根据告警提示信息，对使用访问限定符的位置进行适配整改。