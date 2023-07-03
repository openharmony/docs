# ArkUI Routing/Navigation Development (ArkTS)

## Why can't class objects be transferred through params in the router API?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

Only attributes in an object can be transferred, and methods in the object cannot.

## How do I use router to implement page redirection in the stage model?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

1.  To implement page redirection through **router**, add all redirected-to pages to the **pages** list in the **main\_pages.json** file.
2.  Page routing APIs in **router** can be invoked only after page rendering is complete. Do not call these APIs in **onInit** or **onReady** when the page is still in the rendering phase.

**Reference**

[@ohos.router (Page Routing)](../reference/apis/js-apis-router.md)

## Will a page pushed into the stack through router.push be reclaimed?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9, stage model)

After being pushed to the stack through **router.push**, a page can be reclaimed only when it is popped from the stack through **router.back**.

**Reference**

[router.getParams](../reference/apis/js-apis-router.md#routergetparams)