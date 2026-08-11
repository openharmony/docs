# State Management Terms

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zany_pink-->
<!--Designer: @zhangboren-->
<!--Tester: @zhangwenhan12-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=62b5c3450a87bdc5e575e58aa760685da7a65e8a translatedAt=2026-07-01T11:08:28.009Z pushedAt=2026-07-02T02:48:11.229Z -->

## A

### Attribute-Level Updates

A mechanism in the state management framework that uses class property decorators to precisely observe properties of class objects. When an attribute changes, only the component bound to that property is refreshed, avoiding cascading refreshes of components associated with unchanged properties, thereby improving UI update performance.

## D

### Deep Monitor

The listening capability provided by the \@Monitor decorator in state management V2, which can recursively listen to changes in all nested attributes of an object or array. It is suitable for scenarios with multi-level nested class objects, where a change at any attribute level triggers the listening callback.

### Deep Observation

The observation capability achieved through the combined use of the @ObservedV2 and @Trace decorators in state management V2. It can recursively observe changes to all nested properties of an object or array. Unlike the one‑level observation in state management V1, deep observation triggers UI refreshes when any property changes at any level.

## L

### Local Initialization

Assigning a value directly as the default value when declaring a variable. This provides the initial value for a state variable when initialization data cannot be obtained externally, ensuring that the component can render normally without external data input.

## M

### Mark Dirty

A mechanism where the framework marks the system components that depend on a state variable and the owning custom component as "dirty" when the state variable changes. In subsequent UI rendering, only the dirty nodes are refreshed, avoiding a full refresh and achieving minimum updates.

### Minimum Updates

An optimization strategy of the UI framework that ensures only the parts that have actually changed are updated. That is, only the system components bound to the changed state variables are refreshed, avoiding unnecessary rendering operations and improving UI refresh efficiency.

## N

### Named Parameter Mechanism

A method where the parent component passes data to the child component's state variables by specifying parameter names. This is the primary means of data transfer between parent and child components, explicitly specifying the data items to be transferred to achieve inter-component data communication.

## O

### One-Layer Monitor

The listening capability of the \@Watch decorator in state management V1, which can only listen to changes in the first-layer attributes of an object or array and cannot recursively listen to nested attributes. It is suitable for state listening scenarios involving simple data structures.

### One-Layer Observation

The observation capability of state management V1, which can only observe changes in the first-layer attributes of state variables decorated by V1 decorators such as @State and @Prop, and cannot recursively observe deeply nested attributes.

### One-Way Sync

A data synchronization method where data flows in a single direction, typically from a parent component to a child component. The child component can receive data from the parent component but cannot directly modify the parent component's data source, keeping the data flow clear and avoiding data chaos.

## R

### Record Dependency

A fundamental process of state management, referring to establishing a data binding relationship between a state variable and a component. During UI rendering, the state management framework observes which state variables are read and records the dependency relationships, so that when a state variable is modified, only the components related to that state variable undergo a UI refresh.

### Reference Transmission

A mechanism that transfers the variable itself during a function call or variable assignment, including the logic for collecting dependencies and triggering updates. Unlike value transmission, reference transmission retains the state management capability of the data, making it suitable for scenarios requiring synchronized updates.

### Regular Variable

A variable that is not decorated by a state decorator, typically used for auxiliary calculations or temporary storage. Its changes do not trigger UI refreshes, and it does not possess state management capabilities.

### Render Phase

A phase in the state management update triggering process. After components are marked as dirty, this is the process of refreshing the UI when the next frame signal arrives. The framework traverses the list of dirty custom components, calls the **rerender** method to refresh dirty system components, and updates dependencies.

## S

### State Data Source

The original source of a state variable, which can be synchronized to different state data. It is generally the data passed from the parent component to a child component.

### State Variable

A variable decorated by a state decorator, which is the core concept of the state management framework. Changes to the value of a state variable trigger UI updates, enabling a data-driven UI.

## T

### Trigger Update

A fundamental process of state management. When a state variable changes, the framework notifies all UI components that depend on that variable to recalculate and refresh. It includes three steps: calculating the new value, modifying the state variable value and marking components dirty, and refreshing the dirty nodes.

### Trailing Lambda

A syntax feature of ArkTS in which, when a closure is the last parameter of a function, the closure expression can be placed outside the closing parentheses, enhancing readability and coding convenience.

### Two-Way Sync

A synchronization method where data flows in two directions, allowing parent and child components to modify data mutually. Modifications by the child component can be synchronized back to the parent component, and modifications by the parent component can be synchronized to the child component, enabling bidirectional data synchronization.

## V

### Value Transmission

A mechanism that transfers the value of a variable during a function call or variable assignment, which does not include the logic for collecting dependencies and triggering updates. The new variable after being passed does not possess state management capabilities, making it suitable for scenarios that do not require synchronized updates.

### View

The UI layer, responsible for user interface display and interaction. In the MVVM architecture, the View achieves dynamic updates by binding to data provided by the ViewModel and does not contain service logic.