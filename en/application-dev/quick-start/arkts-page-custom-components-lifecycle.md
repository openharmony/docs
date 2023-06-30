# Page and Custom Component Lifecycle


Before we dive into the page and custom component lifecycle, it would be helpful to learn the relationship between custom components and pages.


- Custom component: \@Component decorated UI unit, which can combine multiple built-in components for component reusability.

- Page: UI page of an application. A page can consist of one or more custom components. A custom component decorated with \@Entry is used as the default entry component of the page. Exactly one component can be decorated with \@Entry in a single source file. Only components decorated by \@Entry can call the lifecycle callbacks of a page.


The following lifecycle callbacks are provided for the lifecycle of a page, that is, the lifecycle of a custom component decorated with \@Entry:


- [onPageShow](../reference/arkui-ts/ts-custom-component-lifecycle.md#onpageshow): Invoked when the page is displayed.

- [onPageHide](../reference/arkui-ts/ts-custom-component-lifecycle.md#onpagehide): Invoked when the page is hidden.

- [onBackPress](../reference/arkui-ts/ts-custom-component-lifecycle.md#onbackpress): Invoked when the user clicks the Back button.


The following lifecycle callbacks are provided for the lifecycle of a component, that is, the lifecycle of a custom component decorated with \@Component:


- [aboutToAppear](../reference/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear): Invoked when the custom component is about to appear. Specifically, it is invoked after a new instance of the custom component is created and before its **build** function is executed.

- [aboutToDisappear](../reference/arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear): Invoked before the destructor of the custom component is consumed.


The following figure shows the lifecycle of a component (home page) decorated with \@Entry.


![en-us_image_0000001502372786](figures/en-us_image_0000001502372786.png)


Based on the preceding figure, let's look into the initial creation, re-rendering, and deletion of a custom component.


## Custom Component Creation and Rendering

1. Custom component creation: An instance of a custom component is created by the ArkUI framework.

2. Initialization of custom component member variables: The member variables are initialized with locally defined default values or component constructor parameters. The initialization happens in the document order, which is the order in which the member variables are defined.

3. If defined, the component's **aboutToAppear** callback is invoked.

4. On initial render, the **build** function of a component is executed for rendering. The rendering creates instances of further child components. While executing the **build** function, the framework observes read access on each state variable and then constructs two mapping tables:
   1. State variable -> UI component (including **ForEach** and **if**)
   2. UI component -> Update function for this component, which is a lambda. As a subset of the **build** function, the lambda creates one UI component and executes its attribute methods.


   ```ts
   build() {
     ...
     this.observeComponentCreation(() => {
       Button.create();
     })

     this.observeComponentCreation(() => {
       Text.create();
     })
     ...
   }
   ```


When the application is started in the background, since the application process is not destroyed, only the **onPageShow** callback is invoked.


## Custom Component Re-rendering

When an event handle is triggered (for example, the click event is triggered), the state variable of the component is changed, or the attribute in LocalStorage or AppStorage is changed, which causes the value of the linked state variable to be changed.


1. The framework observes the variable change and marks the component for re-rendering.

2. Using the two mapping tables created in step 4 of the custom component creation and rendering process, the framework knows which UI components are managed by the state variable and the update functions corresponding to these UI components. With this knowledge, the framework executes only the update functions of these UI components.


## Custom Component Deletion

A custom component is deleted when the branch of the **if** statement or the number of arrays in **ForEach** changes.


1. Before the component is deleted, the **aboutToDisappear** callback is invoked to mark the component for deletion. The component deletion mechanism of ArkUI is as follows: (1) The backend component is directly removed from the component tree and destroyed; (2) The reference to the destroyed component is released from the frontend components; (3) The JS Engine garbage collects the destroyed component.

2. The custom component and all its variables are deleted. Any variables linked to this component, such as [@Link](arkts-link.md), [@Prop](arkts-prop.md), or [@StorageLink](arkts-appstorage.md#storagelink) decorated variables, are unregistered from their [synchronization sources](arkts-state-management-overview.md#basic-concepts).


Use of **async await** is not recommended inside the **aboutToDisappear** callback. In case of an asynchronous operation (a promise or a callback) being started from the **aboutToDisappear** callback, the custom component will remain in the Promise closure until the function has been called, which prevents the component from being garbage collected.


The following example when the lifecycle callbacks are invoked:



```ts
// Index.ets
import router from '@ohos.router';

@Entry
@Component
struct MyComponent {
  @State showChild: boolean = true;

  // Only components decorated by @Entry can call the lifecycle callbacks of a page.
  onPageShow() {
    console.info('Index onPageShow');
  }
  // Only components decorated by @Entry can call the lifecycle callbacks of a page.
  onPageHide() {
    console.info('Index onPageHide');
  }

  // Only components decorated by @Entry can call the lifecycle callbacks of a page.
  onBackPress() {
    console.info('Index onBackPress');
  }

  // Component lifecycle
  aboutToAppear() {
    console.info('MyComponent aboutToAppear');
  }

  // Component lifecycle
  aboutToDisappear() {
    console.info('MyComponent aboutToDisappear');
  }

  build() {
    Column() {
      // When this.showChild is true, the Child child component is created, and Child aboutToAppear is invoked.
      if (this.showChild) {
        Child()
      }
      // When this.showChild is false, the Child child component is deleted, and Child aboutToDisappear is invoked.
      Button('delete Child').onClick(() => {
        this.showChild = false;
      })
      // Because of the pushing from the current page to Page2, onPageHide is invoked.
      Button('push to next page')
        .onClick(() => {
          router.pushUrl({ url: 'pages/Page2' });
        })
    }

  }
}

@Component
struct Child {
  @State title: string = 'Hello World';
  // Component lifecycle
  aboutToDisappear() {
    console.info('[lifeCycle] Child aboutToDisappear')
  }
  // Component lifecycle
  aboutToAppear() {
    console.info('[lifeCycle] Child aboutToAppear')
  }

  build() {
    Text(this.title).fontSize(50).onClick(() => {
      this.title = 'Hello ArkUI';
    })
  }
}
```


In the preceding example, the **Index** page contains two custom components. One is **MyComponent** decorated with \@Entry, which is also the entry component (root node) of the page. The other is **Child**, which is a child component of **MyComponent**. Only components decorated by \@Entry can call the lifecycle callbacks of a page.Therefore, the page lifecycle callbacks of the **Index** page are declared in **MyComponent**. **MyComponent** and its child components also declare the lifecycle callbacks of the respective component.


- The initialization process of application cold start is as follows: MyComponent aboutToAppear -> MyComponent build -> Child aboutToAppear -> Child build -> Child build execution completed -> MyComponent build execution completed -> Index onPageShow.

- When **delete Child** is clicked, the value of **this.showChild** linked to **if** changes to **false**. As a result, the **Child** component is deleted, and the **Child aboutToDisappear** callback is invoked.


- When **push to next page** is clicked, the **router.pushUrl** API is called to jump to the next page. As a result, the **Index** page is hidden, and the **Index onPageHide** callback is invoked. As the called API is **router.pushUrl**, which results in the Index page being hidden, but not destroyed, only the **onPageHide** callback is invoked. After a new page is displayed, the process of initializing the lifecycle of the new page is executed.

- If **router.replaceUrl** is called, the **Index** page is destroyed. In this case, the execution of lifecycle callbacks changes to: Index onPageHide -> MyComponent aboutToDisappear -> Child aboutToDisappear. As aforementioned, a component is destroyed by directly removing it from the component tree. Therefore, **aboutToDisappear** of the parent component is called first, followed by **aboutToDisAppear** of the child component, and then the process of initializing the lifecycle of the new page is executed.

- When the Back button is clicked, the **Index onBackPress** callback is invoked. When the application is minimized or switched to the background, the **Index onPageHide** callback is invoked. The application is not destroyed in these two states. Therefore, the **aboutToDisappear** callback of the component is not executed. When the application returns to the foreground, the **Index onPageShow** callback is invoked.


- When the application exits, the following callbacks are executed in order: Index onPageHide -> MyComponent aboutToDisappear -> Child aboutToDisappear.
