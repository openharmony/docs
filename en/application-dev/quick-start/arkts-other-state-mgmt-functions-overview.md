# Overview of Other State Management Features


In addition to the component state and application state management mentioned in previous topics, ArkTS also provides \@Watch, $$ and \@Track for state management.


- [\@Watch](arkts-watch.md) listens for the changes of state variables.

- [$$operator](arkts-two-way-sync.md) provides a TS variable by-reference to a built-in component so that the variable value and the internal state of that component are kept in sync.

- [\@Track](arkts-track.md) applies to attribute-level updates of class objects. When a property decorated by \@Track changes, only the UI associated with the property is updated.

- [Freezing a Custom Component](arkts-custom-components-freeze.md) represents that the component is inactive and its state variable does not respond to updates.
