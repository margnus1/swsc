// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/rfe005.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r1_1; 
volatile int atom_2_r1_2; 
volatile int atom_2_r4_0; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  vars[1+v3_r3] = 1;
  int v18 = (v2_r1 == 1);
  atom_0_r1_1 = v18;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v5_r1 = vars[1];
  int v6_r3 = v5_r1 ^ v5_r1;
  int v9_r4 = vars[0+v6_r3];
  int v19 = (v5_r1 == 2);
  atom_2_r1_2 = v19;
  int v20 = (v9_r4 == 0);
  atom_2_r4_0 = v20;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r1_1 = 0;
  atom_2_r1_2 = 0;
  atom_2_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v10 = vars[1];
  int v11 = (v10 == 2);
  int v12 = atom_0_r1_1;
  int v13 = atom_2_r1_2;
  int v14 = atom_2_r4_0;
  int v15_conj = v13 & v14;
  int v16_conj = v12 & v15_conj;
  int v17_conj = v11 & v16_conj;
  if (v17_conj == 1) assert(0);
  return 0;
}