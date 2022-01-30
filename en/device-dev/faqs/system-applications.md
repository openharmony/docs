# System Applications<a name="EN-US_TOPIC_0000001169690992"></a>

## Utils<a name="section639433461512"></a>

### 1. Failure in running the KV store on the LiteOS-A kernel \(Hi3516 or Hi3518\) due to incorrect path setting for the KV store<a name="section16520347131511"></a>

**Problem**

When the LiteOS-A kernel \(Hi3516 or Hi3518 platform\) directly calls the API provided by the KV store, the compiled executable program fails to run.

**Possible Causes**

The compiled executable program is run directly without being converted to an application using  **AbilityKit**  APIs. In this case, the Bundle Manager Service \(BMS\) cannot correctly set the path for storing application data during application installation. As a result, the KV store fails to run.

**Solution**

Call the  **UtilsSetEnv**  function of the KV store to set the data storage path.

```
UtilsSetEnv("/storage/com.huawei.kv");
```

## Visual Applications<a name="section787718474161"></a>

### Is there a global variable that can be accessed by all pages?<a name="section187297991718"></a>

There is no such a global variable.

### How do I obtain DOM elements?<a name="section1833493719175"></a>

You can obtain DOM elements via the  **ref**  attribute. You can use methods of the obtained elements but cannot change their attributes. The sample code is as follows:

```
<!--index.hml-->
<div class="container">
   <!-- Set the ref attribute of the component to animator -->.
   <image-animator class="image-player" ref="animator" images="{{images}}" duration="1s" onclick="handleClick"></image-animator>
</div>

/* index.js */
export default {
    data: {
        images:[
            {src:"common/frame1.png"},
            {src:"common/frame2.png"},
            {src:"common/frame3.png"}
        ]
    },
    handleClick(){
        // Obtain the component through the $refs attribute. (The ref attribute of the component has been set to animator in the HML file.)
        const animator = this.$refs.animator;
        const state = animator.getState();
        if(state == "paused"){
            animator.resume();
        }else if(state == "stopped"){
            animator.start();
        }else{
            animator.pause();
        }
    }
}
```

### How do I pass values between pages?<a name="section184283812183"></a>

You can pass values through  **params**  of the  **router.replace**  method. The sample code is as follows:

Set  **params**  to the values to be passed on a page.

```
router.replace({
     uri:'pages/detail/detail',  // URI of the page to switch to.
    params:{transferData:this.data} // Data to be transferred. You need to define the data amount and name.
});
```

Receive the passed values on another page.

```
onInit(){
    const data = this.transferData; // Receive the transferred data by the onInit function.
}  
```

### How do I scroll a list to an item?<a name="section11897734131811"></a>

Call the  **scrollTo**  method of the list. The input parameter of this method is the index of the target item. You can specify an item index, or obtain the index through the  **scrollend**  event.

### Does the  **<text\>**  component support multiple lines?<a name="section5872656121814"></a>

Yes. You can use the Enter key to start a new line. Alternatively, the component automatically starts a new line based on the content, without the need to set the height attribute of the text.

### Why is a component not displayed?<a name="section7397125317107"></a>

**Description**

The component added to the  **.hml**  file cannot be displayed.

**Possible Causes**

-   The width and height of the component may not be set.
-   The style setting may be incorrect.

**Solution**

\(1\) Check whether the width and height values are set explicitly.

\(2\) Check whether the style of the component is set correctly.

### How do I implement scrolling on a page?<a name="section338794422010"></a>

There are three ways to implement page scrolling:  **scroll**,  **<list\>**, or  **<swiper\>**. For a root component with  **scroll**  set, the scrolling effect is automatically implemented when the component size exceeds the screen size. For details, see the development specifications.

### Why do not the  **left**  and  **top**  attributes take effect?<a name="section2597193611217"></a>

**left**  and  **top**  attributes must work with the  **<stack\>**  component in addition to the root component.

### Why does not dynamic binding take effect?<a name="section6939050172115"></a>

The object or its attributes are not defined before dynamic binding.

### How do I implement relative and absolute positioning?<a name="section5547311192215"></a>

You can use the  **<div\>**  and  **<stack\>**  \(with  **top**  and  **left**  attributes\) components.

### How do I display or hide a component?<a name="section16107113352213"></a>

You can use  **display**,  **show**, or  **if**. When an  **if**  clause evaluates to  **false**, the corresponding component will be removed from the VDOM. When  **show**  is set to  **false**, the component will be invisible during rendering, but will not be removed from the VDOM.

### What are the precautions for using the  **margin**  attribute?<a name="section1524910142314"></a>

The  **margin**  attribute cannot be set for child components of the  **<stack\>**  component.

### What are the precautions for event subscription?<a name="section1537132012231"></a>

Only one page exists when the application is running. Therefore, the  **router.replace**  function destroys the previous page and then creates a new one. For pages involving event subscription, an event should be subscribed every time a page is created, and unsubscribed before page switching.

### What are the precautions for using dynamic binding?<a name="section96561452236"></a>

Do not use too many dynamic bindings because they consume too much memory.

### How does the  **loop**  attribute take effect for  **<swiper\>**?<a name="section690166112414"></a>

If the total length of the child components, except for the first and last ones, is greater than the length of  **<swiper\>**, the  **loop**  attribute takes effect.

### What are the precautions for using an array?<a name="section1554552822414"></a>

Do not include too many elements in an array. Avoid frequent operations on a large array.

## HDC<a name="section412357182518"></a>

### hdc\_std Fails to Connect to a Device<a name="section1965012223257"></a>

-   **Symptom**

    **\[Empty\]**  is displayed in the output after the  **hdc\_std list targets**  command is executed.

-   **Solutions**
    1.  The device cannot be identified.

        Check whether  **HDC Device**  exists in the universal serial bus device of the device manager. If  **HDC Device**  does not exist, the device cannot be connected. In this case, remove and then insert the device or burn the latest image for the device.

    2.  hdc\_std works improperly.

        Run the  **hdc kill**  or  **hdc start -r**  command to kill or restart the hdc service. Then, run the  **hdc list targets**  command to check whether device information can be obtained.

    3.  hdc\_std does not match the device.

        If the latest image is burnt on the device, the latest hdc\_std version must be used. As hdc\_std is updated continuously, obtain hdc\_std of the latest version from the  **developtools\_hdc\_standard**  repository in the  **prebuilt**  directory.



### hdc\_std Fails to Run<a name="section1157575212515"></a>

-   **Symptom**

    The  **hdc\_std.exe**  file does not run after being clicked.

-   **Solutions**

    **hdc\_std.exe**  requires no installation. It can be directly used on a disk or added to environment variables. Open the cmd window and run the  **hdc\_std**  command to use  **hdc\_std.exe**.


