#ifndef QuantumProgram_h
#define QuantumProgram_h
#include <bits/stdc++.h>
#include<math.h>
#include<complex>
#include<iostream>
#include <time.h>
#include <random>
#include <iomanip>
using std::cout;
using std::endl;
using std::setprecision;
constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;
using namespace std;

//defining QuantumProgram class
class QuantumProgram
{
public:


//variables in QuantumProgram class
int number_of_qubits;
int number_of_shots;
double theta=0;
bool readstate=false;


// State variables for 2 qubit systems
int q2s1=0;
int q2s2=0;


// State variables for 3 qubit systems
int q3s1=0;
int q3s2=0;
int q3s3=0;

//constructor to initialize number of qubits in the circuit
QuantumProgram(int n)
{
number_of_qubits=n;
}

//arrays to store state vectors
double psi1[2]={0};
double psi2[4]={0};
double psi3[8]={0};


//arrays to store final quantum state vectors
double qs1[2];
double qs2[4];
double qs3[8];


//arrays to store results after executing given number of shots
int executearray1[2]={0};
int executearray2[4]={0};
int executearray3[8]={0};


//count arrays to draw circuit and add gates
int countcircuit0=0;
int countcircuit1=0;
int countcircuit2=0;


//arrays to store probability vectors
int probab1[2]={0};
int probab2[4]={0};
int probab3[8]={0};


//character arrays to draw the circuit
char circuitline0[20]={0};
char circuitline1[20]={0};
char circuitline2[20]={0};


//unitary matrices to store intermediate unitary matrix in between gate operations
double unitary_1q[2][2]={0};
double unitary_2q[4][4]={0};
double unitary_3q[8][8]={0};
double unitary_4q[16][16]={0};


//final unitary matrices to store the resulting unitary matrix after all operations
double unitary_1q_final[2][2]=
{1,0,
0,1};
double unitary_2q_final[4][4]=
{1,0,0,0,
0,1,0,0,
0,0,1,0,
0,0,0,1};
double unitary_3q_final[8][8]=
{1,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,
0,0,0,1,0,0,0,0,
0,0,0,0,1,0,0,0,
0,0,0,0,0,1,0,0,
0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,1};


//Temporary matrices to store multiplication products
double matrix2[2][2]={0};
double matrix4[4][4]={0};
double matrix8[8][8]={0};

/*
Matrices to represent Quantum Gates Matrices. These follow Little Endian convention in accordance to Qiskit's convention.
*/

//CNOT GATE MATRIX (CX)
double cnottc[4][4]=
//little enidian
//when target qubit is greater than control qubit
{1,0,0,0,
0,0,0,1,
0,0,1,0,
0,1,0,0};
double cnotct[4][4]=
//when control qubit is greater than target qubit
{1,0,0,0,
0,1,0,0,
0,0,0,1,
0,0,1,0};
/*
double cnot3q[8][8]=
{1,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,
0,0,0,1,0,0,0,0,
0,0,0,0,0,1,0,0,
0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,1,0};
*/

//HADAMARD GATE MATRIX
double hadamard[2][2]=
{1/sqrt(2),1/sqrt(2),
1/sqrt(2),-1/sqrt(2)};



//NOT GATE (X) MATRIX
double notX[2][2]=
{0,1,
1,0};


//IDENTITY MATRIX (I)
double identity[2][2]=
{1,0,
0,1};

//Z GATE MATRIX (Z)
double z[2][2]=
{1,0,
0,-1};


//ROTATION GATE MATRICES
double rx[2][2]={0};
double ry[2][2]={0};
double rz[2][2]={0};



/*
Methods in Quantum Program Class. Used to execute the quantum circuit and calculate respective probabilities, after application of gates. 
*/

void create_state();
void not_gate(int qubitposition);
void hadamard_gate(int qubitposition);
void z_gate(int qubitposition);
void rx_gate(int qubitposition,double theta);
void ry_gate(int qubitposition,double angle);
void rz_gate(int qubitposition,double theta);
void cnot_gate(int controlqubit,int targetqubit);
void cz_gate(int controlqubit,int targetqubit);
void Kronecker_Product(double *C, double *A, int nrows, int ncols, double *B, int mrows, int mcols);
void Matrix_Product(double *C, double *A, int nrows, int ncols,double *B, int mcols);
void Multiply_Matrix_by_Vector(double u[], double *A, int nrows, int ncols, double v[]);
void observing_probabilitites();                                                                  
void read_state();
void read_unitary();
void draw_circuit();
void execute(int number_of_shots);                                                             

};

#endif
