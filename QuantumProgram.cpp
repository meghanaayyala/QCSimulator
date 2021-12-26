#include "QuantumProgram.h"



//creating a Default Quantum State Psi where all qubits are set to zero
void QuantumProgram:: create_state()
{
if(number_of_qubits==1)
{
psi1[0]=1;
for(int i=1;i<2;i++)
{
psi1[i]=0;
}

}
if(number_of_qubits==2)
{
psi2[0]=1;
for(int i=1;i<4;i++)
{
psi2[i]=0;
}
}
if(number_of_qubits==3)
{
psi3[0]=1;
for(int i=1;i<8;i++)
{
psi3[i]=0;
}
}
}





//Printing Quantum State after multiplying Final Unitary Operator after all operations with Default Quantum State
void QuantumProgram:: read_state()
{
  cout<<"Quantum State is: "<<endl;
  if(number_of_qubits==1)
{
    Multiply_Matrix_by_Vector(qs1, *unitary_1q_final, 2, 2,psi1);
    for(int i=0;i<2;i++)
    {
      cout<<qs1[i]<<endl;
    } 
}
else if(number_of_qubits==2)
{
  Multiply_Matrix_by_Vector(qs2, *unitary_2q_final, 4, 4,psi2);
    for(int i=0;i<4;i++)
    {
      cout<<qs2[i]<<endl;
    } 
}
else if(number_of_qubits==3)
{
 Multiply_Matrix_by_Vector(qs3, *unitary_3q_final, 8, 8,psi3);
    for(int i=0;i<8;i++)
    {
      cout<<qs3[i]<<endl;
    }
}
else
{
  cout<<"Error"<<endl;
}
}
void QuantumProgram:: read_unitary()
{
if(number_of_qubits==1)
{
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      cout<<unitary_1q_final[i][j]<<" ";
    }
    cout<<endl;
  }
}
else if(number_of_qubits==2)
{
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      cout<<unitary_2q_final[i][j]<<" ";
    }
    cout<<endl;
  }
}
else if(number_of_qubits==3)
{
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      cout<<unitary_3q_final[i][j]<<" ";
    }
    cout<<endl;
  }
}
else
{
  cout<<"Error"<<endl;
}
}




//Function to multiply matrices
void QuantumProgram:: Matrix_Product(double *C, double *A, int nrows, int ncols,
                                                         double *B, int mcols)
{
	double *pB;
   double *p_B;
   int i,j,k;

   for (i = 0; i < nrows; A += ncols, i++) {
      for (p_B = B, j = 0; j < mcols; C++, p_B++, j++) {
         pB = p_B;
         *C = 0.0; 
         for (k = 0; k < ncols; pB += mcols, k++) 
            *C += *(A+k) * *pB;
      }
	}
}


//Function to perform Tensor Product

void QuantumProgram::Kronecker_Product(double *C, double *A, int nrows, int ncols, double *B, int mrows, int mcols)
{
int ccols, i, j, k, l;
int block_increment;
double *pB;
double *pC, *p_C;
ccols = ncols * mcols;
block_increment = mrows * ccols;
for (i = 0; i < nrows; C += block_increment, i++)
for (p_C = C, j = 0; j < ncols; p_C += mcols, A++, j++) 
for (pC = p_C, pB = B, k = 0; k < mrows; pC += ccols, k++)
for (l = 0; l < mcols; pB++, l++) *(pC+l) = *A * *pB; 
}





//Function to perform matrix and vector multiplication
void QuantumProgram::Multiply_Matrix_by_Vector(double u[], double *A, int nrows, int ncols,
                                                                    double v[]) 
{
   int i,j;

   for (i = 0; i < nrows; A += ncols, i++) 
      for (u[i] = 0.0, j = 0; j < ncols; j++) u[i] += A[j] * v[j];
}





