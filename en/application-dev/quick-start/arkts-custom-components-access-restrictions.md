# Constraints on Access Modifiers of Custom Component Member Variables


In ArkTS, use of the access modifiers – **private**, **public**, and **protected** – for custom component member variables must comply with the constraints described in this topic. Build errors will be reported for any incompliance.


> **NOTE**
>
> The constraints on access modifiers of custom component member variables are supported since API version 12.


## Constraints

- For regular variables (which do not involve re-rendering) and variables decorated by \@State, \@Prop, \@Provide, or \@BuilderParam, when declared as **private**, value assignment is not allowed during custom component construction.

- For variables decorated by \@StorageLink, \@StorageProp, \@LocalStorageLink, \@LocalStorageProp, or \@Consume, **public** access is not allowed.

- For variables decorated by \@Link or \@ObjectLink, **private** access is not allowed.

- Because structs do not support inheritance, none of the preceding variables can be declared as **protected**.

- The regular variables (which do not involve re-rendering) and variables decorated by \@State, \@Prop, \@Provide, or \@BuilderParam in custom components cannot be decorated by both \@Require and **private**.


## Examples of Incorrect Usage

1. If a member variable is decorated by both the **private** access modifier and the \@State, \@Prop, \@Provide, or \@BuilderParam decorator, and is initialized through the parent component, a build error is reported.

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
  @State private state_value: string = "Hello";
  @Prop private prop_value: string = "Hello";
  @Provide private provide_value: string = "Hello";
  @BuilderParam private builder_value: () => void = this.buildTest;
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

2. If a member variable is decorated by both the **public** access modifier and the \@StorageLink, \@StorageProp, \@LocalStorageLink, \@LocalStorageProp, or \@Consume decorator, and is initialized through the parent component, a build error is reported.

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

The following are some build error examples:

```ts
Property 'local_prop_value' can not be decorated with both @LocalStorageProp and public.
Property 'local_link_value' can not be decorated with both @LocalStorageLink and public.
Property 'storage_prop_value' can not be decorated with both @StorageProp and public.
Property 'storage_link_value' can not be decorated with both @StorageLink and public.
Property 'consume_value' can not be decorated with both @Consume and public.
```

3. If a member variable is decorated by both the **private** access modifier and the \@Link/ or \@ObjectLink decorator, and is initialized through the parent component, a build error is reported.

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

The following are some build error examples:

```ts
Property 'link_value' can not be decorated with both @Link and private.
Property 'objectLink_value' can not be decorated with both @ObjectLink and private.
```

4. If a member variable is decorated by the **protected** access modifier and is initialized through the parent component, a build error is reported.

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

The following are some build error examples:

```ts
The member attributes of a struct can not be protected.
```

5. If a member variable is decorated by both the **private** access modifier and the \@Require, \@State, \@Prop, \@Provide, or \@BuilderParam decorator, and is initialized through the parent component, a build error is reported.

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

The following are some build error examples:

```ts
Property 'prop_value' can not be decorated with both @Require and private.
Property 'prop_value' is private and can not be initialized through the component constructor.
```
