# QCourse-511-1 Final Project
## QCSimulator: Simulating a Quantum Computer using C++
Simulating a Quantum Computer using C++

## Introduction
This repository contains the final code for the project phase of [QCourse 511-1](https://qworld.net/qcourse511-1/). 
It aims to simulate a quantum computer using the C++ Programming Language. It is the implementation of QWorld's QBronze Project- [Your Quantum Simulator](https://gitlab.com/qworld/bronze-qiskit/-/blob/master/projects/Project_Your_Quantum_Simulator.ipynb).
<br>
The target outcome is to implement a simple Quantum Program through implementation of Quantum Gates from scratch. All numerical and algebraic methods have been implemented from scratch, such as matrix multiplications, tensor products, vector products.
**Student Name:** Meghana Ayyala Somayajula <br>
**Discord Handle:** StoicCloud#7376

### Midterm Deliverables
Code for implementing methods for Quantum Operators- Hadamard,NOTZ-gate,Rotations on the unit circle with the specified angle and CNOT operator.
<br>
Link to [Mid Term Report](https://docs.google.com/document/d/1Y-oOJxMQ9ECklWSBW3SVBCbNfBO2QpNzUaaBE8N7vFk/edit?usp=sharing)
### Final Deliverables 
Code for methods for simulating the Circuit:read_unitary(), read_state,observing_probabilities(),execute(the_number_of_shots)and Testing object.
Presentation.

#### Links to GitHub Repository 
[GitHub Repository](https://github.com/meghanaayyala/QCSimulator)


## Outcomes of Project 
### Quantum Program Class
This class contains all the required methods and variables to implement Quantum Gates and efficiently design a circuit. 
A maximum of 3 qubits can be simulated. The following are the list of methods and their syntax.
### Methods for Executing Circuits and Drawing Circuits
#### ```QuantumProgram(int n); ```
Creates an object of QuantumProgram class. Here n stands for number of qubits required in the quantum circuit.
#### ```void create_state(); ```
Creates a default quantum state according to the number of qubits.
#### ```void read_state(); ```
Prints the current quantum state of circuit after application of all the defined quantum operators until this point.
#### ```void read_unitary(); ```
Prints the unitary matrix (quantum operator) equivalent to all defined quantum operators until this point, i.e., the multiplication of all quantum operators in the defined order.
#### ```void draw_circuit();```
Draws the quantum circuit at any point after application of the defined quantum gates in a schematic way. <br>
*Representation*: <br>
Hadamard Gate ‘H’<br>
CNOT Gate ‘C’ (Control Qubit), ‘T’ (Target Qubit)<br>
NOT Gate ‘X’<br>
Z Gate ‘Z’<br>
RY Gate 'R'<br>
#### ```void observing_probabilitites();  ```
Prints the probabilities of observing each quantum state in the state vector in terms of percentages
#### ```void execute(int number_of_shots); ```
Prints the result of execution given the number of shots as input. Results are printed in terms of frequencies of observing a state with respect to its probability, after all qubits are measured.
#### ```Kronecker_Product(double *C, double *A, int nrows, int ncols, double *B, int mrows, int mcols); ```
Performs the tensor product of Matrix A and Matrix B in that order and stores the resultant in Matrix C

#### ```Matrix_Product(double *C, double *A, int nrows, int ncols, double *B, int mcols); ```
Performs matrix multiplication of Matrix A and Matrix B in that order and stores the resultant in Matrix C

#### ```Multiply_Matrix_by_Vector(double U[], double *A, int nrows, int ncols,double V[]); ```
Performs multiplication of a Matrix A with vector V and stores resultant in U.

### Quantum Gates Implementing Methods

#### ```void hadamard_gate(int qubitposition);```
Implements the Hadamard Quantum Gate on the given qubit position argument. 

#### ```void not_gate(int qubitposition);```
Implements the NOT Quantum Gate on the given qubit position argument

#### ```void ry_gate(int qubitposition,double angle);```
Implements the RY Quantum Gate on the given qubit position argument, and given angle in radians

#### ```void cnot_gate(int controlqubit,int targetqubit);```
Implements the multiqubit CNOT Quantum Gate on the given qubits accordingly taken as control qubit and target qubit

#### ```void z_gate(int qubitposition);```
Implements the Z Quantum Gate on the given qubit position argument


### Examples of Circuit Implementation
For further code and explanation, the GitHub repo contains images, code and comparison between the circuits executed through QCSimulator and IBM Circuit Composer. Few Examples are taken here to demonstrate the successful outcomes of the project.

#### Grover's Search for 2 Qubits in IBM Circuit Composer
![GroversSearchIBMCircuit](https://user-images.githubusercontent.com/76214336/148680199-98680002-3506-4ed9-97f7-66a98af1a143.png)
<br>

Code for Grover's Search in Qiskit
```
//Qiskit Code
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
```

#### Grover's Search for 2 Qubits in QCSimulator Output

![GroversSearchOutput](https://user-images.githubusercontent.com/76214336/148680162-245a85e0-8cb8-498b-9357-717adff6fefd.png)
<br>
Code for Grover's Search for 2 Qubits in QCSimulator
```
#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"
int main() 
{

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
```


Further examples, including the creation of the 4 Bell States, and few sample few circuits have been shown in the GitHub Repository. Outputs of the same circuit in IBM Circuit Composer have also been shown.


## Discussions
The simulator successfully replicates existing Quantum Computing Programming Language Qiskit as shown. All the mathematical methods like multiplication of matrices, tensoring products and matrix and vector multiplications have been implemented from scratch. Since the code is in C++, it is rather hard to work with reference variables and dynamic memory storage with respect to the number of qubits passed by the user as input.
<br>
The originality of the project lies in the scratch implementation of matrix methods, along with drawing the circuit through character arrays and characters representing the gates. Also it can be observed that there is very little difference and error as compared to existing QC Programming Languages, despite the heavy calculations and loops in this C++ program. 

## Future Extension
The project can be extended to support more than 3 qubits. Also implementation of the other quantum gates, for example 3 qubit gates can be done. Challenges faced in heavy calculations can be reduced through better algorithms and more efficient writing of loops. Also better logic for computing intermediate multiplications and tensoring of products, for example when Hadamard(0) and Hadamard(1) is applied rather than implemeting IxH and HxI to get the unitary matrix directly implementing HxH through scheduling can be done for reducation in calculations. A text file parser would also help in writing cleaner code.


## Conclusions
This project successfully implements basic 3 qubit quantum circuits with a few one qubit and two qubit gates in C++ Programming language. All the deliverables have been updated in the GitHub Repository. 

## References
[QWorld-QBronze](https://gitlab.com/qworld/bronze-qiskit/-/blob/master/projects/Project_Your_Quantum_Simulator.ipynb) <br>
[Quantum++: A modern C++ quantum computing library](https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0208073)

##

