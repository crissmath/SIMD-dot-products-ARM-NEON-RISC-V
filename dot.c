#include <stdio.h>
#include <stdlib.h>
#include <arm_neon.h>

float A [] = {5,2,3,16}; 
float B [] = {1,2,3,4}; 



float dot_nrm(float *A, float *B){
	float result = 0.0;
	for(int i=0; i<4 ; i++){
		result += A[i]*B[i];
	}
	return result;
}



float dot_vec(float32_t *A, float32_t *B){
	float32_t result = 0.0;
	float32x4_t a 	 = vld1q_f32(&A[0]);
	float32x4_t b 	 = vld1q_f32(&B[0]);
	float32x4_t prod = vmlaq_f32(prod,a,b);
	result 		 = vaddvq_f32(prod);
	return result;
}


int main(){

	float32_t *ptr_A = &A;
	float32_t *ptr_B = &B;
	
	printf("result  = %f\n", dot_nrm(ptr_A, ptr_B));
	printf("result2 = %f\n", dot_vec(ptr_A, ptr_B));


}



