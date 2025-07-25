# Compilation Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 10905301 @Watch Decorator Callback Function Is Not Defined
**Error Message**<br>
\'@Watch\' cannot be used with \'xxx\'. Apply it only to parameters that correspond to existing methods.  

**Description**<br>
This error code is reported when the callback function for the @Watch decorator is not defined.

**Possible Cause**<br>
The variable decorated with @Watch is defined in the struct, but the corresponding callback function is missing.

**Solution**<br>
Define a callback function with the same name in the struct to handle the watched variable.

## 10905101 @BuilderParam Initialization Error
**Error Message**<br>
\'@BuilderParam\' property can only initialized by \'@Builder\' function or \'@LocalBuilder\' method in struct.

**Description**<br>
This error code is reported when @BuilderParam decorated variables are initialized using methods other than those decorated by @Builder.

**Possible Causes**<br>
The @BuilderParam decorated variable is being initialized using a regular function or variable of another type.

**Solution**<br>
Define functions decorated by @LocalBuilder or @Builder and use them to initialize variables decorated by @BuilderParam.

## 10905302 Mixed Use of Multiple State Management Decorators
**Error Message**<br>
The property \'xxx\' cannot have multiple state management decorators.

**Description**<br>
This error code is reported when a variable is decorated by multiple state management decorators.

**Possible Cause**<br>
The same variable is decorated by multiple state management decorators.

**Solution**<br>
Use only one appropriate state management decorator for the variable.

## 10905303 State Variable Initialization Verification Exception
**Error Message**<br>
The \'xxx\' property \'yyy\' must be specified a default value.

**Description**<br>
This error code is reported when variables decorated by @State, @StorageLink, @StorageProp, @LocalStorageLink, @LocalStorageProp, or @Provide are not initialized.

**Possible Cause**<br>
Variables decorated by @State, @StorageLink, @StorageProp, @LocalStorageLink, @LocalStorageProp, or @Provide are not initialized.

**Solution**<br>
Initialize variables decorated by @State, @StorageLink, @StorageProp, @LocalStorageLink, @LocalStorageProp, and @Provide.

## 10905304 Failed to Verify the Initialization of a Specific Decorated Variable
**Error Message**<br>
The \'xxx\' property cannot be specified a default value.

**Description**<br>
This error code is reported when initialization is performed on variables decorated by decorators such as @Consume, @Link, and @ObjectLink.

**Possible Cause**<br>
Initialization is performed when defining variables decorated by decorators such as @Consume, @Link, and @ObjectLink.

**Solution**<br>
Do not initialize variables decorated by @Consume, @Link, and @ObjectLink. Refer to the correct value assignment rules for decorators.

## 10905305 Variable Type Verification Exception
**Error Message**<br>
The property \'xxx\' must specify a type.

**Description**<br>
This error code is reported when the type is not specified for a variable decorated by a decorator.

**Possible Cause**<br>
The type is not specified for a variable decorated by a decorator.

**Solution**<br>
Specify the type for the variable decorated by the decorator.

## 10905307 Failed to Verify the Specific Decorated Variable Type
**Error Message**<br>
\'@ObjectLink\' cannot be used with this type. Apply it only to classes decorated by \'@Observed\' or initialized using the return value of \'makeV1Observed\'.

**Description**<br>
This error code is reported when the type of a variable decorated by @ObjectLink is not a class or union type decorated by @Observed defined in an .ets file.

**Possible Cause**<br>
The variable decorated by @ObjectLink is initialized using a class that is not decorated by @Observed or another incompatible type.

**Solution**<br>
Ensure that class instances decorated by @Observed are used with @ObjectLink.

## 10905308 Failed to Verify the Decorator of a Specific Variable Type
**Error Message**<br>
The \'xxx\' property \'yyy\' cannot be a \'zzz\' object.

**Description**<br>
This error code is reported when a variable decorated by @State or other state decorators is of type CustomDialogController.

**Possible Cause**<br>
A state variable decorator is used on a variable of type CustomDialogController.

**Solution**<br>
Do not use state variable decorators on variables of type CustomDialogController.

## 10905309 Custom Decorator Name Verification Error
**Error Message**<br>
The decorator \'xxx\' cannot have the same name as the built-in style attribute \'yyy\'. 

**Description**<br>
This error code is reported when a custom decorator has the same name as a built-in property.

**Possible Cause**<br>
The custom decorator name conflicts with a built-in property name.

**Solution**<br>
Rename the custom decorator to avoid conflicts with built-in property names.

## 10905310 @Watch Decorator Verification Error
**Error Message**<br>
Regular variable \'xxx\' can not be decorated with \'@Watch\'. 

**Description**<br>
This error code is reported when a regular variable is decorated by @Watch.

**Possible Cause**<br>
The @Watch decorator is used on a regular variable.

**Solution**<br>
Use @Watch only on state variables decorated by appropriate state variable decorators, such as @State.

## 10905311 @Watch Decorator Parameter Verification Error
**Error Message**<br>
\'@Watch\' cannot be used with \'xxx\'. Apply it only to \'string\' parameters.

**Description**<br>
This error code is reported when the parameter of the @Watch decorator is not a string.

**Possible Cause**<br>
A non-string value is used as the parameter for the @Watch decorator.

**Solution**<br>
Ensure that the parameter of the @Watch decorator is a string.

## 10905312 Custom Decorator Verification Exception
**Error Message**<br>
The inner decorator \'xxx\' cannot be used together with custom decorator.

**Description**<br>
This error code is reported when built-in component decorators such as @State are used together with custom decorators.

**Possible Cause**<br>
A custom decorator is applied to a variable that already has a built-in component decorator, such as @State.

**Solution**<br>
Avoid using both state variable decorators (such as @State) and custom decorators on the same variable.

## 10905201 Parent Component Verification Error
**Error Message**<br>
The \'xxx\' component can only be nested in the \'yyy\' parent component.

**Description**<br>
This error code is reported when a component's parent is not the specified parent component.

**Possible Cause**<br>
The parent component of a component (for example, **Blank**) is not within the allowed range of parent components.

