# System Applications




## Utils


### Failed to Run a KV Store on LiteOS-A (Hi3516 or Hi3518)

**Symptom**

When the LiteOS-A kernel (Hi3516 or Hi3518) directly calls the API provided by the KV store, the compiled executable program fails to run.

**Possible Causes**

The compiled executable program is run directly without being converted to an application using **AbilityKit** APIs. In this case, the Bundle Manager Service (BMS) cannot correctly set the path for storing application data during application installation. As a result, the KV store fails to run.

**Solution**

Call the **UtilsSetEnv** function of the KV store to set the data storage path.


```
UtilsSetEnv("/storage/com.example.kv");
```


## Visual Application


### Is there a global variable that can be accessed by all pages?

There is no such a global variable.


### How do I obtain DOM elements?

You can obtain DOM elements via the **ref** attribute. You can use methods of the obtained elements but cannot change their attributes. The sample code is as follows:


```


   
   


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


### How do I pass values between pages?

You can pass values through **params** of the **router.replace** method. The sample code is as follows:

Set **params** to the values to be passed on a page. The sample code is as follows:


```
router.replace({
    uri:'pages/detail/detail',  // URI of the page to be redirected to.
    params:{transferData:this.data}  // Data to be transferred. You need to define the data amount and name.
});
```

Receive the passed values on another page.


```
onInit(){
    const data = this.transferData;  // Use the onInit function to receive the passed data.
}  
```


### How do I scroll a list to an item?

Call the **scrollTo** method of the list. The input parameter of this method is the index of the target item. You can specify an item index, or obtain the index through the **scrollend** event.


### Does the <text> component support multiple lines?

Yes. The **<text>** component supports multiple lines. You can use the **Enter** key to start a new line. If you do not set the height attribute of the text, the component automatically starts a new line based on the content.


### Why is a component not displayed?

**Symptom**

The component added to the **.hml** file cannot be displayed.

**Possible Causes**

- The width and height of the component may not be set.

- The style setting may be incorrect.

**Solution**

1. Check whether the width and height values are set explicitly.

2. Check whether the style of the component is set correctly.



### How do I implement scrolling on a page?

There are three ways to implement page scrolling: **scroll**, **<list>**, or **<swiper>**. For a root component with **scroll** set, the scrolling effect is automatically implemented when the component size exceeds the screen size. For details, see the development specifications.


### Why do not the left and top attributes take effect?

The **left** and **top** attributes must work with the **<stack>** component, except those of the root component.


### Why does not dynamic binding take effect?

The object or its attributes are not defined before dynamic binding.


### How do I implement relative and absolute positioning?

You can use the **<div\>** and **<stack\>** (with **top** and **left** attributes) components to implement relative positioning and absolute positioning.


### How do I display or hide a component?

You can use **display**, **show**, or **if** to display or hide a component. When an **if** clause evaluates to **false**, the corresponding component will be removed from the VDOM. When **show** is set to **false**, the component will be invisible during rendering, but will not be removed from the VDOM.


### What are the precautions for using the Margin attribute?

The **margin** attribute cannot be set for child components of the **<stack>** component.


### What are the precautions for event subscription?

Only one page exists when the application is running. Therefore, the **router.replace** function destroys the previous page and then creates a new one. For pages involving event subscription, an event should be subscribed every time a page is created, and unsubscribed before page switching.


### What are the precautions for using dynamic binding?

Do not use too many dynamic bindings because they consume too much memory.


### How does the loop attribute take effect for <swiper>?

If the total length of child components, except for the first and last ones, is greater than the length of **<swiper>**, the **loop** attribute takes effect.


### What are the precautions for using an array?

Do not include too many elements in an array. Avoid frequent operations on a large array.


## hdc


### hdc_std Failed to Connect to a Device

- **Symptom**
  
  After the **hdc_std list targets** command is executed, **[Empty]** is displayed.

- **Solution**
  
  1. The device cannot be identified.
      
      Check whether **HDC Device** exists under the **Universal Serial Bus controllers** in the **Device Manager**. If **HDC Device** does not exist, the device cannot be connected. In this case, disconnect and then reconnect the USB connection between the test PC and the OpenHarmony device, or burn the latest image.
      
  2. hdc_std works improperly.
      Run the **hdc kill** command to terminate the hdc_std process or run the **hdc start -r** command to restart the hdc service. Then, run the **hdc list targets** command to check whether device information can be obtained.
  
  3. hdc_std does not match the device.
      If the latest image is burnt on the device, the latest hdc_std version must be used.


### hdc_std Failed to Run

- **Symptom**
  

  After you click **hdc_std.exe**, the file fails to execute.

- **Solution**
  
  **hdc_std.exe** requires no installation. You can use it after placing it to a local directory or adding the tool path to environment variables. Run the **cmd** command and then run the **hdc_std** command to start the tool.
