# Overview of Other State Management Features
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:09:47.590Z pushedAt=2026-07-23T10:40:15.926Z -->

In addition to component-level and application-level state management, ArkTS also provides the following specialized state management features:

- [\@Watch decorator](arkts-watch.md): listens for the changes of state variables.

- [$$ operator](arkts-two-way-sync.md): creates two-way binding between TypeScript variables and built-in component states.

- [\@Track decorator](arkts-track.md): enables property-level updates for class objects. When a property decorated with \@Track changes, only the UI associated with that property is updated.

- [Component freezing](arkts-custom-components-freeze.md): suspends inactive components' state responsiveness.