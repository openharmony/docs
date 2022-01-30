# FAQs<a name="EN-US_TOPIC_0000001055049072"></a>

## Visual Application FAQs<a name="section147421736145813"></a>

### Is there a global variable that can be accessed by all pages?<a name="section294382614018"></a>

There is no such a global variable.

### How do I obtain DOM elements?<a name="section1423713435019"></a>

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

### How do I pass values between pages?<a name="section119822143117"></a>

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

### How do I scroll a list to an item?<a name="section188663819111"></a>

Call the  **scrollTo**  method of the list. The input parameter of this method is the index of the target item. You can specify an item index, or obtain the index through the  **scrollend**  event.

### Does the  **<text\>**  component support multiple lines?<a name="section205741157418"></a>

Yes. You can use the Enter key to start a new line. Alternatively, the component automatically starts a new line based on the content, without the need to set the height attribute of the text.

### Why is a component not displayed?<a name="section1345810151025"></a>

**Description**

The component added to the  **.hml**  file cannot be displayed.

**Possible Causes**

-   The width and height of the component may not be set.
-   The style setting may be incorrect.

**Solution**

\(1\) Check whether the width and height values are set explicitly.

\(2\) Check whether the style of the component is set correctly.

### How do I implement scrolling on a page?<a name="section1724052813218"></a>

There are three ways to implement page scrolling:  **scroll**,  **<list\>**, or  **<swiper\>**. For a root component with  **scroll**  set, the scrolling effect is automatically implemented when the component size exceeds the screen size. For details, see the development specifications.

### Why do not the  **left**  and  **top**  attributes take effect?<a name="section34659571520"></a>

**left**  and  **top**  attributes must work with the  **<stack\>**  component in addition to the root component.

### Why does not dynamic binding take effect?<a name="section1758881511313"></a>

The object or its attributes are not defined before dynamic binding.

### How do I implement relative and absolute positioning?<a name="section1378730235"></a>

You can use the  **<div\>**  and  **<stack\>**  \(with  **top**  and  **left**  attributes\) components.

### How do I display or hide a component?<a name="section1243424718312"></a>

You can use  **display**,  **show**, or  **if**. When an  **if**  clause evaluates to  **false**, the corresponding component will be removed from the VDOM. When  **show**  is set to  **false**, the component will be invisible during rendering, but will not be removed from the VDOM.

### What are the precautions for using the  **margin**  attribute?<a name="section7923357414"></a>

The  **margin**  attribute cannot be set for child components of the  **<stack\>**  component.

### What are the precautions for event subscription?<a name="section91641925548"></a>

Only one page exists when the application is running. Therefore, the  **router.replace**  function destroys the previous page and then creates a new one. For pages involving event subscription, an event should be subscribed every time a page is created, and unsubscribed before page switching.

### What are the precautions for using dynamic binding?<a name="section1292412431744"></a>

Do not use too many dynamic bindings because they consume too much memory.

### How does the  **loop**  attribute take effect for  **<swiper\>**?<a name="section1136434952"></a>

If the total length of the child components, except for the first and last ones, is greater than the length of  **<swiper\>**, the  **loop**  attribute takes effect.

### What are the precautions for using an array?<a name="section1979819133510"></a>

Do not include too many elements in an array. Avoid frequent operations on a large array.

