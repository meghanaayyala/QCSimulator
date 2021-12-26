#include<math.h>
#include<complex>
#include<iostream>
using namespace std;
#include "QuantumProgram.h"


int main()
{
QuantumProgram q1(2);

q1.hadamard_gate(0);
q1.cnot_gate(0,1);
q1.create_state();
q1.read_state();
cout<<endl;
q1.draw_circuit();
}