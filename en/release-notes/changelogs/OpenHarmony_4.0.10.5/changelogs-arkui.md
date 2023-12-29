# ArkUI Subsystem Changelog

## cl.arkui.1 Method Name Changes in NavPathStack

**Key API/Component Changes**

[NavPathStack](../../../application-dev/reference/arkui-ts/ts-basic-components-navigation.md#navpathstack10)  
|  Before Change  | After Change |
|  ----  | ----  |
| push  | pushPath |
| pushName  | pushNameByPath |
| popTo| PopToName |

**Change Impact**

After the SDK is updated to 4.0.10.x, if any of the old method names is used in the code, a compilation error will be reported.  
Property 'push' does not exist on type 'NavPathStack'.   
Property 'pushName' does not exist on type 'NavPathStack'.   
Property 'pop' does not exist on type 'NavPathStack'.   

**Adaptation Guide**  

Update the code to use the new method names.

```ts
navPathStack = new NavPathStack();
this.navPathStack.push(...)
this.navPathStack.pushPath(...)

this.navPathStack.pushName('navidesnation_add',this.value)
this.navPathStack.pushPathByName('navidesnation_add',this.value) 

this.navPathStack.pop('navidesnation_add')
this.navPathStack.popToName('navidesnation_add')
```
