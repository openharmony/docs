# ArkUI Routing/Navigation Development (ArkTS)


## Why can't class objects be transferred through params in the router API? (API version 9)

Only attributes in an object can be transferred, and methods in the object cannot.


## How do I use router to implement page redirection in the stage model? (API version 9)

1. To implement page redirection through **router**, add all redirected-to pages to the **pages** list in the **main_pages.json** file.

2. Page routing APIs in **router** can be invoked only after page rendering is complete. Do not call these APIs in **onInit** or **onReady** when the page is still in the rendering phase.

**Reference**

[@ohos.router (Page Routing)](../reference/apis-arkui/js-apis-router.md)


## Will a page pushed into the stack through router.push be reclaimed? (API version 9)

After being pushed to the stack through **router.push**, a page can be reclaimed only when it is popped from the stack through **router.back**.

**Reference**

[router.getParams](../reference/apis-arkui/js-apis-router.md#routergetparams)
