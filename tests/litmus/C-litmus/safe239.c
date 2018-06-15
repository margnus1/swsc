// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/safe239.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_1; 
volatile int atom_2_r1_2; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];

  vars[1] = 1;
  int v24 = (v2_r1 == 1);
  atom_0_r1_1 = v24;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v4_r1 = vars[1];
  int v5_r3 = v4_r1 ^ v4_r1;
  int v8_r4 = vars[1+v5_r3];
  vars[1] = 2;
  int v25 = (v4_r1 == 1);
  atom_1_r1_1 = v25;
  int v26 = (v8_r4 == 1);
  atom_1_r4_1 = v26;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v10_r1 = vars[1];

  vars[2] = 1;
  int v27 = (v10_r1 == 2);
  atom_2_r1_2 = v27;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[2] = 2;

  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[0] = 0;
  vars[2] = 0;
  vars[1] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_1 = 0;
  atom_2_r1_2 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v11 = vars[1];
  int v12 = (v11 == 2);
  int v13 = vars[2];
  int v14 = (v13 == 2);
  int v15 = atom_0_r1_1;
  int v16 = atom_1_r1_1;
  int v17 = atom_1_r4_1;
  int v18 = atom_2_r1_2;
  int v19_conj = v17 & v18;
  int v20_conj = v16 & v19_conj;
  int v21_conj = v15 & v20_conj;
  int v22_conj = v14 & v21_conj;
  int v23_conj = v12 & v22_conj;
  if (v23_conj == 1) assert(0);
  return 0;
}