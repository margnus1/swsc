// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/safe550.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_2; 
volatile int atom_2_r1_1; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  vars[0+v3_r3] = 2;
  int v20 = (v2_r1 == 1);
  atom_0_r1_1 = v20;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v5_r1 = vars[0];

  vars[1] = 1;
  int v21 = (v5_r1 == 2);
  atom_1_r1_2 = v21;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v7_r1 = vars[1];

  int v9_r3 = vars[2];
  int v22 = (v7_r1 == 1);
  atom_2_r1_1 = v22;
  int v23 = (v9_r3 == 0);
  atom_2_r3_0 = v23;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[2] = 1;

  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[1] = 0;
  vars[2] = 0;
  vars[0] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_2 = 0;
  atom_2_r1_1 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v10 = vars[0];
  int v11 = (v10 == 2);
  int v12 = atom_0_r1_1;
  int v13 = atom_1_r1_2;
  int v14 = atom_2_r1_1;
  int v15 = atom_2_r3_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  int v19_conj = v11 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}