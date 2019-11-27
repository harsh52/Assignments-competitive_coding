#include <stdio.h>
#include <stdbool.h>

char mallocArray[25000] = {'\0'};

char *base = mallocArray;

char freeflag = 'f';
char allocate = 'a';

char* find_block(size_t size)
{
    char *mover;
    mover = base;

    int num = 0;

    char *next = NULL;

    while(true)
    {
        num = *(int *)(mover+1);

        if(*mover == freeflag && num >= size + 5)
        {
            return (mover);
        }else if(!mover)
        {
            return NULL;
        }else{

            if( mover + num + size >= mallocArray + 24999)
            {
                printf("Memory Overflow\n");
                return NULL;
            }

            mover = mover + num;
        }

    }

    return (mover);
}

void split_block(char* b, size_t s)
{
    char* temp;
    int b_size = *(int *)(b + 1);

    b_size = b_size - s - 5;
    //50 - 40 -5

    temp = b + s + 5;

    *temp = freeflag;

    *(int *)(temp + 1) = b_size;
    *(int *)(b + 1) = s+5;
    *b = allocate;


}

char *MyMalloc(size_t size)
{
    if(size <= 0)
    {
        return NULL;
    }

    if(!*base)
    {
        *base = freeflag;
        *(int *)(base+1) = 24999 - 5;

    }

    size_t s = size;

    char* b = find_block(s);

    if(b)
    {

       if(*(int *)(b+1) >= size)
       {
           split_block(b,s);

       }
    }else{
        return NULL;
    }

    return (b);


}

void main()
{
    char* addr1 = MyMalloc(8);
    char* addr2 = MyMalloc(400);

    printf(" 8 %p \n",addr1);
    printf(" 400 %p \n",addr2);
    //d = 13(8+5)
}