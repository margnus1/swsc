// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0696.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_1; 
volatile int atom_1_r4_3; 
volatile int atom_1_r1_1; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[0];
  int v3_r4 = v2_r3 ^ v2_r3;
  int v4_r4 = v3_r4 + 1;
  vars[1] = v4_r4;
  vars[1] = 3;
  int v21 = (v2_r3 == 1);
  atom_0_r3_1 = v21;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[1];
  vars[1] = 2;

  int v8_r4 = vars[1];
  int v22 = (v8_r4 == 3);
  atom_1_r4_3 = v22;
  int v23 = (v6_r1 == 1);
  atom_1_r1_1 = v23;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 4;

  int v10_r3 = vars[0];
  int v24 = (v10_r3 == 0);
  atom_2_r3_0 = v24;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r3_1 = 0;
  atom_1_r4_3 = 0;
  atom_1_r1_1 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v11 = vars[1];
  int v12 = (v11 == 4);
  int v13 = atom_0_r3_1;
  int v14 = atom_1_r4_3;
  int v15 = atom_1_r1_1;
  int v16 = atom_2_r3_0;
  int v17_conj = v15 & v16;
  int v18_conj = v14 & v17_conj;
  int v19_conj = v13 & v18_conj;
  int v20_conj = v12 & v19_conj;
  if (v20_conj == 1) assert(0);
  return 0;
}