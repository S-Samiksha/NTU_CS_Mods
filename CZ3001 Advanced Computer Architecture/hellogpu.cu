#include <stdio.h>
__global__ void hello_gpu(void){

    int i = blockIdx.x * blockDim.x + threadIdx.x;
    printf("Hello from GPU[%d]! \n", i);

}

int main(void){
printf("Hello, Would - from CPU!");
hello_gpu<<1,4>>();
cudaDeviceSynchronize();
hello_gpu<<1,6>>();
cudaDeviceSychronize();
return 0;

}