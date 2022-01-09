#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"
int main() 
{


/* Qiskit Code
from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit
from numpy import pi

qreg_q = QuantumRegister(2, 'q')
creg_c = ClassicalRegister(2, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)

circuit.h(qreg_q[0])
circuit.h(qreg_q[1])
circuit.h(qreg_q[1])
circuit.cx(qreg_q[0], qreg_q[1])
circuit.h(qreg_q[0])
circuit.h(qreg_q[1])
circuit.z(qreg_q[0])
circuit.h(qreg_q[1])
circuit.z(qreg_q[1])
circuit.h(qreg_q[1])
circuit.cx(qreg_q[0], qreg_q[1])
circuit.h(qreg_q[0])
circuit.h(qreg_q[1])
circuit.h(qreg_q[1])
*/
  
//QCSimulator Implementation
QuantumProgram q1(2);
q1.hadamard_gate(0);
q1.hadamard_gate(1);
q1.hadamard_gate(1);
q1.cnot_gate(0,1);
q1.hadamard_gate(0);
q1.hadamard_gate(1);
q1.z_gate(0);
q1.hadamard_gate(1);
q1.z_gate(1);
q1.hadamard_gate(1);
q1.cnot_gate(0,1);
q1.hadamard_gate(0);
q1.hadamard_gate(1);
q1.hadamard_gate(1);




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
//OUTPUT:
0 0 0 -1 
0 1 0 0 
0 0 1 0 
1 0 0 0 

Quantum State is: 
|00> 0
|01> 0
|10> 0
|11> 1


Probability of Quantum States: 
|00> 0%
|01> 0%
|10> 0%
|11> 100%


Quantum Circuit: 
Q0 H-C-H-Z-C-H---------------
Q1 H-H-T-H-H-Z-H-T-H-H-----------

Results of Execution are: 
|00> 0
|01> 0
|10> 0
|11> 1024
*/
