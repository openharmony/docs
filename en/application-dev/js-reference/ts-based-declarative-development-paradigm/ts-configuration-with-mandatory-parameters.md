# Configuration with Mandatory Parameters<a name="EN-US_TOPIC_0000001110948900"></a>

If the API definition of a component contains mandatory construction parameters, the parameters must be configured in the brackets  **\(\)**  next to the component. You can use constants to assign values to parameters.

Examples:

Set the mandatory parameter  **src**  of the  **<Image\>**  component as follows:

```
Image('http://xyz/a.jpg')
```

Set the mandatory parameter  **content**  of the  **<Text\>**  component as follows:

```
Text('123')
```

You can also use variables or expressions to assign values to parameters. The result type returned by an expression must meet the parameter type requirements.

To pass a variable or expression to construct the  **Image**  and  **Text**  components:

```
// imagePath, where imageUrl is a private data variable defined in the component.
Image(this.imagePath)
Image('http://' + this.imageUrl)
// count is a private data variable defined in the component.
// (``) and (${}) are the template character string features supported by the TS language and comply with the
// features of the corresponding language. This specification is not limited.
Text(`count: ${this.count}`)
```

