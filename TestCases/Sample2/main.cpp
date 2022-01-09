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
circuit.cx(qreg_q[1], qreg_q[2])
circuit.cx(qreg_q[1], qreg_q[0])
circuit.z(qreg_q[2])
circuit.ry(pi/4, qreg_q[0])
circuit.h(qreg_q[2])
circuit.x(qreg_q[1])
*/
q1.z_gate(0);
q1.cnot_gate(1,2);
q1.cnot_gate(1,0);
q1.z_gate(2);
q1.ry_gate(0,3.14/4);
q1.hadamard_gate(2);
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





/* OUTPUT
0 0 0.270468 0.653335 0 0 -0.270468 -0.653335 
0 0 -0.653335 0.270468 0 0 0.653335 -0.270468 
0.653335 0.270468 0 0 -0.653335 -0.270468 0 0 
0.270468 -0.653335 0 0 -0.270468 0.653335 0 0 
0 0 -0.270468 -0.653335 0 0 -0.270468 -0.653335 
0 0 0.653335 -0.270468 0 0 0.653335 -0.270468 
0.653335 0.270468 0 0 0.653335 0.270468 0 0 
0.270468 -0.653335 0 0 0.270468 -0.653335 0 0 

Quantum State is: 
|000> 0
|001> 0
|010> 0.653335
|011> 0.270468
|100> 0
|101> 0
|110> 0.653335
|111> 0.270468


Probability of Quantum States: 
|000> 0%
|001> 0%
|010> 42.6847%
|011> 7.31529%
|100> 0%
|101> 0%
|110> 42.6847%
|111> 7.31529%


Quantum Circuit: 
Q0 Z-T-R------------------
Q1 C-C-X------------------
Q2 T-Z-H------------------

Results of Execution are: 
|000> 0
|001> 0
|010> 445
|011> 71
|100> 0
|101> 0
|110> 434
|111> 74


*/
