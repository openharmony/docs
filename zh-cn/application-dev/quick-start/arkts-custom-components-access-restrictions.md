# 自定义组件成员属性访问限定符使用限制


ArkTS会对自定义组件的成员变量使用的访问限定符private/public/protected进行校验，当不按规范使用访问限定符private/public/protected时，会产生对应的日志信息。


> **说明：**
>
> 从API version 12开始，支持自定义组件成员属性访问限定符使用限制的规则。


## 使用限制

- 对于\@State/\@Prop/\@Provide/\@BuilderParam/常规成员变量(不涉及更新的普通变量)，当使用private修饰时，在自定义组件构造时，不允许进行赋值传参，否则会有编译告警日志提示。

- 对于\@StorageLink/\@StorageProp/\@LocalStorageLink/\@LocalStorageProp/\@Consume变量，当使用public修饰时，会有编译告警日志提示。

- 对于\@Link/\@ObjectLink变量，当使用private修饰时，会有编译告警日志提示。

- 由于struct没有继承能力，上述所有的这些变量使用protected修饰时，会有编译告警日志提示。

- 当\@Require和private同时修饰自定义组件struct的\@State/\@Prop/\@Provide/\@BuilderParam/常规成员变量(不涉及更新的普通变量)时，会有编译告警日志提示。


## 使用场景

1.当成员变量被private访问限定符和\@State/\@Prop/\@Provide/\@BuilderParam装饰器同时修饰，并且通过父组件进行初始化赋值，ArkTS会进行校验并产生告警日志。

【反例】
```ts
@Entry
@Component
struct AccessRestrictions {
  @Builder
  buildTest() {
    Text("Parent builder")
  }

  build() {
    Column() {
      ComponentsChild({
        state_value: "Hello",
        prop_value: "Hello",
        provide_value: "Hello",
        builder_value: this.buildTest,
        regular_value: "Hello"
      })
    }
    .width('100%')
  }
}

@Component
struct ComponentsChild {
  // 此处使用private修饰符时会出现告警日志
  @State private state_value: string = "Hello";
  // 此处使用private修饰符时会出现告警日志
  @Prop private prop_value: string = "Hello";
  // 此处使用private修饰符时会出现告警日志
  @Provide private provide_value: string = "Hello";
  // 此处使用private修饰符时会出现告警日志
  @BuilderParam private builder_value: () => void = this.buildTest;
  // 此处使用private修饰符时会出现告警日志
  private regular_value: string = "Hello";

  @Builder
  buildTest() {
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

编译告警日志如下：

```ts
Property 'state_value' is private and can not be initialized through the component constructor.
Property 'prop_value' is private and can not be initialized through the component constructor.
Property 'provide_value' is private and can not be initialized through the component constructor.
Property 'builder_value' is private and can not be initialized through the component constructor.
Property 'regular_value' is private and can not be initialized through the component constructor.
```

【正例】
```ts
@Entry
@Component
struct AccessRestrictions {
  @Builder
  buildTest() {
    Text("Parent builder")
  }

  build() {
    Column() {
      ComponentsChild({
        state_value: "Hello",
        prop_value: "Hello",
        provide_value: "Hello",
        builder_value: this.buildTest,
        regular_value: "Hello"
      })
    }
    .width('100%')
  }
}

@Component
struct ComponentsChild {
  @State state_value: string = "Hello";
  @Prop prop_value: string = "Hello";
  @Provide provide_value: string = "Hello";
  @BuilderParam builder_value: () => void = this.buildTest;
  regular_value: string = "Hello";

