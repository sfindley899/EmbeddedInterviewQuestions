#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define IS_POWER_OF_TWO(n) ((n & (n - 1)) == 0)

/*************************************************
 * aligned_malloc
 * 
 * @brief Returns a malloc' pointer in an alignment that is in the power of 2.
 * 
 * @param size      Amount of bytes that are allocated from memory.
 * @param alignment Specifies the byte granularity at which the data should be aligned.
 *                  For instance, an alignment of 8 means the returned memory address 
 *                  will be a multiple of 8 bytes.
 * 
 * @return void *
 * 
 *************************************************/
void * aligned_malloc(uint32_t size, uint64_t alignment)
{
    // check if size and alignment is valid
   if ((size <= 0) || !IS_POWER_OF_TWO(alignment))
    {
        return NULL;
    }

    // Allocate pointer
    uint64_t originalPtr = (uintptr_t)malloc(size + alignment + sizeof(void *));

    /// Check if original pointer is valid
    if (originalPtr == 0ULL)
    {
        return NULL;
    }

    // Adjust new pointer to fit alignment 
    void * alignedPtr = (void *)((originalPtr + alignment) & (~(alignment - 1)));

    // Store the original pointer in the location immediately preceding the aligned pointer
    ((void **)alignedPtr)[-1] = (void *)originalPtr;

    return alignedPtr;
}

/*************************************************
 * aligned_free
 * 
 * @brief Frees a pointer, assuming there is reserved space the original pointer 
 *        in the location immediately preceding the aligned pointer
 * 
 * @param p Aligned pointer allocated by
 * 
 * @return none
 * 
 *************************************************/
void aligned_free(void const * const p)
{
    if (p == NULL)
    {
        return;
    }

    void * originalPtr = ((void **)p)[-1];
    free(originalPtr);
}

int main(void)
{
    // Test 1: Valid alignment request
    void *ptr1 = aligned_malloc(100, 8);
    if ((uintptr_t)ptr1 % 8 != 0)
    {
        printf("Test 1 Failed! Memory not correctly aligned. Expected Alignment %d | Actual %p\n", 8, ptr1);
        return -1;
    }
    aligned_free(ptr1);

    // Test 2: Invalid alignment request
    void *ptr2 = aligned_malloc(100, 5); // 5 is not a power of 2
    if (ptr2 != NULL)
    {
        printf("Test 2 Failed! Memory shouldn't be allocated for non-power-of-2 alignment. Actual: %p\n", ptr2);
        return -1;
    }
    aligned_free(ptr2);

    // Test 3: Memory operations
    void *ptr3 = aligned_malloc(100, 16);
    for (int i = 0; i < 100; i++)
    {
        ((char *)ptr3)[i] = (char)i;
    }
    for (int i = 0; i < 100; i++)
    {
        if (((char *)ptr3)[i] != (char)i)
        {
            printf("Test 3 Failed! Memory operations not consistent. Expected: %c | Actual %c\n", i, ((char *)ptr3)[i]);
            return -1;
            // break;
        }
    }
    aligned_free(ptr3);

    // Test 4: Edge cases
    void *ptr4 = aligned_malloc(0, 16);  // size of 0
    if (ptr4 != NULL)
    {
        printf("Test 4 Failed! Memory shouldn't be allocated for size 0. Actual %p\n", ptr4);
        return -1;
    }
    aligned_free(ptr4);

    printf("All tests completed!\n");
}
