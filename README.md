# tek2_nanotekspice

This was a C++ project in my 4th semester.
It was my first university project using C++ after our Pool (2-week crash course).  
You can test it with the test files in the directory. Be careful you have to specify the state of each input on the commandline.  
Example: ./nanotekspice tests/4001.nts a=0 a2=1 a3=1 a4=0 b=0 b2=1 b3=0 b4=0

Commands:  
exit: closes the program.  
display: prints the current tick and the value of all inputs and outputs the standard output, each sortedby name in ASCII order. 
input=value: changes the value of an input. Possible value are 0,1 and U. This also apply to clocks.  
simulate: simulate a tick of the circuit.  
loop: continuously runs the simulation (simulate,display,simulate, . . . ) without displaying a prompt,until SIGINT is received.  
dump: print values of all components.  


The objective was to simulate logic gates and chipsets.  
I did it together with Alexander Prosch.