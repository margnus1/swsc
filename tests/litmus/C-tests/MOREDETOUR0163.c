// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0163.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 
volatile int atom_1_r3_1; 
volatile int atom_2_r1_1; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v4_r3 = v3_r3 + 1;
  vars[1] = v4_r3;
  int v21 = (v2_r1 == 1);
  atom_0_r1_1 = v21;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[1];
  int v8_r3 = vars[1];
  vars[1] = 3;
  vars[0] = 1;
  int v22 = (v6_r1 == 1);
  atom_1_r1_1 = v22;
  int v23 = (v8_r3 == 1);
  atom_1_r3_1 = v23;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v10_r1 = vars[1];
  vars[1] = 2;
  int v24 = (v10_r1 == 1);
  atom_2_r1_1 = v24;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;
  atom_1_r3_1 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v11 = atom_0_r1_1;
  int v12 = atom_1_r1_1;
  int v13 = atom_1_r3_1;
  int v14 = vars[1];
  int v15 = (v14 == 3);
  int v16 = atom_2_r1_1;
  int v17_conj = v15 & v16;
  int v18_conj = v13 & v17_conj;
  int v19_conj = v12 & v18_conj;
  int v20_conj = v11 & v19_conj;
  if (v20_conj == 1) assert(0);
  return 0;
}