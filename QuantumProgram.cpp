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
  cout<<endl;
  cout<<"Quantum State is: "<<endl;
  if(number_of_qubits==1)
{
    Multiply_Matrix_by_Vector(qs1, *unitary_1q_final, 2, 2,psi1);
    cout<<"|0> "<<qs1[0]<<endl;
    cout<<"|1> "<<qs1[1]<<endl;
    cout<<endl;
    /*
    for(int i=0;i<2;i++)
    {
      cout<<qs1[i]<<"\t|"<<i<<">"<<endl;
    } 
    */
}
else if(number_of_qubits==2)
{
  Multiply_Matrix_by_Vector(qs2, *unitary_2q_final, 4, 4,psi2);
  /*
    for(int i=0;i<4;i++)
    {
      cout<<qs2[i]<<"\t|"<<i<<">"<<endl;
    }
    */
    cout<<"|00> "<<qs2[0]<<endl;
    cout<<"|01> "<<qs2[1]<<endl;
    cout<<"|10> "<<qs2[2]<<endl;
    cout<<"|11> "<<qs2[3]<<endl;
    cout<<endl;
}
else if(number_of_qubits==3)
{
 Multiply_Matrix_by_Vector(qs3, *unitary_3q_final, 8, 8,psi3);
    /*
    for(int i=0;i<8;i++)
    {
      cout<<qs3[i]<<"\t|"<<i<<">"<<endl;
    }
    */
    cout<<"|000> "<<qs3[0]<<endl;
    cout<<"|001> "<<qs3[1]<<endl;
    cout<<"|010> "<<qs3[2]<<endl;
    cout<<"|011> "<<qs3[3]<<endl;
    cout<<"|100> "<<qs3[4]<<endl;
    cout<<"|101> "<<qs3[5]<<endl;
    cout<<"|110> "<<qs3[6]<<endl;
    cout<<"|111> "<<qs3[7]<<endl;
    cout<<endl;
}
else
{
  cout<<"Error"<<endl;
}
readstate=true;
}


//Observing Probabilities


void QuantumProgram::observing_probabilitites()
{
  
  

  
  cout<<"Probability of Quantum States: "<<endl;
if(readstate==false)
{
if(number_of_qubits==1)
{
    Multiply_Matrix_by_Vector(qs1, *unitary_1q_final, 2, 2,psi1);
}
else if(number_of_qubits==2)
{
  Multiply_Matrix_by_Vector(qs2, *unitary_2q_final, 4, 4,psi2);
}
else if(number_of_qubits==3)
{
 Multiply_Matrix_by_Vector(qs3, *unitary_3q_final, 8, 8,psi3);
}
else
{
  cout<<"Error"<<endl;
}
}
if(number_of_qubits==1)
{
      cout<<"|0> "<<qs1[0]*qs1[0]*100<<"%"<<endl;
      cout<<"|1> "<<qs1[1]*qs1[1]*100<<"%"<<endl;
      cout<<endl;
      probab1[0]=qs1[0]*qs1[0]*100;
      probab1[1]=qs1[1]*qs1[1]*100;
    
}
else if(number_of_qubits==2)
{
      cout<<"|00> "<<qs2[0]*qs2[0]*100<<"%"<<endl;
      cout<<"|01> "<<qs2[1]*qs2[1]*100<<"%"<<endl;
      cout<<"|10> "<<qs2[2]*qs2[2]*100<<"%"<<endl;
      cout<<"|11> "<<qs2[3]*qs2[3]*100<<"%"<<endl;
      cout<<endl;
      probab2[0]=qs2[0]*qs2[0]*100;
      probab2[1]=qs2[1]*qs2[1]*100;
      probab2[0]=qs2[2]*qs2[2]*100;
      probab2[1]=qs2[3]*qs2[3]*100;
}
else if(number_of_qubits==3)
{
      cout<<"|000> "<<qs3[0]*qs3[0]*100<<"%"<<endl;
      cout<<"|001> "<<qs3[1]*qs3[1]*100<<"%"<<endl;
      cout<<"|010> "<<qs3[2]*qs3[2]*100<<"%"<<endl;
      cout<<"|011> "<<qs3[3]*qs3[3]*100<<"%"<<endl;
      cout<<"|100> "<<qs3[4]*qs3[4]*100<<"%"<<endl;
      cout<<"|101> "<<qs3[5]*qs3[5]*100<<"%"<<endl;
      cout<<"|110> "<<qs3[6]*qs3[6]*100<<"%"<<endl;
      cout<<"|111> "<<qs3[7]*qs3[7]*100<<"%"<<endl;
      cout<<endl;
    for(int i=0;i<8;i++)
    {
      probab3[i]=qs3[i]*qs3[i]*100;
    }
}
else
{
  cout<<"Error"<<endl;
}

}

void QuantumProgram::execute(int number_of_shots)
{
   cout<<"Results of Execution are: "<<endl;
  float f;
  std::srand(std::time(nullptr));
  if(number_of_qubits==1)
{
  for(int i=0;i<number_of_shots;i++)
    {
      if( FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)))<qs1[0]*qs1[0])
      {
        executearray1[0]++;
      }
      else
      {
        executearray1[1]++;
      }
    }
    cout<<"|0> "<<executearray1[0]<<endl;
    cout<<"|1> "<<executearray1[1]<<endl;
    cout<<endl;
}


