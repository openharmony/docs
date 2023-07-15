# Page Routing (router)


Page routing refers to the redirection and data transfer between different pages in an application. In OpenHarmony, page routing can be implemented through APIs of the **Router** module. Through different URLs, you can easily navigate users through pages. This document describes the functions provided by the **Router** module from the following aspects: [Page Redirection](#page-redirection), [Page Return](#page-return), and [Adding a Confirmation Dialog Box Before Page Return](#adding-a-confirmation-dialog-box-before-page-return).


## Page Redirection

Page redirection is an important part of the development process. When using an application, you usually need to jump between different pages, and sometimes you need to pass data from one page to another.

  **Figure 1** Page redirection 
![router-jump-to-detail](figures/router-jump-to-detail.gif)

The **Router** module provides two redirection modes: [router.pushUrl()](../reference/apis/js-apis-router.md#routerpushurl9) and [router.replaceUrl()](../reference/apis/js-apis-router.md#routerreplaceurl9). The two modes determine whether the target page will replace the current page.

- **router.pushUrl()**: The target page does not replace the current page. Instead, it is pushed into the [page stack](../application-models/page-mission-stack.md). In this way, the state of the current page can be retained, and users can return to the current page by pressing the back button or calling the [router.back()](../reference/apis/js-apis-router.md#routerback) API.

- **router.replaceUrl()**: The target page replaces the current page and destroys the current page. In this way, the resources of the current page can be released, and users cannot return to the current page.

>**NOTE**
>
>The maximum capacity of a page stack is 32 pages. If this limit is exceeded, the [router.clear()](../reference/apis/js-apis-router.md#routerclear) API can be called to clear the historical page stack and free the memory.

The **Router** module also provides two instance modes: **Standard** and **Single**. The two modes determine whether the target URL corresponds to multiple instances.

- **Standard**: standard instance mode, which is the default instance mode. Each time this API is called, a target page is created and pushed to the top of the stack.

- **Single**: singleton mode. If the URL of the target page already exists in the page stack, the page with the same URL closest to the top of the stack is moved to the top of the stack and reloaded. If the URL of the target page does not exist in the page stack, the page is redirected in standard mode.

Before using the **Router** module, you need to import it to the code.


```ts
import router from '@ohos.router';
```

- Scenario 1: There is a home page (**Home**) and a details page (**Detail**). You want to click an offering on the home page to go to the details page. In addition, the home page needs to be retained in the page stack so that the status can be restored when the page is returned. In this scenario, you can use the **pushUrl()** API and use the **Standard** instance mode (which can also be omitted).


  ```ts
  // On the Home page
  function onJumpClick(): void {
    router.pushUrl({
      url: 'pages/Detail' // Target URL.
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
  >In **Standard** instance mode, the **router.RouterMode.Standard** parameter can be omitted.

- Scenario 2: There is a login page (**Login**) and a personal center page (**Profile**). After a user successfully logs in from the **Login** page, the **Profile** page is displayed. At the same time, the **Login** page is destroyed, and the application exits when the back button is pressed. In this scenario, you can use the **replaceUrl()** API and use the Standard instance mode (which can also be omitted).


  ```ts
  // On the Login page
  function onJumpClick(): void {
    router.replaceUrl({
      url: 'pages/Profile' // Target URL.
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
  >In **Standard** instance mode, the **router.RouterMode.Standard** parameter can be omitted.

- Scenario 3: There is a setting page (**Setting**) and a theme switching page (**Theme**). You want to click a theme option on the **Setting** page to go to the **Theme** page. In addition, you want to ensure that only one **Theme** page exists in the page stack at a time. When the back button is clicked on the **Theme** page, the **Setting** page is displayed. In this scenario, you can use the **pushUrl()** API and use the **Single** instance mode.


  ```ts
  // On the Setting page
  function onJumpClick(): void {
    router.pushUrl({
      url: 'pages/Theme' // Target URL.
    }, router.RouterMode.Single, (err) => {
      if (err) {
        console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke pushUrl succeeded.');
    });
  }
  ```

- Scenario 4: There is a search result list page (**SearchResult**) and a search result details page (**SearchDetail**). You want to click a result on the **SearchResult** page to go to the **SearchDetail** page. In addition, if the result has been viewed before, clicking the result displays the existing details page, instead of creating a new one. In this scenario, you can use the **replaceUrl()** API and use the **Single** instance mode.


  ```ts
  // On the SearchResult page
  function onJumpClick(): void {
    router.replaceUrl({
      url: 'pages/SearchDetail' // Target URL.
    }, router.RouterMode.Single, (err) => {
      if (err) {
        console.error(`Invoke replaceUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke replaceUrl succeeded.');})
  }
  ```

The preceding scenarios do not involve parameter transfer.

If you need to transfer some data to the target page during redirection, you can add a **params** attribute and specify an object as a parameter when invoking an API of the **Router** module. Example:


```ts
class DataModelInfo {
  age: number;
}

class DataModel {
  id: number;
  info: DataModelInfo;
}

function onJumpClick(): void {
  // On the Home page
  let paramsInfo: DataModel = {
    id: 123,
    info: {
      age: 20
    }
  };

  router.pushUrl({
    url: 'pages/Detail', // Target URL.
    params: paramsInfo // Add the params attribute to transfer custom parameters.
  }, (err) => {
    if (err) {
      console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Invoke pushUrl succeeded.');
  })
}
```

On the target page, you can call the [getParams()](../reference/apis/js-apis-router.md#routergetparams) API of the **Router** module to obtain the transferred parameters. Example:


```ts
const params = router.getParams(); // Obtain the transferred parameter object.
const id = params['id']; // Obtain the value of the id attribute.
const age = params['info'].age; // Obtain the value of the age attribute.
```


## Page Return

After a user completes an operation on a page, the user usually needs to return to the previous page or a specified page. In this case, the page return function is required. During the return process, the data may need to be transferred to the target page, which requires the data transfer function.

  **Figure 2** Page return 

![router-back-to-home](figures/router-back-to-home.gif)

Before using the **Router** module, you need to import it to the code.


```ts
import router from '@ohos.router';
```

You can use any of the following methods to return to a page:

- Method 1: Return to the previous page.


  ```ts
  router.back();
  ```

  This method allows you to return to the position of the previous page in the page stack. For this method to work, the previous page must exist in the page stack.

- Method 2: Return to the specified page.


  ```ts
  router.back({
    url: 'pages/Home'
  });
  ```

  This method allows you to return to a specified page. You need to specify the path of the target page. For this method to work, the target page must it exist in the page stack.

- Method 3: Return to the specified page and transfer custom parameter information.


  ```ts
  router.back({
    url: 'pages/Home',
    params: {
      info:'From Home Page'
    }
  });
  ```

  This method not only allows you to return to the specified page, but also transfer custom parameter information when returning. The parameter information can be obtained and parsed by invoking the **router.getParams()** API on the target page.

On the target page, call the **router.getParams()** API at the position where parameters need to be obtained, for example, in the **onPageShow()** lifecycle callback:


```ts
onPageShow() {
  const params = router.getParams(); // Obtain the transferred parameter object.
  const info = params['info']; // Obtain the value of the info attribute.
}
```

>**NOTE**
>
>When the **router.back()** API is used to return to a specified page, the page is pushed to the top of the stack again, and all page stacks between the original top page (included) and the specified page (excluded) are destroyed.
>
> If the **router.back()** method is used to return to the original page, the original page will not be created repeatedly. Therefore, the variable declared using \@State will not be declared repeatedly, and the **aboutToAppear()** lifecycle callback of the page will not be triggered. If you want to use the custom parameters transferred from the returned page on the original page, you can parse the parameters in the required position. For example, parameter parsing can be performed in the **onPageShow()** lifecycle callback.


## Adding a Confirmation Dialog Box Before Page Return

During application development, to prevent misoperations or data loss, a dialog box needs to be displayed before a user returns from one page to another, asking the user whether to perform the operation.

Such a dialog box can be in the [default style](#default-confirmation-dialog-box) or [custom style](#custom-confirmation-dialog-box).

  **Figure 3** Adding a confirmation dialog box before page return 

![router-add-query-box-before-back](figures/router-add-query-box-before-back.gif)


### Default Confirmation Dialog Box

To implement this function, you can use the [router.showAlertBeforeBackPage()](../reference/apis/js-apis-router.md#routershowalertbeforebackpage9) and [router.back()](../reference/apis/js-apis-router.md#routerback) APIs provided by the **Router** module.

Before using the **Router** module, you need to import it to the code.


```ts
import router from '@ohos.router';
```

To enable the confirmation dialog box for page return, call the [router.showAlertBeforeBackPage()](../reference/apis/js-apis-router.md#routershowalertbeforebackpage9) API (for setting the information about the dialog box), then the [router.back()](../reference/apis/js-apis-router.md#routerback) API. For example, define a click event processing function for the back button on the payment page:


```ts
// Define a click event processing function for the back button.
function onBackClick(): void {
  // Invoke the router.showAlertBeforeBackPage() API to set the information about the confirmation dialog box.
  try {
    router.showAlertBeforeBackPage({
      message: 'Payment not completed yet. Are you sure you want to return?' // Set the content of the confirmation dialog box.
    });
  } catch (err) {
    console.error(`Invoke showAlertBeforeBackPage failed, code is ${err.code}, message is ${err.message}`);
  }

  // Invoke the router.back() API to return to the previous page.
  router.back();
}
```

The **router.showAlertBeforeBackPage()** API receives an object as a parameter. The object contains the following attributes:

- **message**: content of the dialog box. The value is of the string type.
  If the API is successfully called, the confirmation dialog box is displayed on the target page. Otherwise, an exception is thrown and the error code and error information is obtained through **err.code** and **err.message**.

  When the user clicks the back button, a confirmation dialog box is displayed, prompting the user to confirm their operation. If the user selects Cancel, the application stays on the current page. If the user selects OK, the **router.back()** API is triggered and the redirection is performed based on the parameters.


### Custom Confirmation Dialog Box

To implement a custom confirmation dialog box, use APIs in the [PromptAction](../reference/apis/js-apis-promptAction.md#promptactionshowdialog) module or customize a popup window.  This topic uses the APIs in the **PromptAction** module an example to describe how to implement a custom confirmation dialog box.

Before using the **Router** module, you need to import it to the code.


```ts
import router from '@ohos.router';
```

In the event callback, call the [promptAction.showDialog()](../reference/apis/js-apis-promptAction.md#promptactionshowdialog) API of the **PromptAction** module.


```ts
function onBackClick() {
  // Display a custom confirmation dialog box.
  promptAction.showDialog({
    message:'Payment not completed yet. Are you sure you want to return?',
    buttons: [
      {
        text: 'Cancel',
        color: '#FF0000'
      },
      {
        text: 'OK',
        color: '#0099FF'
      }
    ]
  }).then((result) => {
    if (result.index === 0) {
      // The user selects Cancel.
      console.info('User canceled the operation.');
    } else if (result.index === 1) {
      // The user selects OK.
      console.info('User confirmed the operation.');
      // Invoke the router.back() API to return to the previous page.
      router.back();
    }
  }).catch((err) => {
    console.error(`Invoke showDialog failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

When the user clicks the back button, the custom confirmation dialog box is displayed, prompting the user to confirm their operation. If the user selects Cancel, the application stays on the current page. If the user selects OK, the **router.back()** API is triggered and the redirection is performed based on the parameters.
