# Overview of Other State Management Features
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

In addition to component-level and application-level state management, ArkTS also provides the following specialized state management features:

- [\@Watch decorator](arkts-watch.md): listens for the changes of state variables.

- [$$ operator](arkts-two-way-sync.md): creates two-way binding between TypeScript variables and built-in component states.

- [\@Track decorator](arkts-track.md): enables property-level updates for class objects. When a property decorated with \@Track changes, only the UI associated with that property is updated.

- [Component freezing](arkts-custom-components-freeze.md): suspends inactive components' state responsiveness.
