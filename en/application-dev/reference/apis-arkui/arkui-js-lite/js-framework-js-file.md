# app.js

## Application Lifecycle<sup>4+</sup>

You can implement lifecycle logic specific to your application in the **app.js** file. Available application lifecycle functions are as follows:


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
}
```

## Application Object<sup>10+</sup>

| Attribute    | Type      | Description                                      |
| ------ | -------- | ---------------------------------------- |
| getApp | Function | Obtains the data object exposed in **app.js** from the page JS file. This API works globally.|

> **NOTE**
>
> The application object is global data and occupies JS memory before the application exits. Although it facilitates data sharing between different pages, exercise caution when using it on small-system devices, whose memory is small. If they are overused, exceptions may occur due to insufficient memory when the application displays complex pages.

The following is an example:

Declare the application object in **app.js**.

```javascript
// app.js
export default {
    data: {
        test: "by getAPP"
    },
    onCreate() {
        console.info('Application onCreate');
    },
    onDestroy() {
        console.info('Application onDestroy');
    },
};
```

Access the application object on a specific page.

```javascript
// index.js
export default {
    data: {
        title: ""
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
}
```

> **NOTE**
>
> To ensure that the application can run properly on an earlier version that does not support **getApp**, compatibility processing must be performed in the code. That is, before using **getApp**, check whether it is available.
