; Escriba Mark I - Light CNC, G-code program file
;
; Project: w1 Mark I - Watch Winder
; Description: This program is used to laser cut w1 Mark I main case.
; 
; Change log:
; 2018-04-30
;        * First version
;
; Header
$I  ; View build info
$G  ; View G-code parser state
$$  ; View Grbl settings
?  ; View current status

G90  ; Set absolute distance mode
G21  ; Set all units in millimeters

G00 Z5.000000
G00 X46.247110 Y41.910000

G01 Z-0.125000 F100.0(Penetrate)
G02 X44.982461 Y35.552183 Z-0.125000 I-16.613775 J-0.000001 F400.000000
G02 X41.381048 Y30.162286 Z-0.125000 I-15.349127 J6.357816
G02 X35.991151 Y26.560872 Z-0.125000 I-11.747713 J11.747713
G02 X29.633334 Y25.296224 Z-0.125000 I-6.357816 J15.349127
G02 X23.275517 Y26.560873 Z-0.125000 I0.000000 J16.613775
G02 X17.885620 Y30.162287 Z-0.125000 I6.357817 J15.349126
G02 X14.284207 Y35.552183 Z-0.125000 I11.747713 J11.747712
G02 X13.019559 Y41.910000 Z-0.125000 I15.349127 J6.357816
G02 X14.284207 Y48.267817 Z-0.125000 I16.613775 J-0.000000
G02 X17.885621 Y53.657713 Z-0.125000 I15.349127 J-6.357816
G02 X23.275517 Y57.259127 Z-0.125000 I11.747713 J-11.747713
G02 X29.633334 Y58.523775 Z-0.125000 I6.357816 J-15.349127
G02 X35.991150 Y57.259127 Z-0.125000 I0.000001 J-16.613775
G02 X41.381047 Y53.657714 Z-0.125000 I-6.357816 J-15.349127
G02 X44.982461 Y48.267817 Z-0.125000 I-11.747712 J-11.747713
G02 X46.247110 Y41.910000 Z-0.125000 I-15.349126 J-6.357817
G01 X46.247110 Y41.910000 Z-0.125000
G00 Z5.000000

G00 Z5.000000
G00 X17.639678 Y29.213065

G01 Z-0.125000 F100.0(Penetrate)
G02 X17.433627 Y28.715619 Z-0.125000 I-0.703498 J0.000002 F400.000000
G02 X16.936180 Y28.509570 Z-0.125000 I-0.497447 J0.497449
G02 X16.438733 Y28.715619 Z-0.125000 I0.000000 J0.703498
G02 X16.232682 Y29.213065 Z-0.125000 I0.497447 J0.497449
G02 X16.286233 Y29.482282 Z-0.125000 I0.703498 J0.000001
G02 X16.438732 Y29.710513 Z-0.125000 I0.649947 J-0.269217
G02 X16.666963 Y29.863013 Z-0.125000 I0.497448 J-0.497448
G02 X16.936180 Y29.916563 Z-0.125000 I0.269217 J-0.649947
G02 X17.205397 Y29.863013 Z-0.125000 I-0.000000 J-0.703498
G02 X17.433628 Y29.710513 Z-0.125000 I-0.269217 J-0.649947
G02 X17.586127 Y29.482282 Z-0.125000 I-0.497448 J-0.497448
G02 X17.639678 Y29.213065 Z-0.125000 I-0.649947 J-0.269217
G01 X17.639678 Y29.213065 Z-0.125000
G00 Z5.000000

G00 Z5.000000
G00 X43.033829 Y29.212983

G01 Z-0.125000 F100.0(Penetrate)
G02 X42.827778 Y28.715537 Z-0.125000 I-0.703498 J0.000002 F400.000000
G02 X42.330331 Y28.509488 Z-0.125000 I-0.497447 J0.497449
G02 X41.832885 Y28.715538 Z-0.125000 I0.000002 J0.703498
G02 X41.626835 Y29.212983 Z-0.125000 I0.497448 J0.497448
G02 X41.832884 Y29.710431 Z-0.125000 I0.703498 J0.000001
G02 X42.330331 Y29.916481 Z-0.125000 I0.497449 J-0.497447
G02 X42.599548 Y29.862931 Z-0.125000 I0.000001 J-0.703498
G02 X42.827779 Y29.710432 Z-0.125000 I-0.269217 J-0.649947
G02 X42.980278 Y29.482200 Z-0.125000 I-0.497448 J-0.497448
G02 X43.033829 Y29.212983 Z-0.125000 I-0.649947 J-0.269217
G01 X43.033829 Y29.212983 Z-0.125000
G00 Z5.000000

G00 Z5.000000
G00 X17.639600 Y54.607108

G01 Z-0.125000 F100.0(Penetrate)
G02 X17.433550 Y54.109661 Z-0.125000 I-0.703498 J0.000002 F400.000000
G02 X16.936102 Y53.903612 Z-0.125000 I-0.497447 J0.497449
G02 X16.438655 Y54.109661 Z-0.125000 I0.000000 J0.703498
G02 X16.232605 Y54.607108 Z-0.125000 I0.497447 J0.497449
G02 X16.286155 Y54.876325 Z-0.125000 I0.703498 J0.000001
G02 X16.438654 Y55.104556 Z-0.125000 I0.649947 J-0.269217
G02 X16.666885 Y55.257055 Z-0.125000 I0.497448 J-0.497448
G02 X16.936102 Y55.310606 Z-0.125000 I0.269217 J-0.649947
G02 X17.205319 Y55.257055 Z-0.125000 I0.000000 J-0.703498
G02 X17.433551 Y55.104556 Z-0.125000 I-0.269217 J-0.649947
G02 X17.586050 Y54.876325 Z-0.125000 I-0.497448 J-0.497448
G02 X17.639600 Y54.607108 Z-0.125000 I-0.649947 J-0.269217
G01 X17.639600 Y54.607108 Z-0.125000
G00 Z5.000000

G00 Z5.000000
G00 X43.033756 Y54.607105

G01 Z-0.125000 F100.0(Penetrate)
G02 X42.827707 Y54.109657 Z-0.125000 I-0.703498 J-0.000001 F400.000000
G02 X42.330260 Y53.903607 Z-0.125000 I-0.497449 J0.497447
G02 X42.061043 Y53.957157 Z-0.125000 I-0.000001 J0.703498
G02 X41.832812 Y54.109656 Z-0.125000 I0.269217 J0.649947
G02 X41.680312 Y54.337888 Z-0.125000 I0.497448 J0.497448
G02 X41.626762 Y54.607105 Z-0.125000 I0.649947 J0.269217
G02 X41.680312 Y54.876322 Z-0.125000 I0.703498 J0.000001
G02 X41.832812 Y55.104553 Z-0.125000 I0.649947 J-0.269217
G02 X42.061043 Y55.257052 Z-0.125000 I0.497448 J-0.497448
G02 X42.330260 Y55.310603 Z-0.125000 I0.269217 J-0.649947
G02 X42.827707 Y55.104552 Z-0.125000 I-0.000002 J-0.703498
G02 X43.033756 Y54.607105 Z-0.125000 I-0.497449 J-0.497447
G01 X43.033756 Y54.607105 Z-0.125000
G00 Z5.000000

; Footer
G28  ; Go to home position
M2  ; Program end
