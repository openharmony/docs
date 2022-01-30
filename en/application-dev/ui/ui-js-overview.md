# Overview<a name="EN-US_TOPIC_0000001064068634"></a>

 ArkUI with the JavaScript-based web-like development paradigm provides UI components \(basic, container, canvas, and more\) and standard CSS animation capabilities.

## Basic Capabilities<a name="section1393616301083"></a>

-   **Web-like development paradigm**

     ArkUI supports languages that are similar to those for web development, such as HTML and CSS. You can use them to describe the page layout and style, and use JavaScript \(conforming to the ECMAScript specification\) for page behavior. With  ArkUI, you can configure the UI in an intuitive manner, eliminating the need to code for UI state switching.



## Overall Structure<a name="section105231413161115"></a>

 ArkUI with the JavaScript-based web-like development paradigm consists of the following layers: application layer, frontend framework layer, engine layer, and porting layer.

![](figures/zh-cn_image_0000001077953992.png)

-   **Application**

    Contains applications with FAs you developed. The FA application in this document refers to the application with FAs developed using JavaScript. 

-   **Framework**

    Parses UI pages and provides the Model-View-ViewModel \(MVVM\), page routing, custom components and more for front end development.

-   **Engine**

    Accomplishes animation parsing, Document Object Model \(DOM\) building, layout computing, rendering command building and drawing, and event management.

-   **Porting Layer**

    Abstracts the platform layer to provide abstract interfaces to connect to the platform. For example, event interconnection, rendering pipeline interconnection, and lifecycle interconnection.


