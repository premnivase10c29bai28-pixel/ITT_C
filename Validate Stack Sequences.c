bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int *stack=(int *)malloc(sizeof(int) * pushedSize);
    int top=-1;
    int pop=0;
    for(int i=0;i<pushedSize;i++)
    {
        stack[++top]=pushed[i];
    while(top >=0 && stack[top]==popped[pop])
    {
        top--;
        pop++;
    }
    }
    free(stack);
    return pop == poppedSize;
}

