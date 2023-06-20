# app.js

## Application Lifecycle<sup>4+</sup>

You can implement lifecycle logic specific to your application in the **app.js** file. Available application lifecycle functions are as follows:


- **onCreate()**: called when an application is created

- **onDestory()**: called when an application is destroyed


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