**Solution**<br>
Modify the parent component or add an intermediate component based on the error description.

## 10905202 Failed to Verify the Child Component of the Button Component
**Error Message**<br>
The Button component with a label parameter can not have any child.

**Description**<br>
This error code is reported when a **Button** component with a label contains child components.

**Possible Cause**<br>
The **Button** component includes both a label and child components, which is not allowed.

**Solution**<br>
Remove either the label content or the child component content (including the braces).

## 10905203 .stateStyles Syntax Check Error
**Error Message**<br>
\'.stateStyles\' doesn't conform standard.

**Description**<br>
This error code is reported when the **stateStyles** property does not comply with the syntax.

**Possible Cause**<br>
The **stateStyles** property is incorrectly specified or does not conform to the required syntax.

**Solution**<br>
Ensure that different states in **stateStyles** are correctly specified.

## 10905204 UI Component Syntax Check Error
**Error Message**<br>
\'xxx\' does not meet UI component syntax.

**Description**<br>
This error code is reported when a statement does not comply with the UI component syntax.

**Possible Cause**<br>
The code does not follow the basic UI component syntax.

**Solution**<br>
Modify the syntax according to the correct UI component syntax.

## 10905207 Failed to Verify the then Clause of the if Statement
**Error Message**<br>
Then statement cannot be null in if statement.

**Description**<br>
This error code is reported when the **if** statement is missing a **then** clause.

**Possible Cause**<br>
The **then** statement in the **if** syntax is empty.

**Solution**<br>
Add a valid **then** clause after the **if** statement.

## 10905208 Failed to Verify the Judgment Condition of the if Statement
**Error Message**<br>
Condition expression cannot be null in if statement.

**Description**<br>
This error code is reported when the **if** statement is missing a condition.

**Possible Cause**<br>
The judgment condition of the **if** statement is empty.

**Solution**<br>
Add a valid condition to the **if** statement.

## 10905102 @BuilderParam Tail Closure Scenario Verification Exception
**Error Message**<br>
In the trailing lambda case, \'xxx\' must have one and only one property decorated with \'@BuilderParam\', and its \'@BuilderParam\' expects no parameter.

**Description**<br>
This error code is reported when multiple variables decorated by @BuilderParam are defined in the trailing closure scenario, or a variable decorated by @BuilderParam contains parameters.

**Possible Cause**<br>
In the trailing closure scenario, there can be only one variable decorated by @BuilderParam (excluding parameters).

**Solution**<br>
Remove unnecessary @BuilderParam decorators and retain only one @BuilderParam decorator without parameters.

## 10905209 UI Syntax Verification Error with the build() Method
**Error Message**<br>
Only UI component syntax can be written here.

**Description**<br>
This error code is reported when content other than UI syntax is used.

**Possible Cause**<br>
Non-UI syntax is used.

**Solution**<br>
Modify the syntax according to the correct UI component syntax.

## 10905210 Root Container Verification Error with the build() Method
**Error Message**<br>
In an \'@Entry\' decorated component, the \'build\' method can have only one root node, which must be a container component.

**Description**<br>
This error code is reported when multiple root containers are defined in the **build()** method.

**Possible Cause**<br>
Multiple root containers are defined in the build() method.

**Solution**<br>
Remove redundant root containers to ensure that the **build()** method has only one root container.

## 10905103 Failed to Verify the build() Method
**Error Message**<br>
The struct \'xxx\' must have at least and at most one 'build' method.

**Description**<br>
This error code is reported when multiple **build()** methods are defined in the struct component, or the **build()** method is missing.

**Possible Cause**<br>
Multiple **build()** methods are defined in the struct, or the **build()** method is missing.

**Solution**<br>
Define only one **build()** method in the struct.

## 10905211 Failed to Verify @CustomDialog Member Properties
**Error Message**<br>
The \'@CustomDialog\' decorated custom component must contain a property of the CustomDialogController type.

**Description**<br>
This error code is reported when a custom component decorated by @CustomDialog lacks a member property of the CustomDialogController type.

**Possible Cause**<br>
The custom component decorated by @CustomDialog does not have a member property of the CustomDialogController type.

**Solution**<br>
Add a member property of the CustomDialogController type to the custom component decorated by @CustomDialog.

## 10905212 Struct Verification Error
**Error Message**<br>
Structs are not allowed to inherit from classes or implement interfaces.

**Description**<br>
This error code is reported when a struct is defined as a subclass or implementation of another class or API.

**Possible Cause**<br>
The struct extends another class or implements another API.

**Solution**<br>
Do not use structs to extend other classes or implement other APIs.

## 10905104 Failed to Verify the Static Method Decorator of the Custom Component
**Error Message**<br>
Static methods in custom components cannot be decorated by \'@LocalBuilder\'.

**Description**<br>
This error code is reported when the @LocalBuilder decorator is used on static methods in custom components.

**Possible Cause**<br>
The @LocalBuilder decorator is used on static methods.

**Solution**<br>
Remove the **static** keyword.

## 10905105 @Styles Decorator Verification Error
**Error Message**<br>
\'@Styles\' decorated functions and methods cannot have arguments.

**Description**<br>
This error code is reported when parameters are included in functions decorated by @Styles.

**Possible Cause**<br>
Parameters are included in functions decorated by @Styles.

**Solution**<br>
Remove the parameters from the @Styles decorator.

## 10905106 Failed to Verify the build() Method
**Error Message**<br>
The \'build\' method can not have arguments.

**Description**<br>
This error code is reported when parameters are included in the **build()** method.

**Possible Cause**<br>
Parameters are included in the **build()** method.

**Solution**<br>
Remove the parameters from the **build()** method.

## 10905313 Failed to Verify the Struct Variable
**Error Message**<br>
The static variable of struct cannot be used together with built-in decorators.

**Description**<br>
This error code is reported when a built-in decorator is used to decorate a static variable in the struct.

**Possible Cause**<br>
A built-in decorator is used to decorate a static variable in the struct.

**Solution**<br>
Do not use built-in decorators to decorate static variables in structs.

