# Basic Concepts<a name="EN-US_TOPIC_0000001169868220"></a>

In the declarative UI programming paradigm, the UI is a function of an application state, and you update a UI by modifying the current application state.

The development framework provides various application state management capabilities.

![](figures/corespec_figures_state-mgmt-overview.png)

## State Variable Decorators<a name="section13236174803615"></a>

-   **@State**: state attribute of the component. Each time the  **@State**  annotated variable changes, the component re-renders and updates the UI.
-   **@Link**: The component depends on some state attributes of its parent component. Each time the data in one component is updated, the state of the other component is updated, and the parent and child components are rendered again.
-   **@Prop**: The working principle is similar to that of  **@Link**. The only difference is that the changes made by a child component are not synchronized to the parent component.

## Application State Data<a name="section16386143212559"></a>

**AppStorage**  is the central "database" of the application states used in the entire UI. The UI framework creates a singleton  **AppStorage**  object for the application and provides the corresponding decorators and APIs for the application.

-   **@StorageLink**: The working principle of  **@StorageLink\(_name_\)**  is similar to that of  **@Consume\(_name_\)**. The difference is that the link object with the specified name is obtained from the  **AppStorage**. It establishes bidirectional binding between the UI component and  **AppStorage**  to synchronize data.
-   **@StorageProp**:  **@StorageProp\(_name_\)**  synchronizes UI component attributes with the  **AppStorage**  unidirectionally. The value change in the  **AppStorage**  updates the attribute value in the component, but the UI component cannot change the attribute value in the  **AppStorage**.
-   The  **AppStorage**  also provides an API for service logic implementation. The API is used to add, read, modify, and delete the state attributes of applications. The changes made through this API will cause the modified state data to be synchronized to the UI component for UI update.

