# app.js

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=dfb15c325281e5e789ea7ade45dfdd45876606ad translatedAt=2026-07-27T02:27:32.702Z pushedAt=2026-07-27T09:23:36.745Z -->

You can define app-level lifecycle functions and the app global data object in the **app.js** file. It enables initialization when the app is created or resource release when the app is destroyed, and supports sharing global data across different pages. This is suitable for scenarios where unified management of app state and lifecycle processing is required.

## Application Lifecycle<sup>4+</sup>

You can customize the lifecycle implementation logic on an app-by-app basis in **app.js**, including:

- **onCreate()**: called when an application is created

- **onDestroy()**: called when an application is destroyed

In the following example, logs are printed only in the lifecycle functions.

```js
// app.js
export default {
  onCreate() {
    console.info('Application onCreate');
  },
  onDestroy() {
    console.info('Application onDestroy');
  },
};
```

## Application Object <sup>10+</sup>

| Attribute    | Type      | Description                                      |
| ------ | -------- | ---------------------------------------- |
| getApp | Function | Provides the global method **getApp()** to obtain the object exposed in the **app.js** file from the **.js** file of the page. To be compatible with earlier versions that do not support **getApp**, check whether **getApp** is available before using it. |

> **NOTE**
>
> The app object is global data and occupies JS memory before the app exits. Although it facilitates data sharing between different pages, exercise caution when using it on small devices where available memory is typically limited. If excessive data or memory-intensive data is stored in the app object, exceptions may occur due to insufficient memory when the app navigates to a page containing many components or resources.

The following is an example:

Declare the app object in **app.js**.

```javascript
// app.js
export default {
    data: {
        name: 'by getApp'
    },
    onCreate() {
        console.info('Application onCreate');
    },
    onDestroy() {
        console.info('Application onDestroy');
    },
};
```

Access the app object on a specific page.

```javascript
// index.js
export default {
    data: {
        title: ''
    },
    onInit() {
        if (typeof getApp !== 'undefined') {
            var appData = getApp().data;
            if (typeof appData !== 'undefined') {
                this.title = appData.name; // read from app data
            }
        }
    },
    clickHandler() {
        if (typeof getApp !== 'undefined') {
            var appData = getApp().data;
            if (typeof appData !== 'undefined') {
                appData.name = this.title; // write to app data
            }
        }
    }
};
```

> **NOTE**
>
> To ensure that the application can run properly on an earlier version that does not support **getApp**, compatibility processing must be performed in the code. That is, before using **getApp**, check whether it is available.