# JavaScript


You can use a **.js** file in the ECMAScript compliant JavaScript language to define the service logic of an HML page. With dynamic typing, JavaScript can make your application more expressive with a flexible design. The following describes the JavaScript compilation and running.


## Syntax

The ECMAScript 6.0 syntax is supported. Lite wearables only support the following ECMAScript 6.0 syntax:

1. let/const

2. arrow functions

3. class

4. default value

5. destructuring assignment

6. destructuring binding pattern

7. enhanced object initializer

8. for-of

9. rest parameter

10. template strings

- Module declaration
  Import functionality modules.


  ```
  import router from '@ohos.router';
  ```

- Code reference
  Import JavaScript code.


  ```
  import utils from '../../common/utils.js';
  ```


## Objects

- Page objects
    | Attribute   | Type             | Description                                      |
    | ----- | --------------- | ---------------------------------------- |
    | data  | Object/Function | Data model of the page. If the attribute is of the function type, the return value must be of the object type. The name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (**for**, **if**, **show**, and **tid**).<br>|
    | $refs | Object          | DOM elements or child component instances that have registered the **ref** attribute. For an example, see [Obtaining a DOM Element](#obtaining-a-dom-element).|


## Obtaining a DOM Element

Use **$refs** to obtain a DOM element.

```html
<!-- index.hml -->
<div class="container">
  <image-animator class="image-player" ref="animator" images="{{images}}" duration="1s" onclick="handleClick"></image-animator>
</div>
```


   ```js
   // index.js
   export default {
     data: {
       images: [
         { src: '/common/frame1.png' },
         { src: '/common/frame2.png' },
         { src: '/common/frame3.png' },
       ],
     },
     handleClick() {
       const animator = this.$refs.animator; // Obtain the DOM element whose $refs attribute is animator.
       const state = animator.getState();
       if (state === 'paused') {
         animator.resume();
       } else if (state === 'stopped') {
         animator.start();
       } else {
         animator.pause();
       }
     },
   };
   ```


## Lifecycle APIs

- Page lifecycle APIs
    | Name       | Type      | Parameter  | Return Value | Description    | Triggered When               |
    | --------- | -------- | ---- | ---- | ------ | ------------------- |
    | onInit    | Function | N/A   | N/A   | Listens for page initialization. | Page initialization is complete. This API is called only once in the page lifecycle.|
    | onReady   | Function | N/A   | N/A   | Listens for page creation.| A page is created. This API is called only once in the page lifecycle.   |
    | onShow    | Function | N/A   | N/A   | Listens for page display.  | The page is displayed.           |
    | onHide    | Function | N/A   | N/A   | Listens for page disappearance.  | The page disappears.           |
    | onDestroy | Function | N/A   | N/A   | Listens for page destruction.  | The page is destroyed.           |

    The lifecycle APIs of page A are called in the following sequence:
  - Open page A: onInit() -> onReady() -> onShow()

  - Open page B on page A: onHide() -> onDestroy()

  - Go back to page A from page B: onInit() -> onReady() -> onShow()

  - Exit page A: onHide() -> onDestroy()

  - Hide page A: onHide()

  - Show background page A on the foreground: onShow()

- Application lifecycle APIs
    | Name       | Type      | Parameter  | Return Value | Description  | Triggered When     |
    | --------- | -------- | ---- | ---- | ---- | --------- |
    | onCreate  | Function | N/A   | N/A   | Listens for application creation.| The application is created.|
    | onDestroy | Function | N/A   | N/A   | Listens for application exit.| The application exits.|
