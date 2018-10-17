; Escriba Mark I - Light CNC, G-code program file
;
; Project: w1 Mark I - Watch Winder
; Description: This program is used to laser cut w1 Mark I wood fillets.
; 
; Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
; Contributors: none
; 
; Change log:
; 2018-10-15
;        * First version
;
; Header
$I  ; View build info
$G  ; View G-code parser state
$$  ; View current settings
?  ; View current status

M8  ; Turn on fan
G90  ; Set absolute distance mode
G21  ; Set all units in millimeters

; The first section
G0 Y-7

M03 S2500   ; Turn laser on

; A1
G01 X201 F500
G01 X0
; A2
G01 X201
G01 X0
; A3
G01 X201
G01 X0
; A4
G01 X201
G01 X0
; A5
G01 X201
G01 X0
; A6
G01 X201
G01 X0
; A7
G01 X201
G01 X0
; A8
G01 X201
G01 X0
; A9
G01 X201
G01 X0
; A10
G01 X201
G01 X0
; A11
G01 X201
G01 X0
; A12
G01 X201
G01 X0
; A13
G01 X201
G01 X0
; A14
G01 X201
G01 X0
; A15
G01 X201
G01 X0
; A16
G01 X201
G01 X0
; A17
G01 X201
G01 X0
; A18
G01 X201
G01 X0
; A19
G01 X201
G01 X0
; A20
G01 X201
G01 X0

M03 S0  ; Turn laser off

; Cuting into two parts
G0 X88

M03 S2500   ; Turn laser on

; B1
G01 Y0
G01 Y-7
; B2
G01 Y0
G01 Y-7
; B3
G01 Y0
G01 Y-7
; B4
G01 Y0
G01 Y-7
; B5
G01 Y0
G01 Y-7
; B6
G01 Y0
G01 Y-7
; B7
G01 Y0
G01 Y-7
; B8
G01 Y0
G01 Y-7
; B9
G01 Y0
G01 Y-7
; B10
G01 Y0
G01 Y-7
; B11
G01 Y0
G01 Y-7
; B12
G01 Y0
G01 Y-7
; B13
G01 Y0
G01 Y-7
; B14
G01 Y0
G01 Y-7
; B15
G01 Y0
G01 Y-7
; B16
G01 Y0
G01 Y-7
; B17
G01 Y0
G01 Y-7
; B18
G01 Y0
G01 Y-7
; B19
G01 Y0
G01 Y-7
; B20
G01 Y0
G01 Y-7

M03 S0  ; Turn laser off

; Finishing
G0 X176

M03 S2500   ; Turn laser on

; C1
G01 Y0
G01 Y-7
; C2
G01 Y0
G01 Y-7
; C3
G01 Y0
G01 Y-7
; C4
G01 Y0
G01 Y-7
; C5
G01 Y0
G01 Y-7
; C6
G01 Y0
G01 Y-7
; C7
G01 Y0
G01 Y-7
; C8
G01 Y0
G01 Y-7
; C9
G01 Y0
G01 Y-7
; C10
G01 Y0
G01 Y-7
; C11
G01 Y0
G01 Y-7
; C12
G01 Y0
G01 Y-7
; C13
G01 Y0
G01 Y-7
; C14
G01 Y0
G01 Y-7
; C15
G01 Y0
G01 Y-7
; C16
G01 Y0
G01 Y-7
; C17
G01 Y0
G01 Y-7
; C18
G01 Y0
G01 Y-7
; C19
G01 Y0
G01 Y-7
; C20
G01 Y0
G01 Y-7

M03 S0  ; Turn laser off

; Footer
G28  ; Go to home position
M2  ; Program end
M9  ; Turn off fan
