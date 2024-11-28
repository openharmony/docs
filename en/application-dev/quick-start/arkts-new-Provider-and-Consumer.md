# \@Provider and \@Consumer Decorators: Synchronizing Across Component Levels in a Two-Way Manner

\@Provider and \@Consumer are used for synchronizing data across the component levels in a two-way manner, so that you are free from the constraints of the component levels.
\@Provider and \@Consumer are decorators in state management V2, so they can be used only in \@ComponentV2. A compilation error will be reported if they are used in \@Component.

>**NOTE**
>
>\@Provider and \@Consumer decorators are supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.

## Overview

\@Provider provides data. Its child components can use the \@Consumer to obtain the data by binding the same **key**.
\@Consumer obtains data. It can obtain the \@Provider data of the nearest parent node by binding the same **key**. If the \@Provider data cannot be found, the local default value will be used.
Data types decorated by \@Provider and \@Consumer must be the same.


The following notes must be paid attention to when using \@Provider and \@Consumer:
- \@Provider and \@Consumer strongly depend on the custom component levels. \@Consumer is initialized to different values because the parent component of the custom component is different.
- Using \@Provider with \@Consumer is equivalent to bonding components together. From the perspective of independent component, usage of \@Provider and \@Consumer should be lessened.


## Capability Comparison: \@Provider and \@Consumer Vs. \@Provide and \@Consume
In state management V1, [\@Provide and \@Consume](./arkts-provide-and-consume.md) are the decorators which provide two-way synchronization across component levels. This topic introduces \@Provider and \@Consumer decorators in state management V2. Although the names and features of the two pairs are similar, there are still some differences.
If you are not familiar with \@Provide and \@Consume in state management V1, please skip this section.

| Capability| \@Provider and \@Consumer Decorators of V2                                            |\@Provide and \@Consume Decorators of V1|
| ------------------ | ----------------------------------------------------- |----------------------------------------------------- |
| \@Consume(r)         |Local initialization is allowed. Local default value will be used when \@Provider is not found.| Local initialization is forbidden. An exception will be thrown when the \@Provide is not found.|
| Supported type          | **function** is supported.| **function** is not supported.|
| Observation capability          | Only the value change of itself can be observed. To observe the nesting scenario, use this decorator together with [\@Trace](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/arkts-new-observedV2-and-trace.md).| Changes at the first layer can be observed. To observe the nesting scenario, use this decorator together with [\@Observed and \@ObjectLink](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/arkts-observed-and-objectlink.md).|
| alias and attribute name        | **alias** is the unique matching **key** and the default attribute name.| If both the **alias** and attribute name are **key**, the former one is matched first. If no match is found, the attribute name can be matched.|
| \@Provide(r) initialization from the parent component     | Forbidden.| Allowed.|
| \@Provide(r) overloading support | Enabled by default. That is, \@Provider can have duplicate names and \@Consumer can search upwards for the nearest \@Provider.| Disabled by default. That is, \@Provide with duplicate names is not allowed in the component tree. If overloading is required, set **allowOverride**.|


## Decorator Description

### Basic Rules
\@Provider syntax:
@Provider(alias?: string) varName : varType = initValue

