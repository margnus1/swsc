// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0685.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r3_0; 
volatile int atom_0_r5_1; 
volatile int atom_2_r4_3; 
volatile int atom_2_r1_1; 
volatile int atom_3_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  int v4_r5 = vars[1];
  vars[1] = 3;
  int v23 = (v2_r3 == 0);
  atom_0_r3_0 = v23;
  int v24 = (v4_r5 == 1);
  atom_0_r5_1 = v24;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 1;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v6_r1 = vars[1];
  vars[1] = 2;

  int v8_r4 = vars[1];
  int v25 = (v8_r4 == 3);
  atom_2_r4_3 = v25;
  int v26 = (v6_r1 == 1);
  atom_2_r1_1 = v26;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[1] = 4;

  int v10_r3 = vars[0];
  int v27 = (v10_r3 == 0);
  atom_3_r3_0 = v27;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r3_0 = 0;
  atom_0_r5_1 = 0;
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

  int v11 = vars[1];
  int v12 = (v11 == 4);
  int v13 = atom_0_r3_0;
  int v14 = atom_0_r5_1;
  int v15 = atom_2_r4_3;
  int v16 = atom_2_r1_1;
  int v17 = atom_3_r3_0;
  int v18_conj = v16 & v17;
  int v19_conj = v15 & v18_conj;
  int v20_conj = v14 & v19_conj;
  int v21_conj = v13 & v20_conj;
  int v22_conj = v12 & v21_conj;
  if (v22_conj == 1) assert(0);
  return 0;
}