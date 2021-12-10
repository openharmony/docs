# Using a Separate Line for New Component<a name="EN-US_TOPIC_0000001110788994"></a>

**Semicolons \(;\) can be omitted at the end of each line of code.**

```
Column() {
    Image('icon.png')
    Text('text')
}
```

It is equivalent to:

```
Column() {
    Image('icon.png');
    Text('text');
}
```

**Only one component can be created in each line. The if, else, else if, or ForEach statement is in a separate line.**

Incorrect:

```
Column() {
    Image('icon.png') Text('text') // invalid, creation of two components in same line
}

if (this.condi) {Image('icon.png')} // invalid, if and creation a components in same line
```

**Built-in container components, if, and ForEach item generator functions must use closed parentheses \(\{\}\) in the case of a single subitem.**

Incorrect:

```
if (this.condi)
Image('icon.png'), // invalid, missing {}
else
    Text('text');
```

```
ForEach(this.arr,
    (item) => Image('icon.png'), // invalid, missing {}
    (item) => item.id.toString()
}
```

