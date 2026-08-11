# JavaScript
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sunfei2021-->
<!--Designer: @sunfei2021-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=4431c59b895d1d02940f60be4527223815858a92 translatedAt=2026-07-09T11:48:08.498Z pushedAt=2026-07-09T12:00:56.479Z -->

You can use a .js file in the ECMAScript compliant JavaScript language to define the service logic of an HML page. With dynamic typing, JavaScript can make your application more expressive with a flexible design. The following describes the JavaScript compilation and running.


## Syntax

The ECMAScript 6.0 syntax is supported.

- Module declaration

  Import functionality modules.

  ```js
  import router from '@ohos.router';
  ```

- Code reference

  Import JavaScript code.

  ```js
  import utils from '../../common/utils.js';
  ```


## Objects

- Application objects
  | Name| Type  | Description                                                        |
  | ---- | ------ | ------------------------------------------------------------ |
  | $def | Object | Object that is exposed in the **app.js** file and obtained by `this.$app.$def`.<br>**NOTE**<br>Application objects do not support data binding. Data update should be triggered on the UI.|

  Sample code

  ```js
  // app.js
  export default {
    onCreate() {
      console.info('Application onCreate');
    },
    onDestroy() {
      console.info('Application onDestroy');
    },
    globalData: {
      appData: 'appData',
      appVersion: '2.0',
    },
    globalMethod() {
      console.info('This is a global method!');
      this.globalData.appVersion = '3.0';
    }
  };
  ```

  ```js
  // index.js
  export default {
    data: {
      appData: 'localData',
      appVersion:'1.0',
    },
    onInit() {
      this.appData = this.$app.$def.globalData.appData;
      this.appVersion = this.$app.$def.globalData.appVersion;
    },
    invokeGlobalMethod() {
      this.$app.$def.globalMethod();
    },
    getAppVersion() {
      this.appVersion = this.$app.$def.globalData.appVersion;
    }
  }
  ```

