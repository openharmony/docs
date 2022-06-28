# Getting Started with JavaScript in the Low-Code Approach

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>This feature will be available in DevEco Studio V2.2 Beta1 and later versions.
>
> For best possible results, use [DevEco Studio V3.0.0.900 Beta3](https://developer.harmonyos.com/cn/develop/deveco-studio#download_beta_openharmony) for your development.


On the OpenHarmony low-code development pages, you can design your app UI in an efficient, intuitive manner, with a wide array of UI editing features.


You can develop applications or services in the low-code approach using either of the following methods:


- Create a project that supports low-code development. This method is used as an example in this topic.

- In an existing project, create a Visual file for development. For details, see [Creating a .visual File That Supports Low-Code Development](#building-the-second-page).


## Creating a Project That Supports Low-Code Development

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>This feature is available in DevEco Studio 3.0 Beta2 and later versions and works with compileSdkVersion 7 or later.
>

1. In DevEco Studio, if no project is open, click **Create Project**; if a project is already open, choose **File** &gt; **New** &gt; **Create Project**. Then, select **Empty Ability** and click **Next**.

   ![en-us_image_0000001268198893](figures/en-us_image_0000001268198893.png)
2. Go to the project configuration page, select **Enable Super Visual**, set **UI Syntax** to **JS**, and retain the default values for other parameters.

    ![en-us_image_0000001223717294](figures/en-us_image_0000001223717294.png)

3. Click **Finish**. DevEco Studio will automatically generate the sample code and resources that match your project type. Wait until the project is created.


## Low-code Project Files

After the project synchronization is complete, a low-code directory structure is automatically generated in the project, as shown below.

![en-us_image_0000001223558810](figures/en-us_image_0000001223558810.png)

- **entry &gt; src &gt; main &gt; js &gt; MainAbility &gt; pages &gt; index &gt; index.js**: defines logical relationships, such as data and events, used on low-code pages. For details, see [JavaScript](../ui/js-framework-syntax-js.md). If multiple low-code development pages are created, a page folder and the corresponding **.js** file will be created for each of these pages.
  
  > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>To avoid build errors when using the low-code development page, make sure the directory where the corresponding **.js** file is located does not contain **.hml** or **.css** files. For example, in the preceding example, no **.hml** or **.css** file is allowed in **js** &gt; **MainAbility** &gt; **pages** &gt; **index**.
  >
- **entry &gt; src &gt; main &gt; supervisual &gt; MainAbility &gt; pages &gt; index &gt; index.visual**: stores the data model of the low-code development page. You can double-click the file to open the low-code development page. If multiple low-code development pages are created, a page folder and the corresponding **.visual** file will be created for each of these pages.


## Building the First Page

After the project synchronization is complete, the default first page contains the **Div** and **Text** (**Hello World**) components. To better understand low-code development, we'll delete these template components from the canvas and set the page from scratch.

Add **Div**, **Text**, and **Button** components to the first page.

1. Delete the existing template components from the canvas.<a name= delete_origin_content></a>
   

   Open the index.visual file, right-click the existing template components on the canvas, and choose **Delete** from the shortcut menu to delete them. Below is an illustration of the operations.

   ![en-us_image_0000001216600980](figures/en-us_image_0000001216600980.gif)

2. Add a **Div** component and set its styles and attributes.<a name = add_container></a>

   Drag the **Div** component from the **UI Control** area to the canvas. In the **Attributes &amp; Styles** area on the right, click ![en-us_image_0000001260226691](figures/en-us_image_0000001260226691.png)**General** and set **Height** to **100%** so that the component fills the entire screen. Click ![en-us_image_0000001215226858](figures/en-us_image_0000001215226858.png)**Flex**, set **FlexDirection** to **column** so that the main axis of the component is vertical, and set both **JustifyContent** and **AlignItems** to **center** so that the child components of the **Div** component are centered along the main axis and cross axis. Below is an illustration of the operations.

   ![en-us_image_0000001216448880](figures/en-us_image_0000001216448880.gif)

3. Add a **Text** component.

   Drag the **Text** component from the **UI Control** area to the center area of the **Div** component. In the **Attributes &amp; Styles** area, click ![en-us_image_0000001215066868](figures/en-us_image_0000001215066868.png)**Properties** and set **Content** of the **Text** component to **Hello World**. Click ![en-us_image_0000001215386842](figures/en-us_image_0000001215386842.png)**Feature**, and set **FontSize** to **60px** and **TextAlign** to **center**. Then, select the **Text** component on the canvas and drag its corners to fully display the text. Below is an illustration of the operations.

   ![en-us_image_0000001216446670](figures/en-us_image_0000001216446670.gif)

4. Add a **Button** component.

   Drag the **Button** component from the **UI Control** area to a position under the **Text** component on the canvas. In the **Attributes &amp; Styles** area on the right, click ![en-us_image_0000001260106745](figures/en-us_image_0000001260106745.png)**Properties** and set **Value** of the **Button** component to **Next**. Click ![en-us_image_0000001259866741](figures/en-us_image_0000001259866741.png)**Feature** and set **FontSize** to **40px**. Then, select the **Button** component on the canvas and drag its corners to fully display the text. Below is an illustration of the operations.

   ![en-us_image_0000001260928361](figures/en-us_image_0000001260928361.gif)

5. On the toolbar in the upper right corner of the editing window, click **Previewer** to open the Previewer. 

   Below is how the first page looks on the Previewer.

   ![en-us_image_0000001216288558](figures/en-us_image_0000001216288558.png)


## Building the Second Page

1. Create the second page.
   
   In the **Project** window, choose **entry** &gt; **src** &gt; **main** &gt; **js** &gt; **MainAbility**, right-click the **pages** folder, choose **New** &gt; **Visual**, name the page **second**, and click **Finish**. Below, you can see the structure of the **pages** folder.

   ![en-us_image_0000001223882030](figures/en-us_image_0000001223882030.png)

2. [Delete the existing template components from the canvas.](#delete_origin_content)

3. [Add a Div component and set its styles and attributes.](#add_container)

4. Add a **Text** component.

   Drag the **Text** component from the **UI Control** area to the center area of the **Div** component. In the **Attributes &amp; Styles** area, click ![en-us_image_0000001260227453](figures/en-us_image_0000001260227453.png)**Properties** and set **Content** of the **Text** component to **Hi there**. Click ![en-us_image_0000001260107497](figures/en-us_image_0000001260107497.png)**Feature**, and set **FontSize** to **60px** and **TextAlign** to **center**. Then, select the **Text** component on the canvas and drag its corners to fully display the text. Below is an illustration of the operations.

   ![en-us_image_0000001216614132](figures/en-us_image_0000001216614132.gif)

5. Add a **Button** component.

   Drag the **Button** component from the **UI Control** area to a position under the **Text** component on the canvas. In the **Attributes &amp; Styles** area on the right, click ![en-us_image_0000001215227618](figures/en-us_image_0000001215227618.png)**Properties** and set **Value** of the **Button** component to **Back**. Click ![en-us_image_0000001259987441](figures/en-us_image_0000001259987441.png)**Feature** and set **FontSize** to **40px**. Then, select the **Button** component on the canvas and drag its corners to fully display the text. Below is an illustration of the operations.

   ![en-us_image_0000001261017331](figures/en-us_image_0000001261017331.gif)


## Implementing Page Redirection

You can implement page redirection through the [page router](../ui/ui-js-building-ui-routes.md), which finds the target page based on the page URL. Import the **router** module and then perform the steps below:

1. Implement redirection from the first page to the second page.
   
   In the files of the first page, bind the **onclick** method to the button so that clicking the button redirects the user to the second page. This operation needs to be completed in both .js and .visual files.
   
   - In the **index.js** file:
     
     ```js
     import router from '@ohos.router';  
     
     export default {     
         onclick() {         
             router.push({             
                 url:'pages/second/second', // Specify the page to be redirected to.
             })     
         } 
     }
     ```
   
   - In the index.visual file, select the **Button** component on the canvas. In the **Attributes &amp; Styles** area, click ![en-us_image_0000001215388136](figures/en-us_image_0000001215388136.png)**Events** and set **Click** to **onclick**.
   
       ![en-us_image_0000001223722586](figures/en-us_image_0000001223722586.png)
   
2. Implement redirection from the second page to the first page.

   In the files of the second page, bind the **back** method to the **Back** button so that clicking the button redirects the user back to the first page.

   This operation needs to be completed in both .js and .visual files.

   - In the **second.js** file:
     
      ```js
      import router from '@ohos.router';  
      
      export default {     
          back() {         
              router.back()     
          } 
      }
      ```
   - In the **second.visual** file, select the **Button** component on the canvas. In the **Attributes &amp; Styles** area, click ![en-us_image_0000001215388262](figures/en-us_image_0000001215388262.png)**Events** and set **Click** to **back**.

     ![en-us_image_0000001268082945](figures/en-us_image_0000001268082945.png)

3. Open the **index.visual** or **index.js** file and click ![en-us_image_0000001261979271](figures/en-us_image_0000001261979271.png) in the Previewer to refresh the file. The figure below shows the effect.

   ![en-us_image_0000001261142799](figures/en-us_image_0000001261142799.png)


## Running the Application on a Real Device

1. Connect the development board running the OpenHarmony standard system to the computer.

2. Choose **File** &gt; **Project Structure** &gt; **Project** &gt; **Signing Configs**, select **Automatically generate signing**, wait until the automatic signing is complete, and click **OK**, as shown below.

   ![en-us_image_0000001268283201](figures/en-us_image_0000001268283201.png)

3. On the toolbar in the upper right corner of the editing window, click ![en-us_image_0000001262207811](figures/en-us_image_0000001262207811.png). The display effect is shown in the figure below.

   ![en-us_image_0000001262127855](figures/en-us_image_0000001262127855.png)

Congratulations! You have finished developing your OpenHarmony app in JavaScript in the low-code approach. To learn more about OpenHarmony, see [OpenHarmony Overview](../application-dev-guide.md)
