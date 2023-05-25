# app.js

## 应用生命周期<sup>4+</sup>

每个应用可以在app.js自定义应用级生命周期的实现逻辑，包括：


- onCreate：在应用生成时被调用的生命周期函数。

- onDestory：在应用销毁时被调用的生命周期函数。


以下示例仅在生命周期函数中打印对应日志：



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