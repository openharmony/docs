# \@ComponentV2 Decorator: Declaring a Custom Component
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

To enable V2 state variable decorator capabilities in custom components, you can use the @ComponentV2 decorator.

\@ComponentV2 is designed to work with state management V2. Before reading this topic, you are advised to read [State Management Overview](./arkts-state-management-overview.md).

>**NOTE**
>
> The \@ComponentV2 decorator is supported since API version 12.
>
> This decorator can be used in atomic services since API version 12.


## Overview

Similar to the [\@Component decorator](arkts-create-custom-components.md#component), the @ComponentV2 decorator is used for custom components.

- In custom components decorated with \@ComponentV2, only new state variable decorators can be used, including [\@Local](arkts-new-local.md), [\@Param](arkts-new-param.md), [\@Once](arkts-new-once.md), [\@Event](arkts-new-event.md), [\@Provider](arkts-new-Provider-and-Consumer.md), and [\@Consumer](arkts-new-Provider-and-Consumer.md).
- Custom components decorated with \@ComponentV2 do not support existing component capabilities such as [LocalStorage](arkts-localstorage.md).
- \@ComponentV2 and \@Component cannot be used to decorate the same struct.
- \@ComponentV2 can use an optional parameter **freezeWhenInactive** of the **boolean** type to implement [component freezing](arkts-custom-components-freezeV2.md).

- A simple \@ComponentV2 decorated custom component should contain the following parts:

    ```ts
    @ComponentV2 // Decorator
    struct Index { // Struct-declared data structure
      build() { // UI defined in build
      }
    }
    ```

Unless otherwise specified, a custom component decorated with \@ComponentV2 maintains the same behavior as a custom component decorated with \@Component.

## Constraints

For details about how to mix \@Component decorated custom components with \@ComponentV2 decorated custom components, see [Mixing Use of Custom Components](./arkts-custom-component-mixed-scenarios.md).
