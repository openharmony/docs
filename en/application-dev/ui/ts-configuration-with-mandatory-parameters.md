# Configuration with Mandatory Parameters


If the API definition of a component contains any mandatory parameter, set the parameters in the parentheses next to the component. Use constants to assign values to the parameters.


Examples:


- Set the mandatory parameter src of the &lt;Image&gt; component as follows:
  
  ```
  Image('http://xyz/a.jpg')
  ```


- Set the mandatory parameter content of the &lt;Text&gt; component as follows:
  
  ```
  Text('123')
  ```


You can also use variables or expressions to assign values to parameters. The result type returned by an expression must meet the parameter type requirements. For example, to pass a variable or expression to construct the Image and Text components:

```
// imagePath, where imageUrl is a private data variable defined in the component.
Image(this.imagePath)
Image('http://' + this.imageUrl)
// count is a private data variable defined in the component.
// (``) and (${}) are the template character string features supported by the TS language and comply with the
// features of the corresponding language. This specification is not limited.
Text(`count: ${this.count}`)
```
