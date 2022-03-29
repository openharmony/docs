# Configuration Without Parameters


If the API definition of a component does not contain mandatory parameters, you do not need to configure any content in the parentheses next to the component. For example, the Divider component does not contain parameters:

```
Column() {
    Text('item 1')
    Divider() // No parameter configuration of the divider component
    Text('item 2')
}
```