//Hadamard Gate Implementation
void QuantumProgram:: hadamard_gate(int qubitposition)
{
if(number_of_qubits==1)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
unitary_1q[i][j]=hadamard[i][j];
}
}
Matrix_Product(*matrix2,*unitary_1q_final,2,2,*unitary_1q,2);
for(int i=0;i<2;i++)
{
  for(int j=0;j<2;j++)
  {
    unitary_1q_final[i][j]=matrix2[i][j];
  }
}
circuitline0[countcircuit0]='H';
countcircuit0++;
}
else if(number_of_qubits==2)
{
if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)hadamard, 2, 2, (double*)identity, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline1[countcircuit1]='H';
countcircuit1++;
}
else if(qubitposition==0)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)hadamard, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline0[countcircuit0]='H';
countcircuit0++;
}
else
{
  cout<<"Qubit index out of bounds."<<endl;
}
}
else if( number_of_qubits==3)
{
if(qubitposition==0)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)identity, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)hadamard, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline0[countcircuit0]='H';
countcircuit0++;
}
else if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)hadamard, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline1[countcircuit1]='H';
countcircuit1++;
}
else if(qubitposition==2)
{
Kronecker_Product(&unitary_2q[0][0], (double *)hadamard, 2, 2, (double*)identity, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline2[countcircuit2]='H';
countcircuit2++;
}
else
{
  cout<<"Qubit index out of bounds."<<endl;
}
}
}





//NOT Gate (X Gate) implementation
void QuantumProgram:: not_gate(int qubitposition)
{
if(number_of_qubits==1)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
unitary_1q[i][j]=notX[i][j];
}
}
Matrix_Product(*matrix2,*unitary_1q_final,2,2,*unitary_1q,2);
for(int i=0;i<2;i++)
{
  for(int j=0;j<2;j++)
  {
    unitary_1q_final[i][j]=matrix2[i][j];
  }
}
circuitline0[countcircuit0]='X';
countcircuit0++;
}
else if(number_of_qubits==2)
{
if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)notX, 2, 2, (double*)identity, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline1[countcircuit1]='X';
countcircuit1++;
}
else if(qubitposition==0)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)notX, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline0[countcircuit0]='X';
countcircuit0++;
}
else
{
  cout<<"Qubit index out of bounds."<<endl;
}
}
else if( number_of_qubits==3)
{
if(qubitposition==0)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)identity, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)notX, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline0[countcircuit0]='X';
countcircuit0++;
}
if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)notX, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline1[countcircuit1]='X';
countcircuit1++;
}
else if(qubitposition==2)
{
Kronecker_Product(&unitary_2q[0][0], (double *)notX, 2, 2, (double*)identity, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline2[countcircuit2]='X';
countcircuit2++;
}
else
{
  cout<<"Qubit index out of bounds."<<endl;
}
}
}

//Z Gate implementation
void QuantumProgram:: z_gate(int qubitposition)
{
if(number_of_qubits==1)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
unitary_1q[i][j]=z[i][j];
}
}
Matrix_Product(*matrix2,*unitary_1q_final,2,2,*unitary_1q,2);
for(int i=0;i<2;i++)
{
  for(int j=0;j<2;j++)
  {
    unitary_1q_final[i][j]=matrix2[i][j];
  }
}
circuitline0[countcircuit0]='Z';
countcircuit0++;
}
else if(number_of_qubits==2)
{
if(qubitposition==0)
{
Kronecker_Product(&unitary_2q[0][0], (double *)z, 2, 2, (double*)identity, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline0[countcircuit0]='Z';
countcircuit0++;
}
else if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)z, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline1[countcircuit1]='Z';
countcircuit1++;
}
else
{
  cout<<"Qubit index out of bounds."<<endl;
}
}
else if( number_of_qubits==3)
{
if(qubitposition==0)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)identity, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)z, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline0[countcircuit0]='Z';
countcircuit0++;
}
else if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)z, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline1[countcircuit1]='Z';
countcircuit1++;
}
else if(qubitposition==2)
{
Kronecker_Product(&unitary_2q[0][0], (double *)z, 2, 2, (double*)identity, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline2[countcircuit2]='Z';
countcircuit2++;
}
else
{
  cout<<"Qubit index out of bounds."<<endl;
}
}
}




