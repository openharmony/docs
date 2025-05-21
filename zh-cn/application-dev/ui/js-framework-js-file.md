# app.js

## 应用生命周期

每个应用可以在app.js自定义应用级[生命周期](js-framework-lifecycle.md)的实现逻辑，以下示例仅在生命周期函数中打印对应日志：
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

## 应用对象<sup>6+</sup>

| 属性     | 类型       | 描述                                       |
| ------ | -------- | ---------------------------------------- |
| getApp | Function | 提供getApp()全局方法，可以在自定义js文件中获取app.js中暴露的对象。 |

示例如下：

```js
// app.js
export default {
    data: {
        test: "by getApp"
    },
    onCreate() {
        console.info('AceApplication onCreate');
    },
    onDestroy() {
        console.info('AceApplication onDestroy');
    },
}
```

```js
// test.js 自定义逻辑代码
export var appData = getApp().data;
```
