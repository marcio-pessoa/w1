# w1 Mark I - Watch Winder

[Main page]

## Firmare

A fully original Firmware was developed to this project.
The firmware uses G-code

### G-code

<!---------------------------------------------------------------------------->

#### G28 - Gracefully stop

##### Usage

```
G28
```

 Argument    | Description                                                      
-------------|---------------------------------
 none        | no arguments supported                                           

##### Notes

Go to home position and gracefully stop.

##### Example

~~~ gcode
G28
~~~

<!---------------------------------------------------------------------------->

#### M0 - Unconditional stop

##### Usage

```
M0
```

 Argument    | Description
-------------|---------------------------------
 none        | no arguments supported

##### Notes

##### Example

~~~ gcode
M0
~~~

<!---------------------------------------------------------------------------->

#### M1 - Clockwise

##### Usage

```
M1 [S<rate>]
```

 Argument     | Description
--------------|---------------------------------
 `[S<rate>]`  | Speed rate [0,100]
 `[A<value>]` | Absolute speed (RPD - Revolutions Per Day) [X,XXX]

##### Notes
Speed limits:
- Minimum speed:  RPM
- Maximum speed:  RPM

##### Examples

Set direction to Clockwise:
~~~ gcode
M1
~~~

Set direction to Clockwise at 80% speed rate:
~~~ gcode
M1 S80
~~~

Set direction to Clockwise at 600 RPD:
~~~ gcode
M1 A600
~~~

<!---------------------------------------------------------------------------->

#### M2 - Counterclockwise

##### Usage

```
M2 [S<rate>]
```

 Argument     | Description
--------------|---------------------------------
 `[S<rate>]`  | Speed rate [0,100]
 `[A<value>]` | Absolute speed (RPD - Revolutions Per Day) [X,XXX]

##### Notes
Speed limits:
- Minimum speed:  RPM
- Maximum speed:  RPM

##### Examples

Set direction to Counterclockwise, using current speed:
~~~ gcode
M2
~~~

Set direction to Counterclockwise at 70% speed rate:
~~~ gcode
M2 S70
~~~

<!---------------------------------------------------------------------------->

#### M3 - Show motor direction and speed

##### Usage

```
M3
```

 Argument     | Description
--------------|---------------------------------
 none         | no arguments supported

##### Notes

##### Examples

Get direction and current speed:
~~~ gcode
M3
~~~

<!---------------------------------------------------------------------------->

#### M15 - System information

##### Usage

```
M15
```

 Argument     | Description
--------------|---------------------------------
 none         | no arguments supported

##### Notes

##### Examples

Get system information:
~~~ gcode
M15
~~~

<!---------------------------------------------------------------------------->

#### M89 - Memory information

##### Usage

```
M89
```

 Argument     | Description
--------------|---------------------------------
 none         | no arguments supported

##### Notes

##### Examples

Get memory information:
~~~ gcode
M89
~~~

<!---------------------------------------------------------------------------->

#### M92 - System version

##### Usage

```
M92
```

 Argument     | Description
--------------|---------------------------------
 none         | no arguments supported

##### Notes

##### Examples

Get system version:
~~~ gcode
M92
~~~

<!---------------------------------------------------------------------------->

#### M99 - Reset

##### Usage

```
M99
```

 Argument     | Description
--------------|---------------------------------
 none         | no arguments supported

##### Notes

##### Examples

Reset device:
~~~ gcode
M99
~~~

<!---------------------------------------------------------------------------->

#### M100 - Help message

##### Usage

```
M100
```

 Argument     | Description
--------------|---------------------------------
 none         | no arguments supported

##### Notes

##### Examples

Show help message:
~~~ gcode
M100
~~~

<!---------------------------------------------------------------------------->

#### M111 - Debug mode

##### Usage

```
M111
```

 Argument     | Description
--------------|---------------------------------
 none         | no arguments supported

##### Notes

##### Examples

Enable Debug mode:
~~~ gcode
M111
~~~

Disable Debug mode:
~~~ gcode
M111
~~~

[Main page]

---

[Main page]: ../README.md
