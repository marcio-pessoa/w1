# w1 Mark I - Watch Winder

Márcio Pessoa

2017-09-20

**w1m1** is an acronim to Watch Winder with One slot - Mark I.

A watch winder is a device used to keep automatic watch running when not worn. Automatic watches operate on the principle of winding themselves using a moving weight inside the watch. The weight swings or rotates while the watch is worn and turns the winding mechanism inside the watch. So, fairly obviously, if the watch is not worn, then it no longer receives power this way and will run down. While virtually all automatic watches can be manually wound, this is not always convenient. So the concept of an automatic watch winder was born.

A winder cannot over wind an automatic watch, since all automatic watches have a special mainspring that will never come to the end of the spring. Most winders are on some sort of a timer, so they will operate for a few minutes, then “rest” for a bit, then start their motion again.  There is no need to keep the watch in motion 24 hours.


[Change log](CHANGELOG.md)

[Bill of materials](BOM.md)

[Kanban](KANBAN.md)


# Mechanics
![Mechanical design](Documents/w1.png)

## Case
![Figure [w1_case]: Case](Documents/Case.png width="50%" border="0")
[#Case] technical specifications:
- Material: Wood
- Feature: Noise reduction with fine spounge

## Base
![Figure [w1_base]: Base](Documents/Base.png width="50%" border="0")
[#Base] technical specifications:
- Material: Wood

### Feet
![Figure [w1_base]: Foot](Documents/Foot.png width="50%" border="0")
[#Feet] technical specifications:
- Material: Silicone
- Feature: Self adhesive
- Color: Transparent
- Diameter: 8 mm
- Height: 2.5 mm

## Engine

### Pulleys

![Figure [GT2_60T]: GT2 60T](Documents/GT2_60T.png width="50%" border="0")
Large pulley technical specification:
- Model: [#GT2-60T]
- Bore 5mm
- Standard: GT2
- Pinch: 2 mm
- Teeth: 60 T
- Material: Aluminium

![Figure [GT2_16T]: GT2 16T](Documents/GT2_16T.png width="50%" border="0")
Small pulley technical specification:
- Model: [#GT2-16T]
- Bore 6mm
- Standard: GT2
- Pinch: 2 mm
- Teeth: 16T
- Material: Aluminium

### Pulleys relationship
Calculating pulleys relantionship:

$$ s = \frac{B . 100}{A} \% $$

Where:
- A: Large pulley = 60T (Rotor Pulley)
- B: Small pulley = 16T (Motor Pulley)
- s: Speed Ratio = ?

$$ s = \frac{16 . 100}{60} \% $$

So:
$$ s = 26.7 \% $$

### Wheelbase
![Figure [Wheelbase]: Center distance](Documents/PULLEY_BELT.gif width="50%" border="0")
Use trigonometric functions to calculate distance between points A and B.

Using the Pi constant and pulley sizes, it is possible to calculate the belt size and the number of teeth.

Wheelbase data [^bbman] :
- Large pulley (A): 38.2 mm
- Small pulley (B): 10.2 mm
- Center distance: **64.5 mm**
- Teeth in mesh: **6 T**

![Figure [Right_triangle]: Right triangle](Documents/right_triangle_main.png width="80%" border="0")

### Belt
![Figure [gt2belt]: GT2 belt](Documents/gt2tooth.jpg width="40%" border="0")
[#Belt] Technical specifications:
- Standard: GT2
- Pinch: 2 mm
- Wide: 6 mm
- Internal lenght: 208 mm
- Teeth: 104 T

### Lazy Susan
![Figure [Lazy_Susan]: Lazy Susan](Documents/Lazy_Susan.png width="50%" border="0")
[#Lazy_Susan] Technical specifications:
- Material: aluminium
- Move: bearing 
- External diameter: 140 mm
- Internal diameter: 90 mm

# Electronics

## Arduino
[#Arduino] technical specifications:
[Arduino Leonardo][Arduino_Leonardo]

### Diagram
Figure [pins] shows Arduino diagram.
********************************************************************
*                                      .-----.                     *
*         .----[PWR]-------------------| USB |--.                  *
*         |                            '-----'  |                  *
*         |                                     |                  *
*         |                           A5/SCL[ ] |   C5             *
*         |                           A4/SDA[ ] |   C4             *
*         |                             AREF[ ] |                  *
*         |                              GND[ ] |                  *
*         | [ ]NC                     SCK/13[ ]~|   B5             *
*         | [ ]v.ref                 MISO/12[ ] |   .              *
*         | [ ]RST                   MOSI/11[ ]~|   .              *
*         | [ ]3V3   +-----+              10[ ]~|   .              *
*         | [ ]5v    |     |               9[ ]~|   .              *
*         | [ ]GND   | MCU |               8[ ] |   B0             *
*         | [ ]GND   |     |                    |                  *
*         | [ ]Vin   +-----+               7[ ] |   D7             *
*         |                                6[ ]~|   .              *
*         | [ ]A0                          5[ ]~|   .              *
*         | [ ]A1                          4[ ] |   .              *
*         | [ ]A2                     INT1/3[ ]~|   .              *
*         | [ ]A3                     INT0/2[ ] |   .              *
*         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   .              *
*         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   D0             *
*         |            [ ] [ ] [ ]              |                  *
*         '--.                         .--------'                  *
*             \_______________________/                            *
*                                                                  *
********************************************************************
[Figure [pins]: Arduino Leonardo[^busyducks]]

### Pin designation

 id | pin |   type    | direction |               description                
----|-----|-----------|-----------|--------------------------------------------
  0 |   0 | digital   | input     | Serial communication
  1 |   1 | digital   | output    | Serial communication
  2 |   0 | interrupt | input     | Speed sensor
  3 |   1 | interrupt | input     | Door sensor
  4 |   - | -         | -         | -
  5 |   5 | PWM       | output    | Motor (speed control)
  6 |   6 | PWM       | output    | Motor (speed control)
  7 |   - | -         | -         | -
  8 |   - | -         | -         | -
  9 |   9 | PWM       | output    | LED R (red)
 10 |  10 | PWM       | output    | LED G (green)
 11 |  11 | PWM       | output    | LED B (blue)
 12 |   - | -         | -         | -
 13 |  13 | PWM       | output    | Status LED
 14 |   0 | analog    | input     | User distance sensor
 15 |   - | -         | -         | -
 16 |   - | -         | -         | -
 17 |   - | -         | -         | -
 18 |   - | -         | -         | -
 19 |   5 | analog    | input     | Random number generator Seed
 
## Motor
![Figure [JK42HS34_techspecs]: Technical specifications](Documents/7535673A-56FE7EB81_526F672C_zps33a68bc7.jpg width="50%" border="0")

Gear motor technical specifications:
- Model: [#ZGB37RG]
- Shaft speed: 100 RPM
- Rotor Speed: 5000r/min
- Reversibility: yes
- Voltage: 12V DC
- Current: 800mA (no load)
- Torque: 4kg/cm
- Diameter: 37mm
- Shaft length: 15mm
- Shaft diameter: 6mm

### Driver
![Figure [L298]: L298 motor driver](Documents/pprjWeToHXRVuku3rawL.jpg width="50%" border="0")
> "The L298 is an integrated monolithic circuit in a 15-lead Multiwatt and Power SO20 packages. It is a high voltage, high current dual full-bridge driver designed to accept standard TTL logic levels and drive inductive loads such as relays, solenoids, DC and stepping motors. Two enable inputs are provided to enable or disable the device independently of the input signals. The emitters of the lower transistors of each bridge are connected together and the corresponding external terminal can be used for the connection of an external sensing resistor. Anadditional supply input is provided so that the logic works at a lower voltage."
>
> -- From: [L298](Documents/L298.pdf) data book

[#L298N] absolute maximum ratings:

Symbol   | Parameter                              | Value      | Unit
---------|----------------------------------------|------------|--------------
Vs       | Power Supply                           | 50         | V
Vss      | Logic Supply Voltage                   | 7          | V
Vi,Ven   | Input and Enable Voltage               | -0.3 to 7  | V
Io       | Peak Output Current (each Channel)</br>- Non Repetitive (t = 100µs)</br>- Repetitive (80% on –20% off; ton = 10ms)</br>- DC Operation</br> | </br>3</br>2.5</br>2 | </br>A</br>A</br>A
Vsens    | Sensing Voltage                        | -1 to 2.3  | V
Ptot     | Total Power Dissipation (Tcase = 75°C) | 25         | W
Top      | Junction Operating Temperature         | -25 to 130 | °C
Tstg, Tj | Storage and Junction Temperature       | -40 to 150 | °C

### Speed control
L298 can help to control motor speed with Arduino PWM outputs:
- Minimum speed:  RPM
- Maximum speed:  RPM

### Speed sensor
![Figure [TCST2103]: TCST2103 sensor](Documents/TCST2103.png width="50%" border="0")
> "The [#TCST2103] is a transmissive sensor that include an infrared emitter and phototransistor, located face-to-face on the optical axes in a leaded package which blocks visible light."
>
>                         -- From: [TCST2103](Documents/TCST2103.pdf) data book

## Charger system

### Qi

## Door sensor
[#44E_938] technical specifications:
- Type: Magnetic

# Software

## G-Code

<!---------------------------------------------------------------------------->
### G28 - Auto Home

(####) Usage

```
G28
```

 Argument    | Description                                                      
-------------|---------------------------------
 none        | no arguments supported                                           

(####) Notes

Esse comando não para imediatamente, a máquina vai até a posicao zero

(####) Example

~~~ gcode
G28
~~~

<!---------------------------------------------------------------------------->
### M0 - Unconditional stop
(####) Usage

```
M0
```

 Argument    | Description
-------------|---------------------------------
 none        | no arguments supported

(####) Notes

(####) Example

~~~ gcode
M0
~~~

<!---------------------------------------------------------------------------->
### M1 - Clockwise
(####) Usage

```
M1 [S<rate>]
```

 Argument    | Description
-------------|---------------------------------
 `[S<rate>]` | Speed rate

(####) Notes

(####) Examples

Set direction to Clockwise:
~~~ gcode
M1
~~~

Set direction to Clockwise at 80% speed rate
~~~ gcode
M1 S80
~~~

<!---------------------------------------------------------------------------->
### M2 - Counterclockwise
(####) Usage

```
M2 [S<rate>]
```

 Argument    | Description
-------------|---------------------------------
 `[S<rate>]` | Speed rate

(####) Notes

(####) Examples

Set direction to Counterclockwise:
~~~ gcode
M2
~~~

Set direction to Counterclockwise at 70% speed rate:
~~~ gcode
M2 S70
~~~

---

[^bbman]: Calculator by: https://www.bbman.com/belt-length-calculator/

[^busyducks]: Diagram by: <http://busyducks.com/ascii-art-arduinos>
 
[Arduino_Leonardo]: https://www.arduino.cc/en/Main/arduinoBoardLeonardo/#techspecs
