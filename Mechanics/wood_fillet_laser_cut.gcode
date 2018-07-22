; Escriba Mark I - Light CNC, G-code program file
;
; Project: w1 Mark I - Watch Winder
; Description: This program is used to laser cut w1 Mark I wood fillets.
; 
; Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
; Contributors: none
; 
; Change log:
; 2018-05-26
;        * First version
;
; Header
$I  ; View build info
$G  ; View G-code parser state
$$  ; View current settings
?  ; View current status

G90  ; Set absolute distance mode
G21  ; Set all units in millimeters

M03 S255   ; Turn laser on

G01 X160 F500
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0
G01 X160
G01 X0

M03 S0  ; Turn laser off

; Footer
G28  ; Go to home position
M2  ; Program end
