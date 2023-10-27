# Speeding Up Application Cold Start

Application startup latency is a key factor that affects user experience. When an application is started, the background does not have a process of the application, and therefore the system creates a new process and allocates it to the application. This startup mode is called cold start.

## Analyzing the Time Required for Application Cold Start

The cold start process of OpenHarmony applications can be divided into four phases: application process creation and initialization, application and ability initialization, ability lifecycle, and home page loading and drawing, as shown below.

![application-cold-start](figures/application-cold-start.png)

## 1. Shortening Time Required for Application Process Creation And Initialization

In the phase of application process creation and initialization, the system creates and initializes an application process, including decoding the icon of the startup page (specified by **startWindowIcon**).

### Using startWindowIcon of Appropriate Resolution

With regard to the icon of the startup page, the recommended maximum resolution is 256 x 256 pixels. Larger resolutions may result in slow startup.

```json
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntrance": "./ets/entryability/EntryAbility.ts",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:startWindowIcon", // Modify the icon of the startup page. It is recommended that the icon be less than or equal to 256 x 256 pixels.
        "startWindowBackground": "$color:start_window_background",
        "visible": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ]
```

## 2. Shortening Time Required for Application and Ability Initialization

In this phase of application and ability initialization, resources are loaded, virtual machines are created, application and ability related objects are created and initialized, and dependent modules are loaded.

### Minimizing the Number of Imported Modules

Before the application code is executed, the application must find and load all imported modules. Each additional third-party framework or module to be loaded by the application increases the startup time. The time required depends on the number and size of loaded third-party frameworks or modules. To speed up startup, use system-provided modules when possible and load the modules as required.

## 3. Shortening Time Required for Ability Lifecycle

In this phase of ability lifecycle, the ability lifecycle callbacks are executed.

### Avoiding Time-Consuming Operations in Ability Lifecycle Callbacks

In the application startup process, the system executes the ability lifecycle callbacks. Whenever possible, avoid performing time-consuming operations in these callbacks. You are advised to perform time-consuming operations through asynchronous tasks or execute them in other threads.

In these lifecycle callbacks, perform only necessary operations. For details, see [UIAbility Lifecycle](../application-models/uiability-lifecycle.md).

## 4. Shortening Time Required for Home Page Loading and Drawing

In this phase of home page loading and drawing, the home page content is loaded, the layout is measured, and components are refreshed and drawn.

### Avoid time-consuming operations in the custom component lifecycle callbacks.

When the lifecycle of a custom component changes, the corresponding callback is called.

The **aboutToAppear** function is executed after the custom component instance is created and before the page is drawn. The following code asynchronously processes the time-consuming computing task in **aboutToAppear** to avoid executing the operation in this function and blocking the page drawing.

```typescript
@Entry
@Component
struct Index {
  @State private text: string = "";
  private count: number = 0;

  aboutToAppear() {
    this.computeTaskAsync(); // Asynchronous task
    this.text = "hello world";
  }

  build() {
    Column({space: 10}) {
      Text(this.text).fontSize(50)
    }
    .width('100%')
    .height('100%')
    .padding(10)
  }

   computeTask() {
    this.count = 0;
    while (this.count < 10000000) {
      this.count++;
    }
    this.text = 'task complete';
  }

  // Asynchronous processing of the computing task
  private computeTaskAsync() {
    setTimeout(() => {// setTimeout is used to implement asynchronous processing.
      this.computeTask();
    }, 1000)
  }
}
```
