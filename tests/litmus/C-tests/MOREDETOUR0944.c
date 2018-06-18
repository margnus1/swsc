// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0944.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
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
  vars[1] = 2;
  int v2_r3 = vars[1];
  int v3_cmpeq = (v2_r3 == v2_r3);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[0] = 1;
  vars[0] = 3;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v5_r1 = vars[0];
  vars[0] = 2;

  int v7_r4 = vars[0];
  int v17 = (v7_r4 == 3);
  atom_2_r4_3 = v17;
  int v18 = (v5_r1 == 1);
  atom_2_r1_1 = v18;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[0] = 0;
  vars[1] = 0;
  atom_2_r4_3 = 0;
  atom_2_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v8 = vars[1];
  int v9 = (v8 == 2);
  int v10 = vars[0];
  int v11 = (v10 == 4);
  int v12 = atom_2_r4_3;
  int v13 = atom_2_r1_1;
  int v14_conj = v12 & v13;
  int v15_conj = v11 & v14_conj;
  int v16_conj = v9 & v15_conj;
  if (v16_conj == 1) assert(0);
  return 0;
}