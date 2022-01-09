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

circuit.h(qreg_q[0])
circuit.x(qreg_q[1])
circuit.z(qreg_q[0])
circuit.z(qreg_q[1])
circuit.cx(qreg_q[1], qreg_q[2])
circuit.cx(qreg_q[1], qreg_q[0])
circuit.ry(pi/4, qreg_q[0])
*/
q1.hadamard_gate(0);
q1.not_gate(1);
q1.z_gate(0);
q1.z_gate(1);
q1.cnot_gate(1,2);
q1.cnot_gate(1,0);
q1.ry_gate(0,3.14/4);

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

/*
OUTPUT
0 0 0.923803 0.382867 0 0 0 0 
0 0 -0.382867 0.923803 0 0 0 0 
0 0 0 0 0.923803 -0.382867 0 0 
0 0 0 0 -0.382867 -0.923803 0 0 
0 0 0 0 0 0 0.923803 0.382867 
0 0 0 0 0 0 -0.382867 0.923803 
0.923803 -0.382867 0 0 0 0 0 0 
-0.382867 -0.923803 0 0 0 0 0 0 

Quantum State is: 
|000> 0
|001> 0
|010> 0
|011> 0
|100> 0
|101> 0
|110> 0.923803
|111> -0.382867


Probability of Quantum States: 
|000> 0%
|001> 0%
|010> 0%
|011> 0%
|100> 0%
|101> 0%
|110> 85.3413%
|111> 14.6587%


Quantum Circuit: 
Q0 H-Z-T-R-----------------
Q1 X-Z-C-C-----------------
Q2 T--------------------

Results of Execution are: 
|000> 0
|001> 0
|010> 0
|011> 0
|100> 0
|101> 0
|110> 873
|111> 151


*/
