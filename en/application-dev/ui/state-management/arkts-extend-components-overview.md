# Component Extension Overview
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

ArkUI provides a streamlined code solution through the @Builder decorator. This decorator not only simplifies UI development through modular encapsulation, but also extends to include @BuilderParam decorator, @LocalBuilder decorator, and wrapBuilder, forming a comprehensive system for reusable UI structures.

> **NOTE**
>
> The @Builder decorator serves as the foundation for @BuilderParam, @LocalBuilder, and wrapBuilder.

## @Builder Decorator

The [@Builder decorator](./arkts-builder.md) is specifically designed for creating modular, reusable UI structures. It prohibits the definition of state variables and invocation of component lifecycle methods within its scope, supporting only data interaction with callers through parameters.

## @LocalBuilder Decorator

When using @Builder for inter-component data transfer, note that component hierarchy relationships may conflict with state management parent-child relationships. To address this specific issue, the framework provides the [@LocalBuilder decorator](./arkts-localBuilder.md).

## @BuilderParam Decorator

When multiple scenarios share the same @Builder function but require scenario-specific extensions (similar to slot placeholder mechanisms), the [@BuilderParam decorator](./arkts-builderparam.md) can be used to receive and encapsulate @Builder functions.

## wrapBuilder

When pages contain multiple global @Builder functions with different UI structures, you may face significant maintenance challenges. The framework provides the [wrapBuilder](./arkts-wrapBuilder.md) mechanism to simplify code maintenance in such scenarios.