//CNOT Gate implementation
void QuantumProgram::cnot_gate(int controlqubit,int targetqubit)
{
if(number_of_qubits==1)
{
cout<<"Error"<<endl;
}
else if(targetqubit==controlqubit)
{
cout<<"Error"<<endl;
}
else
{
if(number_of_qubits==2)
{
if(targetqubit==1&&controlqubit==0)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
unitary_2q[i][j]=cnottc[i][j];
}
Matrix_Product(*matrix4,*unitary_2q,4,4,*unitary_2q_final,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline1[countcircuit1]='T';
countcircuit1++;
circuitline0[countcircuit0]='C';
countcircuit0++;
}
else
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
unitary_2q[i][j]=cnotct[i][j];
}
Matrix_Product(*matrix4,*unitary_2q,4,4,*unitary_2q_final,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline1[countcircuit1]='C';
countcircuit1++;
circuitline0[countcircuit0]='T';
countcircuit0++;
}
}
if(number_of_qubits==3)
{
if(controlqubit==1&&targetqubit==2)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++){
unitary_2q[i][j]=cnottc[i][j];}
}
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q,8,8,*unitary_3q_final,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline1[countcircuit1]='C';
countcircuit1++;
circuitline2[countcircuit2]='T';
countcircuit2++;
}
else if(controlqubit==2&&targetqubit==1)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++){
unitary_2q[i][j]=cnotct[i][j];
}
}
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline2[countcircuit2]='C';
countcircuit2++;
circuitline1[countcircuit1]='T';
countcircuit1++;
}
else if(controlqubit==0&&targetqubit==2)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++){
unitary_2q[i][j]=cnottc[i][j];
}
}
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline2[countcircuit2]='T';
countcircuit2++;
circuitline0[countcircuit0]='C';
countcircuit0++;
}
else if(controlqubit==2&&targetqubit==0)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++){
unitary_2q[i][j]=cnotct[i][j];
}
}
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline2[countcircuit2]='C';
countcircuit2++;
circuitline0[countcircuit0]='T';
countcircuit0++;
}
else if(controlqubit==0&&targetqubit==1)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++){
unitary_2q[i][j]=cnottc[i][j];}
}
Kronecker_Product(&unitary_3q[0][0], (double *)identity, 2, 2, (double*)unitary_2q, 4, 4);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
  cout<<endl;
}
circuitline0[countcircuit0]='C';
countcircuit0++;
circuitline1[countcircuit1]='T';
countcircuit1++;
}
else if(controlqubit==1&&targetqubit==0)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++){
unitary_2q[i][j]=cnotct[i][j];}
}
Kronecker_Product(&unitary_3q[0][0], (double *)identity, 2, 2, (double*)unitary_2q, 4, 4);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline0[countcircuit0]='T';
countcircuit0++;
circuitline1[countcircuit1]='C';
countcircuit1++;
}
else
{
  cout<<"Error."<<endl;
}
}
}
}




//Function to draw Quantum Circuit
void QuantumProgram::draw_circuit()
{
  cout<<"Quantum Circuit: "<<endl;
  if(number_of_qubits==1){
    cout<<"Q0"<<" ";
  for(int i=0;i<20;i++)
  {
    //if(circuitline0[i]!=0)
    //{
      cout<<circuitline0[i]<<"-";
    //}
  }
  }
  else if(number_of_qubits==2)
  {
     cout<<"Q0"<<" ";
      for(int i=0;i<20;i++)
  {
    //if(circuitline0[i]!=0)
    //{
      cout<<circuitline0[i]<<"-";
    //}
  }
    cout<<endl;
 cout<<"Q1"<<" ";
    for(int i=0;i<20;i++)
  {
    //if(circuitline1[i]!=0)
    //{
      cout<<circuitline1[i]<<"-";
    //}
  }
  
  }
  else if(number_of_qubits==3)
  {

     cout<<"Q0"<<" ";
   for(int i=0;i<20;i++)
  {
    //if(circuitline0[i]!=0)
    //{
      cout<<circuitline0[i]<<"-";
    //}
  }
    cout<<endl;
 cout<<"Q1"<<" ";
    for(int i=0;i<20;i++)
  {
    //if(circuitline1[i]!=0)
    //{
      cout<<circuitline1[i]<<"-";
    //}
  }
  cout<<endl;
 cout<<"Q2"<<" ";
    for(int i=0;i<20;i++)
  {
    //if(circuitline2[i]!=0)
    //{
      cout<<circuitline2[i]<<"-";
    //}
  }
  }

}