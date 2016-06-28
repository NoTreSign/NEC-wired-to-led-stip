# NEC-wired-to-led-stip
Programmed an arduino to be the replacement of an IR remote, with added functions for serial as bluetooth control

After connect send the following commands in the following structure</td><td>
'#'+'command'+'$'  --> example : #1$ or #0$ 

##Commands
<table>
<tr>
</tr>
command </td><td> Action    </td><td>   explenation /n

<tr>
<td>'0'     </td><td> 'off'     </td><td>   turns the leds off /n,</td>
</tr><tr>
<td>'1'     </td><td> 'on'      </td><td>   turns the leds on,</td></tr><tr>
<td>'q' 	  </td><td>	'x1y3'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'w' 	  </td><td>	'x2y3'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4 ,</td></tr><tr>
<td>'e' 	  </td><td>	'x0y3'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'r' 	  </td><td>	'x1y2'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'t' 	  </td><td>	'x2y2'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'y' 	  </td><td>	'x0y2'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'u' 	  </td><td>	'x1y1'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'i' 	  </td><td>	'x2y1'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'o' 	  </td><td>	'x0y1'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'p' 	  </td><td>	'x1y0'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'a' 	  </td><td>	'x2y0'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'s' 	  </td><td>	'x0y0'    </td><td>   //see added picture remote colors from left top to right X0 -X2 , up to down yo - y4,</td></tr><tr>
<td>'A' 	  </td><td>	'Smooth'  </td><td>   turns on smooth mode,</td></tr><tr>
<td>'D' 	  </td><td>	'Fade'    </td><td>   turns on Fade mode,</td></tr><tr>
<td>'S' 	  </td><td>	'Strobe'  </td><td>   turns on Strobe mode,</td></tr><tr>
<td>'F' 	  </td><td>	'Flash'   </td><td>   turns on Flash mode,</td></tr><tr>
<td>'W' 	  </td><td>	'White'   </td><td>   turns on White mode,</td></tr><tr>
<td>'B' 	  </td><td>	'Blue'    </td><td>   turns on Blue mode,</td></tr><tr>
<td>'G' 	  </td><td>	'Green'   </td><td>   turns on Green mode,</td></tr><tr>
<td>'R' 	  </td><td>	'Red'     </td><td>   turns on Red mode,</td></tr><tr>
<td>'-' 	  </td><td>	'-dim'    </td><td>   dims the light,</td></tr><tr>
<td>'+' 	  </td><td>	'+dim'    </td><td>   increade brightnis,</td></tr><tr>
<td>'.' 	  </td><td>	'status'  </td><td>   shows status of booleans used for data receive protocol + shows how many commands of '#' have been received,</td>
</tr>
</table>

##EDIT: 
After trying to implement the same code for an 48key controller i found that that controller uses different datasignals. when researching into this i found the following site</td><td> http://woodsgood.ca/projects/2015/02/13/rgb-led-strip-controllers-ir-codes/. 

