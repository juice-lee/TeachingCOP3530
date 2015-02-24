#include<iostream>

class Deque{
private:
	std::string *queue;	// The array which holds the queue.
	int num_elements;	// The number of elements in the queue
	int size_of_queue;	// The capacity of the queue
	int front;		// Points to the front element of the queue
	int back;		// Points to the back element of the queue

	/*
	 * Deque::growQueue
	 * Takes in - Nothing
	 * Returns - Nothing
	 *
	 * Doubles the size of the queue
	 */
	void growQueue() {
		std::string *new_queue = new std::string[size_of_queue*2];


		int i,j;
		i=front;
		j=0;
		while(i != back) {
			new_queue[j]=queue[i];
			i=(i+1)%size_of_queue;
			j++;
		}
		new_queue[j] = queue[back];
		size_of_queue = size_of_queue * 2;
		front = 0;
		back = j;
		delete []queue;
		queue = new_queue;
	}

	/*
	 * Deque::shrinkQueue
	 * Takes in - Nothing
	 * Returns - Nothing
	 *
	 * Halves the size of the queue
	 */
	void shrinkQueue() {
	int new_q_size = 0;
	if(size_of_queue/2 < 8) {
		new_q_size = 8;
	} else {
		new_q_size = size_of_queue/2;
	}
        std::string *new_queue = new std::string[new_q_size];
        int i,j;
        i=front;
        j=0;
        while(i != back) {
                new_queue[j]=queue[i];
                i=(i+1)%size_of_queue;
                j++;
        }
        new_queue[j] = queue[back];
        size_of_queue = new_q_size;
        front = 0;
        back = j;
        delete []queue;
        queue = new_queue;

	}
public:
	/* Deque::Deque
	 *  Takes in -
	 *  	int - The initial size of the array to be allocated.
	 *  Returns - Nothing
	 *
	 *  Allocates memory for the array. Default is 10.
	 */
	Deque(int initial_size=8) {
		queue = new std::string[initial_size];
		num_elements = 0;
		size_of_queue = initial_size;
		front = -1;
		back = -1;
	}

	/*
	 * Deque::~Deque - The destructor
	 * Takes in - Nothing
	 * Returns - Nothing
	 *
	 * Deallocates the memory allocated to the queue
	 */
	~Deque() {
		delete[] queue;
	}

	/*
	 * Deque::push_front
	 * Takes in -
	 * 	std::string - the item to be inserted into the queue
	 * Returns - Nothing
	 *
	 * Inserts the element at the front of the queue. If the queue becomes full,
	 * it doubles the size of the queue.
	 */
	void push_front(std::string item) {
		if(num_elements == size_of_queue) {
				growQueue();
		}

		if(empty())
	    {
	        back=0;
	        front=0;
	        queue[0]=item;
	    } else {
	        front=(front-1+size_of_queue)%size_of_queue;
	        queue[front]=item;
	    }
	    num_elements++;
		/*if(num_elements == size_of_queue - 1) {
			growQueue();
		}
		queue[front] = item;
		front = (front + 1)%size_of_queue;
		num_elements++;*/
	}

	/*
	 * Deque::pop_front - Deletes the element at the front of the queue.
	 * Takes in - Nothing
	 * Returns -
	 * 	std::string - the item deleted from the queue
	 *
	 * Deletes the element at the front of the queue. If the queue becomes 1/4 full,
	 * it shrinks the size of the queue to half its current size.
	 */
	std::string pop_front() {
		if(empty()) {
			return "";
		}
		if(num_elements <= size_of_queue * 0.25) {
			shrinkQueue();
		}
	    std::string x;
	    x=queue[front];
	    if(back==front) {   //delete the last element
	    	front = -1;
	    	back = -1;
	    }
	    else
	        front=(front+1)%size_of_queue;
	    num_elements--;
	    return(x);
	}

	/*
	 * Deque::push_back - Inserts the element at the back of the queue.
	 * Takes in -
	 * 	std::string - the item to be inserted into the queue
	 * Returns - Nothing
	 *
	 * Inserts the element at the back of the queue. If the queue becomes full,
	 * it doubles the size of the queue.
	 */
	void push_back(std::string item) {
		if(num_elements == size_of_queue) {
			growQueue();
		}
	   if(empty())
		{
			back=0;
			front=0;
			queue[0]=item;
		}
		else
		{
				back=(back+1)%size_of_queue;
				queue[back]=item;
		}
	   num_elements++;
	}


	/*
	 * Deque::pop_back - Deletes the element at the front of the queue.
	 * Takes in - Nothing
	 * Returns -
	 * 	std::string - the item deleted from the queue
	 *
	 * Deletes the element at the front of the queue. If the queue becomes 1/4 full,
	 * it shrinks the size of the queue to half its current size.
	 */
	std::string pop_back() {
		if(empty()) {
			return "";
		}
		if(num_elements <= size_of_queue * 0.25) {
			shrinkQueue();
		}
	    std::string x;
	    x=queue[back];
	    if(back==front) {
	    	front = -1;
	    	back = -1;
	    }
	    else
	        back=(back-1+size_of_queue)%size_of_queue;
	    num_elements--;
	    return(x);
	}

	/*
	 * Deque::size
	 * Takes in - Nothing
	 * Returns -
	 * 	int - The size of the queue.
	 *
	 * Returns the size of the queue.
	 */
	int size() {
		return size_of_queue;
	}

	/*
	 * Deque::size
	 * Takes in - Nothing
	 * Returns -
	 * 	bool -  true if the queue is empty.
	 		false if the queue has at least one element.
	 *
	 * Tells whether the queue is full or not.
	 */
	bool empty() {
		if(num_elements == 0) {
			return true;
		}
		return false;
	}

	std::string toStr() {
		if(empty()) {
		      return "";
		}

		int i;
		i=front;
		std::string q;
		while(i != back) {
			q += queue[i] + "\n";
			i=(i+1)%size_of_queue;
		}
		q += queue[back] + "\n";
		return q;
	}
	

};
