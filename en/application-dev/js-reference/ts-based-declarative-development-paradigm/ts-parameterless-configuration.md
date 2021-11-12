# Parameterless Configuration<a name="EN-US_TOPIC_0000001157228859"></a>

If the API definition of a component does not contain mandatory parameters, you do not need to configure any content in the parentheses next to the component.

For example, the following  **Divider**  component does not contain parameters:

```
Column() {
    Text('item 1')
    Divider() // No parameter configuration of the divider component
    Text('item 2')
}
```

