# Rendering Control Overview


ArkUI uses the **build()** function of [custom components](arkts-create-custom-components.md) and declarative UI description statements in the [@builder decorator](arkts-builder.md) to build the corresponding UI. In declarative description statements, you can use rendering control statements in addition to system components to accelerate UI construction. These rendering control statements include conditional statements that control whether components are displayed, rendering statements for repeated content that quickly generate components based on array data, and lazy loading statements for scenarios involving a large amount of data.
