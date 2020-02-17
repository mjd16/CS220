/** queueAsArray.c
* ===========================================================
* Name: First Last
* Section: xxx
* Project: Lab11 - Queue ADT implemented with C array
* ===========================================================
*/
#include <stdio.h>
#include "queueAsArray.h"


/** Task 0) - write the implementations for circular queue functions
 * 0) implement functions below
 * 1) test each function in Lab09_queue.c prior to completing
 * the DMV application.
 */

/** enqueue() - adds an element to the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - the item to add to the queue
 * @return 1 on success, -1 on failure
 */
int enqueue(QueueAsArray* queue, int element) {
    if (!queueIsFull(queue)) {
        queue->back = (queue->back + 1) % QUEUE_MAX_SIZE;
        queue->number[queue->back] = element;
        return 1;
    }
    return -1;
}


/** dequeue() - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @return - the top of the queue on success, -1 on failure
 */
int dequeue(QueueAsArray* queue) {
    if (!queueIsEmpty(queue)) {
        queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
        return queue->number[queue->front];
    }
    return -1;
}


/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsArray* queue) {
    if (queue->front == queue->back)
        return true;
    return false;
}


/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 */
bool queueIsFull(QueueAsArray* queue) {
    if (queue->front == ((queue->back + 1) % QUEUE_MAX_SIZE))
        return true;
    return false;
}


/** queueInit() - initializes the queue structure
 * @param queue - a ptr to the queue structure
 */
void queueInit(QueueAsArray* queue) {
    queue->back = 0;
    queue->front = 0;
    //not sure what this is for
    queue->priority = 0;
}


/** queuePeek() - returns the item on the front of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item at the front of the queue or -1 on failure
 */
int queuePeek(QueueAsArray* queue) {
    
    if (!queueIsEmpty(queue)) {
        return (queue->number[(queue->front + 1) % QUEUE_MAX_SIZE]);
    }
    return -1;
}


/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsArray* queue) {
    if (!queueIsEmpty(queue)) {
        return (queue->front + queue->back) % QUEUE_MAX_SIZE;
    }
    return -1;
}


/** queuePrint() - outputs the queue to the console
 * @param queue - ptr to the queue structure
 */
void queuePrint(QueueAsArray* queue) {
    if (!queueIsEmpty(queue)) {
        int i = queue->front;
        while (i != queue->back) {
            i = (i + 1) % QUEUE_MAX_SIZE;
            printf("Item %d is at position %d\n", queue->number[i], i);
        }
    }
}