// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0695.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_2; 
volatile int atom_2_r4_3; 
volatile int atom_2_r1_1; 
volatile int atom_3_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[0];
  int v3_r4 = v2_r3 ^ v2_r3;
  vars[1+v3_r4] = 1;
  vars[1] = 3;
  int v20 = (v2_r3 == 2);
  atom_0_r3_2 = v20;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[0] = 2;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v5_r1 = vars[1];
  vars[1] = 2;

  int v7_r4 = vars[1];
  int v21 = (v7_r4 == 3);
  atom_2_r4_3 = v21;
  int v22 = (v5_r1 == 1);
  atom_2_r1_1 = v22;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[1] = 4;

  int v9_r3 = vars[0];
  int v23 = (v9_r3 == 0);
  atom_3_r3_0 = v23;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r3_2 = 0;
  atom_2_r4_3 = 0;
  atom_2_r1_1 = 0;
  atom_3_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v10 = vars[1];
  int v11 = (v10 == 4);
  int v12 = atom_0_r3_2;
  int v13 = atom_2_r4_3;
  int v14 = atom_2_r1_1;
  int v15 = atom_3_r3_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  int v19_conj = v11 & v18_conj;
  if (v19_conj == 1) assert(0);
  return 0;
}