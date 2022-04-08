#include <stdio.h>
__global__ void dot_prod_cu(int *d_c, int *d_a, int *d_b){ 
    __shared__ int tmp[3]; 
    int i = threadIdx.x;
    tmp[i] = d_a[i] * d_b[i]; 
    __syncthreads();
    if (i==0){
        int sum = 0, j=0;
        for (int j = 0; j < 3; j++){
            sum = sum + tmp[j]; 
            *c = sum; 
        }
        
    } 
}

int main(void){
    int N = 4, i=0;
    int a[N] = {22,13,16, 5};
    int b[N] = {5, 22, 17, 37};
    int c[N]; 
    int *d_a, *d_b, *d_c; 
    cudaMalloc((void**)&d_a, sizeof(int)*N); 
    cudaMalloc((void**)&d_b, sizeof(int)*N); 
    cudaMalloc((void**)&d_c, sizeof(int)); 
    cudaMemcpy(d_a, a, sizeof(int)*N, cudaMemcpyHostToDevice); 
    cudaMemcpy(d_b, b, sizeof(int)*N, cudaMemcpyHostToDevice); 
    dot_prod_cu<<<1,N>>>(d_c, d_a, d_b); // note: 1 thread
    cudaDeviceSynchronize();
    cudaMemcpy(c, d_c, sizeof(int), cudaMemcpyDeviceToHost); 
    printf("value of d_c: %d", &d_c);
    printf("\n");
    cudaFree(d_a); 
    cudaFree(d_b);
    cudaFree(d_c);
  
} 