# Want Overview


## Definition and Usage of Want

[Want](../reference/apis/js-apis-app-ability-want.md) is used as the carrier to transfer information between application components. It is used as a parameter of **startAbility()** to specify the startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. For example, when UIAbilityA starts UIAbilityB and needs to transfer some data to UIAbilityB, it can use Want to transfer the data.

**Figure 1** Want usage 
<img src="figures/usage-of-want.png" alt="usage-of-want" style="zoom:80%;" />


## Types of Want

- **Explicit Want**: A type of Want with **abilityName** and **bundleName** specified when starting an ability.
    When there is an explicit object to process the request, the target ability can be started by specifying the bundle name and ability name in Want. Explicit Want is usually used to start a known ability.
    
  ```ts
  let wantInfo = {
      deviceId: '', // An empty deviceId indicates the local device.
      bundleName: 'com.example.myapplication',
      abilityName: 'FuncAbility',
  }
  ```

- **Implicit Want**: A type of Want with **abilityName** unspecified when starting the ability.
  Implicit Want can be used when the object used to process the request is unclear and the current application wants to use a capability (defined by the [skills tag](../quick-start/module-configuration-file.md#skills)) provided by another application. For example, you can use implicit Want to describe a request for opening a link, since you do not care which application is used to open the link. The system matches all applications that support the request.

  
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
  > - Depending on the ability matching result, the following cases may be possible when you attempt to use implicit Want to start the ability.
  >   - No ability is matched. The startup fails.
  >   - An ability that meets the conditions is matched. That ability is started.
  >   - Multiple abilities that meet the conditions are matched. A dialog box is displayed for users to select one of them.
  > 
  > - If the **want** parameter passed does not contain **abilityName** or **bundleName**, the ServiceExtensionAbility components of all applications cannot be started through implicit Want.
  > 
  > - If the **want** parameter passed contains **bundleName**, the **startServiceExtensionAbility()** method can be used to implicitly start ServiceExtensionAbility. By default, ServiceExtensionAbility with the highest priority is returned. If all the matching ServiceExtensionAbility components have the same priority, the first ServiceExtensionAbility is returned.
