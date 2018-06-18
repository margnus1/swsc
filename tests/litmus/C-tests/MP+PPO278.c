// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MP+PPO278.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r12_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v3_r3 = v2_r1 ^ v2_r1;
  vars[2+v3_r3] = 1;
  vars[2] = 2;
  int v5_r7 = vars[2];
  int v7_r8 = vars[2];
  int v8_r9 = v7_r8 ^ v7_r8;
  int v11_r10 = vars[3+v8_r9];
  int v12_cmpeq = (v11_r10 == v11_r10);
  if (v12_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;

  int v14_r12 = vars[0];
  int v21 = (v2_r1 == 1);
  atom_1_r1_1 = v21;
  int v22 = (v14_r12 == 0);
  atom_1_r12_0 = v22;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[3] = 0;
  vars[0] = 0;
  vars[1] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;
  atom_1_r12_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v15 = vars[2];
  int v16 = (v15 == 2);
  int v17 = atom_1_r1_1;
  int v18 = atom_1_r12_0;
  int v19_conj = v17 & v18;
  int v20_conj = v16 & v19_conj;
  if (v20_conj == 1) assert(0);
  return 0;
}