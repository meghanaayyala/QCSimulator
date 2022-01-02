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
class QuantumProgram
{
public:
int number_of_qubits;
int number_of_shots;
double theta=0;
bool readstate=false;
QuantumProgram(int n)
{
number_of_qubits=n;
}
//
int q2s1=0;
int q2s2=0;
//
int q3s1=0;
int q3s2=0;
int q3s3=0;
double psi1[2]={0};
double psi2[4]={0};
double psi3[8]={0};
//double psi4[16]={0};
double qs1[2];
double qs2[4];
double qs3[8];
//double qs4[16];
int executearray1[2]={0};
int executearray2[4]={0};
int executearray3[8]={0};
//
int countcircuit0=0;
int countcircuit1=0;
int countcircuit2=0;
//
int probab1[2]={0};
  int probab2[4]={0};
  int probab3[8]={0};
//
char circuitline0[20]={0};
char circuitline1[20]={0};
char circuitline2[20]={0};
double unitary_1q[2][2]={0};
double unitary_2q[4][4]={0};
double unitary_3q[8][8]={0};
double unitary_4q[16][16]={0};
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
double cnottc[4][4]=
{1,0,0,0,
0,0,0,1,
0,0,1,0,
0,1,0,0};
double cnotct[4][4]=
{1,0,0,0,
0,1,0,0,
0,0,0,1,
0,0,1,0};
double hadamard[2][2]=
{1/sqrt(2),1/sqrt(2),
1/sqrt(2),-1/sqrt(2)};
double matrix2[2][2]={0};
double matrix4[4][4]={0};
double matrix8[8][8]={0};
double notX[2][2]=
{0,1,
1,0};
double identity[2][2]=
{1,0,
0,1};
double z[2][2]=
{1,0,
0,-1};

double rx[2][2]={0};
double ry[2][2]={0};
double rz[2][2]={0};
void create_state();
void not_gate(int qubitposition);
void hadamard_gate(int qubitposition);
void z_gate(int qubitposition);
void rx_gate(int qubitposition,double theta);
void ry_gate(int qubitposition,double angle);
void rz_gate(int qubitposition,double theta);
void cnot_gate(int controlqubit,int targetqubit);

void Kronecker_Product(double *C, double *A, int nrows, int ncols, double *B, int mrows, int mcols);
void Matrix_Product(double *C, double *A, int nrows, int ncols,
                                                          double *B, int mcols);
                                                        
void Multiply_Matrix_by_Vector(double u[], double *A, int nrows, int ncols,
                                                                    double v[]);
                                                              
void observing_probabilitites();
void read_state();
void read_unitary();
void draw_circuit();
void execute(int number_of_shots);
};

#endif
