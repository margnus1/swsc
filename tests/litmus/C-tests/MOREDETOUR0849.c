// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0849.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_2_r4_3; 
volatile int atom_2_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 4;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v3_r3 = v2_r1 ^ v2_r1;
  int v6_r4 = vars[0+v3_r3];
  vars[0] = 1;
  vars[0] = 3;
  int v19 = (v2_r1 == 1);
  atom_1_r1_1 = v19;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v8_r1 = vars[0];
  vars[0] = 2;

  int v10_r4 = vars[0];
  int v20 = (v10_r4 == 3);
  atom_2_r4_3 = v20;
  int v21 = (v8_r1 == 1);
  atom_2_r1_1 = v21;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_2_r4_3 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v11 = vars[0];
  int v12 = (v11 == 4);
  int v13 = atom_1_r1_1;
  int v14 = atom_2_r4_3;
  int v15 = atom_2_r1_1;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}