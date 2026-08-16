# Glossary

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8e856b06a34a819612cae112a81452d688b21bcf translatedAt=2026-08-15T01:52:26.489Z pushedAt=2026-08-15T08:36:45.072Z -->

## B

### Basic Access Mode

A restricted security mode for input method applications. In this mode, only basic typing functions are provided.

## C

### CustomInput

A custom text input control developed by developers. It integrates [InputMethodController](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodcontroller) to bind to an input method.

## D

### DARK_IMMERSIVE

An immersive mode that applies a dark immersive effect to the input method panel.

## E

### EditorAttribute

Attributes that describe the characteristics of an editor box, including **inputPattern**, **enterKeyType**, and **immersiveMode**.

### ExtensionContext

The context of an Extension ability, which provides capabilities for starting, stopping, connecting to, and disconnecting from an Ability.

## F

### FLAG_FIXED

A state in which the input method panel is fixed at the bottom of the screen.

### FLAG_FLOATING

A state in which the input method panel can float and move.

### FLAG_CANDIDATE

A state in which the input method panel displays candidate words for user input.

### Full Access Mode

A full experience mode for input method apps, providing complete input method functions.

## I

### IME Kit

IME Kit establishes a communication channel between the application that contains the editor box and the input method application to support text input collaboration. It also provides input method application management capabilities for system applications.

### ImmersiveEffect

The visual effect of the input method panel, including gradient mode and streamer mode.

### ImmersiveMode

The immersive display mode of the input method panel, including light immersive mode and dark immersive mode. This mode is set by the input method application.

### InputMethodExtensionAbility

An input method Extension ability component that allows you to develop input method applications.

### InputMethodSubtype

A specific input mode or language of an input method, such as a Chinese keyboard or English keyboard.

### input_method_config.json

A JSON file that configures input method subtype information. It contains the subtypes array, which defines properties such as `icon`, `id`, `label`, and `locale` for each subtype.

### IME Command Tool

A command-line tool for managing input methods, including querying input methods, enabling or disabling input methods, switching input method access modes, and switching the current input method.

## K

### KeyboardAppearance

The expected keyboard display mode for an editor box, including immersive and non-immersive modes.

### KeyboardController

A controller class in an input method that controls soft keyboard display, event listening, and text operations.

## L

### LIGHT_IMMERSIVE

An immersive mode that applies a light immersive effect to the input method panel.

## P

### Panel

A window component created by an input method app to display the soft keyboard or status bar.

### PanelFlag

An enum for input method panel states, including fixed (`FLAG_FIXED`), floating (`FLAG_FLOATING`), and candidate (`FLAG_CANDIDATE`) states.

### PanelInfo

Configuration information for creating an input method panel, including `type` (panel type) and `flag` (panel state).

### PanelType

An enum for input method panel types, including soft keyboard (`SOFT_KEYBOARD`) and status bar (`STATUS_BAR`).

### PreviewText

A preview function that displays input text before the user confirms the input.

## S

### SOFT_KEYBOARD

A virtual keyboard consisting of keys. It is a panel type used for text input.

### SystemPanel

A system input method panel in which the input method soft keyboard window is displayed. The soft keyboard window has an offset area relative to the system panel.