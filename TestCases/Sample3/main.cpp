#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"
int main() 
{
QuantumProgram q1(3);
/*Qiskit Code
from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit
from numpy import pi

qreg_q = QuantumRegister(3, 'q')
creg_c = ClassicalRegister(3, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)

circuit.z(qreg_q[0])
circuit.h(qreg_q[1])
circuit.z(qreg_q[2])
circuit.cx(qreg_q[1], qreg_q[0])
circuit.h(qreg_q[2])
circuit.ry(pi/6, qreg_q[0])
circuit.cx(qreg_q[1], qreg_q[2])
circuit.h(qreg_q[0])
circuit.x(qreg_q[1])
*/

q1.z_gate(0);
q1.hadamard_gate(1);
q1.z_gate(2);
q1.cnot_gate(1,0);
q1.hadamard_gate(2);
q1.ry_gate(0,3.14/6);
q1.cnot_gate(1,2);
q1.hadamard_gate(0);
q1.not_gate(1);




//Code to print the necessary outputs
/////////////
q1.read_unitary();
q1.create_state();
q1.read_state();
cout<<endl;
q1.observing_probabilitites();
cout<<endl;
q1.draw_circuit();
cout<<endl;
q1.execute(1024);
/////////////
} 



/*OUTPUT
0.250057 -0.43298 -0.250057 0.43298 0.250057 -0.43298 -0.250057 0.43298 
-0.43298 -0.250057 0.43298 0.250057 -0.43298 -0.250057 0.43298 0.250057 
0.43298 -0.250057 0.43298 -0.250057 -0.43298 0.250057 -0.43298 0.250057 
0.250057 0.43298 0.250057 0.43298 -0.250057 -0.43298 -0.250057 -0.43298 
0.250057 -0.43298 -0.250057 0.43298 -0.250057 0.43298 0.250057 -0.43298 
-0.43298 -0.250057 0.43298 0.250057 0.43298 0.250057 -0.43298 -0.250057 
0.43298 -0.250057 0.43298 -0.250057 0.43298 -0.250057 0.43298 -0.250057 
0.250057 0.43298 0.250057 0.43298 0.250057 0.43298 0.250057 0.43298 

Quantum State is: 
|000> 0.250057
|001> -0.43298
|010> 0.43298
|011> 0.250057
|100> 0.250057
|101> -0.43298
|110> 0.43298
|111> 0.250057


Probability of Quantum States: 
|000> 6.25287%
|001> 18.7471%
|010> 18.7471%
|011> 6.25287%
|100> 6.25287%
|101> 18.7471%
|110> 18.7471%
|111> 6.25287%


Quantum Circuit: 
Q0 Z-T-R-H-----------------
Q1 H-C-C-X-----------------
Q2 Z-H-T------------------

Results of Execution are: 
|000> 63
|001> 203
|010> 209
|011> 83
|100> 68
|101> 180
|110> 160
|111> 58


*/
