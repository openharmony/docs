# Getting Started with ArkTS


ArkTS is the preferred main programming language for application development in OpenHarmony. ArkTS is a superset of [TypeScript](https://www.typescriptlang.org/) (TS for short). It contains all TS features and added features. Before getting started with ArkTS, it would be helpful if you have experience with TS development.


The added features offered by ArkTS include the following:


- [Basic syntax](arkts-basic-syntax-overview.md): ArkTS defines declarative UI description, custom components, and dynamic extension of UI elements. All these, together with built-in components, event methods, and attribute methods in ArkUI, jointly underpin UI development.

- [State management](arkts-state-management-overview.md): In the multi-dimensional state management mechanism for ArkUI, UI-related data can be used not only within a component, but also be transferred between different component levels (for example, between parent and child components, between grandparent and grandchild components, or globally) in a device or even across devices. In addition, data transfer can be classified as one-way (read-only) or two-way (mutable). You can use these capabilities at your disposal to implement linkage between data and the UI.

- [Rendering control](arkts-rendering-control-overview.md): ArkTS provides rendering control. Conditional rendering can render state-specific content based on the application status. **ForEach** iteratively obtains data from the data source and creates the corresponding component during each iteration. **LazyForEach** iterates over provided data sources and creates corresponding components during each iteration.


ArkTS will continue to evolve to accommodate changing application development and running requirements, and gradually adds more features, such as parallelism and concurrency enhancement, typed system enhancement, and distributed development paradigm.
