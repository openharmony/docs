# Component Overview


## Rows and Columns

- [Column](ts-container-column.md)

    A container that lays out child components vertically.
- [ColumnSplit](ts-container-columnsplit.md)

    A container that lays out child components vertically and inserts a horizontal divider between every two child components.
- [Row](ts-container-row.md)

    A container that lays out child components horizontally.
- [RowSplit](ts-container-rowsplit.md)

    A container that lays out child components horizontally and inserts a vertical divider between every two child components.
- [SideBarContainer](ts-container-sidebarcontainer.md)

    A container that contains a sidebar and content area as its child components. The sidebar is the first child component and can be shown or hidden as needed. The content area is the second child component.


## Stack, Flex, and Grid

- [Stack](ts-container-stack.md) 

    A container where child components are successively stacked and the latter one overwrites the previous one.
- [Flex](ts-container-flex.md)

    A container that allows for flexible layout of child components.
- [GridContainer](ts-container-gridcontainer.md)

    A container that lays out components vertically and is used only in the grid layout.
- [GridRow](ts-container-gridrow.md)

    A container that is used in a grid layout, together with its child component **\<GridCol>**.
- [GridCol](ts-container-gridcol.md)

    A container that must be used as a child component of the **\<GridRow>** container.
- [RelativeContainer](ts-container-relativecontainer.md)

    A container that is used for element alignment in complex scenarios.


## List and Grid

- [List](ts-container-list.md)

    A container that presents a series of list items arranged in a column with the same width. It supports presentations of the same type of data in a multiple and coherent row style, for example, images or text.
- [ListItem](ts-container-listitem.md)

    A component that displays a specific item in the list and that must be used together with **\<List>**.
- [ListItemGroup](ts-container-listitemgroup.md)

    A component that displays list item groups and that must be used together with **\<List>**.
- [Grid](ts-container-grid.md)

    A container that consists of cells formed by rows and columns. You can specify the cells where items are located to form various layouts.
- [GridItem](ts-container-griditem.md)

    A container that provides a single item in a grid.


## Scroll and Swipe

- [Scroll](ts-container-scroll.md) 

    A container that scrolls the content when the layout size of a component exceeds the size of its parent component.
- [Swiper](ts-container-swiper.md)

    A container that is able to display child components in looping mode.
- [WaterFlow](ts-container-waterflow.md)

    A container that consists of cells formed by rows and columns and arranges items of different sizes from top to bottom according to the preset rules.
- [FlowItem](ts-container-flowitem.md)

    A child component of the **\<WaterFlow>** container that is used to display specific items in the container layout.


## Navigation

- [Navigator](ts-container-navigator.md) 

    A container that provides redirection.   
- [Navigation](ts-basic-components-navigation.md)

    A container that typically functions as the root container of a page and displays the title bar, toolbar, and navigation bar based on the attribute settings.
- [NavRouter](ts-basic-components-navrouter.md)

    A container that provides default logic for click response processing, eliminating the need for manual logic definition.
- [NavDestination](ts-basic-components-navdestination.md)

    A child component of the **\<NavRouter>** component that represents a destination in the navigation area.
- [Stepper](ts-basic-components-stepper.md)

    A component that provides a step navigator.
- [StepperItem](ts-basic-components-stepperitem.md)

    A child component of the **\<Stepper>** component.
- [Tabs](ts-container-tabs.md)

    A container that allows users to switch between content views through tabs.
- [TabContent](ts-container-tabcontent.md)

    A component that corresponds to the content view on a tab page and is used only in the **\<Tabs>** component.


## Button and Selection

- [Button](ts-basic-components-button.md)

    A component that can be used to create different types of buttons.
- [Toggle](ts-basic-components-toggle.md)

    A component that provides a clickable element in the check box, button, or switch type.
- [Checkbox](ts-basic-components-checkbox.md)

    A component that is used to enable or disable an option.
- [CheckboxGroup](ts-basic-components-checkboxgroup.md)

    A component that is used to select or deselect all check boxes in a group.
- [DatePicker](ts-basic-components-datepicker.md)

    A component that allows users to select a date from the given range.
- [TextPicker](ts-basic-components-textpicker.md)

    A component that allows users to scroll to select text.
- [TimePicker](ts-basic-components-timepicker.md)

    A component that allows users to select a time from the given range through scrolling.
- [Radio](ts-basic-components-radio.md)

    A component that allows users to select from a set of mutually exclusive options.
- [Rating](ts-basic-components-rating.md)

    A component that provides a rating bar.
- [Select](ts-basic-components-select.md)

    A component that provides a drop-down list box to allow user to select among multiple options.
- [Slider](ts-basic-components-slider.md)

    A component that is used to quickly adjust settings, such as the volume and brightness.
