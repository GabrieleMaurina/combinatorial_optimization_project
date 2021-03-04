#include "moore_fifo_queue.h"

void MooreFifoQueue::push(const ui value){
	q.push(value);
	us.insert(value);
}

ui MooreFifoQueue::pop(){
	ui value = q.front();
	q.pop();
	us.erase(value);
	return value;
}

bool MooreFifoQueue::empty(){
	return q.empty();
}

bool MooreFifoQueue::contains(const ui value){
	return us.contains(value);
}