## 10905314 \$ Use Verification Error
**Error Message**<br>
Property \'xxx\' cannot initialize using \'\$\' to create a reference to a variable.

**Description**<br>
This error code is reported when $ is used incorrectly to decorate a variable. $ can only be used on child component attributes decorated by @Link.

**Possible Cause**<br>
The \$ symbol is used to decorate a property member that is decorated by @Prop or other property members not decorated by @Link in a child component.

**Solution**<br>
Use the @Link decorator to decorate the corresponding variable in the child component, or remove \$.

## 10905315 Parent and Child Component Value Verification Exception
**Error Message**<br>
The \'xxx\' property \'yyy\' cannot be assigned to the \'zzz\' property \'nnn\'.

**Description**<br>
This error code is reported when the value assignment between parent and child components is incorrect.

**Possible Cause**<br>
A regular variable is used to initialize a member variable decorated by @Link in a child component.

**Solution**<br>
Do not use regular variables to initialize member variables decorated by @Link in child components.

## 10905316 @Link Decorator Variable Initialization Verification Exception
**Error Message**<br>
The property \'xxx\' in the custom component \'yyy\' is missing (mandatory to specify).

**Description**<br>
This error code is reported when variables decorated by @Link are not initialized from the parent component.

**Possible Cause**<br>
The member variable decorated by @Link in the child component is not initialized when the parent component calls the child component.

**Solution**<br>
Initialize variables decorated by @Link from the parent component.

## 10905317 Failed to Verify the Initialization of a Decorated Variable
**Error Message**<br>
The property \'xxx\' in the custom component \'yyy\' cannot be initialized here (forbidden to specify).

**Description**<br>
This error code is reported when variables decorated by @StorageProp, @StorageLink, @Consume, or other decorators are initialized when a parent component calls a child component.

**Possible Cause**<br>
Member variables decorated by @StorageProp, @StorageLink, and @Consume are initialized when the parent component calls the child component.

**Solution**<br>
Correctly use variables decorated by the @StorageProp, @StorageLink, or @Consume decorator. For details, see the reference documentation of these decorators.

## 10905318 Verification Error During Parent-to-Child Transfer Using !! with a V2 Component
**Error Message**<br>
When the two-way binding syntax is used, the initial value of property \'xxx\' must be a variable.

**Description**<br>
This error code is reported when non-variables are used for parent-child transfer using **!!** with a V2 component.

**Possible Cause**<br>
Functions, constants, or literals are used for parent-child transfer using **!!** with a V2 component.

**Solution**<br>
When using **!!** with a V2 component for parent-child transfer, make sure only variables are used.

## 10905319 Child Component Variable Verification Error During !! Use with a V2 Component
**Error Message**<br>
When the two-way binding syntax is used, the variable \'xxx\' must be decorated with \'@Param\', and the \'@Event\' variable \'yyy\' must be defined in the \'zzz\'.

**Description**<br>
This error code is reported when @Param is not used together with @Event when **!!** is used with a V2 component.

**Possible Cause**<br>
When a V2 component is used, the child component variable is not decorated by @Param or the @Event decorated callback method is not defined.

**Solution**<br>
Use @Param to decorate child component variables and define the callback method decorated by @Event in the V2 scenario.

## 10905320 @Param Initialization Verification Error in the V2 Scenario
**Error Message**<br>
The optional character can not be used in the initial value of property \'xxx\'.

**Description**<br>
This error code is reported when optional symbols are used to transfer @Param decorated variables defined by child components in the V2 scenario.

**Possible Cause**<br>
In the V2 scenario, an optional symbol is used for initializing an @Param decorated variable in the child component.

**Solution**<br>
Avoid using optional symbols when initializing variables decorated by @Param in the V2 scenario.

## 10905321 Failed to Verify the Initialization of @Prop and @BuilderParam Decorated Variables
**Error Message**<br>
\'@Required\' decorated \'xxx\' must be initialized through the component constructor.

**Description**<br>
This error code is reported when the initialization of the @Prop and @BuilderParam decorated variables is incorrect.

**Possible Cause**<br>
The @Require decorator is used with @Prop and @BuilderParam to decorate child component variables, but these variables fail to be initialized when the parent component calls the child component.

**Solution**<br>
Make sure variables decorated by @Require, @Prop, or @BuilderParam are initialized when the parent component calls the child component.

## 10905213 Incorrect Mixed Use of V1 and V2 Components
**Error Message**<br>
A V2 component cannot be used with any member property decorated by \'@Link\' in a V1 component.

**Description**<br>
This error code is reported when a V2 component is used together with the @Link decorator of a V1 component.

**Possible Cause**<br>
V1 components containing the @Link decorator are used within V2 components.

**Solution**<br>
Avoid using V1 components with the @Link decorator in V2 components.

## 10905323 V2 Decorator Decorated Properties Incorrectly Assigned to V1 Components
**Error Message**<br>
Property \'xxx\' in the \'@ComponentV2\' component \'yyy\' is not allowed to be assigned values here.

**Description**<br>
This error code is reported when a property decorated by a V2 decorator is assigned to a V1 component.

**Possible Cause**<br>
The V1 component called is assigned with a property decorated by a V2 decorator.

**Solution**<br>
Do not assign values of properties decorated by V2 decorators to V1 components.

## 10905324 Incorrect Initialization of a Specific Decorated Variable
**Error Message**<br>
The \'xxx\' property \'yyy\' in the custom component \'zzz\' cannot be initialized here (forbidden to specify).

**Description**<br>
This error code is reported when variables decorated by specific decorators are initialized during parent-child component calls.

**Possible Cause**<br>
A variable decorated by a specific decorator in a child component is not correctly initialized when called in the parent component.

**Solution**<br>
Follow the usage guidelines of the specific decorators.

## 10905325 Incorrect Use of @Require in the V2 Scenario
**Error Message**<br>
In a struct decorated with \'@ComponentV2\', \'@Require\' can only be used with \'@Param\'.

**Description**<br>
This error code is reported when the @Require decorator is used with a decorator other than @Param in the V2 scenario.

**Possible Cause**<br>
The @Require decorator is used with a decorator other than @Param in the V2 scenario.