- [Counter](ts-container-counter.md)

    A component that provides an operation to increase or decrease the number.


## Text and Input

- [Text](ts-basic-components-text.md)

    A component that is used to display a piece of textual information.
- [Span](ts-basic-components-span.md)

    A component that is used to display inline text in the **\<Text>** component.
- [Search](ts-basic-components-search.md)

    A component that provides an area for users to enter search queries.
- [TextArea](ts-basic-components-textarea.md)

    A component that provides multi-line text input and automatically wraps text so that each line does not have more than the width of the component.
- [TextInput](ts-basic-components-textinput.md)

    A component that provides single-line text input.
- [PatternLock](ts-basic-components-patternlock.md)

    A component that allows users to use a pattern password for authentication. It enters the input state once a finger is pressed against it, and exits the input state and completes the input once the finger leaves the screen.
- [RichText](ts-basic-components-richtext.md)

    A component that parses and displays HTML text.


## Image, Video, and Media

- [Image](ts-basic-components-image.md)

    A component that is used to render and display local and online images.
- [ImageAnimator](ts-basic-components-imageanimator.md)

    A component that enables images to be played frame by frame. The list of images to be played as well as the duration of each image can be configured.
- [Video](ts-media-components-video.md)

    A component that is used to play a video and control its playback.
- [PluginComponent](ts-basic-components-plugincomponent.md)

    A component that allows the UI provided by an external application to be displayed in the application.
- [XComponent](ts-basic-components-xcomponent.md)

    A component that can accept and display the EGL/OpenGL ES and media data input.


## Information Display

- [DataPanel](ts-basic-components-datapanel.md)

    A component that displays proportions in a chart.
- [Gauge](ts-basic-components-gauge.md)

    A component that is used to display data in a ring chart.
- [LoadingProgress](ts-basic-components-loadingprogress.md)

    A component that is used to create a loading animation.
- [Marquee](ts-basic-components-marquee.md)

    A component that is used to display a scrolling piece of text. The text is scrolled only when its width exceeds the width of the **\<Marquee>** component.
- [Progress](ts-basic-components-progress.md)

    A component that is used to provide a progress indicator that displays the progress of content loading or an operation.
- [QRCode](ts-basic-components-qrcode.md)

    A component that is used to display a QR code.
- [TextClock](ts-basic-components-textclock.md)

    A component that displays the current system time in text format for different time zones. The time is accurate to seconds.
- [TextTimer](ts-basic-components-texttimer.md)

    A component that displays timing information and is controlled in text format.


## Blank and Divider

- [Blank](ts-basic-components-blank.md)

    A component that is able to automatically fill the empty spaces in the container along the main axis. It is valid only when the parent component is **\<Row>** or **\<Column>**.
- [Divider](ts-basic-components-divider.md)

    A component that is used to separate content blocks and elements.


## Canvas and Graphics Drawing

- [Canvas](ts-components-canvas-canvas.md)

    A component that can be used to customize drawings.
- [Circle](ts-drawing-components-circle.md)

    A component that is used to draw a circle.
- [Ellipse](ts-drawing-components-ellipse.md)

    A component that is used to draw an ellipse.
- [Line](ts-drawing-components-line.md)

    A component that is used to draw a straight line.
- [Polyline](ts-drawing-components-polyline.md)

    A component that is used to draw a polyline.
- [Polygon](ts-drawing-components-polygon.md)

    A component that is used to draw a polygon.
- [Path](ts-drawing-components-path.md)

    A component that is used to define a closed shape.
- [Rect](ts-drawing-components-rect.md)

    A component that is used to draw a rectangle.
- [Shape](ts-drawing-components-shape.md)

    A parent component of the drawing components. The attributes provided by this component are universal attributes supported by all the drawing components.


## Web

- [Web](ts-basic-components-web.md)

    A component that can be used to display web pages.


##  Miscellaneous

- [ScrollBar](ts-basic-components-scrollbar.md)

    A component that is used together with scrollable components, such as **\<List>**, **\<Grid>**, and **\<Scroll>**.
- [Badge](ts-container-badge.md)

    A container that can be attached to another component for tagging.
- [AlphabetIndexer](ts-container-alphabet-indexer.md)

    A component that can create a logically indexed array of items in a container for instant location.
- [Panel](ts-container-panel.md)

    A container that presents lightweight content with flexible sizes.
- [Refresh](ts-container-refresh.md)

    A container that provides the pull-to-refresh feature.
- [AbilityComponent](ts-container-ability-component.md)

    A container that is used for independently displaying an ability.
- [RemoteWindow](ts-basic-components-remotewindow.md)

    A component that is used to control the application window, providing the component animator and application window linkage animator during application startup and exit.
