# @State<a name="EN-US_TOPIC_0000001157228861"></a>

The  **@State**  annotated variable is the internal state data of the component. When the state data is modified, the** build**  method of the component is called to refresh the UI.

The  **@State**  data has the following features:

-   **Support for multiple types**: The following strong types by value and by reference are supported:  **class**,  **number**,  **boolean**,  **string**, and arrays of these types, that is,** Array<class\>**,  **Array<string\>**,  **Array<boolean\>**, and  **Array<number\>**.  **object**  and  **any**  are not allowed.
-   **Support for multi-instance**: The internal state data of different instances of a component is independent.
-   **Internal private**: Attributes marked with  **@State**  cannot be directly modified outside the component. Its lifecycle depends on the component where it is located.
-   **Local initialization required**: Initial values must be allocated to all  **@State**  annotated variables. Otherwise, they may become undefined in the framework.
-   **Can be used to set initial values for custom components**: When creating a component instance, you can explicitly specify the initial value of the  **@State**  annotated attribute based on the variable name.

## Simple Example of @State Annotated Attribute<a name="section1943814324316"></a>

```
@Entry
@Component
struct MyComponent {
    @State count: number = 0
    // MyComponent provides a method for modifying the @State status data member.
    private toggleClick() {
        this.count += 1
    }

    build() {
        Column() {
            Button() {
                Text(`click times: ${this.count}`)
                    .fontSize(10)
            }.onClick(this.toggleClick.bind(this))
        }
    }
}
```

## Complex Example of @State Annotated Variable<a name="section17881156184313"></a>

```
// Customize the status data class.
class Model {
    value: string
    constructor(value: string) {
        this.value = value
    }
}

@Entry
@Component
struct EntryComponent {
    build() {
        Column() {
            MyComponent({count: 1, increaseBy: 2})  // MyComponent1 in this document
            MyComponent({title: {value: 'Hello, World 2'}, count: 7})   //MyComponent2 in this document
        }
    }
}

@Component
struct MyComponent {
    @State title: Model = {value: 'Hello World'}
    @State count: number = 0
    private toggle: string = 'Hello World'
    private increaseBy: number = 1

    build() {
        Column() {
            Text(`${this.title.value}`)
            Button() {
                Text(`Click to change title`).fontSize(10)
            }.onClick(() => {
                this.title.value = this.toggle ? 'Hello World' : 'Hello UI'
            }) // Modify the internal state of MyComponent using the anonymous method.

            Button() {
                Text(`Click to increase count=${this.count}`).fontSize(10)
            }.onClick(() => {
                this.count += this.increaseBy
            }) // Modify the internal state of MyComponent using the anonymous method.
        }
    }
}
```

In the preceding example:

-   The custom component  **MyComponent**  defines the  **@State**  annotated variables  **count**  and  **title**. If the value of  **count**  or  **title**  changes, the  **build**  method of  **MyComponent**  is called to render the component again.
-   The  **EntryComponent**  has multiple  **MyComponent**  instances. The internal status change of the first  **MyComponent**  does not affect the second  **MyComponent**.
-   When creating a  **MyComponent**  instance, use the variable name to initialize the variables in the component. For example:

    ```
    MyComponent({title: {value: 'Hello, World 2'}, count: 7})
    ```


