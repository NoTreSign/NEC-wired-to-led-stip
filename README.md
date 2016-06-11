# NEC-wired-to-led-stip
Programmed an arduino to be the replacement of an IR remote, with added functions for serial as bluetooth control

After connect send the following commands in the following structure:
'#'+'command'+'$'  --> example : #1$ or #0$ 

command | Action    :   explenation
'0'     | 'off'     :   turns the leds off
'1'     | 'on'      :   turns the leds on
'q' 	  |	'x1y3'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'w' 	  |	'x2y3'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4 
'e' 	  |	'x0y3'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'r' 	  |	'x1y2'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
't' 	  |	'x2y2'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'y' 	  |	'x0y2'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'u' 	  |	'x1y1'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'i' 	  |	'x2y1'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'o' 	  |	'x0y1'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'p' 	  |	'x1y0'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'a' 	  |	'x2y0'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
's' 	  |	'x0y0'    :   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4
'A' 	  |	'Smooth'  :   turns on smooth mode
'D' 	  |	'Fade'    :   turns on Fade mode
'S' 	  |	'Strobe'  :   turns on Strobe mode
'F' 	  |	'Flash'   :   turns on Flash mode
'W' 	  |	'White'   :   turns on White mode
'B' 	  |	'Blue'    :   turns on Blue mode
'G' 	  |	'Green'   :   turns on Green mode
'R' 	  |	'Red'     :   turns on Red mode
'-' 	  |	'-dim'    :   dims the light
'+' 	  |	'+dim'    :   increade brightnis
'.' 	  |	'status'  :   shows status of booleans used for data receive protocol + shows how many commands of '#' have been                             received
