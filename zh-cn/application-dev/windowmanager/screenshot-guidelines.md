# 屏幕截图开发指导

## 场景介绍

指定显示设备进行特定参数的屏幕截图。

## 接口说明

完整版的接口定义请参考API接口说明文件：[屏幕截图](../reference/apis/js-apis-screenshot.md)。

## 开发步骤

通过接口`save(options?: ScreenshotOptions): Promise<image.PixelMap>`进行屏幕截图。其中`options`为预定义的截屏参数，如果没有输入`options`，则使用默认截取整屏，具体代码示例可参考：

```js
import screenshot from '@ohos.screenshot' // 导入模块

// 设置屏幕截图参数
var ScreenshotOptions = {
	"screenRect": {
		"left": 200,
		"top": 100,
		"width": 200,
		"height": 200},
	"imageSize": {
		"width": 300,
		"height": 300},
	"rotation": 0
};

let image; // image用来保存屏幕截图
screenshot.save(ScreenshotOptions).then((image) => {
	console.log('screenshot.save success, screenshot image :' + JSON.stringify(image));
}, (err) => {
    console.log('screenshot.save failed, error : ' + JSON.stringify(err));
})
```
## 相关实例
针对屏幕截图开发，有以下相关实例可供参考：
- [`Screenshot`：屏幕截图（eTS）（API9）](https://gitee.com/openharmony/app_samples/tree/master/Basic/Screenshot)
