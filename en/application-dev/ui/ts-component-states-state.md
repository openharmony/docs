# @State


The @State decorated variable is the internal state data of the component. When the state data is modified, the build method of the component is called to refresh the UI.


The @State data has the following features:


- Support for multiple types: The following types are supported: strong types by value and by reference, including class, number, boolean, string, as well as arrays of these types, that is, Array&lt;class&gt;, Array&lt;string&gt;, Array&lt;boolean&gt;, and Array&lt;number>. object and any are not allowed.

- Support for multiple instances: Multiple instances can coexist in a component. The internal state data of different instances is independent.

- Private: An attribute marked with @State can only be accessed within the component.

- Local initialization required: Initial values must be allocated to all @State decorated variables through the initialization process. Otherwise, they may become undefined in the framework.

- Support for setting of initial attribute values based on the state variable name: When creating a component instance, you can explicitly specify the initial value of the @State decorated attribute based on the variable name.


## Simple Example of @State Decorated Attribute


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


## Complex Example of @State Decorated Variable


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
            MyComponent({title: {value: 'Hello, World 2'}, count: 7})   // MyComponent2 in this document
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
            Text(`${this.title.value}`).fontSize(30)
            Button() {
                Text(`Click to change title`).fontSize(20).fontColor(Color.White)
            }.onClick(() => {
                this.title.value = (this.toggle == this.title.value) ? 'Hello World' : 'Hello UI'
            }) // Modify the internal state of MyComponent using the anonymous method.

            Button() {
                Text(`Click to increase count=${this.count}`).fontSize(20).fontColor(Color.White)
            }.onClick(() => {
                this.count += this.increaseBy
            }) // Modify the internal state of MyComponent using the anonymous method.
        }
    }
}
```


In the preceding example:


- Two @State decorated variables, count and title, have been defined for MyComponent. If the value of count or title changes, the build method of MyComponent needs to be called to render the component again.

- The EntryComponent has multiple MyComponent instances. The internal status change of the first MyComponent does not affect the second MyComponent.

- When creating a MyComponent instance, initialize the variables in the component based on the variable name. For example:
  
  ```
  MyComponent({title: {value: 'Hello, World 2'}, count: 7})
  ```
