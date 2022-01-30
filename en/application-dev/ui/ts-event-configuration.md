# Event Configuration<a name="EN-US_TOPIC_0000001157388863"></a>

You can use event methods to configure events supported by components.

-   Example of using a lambda expression to configure the event of a component:

    ```
    // Counter is a private data variable defined in the component.
    Button('add counter')
        .onClick(() => {
            this.counter += 2
        })
    ```


-   Example of using an anonymous function expression to configure the event of a component:

    In this case,  **bind**  must be used to ensure that the contained components are referenced by  **this**  in the function body.

    ```
    // Counter is a private data variable defined in the component.
    Button('add counter')
        .onClick(function () {
            this.counter += 2
        }.bind(this))
    ```


-   Example of using a component's member function to configure the event of the component:

    ```
    myClickHandler(): void {
        // do something
    }
    
    ...
    
    Button('add counter')
      .onClick(this.myClickHandler)
    ```


