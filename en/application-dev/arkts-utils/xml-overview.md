# XML Overview
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


Extensible Markup Language (XML) is a markup language used to describe data, providing a universal method for data transmission and storage. Unlike predefined languages, XML offers greater flexibility, making it suitable for a wide range of applications.


An XML document is composed of the following components:


- Elements: tag pairs that can enclose text, attributes, or other elements.

- Attributes: additional details about the elements.

- Content: data or nested elements within an element.


XML supports the use of XML Schema Definition (XSD) or Document Type Definition (DTD) to define the structure of documents. This allows you to create custom validation rules to ensure that XML documents adhere to their intended format.


Additional features of XML include namespaces, entity references, comments, and processing instructions, which enhance its flexibility and applicability across different data scenarios.


The ArkTS common library provides essential XML functionalities such as [XML generation](xml-generation.md), [XML parsing](xml-parsing.md), and [XML conversion](xml-conversion.md).

The following is a simple XML example with explanations. For details about more XML interfaces and their usage, see [@ohos.xml](../reference/apis-arkts/js-apis-xml.md).

```XML
<!--Declaration-->
<?xml version="1.0" encoding="utf-8"?>
<!--Processing instruction-->
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