**Solution**<br>
Use @Require together with @Param.

## 10905326 Incorrect Use of @Once in the V2 Scenario
**Error Message**<br>
When a variable decorated with \'@Once\', it must also be decorated with \'@Param\'.

**Description**<br>
This error code is reported when the @Once decorator is used without the @Param decorator in the V2 scenario.

**Possible Cause**<br>
The variable decorated by @Once is not decorated by @Param in the V2 scenario.

**Solution**<br>
Use @Once together with @Param.

## 10905327 Failed to Verify the Default Value of @Param in the V2 Scenario
**Error Message**<br>
When a variable decorated with \'@Param\' is not assigned a default value, it must also be decorated with \'@Require\'. 

**Description**<br>
This error code is reported when a variable decorated by @Param in a V2 component is not assigned a default value and is not decorated by @Require.

**Possible Cause**<br>
In the V2 scenario, the @Param decorator is used to decorate variables that are not assigned default values or decorated by the @Require decorator.

**Solution**<br>
Assign a default value to the variable decorated by @Param or decorate it with @Require.

## 10905107 @BuilderParam Initialization Error
**Error Message**<br>
\'@BuilderParam\' property can only be initialized by \'@Builder\' function.

**Description**<br>
This error code is reported when @BuilderParam decorated variables are initialized using methods other than those decorated by @Builder.

**Possible Cause**<br>
Other types of variables or regular functions are used to initialize variables decorated by @BuilderParam.

**Solution**<br>
Change the initial value of @BuilderParam to a function decorated by @Builder.

## 10905328 Failed to Verify the Member Type of a State Variable
**Error Message**<br>
The property \'xxx\' must specify a type.

**Description**<br>
This error code is reported when the member property type of a state variable fails verification.

**Possible Cause**<br>
The type of the state variable is not declared.

**Solution**<br>
Declare the type for the state variable. The type must meet the verification requirements.

## 10906217 Failed to verify Service Widget Parameters
**Error Message**<br>
\'@Entry\' doesn't support {} parameter in card. 

**Description**<br>
This error code is reported when @Entry in the service widget does not support the specified input parameter.

**Possible Cause**<br>
An invalid parameter is passed to @Entry in the service widget.

**Solution**<br>
Rectify the issue based on the error message.

## 10905108 @Extend Decorator Parameter Verification Error
**Error Message**<br>
\'xxx\' should have one and only one parameter.

**Description**<br>
This error code is reported when decorators such as @Extend do not have exactly one parameter.

**Possible Cause**<br>
When using decorators such as @Extend, no parameter is provided or multiple parameters are provided.

**Solution**<br>
Make sure decorators such as @Extend have exactly one parameter.

## 10903329 Resource Name Verification Exception
**Error Message**<br>
Unknown resource name \'xxx\'.

**Description**<br>
This error code is reported when the resource name fails verification.

**Possible Cause**<br>
The provided resource name is incorrect.

**Solution**<br>
Make sure the resource name is correct.

## 10903330 Resource Type Verification Exception
**Error Message**<br>
Unknown resource type \'xxx\'.

**Description**<br>
This error code is reported when the resource type fails verification.

**Possible Cause**<br>
The provided resource name is incorrect.

**Solution**<br>
Make sure the resource type is correct.

## 10903331 Resource Source Verification Exception
**Error Message**<br>
Unknown resource source \'xxx\'.

**Description**<br>
This error code is reported when the resource source fails verification.

**Possible Cause**<br>
The provided resource source is incorrect.

**Solution**<br>
Make sure the resource source is correct.

## 10905332 Resource Reference Format Verification Exception
**Error Message**<br>
Invalid resource file parameter. Enter a value in the format of \'xxx.yyy.zzz\'.

**Description**<br>
This error code is reported when the resource is incorrectly referenced.

**Possible Cause**<br>
The format used to reference resources is incorrect.

**Solution**<br>
Make sure the format used to reference resources is correct.

## 10904333 Resource Verification Exception
**Error Message**<br>
No such \'xxx\' resource in current module.

**Description**<br>
This error code is reported when the **\$rawfile\(\)** references a resource that does not exist.

**Possible Cause**<br>
The provided resource does not exist.

**Solution**<br>
Make sure the resource name and path used match those specified using **\$rawfile**.

## 10905109 wrapBuilder Parameter Verification Exception
**Error Message**<br>
The wrapBuilder\'s parameter should be a \'@Builder\' function.

**Description**<br>
This error code is reported when the parameter of **wrapBuilder** is not an @Builder decorated method.

**Possible Cause**<br>
a variable of another type or a regular function is used as the parameter of **wrapBuilder**.

**Solution**<br>
Change the parameter of **wrapBuilder** to an @Builder decorated method.

## 10905110 @Styles Verification Exception
**Error Message**<br>
\'@Styles\' decorated functions and methods cannot have arguments.

**Description**<br>
This error code is reported when the method decorated by the @Styles decorator contains parameters.

**Possible Cause**<br>
The method decorated by the @Styles decorator contains parameters.

**Solution**<br>
Remove the parameters from the @Styles decorated method.

## 10905111 Incorrect Mixed Use of @AnimatedExtend and @Extend
**Error Message**<br>
The function can not be decorated by \'@Extend\' and \'@AnimatedExtend\' at the same time.

**Description**<br>
This error code is reported when both @AnimatedExtend and @Extend decorators are used to decorate the same API.

**Possible Cause**<br>
Both the @AnimatedExtend and @Extend decorators are used to decorate the same API.

**Solution**<br>
Remove either the @Extend or @AnimatedExtend decorator.

## 10905112 Decorator Verification Error
**Error Message**<br>
\'xxx\' can not decorate the method.

**Description**<br>
This error code is reported when invalid decorators such as @State are used to decorate methods.

**Possible Cause**<br>
Property decorators such as @State are used to decorate methods.

**Solution**<br>
Do not use property decorators such as @State to decorate methods.

## 10905219 Incorrect Use of Child Components
**Error Message**<br>
The component \'xxx\' can only have the child component \'yyy\'.

