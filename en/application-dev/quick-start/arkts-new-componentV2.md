# \@ComponentV2 Decorator: Custom Component

To use the capability of the state variable decorator V2 in a custom component, you can use the \@ComponentV2 Decorator to decorate the custom component.

>**NOTE**
>
>The \@ComponentV2 decorator is supported since API version 12.
>


## Overview

Similar to [\@Component Decorator](arkts-create-custom-components.md), the \@ComponentV2 decorator is used to decorate custom components.

- In the custom component decorated by \@ComponentV2, only new state variable decorators can be used, including \@Local, \@Param, \@Once, \@Event, \@Provider, and \@Consumer.
- Custom components decorated by \@ComponentV2 do not support component reuse and LocalStorage.
- \@ComponentV2 and \@Component cannot be used to decorate the same struct.
- \@ComponentV2 can use an optional parameter **freezeWhenInactive** of the **boolean** type to implement the [component freezing](arkts-custom-components-freezeV2.md).

- A simple \@ComponentV2 decorated custom component should contain the following parts:

    ```ts
    @ComponentV2 // Decorator
    struct Index { // Data declared by the struct
      build() { // UI defined by build
      }
    }
    ```

Unless otherwise specified, a custom component decorated by \@ComponentV2 maintains the same behavior as a custom component decorated by \@Component.

## Constraints

For details about how to use the custom components decorated by \@Component and \@ComponentV2 together, see [Mixing Use of Custom Components](./arkts-custom-component-mixed-scenarios.md).
