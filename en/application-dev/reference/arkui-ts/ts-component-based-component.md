# @Component<a name="EN-US_TOPIC_0000001157388849"></a>

A struct annotated by  **@Component**  has the component-based capability and can function an independent component. This type of component is also called a custom component.

This component can be combined with other components. It describes the UI structure by implementing the  **build**  method, which must comply with the API constraints of  **Builder**. The API definition is as follows:

```
interface Builder {
    build: () => void
}
```

Custom components have the following features:

-   **Composable:**  can be combined with preset or other components, as well as common attributes and methods.
-   **Reusable:**  can be reused by other components and used as different instances in different parent components or containers.
-   **With a lifecycle:**  provide lifecycle callbacks in the component for service logic processing.
-   **Data-driven update:**  enable the UI to be automatically updated based on the status data.

The component lifecycle mainly includes the  **aboutToAppear**  and  **aboutToDisappear**  callbacks. For details, see  [Custom Component Lifecycle Callbacks](ts-custom-component-lifecycle-callbacks.md).

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Components must comply with the preceding  **Builder**  API constraints. Other components are combined in declarative mode in the internal  **build**  method. The  **build**  method is called when a component is created or updated for the first time.
>-   Do not customize constructors for components.

## Example<a name="section84921442616"></a>

The following code defines the  **MyComponent**  component:

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

The  **build**  method of  **MyComponent**  is executed during initial rendering. In addition, when the component status changes, the  **build**  method is executed again.

The following code uses the  **MyComponent**  component:

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

**MyComponent**  can be embedded multiple times into different components for reuse.

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

