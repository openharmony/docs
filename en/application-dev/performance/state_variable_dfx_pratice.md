# State Variable Component Location Tool Practice

## Overview

A variable in a customized component becomes a state variable after being decorated by a state decorator (such as @State and @Prop). The change of the state variable causes the rendering and refreshing of the UI component that uses the variable. Improper use of state variables may cause performance problems such as redundant refresh. Developers can use the status variable component locating tool to obtain status management information, such as status variables of customized components, synchronization objects of status variables, and associated components, understand the scope of status variables affecting the UI, and write high-performance application code.

This document uses scenario examples to provide developers with practice guidance on the status variable component locating tool, and explains the debugging commands and output results related to the tool.

## Usage Process

The status variable component locating tool uses specific commands in the HiDumper tool to obtain component and status management information. Developers can use the tool to view the status variables of a specified customized component and understand the scope of components affected by each status variable.

The process of using the tool can be divided into the following steps:

1. Open the page where the component is located on the device.

2. Obtains the window ID of an application.

3. Obtain the customized component tree of the application based on the application window ID and find the target component and its node ID.

4. Obtain the status variable information of the component based on the component node ID obtained in the previous step.

5. Find the target state variable and see the scope of components it affects.

After determining the status variables contained in the target component and the component update scope affected by the variables, developers can analyze whether the status variables are used improperly based on requirements, and analyze and optimize the corresponding code.

## Scenario Examples