  @Builder
  buildTest() {
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

2.当成员变量被public访问限定符和\@StorageLink/\@StorageProp/\@LocalStorageLink/\@LocalStorageProp/\@Consume装饰器同时修饰，并且通过父组件进行初始化赋值，ArkTS会进行校验并产生告警日志。

【反例】
```ts
@Entry
@Component
struct AccessRestrictions {
  @Provide consume_value: string = "Hello";
  build() {
    Column() {
      ComponentChild()
    }
    .width('100%')
  }
}

@Component
struct ComponentChild {
  // 此处使用public修饰符时会出现告警日志
  @LocalStorageProp("sessionLocalProp") public local_prop_value: string = "Hello";
  // 此处使用public修饰符时会出现告警日志
  @LocalStorageLink("sessionLocalLink") public local_link_value: string = "Hello";
  // 此处使用public修饰符时会出现告警日志
  @StorageProp("sessionProp") public storage_prop_value: string = "Hello";
  // 此处使用public修饰符时会出现告警日志
  @StorageLink("sessionLink") public storage_link_value: string = "Hello";
  // 此处使用public修饰符时会出现告警日志
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

编译告警日志如下：

```ts
Property 'local_prop_value' can not be decorated with both @LocalStorageProp and public.
Property 'local_link_value' can not be decorated with both @LocalStorageLink and public.
Property 'storage_prop_value' can not be decorated with both @StorageProp and public.
Property 'storage_link_value' can not be decorated with both @StorageLink and public.
Property 'consume_value' can not be decorated with both @Consume and public.
```

【正例】
```ts
@Entry
@Component
struct AccessRestrictions {
  @Provide consume_value: string = "Hello";
  build() {
    Column() {
      ComponentChild()
    }
    .width('100%')
  }
}

@Component
struct ComponentChild {
  @LocalStorageProp("sessionLocalProp") local_prop_value: string = "Hello";
  @LocalStorageLink("sessionLocalLink") local_link_value: string = "Hello";
  @StorageProp("sessionProp") storage_prop_value: string = "Hello";
  @StorageLink("sessionLink") storage_link_value: string = "Hello";
  @Consume consume_value: string;
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

3.当成员变量被private访问限定符和\@Link/\@ObjectLink装饰器同时修饰，并且通过父组件进行初始化赋值，ArkTS会进行校验并产生告警日志。

【反例】
```ts
@Entry
@Component
struct AccessRestrictions {
  @State link_value: string = "Hello";
  @State objectLink_value: ComponentObj = new ComponentObj();
  build() {
    Column() {
      ComponentChild({link_value: this.link_value, objectLink_value: this.objectLink_value})
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
  // 此处使用private修饰符时会出现告警日志
  @Link private link_value: string;
  // 此处使用private修饰符时会出现告警日志
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

编译告警日志如下：

```ts
Property 'link_value' can not be decorated with both @Link and private.
Property 'objectLink_value' can not be decorated with both @ObjectLink and private.
```

【正例】
```ts
@Entry
@Component
struct AccessRestrictions {
  @State link_value: string = "Hello";
  @State objectLink_value: ComponentObj = new ComponentObj();
  build() {
    Column() {
      ComponentChild({link_value: this.link_value, objectLink_value: this.objectLink_value})
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
  @Link link_value: string;
  @ObjectLink objectLink_value: ComponentObj;
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

4.当成员变量被protected访问限定符修饰，并且通过父组件进行初始化赋值，ArkTS会进行校验并产生告警日志。

【反例】
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
  // 此处使用protected修饰符时会出现告警日志
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

编译告警日志如下：

```ts
The member attributes of a struct can not be protected.
```

【正例】
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
  regular_value: string = "Hello";
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

5.当成员变量被private访问限定符、\@Require和\@State/\@Prop/\@Provide/\@BuilderParam装饰器同时修饰，并且通过父组件进行初始化赋值，ArkTS会进行校验并产生告警日志。

【反例】
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
  // 此处使用private修饰符时会出现告警日志
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

编译告警日志如下：

```ts
Property 'prop_value' can not be decorated with both @Require and private.
Property 'prop_value' is private and can not be initialized through the component constructor.
```

【正例】
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
  @Require @Prop prop_value: string = "Hello";
  build() {
    Column() {
      Text("Hello")
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```
