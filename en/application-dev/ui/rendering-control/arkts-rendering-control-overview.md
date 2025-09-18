# Rendering Control Overview
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liubihao-->
<!--Designer: @lixingchi1-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->


ArkUI leverages two primary approaches for building UIs: the **build()** function of [custom components](arkts-create-custom-components.md) and declarative UI description statements in the [@Builder decorator](arkts-builder.md). In declarative description statements, you can use rendering control statements along with built-in components to accelerate UI construction. These rendering control statements include conditional statements that control component visibility, loop statements for repeated content that quickly generate components based on array data, lazy loading statements that optimize performance for scenarios involving large datasets, and component rendering statements that facilitate hybrid development.
