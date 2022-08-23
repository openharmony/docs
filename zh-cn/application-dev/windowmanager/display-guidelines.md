# 屏幕属性开发指导

## 场景介绍

应用通过调用屏幕接口获取默认Display或者所有Display的属性。

## 接口说明

完整版的接口定义请参考API接口说明文件：[屏幕属性](../reference/apis/js-apis-display.md)。

## 开发步骤

通过`getDefaultDisplay(): Promise<Display>`来获取当前默认的`Display`对象，具体代码示例可参考：

```js
import display from '@ohos.display' // 导入模块

let disp; // disp用来保存默认Display
display.getDefaultDisplay().then((disp) => {
	console.log('display.getDefaultDisplay success, display :' + JSON.stringify(disp));
}, (err) => {
    console.log('display.getDefaultDisplay failed, error : ' + JSON.stringify(err));
})
```
## 相关实例
针对屏幕属性开发，有以下相关实例可供参考：
- [`Screen`：屏幕属性（eTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/device/Screen)

