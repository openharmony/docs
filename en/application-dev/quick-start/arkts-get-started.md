# Getting Started with ArkTS


ArkTS is the preferred main programming language for application development in OpenHarmony. ArkTS is based on the popular programming language [TypeScript](https://www.typescriptlang.org/) (TS for short). While maintaining the basic style of TS, ArkTS enforces type definitions to impose stricter static checks and analysis during development for higher execution stability and performance of applications.


Since API version 10, ArkTS further strengthens its static check and analysis in terms of the following aspects. For more details about the differences between standard TS and ArkTS, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md).


- Forced use of static types: Static typing is one of the most important features of ArkTS. With static typing, the types of variables in the program are definite. In addition, because all types are known at compile time, the compiler can verify the code correctness, thereby reducing the type check at run time and helping improve performance.

- Forbidden object layout at run time: To achieve maximum performance, ArkTS requires that the object layout remain unchanged during program execution.

- Restricted operator semantics: For performance and code readability purposes, ArkTS restricts the semantics of some operators. For example, it confines the use of unary plus operators to numbers.

- Structural typing not supported. The support for structural typing requires a lot of consideration and careful implementation in the language, compiler, and runtime. Currently, ArkTS does not support this feature. It may be supported in later versions depending on the requirements and feedback.


The added features offered by ArkTS for the ArkUI framework include the following:


- [Basic syntax](arkts-basic-syntax-overview.md): ArkTS defines declarative UI description, custom components, and dynamic extension of UI elements. All these, together with built-in components, event methods, and attribute methods in ArkUI, jointly underpin UI development.

- [State management](arkts-state-management-overview.md): In the multi-dimensional state management mechanism for ArkUI, UI-related data can be used not only within a component, but also be transferred between different component levels (for example, between parent and child components, between grandparent and grandchild components, or globally) in a device or even across devices. In addition, data transfer can be classified as one-way (read-only) or two-way (mutable). You can use these decorators at your disposal to implement linkage between data and the UI.

- [Rendering control](arkts-rendering-control-overview.md): ArkTS provides rendering control. Conditional rendering can render state-specific content based on the application state. **ForEach** iteratively obtains data from the data source and creates the corresponding component during each iteration. **LazyForEach** iterates over provided data sources and creates corresponding components during each iteration.


ArkTS is compatible with the TS and JavaScript (JS) ecosystem, so that you can write new code or reuse existing code in TS or JS for development. For details about how the OpenHarmony system supports TS or JS language, see [ARK Runtime Compatibility with TS/JS](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/arkts-migration-background.md#ark-runtime-compatibility-with-tsjs).


ArkTS will continue to accommodate ever-changing application development and running requirements, and gradually provides more features, such as enhanced parallelization and concurrency, improved system, and distributed development paradigm.

For a more detailed understanding of the ArkTS language, please refer to the [ArkTS Specific Guide](../arkts-utils/arkts-commonlibrary-overview.md).