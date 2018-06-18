// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0126.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_4; 
volatile int atom_2_r4_3; 
volatile int atom_2_r1_1; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v4_r3 = v3_r3 + 1;
  vars[1] = v4_r3;
  int v23 = (v2_r1 == 1);
  atom_0_r1_1 = v23;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[1];
  vars[1] = 3;
  int v8_r4 = vars[1];
  int v9_r5 = v8_r4 ^ v8_r4;
  vars[0+v9_r5] = 1;
  int v24 = (v6_r1 == 1);
  atom_1_r1_1 = v24;
  int v25 = (v8_r4 == 4);
  atom_1_r4_4 = v25;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v11_r1 = vars[1];
  vars[1] = 2;

  int v13_r4 = vars[1];
  int v26 = (v13_r4 == 3);
  atom_2_r4_3 = v26;
  int v27 = (v11_r1 == 1);
  atom_2_r1_1 = v27;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[1] = 4;
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
  atom_1_r1_1 = 0;
  atom_1_r4_4 = 0;
  atom_2_r4_3 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v14 = atom_0_r1_1;
  int v15 = atom_1_r1_1;
  int v16 = atom_1_r4_4;
  int v17 = atom_2_r4_3;
  int v18 = atom_2_r1_1;
  int v19_conj = v17 & v18;
  int v20_conj = v16 & v19_conj;
  int v21_conj = v15 & v20_conj;
  int v22_conj = v14 & v21_conj;
  if (v22_conj == 1) assert(0);
  return 0;
}