# Screenshot Development

## When to Use

You can specify a display device to take screenshots, with screenshot parameters specified.

## Available APIs

For details about the APIs, see [Screenshot](../reference/apis/js-apis-screenshot.md).

## How to Develop

Call **save(options?: ScreenshotOptions): Promise<image.PixelMap>** to take a screenshot. In this API, **options** is a predefined screenshot parameter. If **options** is unspecified, the entire screen is captured by default. An example code snippet is as follows:

```js
import screenshot from '@ohos.screenshot' // Import the module.

// Set screenshot parameters.
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

let image; // image is used to save the screenshot.
screenshot.save(ScreenshotOptions).then((image) => {
	console.log('screenshot.save success, screenshot image :' + JSON.stringify(image));
}, (err) => {
    console.log('screenshot.save failed, error : ' + JSON.stringify(err));
})
```
