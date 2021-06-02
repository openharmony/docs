# JS UI Framework Overview<a name="EN-US_TOPIC_0000001064068634"></a>

-   [Basic Capabilities](#section1393616301083)
-   [Overall Structure](#section105231413161115)

The OpenHarmony JS UI framework provides basic, container, and canvas UI components and standard CSS animation capabilities. It supports the web-development-like programming paradigm.

## Basic Capabilities<a name="section1393616301083"></a>

-   **Web-development-like paradigm**

    The JS UI framework supports languages that are similar to those for web development, such as HTML and CSS. You can use them to describe the page layout and style, and use JavaScript \(conforming to the ECMAScript specification\) for page behavior. This paradigm allows you to avoid code for UI state switching. The view configuration information is intuitive.



## Overall Structure<a name="section105231413161115"></a>

The JS UI framework consists of the application, framework, engine, and porting layers.

![](figures/zh-cn_image_0000001077953992.png)

-   **Application**

    Contains applications with FA developed with the JS UI framework. The FA application in this document refers to the application with FAs developed using JavaScript. 

-   **Framework**

    Parses UI pages and provides the Model-View-ViewModel \(MVVM\), page routing, custom components and more for front end development.

-   **Engine**

    Accomplishes animation parsing, Document Object Model \(DOM\) building, layout computing, rendering command building and drawing, and event management.

-   **Porting Layer**

    Abstracts the platform layer to provide abstract interfaces to connect to the platform. For example, event interconnection, rendering pipeline interconnection, and lifecycle interconnection.


