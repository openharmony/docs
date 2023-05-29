# Want Overview


## Definition and Usage of Want

[Want](../reference/apis/js-apis-app-ability-want.md) is an object that transfers information between application components. It is often used as a parameter of [startAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability). For example, when UIAbilityA needs to start UIAbilityB and transfer some data to UIAbilityB, it can use the **want** parameter in **startAbility()** to transfer the data.

**Figure 1** Want usage 

![usage-of-want](figures/usage-of-want.png)  


## Types of Want

- **Explicit Want**: If **abilityName** and **bundleName** are specified in the **want** parameter when starting an an application component, explicit Want is used.
  
    Explicit Want is usually used to start a known target application component in the same application. The target application component is started by specifying **bundleName** of the application where the target application component is located and **abilityName** in the **Want** object. When there is an explicit object to process the request, explicit Want is a simple and effective way to start the target application component.
  
  ```ts
  let wantInfo = {
    deviceId: '', // An empty deviceId indicates the local device.
    bundleName: 'com.example.myapplication',
    abilityName: 'FuncAbility',
  }
  ```
  
- **Implicit Want**: If **abilityName** is not specified in the **want** parameter when starting the an application component, implicit Want is used.
  
  Implicit Want can be used when the object used to process the request is unclear and the current application wants to use a capability (defined by the [skills tag](../quick-start/module-configuration-file.md#skills)) provided by another application. The system matches all applications that declare to support the capability. For example, for a link open request, the system matches all applications that support the request and provides the available ones for users to select.
  
  
  ```ts
  let wantInfo = {
    // Uncomment the line below if you want to implicitly query data only in the specific bundle.
    // bundleName: 'com.example.myapplication',
    action: 'ohos.want.action.search',
    // entities can be omitted.
    entities: [ 'entity.system.browsable' ],
    uri: 'https://www.test.com:8080/query/student',
    type: 'text/plain',
  };
  ```
  
  > **NOTE**
  > - Depending on the application component matching result, the following cases may be possible when you attempt to use implicit Want to start the application component.
  >   - No application component is matched. The startup fails.
  >   - An application component that meets the conditions is matched. That application component is started.
  >   - Multiple application components that meet the conditions are matched. A dialog box is displayed for users to select one of them.
  > 
  > - If the **want** parameter passed does not contain **abilityName** or **bundleName**, the ServiceExtensionAbility components of all applications cannot be started through implicit Want.
  > 
  > - If the **want** parameter passed contains **bundleName**, the **startServiceExtensionAbility()** method can be used to implicitly start ServiceExtensionAbility. By default, ServiceExtensionAbility with the highest priority is returned. If all the matching ServiceExtensionAbility components have the same priority, the first ServiceExtensionAbility is returned.
