

#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"
int main() 
{
  /*
  Qiskit Code
  from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit
from numpy import pi

qreg_q = QuantumRegister(2, 'q')
creg_c = ClassicalRegister(2, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)

circuit.h(qreg_q[0])
circuit.cx(qreg_q[0], qreg_q[1])
*/
  
 
QuantumProgram q1(2);
q1.hadamard_gate(0);
q1.cnot_gate(0,1);


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
0.707107 0.707107 0 0 
0 0 0.707107 -0.707107 
0 0 0.707107 0.707107 
0.707107 -0.707107 0 0 

Quantum State is: 
|00> 0.707107
|01> 0
|10> 0
|11> 0.707107


Probability of Quantum States: 
|00> 50%
|01> 0%
|10> 0%
|11> 50%


Quantum Circuit: 
Q0 H-C-------------------
Q1 T--------------------

Results of Execution are: 
|00> 515
|01> 0
|10> 0
|11> 509
*/






#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"
int main() 
{
  /*
  Qiskit Code
  from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit
from numpy import pi

qreg_q = QuantumRegister(2, 'q')
creg_c = ClassicalRegister(2, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)
circuit.x(qreg_q[0])
circuit.h(qreg_q[0])
circuit.cx(qreg_q[0], qreg_q[1])
*/
  
 
QuantumProgram q1(2);
q1.not_gate(0);
q1.hadamard_gate(0);
q1.cnot_gate(0,1);


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
0.707107 0.707107 0 0 
0 0 -0.707107 0.707107 
0 0 0.707107 0.707107 
-0.707107 0.707107 0 0 

Quantum State is: 
|00> 0.707107
|01> 0
|10> 0
|11> -0.707107


Probability of Quantum States: 
|00> 50%
|01> 0%
|10> 0%
|11> 50%


Quantum Circuit: 
Q0 X-H-C------------------
Q1 T--------------------

Results of Execution are: 
|00> 514
|01> 0
|10> 0
|11> 510
*/






#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"
int main() 
{
  /*
  Qiskit Code
  from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit
from numpy import pi

qreg_q = QuantumRegister(2, 'q')
creg_c = ClassicalRegister(2, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)
circuit.h(qreg_q[0])
circuit.x(qreg_q[1])
circuit.cx(qreg_q[0], qreg_q[1])
*/
  
 
QuantumProgram q1(2);
q1.hadamard_gate(0);
q1.not_gate(1);
q1.cnot_gate(0,1);


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
/*  OUTPUT
0 0 0.707107 0.707107 
0.707107 -0.707107 0 0 
0.707107 0.707107 0 0 
0 0 0.707107 -0.707107 

Quantum State is: 
|00> 0
|01> 0.707107
|10> 0.707107
|11> 0


Probability of Quantum States: 
|00> 0%
|01> 50%
|10> 50%
|11> 0%


Quantum Circuit: 
Q0 H-C-------------------
Q1 X-T-------------------

Results of Execution are: 
|00> 0
|01> 499
|10> 525
|11> 0
*/







#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"
int main() 
{
  /*
  Qiskit Code
  from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit
from numpy import pi

qreg_q = QuantumRegister(2, 'q')
creg_c = ClassicalRegister(2, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)
circuit.h(qreg_q[0])
circuit.x(qreg_q[1])
circuit.z(qreg_q[0])
circuit.z(qreg_q[1])
circuit.cx(qreg_q[0], qreg_q[1])
*/
  
 
QuantumProgram q1(2);
q1.hadamard_gate(0);
q1.not_gate(1);
q1.z_gate(0);
q1.z_gate(1);
q1.cnot_gate(0,1);


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
0 0 0.707107 0.707107 
0.707107 -0.707107 0 0 
-0.707107 -0.707107 0 0 
0 0 -0.707107 0.707107 

Quantum State is: 
|00> 0
|01> 0.707107
|10> -0.707107
|11> 0


Probability of Quantum States: 
|00> 0%
|01> 50%
|10> 50%
|11> 0%


Quantum Circuit: 
Q0 H-Z-C------------------
Q1 X-Z-T------------------

Results of Execution are: 
|00> 0
|01> 532
|10> 492
|11> 0

*/
