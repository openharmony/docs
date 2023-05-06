# Page Routing


Page routing refers to the jump and data transfer between different pages in an application. The OpenHarmony provides the Router module. Through different URLs, you can easily route pages and access different pages. This document describes the functions provided by the Router module from the following aspects: [Page Jump] (#Page Jump), [Page Return] (#Page Return), and [Adding a Query Box Before Page Return] (#Adding a Query Box Before Page Return).


## Page redirection

Page jumping is an important part of the development process. When using an application, you usually need to jump between different pages, and sometimes you need to pass data from one page to another.

  **Figure 1** Page redirection 
![router-jump-to-detail](figures/router-jump-to-detail.gif)

The Router module provides two jump modes: [router.pushUrl()](../reference/apis/js-apis-router.md#routerpushurl9) and [router.replaceUrl()](../reference/apis/js-apis-router.md#routerreplaceurl9). The two modes determine whether the target page will replace the current page.

- router.pushUrl(): The target page does not replace the current page. Instead, it is pushed into the page stack (../application-models/page-mission-stack.md). In this way, the state of the current page can be retained, and you can return to the current page by pressing the Back key or calling the [router.back()](../reference/apis/js-apis-router.md#routerback) method.

- router.replaceUrl(): The target page replaces the current page and destroys the current page. In this way, the resources of the current page can be released and the current page cannot be returned.

>**Notes:**
>
>The maximum capacity of a page stack is 32 pages. If this limit is exceeded, the [router.clear()](../reference/apis/js-apis-router.md#routerclear) method can be called to clear the historical page stack and release the memory space.

In addition, the Router module provides two instance modes: Standard and Single. The two modes determine whether the target URL corresponds to multiple instances.

- Standard: standard instance mode, which is the default instance mode. Each time this method is called, a target page is created and pushed to the top of the stack.

- Single: single-instance mode. If the URL of the target page already exists in the page stack, the page with the same URL closest to the top of the stack is moved to the top of the stack and reloaded. If the URL of the target page does not exist in the page stack, the page is redirected in standard mode.

Before using the Router function, you need to import the Router module to the code.


```ts
import router from '@ohos.router';
```

- Scenario 1: There is a home page (Home) and a details page (Detail). You want to click an offering on the home page to go to the details page. In addition, the home page needs to be retained in the page stack so that the status can be restored when the page is returned. In this scenario, you can use the pushUrl() method and use the Standard instance mode (or omit it).


  ```ts
  //On the Home page
  function onJumpClick(): void {
    router.pushUrl({
      url: 'pages/Detail' //Target URL.
    }, router.RouterMode.Standard, (err) => {
      if (err) {
        console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke pushUrl succeeded.');
    });
  }
  ```

  >**NOTE**
  >
  >In standard instance mode, the router.RouterMode.Standard parameter can be omitted.

- Scenario 2: There is a login page (Login) and a personal center page (Profile). After a user successfully logs in from the login page, the personal center page is displayed. At the same time, the login page is destroyed and the application is directly exited when the page is returned. In this scenario, you can use the replaceUrl() method and use the Standard instance mode (or omit it).


  ```ts
  //On the Login page
  function onJumpClick(): void {
    router.replaceUrl({
      url: 'pages/Profile' //Target URL.
    }, router.RouterMode.Standard, (err) => {
      if (err) {
        console.error(`Invoke replaceUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke replaceUrl succeeded.');
    })
  }
  ```

  >**NOTE**
  >
  >In standard instance mode, the router.RouterMode.Standard parameter can be omitted.

- Scenario 3: There is a setting page (Setting) and a theme switch page (Theme). You want to click the theme option on the setting page to go to the theme switch page. In addition, ensure that only one theme switching page exists in the page stack at a time. When the page is returned, the setting page is displayed. In this scenario, the pushUrl() method can be used and the Single instance mode can be used.


  ```ts
  //On the Setting page
  function onJumpClick(): void {
    router.pushUrl({
      url: 'pages/Theme' //Target URL.
    }, router.RouterMode.Single, (err) => {
      if (err) {
        console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke pushUrl succeeded.');
    });
  }
  ```

- Scenario 4: There is a search result list page (SearchResult) and a search result details page (SearchDetail). You want to click a result on the search result list page to go to the search result details page. In addition, if the result has been viewed, you do not need to create a details page. Instead, you can directly go to the existing details page. In this scenario, the replaceUrl() method can be used and the Single instance mode can be used.


  ```ts
  //On the SearchResult page
  function onJumpClick(): void {
    router.replaceUrl({
      url: 'pages/SearchDetail' //Target URL.
    }, router.RouterMode.Single, (err) => {
      if (err) {
        console.error(`Invoke replaceUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke replaceUrl succeeded.');})
  }
  ```

The preceding scenario does not involve parameter transfer.

If you need to transfer some data to the target page during redirection, you can add a params attribute and specify an object as a parameter when invoking the method of the Router module. Example:


```ts
class DataModelInfo {
  age: number;
}

class DataModel {
  id: number;
  info: DataModelInfo;
}

function onJumpClick(): void {
  //On the Home page
  let paramsInfo: DataModel = {
    id: 123,
    info: {
      age: 20
    }
  };

  router.pushUrl({
    url: 'pages/Detail', //Target URL
    params: paramsInfo // Add the params attribute to transfer customized parameters.
  }, (err) => {
    if (err) {
      console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Invoke pushUrl succeeded.');
  })
}
```

On the target page, you can call the [getParams()](../reference/apis/js-apis-router.md#routergetparams) method of the Router module to obtain the transferred parameters. Example:


```ts
const params = router.getParams(); // Obtain the transferred parameter object.
const id = params['id']; // Obtain the value of the id attribute.
const age = params['info'].age; // Obtain the value of the age attribute.
```


## Page Return

After a user completes an operation on a page, the user usually needs to return to the previous page or a specified page. In this case, the page return function is required. During the return process, the data may need to be transferred to the target page, which requires the data transfer function.

  Figure 2 Page return 

![router-back-to-home](figures/router-back-to-home.gif)

Before using the Router function, you need to import the Router module to the code.


```ts
import router from '@ohos.router';
```

You can use any of the following methods to return to the page:

- Method 1: Return to the previous page.


  ```ts
  router.back();
  ```

  In this mode, the previous page is returned, that is, the position of the previous page in the page stack. However, the previous page must exist in the page stack to return. Otherwise, the method is invalid.

- Method 2: Return to the specified page.


  ```ts
  router.back({
    url: 'pages/Home'
  });
  ```

  In this mode, you can return to a specified page. You need to specify the path of the target page. The target page can be returned only when it exists in the page stack.

- Method 3: Return to the specified page and transfer custom parameter information.


  ```ts
  router.back({
    url: 'pages/Home',
    params: {
      info:'From Home Page'
    }
  });
  ```

  In this mode, you can not only return to the specified page, but also transfer custom parameter information when returning. The parameter information can be obtained and parsed by invoking the router.getParams() method on the target page.

On the target page, call the router.getParams() method at the position where parameters need to be obtained. For example, in the onPageShow() lifecycle callback:


```ts
onPageShow() {
  const params = router.getParams(); //Obtain the transferred parameter object.
  const info = params['info']; //Obtain the value of the info attribute.
}
```

>**NOTE**
>
>When the router.back() method is used to return to a specified page, the page is pushed to the top of the stack again, and all page stacks between the original top page (included) and the specified page (excluded) are destroyed.
>
> In addition, if the router.back() method is used to return to the original page, the original page will not be created repeatedly. Therefore, the variable declared using \@State will not be declared repeatedly, and the aboutToAppear() lifecycle callback of the page will not be triggered. If you want to use the customized parameters transferred from the return page on the original page, you can parse the parameters in the required position. For example, parameter parsing is performed in the onPageShow() lifecycle callback.


## A query box is added before the page is returned.

During application development, to prevent misoperations or data loss, a dialog box needs to be displayed before a user returns from one page to another, asking the user whether to perform the operation.

This document describes how to add a query box before returning to the page from two aspects: [System Default Query Box] (#System Default Query Box) and [Customized Query Box] (#Customized Query Box).

  Figure 3 Adding a query box before returning to the page 

![router-add-query-box-before-back](figures/router-add-query-box-before-back.gif)


### Default query box

To implement this function, you can use the [router.showAlertBeforeBackPage()](../reference/apis/js-apis-router.md#routershowalertbeforebackpage9) and [router.back()](../reference/apis/js-apis-router.md#routerback) methods provided by the Router module.

Before using the Router function, you need to import the Router module to the code.


```ts
import router from '@ohos.router';
```

If you want to enable the function of returning to the query box on the target page, you need to call the [router.showAlertBeforeBackPage()](../reference/apis/js-apis-router.md#routershowalertbeforebackpage9) method to set the information about the returned query box before invoking the [router.back()](../reference/apis/js-apis-router.md#routerback) method. For example, define a click event processing function for the return button on the payment page:


```ts
//Define a click event processing function for the return button.
function onBackClick(): void {
  //Invoke the router.showAlertBeforeBackPage() method to set the information about the returned query box.
  try {
    router.showAlertBeforeBackPage({
      message: 'You have not completed the payment. Are you sure you want to return?' //Set the content of the inquiry box.
    });
  } catch (err) {
    console.error(`Invoke showAlertBeforeBackPage failed, code is ${err.code}, message is ${err.message}`);
  }

  // Invoke the router.back() method to return to the previous page.
  router.back();
}
```

The router.showAlertBeforeBackPage() method receives an object as a parameter. The object contains the following attributes:

- message: content of the query box. The value is of the string type.
  If the interface is successfully called, the page is displayed on the target page and the query box is displayed. If the interface fails to be called, an exception is thrown and the error code and error information is obtained through err.code and err.message.

  When the user clicks Back, a confirmation dialog box is displayed, asking the user whether to confirm the return. If you select Cancel, the target page of the current page is displayed. If you select OK, the router.back() method is triggered and the jump is performed based on the parameters.


### Custom Inquiry Box

You can use the pop-up window (../reference/apis/js-apis-promptAction.md#promptactionshowdialog) or customize a pop-up window. In this way, the application interface can be different from the default query box of the system, thereby improving user experience of the application. This document uses a pop-up window as an example to describe how to customize a query box.

Before using the Router function, you need to import the Router module to the code.


```ts
import router from '@ohos.router';
```

In the event callback, call the [promptAction.showDialog()](../reference/apis/js-apis-promptAction.md#promptactionshowdialog) method of the pop-up window.


```ts
function onBackClick() {
  //The user-defined query dialog box is displayed.
  promptAction.showDialog({
    message:'You have not completed the payment. Are you sure you want to return?',
    buttons: [
      {
                text: 'Cancel',
        color: '#FF0000'
      },
      {
        text: 'Confirm',
        color: '#0099FF'
      }
    ]
  }).then((result) => {
    if (result.index === 0) {
      // The user clicks Cancel.
      console.info('User canceled the operation.');
    } else if (result.index === 1) {
      //The user clicks OK.
      console.info('User confirmed the operation.');
      // Invoke the router.back() method to return to the previous page.
      router.back();
    }
  }).catch((err) => {
    console.error(`Invoke showDialog failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

When the user clicks Back, a user-defined query box is displayed, asking the user whether to confirm the return. If you select Cancel, the target page of the current page is displayed. If you select OK, the router.back() method is triggered and the jump is performed based on the parameters.
