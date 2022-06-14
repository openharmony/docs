# Display Development

## When to Use

An application can obtain the default display object or all display objects by calling the **Display** APIs.

## Available APIs

For details about the APIs, see [Display](../reference/apis/js-apis-display.md).

## How to Develop

Call **getDefaultDisplay(): Promise\<Display>** to obtain the default display object. An example code snippet is as follows:

```js
import display from '@ohos.display' // Import the module.

let disp; // disp is used to save the default display object.
display.getDefaultDisplay().then((disp) => {
	console.log('display.getDefaultDisplay success, display :' + JSON.stringify(disp));
}, (err) => {
    console.log('display.getDefaultDisplay failed, error : ' + JSON.stringify(err));
})
```