| \@Provider Property Decorator| Description                                                 |
| ------------------ | ----------------------------------------------------- |
| Decorator parameters        | **aliasName?: string**: alias. The default value is the attribute name.|
| Supported type          | Member variables in the custom component.<br>Property types include number, string, boolean, class, Array, Date, Map, and Set.<br>[Arrow function](#decorating-callback-by-using-provider-and-consumer-and-facilitating-behavior-abstraction-between-components). |
| Initialization from the parent component     | Forbidden.|
| Local initialization        | Required.|
| Observation capability        | Be equivalent to \@Trace. Changes will be synchronized to the corresponding \@Consumer.|

\@Consumer syntax:
@Consumer(alias?: string) varName : varType = initValue


| \@Consumer Property Decorator| Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Decorator parameters           | **aliasName?: string**: alias. The default value is the attribute name. The nearest \@Provider is searched upwards.   |
| Supported type | Member variables in the custom component.<br>Property types include number, string, boolean, class, Array, Date, Map, and Set.<br>Arrow function. |
| Initialization from the parent component     | Forbidden.|
| Local initialization        | Required.|
| Observation capability        | Be equivalent to \@Trace. Changes will be synchronized to the corresponding \@Provider.|

### aliasName and Attribute Name
\@Provider and \@Consumer accept the optional parameter **aliasName**. If the parameter is not set, the attribute name will be used as the default **aliasName** Note that **aliasName** is the unique key used to match \@Provider and \@Consumer.

The following three examples clearly describe how \@Provider and \@Consumer use **aliasName** for searching and matching.
```ts
@ComponentV2 struct Parent {
    @Provider() str: string = 'hello';   // no aliasName, use propertyName "str" as aliasName
}

@ComponentV2 struct Child {
    @Consumer('str') str: string = 'world';   // use aliasName 'str' to find
                                              // can find in Parent, use Provider value 'hello'
}
```

```ts
@ComponentV2 struct Parent {
    @Provider('alias') str: string = 'hello';   // has alias
}

@ComponentV2 struct Child {
    @Consumer('alias') str: string = 'world';   // use aliasName 'alias' to find Provider value 'hello'
}
```

```ts
@ComponentV2 struct Parent {
    @Provider('alias') str: string = 'hello';   // has alias
}

@ComponentV2 struct Child {
    @Consumer() str: string = 'world';   // no aliasName, use propertyName "str" as aliasName, cannot find Provider, so use the local value 'world'
}
```

## Constraints
1. \@Provider and \@Consumer are property decorators for custom components. They can only decorate the attributes of custom components and cannot decorate the class properties.
2. \@Provider and \@Consumer are decorators of the state management V2, which can be used only in \@ComponentV2 but not in \@Component.

## Use Scenarios

### Synchronizing \@Provider and \@Consumer in a Two-Way Manner
#### Establishing a Two-Way Binding
1. Initialize the **Parent** and **Child** custom components:
    - **@Consumer() str: string = 'world'** in the **Child** component searches upwards to find **@Provider() str: string = 'hello'** in the **Parent** component.
    - **@Consumer() str: string = 'world'** is initialized to the value of **@Provider**, that is, **'hello'**.
    - Both of them establish a two-way synchronization relationship.
2. Click the button in **Parent** to change the \@Provider decorated **str** and notify the corresponding \@Consumer to re-render the UI.
3. Click the button in **Child** to change the \@Consumer decorated **str**, and notify the corresponding \@Provider to re-render the UI.

```ts
@Entry
@ComponentV2
struct Parent {
  @Provider() str: string = 'hello';

  build() {
    Column() {
      Button(this.str)
        .onClick(() => {
          this.str += '0';
        })
      Child()
    }
  }
}

@ComponentV2
struct Child {
  @Consumer() str: string = 'world';

  build() {
    Column() {
      Button(this.str)
        .onClick(() => {
          this.str += '0';
        })
    }
  }
}
```
#### Establishing a Two-Way Binding Failed

In the following example, \@Provider and \@Consumer fail to establish a two-way synchronization relationship because of different **aliasName** value.
1. Initialize the **Parent** and **Child** custom components:
    - @Provider is not found when **@Consumer() str: string = 'world'** in the **Child** component searches upwards.
    - **@Consumer() str: string = 'world'** uses the local default value 'world'.
    - Both of them fail to establish a two-way synchronization relationship.
2. Click the button in the **Parent** component to change @Provider decorated **str1** and re-render only the **Button** component associated with @Provider.
3. Click the button in the **Child** component to change the @Consumer decorated **str** and re-render only the **Button** component associated with @Consumer.

```ts
@Entry
@ComponentV2
struct Parent {
  @Provider() str1: string = 'hello';

  build() {
    Column() {
      Button(this.str1)
        .onClick(() => {
          this.str1 += '0';
        })
      Child()
    }
  }
}

@ComponentV2
struct Child {
  @Consumer() str: string = 'world';

  build() {
    Column() {
      Button(this.str)
        .onClick(() => {
          this.str += '0';
        })
    }
  }
}
```

### Decorating Callback by Using @Provider and @Consumer and Facilitating Behavior Abstraction Between Components

To register a callback function for a child component in a parent component, you can use \@Provider and \@Consumer to decorate a callback.
For example, when a drag event occurs, if you want to synchronize the start position of the child component to the parent component, see the example below.

```ts
@Entry
@ComponentV2
struct Parent {
  @Local childX: number = 0;
  @Local childY: number = 1;
  @Provider() onDrag: (x: number, y: number) => void = (x: number, y: number) => {
    console.log(`onDrag event at x=${x} y:${y}`);
    this.childX = x;
    this.childY = y;
  }

  build() {
    Column() {
      Text(`child position x: ${this.childX}, y: ${this.childY}`)
      Child()
    }
  }
}

@ComponentV2
struct Child {
  @Consumer() onDrag: (x: number, y: number) => void = (x: number, y: number) => {};

  build() {
    Button("changed")
      .draggable(true)
      .onDragStart((event: DragEvent) => {
        // Current Previewer does not support common drag events.
        this.onDrag(event.getDisplayX(), event.getDisplayY());
      })
  }
}
```


### Decorating Complex Types by \@Provider and \@Consumer and Using together with \@Trace

1. \@Provider and \@Consumer can only observe the changes of the data. If they are used to decorate complex data types and you need to observe the changes of the properties, \@Trace is also required.
2. When decorating built-in types, such as Array, Map, Set, and Date, you can observe the changes of some APIs. The observation capability is the same as that of [\@Trace](./arkts-new-observedV2-and-trace.md#observed-changes).

```ts
@ObservedV2
class User {
  @Trace name: string;
  @Trace age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

const data: User[] = [new User('Json', 10), new User('Eric', 15)];

@Entry
@ComponentV2
struct Parent {
  @Provider('data') users: User[] = data;

  build() {
    Column() {
      Child()
      Button('add new user')
        .onClick(() => {
          this.users.push(new User('Molly', 18));
        })
      Button('age++')
        .onClick(() => {
          this.users[0].age++;
        })
      Button('change name')
        .onClick(() => {
          this.users[0].name = 'Shelly';
        })
    }
  }
}


@ComponentV2
struct Child {
  @Consumer('data') users: User[] = [];

  build() {
    Column() {
      ForEach(this.users, (item: User) => {
        Column() {
          Text(`name: ${item.name}`).fontSize(30)
          Text(`age: ${item.age}`).fontSize(30)
          Divider()
        }
      })
    }
  }
}
```

### Searching Upwards by \@Consumer for the Nearest \@Provider
If \@Provider has duplicate names in the component tree, \@Consumer will search upwards for the \@Provider data of the nearest parent node.
- In **AComp**, \@Consumer searches upwards to find **@Provider() val: number = 10** defined in the **Parent** component. Therefore, the value is initialized to 10.
- In **A1Comp**, \@Consumer searches upwards to find **@Provider() val: number = 20** defined in **AComp** and stops searching when it is found. Therefore, the value is initialized to 20.

```ts
@Entry
@ComponentV2
struct Parent {
  @Provider() val: number = 10;

  build() {
    Column() {
      AComp()
    }
  }
}

@ComponentV2
struct AComp {
  @Provider() val: number = 20;
  @Consumer("val") val2: number = 0; // 10

  build() {
    Column() {
      Text(`${this.val2}`)
      A1Comp()
    }
  }
}

@ComponentV2
struct A1Comp {
  @Consumer() val: number = 0; // 20

  build() {
      Text(`${this.val}`)
  }
}
```

### Initializing \@Param by \@Provider and \@Consumer
- Click **Text(\`@Consumer val: ${this.val}\`)** to trigger the change of **@Consumer() val**. This change will be synchronized to **@Provider() val** in the **Parent** component, triggering the re-render of the **Text(@Param val2: ${this.val2})** in the **Child** component.
- The change of **@Consumer() val** is also synchronized to **A1Comp**, triggering the re-render of **Text(A1Comp @Param val ${this.val})**.

```ts
@Entry
@ComponentV2
struct Parent {
  @Provider() val: number = 10;

  build() {
    Column() {
      AComp({ val2: this.val })
    }
  }
}

@ComponentV2
struct AComp {
  @Consumer() val: number = 0;
  @Param val2: number = 0;

  build() {
    Column() {
      Text(`AComp @Consumer val: ${this.val}`).fontSize(30).onClick(() => {
        this.val++;
      })
      Text(`AComp @Param val2: ${this.val2}`).fontSize(30)
      A1Comp({ val: this.val })
    }.border({ width: 2, color: Color.Green })
  }
}

@ComponentV2
struct A1Comp {
  @Param val: number = 0;

  build() {
    Column() {
      Text(`A1Comp @Param val ${this.val}`).fontSize(30)
    }.border({ width: 2, color: Color.Pink })
  }
}
```