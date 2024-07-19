# DataAbility Switching


The DataAbility component in the FA model corresponds to the DataShareExtensionAbility component in the stage model.


The DataShareExtensionAbility class provides system APIs. Only system applications can create DataShareExtensionAbility instances. Therefore, DataAbility switching adopts different policies for system applications and third-party applications.  


## Switching a DataAbility for a System Application

The procedure for switching a DataAbility for a system application is similar to the procedure of PageAbility switching.

1. Create a DataShareExtensionAbility in the stage model.

2. Migrate the DataAbility code to the DataShareExtensionAbility.
     
     The table below describes the lifecycle comparison of the DataAbility and DataShareExtensionAbility.
     | DataAbility| DataShareExtensionAbility| Comparison Description|
   | -------- | -------- | -------- |
   | onInitialized?(info: AbilityInfo): void | onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void<br> | The two methods have the same invoking time but different input parameters. In the stage model, the **want** parameter is added so that you can obtain parameters during creation.|
   | update?(uri: string, valueBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback&lt;number&gt;): void | update?(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | The two methods have the same meaning and invoking time, but slightly different parameter sequence and parameter type. A simple reconstruction is required.|
   | query?(uri: string, columns: Array&lt;string&gt;, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback&lt;ResultSet&gt;): void | query?(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void;| The two methods have the same meaning and invoking time, but slightly different parameter sequence and parameter type. A simple reconstruction is required.|
   | delete?(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback&lt;number&gt;): void | delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;):| The two methods have the same meaning and invoking time, but slightly different parameter type. A simple reconstruction is required.|
   | normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void| normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void| The two methods have the same meaning, invoking time, and parameters.|
   | batchInsert?(uri: string, valueBuckets: Array&lt;rdb.ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void | batchInsert?(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void| The two methods have the same meaning and invoking time, but slightly different parameter type. A simple reconstruction is required.|
   | denormalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void | denormalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void | The two methods have the same meaning, invoking time, and parameters.|
   | insert?(uri: string, valueBucket: rdb.ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | insert?(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | The two methods have the same meaning and invoking time, but slightly different parameter type. A simple reconstruction is required.|
   | openFile?(uri: string, mode: string, callback: AsyncCallback&lt;number&gt;): void | NA | The stage model does not support cross-process URI access. You are advised to use [the **want** parameter to carry the file descriptor and file information](file-processing-apps-startup.md) for cross-process file access.|
   | getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void | NA | The stage model does not support cross-process URI access. You are advised to use [the **want** parameter to carry the file descriptor and file information](file-processing-apps-startup.md) for cross-process file access.|
   | getType?(uri: string, callback: AsyncCallback&lt;string&gt;): void | NA | The stage model does not support cross-process URI access. You are advised to use [the **want** parameter to carry the file descriptor and file information](file-processing-apps-startup.md) for cross-process file access.|
   | executeBatch?(ops: Array&lt;DataAbilityOperation&gt;, callback: AsyncCallback&lt;Array&lt;DataAbilityResult&gt;&gt;): void | NA | This method is not provided in the stage model. You need to implement the functionality based on service functions.|
   | call?(method: string, arg: string, extras: PacMap, callback: AsyncCallback&lt;PacMap&gt;): void | NA | This method is not provided in the stage model. You need to implement the functionality based on service functions.|


## Switching a DataAbility for a Third-Party Application

In the stage model, third-party applications cannot provide data services for other third-party applications. You can select a switching solution based on your service requirements.

| Service Type| Switching Solution|
| -------- | -------- |
| Providing data for third-party applications| Match a scenario-specific [ExtensionAbility](../reference/apis-ability-kit/js-apis-bundleManager.md#extensionabilitytype).|
| Providing data within the application| Extract the component code as a common module for other components to use.|