**Description**<br>
This error code is reported when unsupported child components are used in components such as **ContainerSpan**.

**Possible Cause**<br>
A component such as **ContainerSpan** is used incorrectly with a child component outside the supported range.

**Solution**<br>
Change the child component to one within the specified range.

## 10905220 Incorrect Number of Child Components
**Error Message**<br>
The \'xxx\' component can have only one child component.

**Description**<br>
This error code is reported when components such as **Button** that allows only a single child component contains multiple child components.

**Possible Cause**<br>
Multiple child components are defined in a component that allows only a single child component.

**Solution**<br>
Make sure the component in question has only one child component.

## 10905221 Incorrect Number of Child Components of a Specific Component
**Error Message**<br>
When the component \'xxx\' set \'yyy\' as \'zzz\', it can only have a single child component. 

**Description**<br>
This error code is reported when multiple child components are defined for a specific component attribute that allows only a single child component.

**Possible Cause**<br>
Multiple child components are defined for a specific component attribute that allows only a single child component.

**Solution**<br>
Delete redundant child components of the specific component. Retain a maximum of one child component.

## 10905222 Failed to Verify Components Such as Image
**Error Message**<br>
The component \'xxx\' can't have any child.

**Description**<br>
This error code is reported when components such as **Image** contain braces (child components).

**Possible Cause**<br>
Child components are defined for components that do not allow child components, such as **Image**.

**Solution**<br>
Delete the child components.

## 10905223 Incorrect Number of Child Components of a Specific Component
**Error Message**<br>
When the component \'xxx\' set \'yyy\' as \'zzz\', it can't have any child. 

**Description**<br>
This error code is reported when child components are defined for the target component attribute that does not allow child components.

**Possible Cause**<br>
Child components are defined for the target component attribute that does not allow child components.

**Solution**<br>
Delete the child components from the target component.

## 10905113 Incorrect Use of @Extend
**Error Message**<br>
Use the \'xxx\' decorator only in the global scope.

**Description**<br>
This error code is reported when decorators such as @Extend is used to decorate a member property method of a class or struct.

**Possible Cause**<br>
A decorator such as @Extend is used in a class or struct.

**Solution**<br>
Follow the usage guidelines of decorators.

## 10905337 Incorrect Decorator Use
**Error Message**<br>
The \'xxx\' decorator can only be used with \'struct\'.

**Description**<br>
This error code is reported when a struct decorator is used to decorate non-structs.

**Possible Cause**<br>
Struct decorators such as @Component and @ComponentV2 are used to decorate non-structs, such as functions.

**Solution**<br>
Use the correct decorator based on the error message.

## 10905338 V2 Decorator Verification Error
**Error Message**<br>
The \'xxx\' decorator can only be used in a \'struct\' decorated with \'@ComponentV2\'.

**Description**<br>
This error code is reported when a V2 member decorator is used in a struct not decorated by @ComponentV2.

**Possible Cause**<br>
The V2 member decorator is used in a struct decorated by @Component.

**Solution**<br>
Apply the V2 member decorator according to the instructions provided in the error message.

## 10905339 V1 Decorator Verification Error
**Error Message**<br>
The \'xxx\' decorator can only be used in a \'struct\' decorated with \'@Component\'.

**Description**<br>
This error code is reported when the member decorator of V1 is used in a struct not decorated by @Component.

**Possible Cause**<br>
The V1 member decorator is used in a struct decorated by @ComponentV2.

**Solution**<br>
Apply the V1 member decorator according to the instructions provided in the error message.

## 10905224 An @Observed Decorated Class Cannot Inherit from an @ObservedV2 Decorated Class
**Error Message**<br>
A class decorated by \'@Observed\' cannot inherit from a class decorated by \'@ObservedV2\'.

**Description**<br>
This error code is reported when an @Observed decorated class inherits from an @ObservedV2 decorated class.

**Possible Cause**<br>
An @Observed decorated class inherits from an @ObservedV2 decorated class.

**Solution**<br>
Inherit from a class decorated by @Observed or change the class decorator to @ObservedV2.

## 10905225 An @ObservedV2 Decorated Class Cannot Inherit from an @Observed Decorated Class
**Error Message**<br>
A class decorated by \'@ObservedV2\' cannot inherit from a class decorated by \'@Observed\'.

**Description**<br>
This error code is reported when an @ObservedV2 decorated class inherits from an @Observed decorated class.

**Possible Cause**<br>
An @ObservedV2 decorated class inherits from an @Observed decorated class.

**Solution**<br>
Inherit from a class decorated by @ObservedV2 or change the class decorator to @Observed.

## 10905226 Incorrect Mixed Use of @Observed and @ObservedV2
**Error Message**<br>
A class can not be decorated by \'@Observed\' and \'@ObservedV2\' at the same time.

**Description**<br>
This error code is reported when a class is decorated by both @Observed and @ObservedV2.

**Possible Cause**<br>
Both @Observed and @ObservedV2 are used to decorate the same class.

**Solution**<br>
Retain only one appropriate class decorator.

## 10905340 Incorrect Use of Decorators Designed to Decorate Member Variables in a Class
**Error Message**<br>
The \'xxx\' can decorate only member variables in a \'class\'.

**Description**<br>
This error code is reported when decorators designed to decorate member variables in a class are used to decorate methods instead.

**Possible Cause**<br>
Decorators designed to decorate member variables in a class, such as @Type, are used to decorate methods instead.

**Solution**<br>
Remove the decorators in question from methods in the class.

## 10905341 Incorrect Mixed Use of @Type and @Observed
**Error Message**<br>
The \'xxx\' decorator can not be used in a \'class\' decorated with \'@Observed\'.

**Description**<br>
This error code is reported when the decorator used in an @Observed decorated class is not supported.

**Possible Cause**<br>
The decorator used in an @Observed decorated class is not supported.

**Solution**<br>
Remove the unsupported decorator.

## 10905342 Incorrect Mixed Use of @Type and @Sendable
**Error Message**<br>
The \'xxx\' decorator can not be used in a \'class\' decorated with \'@Sendable\'.

