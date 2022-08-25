# app.js


## Application Lifecycle

You can customize the [lifecycle](../ui/js-framework-lifecycle.md) implementation logic on an application-by-application basis in app.js. The following example only prints the corresponding logs in the lifecycle function:

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

## Application Object<sup>6+</sup>

| Attribute | Data Type | Description | 
| -------- | -------- | -------- |
| getApp | Function | Obtains the object exposed in the **app.js** file from the custom .js file. | 

The following is a sample code snippet:

```js
// app.js
export default {
    data: {
        test: "by getAPP"
    },
    onCreate() {
        console.info('AceApplication onCreate');
    },
    onDestroy() {
        console.info('AceApplication onDestroy');
    },
};
```


```js
// test.js Customize the logic code.
export var appData = getApp().data;
```
