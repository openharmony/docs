# XML Overview


Extensible Markup Language (XML) is a markup language used to describe data. It aims to provide a common way to transmit and store data, especially data frequently used in web applications. XML does not predefine tags. As a result, it is more flexible and widely used.


An XML file consists of elements, attributes, and content.


- An element refers to a tag pair that contains text, attributes, or other elements.

- Attributes provide additional information about an element.

- Content is the data or sub-element contained in an element.


XML supports the use of XML Schema Definition (XSD) or Document Type Definition (DTD) for defining the document structure. This allows you to customize rules to verify whether an XML document is in the expected format.


XML also supports features such as namespaces, entity references, comments, and processing instructions, making it easy to adapt to diverse data requirements.


The common library provides XML-related basic capabilities, including [XML generation](xml-generation.md), [XML parsing](xml-parsing.md), and [XML conversion](xml-conversion.md).

The following is a simple XML example and the corresponding description. For more XML interfaces and their usage, see [@ohos.xml](../reference/apis-arkts/js-apis-xml.md).

```XML
<?xml version="1.0" encoding="utf-8"?> <!--Declaration-- >
<!--Processing command-->
<?xml-stylesheet type="text/css" href="style.css"?>
<!--Element, attribute, and attribute value-->
<note importance="high">
    <title>Happy</title>
    <!--Entity reference-->
    <todo>&amp;</todo>
    <!--Namespace declaration and URI -->
    <h:table xmlns:h="http://www.w3.org/TR/html4/">
        <h:tr>
            <h:td>Apples</h:td>
            <h:td>Bananas</h:td>
        </h:tr>
    </h:table>
</note>
```