The following uses a scenario where a component is refreshed when a button is clicked to change the status variable as an example to provide practical guidance for developers. The scenario example shows only some key code. For details about the complete code, visit [Sample Code] (https://gitee.com/openharmony/applications_app_samples/blob/master/code/Performance/PerformanceLibrary/feature/DFXStateManagement/src/main/ets/view/DFXStateBeforeOptimization.ets).

In the following code, customized components ComponentA and SpecialImage are created. Each component has some status variables and UI components. ComponentA has the Move and Scale buttons. When a button is clicked, the value of the status variable is changed to refresh the corresponding component.
```javascript
// feature/DFXStateManagement/src/main/ets/view/DFXStateBeforeOptimization.ets  

//Constant declaration
// ... 
// Style attribute class. 
class UIStyle {  
  public translateX: number = 0;  
  public translateY: number = 0;  
  public scaleX: number = 0.3;  
  public scaleY: number = 0.3;  
}  
@Component  
struct ComponentA {  
  The attributes of @Link uiStyle: UIStyle; // uiStyle are used by multiple components. 
  build() {  
    Column() {  
      //Components that use state variables 
      SpecialImage({ specialImageUiStyle: this.uiStyle })  
      Stack() {  
        Column() {  
          Image($r('app.media.icon'))  
            .scale({  
              x: this.uiStyle.scaleX,  
              y: this.uiStyle.scaleY  
            })  
        }  
        Stack() {  
          Text('Hello World')  
        }  
      }  
      .translate({  
        x: this.uiStyle.translateX,  
        y: this.uiStyle.translateY  
      })  
  
      //Change the value of the status variable through button click callback to cause the corresponding component to be refreshed. 
      Column() {  
        Button('Move')  
          .onClick(() => {  
            animateTo({ duration: animationDuration }, () => {  
              this.uiStyle.translateY = (this.uiStyle.translateY + translateYChangeValue) % translateYChangeRange;  
            })  
          })  
        Button('Scale')  
          .onClick(() => {  
            this.uiStyle.scaleX = (this.uiStyle.scaleX + scaleXChangeValue) % scaleXChangeRange;  
          })  
      }  
    }  
  }  
}  
@Component  
struct SpecialImage {  
  @Link specialImageUiStyle: UIStyle;  
  private opacityNum: number = 0.5; //default transparency 
  private isRenderSpecialImage(): number {  
    //The transparency of the image is increased by 0.1 each time the image is rendered. The transparency ranges from 0 to 1. 
    this.opacityNum = (this.opacityNum + opacityChangeValue) % opacityChangeRange;  
    return this.opacityNum;  
  }  
  build() {  
    Column() {  
      Image($r('app.media.icon'))  
        .scale({  
          x: this.specialImageUiStyle.scaleX,  
          y: this.specialImageUiStyle.scaleY  
        })  
        .opacity(this.isRenderSpecialImage())  
      Text("SpecialImage")  
    }  
  }  
}  
//Root component of the page, which is the parent component of ComponentA.
```

Run the preceding example and click. You can see that the SpecialImage component is refreshed when you click Move and Scale, as shown in the following figure.

![](./figures/state_viariable_dfx_pratice_pic1.gif) 

The following uses the customized component ComponentA and the status variable uiStyle as an example to describe how to use the tool.

1. Open the application on the device and go to the page where ComponentA is located.

2. Run the following command to obtain the window ID of the sample application: The name of the running sample application package is performancelibrary. You can find WinId corresponding to the window name performancelibrary0 in the command output, which is the window ID of the application. When the application is running in the foreground, the value of Focus window is the window ID of the application. In this example, the window ID of the application is 11. The window ID must be specified for commands used in subsequent processes.
```shell
hdc shell "hidumper -s WindowManagerService -a '-a'"
```
![](./figures/state_viariable_dfx_pratice_pic2.png) 

3. Based on the window ID 11 obtained in the previous step, use the -viewHierarchy command with the -r parameter to recursively print the customized component tree of the application. Find the target component ComponentA in the command output. The content in the brackets is the node ID 70 of ComponentA.
```shell
hdc shell "hidumper -s WindowManagerService -a '-w 11 -jsdump -viewHierarchy -r'"
```
```shell
-----------------ViewPU Hierarchy-----------------  
[-viewHierarchy, viewId=4, isRecursive=true]  
|--Index[4]  
-----------------ViewPU Hierarchy-----------------  
[-viewHierarchy, viewId=53, isRecursive=true]  
|--DFXStateManagementPage[53]  
  |--DFXStateManagementHome[55]  
-----------------ViewPU Hierarchy-----------------  
[-viewHierarchy, viewId=65, isRecursive=true]  
|--DFXStateBeforeOptimizationPage[65]  
  |--DFXStateBeforeOptimization[67]  
    |--ComponentA[70]  
      |--SpecialImage[73]
```
4. Run the -stateVariables command with the -viewId parameter (the parameter value is the node ID of ComponentA) to obtain the status variable information of ComponentA. The result shows that ComponentA has the state variable uiStyle of the @Link/@Consume type. The details of each state variable contain the owning component, synchronization object, and associated component of the state variable.
```shell
hdc shell "hidumper -s WindowManagerService -a '-w 11 -jsdump -stateVariables -viewId=70'"
```
```shell
--------------ViewPU State Variables--------------  
[-stateVariables, viewId=70, isRecursive=false]  
|--ComponentA[70]  
  @Link/@Consume (class SynchedPropertyTwoWayPU) 'uiStyle'[71]  
  |--Owned by @Component 'ComponentA'[70]  
  |--Sync peers: {  
    @Link/@Consume (class SynchedPropertyTwoWayPU) 'specialImageUiStyle'[74] <@Component 'SpecialImage'[73]>  
  }  
  |--Dependent components: 2 elmtIds: 'Stack[75]', 'Image[77]'
```
5. The state variable uiStyle is used as an example.

1. Sync peers indicates that uiStyle has the status variable specialImageUiStyle of the @Link/@Consume type in the customized component SpecialImage to subscribe to data changes.

2. Dependent components indicates that Stack[79] and Image[81] in ComponentA use the state variable uiStyle, and the number of associated components is 2.

Therefore, when uiStyle changes, the customized component SpecialImage and system components Stack[79] and Image[81] are affected.

![](./figures/state_viariable_dfx_pratice_pic3.png) 

In the example, the SpecialImage component uses only the scaleX and scaleY attributes transferred from uiStyle to specialImageUiStyle, however, when you click Move to modify the translateY attribute in uiStyle, the uiStyle change also causes the update of the SpecialImage component. Therefore, you can extract the scaleX and scaleY attributes in uiStyle to the status variable scaleStyle, the translateX and translateY attributes are extracted to the state variable translateStyle. Only scaleStyle is transferred to the component SpecialImage to avoid unnecessary update.

Class nesting exists after extraction. Therefore, you need to use the @Observed/@ObjectLink decorator to decorate the corresponding class and status variables. The modified code is as follows. You can obtain the complete code from [Sample Code] (https://gitee.com/openharmony/applications_app_samples/blob/master/code/Performance/PerformanceLibrary/feature/DFXStateManagement/src/main/ets/view/DFXStateAfterOptimization.ets).
```javascript
// feature/DFXStateManagement/src/main/ets/view/DFXStateAfterOptimization.ets

//Constant declaration
// ...
// Style attribute class, nested ScaleStyle, TranslateStyle 
@Observed  
class UIStyle {  
  translateStyle: TranslateStyle = new TranslateStyle();  
  scaleStyle: ScaleStyle = new ScaleStyle();  
}  
// Zoom attribute class. 
@Observed  
class ScaleStyle {  
  public scaleX: number = 0.3;  
  public scaleY: number = 0.3;  
}  
//Displacement attribute class 
@Observed  
class TranslateStyle {  
  public translateX: number = 0;  
  public translateY: number = 0;  
}  
@Component  
struct ComponentA {  
  @ObjectLink scaleStyle: ScaleStyle;  
  @ObjectLink translateStyle: TranslateStyle;  
  
  build() {  
    Column() {  
      SpecialImage({  
        specialImageScaleStyle: this.scaleStyle  
      })  
      //Other UI components 
    }  
  }  
}  
  
@Component  
struct SpecialImage {  
  @Link specialImageScaleStyle: ScaleStyle;  
  //isRenderSpecialImage function 
  build() {  
    Column() {  
      Image($r('app.media.icon'))  
        .scale({  
          x: this.specialImageScaleStyle.scaleX,  
          y: this.specialImageScaleStyle.scaleY  
        })  
        .opacity(this.isRenderSpecialImage())   
      Text("SpecialImage")  
    }
  }  
}
//Root component of the page, which is the parent component of ComponentA.
```

The following figure shows the running effect of the modified example. The SpecialImage is refreshed only when the Scale button is clicked. The SpecialImage is not refreshed when the Move button is clicked.

![](./figures/state_viariable_dfx_pratice_pic4.gif) 

You can perform the preceding steps to obtain the status variable information of ComponentA again. The status variable scaleStyle in ComponentA affects SpecialImage[74] and Image[78], and the status variable translateStyle affects Stack[76], the change of translateStyle does not cause the update of SpecialImage.
```shell
--------------ViewPU State Variables--------------  
[-stateVariables, viewId=70, isRecursive=false]  
  
|--ComponentA[70]  
  @ObjectLink (class SynchedPropertyNestedObjectPU) 'scaleStyle'[71]  
  |--Owned by @Component 'ComponentA'[70]  
  |--Sync peers: {  
    @Link/@Consume (class SynchedPropertyTwoWayPU) 'specialImageScaleStyle'[75] <@Component 'SpecialImage'[74]>  
  }  
  |--Dependent components: 1 elmtIds: 'Image[78]'  
  @ObjectLink (class SynchedPropertyNestedObjectPU) 'translateStyle'[72]  
  |--Owned by @Component 'ComponentA'[70]  
  |--Sync peers: none  
  |--Dependent components: 1 elmtIds: 'Stack[76]'
```
## Debugging Commands and Outputs

The following uses a simple example program of three-layer nesting of customized components to describe the debugging commands and output results of the tool in detail.
```javascript
@Entry  
@Component  
struct Index {  
  @State indexMessage: string = 'Hello World';  
  build() {  
    Row() {  
      Column() {  
        Text(this.indexMessage)  
        ComponentA({ componentAMessage: this.indexMessage })  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
@Component  
struct ComponentA {  
  @Link componentAMessage: string;  
  build() {  
    Column() {  
      ComponentB({ componentBMessage: this.componentAMessage })  
    }  
  }  
}  
@Component  
struct ComponentB {  
  @Link componentBMessage: string;  
  build() {  
    Column() {  
      Text(this.componentBMessage)  
    }  
  }  
}
```
1. Check the application window ID. You can find WinId, that is, the application window ID, based on WindowName of the application in the window list. (The bundle name of the example application is dfxdemo, and the default WindowName is dfxdemo0.) In the result, Focus window indicates the ID of the window displayed on the current page. When the application is running in the foreground, the value of Focus window is the application window ID.
```shell
hdc shell "hidumper -s WindowManagerService -a '-a'"
```
![](./figures/state_viariable_dfx_pratice_pic5.png) 

2. Prints the customized component tree.

By default, only the root node and its child custom components are printed. In the preceding command, 11 indicates the window ID, which can be obtained by running the command for viewing the application window ID. In the result, the information in the format of Index[4] is the name of the user-defined component, and the number in the square brackets ([]) is the node ID of the component.
```shell
hdc shell "hidumper -s WindowManagerService -a '-w 11 -jsdump -viewHierarchy'"
```
```shell
-----------------ViewPU Hierarchy-----------------  
[-viewHierarchy, viewId=4, isRecursive=false]  
|--Index[4]  
  |--ComponentA[9]
```
If the -viewId parameter is carried, the customized component of the specified viewId and the customized component of the sub-level of the component can be printed. Only the node ID of a customized component can be used as the value of -viewId. Take -viewId=9 as an example. You can obtain the customized component ComponentA whose viewId is 9 and its child customized component ComponentB.
```shell
hdc shell "hidumper -s WindowManagerService -a '-w 11 -jsdump -viewHierarchy -viewId=9'"
```
```shell
-----------------ViewPU Hierarchy-----------------  
[-viewHierarchy, viewId=9, isRecursive=false]  
|--ComponentA[9]  
  |--ComponentB[12]
```
Prints the customized component tree recursively starting from the root node with the -r parameter. For example, the output of the following command is the root node Index and each level of customized components, which are displayed in a tree structure.
```shell
hdc shell "hidumper -s WindowManagerService -a '-w 11 -jsdump -viewHierarchy -r'"
```
```shell
-----------------ViewPU Hierarchy-----------------  
[-viewHierarchy, viewId=4, isRecursive=true]  
|--Index[4]  
  |--ComponentA[9]  
    |--ComponentB[12]
```
3. Displays the status variable information of a customized component. Each piece of information contains the component to which the variable belongs, Sync peers (synchronization object), and Dependent components (associated components). When the state variable changes, its Dependent components and the Dependent components of Sync peers are dirty nodes. By default, the root node is printed.
```shell
hdc shell "hidumper -s WindowManagerService -a '-w 11 -jsdump -stateVariables'"
```
```shell
--------------ViewPU State Variables--------------  
--Index[4]  
  @State/@Provide (class ObservedPropertyPU) 'indexMessage'[5]  
  |--Owned by @Component 'Index'[4]  
  |--Sync peers: {  
    @Link/@Consume (class SynchedPropertyTwoWayPU) 'componentAMessage'[9] <@Component 'ComponentA'[8]>  
  }  
  |--Dependent components: 1 elmtIds: 'Text[8]'
```
- @State/@Provide: decorator type of the state variable.
- 'message'[5]: name and node ID of the status variable. However, -viewId=5 cannot be used to obtain the corresponding dump information.
- Owned by @Component'Index'[4]: component to which the status variable belongs.
- Sync peers: other state variables to be synchronized and the components to which the variables belong.
- Dependent components: ID of the node associated with the current status variable in the component, that is, the node ID of the system or customized component that depends on the variable.

**NOTE**

-stateVariables can print only the status variable information of a specified viewId. Recursive printing is not supported. Therefore, you can only obtain the status variable information of a single customized component for level-by-level analysis. Currently, you cannot view all components affected by a status variable globally.

4. Displays all information, including information about the customized component tree and status variables. If no node is specified, the root node is printed by default. If the -viewId parameter is carried, information about the specified node is printed. If the -r parameter is carried, information about the specified node is printed recursively.
```shell
hdc shell "hidumper -s WindowManagerService -a '-w 11 -jsdump -dumpAll'"
```
The following figure shows the command output.

![](./figures/state_viariable_dfx_pratice_pic6.png) 

1. Customized component tree, corresponding to the -viewHierarchy command.

2. Status variable information, corresponding to the -stateVariables command.

If the dumpAll command contains the -r and -viewId parameters, the command output is the same as that when the dumpAll command contains the corresponding parameters.

## References

[Scenario Sample Code] (https://gitee.com/openharmony/applications_app_samples/tree/master/code/Performance/PerformanceLibrary/feature/DFXStateManagement/src/main/ets/view)

[Using the HiDumper Command Line Tool to Optimize Performance] (performance-optimization-using-hidumper.md)

[Precise Control of Component Update Scope] (precisely-control-render-scope.md)