else if(number_of_qubits==2)
{
  for(int i=0;i<number_of_shots;i++)
    {
      if( FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)))<((qs2[0]*qs2[0])+(qs2[1]*qs2[1])))
      {
        q2s1=0;
      }
      else
      {
        q2s1=1;
      }
      if( FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)))<((qs2[0]*qs2[0])+(qs2[2]*qs2[2])))
      {
        q2s2=0;
      }
      else
      {
        q2s2=1;
      }
      if(q2s1==0&&q2s2==0)
      {
        executearray2[0]++;
      }
      else if(q2s1==0&&q2s2==1)
      {
        executearray2[1]++;
      }
      else if(q2s1==1&&q2s2==0)
      {
        executearray2[2]++;
      }
      else if(q2s1==1&&q2s2==1)
      {
        executearray2[3]++;
      }
      else
      {
        cout<<"Error"<<endl;
      }
    }
    cout<<"|00> "<<executearray2[0]<<endl;
    cout<<"|01> "<<executearray2[1]<<endl;
    cout<<"|10> "<<executearray2[2]<<endl;
    cout<<"|11> "<<executearray2[3]<<endl;
    cout<<endl;  
}
else if(number_of_qubits==3)
{
   for(int i=0;i<number_of_shots;i++)
    {
      if( FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)))<((qs3[0]*qs3[0])+(qs3[1]*qs3[1])+(qs3[2]*qs3[2])+(qs3[3]*qs3[3])))
      {
        q3s1=0;
      }
      else
      {
        q3s1=1;
      }
      if( FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)))<((qs3[0]*qs3[0])+(qs3[1]*qs3[1])+(qs3[4]*qs3[4])+(qs3[5]*qs3[5])))
      {
        q3s2=0;
      }
      else
      {
        q3s2=1;
      }
      if( FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)))<((qs3[0]*qs3[0])+(qs3[2]*qs3[2])+(qs3[4]*qs3[4])+(qs3[4]*qs3[6])))
      {
        q3s3=0;
      }
      else
      {
        q3s3=1;
      }
      if(q3s1==0&&q3s2==0&&q3s3==0)
      {
        executearray3[0]++;
      }
     else if(q3s1==0&&q3s2==0&&q3s3==1)
      {
        executearray3[1]++;
      }
      else if(q3s1==0&&q3s2==1&&q3s3==0)
      {
        executearray3[2]++;
      }
      else if(q3s1==0&&q3s2==1&&q3s3==1)
      {
        executearray3[3]++;
      }
      else if(q3s1==1&&q3s2==0&&q3s3==0)
      {
        executearray3[4]++;
      }
      else if(q3s1==1&&q3s2==0&&q3s3==1)
      {
        executearray3[5]++;
      }
      else if(q3s1==1&&q3s2==1&&q3s3==0)
      {
        executearray3[6]++;
      }
      else if(q3s1==1&&q3s2==1&&q3s3==1)
      {
        executearray3[7]++;
      }
      else
      {
        cout<<"Error"<<endl;
      }
    }
    cout<<"|000> "<<executearray3[0]<<endl;
    cout<<"|001> "<<executearray3[1]<<endl;
    cout<<"|010> "<<executearray3[2]<<endl;
    cout<<"|011> "<<executearray3[3]<<endl;
    cout<<"|100> "<<executearray3[4]<<endl;
    cout<<"|101> "<<executearray3[5]<<endl;
    cout<<"|110> "<<executearray3[6]<<endl;
    cout<<"|111> "<<executearray3[7]<<endl;
    cout<<endl;
    
     
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
if(qubitposition==1)
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
circuitline1[countcircuit1]='Z';
countcircuit1++;
}
else if(qubitposition==0)
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
circuitline0[countcircuit0]='Z';
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
cout<<endl;
}




//Function to define Ry Gate
void QuantumProgram:: ry_gate(int qubitposition,double angle)
{
  //theta=angle;
  ry[0][0]=cos(angle/2);ry[0][1]=-sin(angle/2);
  ry[1][0]=sin(angle/2);ry[1][1]=cos(angle/2);
   

  if(number_of_qubits==1)
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
unitary_1q[i][j]=ry[i][j];
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
circuitline0[countcircuit0]='R';
countcircuit0++;
}
else if(number_of_qubits==2)
{
if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)ry, 2, 2, (double*)identity, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline1[countcircuit1]='R';
countcircuit1++;
}
else if(qubitposition==0)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)ry, 2, 2);
Matrix_Product(*matrix4,*unitary_2q_final,4,4,*unitary_2q,4);
for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    unitary_2q_final[i][j]=matrix4[i][j];
  }
}
circuitline0[countcircuit0]='R';
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
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)ry, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline0[countcircuit0]='R';
countcircuit0++;
}
else if(qubitposition==1)
{
Kronecker_Product(&unitary_2q[0][0], (double *)identity, 2, 2, (double*)ry, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline1[countcircuit1]='R';
countcircuit1++;
}
else if(qubitposition==2)
{
Kronecker_Product(&unitary_2q[0][0], (double *)ry, 2, 2, (double*)identity, 2, 2);
Kronecker_Product(&unitary_3q[0][0], (double *)unitary_2q, 4, 4, (double*)identity, 2, 2);
Matrix_Product(*matrix8,*unitary_3q_final,8,8,*unitary_3q,8);
for(int i=0;i<8;i++)
{
  for(int j=0;j<8;j++)
  {
    unitary_3q_final[i][j]=matrix8[i][j];
  }
}
circuitline2[countcircuit2]='R';
countcircuit2++;
}
else
{
  cout<<"Qubit index out of bounds."<<endl;
}
}
}