- Page objects
  | Name    | Type           | Description                                                        |
  | -------- | --------------- | ------------------------------------------------------------ |
  | data     | Object/Function | Data model of the page. If the attribute is of the function type, the return value must be of the object type. The name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (**for**, **if**, **show**, and **tid**).<br>The **data** field cannot be used together with the **private** or **public** field.|
  | $refs    | Object          | DOM elements or child component instances that have registered the **ref** attribute. For example code, see [Obtaining a DOM Element](#obtaining-a-dom-element).|
  | private  | Object          | Data model of the page. Private data attribute can be modified only on the current page.     |
  | public   | Object          | Data model of the page. Behaviors of public data attributes are the same as those of the **data** attribute.    |
  | props    | Array/Object    | Used for communication between components. This attribute can be transferred to components via **\<tag xxxx='value'>**. A **props** name must be in lowercase and cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (**for**, **if**, **show**, and **tid**). Currently, **props** does not support functions. For details, see [Props](../reference/apis-arkui/arkui-js/js-components-custom-props.md#props).|
  | computed | Object          | Used for pre-processing an object for reading and setting. The result is cached. The name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words. For details, see [computed](../reference/apis-arkui/arkui-js/js-components-custom-props.md#computed).|

## Methods

- Data methods
  | Method     | Parameters                                    | Description                                      |
  | ------- | -------------------------------------- | ---------------------------------------- |
  | $set    | key:&nbsp;string,&nbsp;value:&nbsp;any | Adds an attribute or modifies an existing attribute.<br>Usage:<br>`this.$set('key',value)`: adds an attribute.|
  | $delete | key:&nbsp;string                       | Deletes an attribute.<br>Usage:<br>`this.$delete('key')`: deletes an attribute.|

  Sample code

  ```js
  // index.js
  export default {
    data: {
      keyMap: {
        OS: 'OS',
        Version: '2.0',
      },
    },
    getAppVersion() {
      this.$set('keyMap.Version', '3.0');
      console.info("keyMap.Version = " + this.keyMap.Version); // keyMap.Version = 3.0
  
      this.$delete('keyMap');
      console.info("keyMap.Version = " + this.keyMap); // log print: keyMap.Version = undefined
    }
  }
  ```

- Public methods
  | Method        | Parameters           | Description                                                        |
  | ------------ | --------------- | ------------------------------------------------------------ |
  | $element     | id:&nbsp;string | Obtains the component with a specified ID. If no ID is specified, the root component is returned. For an example, see [Obtaining a DOM Element](#obtaining-a-dom-element).<br>Usage:<br>**\<div id='xxx'>\</div>**<br>- `this.$element('*xxx*')`: obtains the component whose ID is *xxx*.<br>- `this.$element()`: obtains the root component.|
  | $rootElement | N/A             | Obtains the root element.<br>Usage:<br>`this.\$rootElement().scrollTo({ duration: 500, position: 300 })`: scrolls the page by 300 px within 500 ms.|
  | $root        | N/A             | Obtains the root **ViewModel** instance. For example code, see [Obtaining the ViewModel](#obtaining-the-viewmodel).|
  | $parent      | N/A             | Obtains the parent **ViewModel** instance. For example code, see [Obtaining the ViewModel](#obtaining-the-viewmodel).|
  | $child       | id:&nbsp;string | Obtains the **ViewModel** instance of a custom child component with a specified ID. For example code, see [Obtaining the ViewModel](#obtaining-the-viewmodel).<br>Usage:<br>`this.\$child('xxx')`: obtains the **ViewModel** instance of a custom child component whose ID is *xxx*.|

- Event methods
  | Method  | Parameters                                                        | Description                                                        |
  | ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | $watch | data:&nbsp;string,&nbsp;callback:&nbsp;string&nbsp;\|&nbsp;Function | Listens for attribute changes. If the value of the **data** attribute changes, the bound event is triggered. For details, see [Monitoring Data Changes by \$watch](../reference/apis-arkui/arkui-js/js-components-custom-props.md#monitoring-data-changes-by-watch).<br>Usage:<br>`this.$watch('key', callback)`: triggers the callback event by listening for changes in the value of the **key** attribute.|

- Page methods
  | Method                   | Parameters                              | Description                             |
  | --------------------- | -------------------------------- | ------------------------------- |
  | scrollTo<sup>6+</sup> | scrollPageParam: ScrollPageParam | Scrolls the page to the target position. You can specify the position using the ID selector or scrolling distance.|

  **Table 1** ScrollPageParam<sup>6+</sup>

  | Name          | Type                   | Default Value| Description                                                        |
  | -------------- | ----------------------- | ------ | ------------------------------------------------------------ |
  | position       | number                  | -      | Position to scroll to.                                              |
  | id             | string                  | -      | ID of the element to be scrolled to.                                    |
  | duration       | number                  | 300    | Scrolling duration, in milliseconds.                                  |
  | timingFunction | string                  | ease   | Animation curve for scrolling. Available option:<br>[animation-timing-function](../reference/apis-arkui/arkui-js/js-components-common-animation.md)|
  | complete       | ()&nbsp;=&gt;&nbsp;void | -      | Callback to be invoked when the scrolling is complete.                          |

  Example:

  ```js
  this.$rootElement().scrollTo({ position: 0 });
  this.$rootElement().scrollTo({ id: 'id', duration: 200, timingFunction: 'ease-in', complete: () => {
      console.info('Scrolling completed');
  } });
  ```


## Obtaining a DOM Element

1. Use **$refs** to obtain a DOM element.
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
         { src: '/common/frame3.png' }
       ]
     },
     handleClick() {
           const animator = this.$refs.animator; // Obtain the DOM element whose $refs attribute is animator.
       const state = animator.getState();
       if (state === 'Paused') {
         animator.resume();
       } else if (state === 'Stopped') {
         animator.start();
       } else {
         animator.pause();
       }
     },
   };
   ```

2. Call **$element** to obtain a DOM element.
   ```html
   <!-- index.hml -->
   <div class="container" style="width:500px;height: 700px; margin: 100px;">
     <image-animator class="image-player" id="animator" images="{{images}}" duration="1s" onclick="handleClick"></image-animator>
   </div>
   ```

   ```js
   // index.js
   export default {
     data: {
       images: [
         { src: '/common/frame1.png' },
         { src: '/common/frame2.png' },
         { src: '/common/frame3.png' }
       ]
     },
     handleClick() {
       const animator = this.$element('animator'); // Obtain the DOM element whose ID is animator.
       const state = animator.getState();
       if (state === 'Paused') {
         animator.resume();
       } else if (state === 'Stopped') {
         animator.start();
       } else {
         animator.pause();
       }
     },
   };
   ```

![en-us_image_0000001118642007](figures/Obtaining-DOM-Element.gif)

## Obtaining the ViewModel

The following shows files of the root page:

```html
<!-- root.hml -->
<element name='parentComp' src='../../common/component/parent/parent.hml'></element>
<div class="container">
  <div class="container">
    <text>{{text}}</text>
    <parentComp></parentComp>
  </div>
</div>
```

```js
// root.js
export default {
  data: {
    text: 'I am root!',
  },
}
```

![en-us_image_0000001118642008](figures/Obtaining-ViewModel.png)

Customize the parent component.

```html
<!-- parent.hml -->
<element name='childComp' src='../child/child.hml'></element>
<div class="item" onclick="textClicked">
  <text class="text-style" onclick="parentClicked">parent component click</text>
  <text class="text-style" if="{{showValue}}">hello parent component!</text>
  <childComp id = "selfDefineChild"></childComp>
</div>
```

```js
// parent.js
export default {
  data: {
    showValue: false,
    text: 'I am parent component!',
  },
  parentClicked () {
    this.showValue = !this.showValue;
    console.info('parent component get parent text');
    console.info(`${this.$parent().text}`);
    console.info("parent component get child function");
    console.info(`${this.$child('selfDefineChild').childClicked()}`);
  },
}
```

Customize the child component.

```html
<!-- child.hml -->
<div class="item" onclick="textClicked">
  <text class="text-style" onclick="childClicked">child component clicked</text>
  <text class="text-style" if="{{isShow}}">hello child component</text>
</div>
```

```js
// child.js
export default {
  data: {
    isShow: false,
    text: 'I am child component!',
  },
  childClicked () {
    this.isShow = !this.isShow;
    console.info('child component get parent text');
    console.info(`${this.$parent().text}`);
    console.info('child component get root text');
    console.info(`${this.$root().text}`);
  },
}
```

![en-us_image_0000001118642009](figures/Obtaining-ViewModel.gif)