**Description**<br>
This error code is reported when the decorator used in an @Sendable decorated class is not supported.

**Possible Cause**<br>
The decorator used in an @Sendable decorated class is not supported.

**Solution**<br>
Remove the unsupported decorator.

## 10905343 Incorrect Use of Decorators Designed to Decorate Member Methods in an @ObservedV2 Decorated Class
**Error Message**<br>
The \'xxx\' can decorate only member \'yyy\' within a \'class\' decorated with \'@ObservedV2\'.

**Description**<br>
This error code is reported when decorators designed to decorate member methods in an @ObservedV2 decorated class are used to decorate member methods in classes decorated by @Observed.

**Possible Cause**<br>
Decorators designed to decorate member methods in an @ObservedV2 decorated class are used to decorate member methods in classes decorated by @Observed.

**Solution**<br>
Use the decorator in question, such as @Monitor, only in @ObservedV2 decorated classes. In @Observed classes, use the @Watch decorator instead.

## 10905344 Incorrect Use of @Track and a V2 Decorator
**Error Message**<br>
\'xxx\' cannot be used with classes decorated by \'@ObservedV2\'. Use the \'@Trace\' decorator instead.

**Description**<br>
This error code is reported when a decorator designed for V1 is used with an @ObservedV2 decorated class.

**Possible Cause**<br>
A decorator designed for V1, such as @Track, is used with an @ObservedV2 decorated class.

**Solution**<br>
Do not use decorators designed for V1 in @ObservedV2 decorated classes.

## 10905345 Incorrect Use of @Track Outside a Class
**Error Message**<br>
The \'xxx\' decorator can decorate only member variables of a class.

**Description**<br>
This error code is reported when a decorator designed for use within a class is applied outside of a class.

**Possible Cause**<br>
A decorator designed for use within a class, such as @Track, are applied outside of a class.

**Solution**<br>
Make sure the decorators designed for use within a class are applied only within a class.

## 10905346 Incorrect Use of a V2 Decorator
**Error Message**<br>
\'xxx\' can only decorate member property.

**Description**<br>
This error code is reported when decorators such as @Local, @Param, @Once, @Event, @Provider, @Consume, and @BuilderParam are used to decorate non-member properties in @ComponentV2.

**Possible Cause**<br>
The @Local, @Param, @Once, @Event, @Provider, @Consume, or @BuilderParam decorator is used to decorate a non-member property in @ComponentV2.

**Solution**<br>
Use @Local, @Param, @Once, @Event, @Provider, @Consume, and @BuilderParam only to decorate member properties in @ComponentV2.

## 10905115 Incorrect Use of Method Decorators
**Error Message**<br>
\'xxx\' can only decorate method.

**Description**<br>
This error code is reported when method decorators, such as @LocalBuilder and @Monitor, are used to decorate non-methods.

**Possible Cause**<br>
Method decorators, such as @LocalBuilder and @Monitor, are used to decorate property variables, global functions, or methods in classes.

**Solution**<br>
Use the method decorators only to decorate methods.

## 10905116 Incorrect Use of the @Computed Decorator
**Error Message**<br>
\'@Computed\' can only decorate 'GetAccessor'.

**Description**<br>
This error code is reported when @Computed is used to decorate a method that is not a getter.

**Possible Cause**<br>
The @Computed decorator is used to decorate a non-getter method.

**Solution**<br>
Use @Computed only to decorate getter methods.

## 10905117 Incorrect Mixed Use of Method Decorators
**Error Message**<br>
A function can only be decorated by one of the \'@AnimatedExtend\', \'@Builder\', \'@Extend\', \'@Styles\', \'@Concurrent\' and \'@Sendable\''.

**Description**<br>
This error code is reported when two different method decorators are defined on the same method.

**Possible Cause**<br>
Multiple method decorators are defined on the same method.

**Solution**<br>
Select a single appropriate method decorator to use.

## 10905119 Duplicate Decorators
**Error Message**<br>
Duplicate \'xxx\' decorators for method are not allowed.

**Description**<br>
This error code is reported when the same decorator is applied to the same method multiple times.

**Possible Cause**<br>
The same decorator is used repeatedly for a method.

**Solution**<br>
Avoid using the same decorator multiple times on the same method.

## 10905121 Incorrect Mixed Use of Built-in Decorators
**Error Message**<br>
The member property or method can not be decorated by multiple built-in decorators.

**Description**<br>
This error code is reported when multiple built-in decorators are used to decorate the same member property or method.

**Possible Cause**<br>
Multiple built-in decorators are used on the same member property or method.

**Solution**<br>
Select a single appropriate built-in decorator to use.

## 10905348 Invalid State Variable Type
**Error Message**<br>
The type of the \'xxx\' property can not be a class decorated with \'@ObservedV2\'.

**Description**<br>
This error code is reported when a class decorated by @ObservedV2 is used as the type of a state variable.

**Possible Cause**<br>
A class decorated by @ObservedV2 is used as the type of a state variable.

**Solution**<br>
Avoid using classes decorated by @ObservedV2 as the type for state variables.

## 10905122 Incorrect Use of the @Concurrent Decorator
**Error Message**<br> 
\'@Concurrent\' can not be used on \'xxx\' function declaration.

**Description**<br>
This error code is reported when @Concurrent is used to decorate a specific function.

**Possible Cause**<br>
The @Concurrent decorator is used to decorate a specific function.

**Solution**<br>
Do not use the @Concurrent decorator on specific functions.

## 10905123 Incorrect Use of @Concurrent on Methods
**Error Message**<br>
\'@Concurrent\' can not be used on method, please use it on function declaration.

**Description**<br>
This error code is reported when @Concurrent is used to decorate methods.

**Possible Cause**<br>
The @Concurrent decorator is used to decorate methods.

**Solution**<br>
Use the @Concurrent decorator only on function declarations, not on methods.

## 10905227 The Name of a Custom Component Cannot Be the Same as That of a Built-in Component
**Error Message**<br>
The struct \'xxx\' cannot have the same name as the built-in component \'xxx\'.

