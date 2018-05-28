; Escriba Mark I - Light CNC, G-code program file
;
; Project: w1 Mark I - Watch Winder
; Description: This program is used to laser cut w1 Mark I wood fillets.
; 
; Change log:
; 2018-05-26
;        * First version
;
; Header
$I  ; View build info
$G  ; View G-code parser state
$$  ; View Grbl settings
?  ; View current status

G90  ; Set absolute distance mode
G21  ; Set all units in millimeters

G00 Z5
G00 X50 Y100

G01 Z-0.125 F5000  ; Turn laser on

G01 X168
G01 X50
G01 X168
G01 X50
G01 X168
G01 X50

G00 Z5  ; Turn laser off

; Footer
G28  ; Go to home position
M2  ; Program end
