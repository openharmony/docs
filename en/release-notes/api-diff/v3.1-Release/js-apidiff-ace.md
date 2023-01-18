# JS API Changes of the ArkUI Development Framework

The table below lists the APIs changes of the ArkUI development framework in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Component Type  | Component Name                     | Change Type| Change Description                                                    |
| ---------- | ----------------------------- | -------- | ------------------------------------------------------------ |
| Universal event  | onFocus/onBlur      | Added    | Added the focus events.                                              |
| Universal event  | onHover/onMouse     | Added    | Added the mouse events.                                              |
| Universal event  | onAreaChange| Added    | Added the event indicating component area (including the size and position) changes.                    |
| Universal attribute  | stateStyles      | Added    | Added the attribute for polymorphic style settings.                                      |
| Universal attribute  | responseRegion  | Added    | Added the attribute for touch hotspot settings.                                      |
| Universal attribute  | touchable           | Added    | Added the attribute that specifies whether a component is touchable.                                |
| Universal attribute  | focusable           | Added    | Added the attribute that specifies whether a component can gain focus.                              |
| Universal attribute  | bindPopup          | Added    | Added the layout customization capability for pop-up windows.                                   |
| Universal attribute  | bindMenu            | Added    | Added the layout customization capability for menus.                                    |
| Universal attribute  | hoverEffect        | Added    | Added the attribute that specifies the hover effect of a component.                        |
| General gesture  | SwipeGesture                  | Added    | Added the swipe gesture.                                              |
| Basic component  | Image                         | Added    | Added the **syncLoad** attribute to specify whether data is loaded synchronously.                          |
| Basic component  | Swiper                        | Added    | Added the **cachedCount** attribute to set the number of preloaded child components.                   |
| Basic component  | Swiper                        | Added    | Added the **disableSwipe** attribute to disable component swipe.                  |
| Basic component  | Slider                        | Added    | Added the vertical slider.                                      |
| Basic component  | TabContent                    | Added    | Added the **tabbar** attribute to provide the layout customization capability.                              |
| Basic component  | Marquee                       | Added    | Added the **\<Marquee>** component.                                            |
| Basic component  | Gauge                         | Added    | Added the **\<Gauge>** component.                                      |
| Basic component  | PluginComponent               | Added    | Added the **\<PluginComponent>** component.                                              |
| Basic component  | TextArea                      | Added    | Added the **\<TextArea>** component.                                          |
| Basic component  | TextInput                     | Added    | Added the **\<TextInput>** component.                                            |
| Basic component  | Toggle                        | Added    | Added the **\<Toggle>** component.                                              |
| Container component  | List                          | Added    | Added the **\<List>** component.                                        |
| Container component  | ScrollBar                     | Added    | Added the **\<ScrollBar>** component.                                            |
| Container component  | Navigation                    | Added    | Added the **\<Navigation>** component.                                          |
| Container component  | Stepper                       | Added    | Added the **\<Stepper>** component.                                        |
| Container component  | StepperItem                   | Added    | Added the **\<StepperItem>** component.                                  |
| Canvas component  | Canvas                        | Added    | Added the **\<Canvas>** component.                                              |
| Canvas component  | Lottie                        | Added    | Added the support for the Lottie library.                                        |
| Global UI method| ActionSheet                   | Added    | Added the support for the list selection dialog box.                                          |
| Basic component  | Web                           | Added    | Added the **\<Web>** component.                                          |
| Basic component  | Checkbox                      | Added    | Added the **\<Checkbox>** component to enable or disable an option.                |
| Basic component  | CheckboxGroup                 | Added    | Added the **\<CheckboxGroup>** component to select or deselect all check boxes in a group.      |
| Basic component  | DatePicker                    | Added    | Added the **\<DatePicker>** component to allow users to select a date from the given range.                              |
| Basic component  | TextPicker                    | Added    | Added the **\<TextPicker>** component.                                  |
| Basic component  | PatternLock                   | Added    | Added the **\<PatternLock>** component to allow users to use a pattern password for authentication.|
| Basic component  | RichText                      | Added    | Added the **\<RichText>** component to parse and display HTML text.                    |
| Basic component  | Search                        | Added    | Added the **\<Search>** component to provide an input area for users to search.            |
| Basic component  | Select                        | Added    | Added the **\<Select>** component to provide a drop-down list box that allows users to select among multiple options.        |
| Basic component  | TextClock                     | Added    | Added the **\<TextClock>** component.                                          |
| Container component  | Refresh                       | Added    | Added the **\<Refresh>** component.                                      |
| Container component  | SideBarContainer              | Added    | Added the **\<SideBarContainer>** component.                                        |
| Global UI method| TextPickerDialog              | Added    | Added the **\<TextPickerDialog>** component.                                    |
| Global UI method| TimePickerDialog              | Added    | Added the **\<TimePickerDialog>** component.                                    |
| Global UI method| DatePickerDialog              | Added    | Added the **\<DatePickerDialog>** component.                                    |