**Description**<br>
This error code is reported when the name of a custom component matches the name of a built-in component.

**Possible Cause**<br>
The custom component has the same name as a built-in component.

**Solution**<br>
Rename the custom component to a name that is different from any built-in component names.

## 10905228 The Name of a Custom Component Cannot Be the Same as That of a Built-in Component Attribute Method
**Error Message**<br>
The struct \'xxx\' cannot have the same name as the built-in attribute \'xxx\'.

**Description**<br>
This error code is reported when the name of a custom component matches the name of a built-in component attribute method.

**Possible Cause**<br>
The custom component has the same name as an attribute method of a built-in component.

**Solution**<br>
Rename the custom component to a name that is different from any built-in component attribute method names.

## 10905229 Invalid Struct Decorator
**Error Message**<br>
The struct \'xxx\' can not be decorated with \'@ComponentV2\' and \'@Component\', \'@Reusable\', \'@CustomDialog\' at the same time.

**Description**<br>
This error code is reported when a struct is decorated by multiple incompatible decorators such as @ComponentV2, @Component, @Reusable, and @CustomDialog.

**Possible Cause**<br>
Multiple decorators that are not compatible with each other are used on the same struct.

**Solution**<br>
Avoid using incompatible decorators on the same struct. Use only one appropriate decorator for the struct.

## 10905230 Lack of Required Decorators for Child Components
**Error Message**<br>
Decorator \'@Component\', \'@ComponentV2\', or \'@CustomDialog\' is missing for struct \'xxx\'.

**Description**<br>
TThis error code is reported when a child component is not decorated by @Component, @ComponentV2, or @CustomDialog.

**Possible Cause**<br>
The child component is not decorated with the required decorators.

**Solution**<br>
Make sure the child component is decorated by @Component, @ComponentV2, or @CustomDialog.

## 10905402 Invalid Use of the @Entry Decorator
**Error Message**<br>
A page configured in \'main_pages.json\' or \'build-profile.json5\' must have one and only one \'@Entry\' decorator.

**Description**<br>
This error code is reported when the @Entry decorator is missing or incorrectly used on the home page.

**Possible Cause**<br>
The home page is not decorated with the @Entry decorator.

**Solution**<br>
Make sure the home page has exactly one @Entry decorator.

## 10905231 Invalid Number of the @Entry Decorators
**Error Message**<br>
A page can't contain more than one \'@Entry\' decorator.

**Description**<br>
This error code is reported when multiple @Entry decorators are used on a single page.

**Possible Cause**<br>
Multiple @Entry decorators are used on a single page.

**Solution**<br>
Remove unnecessary @Entry decorators, making sure only one @Entry decorator is used on a page.

## 10905404 Invalid Number of the @Preview Decorators
**Error Message**<br>
A page can contain at most 10 \'@Preview\' decorators.

**Description**<br>
This error code is reported when more than 10 @Preview decorators are used on a single page.

**Possible Cause**<br>
More than 10 @Preview decorators are used on the same page.

**Solution**<br>
Remove unnecessary @Preview decorators, making sure a maximum of 10 @Preview decorators are used on a page.

## 10905232 Invalid Struct Name
**Error Message**<br>
A struct must have a name.

**Description**<br>
This error code is reported when a struct is not named.

**Possible Cause**<br>
No name is provided for the struct.

**Solution**<br>
Define a name for the struct.

## 10905233 Lack of Required Decorators for Child Components
**Error Message**<br>
Decorator \'@Component\', \'@ComponentV2\', or \'@CustomDialog\' is missing for struct \'xxx\'.

**Description**<br>
This error code is reported when a child component is not decorated with @Component, @ComponentV2, or @CustomDialog and is called by the parent component.

**Possible Cause**<br>
The child component is not decorated with the required decorators.

**Solution**<br>
Make sure the child component is decorated by @Component, @ComponentV2, or @CustomDialog before calling it.

## 10905125 Incorrect Use of Multiple Decorators on the Same Member Property or Method
**Error Message**<br>
The member property or method can not be decorated by multiple decorators.

**Description**<br>
This error code is reported when multiple decorators are used on the same member property or method.

**Possible Cause**<br>
Multiple decorators are used on the same member property or method.

**Solution**<br>
Remove redundant decorators and retain only one appropriate decorator.

## 10905235 Invalid Component Name
**Error Message**<br>
The module name \'xxx\' can not be the same as the inner component name.

**Description**<br>
This error code is reported when the name of a custom component matches the name of a built-in component.

**Possible Cause**<br>
The custom component has the same name as a built-in component.

**Solution**<br>
Change the name of the custom component to a name that is different from any built-in component names.

## 10905236 Incorrect Component Use
**Error Message**<br>
UI component \'xxx\' cannot be used in this place.

**Description**<br>
This error code is reported when the ArkUI built-in component is used outside the allowed context, such as outside the @Builder or build() method.

**Possible Cause**<br>
The built-in component is used outside the @Builder or build() method, which does not meet the usage restrictions.

**Solution**<br>
Use the built-in component within the @Builder method, build() method, or page transition method.

## 10905237 Invalid Component Name
**Error Message**<br>
The struct name cannot contain reserved tag name: \'xxx\'.

**Description**<br>
This error code is reported when the name of a custom component matches the name of an existing component.

**Possible Cause**<br>
The custom component has the same name as an existing component.

**Solution**<br>
Change the name of the custom component to a valid component name that is different from the existing component name.

## 10905127 Invalid @Styles Declaration
**Error Message**<br>
Should not add return type to the function that is decorated by Styles.

**Description**<br>
This error code is reported when functions decorated by @Styles return function types.

**Possible Cause**<br>
The return value of the function decorated by @Styles is of the function type.

**Solution**<br>
Do not declare the return value of a function decorated by @Styles as a function type.

## 10905238 Invalid Struct Declaration
**Error Message**<br>
A struct declaration without the \'default\' modifier must have a name.

**Description**<br>
This error code is reported when a struct declaration without the default modifier is not named.

**Possible Cause**<br>
The struct is declared without the default modifier and is not named.

**Solution**<br>
Name the struct correctly.

