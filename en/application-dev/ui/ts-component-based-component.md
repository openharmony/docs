# @Component

A struct decorated by **@Component** has the componentization capability and can serve as an independent component. This type of component is also called a custom component, and its UI structure is described in the **build** method. Custom components have the following features:


- Composability: Custom components can be used with preset or other components, as well as common attributes and methods.
- Chain call<sup>9+</sup>: Universal attributes can be invoked in chain call mode to change the component style.
- Reusable: Custom components can be reused by other components and used as different instances in different parent components or containers.
- Lifecycle: Custom components provide callbacks for service logic processing throughout the lifecycle.
- Data-driven update: The UI of custom components can be automatically updated based on the data of state variables.


For details about componentization, see [About @Component](ts-custom-component-initialization.md).


>  **NOTE**
>
>  - The **build** method must be defined for a custom component.
>- Custom constructors are prohibited for custom components.


The following code illustrates how to create a custom component named **MyComponent**:


```ts
@Component
struct MyComponent {
    build() {
        Column() {
            Text('my component')
                .fontColor(Color.Red)
        }.alignItems(HorizontalAlign.Center) // center align Text inside Column
    }
}
```


The **build** method of **MyComponent** is executed during initial rendering. When the component status changes, the **build** method will be executed again.


The following code illustrates how to use **MyComponent**:


```ts
@Component
struct ParentComponent {
    build() {
        Column() {
            MyComponent()
            Text('we use component')
                .fontSize(20)
        }
    }
}
```


**MyComponent** can be applied multiple times and reused in different components, as shown in the code below:


```ts
@Component
struct ParentComponent {
    build() {
        Row() {
            Column() {
                MyComponent()
                Text('first column')
                    .fontSize(20)
            }
            Column() {
                MyComponent()
                Text('second column')
                    .fontSize(20)
            }
        }
    }

    aboutToAppear() {
        console.log('ParentComponent: Just created, about to become rendered first time.')
    }

    aboutToDisappear() {
        console.log('ParentComponent: About to be removed from the UI.')
    }
}
```

Universal attributes can be invoked in chain call mode to diversify component styles.

> **NOTE**
>
> This feature is supported since API version 9.
>
> The chain call for custom components does not support trailing closures in the following scenario: When the custom component is initialized, the component name is followed by a pair of braces ({}) to form a trailing closure (as in `Index(){}`). You can consider a trailing closure as a container and add content to it, as in `{Column(){Text("content")}`.

```ts
@Entry
@Component
struct Index {
  @State bannerValue: string = 'Hello,world';
  build() {
    Column() {
      Chind({ ChindBannerValue:$bannerValue })
      .height(60)
      .width(250)
      .border({ width:5, color:Color.Red, radius:10, style: BorderStyle.Dotted })
    }
  }
}

@Component
struct Chind {
  @Link ChindBannerValue: string;
  build() {
    Column() {
      Text(this.ChindBannerValue)
      .fontSize(30)
    }
  }
}
```
