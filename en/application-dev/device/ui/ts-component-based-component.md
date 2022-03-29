# @Component


A struct decorated by @Component has the componentization capability and can serve as an independent component. This type of component is also called a custom component, and its UI structure is described in the build method. Custom components have the following features:


- Composability: Custom components can be used with preset or other components, as well as common attributes and methods.

- Reusable: Custom components can be reused by other components and used as different instances in different parent components or containers.

- Lifecycle: Custom components provide callbacks for service logic processing throughout the lifecycle.

- Data-driven update: The UI of custom components can be automatically updated based on the data of state variables.


For details about componentization, see [About @Component](ts-function-build.md).


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> - The build method must be defined for a custom component.
> 
> - Custom constructors are prohibited for custom components.


The following code illustrates how to create a custom component named MyComponent:

```
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


The build method of MyComponent is executed during initial rendering. When the component status changes, the build method will be executed again.


The following code illustrates how to use MyComponent:

```
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


MyComponent can be applied multiple times and reused in different components, as shown in the code below:

```
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

    private aboutToAppear() {
        console.log('ParentComponent: Just created, about to become rendered first time.')
    }

    private aboutToDisappear() {
        console.log('ParentComponent: About to be removed from the UI.')
    }
}
```