## 10905128 Invalid @Extend Declaration
**Error Message**<br>
Should not add return type to the function that is decorated by Extend.

**Description**<br>
This error code is reported when functions decorated by @Extend return function types.

**Possible Cause**<br>
The return value of the function decorated by @Extend is of the function type.

**Solution**<br>
Do not declare the return value of a function decorated by @Extend as a function type.

## 10905129 Incorrect Mixed Use of @Computed and !!
**Error Message**<br>
A property decorated by \'xxx\' cannot be used with two-bind syntax.

**Description**<br>
This error code is reported when the @Computed decorator is incorrectly used with two-way binding syntax.

**Possible Cause**<br>
The @Computed decorator and two-way binding syntax are used together.

**Solution**<br>
Do not use the @Computed decorator and two-way binding syntax together.

## 10905130 Incorrect Use of @Computed on a Setter Method
**Error Message**<br>
A property decorated by \'xxx\' cannot define a set method.

**Description**<br>
This error code is reported when the @Computed decorator is used on a setter method.

**Possible Cause**<br>
The setter method is decorated using the @Computed decorator.

**Solution**<br>
Use the @Computed decorator only on a getter method.

## 10905358 !! Syntax Error
**Error Message**<br>
When the two-way binding syntax is used, do not assign a value to \'xxx\' variable \'yyy\' because the framework generates the default assignment.

**Description**<br>
This error code is reported when a value is assigned to the variable in an @Event decorated method while two-way binding syntax is used.

**Possible Cause**<br>
Two-way binding syntax is used and a value is passed to the @Event method.

**Solution**<br>
When using two-way binding syntax, do not pass values to the @Event method. The ArkUI framework will handle the default assignment.

## 10905241 Incorrect Mixed Use of @Reusable and @ReusableV2
**Error Message**<br>
The \'@Reusable\' and \'@ReusableV2\' decorators cannot be applied simultaneously.

**Description**<br>
This error code is reported when @Reusable and @ReusableV2 are used together.

**Possible Cause**<br>
Both @Reusable and @ReusableV2 are used to decorate a component.

**Solution**<br>
Do not use @Reusable and @ReusableV2 together. Choose one appropriate decorator.

## 10905242 Incorrect Use of @ReusableV2
**Error Message**<br>
\'@ReusableV2\' is only applicable to custom components decorated by \'@ComponentV2\'.

**Description**<br>
This error code is reported when @ReusableV2 is used to decorate custom components that are not decorated by @ComponentV2.

**Possible Cause**<br>
The @ReusableV2 decorator is used to decorate components that are not decorated by @ComponentV2.

**Solution**<br>
Use @ReusableV2 only with custom components decorated by @ComponentV2.

## 10905244 Incorrect Use of @ReusableV2
**Error Message**<br>
A custom component decorated with \'@Component\' cannot contain child components decorated with \'@ReusableV2\'.

**Description**<br>
This error code is reported when components decorated by @Component contain child components decorated by @ReusableV2.

**Possible Cause**<br>
A component decorated by @Component calls a child component decorated by @ReusableV2.

**Solution**<br>
Do not call components decorated by @ReusableV2 within components decorated by @Component.

## 10905245 Incorrect Use of @ReusableV2
**Error Message**<br>
A custom component decorated with \'@Reusable\' cannot contain any child components decorated with \'@ReusableV2\'.

**Description**<br>
This error code is reported when components decorated by @Reusable contain child components decorated by @ReusableV2.

**Possible Cause**<br>
A component decorated by @Reusable calls a child component decorated by @ReusableV2.

**Solution**<br>
Do not call components decorated by @ReusableV2 within components decorated by @Reusable.

## 10905246 Incorrect Use of @Reusable
**Error Message**<br>
A custom component decorated with \'@ReusableV2\' cannot contain child components decorated with \'@Reusable\'.

**Description**<br>
This error code is reported when components decorated by @ReusableV2 contain child components decorated by @Reusable.

**Possible Cause**<br>
A component decorated by @ReusableV2 calls a child component decorated by @Reusable.

**Solution**<br>
Do not call components decorated by @Reusable within components decorated by @ReusableV2.

## 10905359 Component Initialization Error
**Error Message**<br>
Property \'xxx\' must be initialized through the component constructor.

**Description**<br>
This error code is reported when the variable decorated by @Require is not initialized during parent component construction.

**Possible Cause**<br>
The variable decorated by @Require is not initialized during parent component construction.

**Solution**<br>
Initialize variables decorated by @Require when constructing the parent component.

## 10905247 Incorrect Use of @ReusableV2
**Error Message**<br>
The template attribute of the Repeat component cannot contain any custom component decorated with \'@ReusableV2\'.

**Description**<br>
This error code is reported when **Repeat.template** contains custom components decorated by @ReusableV2.

**Possible Cause**<br>
The **template** property of **Repeat** contains a custom component decorated by @ReusableV2.

**Solution**<br>
Remove the component decorated by @ReusableV2 from the template property.

## 10905248 Incorrect Use of the reuse Attribute
**Error Message**<br>
The reuse attribute is only applicable to custom components decorated with both \'@ComponentV2\' and \'@ReusableV2\'.

**Description**<br>
This error code is reported when the **reuse** attribute is incorrectly applied to components that are not properly decorated for reuse functionality.

**Possible Cause**<br>
The **reuse** attribute is not used with custom components that are decorated by both @ComponentV2 and @ReusableV2.

**Solution**<br>
Use the **reuse** attribute only for custom components decorated by both @ComponentV2 and @ReusableV2.

## 10905249 Incorrect Use of the reuseId Attribute
**Error Message**<br>
The reuseId attribute is not applicable to custom components decorated with both \'@ComponentV2\' and \'@ReusableV2\'.

**Description**<br>
This error code is reported when **reuseId** is used for custom components decorated by @ComponentV2 and @ReusableV2.

**Possible Cause**<br>
**reuseId** is used for custom components decorated by @ComponentV2 and @ReusableV2.

**Solution**<br>
Use the **reuseId** attribute in the correct scenario.
