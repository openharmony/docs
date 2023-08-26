# Getting Started with ArkTS


ArkTS is the preferred main programming language for application development in OpenHarmony. ArkTS maintains the basic style of [TypeScript](https://www.typescriptlang.org/) (TS for short). It is a static typing language. Some TS features are restricted for better performance.


The following syntaxes in TS are restricted in ArkTS:


- Static typing is enforced. Static typing is one of the most important features of ArkTS. If the program is statically typed, that is, all types are known at the compile time, it's much easier to understand which data structures are used in the code. At the same time, since all types are known before the program actually runs, code correctness can be verified by the compiler, which eliminates many runtime type checks and improves the performance.

- Changing object layout in runtime is prohibited. To achieve maximum performance benefits, ArkTS requires that layout of objects does not change during program execution.

- Semantics of operators is restricted. To achieve better performance and encourage developers to write cleaner code, ArkTS restricts the semantics of operators. For example, the binary `+` operator is supported for strings and numbers, but not for objects.

- Structural typing is not supported. Support for structural typing is a major feature that needs lots of consideration and careful implementation in language specification, compiler and runtime. Currently, ArkTS does not supports structural typing. The team will be ready to reconsider this feature based on real-world scenarios and feedback.


The added features offered by ArkTS for the ArkUI framework include the following:


- [Basic syntax](arkts-basic-syntax-overview.md): ArkTS defines declarative UI description, custom components, and dynamic extension of UI elements. All these, together with built-in components, event methods, and attribute methods in ArkUI, jointly underpin UI development.

- [State management](arkts-state-management-overview.md): In the multi-dimensional state management mechanism for ArkUI, UI-related data can be used not only within a component, but also be transferred between different component levels (for example, between parent and child components, between grandparent and grandchild components, or globally) in a device or even across devices. In addition, data transfer can be classified as one-way (read-only) or two-way (mutable). You can use these capabilities at your disposal to implement linkage between data and the UI.

- [Rendering control](arkts-rendering-control-overview.md): ArkTS provides rendering control. Conditional rendering can render state-specific content based on the application status. **ForEach** iteratively obtains data from the data source and creates the corresponding component during each iteration. **LazyForEach** iterates over provided data sources and creates corresponding components during each iteration.


ArkTS will continue to evolve to accommodate changing application development and running requirements, and gradually adds more features, such as parallelism and concurrency enhancement, typed system enhancement, and distributed development paradigm.
