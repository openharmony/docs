# \@ComponentV2 Decorator: Custom Component

To use the capability of the state variable decorator V2 in a custom component, you can use the \@ComponentV2 Decorator to decorate the custom component.

>**NOTE**
>
>The \@ComponentV2 decorator is supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.


## Overview

Similar to [\@Component Decorator](arkts-create-custom-components.md), the \@ComponentV2 decorator is used to decorate custom components.

- In the custom component decorated by \@ComponentV2, only new state variable decorators can be used, including \@Local, \@Param, \@Once, \@Event, \@Provider, and \@Consumer.
- Custom components decorated by \@ComponentV2 do not support component reuse, freezing, and LocalStorage.
- \@ComponentV2 and \@Component cannot be used to decorate the same struct.

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

When a custom component decorated by \@Component is used together with a custom component decorated by \@ComponentV2, variable is not allowed to pass in the following cases:

- Pass Common Variables Between \@Component and \@ComponentV2

- Pass the variables decorated by \@State, \@Prop, \@Link, \@ObjectLink, \@Provide, \@Consume, \@StorageLink, \@StorageProp, \@LocalStorageLink, and \@LocalStorageProp to the custom component decorated by \@ComponentV2.
- Pass the variables decorated by \@Local, \@Param, \@Event, \@Provider, and \@Consumer to the custom component decorated by \@Component.
