# ArkUI Subsystem Changelog

## cl.arkui.1 Validation Changes for the @Require Decorator on Regular Variables and @State or @Provide Decorated Variables

**Access Level**

Public API

**Reason for Change**

Enhancements to the @Require decorator are made to include value assignment verification for regular variables and \@State or \@Provide decorated variables.

**Change Impact**

Before change: @Require only supports the verification for @Prop and @BuilderParam decorators.

After change: @Require supports the verification for regular variables and @Prop, @BuilderParam, @State, or @Provide decorated variables.

The following is an example of incorrect code:

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
  // As @Require is used here, parameters must be passed in to the constructor.
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

Below is an example of correct usage:
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
  @Require regular_value: string = 'Hello';
  @Require @State state_value: string = "Hello";
  @Require @Provide provide_value: string = "Hello";
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

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.12

**Adaptation Guide**

Adjust the @Require variable values based on the provided error messages.

**Reference**

[\@Require Decorator: Validating Constructor Input Parameters](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/arkts-require.md)


## cl.arkui.2 Restrictions on Using Access Qualifiers for Custom Component Member Properties

**Access Level**

Public API

**Reason for Change**

To enforce proper use of access qualifiers (**private**, **public**, and **protected**) in accordance with specifications, compilation verification is required.

**Change Impact**

The console outputs warning logs when incorrect usage is detected.

The following is an example of incorrect usage:

1. When a member variable is decorated by both the **private** access qualifier and the @State, @Prop, @Provide, or @BuilderParam decorator, the parent component **AccessRestrictions** uses the custom component **ComponentsChild** to construct and assign values. However, **ComponentsChild**'s private attributes do not support external construction and assignment. Therefore, ArkTS generates a warning log.

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

2. Member variables decorated by @StorageLink, @StorageProp, @LocalStorageLink, or @Consume can only be modified by private members. Therefore, when they are decorated by the **private** access qualifier, ArkTS generates a warning log.

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

3. The @Link or @ObjectLink decorated variables can only be initialized from the parent components. Therefore, when they are decorated by the **private** access qualifier, ArkTS generates a warning log.

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

4. Custom components do not support inheritance. Therefore, when they are decorated by the **protected** access qualifier, ArkTS generates a warning log.

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

5. The @Require decorator requires external construction and assignment, which is not supported for private members. Therefore, when a member variable is decorated by the **private** access qualifier, the @Require decorator, and the @State, @Prop, @Provide, or @BuilderParam decorator, ArkTS generates a warning log.

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

12

**Change Since**

OpenHarmony SDK 5.0.0.12

**Adaptation Guide**

Adjust the use of access qualifiers based on the provided error messages.

**Reference**

[Constraints on Access Modifiers of Custom Component Member Variables](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/arkts-custom-components-access-restrictions.md)


6. The **onFrame**, **onFinish**, **onCancel**, and **onRepeat** APIs in **AnimatorResult** do not adhere to syntax specifications.

**API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.12

**Adaptation Guide**

For inheritence from **AnimatorResult**, implement the **onFrame**, **onFinish**, **onCancel**, and **onRepeat** APIs.

**Reference**

[@ohos.animator (Animator)](../../../application-dev/reference/apis-arkui/js-apis-animator.md)
