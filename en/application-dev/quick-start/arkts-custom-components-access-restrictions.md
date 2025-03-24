# Constraints on Access Modifiers of Custom Component Member Variables

In state management V1, after you encapsulates a custom component, the caller cannot determine the input variables as the component input parameters based on the unified standard because the component does not have specific input and output identifiers.

To prevent a state variable from being initialized externally, you can use the **private** qualifier to remind the component caller. However, external initialization must comply with the rules of the decorator. For details, see [Constraints](#constraints).

In ArkTS, use of the access modifiers – **private**, **public**, and **protected** – for custom component member variables must comply with the constraints described in this topic. Build errors will be reported for any incompliance.

Before reading this topic, you are advised to read [State Management Overview](./arkts-state-management-overview.md).

> **NOTE**
>
> The constraints on access modifiers of custom component member variables are supported since API version 12.


## Constraints

- The regular variables (which do not involve re-rendering) and variables decorated by [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), [\@Provide](./arkts-provide-and-consume.md), or [\@BuilderParam](./arkts-builderparam.md) can be initialized externally or using local values. However, **private** access is not allowed.

- Variables decorated by [\@StorageLink](./arkts-appstorage.md), [\@StorageProp](./arkts-appstorage.md), [\@LocalStorageLink](./arkts-localstorage.md), [\@LocalStorageProp](./arkts-localstorage.md), or [\@Consume](./arkts-provide-and-consume.md) cannot be initialized externally. Therefore, **public** access is not allowed.

- Variables decorated by [\@Link](./arkts-link.md) or [\@ObjectLink](./arkts-observed-and-objectlink.md) must be initialized externally and local initialization is prohibited. Therefore, **private** access is not allowed.

- Because structs do not support inheritance, none of the preceding variables can be declared as **protected**.

- Variables decorated by [\@Require](./arkts-require.md) must be initialized externally. Therefore, using \@Require and **private** together to decorate regular variables (which do not involve re-rendering) and variables decorated by [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), [\@Provide](./arkts-provide-and-consume.md), or [\@BuilderParam](./arkts-builderparam.md) is not allowed.


## Use Scenarios

1. If a member variable is decorated by both **private** and the \@State, \@Prop, \@Provide, or \@BuilderParam decorator, and is initialized through the parent component, a build error is reported.

[Negative Example]
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
  // The private access is not allowed and an alarm is reported.
  @State private state_value: string = "Hello";
  // The private access is not allowed and an alarm is reported.
  @Prop private prop_value: string = "Hello";
  // The private access is not allowed and an alarm is reported.
  @Provide private provide_value: string = "Hello";
  // The private access is not allowed and an alarm is reported.
  @BuilderParam private builder_value: () => void = this.buildTest;
  // The private access is not allowed and an alarm is reported.
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

The following are some build error examples:

```ts
Property 'state_value' is private and can not be initialized through the component constructor.
Property 'prop_value' is private and can not be initialized through the component constructor.
Property 'provide_value' is private and can not be initialized through the component constructor.
Property 'builder_value' is private and can not be initialized through the component constructor.
Property 'regular_value' is private and can not be initialized through the component constructor.
```

[Positive Example]
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

2. If a member variable is decorated by both the **public** access modifier and the \@StorageLink, \@StorageProp, \@LocalStorageLink, \@LocalStorageProp, or \@Consume decorator, and is initialized through the parent component, a build error is reported.

[Negative Example]
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
  // The public access is not allowed and an alarm is reported.
  @LocalStorageProp("sessionLocalProp") public local_prop_value: string = "Hello";
  // The public access is not allowed and an alarm is reported.
  @LocalStorageLink("sessionLocalLink") public local_link_value: string = "Hello";
  // The public access is not allowed and an alarm is reported.
  @StorageProp("sessionProp") public storage_prop_value: string = "Hello";
  // The public access is not allowed and an alarm is reported.
  @StorageLink("sessionLink") public storage_link_value: string = "Hello";
  // The public access is not allowed and an alarm is reported.
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

The following are some build error examples:

```ts
Property 'local_prop_value' can not be decorated with both @LocalStorageProp and public.
Property 'local_link_value' can not be decorated with both @LocalStorageLink and public.
Property 'storage_prop_value' can not be decorated with both @StorageProp and public.
Property 'storage_link_value' can not be decorated with both @StorageLink and public.
Property 'consume_value' can not be decorated with both @Consume and public.
```

[Positive Example]
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

3. If a member variable is decorated by both the **private** access modifier and the \@Link/ or \@ObjectLink decorator, and is initialized through the parent component, a build error is reported.

[Negative Example]
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
  // The private access is not allowed and an alarm is reported.
  @Link private link_value: string;
  // The private access is not allowed and an alarm is reported.
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

The following are some build error examples:

```ts
Property 'link_value' can not be decorated with both @Link and private.
Property 'objectLink_value' can not be decorated with both @ObjectLink and private.
```

[Positive Example]
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

4. If a member variable is decorated by the **protected** access modifier and is initialized through the parent component, a build error is reported.

[Negative Example]
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
  // The protected access is not allowed and an alarm is reported.
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

The following are some build error examples:

```ts
The member attributes of a struct can not be protected.
```

[Positive Example]
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

5. If a member variable is decorated by both the **private** access modifier and the \@Require, \@State, \@Prop, \@Provide, or \@BuilderParam decorator, and is initialized through the parent component, a build error is reported.

[Negative Example]
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
  // The private access is not allowed and an alarm is reported.
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

The following are some build error examples:

```ts
Property 'prop_value' can not be decorated with both @Require and private.
Property 'prop_value' is private and can not be initialized through the component constructor.
```

[Positive Example]
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
